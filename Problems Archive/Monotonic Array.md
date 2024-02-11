# Monotonic Array

Problem: 896
Official Difficulty: easy
Feels Like : medium
Topic: array
Link: https://leetcode.com/problems/monotonic-array/description/
Completed On : January 6, 2024
My Understanding: Fully Understand
Last Review: January 6, 2024
Days Since Review: 35

## Problem

---

An array is **monotonic** if it is either monotone increasing or monotone decreasing.

An array `nums` is monotone increasing if for all `i <= j`, `nums[i] <= nums[j]`. An array `nums` is monotone decreasing if for all `i <= j`, `nums[i] >= nums[j]`.

Given an integer array `nums`, return `true` *if the given array is monotonic, or* `false` *otherwise*.

**Example 1:**

```
Input: nums = [1,2,2,3]
Output: true
```

**Example 2:**

```
Input: nums = [6,5,4,4]
Output: true
```

**Example 3:**

```
Input: nums = [1,3,2]
Output: false
```

**Constraints:**

- `1 <= nums.length <= 105`
- `105 <= nums[i] <= 105`

## My Solutions

---

```python
class Solution:
    def isMonotonic(self, nums: List[int]) -> bool:

        direction = 0

        pointer = 1

        # 0 - Decreasing 

        # 1 - Increasing

        [2,2,3,5]

        while pointer <= len(nums) : 

            if nums[pointer] == nums[pointer - 1] : 

                pointer += 1

                continue 

            elif nums[pointer] >= nums[pointer - 1] : 

                direction = 1 

                break

            else : 

                direction = 0 

                break 

        if direction == 0 :

            for i in range (1,len(nums)) : 

                if nums[i-1] < nums[i] : 

                    return False 

                elif nums[i-1] == nums[i] : 

                    continue

        if direction == 1 : 

            for i in range (1,len(nums)) : 

                if nums[i-1] > nums[i] : 

                    return False 

                elif nums[i-1] == nums[i] : 

                    continue

        return True
```

```python

```

## Optimal Solutions

---

The "Monotonic Array" problem is a straightforward question where you need to determine if a given array is monotonic. An array is monotonic if it is either entirely non-increasing or entirely non-decreasing.

### Problem Statement

Given an array `A`, return `True` if and only if it is monotonic. An array `A` is monotonic if and only if either of the following conditions hold:

- `A` is entirely non-decreasing (for every `i <= j`, `A[i] <= A[j]`).
- `A` is entirely non-increasing (for every `i <= j`, `A[i] >= A[j]`).

### Solution Approach: Single Pass

The problem can be solved efficiently in a single pass through the array. The idea is to track if the array is non-decreasing, non-increasing, or neither as you iterate through it.

### Python Implementation

```python
class Solution:
    def isMonotonic(self, A: List[int]) -> bool:
        increasing = decreasing = True

        for i in range(1, len(A)):
            if A[i] > A[i - 1]:
                decreasing = False
            elif A[i] < A[i - 1]:
                increasing = False

        return increasing or decreasing

```

### Explanation

- Two flags, `increasing` and `decreasing`, are initialized to `True`.
- As you iterate through the array, update these flags based on the relation between consecutive elements.
- If you find an element that is greater than its predecessor, set `decreasing` to `False`.
- If you find an element that is less than its predecessor, set `increasing` to `False`.
- If the array is either non-decreasing or non-increasing, it is monotonic. Hence, return `increasing or decreasing`.

### Complexity Analysis

- **Time Complexity**: O(n), where `n` is the number of elements in the array. The solution requires a single pass through the array.
- **Space Complexity**: O(1), as no additional space is required beyond constant extra variables.

This approach efficiently determines if an array is monotonic by checking the relationship between consecutive elements in a single pass.

## Notes

---

 Seeing the optimal solution makes mine look way too much but I think that was simply the only way I understood the implementation at the time 

## Related Videos

---

[https://www.youtube.com/watch?v=sqWOFIZ9Z0U](https://www.youtube.com/watch?v=sqWOFIZ9Z0U)