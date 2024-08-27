# Design Hit Counter

Problem: 362
Official Difficulty: medium
Feels Like : easy
My Understanding: Fully Understand
Topic: Data Stream, Queue, array, binary search, design
Link: https://leetcode.com/problems/design-hit-counter/description/
Completed On : August 20, 2024
Last Review: August 20, 2024
Days Since Review: 6

## Problem

---

Design a hit counter which counts the number of hits received in the past `5` minutes (i.e., the past `300` seconds).

Your system should accept a `timestamp` parameter (**in seconds** granularity), and you may assume that calls are being made to the system in chronological order (i.e., `timestamp` is monotonically increasing). Several hits may arrive roughly at the same time.

Implement the `HitCounter` class:

- `HitCounter()` Initializes the object of the hit counter system.
- `void hit(int timestamp)` Records a hit that happened at `timestamp` (**in seconds**). Several hits may happen at the same `timestamp`.
- `int getHits(int timestamp)` Returns the number of hits in the past 5 minutes from `timestamp` (i.e., the past `300` seconds).

**Example 1:**

```
Input
["HitCounter", "hit", "hit", "hit", "getHits", "hit", "getHits", "getHits"]
[[], [1], [2], [3], [4], [300], [300], [301]]
Output
[null, null, null, null, 3, null, 4, 3]

Explanation
HitCounter hitCounter = new HitCounter();
hitCounter.hit(1);       // hit at timestamp 1.
hitCounter.hit(2);       // hit at timestamp 2.
hitCounter.hit(3);       // hit at timestamp 3.
hitCounter.getHits(4);   // get hits at timestamp 4, return 3.
hitCounter.hit(300);     // hit at timestamp 300.
hitCounter.getHits(300); // get hits at timestamp 300, return 4.
hitCounter.getHits(301); // get hits at timestamp 301, return 3.

```

**Constraints:**

- `1 <= timestamp <= 2 * 109`
- All the calls are being made to the system in chronological order (i.e., `timestamp` is monotonically increasing).
- At most `300` calls will be made to `hit` and `getHits`.

**Follow up:** What if the number of hits per second could be huge? Does your design scale?

## My Solutions

---

```python
class HitCounter:

    def __init__(self):

        self.hits = defaultdict(int)
        self.id = 0
        
    def hit(self, timestamp: int) -> None:

        self.id += 1
        self.hits[self.id] = timestamp
        
    def getHits(self, timestamp: int) -> int:

        total_hits = 0

        low = timestamp - 300
        low = [low,0][low < 0]

        for _ , v in self.hits.items():
						# can simply do v > low since it is chnronological
            if v > low and v <= timestamp:
                total_hits += 1
                
        return total_hits
```

```python

```

## Optimal Solutions

---

### Approach

The problem requires us to maintain a record of hits and efficiently retrieve the count of hits within the past 5 minutes. A simple and effective way to achieve this is to use a combination of a queue and a list to store the timestamps and their corresponding hit counts.

### Design

- **Queue-Based Approach**:
    - We can use a queue to store tuples of (timestamp, count), where `timestamp` represents the time when hits were received, and `count` represents the number of hits at that timestamp.
    - When `getHits()` is called, we remove any hits that are older than 300 seconds from the queue.
    - We then sum up the counts of the remaining hits in the queue.

### Python Implementation

Here’s how you can implement the `HitCounter` class using the described approach:

```python
from collections import deque

class HitCounter:

    def __init__(self):
        # Initialize the queue to store (timestamp, count) tuples
        self.hits = deque()

    def hit(self, timestamp: int) -> None:
        if self.hits and self.hits[-1][0] == timestamp:
            # If the latest hit is at the same timestamp, just increment the count
            self.hits[-1] = (timestamp, self.hits[-1][1] + 1)
        else:
            # Otherwise, add a new record to the deque
            self.hits.append((timestamp, 1))

    def getHits(self, timestamp: int) -> int:
        # Remove all hits that are outside the 300-second window
        while self.hits and self.hits[0][0] <= timestamp - 300:
            self.hits.popleft()

        # Sum the counts of the remaining hits in the queue
        return sum(hit[1] for hit in self.hits)

# Example usage
hitCounter = HitCounter()

hitCounter.hit(1)
hitCounter.hit(2)
hitCounter.hit(3)
print(hitCounter.getHits(4))  # Returns 3

hitCounter.hit(300)
print(hitCounter.getHits(300))  # Returns 4

print(hitCounter.getHits(301))  # Returns 3

```

### Explanation

1. **Initialization**:
    - We initialize a `deque` named `hits` to store pairs of `(timestamp, count)`.
2. **Hit Function**:
    - If the most recent hit in the `deque` is at the same timestamp as the current one, we increment its count.
    - Otherwise, we append a new entry to the `deque`.
3. **GetHits Function**:
    - We first remove any entries from the `deque` that are older than 300 seconds relative to the current `timestamp`.
    - Then, we sum up the counts of the remaining entries to return the total number of hits in the last 5 minutes.

### Complexity Analysis

- **Time Complexity**:
    - `hit(timestamp)`: O(1) - Adding or updating a hit is constant time.
    - `getHits(timestamp)`: O(n) - In the worst case, all `n` entries in the `deque` are within the 300-second window, so summing up the counts takes linear time.
- **Space Complexity**: O(n) - The space complexity is proportional to the number of unique timestamps within the last 300 seconds.

This approach efficiently handles hit recording and retrieval, ensuring that the operations remain performant even as the number of hits grows.

## Notes

---

 

## Related Videos

---

[https://www.notion.so](https://www.notion.so)