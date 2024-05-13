# Missing Ranges

Problem: 163
Official Difficulty: easy
Feels Like : easy
My Understanding: Fully Understand
Topic: array
Link: https://leetcode.com/problems/missing-ranges/description/?envType=study-plan-v2&envId=programming-skills
Completed On : May 8, 2024
Last Review: May 8, 2024
Days Since Review: 4

## Problem

---

You are given an inclusive range `[lower, upper]` and a **sorted unique** integer array `nums`, where all elements are within the inclusive range.

A number `x` is considered **missing** if `x` is in the range `[lower, upper]` and `x` is not in `nums`.

Return *the **shortest sorted** list of ranges that **exactly covers all the missing numbers***. That is, no element of `nums` is included in any of the ranges, and each missing number is covered by one of the ranges.

**Example 1:**

```
Input: nums = [0,1,3,50,75], lower = 0, upper = 99
Output: [[2,2],[4,49],[51,74],[76,99]]
Explanation: The ranges are:
[2,2]
[4,49]
[51,74]
[76,99]
```

**Example 2:**

```
Input: nums = [-1], lower = -1, upper = -1
Output: []
Explanation: There are no missing ranges since there are no missing numbers.
```

**Constraints:**

- `109 <= lower <= upper <= 109`
- `0 <= nums.length <= 100`
- `lower <= nums[i] <= upper`
- All the values of `nums` are **unique**.

## My Solutions

---

```python
class Solution:
    def findMissingRanges(self, nums: List[int], lower: int, upper: int) -> List[List[int]]:

        if len(nums) == 0:
            return [[lower,upper]]

        output = []

        if nums[0] > lower :
            output.append([lower,nums[0]-1])

        for i in range(1,len(nums)):

            if nums[i] - nums[i-1] != 1 :
                output.append([nums[i-1]+1,nums[i]-1])

        if nums[-1] < upper :
            output.append([nums[-1]+1,upper])

        return output
```

```python

```

## Optimal Solutions

---

## Notes

---

 

## Related Videos

---

[https://youtu.be/42pJ5G2Ttz0?si=jIjqdANQbnPvkJIH](https://youtu.be/42pJ5G2Ttz0?si=jIjqdANQbnPvkJIH)