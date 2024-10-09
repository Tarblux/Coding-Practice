# Heaps / Priority Queues

### Introduction to Heaps in Python

Heaps are specialized tree-based data structures that satisfy the heap property. In a heap, for any given node C, if P is a parent node of C, then the key (the value) of P is either greater than or equal to (in a max heap) or less than or equal to (in a min heap) the key of C. The node at the "top" of the heap (with no parents) is called the root node.

Python’s standard library provides a `heapq` module, which implements a min-heap on top of a regular list, providing a way to efficiently add elements and remove the smallest element.

### Creating a Heap

In Python, a heap is created using a list. The `heapq` module provides functions like `heapify()`, which converts a list into a heap.

```python
import heapq

# Create a heap
heap = [3, 1, 4, 1, 5, 9, 2, 6]
heapq.heapify(heap)  # Transforms the list into a heap
print(heap)  # Output might be [1, 1, 2, 3, 5, 9, 4, 6], representing the heap
```

### Adding Elements

To add an element to the heap, use `heapq.heappush()`.

```python
heapq.heappush(heap, 7)
print(heap)  # Adds 7 maintaining the heap property
```

### Removing Elements

The `heapq.heappop()` function pops the smallest element from the heap.

```python
smallest = heapq.heappop(heap)
print(smallest)  # Removes and returns the smallest element
```

### Accessing the Smallest Element

The smallest element in a heap can be accessed directly as the first element of the list.

```python
print(heap[0])  # Gets the smallest element without removing it
```

### Transforming Lists into Heaps

The `heapq.heapify()` function is used to convert a populated list into a heap in-place.

```python
numbers = [10, 1, 5, 2, 3]
heapq.heapify(numbers)
print(numbers)  # The list 'numbers' is now a heap

```

### nlargest and nsmallest

The `heapq` module also provides functions to find the `n` largest or `n` smallest elements from a iterable.

```python
largest_three = heapq.nlargest(3, heap)
print(largest_three)  # Returns the three largest elements

smallest_three = heapq.nsmallest(3, heap)
print(smallest_three)  # Returns the three smallest elements
```

### Heap Methods and Functions

Here are some common methods and functions provided by the `heapq` module, with placeholders for links to further reading:

| Function | Description |
| --- | --- |
| [heapq.heappush(heap, item)](#) | Adds an item to the heap, maintaining the heap invariant. |
| [heapq.heappop(heap)](#) | Pops and returns the smallest item from the heap, maintaining the heap invariant. |
| [heapq.heapify(x)](#) | Transforms a list into a heap, in-place. |
| [heapq.heapreplace(heap, item)](#) | Pops and returns the smallest item from the heap, and also adds the new item. The heap size doesn't change. |
| [heapq.nlargest(n, iterable, key=None)](#) | Returns a list with the n largest elements from the dataset defined by iterable. |
| [heapq.nsmallest(n, iterable, key=None)](#) | Returns a list with the n smallest elements from the dataset defined by iterable. |

For the most accurate and detailed information, including examples and usage, visiting the [official Python documentation](https://docs.python.org/3/library/heapq.html) for the `heapq` module is highly recommended.
