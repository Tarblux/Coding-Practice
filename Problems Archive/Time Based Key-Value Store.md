# Time Based Key-Value Store

Problem: 981
Official Difficulty: medium
Feels Like : medium
My Understanding: Needs Review
Topic: binary search, design, hash table, string
Link: https://leetcode.com/problems/time-based-key-value-store/description/?envType=problem-list-v2&envId=m74tw92e
Completed On : June 7, 2024
Last Review: June 7, 2024
Days Since Review: 2

## Problem

---

Design a 
time-based key-value data structure that can store multiple values for 
the same key at different time stamps and retrieve the key's value at a 
certain timestamp.

Implement the `TimeMap` class:

- `TimeMap()` Initializes the object of the data structure.
- `void set(String key, String value, int timestamp)` Stores the key `key` with the value `value` at the given time `timestamp`.
- `String get(String key, int timestamp)` Returns a value such that `set` was called previously, with `timestamp_prev <= timestamp`. If there are multiple such values, it returns the value associated with the largest `timestamp_prev`. If there are no values, it returns `""`.

**Example 1:**

```
Input
["TimeMap", "set", "get", "get", "set", "get", "get"]
[[], ["foo", "bar", 1], ["foo", 1], ["foo", 3], ["foo", "bar2", 4], ["foo", 4], ["foo", 5]]
Output
[null, null, "bar", "bar", null, "bar2", "bar2"]

Explanation
TimeMap timeMap = new TimeMap();
timeMap.set("foo", "bar", 1);  // store the key "foo" and value "bar" along with timestamp = 1.
timeMap.get("foo", 1);         // return "bar"
timeMap.get("foo", 3);         // return "bar", since there is no value corresponding to foo at timestamp 3 and timestamp 2, then the only value is at timestamp 1 is "bar".
timeMap.set("foo", "bar2", 4); // store the key "foo" and value "bar2" along with timestamp = 4.
timeMap.get("foo", 4);         // return "bar2"
timeMap.get("foo", 5);         // return "bar2"
```

**Constraints:**

- `1 <= key.length, value.length <= 100`
- `key` and `value` consist of lowercase English letters and digits.
- `1 <= timestamp <= 107`
- All the timestamps `timestamp` of `set` are strictly increasing.
- At most `2 * 105` calls will be made to `set` and `get`.

## My Solutions

---

```python
class TimeMap:

    """
    - Make Dictionary to store data 

    - Store Tuple for timestamp and value

    - Query key and establish search range 

    - Binary Search for value related to timestamp    
    """

    def __init__(self):

        self.storage = defaultdict(list)
        
    def set(self, key: str, value: str, timestamp: int) -> None:

        self.storage[key].append([value,timestamp])
        # key : (value,timestamp)
        
    def get(self, key: str, timestamp: int) -> str:

        all_times = self.storage[key]

        left = 0
        right = len(all_times) - 1
        
        while left <= right:

            if key not in self.storage:
                return ""

            mid = left + (right-left) // 2

            if all_times[mid][1] == timestamp:
                return all_times[mid][0]
            elif all_times[mid][1] > timestamp:
                right = mid - 1
            else:
                left = mid + 1

        # If left is 0, it means no timestamp is <= the given timestamp

        if right < 0:
            return ""

        return all_times[right][0]
```

```python

```

## Optimal Solutions

---

### Problem Description

Design a time-based key-value data structure that can store multiple values for the same key at different timestamps and retrieve the key's value at a certain timestamp.

Implement the `TimeMap` class:

- `void set(String key, String value, int timestamp)` Stores the key `key` with the value `value` at the given time `timestamp`.
- `String get(String key, int timestamp)` Returns a value such that `set` was called previously with `timestamp_prev <= timestamp`. If there are multiple such values, it returns the one with the largest `timestamp_prev`. If there are no values, it returns an empty string `""`.

### Example

```python
Input:
["TimeMap", "set", "get", "set", "get", "get"]
[[], ["foo", "bar", 1], ["foo", 1], ["foo", "bar2", 4], ["foo", 4], ["foo", 5]]

Output:
[null, null, "bar", null, "bar2", "bar2"]

Explanation:
TimeMap timeMap = new TimeMap();
timeMap.set("foo", "bar", 1); // store the key "foo" and value "bar" along with timestamp = 1.
timeMap.get("foo", 1);        // return "bar"
timeMap.set("foo", "bar2", 4); // store the key "foo" and value "bar2" along with timestamp = 4.
timeMap.get("foo", 4);        // return "bar2"
timeMap.get("foo", 5);        // return "bar2" since there is no value corresponding to foo at timestamp 5, return the latest one before 5 which is "bar2".

```

### Optimal Solution and Explanation

To design this data structure, we can use a dictionary to map each key to a list of tuples, where each tuple contains a value and its corresponding timestamp. For the `get` method, we can use binary search to efficiently find the appropriate value for a given timestamp.

### Steps:

1. **Dictionary of Lists**: Use a dictionary where each key maps to a list of tuples `(timestamp, value)`. The list is kept sorted by timestamps.
2. **Binary Search for Get**: When retrieving a value for a given timestamp, use binary search to find the largest timestamp that is less than or equal to the given timestamp.

### Python Code

Here’s the Python code to achieve this:

```python
from collections import defaultdict
import bisect

class TimeMap:
    def __init__(self):
        self.store = defaultdict(list)

    def set(self, key, value, timestamp):
        # Append the (timestamp, value) tuple to the list for the key
        self.store[key].append((timestamp, value))

    def get(self, key, timestamp):
        if key not in self.store:
            return ""

        values = self.store[key]
        # Use binary search to find the right position
        i = bisect.bisect_right(values, (timestamp, chr(127)))

        if i == 0:
            return ""

        return values[i-1][1]

# Example usage
timeMap = TimeMap()
timeMap.set("foo", "bar", 1)
print(timeMap.get("foo", 1))  # Output: "bar"
timeMap.set("foo", "bar2", 4)
print(timeMap.get("foo", 4))  # Output: "bar2"
print(timeMap.get("foo", 5))  # Output: "bar2"

```

### Explanation

1. **Initialization**:
    - Initialize the `TimeMap` class with a dictionary `store` that maps keys to lists of `(timestamp, value)` tuples.
2. **Set Method**:
    - Append the `(timestamp, value)` tuple to the list corresponding to the key in the dictionary.
3. **Get Method**:
    - Check if the key exists in the dictionary. If not, return an empty string.
    - Use `bisect.bisect_right` to find the index `i` where `(timestamp, value)` could be inserted to maintain sorted order.
    - If `i` is 0, it means there is no valid timestamp less than or equal to the given timestamp, so return an empty string.
    - Otherwise, return the value corresponding to the largest timestamp less than or equal to the given timestamp.

### Time Complexity Analysis

- **Set Method**: `O(1)` on average, since appending to the list is constant time.
- **Get Method**: `O(log n)` for the binary search, where `n` is the number of timestamps for the given key.

### Space Complexity Analysis

- **Space Complexity**: `O(n)`, where `n` is the total number of `set` operations performed. Each `set` operation stores a tuple in the dictionary.

### Explain Like I'm Five (ELI5)

Imagine you have a big book where you keep notes for different topics (keys). Each note is written on a specific page (timestamp). When you want to add a new note for a topic, you just write it on a new page.

When you need to find the latest note before a certain page number for a topic, you quickly flip through the pages to find the last note that was written before that page. By organizing your notes this way, you can quickly find what you wrote for each topic at any given time.

## Notes

---

 

## Related Videos

---

[https://youtu.be/fu2cD_6E8Hw](https://youtu.be/fu2cD_6E8Hw)