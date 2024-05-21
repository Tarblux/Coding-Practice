# Insert Interval

Problem: 57
Official Difficulty: medium
Feels Like : hard
My Understanding: Needs Review
Topic: array
Link: https://leetcode.com/problems/insert-interval/description/
Completed On : May 15, 2024
Last Review: May 15, 2024
Days Since Review: 4

## Problem

---

You are given an array of non-overlapping intervals `intervals` where `intervals[i] = [starti, endi]` represent the start and the end of the `ith` interval and `intervals` is sorted in ascending order by `starti`. You are also given an interval `newInterval = [start, end]` that represents the start and end of another interval.

Insert `newInterval` into `intervals` such that `intervals` is still sorted in ascending order by `starti` and `intervals` still does not have any overlapping intervals (merge overlapping intervals if necessary).

Return `intervals` *after the insertion*.

**Note** that you don't need to modify `intervals` in-place. You can make a new array and return it.

**Example 1:**

```
Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
```

**Example 2:**

```
Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
```

**Constraints:**

- `0 <= intervals.length <= 104`
- `intervals[i].length == 2`
- `0 <= starti <= endi <= 105`
- `intervals` is sorted by `starti` in **ascending** order.
- `newInterval.length == 2`
- `0 <= start <= end <= 105`

## My Solutions

---

```python
class Solution:
    
    def overlap(self, interval1: List[int], interval2: List[int]) -> bool:
        s1, e1 = interval1
        s2, e2 = interval2
        return max(s1, s2) <= min(e1, e2)

    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        merged = []
        added = False
        
        for interval in intervals:
            if self.overlap(interval, newInterval):
                newInterval = [min(interval[0], newInterval[0]), max(interval[1], newInterval[1])]
            elif interval[1] < newInterval[0]:
                merged.append(interval)
            elif interval[0] > newInterval[1]:
                if not added:
                    merged.append(newInterval)
                    added = True
                merged.append(interval)
        
        if not added:
            merged.append(newInterval)
        
        return merged
```

```python

```

## Optimal Solutions

---

Let's solve the LeetCode problem "Insert Interval."

### Problem Description

Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary). You may assume that the intervals were initially sorted according to their start times.

### Example

```python
Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
```

### Optimal Solution and Explanation

The optimal solution involves a single pass through the list of intervals. Here’s the step-by-step process:

1. **Initialization**: Create an empty list to store the resulting intervals.
2. **Iterate through the intervals**:
    - If the current interval ends before the new interval starts, add it to the result.
    - If the current interval starts after the new interval ends, add the new interval to the result (if it hasn't been added yet) and then add the current interval.
    - If the intervals overlap, merge them by updating the new interval to be the union of the overlapping intervals.
3. **Post-iteration**: Add the new interval to the result if it hasn’t been added yet.
4. **Return the result**: The resulting list will have the new interval correctly inserted and merged.

Here's the Python code for this solution:

```python
def insert(intervals, newInterval):
    result = []
    inserted = False

    for interval in intervals:
        if interval[1] < newInterval[0]:
            result.append(interval)
        elif interval[0] > newInterval[1]:
            if not inserted:
                result.append(newInterval)
                inserted = True
            result.append(interval)
        else:  # Overlapping intervals
            newInterval[0] = min(newInterval[0], interval[0])
            newInterval[1] = max(newInterval[1], interval[1])

    if not inserted:
        result.append(newInterval)

    return result

```

### Explanation

- **Initialize** `result` as an empty list to store the final intervals.
- **Iterate through each interval** in `intervals`:
    - If the current interval ends before `newInterval` starts, add it to `result`.
    - If the current interval starts after `newInterval` ends, add `newInterval` (if not already added) and then add the current interval.
    - If the intervals overlap, merge them by updating the `newInterval`'s start and end to be the minimum start and maximum end of the overlapping intervals.
- **Post-iteration**, if `newInterval` wasn't added (meaning it should be added at the end), add it to `result`.
- **Return** the `result`.

### Explain Like I'm Five (ELI5)

Imagine you have a bunch of blocks lined up in order, and each block has a start and end point. You get a new block that you need to add to the lineup. Sometimes the new block can fit perfectly without touching the others, and sometimes it overlaps with one or more blocks.

Here’s what you do:

1. Go through each block in the lineup one by one.
2. If a block is completely before the new block, you put it in a new line.
3. If a block is completely after the new block, you put the new block in the new line first (if it’s not already there) and then put the current block.
4. If a block overlaps with the new block, you merge them into a bigger block.
5. After you’ve gone through all the blocks, make sure the new block is in the new line if it hasn’t been added yet.

This way, you end up with all the blocks in order, with the new block properly inserted and any overlapping blocks merged together.

## Notes

---

 

## Related Videos

---

[https://www.youtube.com/watch?v=A8NUOmlwOlM](https://www.youtube.com/watch?v=A8NUOmlwOlM)