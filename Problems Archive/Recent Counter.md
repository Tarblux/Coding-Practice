# Recent Counter

Problem: 933
Official Difficulty: easy
Feels Like : easy
Topic: Data Stream, Queue, design
Link: https://leetcode.com/problems/number-of-recent-calls/
Completed On : December 16, 2023
My Understanding: Mostly Understand
Last Review: December 16, 2023
Days Since Review: 56

## Problem

---

You have a `RecentCounter` class which counts the number of recent requests within a certain time frame.

Implement the `RecentCounter` class:

- `RecentCounter()` Initializes the counter with zero recent requests.
- `int ping(int t)` Adds a new request at time `t`, where `t` represents some time in milliseconds, and returns the number of requests that has happened in the past `3000` milliseconds (including the new request). Specifically, return the
number of requests that have happened in the inclusive range `[t - 3000, t]`.

It is **guaranteed** that every call to `ping` uses a strictly larger value of `t` than the previous call.

**Example 1:**

```
Input
["RecentCounter", "ping", "ping", "ping", "ping"]
[[], [1], [100], [3001], [3002]]
Output
[null, 1, 2, 3, 3]

Explanation
RecentCounter recentCounter = new RecentCounter();
recentCounter.ping(1);     // requests = [1], range is [-2999,1], return 1
recentCounter.ping(100);   // requests = [1,100], range is [-2900,100], return 2
recentCounter.ping(3001);  // requests = [1,100,3001], range is [1,3001], return 3
recentCounter.ping(3002);  // requests = [1,100,3001,3002], range is [2,3002], return 3

```

**Constraints:**

- `1 <= t <= 109`
- Each test case will call `ping` with **strictly increasing** values of `t`.
- At most `104` calls will be made to `ping`.

## My Solutions

---

```python
class RecentCounter:

    def __init__(self):

        self.counter = []     

    def ping(self, t: int) -> int:

        last_3k = t - 3000

        self.counter.append(t)

        while self.counter[0] < last_3k : 

            self.counter.pop(0)

        return len(self.counter)

# Your RecentCounter object will be instantiated and called as such:
# obj = RecentCounter()
# param_1 = obj.ping(t)
```

```python

```

## Optimal Solutions

---

The most optimal solution for the "Number of Recent Calls" problem, also known as the "RecentCounter" problem, is to use a queue to keep track of the recent calls (or "pings"). The key here is to efficiently remove older pings that are no longer within the 3000 milliseconds time frame for every new ping.

### Optimal Solution Approach: Queue

1. **Use a Queue**: Implement the recent counter using a queue data structure (like `deque` in Python) which allows efficient addition and removal of elements.
2. **Add New Ping**: For each new ping, add its timestamp to the queue.
3. **Remove Old Pings**: Remove pings from the front of the queue until all pings are within the last 3000 milliseconds from the current ping time.
4. **Return the Count**: The count of recent calls is the size of the queue after the removal of old pings.

This approach ensures that the queue always contains only the pings within the last 3000 milliseconds, and the length of the queue gives the number of recent calls.

### Python Implementation Using `deque`

```python
from collections import deque

class RecentCounter:
    def __init__(self):
        self.queue = deque()

    def ping(self, t: int) -> int:
        self.queue.append(t)

        # Remove pings older than 3000 milliseconds from t
        while self.queue[0] < t - 3000:
            self.queue.popleft()

        return len(self.queue)

```

### Explanation

- `deque` is used for efficient addition and removal of elements from both ends.
- When a new ping comes in, it is added to the queue.
- The `while` loop removes pings from the front of the queue that are older than 3000 milliseconds from the current ping time.
- The size of the queue, which is the return value, represents the number of pings in the last 3000 milliseconds.

### Complexity Analysis

- **Time Complexity**: O(1) on average for each call to `ping`. While the worst-case scenario for a single call might involve traversing the entire queue, across multiple calls, each ping is added and removed exactly once, leading to an amortized O(1) time complexity.
- **Space Complexity**: O(n), where `n` is the number of pings within the 3000 milliseconds window. This is the space required to store the pings in the queue.

## Notes

---

 

## Related Videos

---

[https://www.youtube.com/watch?v=HlmNEfcgyjM&pp=ygUfbnVtYmVyIG9mIHJlY2VudCBjYWxscyBsZWV0Y29kZQ%3D%3D](https://www.youtube.com/watch?v=HlmNEfcgyjM&pp=ygUfbnVtYmVyIG9mIHJlY2VudCBjYWxscyBsZWV0Y29kZQ%3D%3D)