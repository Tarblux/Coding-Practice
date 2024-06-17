# Majority Element

Problem: 169
Official Difficulty: easy
Feels Like : easy breazy
My Understanding: Fully Understand
Topic: Counting, Divide and Conquer, array, hash table
Link: https://leetcode.com/problems/majority-element/description/
Completed On : June 16, 2024
Last Review: June 16, 2024
Days Since Review: 0

## Problem

---

Given an array `nums` of size `n`, return *the majority element*.

The majority element is the element that appears more than `⌊n / 2⌋` times. You may assume that the majority element always exists in the array.

**Example 1:**

```
Input: nums = [3,2,3]
Output: 3

```

**Example 2:**

```
Input: nums = [2,2,1,1,1,2,2]
Output: 2

```

**Constraints:**

- `n == nums.length`
- `1 <= n <= 5 * 104`
- `109 <= nums[i] <= 109`

**Follow-up:**

Could you solve the problem in linear time and in

```
O(1)
```

space?

## My Solutions

---

```python
class Solution:
    def majorityElement(self, nums: List[int]) -> int:

        majority_num = len(nums) / 2 

        nums_dict = {}

        for num in nums : 

            nums_dict[num] = nums_dict.get(num,0) + 1

            if nums_dict[num] > majority_num : 

                return num
```

```python

```

## Optimal Solutions

---

## Notes

---

 

## Related Videos

---

[https://youtu.be/7pnhv842keE](https://youtu.be/7pnhv842keE)