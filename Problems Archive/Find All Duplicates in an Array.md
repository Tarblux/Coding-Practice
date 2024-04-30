# Find All Duplicates in an Array

Problem: 442
Official Difficulty: medium
Feels Like : medium
My Understanding: Needs Review
Topic: array, hash table
Link: https://leetcode.com/problems/find-all-duplicates-in-an-array/description/
Completed On : March 25, 2024
Last Review: March 25, 2024
Days Since Review: 36

## Problem

---

Given an integer array `nums` of length `n` where all the integers of `nums` are in the range `[1, n]` and each integer appears **once** or **twice**, return *an array of all the integers that appears **twice***.

You must write an algorithm that runs in `O(n)` time and uses only constant extra space.

**Example 1:**

```
Input: nums = [4,3,2,7,8,2,3,1]
Output: [2,3]
```

**Example 2:**

```
Input: nums = [1,1,2]
Output: [1]
```

**Example 3:**

```
Input: nums = [1]
Output: []
```

**Constraints:**

- `n == nums.length`
- `1 <= n <= 105`
- `1 <= nums[i] <= n`
- Each element in `nums` appears **once** or **twice**.

## My Solutions

---

```python
class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:

        output = []

        for num in nums:

            num = abs(num)

            if nums[num-1] < 0:
                output.append(num)

            nums[num-1] = - nums[num-1]

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

[https://www.notion.so](https://www.notion.so)