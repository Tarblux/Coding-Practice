# Design HashSet

Problem: 705
Official Difficulty: easy
Feels Like : hard
My Understanding: Needs Review
Topic: array, design, hash function, hash table, linked list
Link: https://leetcode.com/problems/design-hashset/description/
Completed On : June 4, 2024
Last Review: June 4, 2024
Days Since Review: 5

## Problem

---

Design a HashSet without using any built-in hash table libraries.

Implement `MyHashSet` class:

- `void add(key)` Inserts the value `key` into the HashSet.
- `bool contains(key)` Returns whether the value `key` exists in the HashSet or not.
- `void remove(key)` Removes the value `key` in the HashSet. If `key` does not exist in the HashSet, do nothing.

**Example 1:**

```
Input
["MyHashSet", "add", "add", "contains", "contains", "add", "contains", "remove", "contains"]
[[], [1], [2], [1], [3], [2], [2], [2], [2]]
Output
[null, null, null, true, false, null, true, null, false]

Explanation
MyHashSet myHashSet = new MyHashSet();
myHashSet.add(1);      // set = [1]
myHashSet.add(2);      // set = [1, 2]
myHashSet.contains(1); // return True
myHashSet.contains(3); // return False, (not found)
myHashSet.add(2);      // set = [1, 2]
myHashSet.contains(2); // return True
myHashSet.remove(2);   // set = [1]
myHashSet.contains(2); // return False, (already removed)
```

**Constraints:**

- `0 <= key <= 106`
- At most `104` calls will be made to `add`, `remove`, and `contains`.

## My Solutions

---

```python
class MyHashSet:

    def __init__(self):
        self.collection = [False for _ in range(10**6 + 1)]

    def add(self, key: int) -> None:
        
        self.collection[key] = True

    def remove(self, key: int) -> None:

        self.collection[key] = False
        

    def contains(self, key: int) -> bool:

        return self.collection[key] == True
        

# Your MyHashSet object will be instantiated and called as such:
# obj = MyHashSet()
# obj.add(key)
# obj.remove(key)
# param_3 = obj.contains(key)
```

```python

```

## Optimal Solutions

---

### Optimal Solution and Explanation

To implement a Hash Set, we can use a combination of an array (to store the buckets) and linked lists (to handle collisions within each bucket). This approach provides an efficient way to manage the elements with average O(1) time complexity for add, remove, and contains operations.

### Steps:

1. **Define the Bucket and Node Classes**:
    - A `Node` class to represent each element in the linked list.
    - A `Bucket` class to manage collisions within a bucket using a linked list.
2. **Define the HashSet Class**:
    - Initialize the hash set with a fixed number of buckets.
    - Implement the `hash` function to determine the bucket index for a given key.
    - Implement `add`, `remove`, and `contains` methods using the `Bucket` class.

### Python Code

Here’s the Python code to achieve this:

```python
class Node:
    def __init__(self, value):
        self.value = value
        self.next = None

class Bucket:
    def __init__(self):
        self.head = Node(0)  # Sentinel node

    def insert(self, value):
        if not self.exists(value):
            new_node = Node(value)
            new_node.next = self.head.next
            self.head.next = new_node

    def delete(self, value):
        prev, curr = self.head, self.head.next
        while curr:
            if curr.value == value:
                prev.next = curr.next
                return
            prev, curr = curr, curr.next

    def exists(self, value):
        curr = self.head.next
        while curr:
            if curr.value == value:
                return True
            curr = curr.next
        return False

class MyHashSet:
    def __init__(self):
        self.key_space = 2069
        self.buckets = [Bucket() for _ in range(self.key_space)]

    def _hash(self, key):
        return key % self.key_space

    def add(self, key):
        bucket_index = self._hash(key)
        self.buckets[bucket_index].insert(key)

    def remove(self, key):
        bucket_index = self._hash(key)
        self.buckets[bucket_index].delete(key)

    def contains(self, key):
        bucket_index = self._hash(key)
        return self.buckets[bucket_index].exists(key)

# Example usage
myHashSet = MyHashSet()
myHashSet.add(1)
myHashSet.add(2)
print(myHashSet.contains(1))  # returns True
print(myHashSet.contains(3))  # returns False
myHashSet.add(2)
print(myHashSet.contains(2))  # returns True
myHashSet.remove(2)
print(myHashSet.contains(2))  # returns False

```

### Explanation

1. **Node Class**:
    - Represents an element in the linked list with a value and a reference to the next node.
2. **Bucket Class**:
    - Manages a linked list to handle collisions within a bucket.
    - `insert` method adds a new element if it does not already exist.
    - `delete` method removes an element if it exists.
    - `exists` method checks if an element is present in the bucket.
3. **MyHashSet Class**:
    - Initializes an array of `Bucket` objects.
    - `_hash` method computes the bucket index for a given key.
    - `add` method inserts the key into the appropriate bucket.
    - `remove` method removes the key from the appropriate bucket.
    - `contains` method checks if the key exists in the appropriate bucket.

### Time Complexity Analysis

- **add, remove, contains**: Each of these operations runs in average O(1) time due to the efficient handling of collisions with linked lists and the uniform distribution provided by the hash function.
- **Worst-case Time Complexity**: O(n) if all keys hash to the same bucket, but this is rare with a good hash function and a reasonable number of buckets.

### Space Complexity Analysis

- **Space Complexity**: O(n + k), where `n` is the number of elements and `k` is the number of buckets.
    - The linked list within each bucket only grows as needed.

### Explain Like I'm Five (ELI5)

Imagine you have a big drawer with many small compartments, and you want to store your toys in an organized way:

1. **Compartments (Buckets)**: Each compartment can hold multiple toys (elements).
2. **Labels (Hash Function)**: You have a special label maker that tells you which compartment to put each toy in based on a number (hashing).
3. **Linked Chains (Linked Lists)**: If two toys need to go into the same compartment, you link them together in a chain.

By using compartments and linking toys in the same compartment, you can quickly find, add, or remove any toy without having to look through the entire drawer.

## Notes

---

 

## Related Videos

---

[https://www.youtube.com/watch?v=VymjPQUXjL8&pp=ygUPZGVzaWduIGhhc2ggc2V0](https://www.youtube.com/watch?v=VymjPQUXjL8&pp=ygUPZGVzaWduIGhhc2ggc2V0)