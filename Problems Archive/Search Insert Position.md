# Search Insert Position

Problem: 35
Official Difficulty: easy
Feels Like : medium
Topic: array, binary search
Link: https://leetcode.com/problems/search-insert-position/
Completed On : December 27, 2023
My Understanding: Mostly Understand
Last Review: December 27, 2023
Days Since Review: 45

## Problem

---

Given a sorted array of distinct integers and a target value, return 
the index if the target is found. If not, return the index where it 
would be if it were inserted in order.

You must write an algorithm with `O(log n)` runtime complexity.

**Example 1:**

```
Input: nums = [1,3,5,6], target = 5
Output: 2
```

**Example 2:**

```
Input: nums = [1,3,5,6], target = 2
Output: 1
```

**Example 3:**

```
Input: nums = [1,3,5,6], target = 7
Output: 4
```

**Constraints:**

- `1 <= nums.length <= 104`
- `104 <= nums[i] <= 104`
- `nums` contains **distinct** values sorted in **ascending** order.
- `104 <= target <= 104`

## My Solutions

---

```python
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:

        left = 0 

        right = len(nums) - 1

        mid = 0

        if target > nums[-1] : 

            return right + 1

        if target < nums[0] :

            return left

        while left <= right : 

            # mid = left + (right - left) // 2

            # Why tf are these the same ? 

            mid = (left + right) // 2

            if nums[mid] == target : 

                return mid

            elif nums[mid] > target : 

                right = mid - 1

            elif nums[mid] < target : 

                left = mid + 1

        return left
```

```python

```

## Optimal Solutions

---

The "Search Insert Position" problem is a common question in algorithm and data structure interviews and practice. The problem statement is as follows:

Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

### Solution Approach: Binary Search

Since the array is sorted, the most efficient way to solve this problem is to use binary search. Binary search has a time complexity of O(log n), making it much faster than linear search for large arrays.

### Algorithm

1. **Initialize Two Pointers**: Set `left` to 0 and `right` to `len(nums) - 1`.
2. **Binary Search**: While the `left` pointer is less than or equal to the `right` pointer:
    - Find the middle element `mid` of the current range.
    - If the `mid` element is equal to the target, return `mid` (the target found).
    - If the target is less than the `mid` element, move the `right` pointer to `mid - 1`.
    - If the target is greater than the `mid` element, move the `left` pointer to `mid + 1`.
3. **Return Insert Position**: If the target is not found in the array, the `left` pointer will be at the position where the target should be inserted. Return `left`.

### Python Implementation

```python
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        left, right = 0, len(nums) - 1

        while left <= right:
            mid = (left + right) // 2
            if nums[mid] == target:
                return mid
            elif nums[mid] < target:
                left = mid + 1
            else:
                right = mid - 1

        return left

```

### Explanation

- The binary search algorithm divides the search interval in half each time.
- If the target is found, its index is returned immediately.
- If the target is not in the array, the loop exits when `left > right`, and `left` is the correct insertion point for the target.

### Complexity Analysis

- **Time Complexity**: O(log n), where n is the number of elements in the array. Binary search splits the search space in half with each step.
- **Space Complexity**: O(1), as the solution uses a constant amount of space.

This approach efficiently determines the position where the target would be found or inserted in a sorted array.

## Notes

---

### Why are these the same ?

mid = (left + right) // 2

mid = left + (right - left) // 2

## Related Videos

---

[https://www.youtube.com/watch?v=K-RYzDZkzCI](https://www.youtube.com/watch?v=K-RYzDZkzCI)