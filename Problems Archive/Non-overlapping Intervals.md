# Non-overlapping Intervals

Problem: 435
Official Difficulty: medium
Feels Like : medium
Topic: array, dynamic programming, greedy, sorting
Link: https://leetcode.com/problems/non-overlapping-intervals/description/
Completed On : January 26, 2024
My Understanding: Needs Review
Last Review: January 26, 2024
Days Since Review: 15

## Problem

---

Given an array of intervals `intervals` where `intervals[i] = [starti, endi]`, return *the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping*.

**Example 1:**

```
Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.
```

**Example 2:**

```
Input: intervals = [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping
```

**Example 3:**

```
Input: intervals = [[1,2],[2,3]]
Output: 0
Explanation: You don't need to remove any of the intervals since they're already non-overlapping.
```

**Constraints:**

- `1 <= intervals.length <= 105`
- `intervals[i].length == 2`
- `5 * 104 <= starti < endi <= 5 * 104`

## My Solutions

---

```python
class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:

        def pickfirstx(x):

            return x[0]

        def overlapped(interval1 , interval2):

            start1 , start2 = interval1[0] , interval2[0]

            end1 , end2 = interval1[1] , interval2[1]

            return (start2 < end1 and end2 > start1)

        min_overlaps = 0

        sorted_intervals = sorted(intervals , key = pickfirstx)

        cur1 = sorted_intervals[0]

        for i in range(1,len(sorted_intervals)):

            if overlapped(cur1 , sorted_intervals[i]) :

                min_overlaps += 1

                if cur1[1] < sorted_intervals[i][1] : 

                    continue 

                else : 

                    cur1 = sorted_intervals[i]

            else : 

                cur1 = sorted_intervals[i]

        return min_overlaps
```

```python

```

## Optimal Solutions

---

### Explain Like I am Five (ELI5)

---

## Notes

---

 

## Related Videos

---

[https://www.notion.so](https://www.notion.so)