# Find Median from Data Stream

Problem: 295
Official Difficulty: hard
Feels Like : hard
My Understanding: Needs Review
Topic: Data Stream, Heap(Priority Queue), design, sorting, two pointers
Link: https://leetcode.com/problems/find-median-from-data-stream/description/?envType=problem-list-v2&envId=m7475vs1&difficulty=HARD
Completed On : December 10, 2024
Last Review: December 10, 2024
Days Since Review: 82
Neetcode: Yes

## Problem

---

The **median** is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.

- For example, for `arr = [2,3,4]`, the median is `3`.
- For example, for `arr = [2,3]`, the median is `(2 + 3) / 2 = 2.5`.

Implement the MedianFinder class:

- `MedianFinder()` initializes the `MedianFinder` object.
- `void addNum(int num)` adds the integer `num` from the data stream to the data structure.
- `double findMedian()` returns the median of all elements so far. Answers within `105` of the actual answer will be accepted.

**Example 1:**

```
Input
["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
[[], [1], [2], [], [3], []]
Output
[null, null, null, 1.5, null, 2.0]

Explanation
MedianFinder medianFinder = new MedianFinder();
medianFinder.addNum(1);    // arr = [1]
medianFinder.addNum(2);    // arr = [1, 2]
medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
medianFinder.addNum(3);    // arr[1, 2, 3]
medianFinder.findMedian(); // return 2.0
```

**Constraints:**

- `105 <= num <= 105`
- There will be at least one element in the data structure before calling `findMedian`.
- At most `5 * 104` calls will be made to `addNum` and `findMedian`.

**Follow up:**

- If all integer numbers from the stream are in the range `[0, 100]`, how would you optimize your solution?
- If `99%` of all integer numbers from the stream are in the range `[0, 100]`, how would you optimize your solution?

## My Solutions

---

```python

```

```python

```

## Optimal Solutions

---

To maintain the median in a data stream, use two heaps: a max-heap for the lower half of numbers and a min-heap for the upper half. Ensure both heaps differ in size by at most one element. The max-heap stores smaller numbers (with the max at the top), and the min-heap stores larger numbers (with the min at the top).

When a new number arrives, decide which heap to put it in based on its value relative to the heaps’ tops. If the max-heap is empty or the number is less than or equal to the max-heap’s top, push it into the max-heap. Otherwise, push it into the min-heap. After insertion, rebalance if one heap’s size exceeds the other’s by more than one.

To find the median:

- If both heaps are of equal size, the median is the average of the tops of both heaps.
- If one heap has an extra element, the median is the top of that heap.

This approach ensures O(log n) insertion time and O(1) median retrieval time.

**Code:**

```python
import heapq

class MedianFinder:

    def __init__(self):
        self.max_heap = []  # Stores the smaller half (negated values for max behavior)
        self.min_heap = []  # Stores the larger half

    def addNum(self, num: int) -> None:
        # Decide where to push the new number
        if not self.max_heap or num <= -self.max_heap[0]:
            heapq.heappush(self.max_heap, -num)
        else:
            heapq.heappush(self.min_heap, num)

        # Rebalance heaps
        if len(self.max_heap) > len(self.min_heap) + 1:
            val = -heapq.heappop(self.max_heap)
            heapq.heappush(self.min_heap, val)
        elif len(self.min_heap) > len(self.max_heap) + 1:
            val = heapq.heappop(self.min_heap)
            heapq.heappush(self.max_heap, -val)

    def findMedian(self) -> float:
        if len(self.max_heap) == len(self.min_heap):
            return (-self.max_heap[0] + self.min_heap[0]) / 2
        elif len(self.max_heap) > len(self.min_heap):
            return float(-self.max_heap[0])
        else:
            return float(self.min_heap[0])

```

## Notes

---

 

## Related Videos

---

[https://www.youtube.com/watch?v=itmhHWaHupI&pp=ygUcZmluZCBtZWRpYW4gZnJvbSBkYXRhIHN0cmVhbQ%3D%3D](https://www.youtube.com/watch?v=itmhHWaHupI&pp=ygUcZmluZCBtZWRpYW4gZnJvbSBkYXRhIHN0cmVhbQ%3D%3D)