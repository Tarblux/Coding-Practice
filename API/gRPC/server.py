import grpc
import time
from concurrent import futures

import calculator_pb2
import calculator_pb2_grpc


# This class implements the 4 RPCs defined in calculator.proto
# Think of it like a controller in REST - one method per endpoint

class CalculatorServicer(calculator_pb2_grpc.CalculatorServicer):

    # Pattern 1 — Unary
    # Called once, returns once. Simplest pattern - just like a normal function.
    def Add(self, request, context):
        print(f"[Unary]        Add called: {request.a} + {request.b}")
        result = request.a + request.b
        return calculator_pb2.AddResponse(result=result)

    # Pattern 2 — Client Streaming
    # `request_iterator` is a generator - we loop through every message the client sends
    # We only respond ONCE after all messages are received
    def RunningSum(self, request_iterator, context):
        total = 0.0
        for req in request_iterator:
            total += req.number
            print(f"[ClientStream] RunningSum received: {req.number}, running total: {total}")
        print(f"[ClientStream] RunningSum final total: {total}")
        return calculator_pb2.SumResponse(total=total)

    # Pattern 3 — Server Streaming
    # We receive ONE request, then `yield` multiple responses back
    # The client receives them one at a time as we yield
    def MultiplyTable(self, request, context):
        print(f"[ServerStream] MultiplyTable called for: {request.number}")
        for i in range(1, 11):
            result = request.number * i
            print(f"[ServerStream] Sending: {request.number} x {i} = {result}")
            yield calculator_pb2.MultiplyResponse(result=result, multiplier=i)
            time.sleep(0.1)  # slight delay so streaming is visible

    # Pattern 4 — Bidirectional Streaming
    # Both sides stream simultaneously
    # We loop through incoming requests and yield a response for each one
    def Calculate(self, request_iterator, context):
        for req in request_iterator:
            print(f"[BiDiStream]   Calculate received: {req.a} {req.op} {req.b}")
            result = None

            if req.op == "add":
                result = req.a + req.b
            elif req.op == "subtract":
                result = req.a - req.b
            elif req.op == "multiply":
                result = req.a * req.b
            elif req.op == "divide":
                if req.b == 0:
                    context.set_code(grpc.StatusCode.INVALID_ARGUMENT)
                    context.set_details("Cannot divide by zero")
                    return
                result = req.a / req.b
            else:
                context.set_code(grpc.StatusCode.INVALID_ARGUMENT)
                context.set_details(f"Unknown op: {req.op}")
                return

            description = f"{req.a} {req.op} {req.b} = {result}"
            yield calculator_pb2.OperationResponse(result=result, description=description)



def serve():
    
    # ThreadPoolExecutor allows the server to handle multiple RPCs concurrently
    server = grpc.server(futures.ThreadPoolExecutor(max_workers=10))

    # Register our servicer with the server
    calculator_pb2_grpc.add_CalculatorServicer_to_server(CalculatorServicer(), server)

    server.add_insecure_port("[::]:50051")  # no TLS for local dev
    server.start()
    print("=" * 40)
    print("  gRPC Calculator Server running")
    print("  Listening on localhost:50051")
    print("=" * 40)

    try:
        server.wait_for_termination()  # block until Ctrl+C
    except KeyboardInterrupt:
        print("\nServer shutting down...")
        server.stop(0)


if __name__ == "__main__":
    serve()