# Linked Lists

## Introduction to Linked Lists

Linked lists are a fundamental data structure in computer science used to organize and manage data. Unlike arrays, linked lists do not store elements in contiguous memory locations. Instead, they consist of nodes, where each node contains data and a reference (or link) to the next node in the sequence.

### Types of Linked Lists

1. **Singly Linked List:**
    - Each node points to the next node in the sequence.
    - The last node points to `None` to indicate the end.
    
    ```python
    class Node:
        def __init__(self, data=None):
            self.data = data
            self.next = None
    
    ```
    
    Example:
    
    ```
    1 -> 2 -> 3 -> None
    
    ```
    
2. **Doubly Linked List:**
    - Each node has references to both the next and the previous nodes.
    
    ```python
    class Node:
        def __init__(self, data=None):
            self.data = data
            self.next = None
            self.prev = None
    
    ```
    
    Example:
    
    ```
    None <- 1 <-> 2 <-> 3 -> None
    
    ```
    
3. **Circular Linked List:**
    - The last node points back to the first node, forming a circle.
    
    Example:
    
    ```
    1 -> 2 -> 3 -> 1 -> ...
    
    ```
    

## Basic Operations on Linked Lists

### 1. Insertion

### a. Insert at the Beginning

```python
def insert_at_beginning(head, data):
    new_node = Node(data)
    new_node.next = head
    return new_node

```

### b. Insert at the End

```python
def insert_at_end(head, data):
    new_node = Node(data)
    if not head:
        return new_node
    current = head
    while current.next:
        current = current.next
    current.next = new_node
    return head

```

### c. Insert at a Specific Position

```python
def insert_at_position(head, data, position):
    new_node = Node(data)
    if position == 0:
        new_node.next = head
        return new_node
    current = head
    for _ in range(position - 1):
        if not current:
            raise ValueError("Invalid position")
        current = current.next
    new_node.next = current.next
    current.next = new_node
    return head

```

### 2. Deletion

### a. Delete at the Beginning

```python
def delete_at_beginning(head):
    if not head:
        return None
    return head.next

```

### b. Delete at the End

```python
def delete_at_end(head):
    if not head:
        return None
    if not head.next:
        return None
    current = head
    while current.next.next:
        current = current.next
    current.next = None
    return head

```

### c. Delete at a Specific Position

```python
def delete_at_position(head, position):
    if not head:
        return None
    if position == 0:
        return head.next
    current = head
    for _ in range(position - 1):
        if not current or not current.next:
            raise ValueError("Invalid position")
        current = current.next
    current.next = current.next.next
    return head

```

### 3. Traversal

```python
def print_linked_list(head):
    current = head
    while current:
        print(current.data, end=" -> ")
        current = current.next
    print("None")

```

### 4. Searching

```python
def search_linked_list(head, target):
    current = head
    index = 0
    while current:
        if current.data == target:
            return index
        current = current.next
        index += 1
    return -1

```

## Advanced Concepts

### 1. Circular Linked Lists

- Ensure that the last node points back to the first node.

### 2. Doubly Linked Lists

- Allow traversal in both directions.

### 3. Dummy Nodes

- Introduce a dummy node at the beginning to simplify edge cases.

```python
def insert_at_beginning(head, data):
    new_node = Node(data)
    dummy = Node()
    dummy.next = head
    new_node.next = dummy.next
    return new_node

```

### 4. Runner Technique

- Use two pointers to traverse the linked list at different speeds.

```python
def has_cycle(head):
    slow = head
    fast = head
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next
        if slow == fast:
            return True
    return False

```

### 5. Merge Two Sorted Linked Lists

```python
def merge_sorted_lists(list1, list2):
    dummy = Node()
    current = dummy
    while list1 and list2:
        if list1.data < list2.data:
            current.next = list1
            list1 = list1.next
        else:
            current.next = list2
            list2 = list2.next
        current = current.next
    current.next = list1 or list2
    return dummy.next

```

### 6. Reverse Linked List

```python
def reverse_linked_list(head):
    prev = None
    current = head
    while current:
        next_node = current.next
        current.next = prev
        prev = current
        current = next_node
    return prev

```

### 7. Detect and Remove Cycle

```python
def detect_and_remove_cycle(head):
    slow = head
    fast = head
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next
        if slow == fast:
            # Cycle detected
            slow = head
            while slow.next != fast.next:
                slow = slow.next
                fast = fast.next
            fast.next = None  # Remove the cycle
            return head
    return head

```

## Conclusion

Linked lists are a versatile data structure with various applications in computer science. Understanding their basic operations and advanced concepts, such as handling cycles and merging sorted lists, is essential for efficient algorithm design and problem-solving. Whether implementing a simple linked list or dealing with more complex scenarios, these concepts form the foundation for mastering linked list manipulation in Python.