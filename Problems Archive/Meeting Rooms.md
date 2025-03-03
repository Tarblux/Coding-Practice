# Meeting Rooms

Problem: 252
Official Difficulty: easy
Feels Like : easy breazy
My Understanding: Fully Understand
Topic: array, sorting
Link: https://leetcode.com/problems/meeting-rooms/description/?envType=problem-list-v2&envId=sorting
Completed On : October 15, 2024
Last Review: October 15, 2024
Days Since Review: 138
Neetcode: Yes

## Problem

---

Given an array of meeting time `intervals` where `intervals[i] = [starti, endi]`, determine if a person could attend all meetings.

**Example 1:**

```
Input: intervals = [[0,30],[5,10],[15,20]]
Output: false

```

**Example 2:**

```
Input: intervals = [[7,10],[2,4]]
Output: true

```

**Constraints:**

- `0 <= intervals.length <= 104`
- `intervals[i].length == 2`
- `0 <= starti < endi <= 106`

## My Solutions

---

```python
class Solution:
    def canAttendMeetings(self, intervals: List[List[int]]) -> bool:

        if len(intervals) == 1:
            return True

        intervals.sort()

        for i in range(1,len(intervals)):

            _ , last_end = intervals[i-1]
            next_start , _ = intervals[i]

            if next_start < last_end:
                return False

        return True

```

```python

```

## Optimal Solutions

---

```jsx
class Solution:
    def canAttendMeetings(self, intervals: List[List[int]]) -> bool:
        intervals.sort()
        for i in range(len(intervals) - 1):
            if intervals[i][1] > intervals[i + 1][0]:
                return False
        return True
```

**Complexity Analysis**

- Time complexity : *O*(*n*log*n*).
    
    The time complexity is dominated by sorting. Once the array has been sorted, only *O*(*n*) time is taken to go through the array and determine if there is any overlap.
    
- Space complexity : *O*(1).
    
    Since no additional space is allocated.
    

## Notes

---

 

## Related Videos

---

[https://www.notion.so](https://www.notion.so)