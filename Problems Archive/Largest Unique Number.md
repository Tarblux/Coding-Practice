# Largest Unique Number

Problem: 1133
Official Difficulty: easy
Feels Like : easy
My Understanding: Fully Understand
Topic: array, hash table, sorting
Link: https://leetcode.com/problems/largest-unique-number/description/
Completed On : October 6, 2024
Last Review: October 6, 2024
Days Since Review: 147
Neetcode: No

## Problem

---

Given an integer array `nums`, return *the largest integer that only occurs once*. If no integer occurs once, return `-1`.

**Example 1:**

```
Input: nums = [5,7,3,9,4,9,8,3,1]
Output: 8
Explanation: The maximum integer in the array is 9 but it is repeated. The number 8 occurs only once, so it is the answer.
```

**Example 2:**

```
Input: nums = [9,9,8,8]
Output: -1
Explanation: There is no number that occurs only once.
```

**Constraints:**

- `1 <= nums.length <= 2000`
- `0 <= nums[i] <= 1000`

## My Solutions

---

```python
class Solution:
    def largestUniqueNumber(self, nums: List[int]) -> int:

        largest = -1
        freq = Counter(nums)

        for num in nums:

            if freq[num] > 1:
                continue

            largest = max(num,largest)

        return largest    
```

```python

```

## Optimal Solutions

---

## Notes

---

 

## Related Videos

---

[https://www.notion.so](https://www.notion.so)