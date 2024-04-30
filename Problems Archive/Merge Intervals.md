# Merge Intervals

Problem: 56
Official Difficulty: medium
Feels Like : medium
My Understanding: Mostly Understand, Needs Review
Topic: array, sorting
Link: https://leetcode.com/problems/merge-intervals/description/?envType=study-plan-v2&envId=top-interview-150
Completed On : April 29, 2024
Last Review: April 29, 2024
Days Since Review: 1

## Problem

---

Given an array of `intervals` where `intervals[i] = [starti, endi]`, merge all overlapping intervals, and return *an array of the non-overlapping intervals that cover all the intervals in the input*.

**Example 1:**

```
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
```

**Example 2:**

```
Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
```

**Constraints:**

- `1 <= intervals.length <= 104`
- `intervals[i].length == 2`
- `0 <= starti <= endi <= 104`

## My Solutions

---

```python
class Solution:

    def merge(self, intervals: List[List[int]]) -> List[List[int]]:

        if len(intervals) < 2 :

            return intervals

        intervals.sort(key= lambda x : x[0])

        output = [intervals[0]]
        
        for i in range(1,len(intervals)):

            x1,y1 = output[-1]
            x2,y2 = intervals[i]

            if x2 <= y1 :

                output[-1] = [x1,max(y1,y2)]
            else :
                output.append([x2,y2])

        return output
```

```python

```

## Optimal Solutions

---

The optimal solution for the "Merge Intervals" problem in terms of time complexity involves sorting the list of intervals followed by a single pass through the sorted intervals to merge them as necessary. This method efficiently handles overlapping and non-overlapping intervals and ensures all are processed correctly.

### Problem Statement:

Given an array of intervals where intervals[i] = [start_i, end_i], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

### Approach and Rationale:

1. **Sorting**: First, sort the intervals based on their start times. This allows you to easily check for overlaps because if an interval overlaps with another, it will only overlap with the next one in the sorted order (given that the start times are sorted).
2. **One-Pass Merge**:
    - Iterate through the sorted intervals and merge them as necessary.
    - Use a variable to keep track of the last added interval in the output list. Compare this interval with the current interval from the sorted list to decide whether to merge them or add the current interval as a new entry in the output.

### Step-by-Step Solution:

- **Sort** the intervals based on their start values.
- Initialize an output list with the first interval.
- For each subsequent interval:
    - If the current interval's start is less than or equal to the end of the last interval in the output list, there is an overlap. Merge the current interval with the last interval in the output list by updating the end of the last interval to be the maximum of its current end and the end of the current interval.
    - If there is no overlap, add the current interval to the output list.
- Return the output list containing all merged intervals.

### Python Code Implementation:

```python
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if not intervals:
            return []

        # Sort intervals based on the start of each interval
        intervals.sort(key=lambda x: x[0])

        output = [intervals[0]]  # Start with the first interval

        for i in range(1, len(intervals)):
            current = intervals[i]
            last = output[-1]

            # Check if there is an overlap
            if current[0] <= last[1]:
                # There is an overlap, merge the current interval with the last one in output
                output[-1] = [last[0], max(last[1], current[1])]
            else:
                # No overlap, simply add the current interval to output
                output.append(current)

        return output

```

### Complexity Analysis:

- **Time Complexity**: \(O(n \log n)\) due to the sorting step, where \(n\) is the number of intervals. The merging process is \(O(n)\), as each interval is processed once.
- **Space Complexity**: \(O(n)\) or \(O(\log n)\), depending on whether the sorting algorithm is in-place. \(O(n)\) is needed for the output list in the worst case.

This method is both optimal and practical, efficiently handling overlapping intervals with minimal operations and ensuring that the solution is easy to understand and maintain.

## Notes

---

 

## Related Videos

---

[https://www.youtube.com/watch?v=44H3cEC2fFM&pp=ygUPbWVyZ2UgaW50ZXJ2YWxz](https://www.youtube.com/watch?v=44H3cEC2fFM&pp=ygUPbWVyZ2UgaW50ZXJ2YWxz)