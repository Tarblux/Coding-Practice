# Queues

### Introduction to Python Queues

- **Python queues** are abstract data structures that follow the First In, First Out (FIFO) principle.
- Unlike stacks, the first element added to the queue will be the first one to be removed.
- Python doesn't have a built-in queue data type, but it can be implemented using lists or collections.deque.

[https://youtu.be/rUUrmGKYwHw](https://youtu.be/rUUrmGKYwHw)

### Creating and Using a Queue

1. **Creating a Queue**
    - Using a list (not recommended for large datasets due to inefficiency in pop operations):
        
        ```python
        queue = []
        
        ```
        
    - Using `collections.deque` for efficient pop and append operations:
        
        ```python
        from collections import deque
        queue = deque()
        
        ```
        
2. **Enqueuing Elements**
    - Adding elements to the end of the queue.
        
        ```python
        queue.append('apple')
        queue.append('ball')
        ```
        
3. **Dequeuing Elements**
    - Removing and returning the first element.
        
        ```python
        dequeued_element = queue.popleft()  # 'apple'
        ```
        

### Queue Operations

1. **Peeking at the First Element**
    - Viewing the first element without removing it.
        
        ```python
        first_element = queue[0]
        ```
        
2. **Checking if Queue is Empty**
    - Determining if the queue is empty.
        
        ```python
        is_empty = not queue
        ```
        
3. **Getting Queue Length**
    - Finding out the number of elements in the queue.
        
        ```python
        queue_length = len(queue)
        ```
        

### Advanced Concepts

1. **Priority Queues**
    - Using `queue.PriorityQueue` to sort elements based on their assigned priority.
    - Example:
        
        ```python
        from queue import PriorityQueue
        pq = PriorityQueue()
        pq.put((2, 'apple'))
        pq.put((1, 'ball'))
        pq.get()  # (1, 'ball')
        ```
        
2. **Thread-Safe Queues**
    - Utilizing `queue.Queue` for thread-safe operations in multi-threaded applications.
    - Example:
        
        ```python
        from queue import Queue
        ts_queue = Queue()
        
        ```
        
3. **Circular Queues**
    - Implementing circular queues where the last position connects back to the first.

### Conclusion

- Queues in Python, implemented via lists or `collections.deque`, provide an effective way to handle data in FIFO order.
- They are essential for tasks like task scheduling, and managing data streams.

---

### Queue Operations Table

| Operation | Description |
| --- | --- |
| append() | Adds an item to the end of the queue |
| popleft() | Removes and returns the first item (deque) |
| [0] | Accesses the first item without removing it |
| len() | Returns the number of items in the queue |
| not queue | Checks if the queue is empty |

---