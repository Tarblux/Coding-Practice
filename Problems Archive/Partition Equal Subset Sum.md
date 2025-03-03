# Partition Equal Subset Sum

Problem: 416
Official Difficulty: medium
Feels Like : medium
My Understanding: Mostly Understand, Needs Review
Topic: array, dynamic programming, neetcode150
Link: https://leetcode.com/problems/partition-equal-subset-sum/description/
Completed On : February 12, 2025
Last Review: February 12, 2025
Days Since Review: 18
Neetcode: Yes

## Problem

---

Given an integer array `nums`, return `true` *if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or* `false` *otherwise*.

**Example 1:**

```
Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
```

**Example 2:**

```
Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.
```

**Constraints:**

- `1 <= nums.length <= 200`
- `1 <= nums[i] <= 100`

## My Solutions

---

```python
class Solution:
    def canPartition(self, nums: List[int]) -> bool:

        total = sum(nums)

        if total % 2 != 0:
            return False

        subsum = total // 2
        memo = {}

        def partition(nums,subset_sum,n):

            if subset_sum == 0:
                return True
            elif subset_sum < 0 or n == 0:
                return False

            if (subset_sum,n) in memo:
                return memo[(subset_sum,n)]

            # include = 
            # exclude = 

            memo[(subset_sum,n)] = (partition(nums,subset_sum - nums[n-1],n-1) or partition(nums,subset_sum,n-1))

            return memo[(subset_sum,n)]

        return partition(nums,subsum,len(nums)-1)
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