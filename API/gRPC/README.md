# gRPC Calculator — Python Learning Prototype

A full end-to-end gRPC prototype demonstrating all 4 communication patterns.

---

## Concepts

### What is gRPC?
- A high-performance RPC framework by Google
- Uses **HTTP/2** under the hood (vs HTTP/1.1 in REST)
- Contract-first: you define your API in a `.proto` file **before** writing any code
- Strongly typed — no ambiguity about what fields exist or their types
- Supports **streaming** natively — REST does not

### Why HTTP/2 matters
| Feature | REST (HTTP/1.1) | gRPC (HTTP/2) |
|---|---|---|
| Multiplexing | ❌ one request at a time per connection | ✅ many requests on one connection |
| Streaming | ❌ workarounds only | ✅ first-class |
| Header compression | ❌ | ✅ |
| Message format | JSON (text) | Protobuf (binary, smaller) |

### The 4 gRPC Communication Patterns
| Pattern | Client sends | Server sends | Use case |
|---|---|---|---|
| **Unary** | 1 message | 1 message | Normal function call |
| **Client Streaming** | many messages | 1 message | Upload, aggregation |
| **Server Streaming** | 1 message | many messages | Live feed, large data |
| **Bidirectional** | many messages | many messages | Chat, real-time sync |

---

## Project Structure
```
API/gRPC/
├── calculator.proto        # Service contract (source of truth)
├── calculator_pb2.py       # Generated: message classes (DO NOT EDIT)
├── calculator_pb2_grpc.py  # Generated: server/client stubs (DO NOT EDIT)
├── server.py               # gRPC server implementing the 4 RPCs
├── client.py               # Client exercising all 4 patterns
└── requirements.txt        # Dependencies
```

---

## Setup

```bash
# 1. Create and activate virtual environment
python3 -m venv .venv
source .venv/bin/activate

# 2. Install dependencies
pip install -r requirements.txt

# 3. Regenerate stubs from proto (only needed if you change calculator.proto)
python -m grpc_tools.protoc \
  -I. \
  --python_out=. \
  --grpc_python_out=. \
  calculator.proto
```

---

## Run

```bash
# Terminal 1 — start the server
python server.py

# Terminal 2 — run the client
python client.py
```

---

## How the Files Relate

```
calculator.proto
      │
      │  grpc_tools.protoc (code generation)
      │
      ├──► calculator_pb2.py        (message classes: AddRequest, AddResponse ...)
      └──► calculator_pb2_grpc.py   (CalculatorStub, CalculatorServicer)
                  │
                  ├──► server.py imports and implements CalculatorServicer
                  └──► client.py imports and uses CalculatorStub
```

---

## Key Learning Points

1. **The `.proto` file is the contract** — both server and client are generated from it
2. **Never edit generated files** — regenerate them if the proto changes
3. **Streaming uses generators** — `yield` on server side, generator functions on client side
4. **Errors use status codes** — `grpc.StatusCode.INVALID_ARGUMENT` not HTTP 400
5. **Channel vs Stub** — channel is the connection, stub is the proxy you call methods on