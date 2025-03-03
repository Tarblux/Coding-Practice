# Maximum Product Subarray

Problem: 152
Official Difficulty: medium
Feels Like : hard
My Understanding: Mostly Understand
Topic: array, dynamic programming
Link: https://leetcode.com/problems/maximum-product-subarray/description/
Completed On : February 1, 2025
Last Review: February 1, 2025
Days Since Review: 29
Neetcode: Yes

## Problem

---

Given an integer array `nums`, find a

subarray

that has the largest product, and return

*the product*

.

The test cases are generated so that the answer will fit in a **32-bit** integer.

**Example 1:**

```
Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
```

**Example 2:**

```
Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
```

**Constraints:**

- `1 <= nums.length <= 2 * 104`
- `10 <= nums[i] <= 10`
- The product of any subarray of `nums` is **guaranteed** to fit in a **32-bit** integer.

## My Solutions

---

```python
class Solution:
    def maxProduct(self, nums: List[int]) -> int:

        if not nums:
            return 0

        largest = nums[0]
        smallest = nums[0]

        output = largest

        for i in range(1, len(nums)):

            prev_largest = largest
            prev_smallest = smallest
            
            largest = max(nums[i], nums[i] * prev_largest, nums[i] * prev_smallest)
            smallest =min(nums[i], nums[i] * prev_largest, nums[i] * prev_smallest)
            
            output = max(output, largest)

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