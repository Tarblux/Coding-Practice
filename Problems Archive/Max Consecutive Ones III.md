# Max Consecutive Ones III

Problem: 1004
Official Difficulty: medium
Feels Like : medium
Topic: array, binary search, binary tree, prefix sum
Link: https://leetcode.com/problems/max-consecutive-ones-iii/description/
Completed On : January 7, 2024
My Understanding: I Have No Idea
Last Review: January 7, 2024
Days Since Review: 34

## Problem

---

Given a binary array `nums` and an integer `k`, return *the maximum number of consecutive* `1`*'s in the array if you can flip at most* `k` `0`'s.

**Example 1:**

```
Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
```

**Example 2:**

```
Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.

```

**Constraints:**

- `1 <= nums.length <= 105`
- `nums[i]` is either `0` or `1`.
- `0 <= k <= nums.length`

## My Solutions

---

```python
class Solution:
    def longestOnes(self, nums: List[int], k: int) -> int:

        left = 0
        right = 0
        max_length = 0
        count = {0: 0, 1: 0}

        while right < len(nums):

            count[nums[right]] += 1
            right += 1

            while count[0] > k:
                count[nums[left]] -= 1
                left += 1

            max_length = max(max_length, right - left)

        return max_length
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