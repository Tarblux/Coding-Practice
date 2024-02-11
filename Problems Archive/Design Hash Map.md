# Design Hash Map

Problem: 706
Official Difficulty: easy
Feels Like : easy
Topic: array, design, hash table, linked list
Link: https://leetcode.com/problems/design-hashmap/description/
Completed On : January 27, 2024
My Understanding: Fully Understand
Last Review: January 27, 2024
Days Since Review: 14

## Problem

---

Design a HashMap without using any built-in hash table libraries.

Implement the `MyHashMap` class:

- `MyHashMap()` initializes the object with an empty map.
- `void put(int key, int value)` inserts a `(key, value)` pair into the HashMap. If the `key` already exists in the map, update the corresponding `value`.
- `int get(int key)` returns the `value` to which the specified `key` is mapped, or `1` if this map contains no mapping for the `key`.
- `void remove(key)` removes the `key` and its corresponding `value` if the map contains the mapping for the `key`.

**Example 1:**

```
Input
["MyHashMap", "put", "put", "get", "get", "put", "get", "remove", "get"]
[[], [1, 1], [2, 2], [1], [3], [2, 1], [2], [2], [2]]
Output
[null, null, null, 1, -1, null, 1, null, -1]

Explanation
MyHashMap myHashMap = new MyHashMap();
myHashMap.put(1, 1); // The map is now [[1,1]]
myHashMap.put(2, 2); // The map is now [[1,1], [2,2]]
myHashMap.get(1);    // return 1, The map is now [[1,1], [2,2]]
myHashMap.get(3);    // return -1 (i.e., not found), The map is now [[1,1], [2,2]]
myHashMap.put(2, 1); // The map is now [[1,1], [2,1]] (i.e., update the existing value)
myHashMap.get(2);    // return 1, The map is now [[1,1], [2,1]]
myHashMap.remove(2); // remove the mapping for 2, The map is now [[1,1]]
myHashMap.get(2);    // return -1 (i.e., not found), The map is now [[1,1]]
```

**Constraints:**

- `0 <= key, value <= 106`
- At most `104` calls will be made to `put`, `get`, and `remove`.

## My Solutions

---

```python
class MyHashMap:

    def __init__(self):

        self.map = []

    def put(self, key: int, value: int) -> None:

        for i in range(len(self.map)):

            if self.map[i][0] == key:

                self.map[i][1] = value

                return

        self.map.append([key, value])

    def get(self, key: int) -> int:

        for pair in self.map:

            if pair[0] == key:

                return pair[1]

        return -1

    def remove(self, key: int) -> None:

        for i in range(len(self.map)):

            if self.map[i][0] == key:

                self.map.pop(i)

                return
        

# Your MyHashMap object will be instantiated and called as such:
# obj = MyHashMap()
# obj.put(key,value)
# param_2 = obj.get(key)
# obj.remove(key)
```

```python

```

## Optimal Solutions

---

Designing a hash map (or hash table) involves implementing a data structure that maps keys to values. A basic hash map can be implemented using an array of linked lists (to handle collisions) or an array of arrays. The key operations are `put` (add a key-value pair), `get` (retrieve a value by key), and `remove` (delete a key-value pair).

Here, I'll provide a simple implementation of a hash map using an array of arrays (bucket approach). We'll handle collisions by chaining, which means each bucket can store multiple key-value pairs if they hash to the same bucket.

### Basic Implementation of Hash Map

```python
class MyHashMap:
    def __init__(self):
        # Initialize a large array to minimize collision
        self.size = 1000
        self.buckets = [[] for _ in range(self.size)]

    def put(self, key: int, value: int) -> None:
        # Compute hash to find the correct bucket
        bucket, idx = self._index(key)
        if idx >= 0:
            # Key exists, update the value
            self.buckets[bucket][idx][1] = value
        else:
            # Key does not exist, insert a new key-value pair
            self.buckets[bucket].append([key, value])

    def get(self, key: int) -> int:
        # Compute hash to find the correct bucket
        bucket, idx = self._index(key)
        if idx < 0:
            return -1  # Key not found
        return self.buckets[bucket][idx][1]

    def remove(self, key: int) -> None:
        # Compute hash to find the correct bucket
        bucket, idx = self._index(key)
        if idx >= 0:
            # Remove the key-value pair
            self.buckets[bucket].pop(idx)

    def _index(self, key: int):
        # Helper function to compute hash and find index of key in bucket
        hash_key = key % self.size
        for i, (k, v) in enumerate(self.buckets[hash_key]):
            if k == key:
                return hash_key, i
        return hash_key, -1

```

### Explanation

- `__init__`: Initialize the hash map with a fixed size. Each bucket can hold multiple items (chaining to handle collisions).
- `put`: Insert a new key-value pair or update the value if the key already exists.
- `get`: Retrieve the value for a key. Returns `1` if the key is not found.
- `remove`: Remove the key-value pair if the key exists.
- `_index`: A helper function to compute the hash (bucket index) and find the index of a key in a bucket.

### Complexity Analysis

- **Time Complexity**: Average O(1) for each operation. In the worst case (many collisions), it could be O(n).
- **Space Complexity**: O(n), where `n` is the number of key-value pairs stored in the hash map.

This is a basic implementation of a hash map and is efficient for a moderate number of collisions. For a large number of key-value pairs or high collision scenarios, more sophisticated techniques like dynamic resizing or using a balanced tree in each bucket might be necessary.

### Explain Like I am Five (ELI5)

---

## Notes

---

 

## Related Videos

---

[https://www.notion.so](https://www.notion.so)