# Increasing Triplet Subsequence

Problem: 334
Official Difficulty: medium
Feels Like : medium
Topic: array, greedy
Link: https://leetcode.com/problems/increasing-triplet-subsequence/description/
Completed On : January 10, 2024
My Understanding: Mostly Understand, Needs Review
Last Review: January 10, 2024
Days Since Review: 31

## Problem

---

Given an integer array `nums`, return `true` *if there exists a triple of indices* `(i, j, k)` *such that* `i < j < k` *and* `nums[i] < nums[j] < nums[k]`. If no such indices exists, return `false`.

**Example 1:**

```
Input: nums = [1,2,3,4,5]
Output: true
Explanation: Any triplet where i < j < k is valid.

```

**Example 2:**

```
Input: nums = [5,4,3,2,1]
Output: false
Explanation: No triplet exists.

```

**Example 3:**

```
Input: nums = [2,1,5,0,4,6]
Output: true
Explanation: The triplet (3, 4, 5) is valid because nums[3] == 0 < nums[4] == 4 < nums[5] == 6.

```

**Constraints:**

- `1 <= nums.length <= 5 * 105`
- `231 <= nums[i] <= 231 - 1`

**Follow up:** Could you implement a solution that runs in `O(n)` time complexity and `O(1)` space complexity?

## My Solutions

---

```python

```

```python

```

## Optimal Solutions

---

The "Increasing Triplet Subsequence" problem, typically found on LeetCode (problem number 334), asks if there exists a triplet `(i, j, k)` such that `i < j < k` and `nums[i] < nums[j] < nums[k]` in a given array `nums`. The most optimal solution for this problem uses a linear scan approach with a constant space complexity.

### Solution Approach: Linear Scan with Two Variables

The idea is to traverse the array and keep track of the smallest and second smallest elements found so far. If you find a number larger than both, it means there's an increasing triplet subsequence.

### Python Implementation

```python
class Solution:
    def increasingTriplet(self, nums: List[int]) -> bool:
        first = second = float('inf')

        for num in nums:
            if num <= first:  # Update the smallest element
                first = num
            elif num <= second:  # Update the second smallest element
                second = num
            else:  # Found a number greater than both first and second
                return True

        return False

```

### Explanation

1. **Initialize Two Variables**: Initialize `first` and `second` to infinity. These variables will keep track of the smallest and second smallest numbers found so far in the array.
2. **Iterate Through the Array**:
    - If the current number `num` is smaller than or equal to `first`, update `first`. This step ensures that `first` always contains the smallest number seen so far.
    - If `num` is larger than `first` but smaller than or equal to `second`, update `second`. This step finds a number that's larger than `first` but smaller than any larger numbers seen so far.
    - If `num` is larger than both `first` and `second`, it means an increasing triplet is found, and the function returns `True`.
3. **Return False if No Triplet Found**: If the loop completes without finding a triplet, return `False`.

### Complexity Analysis

- **Time Complexity**: O(n), where n is the number of elements in `nums`. The solution involves a single pass through the array.
- **Space Complexity**: O(1), as the solution uses a constant amount of space.

This approach efficiently determines if an increasing triplet subsequence exists without the need for any extra space or complex data structures.

## Notes

---

 Has tricky little greedy approach built in. Nifty mate

## Related Videos

---

[https://www.notion.so](https://www.notion.so)