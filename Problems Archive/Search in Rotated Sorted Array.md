# Search in Rotated Sorted Array

Problem: 33
Official Difficulty: medium
Feels Like : hard
My Understanding: I Have No Idea, Needs Review
Topic: array, binary search
Link: https://leetcode.com/problems/search-in-rotated-sorted-array/description
Completed On : June 11, 2024
Last Review: June 11, 2024
Days Since Review: 59

## Problem

---

There is an integer array `nums` sorted in ascending order (with **distinct** values).

Prior to being passed to your function, `nums` is **possibly rotated** at an unknown pivot index `k` (`1 <= k < nums.length`) such that the resulting array is `[nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]` (**0-indexed**). For example, `[0,1,2,4,5,6,7]` might be rotated at pivot index `3` and become `[4,5,6,7,0,1,2]`.

Given the array `nums` **after** the possible rotation and an integer `target`, return *the index of* `target` *if it is in* `nums`*, or* `-1` *if it is not in* `nums`.

You must write an algorithm with `O(log n)` runtime complexity.

**Example 1:**

```
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
```

**Example 2:**

```
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
```

**Example 3:**

```
Input: nums = [1], target = 0
Output: -1
```

**Constraints:**

- `1 <= nums.length <= 5000`
- `104 <= nums[i] <= 104`
- All values of `nums` are **unique**.
- `nums` is an ascending array that is possibly rotated.
- `104 <= target <= 104`

## My Solutions

---

```python
class Solution:
    def search(self, nums: List[int], target: int) -> int:

        if len(nums) == 1:
            if nums[0] == target:
                return 0
            else:
                return -1

        left = 0

        right = len(nums) - 1

        while left < right:

            mid = left + (right-left)//2

            if nums[mid] == target:
                return mid

            if nums[left] <= nums[mid]:
                if nums[left] <= target <= nums[mid]:
                    right = mid
                else:
                    left = mid + 1
            else:
                if nums[right] >= target >= nums[mid]:
                    left = mid + 1
                else:
                    right = mid
                
        return left if nums[left] == target else -1

        

```

```python

```

## Optimal Solutions

---

### Problem Description

Given a sorted array that has been rotated at an unknown pivot, find the index of a given target value. If the target cannot be found, return -1. The array has no duplicate elements.

### Example

```python
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

```

### Optimal Solutions and Explanation

The optimal solution for searching in a rotated sorted array is to use a modified binary search. The key is to determine which part of the array is properly sorted and then adjust the search range accordingly.

### Solution 1: Modified Binary Search

### Steps:

1. **Initialize Pointers**: Set `left` to 0 and `right` to `len(nums) - 1`.
2. **Binary Search Execution**:
    - Calculate the middle index `mid`.
    - Check if `nums[mid]` is the target. If so, return `mid`.
    - Determine which part of the array is sorted:
        - If `nums[left] <= nums[mid]`, the left part is sorted.
            - If the target is in the range of the left part (`nums[left] <= target < nums[mid]`), adjust `right` to `mid - 1`.
            - Otherwise, adjust `left` to `mid + 1`.
        - If `nums[mid] <= nums[right]`, the right part is sorted.
            - If the target is in the range of the right part (`nums[mid] < target <= nums[right]`), adjust `left` to `mid + 1`.
            - Otherwise, adjust `right` to `mid - 1`.
3. **Return Result**: If the loop ends, return `1`.

### Python Code

Here's the Python code for this solution:

```python
def search(nums, target):
    left, right = 0, len(nums) - 1

    while left <= right:
        mid = (left + right) // 2
        if nums[mid] == target:
            return mid

        if nums[left] <= nums[mid]:
            if nums[left] <= target < nums[mid]:
                right = mid - 1
            else:
                left = mid + 1
        else:
            if nums[mid] < target <= nums[right]:
                left = mid + 1
            else:
                right = mid - 1

    return -1

# Example usage
print(search([4, 5, 6, 7, 0, 1, 2], 0))  # Output: 4
print(search([4, 5, 6, 7, 0, 1, 2], 3))  # Output: -1

```

### Solution 2: Binary Search with One-Pass Check

### Steps:

1. **Initialize Pointers**: Set `left` to 0 and `right` to `len(nums) - 1`.
2. **Binary Search Execution**:
    - Calculate the middle index `mid`.
    - Check if `nums[mid]` is the target. If so, return `mid`.
    - Use the relative values of `nums[mid]`, `nums[left]`, and `nums[right]` to decide the search direction:
        - If `nums[mid] >= nums[left]`, the left part is sorted.
            - If `nums[left] <= target < nums[mid]`, adjust `right` to `mid - 1`.
            - Otherwise, adjust `left` to `mid + 1`.
        - Otherwise, the right part is sorted.
            - If `nums[mid] < target <= nums[right]`, adjust `left` to `mid + 1`.
            - Otherwise, adjust `right` to `mid - 1`.
3. **Return Result**: If the loop ends, return `1`.

### Python Code

Here's the Python code for this solution:

```python
def search(nums, target):
    left, right = 0, len(nums) - 1

    while left <= right:
        mid = (left + right) // 2
        if nums[mid] == target:
            return mid

        if nums[mid] >= nums[left]:
            if nums[left] <= target < nums[mid]:
                right = mid - 1
            else:
                left = mid + 1
        else:
            if nums[mid] < target <= nums[right]:
                left = mid + 1
            else:
                right = mid - 1

    return -1

# Example usage
print(search([4, 5, 6, 7, 0, 1, 2], 0))  # Output: 4
print(search([4, 5, 6, 7, 0, 1, 2], 3))  # Output: -1

```

### Time Complexity Analysis

- **Time Complexity**: `O(log n)`
    - Each step in the binary search halves the search space, resulting in a logarithmic time complexity.

### Space Complexity Analysis

- **Space Complexity**: `O(1)`
    - The algorithm uses a constant amount of additional space for the pointers and variables.

These two solutions both leverage the properties of the rotated sorted array and the efficiency of binary search to find the target element.

## Notes

---

 

## Related Videos

---

[https://youtu.be/U8XENwh8Oy8](https://youtu.be/U8XENwh8Oy8)