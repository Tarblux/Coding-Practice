# Subarray Sum Equals K

Problem: 560
Official Difficulty: medium
Feels Like : medium
My Understanding: Mostly Understand
Topic: array, hash table, prefix sum
Link: https://leetcode.com/problems/subarray-sum-equals-k/description/
Completed On : February 25, 2025
Last Review: February 25, 2025
Days Since Review: 5
Neetcode: No

## Problem

---

Given an array of integers `nums` and an integer `k`, return *the total number of subarrays whose sum equals to* `k`.

A subarray is a contiguous **non-empty** sequence of elements within an array.

**Example 1:**

```
Input: nums = [1,1,1], k = 2
Output: 2
```

**Example 2:**

```
Input: nums = [1,2,3], k = 3
Output: 2
```

**Constraints:**

- `1 <= nums.length <= 2 * 104`
- `1000 <= nums[i] <= 1000`
- `107 <= k <= 107`

## My Solutions

---

```python
class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:

        n = len(nums)
        prefix_sum = 0
        prefix_counts = defaultdict(int)
        prefix_counts[0] = 1

        output = 0

        for i in range(n):
            
            prefix_sum += nums[i]
            
            # need is basically we just try to solve for prefix[i] in prefix[j+1] - prefix[i] = k
            need = prefix_sum - k
            output += prefix_counts[need]
            prefix_counts[prefix_sum] += 1

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