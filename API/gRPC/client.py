import grpc
import calculator_pb2
import calculator_pb2_grpc

# ── Helpers ───────────────────────────────────────────────────────────────────
def section(title):
    print(f"\n{'='*40}")
    print(f"  {title}")
    print('='*40)

# ── Pattern 1: Unary ──────────────────────────────────────────────────────────
# One request, one response - simplest pattern
def run_unary(stub):
    section("Pattern 1: Unary — Add")
    request = calculator_pb2.AddRequest(a=7, b=3)
    response = stub.Add(request)
    print(f"  7 + 3 = {response.result}")

# ── Pattern 2: Client Streaming ───────────────────────────────────────────────
# We generate a stream of messages, server replies once when we're done
def run_client_streaming(stub):
    section("Pattern 2: Client Streaming — RunningSum")

    numbers = [10, 20, 30, 40, 50]

    # A generator function - each yield sends one message to the server
    def number_generator():
        for n in numbers:
            print(f"  Sending number: {n}")
            yield calculator_pb2.NumberRequest(number=n)

    response = stub.RunningSum(number_generator())
    print(f"  Server replied with total: {response.total}")

# ── Pattern 3: Server Streaming ───────────────────────────────────────────────
# We send one request, server streams multiple responses back
def run_server_streaming(stub):
    section("Pattern 3: Server Streaming — MultiplyTable for 6")
    request = calculator_pb2.MultiplyRequest(number=6)

    # response is an iterator - we loop through each message as it arrives
    for response in stub.MultiplyTable(request):
        print(f"  6 x {response.multiplier} = {response.result}")

# ── Pattern 4: Bidirectional Streaming ───────────────────────────────────────
# Both client and server stream simultaneously
def run_bidi_streaming(stub):
    section("Pattern 4: Bidirectional Streaming — Calculate")

    operations = [
        ("add",      10, 5),
        ("subtract", 10, 5),
        ("multiply", 10, 5),
        ("divide",   10, 5),
        ("divide",   10, 0),  # intentional error - divide by zero
    ]

    def operation_generator():
        for op, a, b in operations:
            print(f"  Sending: {a} {op} {b}")
            yield calculator_pb2.OperationRequest(a=a, b=b, op=op)

    try:
        for response in stub.Calculate(operation_generator()):
            print(f"  Result: {response.description}")
    except grpc.RpcError as e:
        # This shows how gRPC surfaces errors from the server
        print(f"  gRPC Error [{e.code()}]: {e.details()}")

# ── Main ──────────────────────────────────────────────────────────────────────
def run():
    # A channel is the connection to the server
    # insecure_channel = no TLS (fine for local dev)
    with grpc.insecure_channel("localhost:50051") as channel:
        # Stub is the client-side proxy - call RPCs on it like local functions
        stub = calculator_pb2_grpc.CalculatorStub(channel)

        run_unary(stub)
        run_client_streaming(stub)
        run_server_streaming(stub)
        run_bidi_streaming(stub)

    print("\n✅ All 4 gRPC patterns demonstrated successfully\n")

if __name__ == "__main__":
    run()