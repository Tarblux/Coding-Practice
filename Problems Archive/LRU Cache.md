# LRU Cache

Problem: 146
Official Difficulty: medium
Feels Like : medium
Topic: design, doubly-linked list, hash table, linked list
Link: https://leetcode.com/problems/lru-cache/description/
Completed On : February 9, 2024
My Understanding: Needs Review
Last Review: February 9, 2024
Days Since Review: 1

## Problem

---

Design a data structure that follows the constraints of a **[Least Recently Used (LRU) cache](https://en.wikipedia.org/wiki/Cache_replacement_policies#LRU)**.

Implement the `LRUCache` class:

- `LRUCache(int capacity)` Initialize the LRU cache with **positive** size `capacity`.
- `int get(int key)` Return the value of the `key` if the key exists, otherwise return `1`.
- `void put(int key, int value)` Update the value of the `key` if the `key` exists. Otherwise, add the `key-value` pair to the cache. If the number of keys exceeds the `capacity` from this operation, **evict** the least recently used key.

The functions `get` and `put` must each run in `O(1)` average time complexity.

**Example 1:**

```
Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4
```

**Constraints:**

- `1 <= capacity <= 3000`
- `0 <= key <= 104`
- `0 <= value <= 105`
- At most `2 * 105` calls will be made to `get` and `put`.

## My Solutions

---

```python
class LRUCache:

    def __init__(self, capacity: int):

        self.cache = OrderedDict()

        self.capacity = capacity

    def get(self, key: int) -> int:

        if key in self.cache:

            self.cache.move_to_end(key)

            return self.cache[key]

        return -1
        
    def put(self, key: int, value: int) -> None:

        if key in self.cache:

            self.cache.move_to_end(key)

        self.cache[key] = value

        if len(self.cache) > self.capacity:
            
            self.cache.popitem(last=False)
```

```python

```

## Optimal Solutions

- Shoot me 🤮🤮

---

The optimal solution for implementing an LRU (Least Recently Used) Cache typically involves combining a hashmap (dictionary in Python) for O(1) access time and a double-linked list for maintaining the order of elements based on their usage (to efficiently update the "recently used" status). This combination allows for O(1) time complexity for both `get` and `put` operations.

### Why Use a Double-Linked List and Hashmap?

- **Hashmap**: Provides O(1) access time to cache items. However, it doesn't naturally maintain the order of items based on their usage.
- **Double-Linked List**: Efficiently maintains items in order of use, allowing quick removal and addition of nodes. Specifically, nodes can be moved or removed in O(1) time, which is crucial for updating the LRU order.

### Implementation

Below is an implementation of an LRU Cache using a hashmap and a double-linked list:

```python
class DLinkedNode:
    def __init__(self, key=0, value=0):
        self.key = key
        self.value = value
        self.prev = None
        self.next = None

class LRUCache:

    def __init__(self, capacity: int):
        self.cache = {}
        # Using dummy head and tail nodes to avoid checking for null nodes
        self.head = DLinkedNode()
        self.tail = DLinkedNode()
        self.head.next = self.tail
        self.tail.prev = self.head
        self.capacity = capacity

    def get(self, key: int) -> int:
        if key in self.cache:
            node = self.cache[key]
            self._move_to_head(node)
            return node.value
        return -1

    def put(self, key: int, value: int) -> None:
        if key in self.cache:
            node = self.cache[key]
            node.value = value
            self._move_to_head(node)
        else:
            node = DLinkedNode(key, value)
            self.cache[key] = node
            self._add_node(node)
            if len(self.cache) > self.capacity:
                removed = self._pop_tail()
                self.cache.pop(removed.key)

    def _add_node(self, node):
        node.prev = self.head
        node.next = self.head.next
        self.head.next.prev = node
        self.head.next = node

    def _remove_node(self, node):
        prev = node.prev
        new = node.next
        prev.next = new
        new.prev = prev

    def _move_to_head(self, node):
        self._remove_node(node)
        self._add_node(node)

    def _pop_tail(self):
        node = self.tail.prev
        self._remove_node(node)
        return node

```

### Key Components

- **DLinkedNode**: Represents an element in the double-linked list, storing the key, value, and pointers to the previous and next nodes.
- **_add_node**, **_remove_node**, **_move_to_head**, **_pop_tail**: Helper methods to manage the double-linked list. These ensure nodes are added to the head (most recently used), moved to the head (on access), or removed from the tail (least recently used).
- **get** and **put**: Implements the cache's main functionality, using the helper methods to maintain the LRU order.

### Complexity Analysis

- **Time Complexity**: O(1) for both `get` and `put` operations.
- **Space Complexity**: O(capacity) since the space is used by the double-linked list and hashmap, proportional to the number of items stored in the cache, which is capped by its capacity.

This implementation efficiently maintains the LRU order without compromising on the quick access and update times essential for a cache mechanism.

## Notes

---

 

## Related Videos

---

[https://www.youtube.com/watch?v=7ABFKPK2hD4](https://www.youtube.com/watch?v=7ABFKPK2hD4)