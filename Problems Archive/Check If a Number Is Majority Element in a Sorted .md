# Check If a Number Is Majority Element in a Sorted Array

Problem: 1150
Official Difficulty: easy
Feels Like : medium
My Understanding: Fully Understand
Topic: array, binary search
Link: https://leetcode.com/problems/check-if-a-number-is-majority-element-in-a-sorted-array/description/
Completed On : June 16, 2024
Last Review: June 16, 2024
Days Since Review: 54

## Problem

---

Given an integer array `nums` sorted in non-decreasing order and an integer `target`, return `true` *if* `target` *is a **majority** element, or* `false` *otherwise*.

A **majority** element in an array `nums` is an element that appears more than `nums.length / 2` times in the array.

**Example 1:**

```
Input: nums = [2,4,5,5,5,5,5,6,6], target = 5
Output: true
Explanation: The value 5 appears 5 times and the length of the array is 9.
Thus, 5 is a majority element because 5 > 9/2 is true.
```

**Example 2:**

```
Input: nums = [10,100,101,101], target = 101
Output: false
Explanation: The value 101 appears 2 times and the length of the array is 4.
Thus, 101 is not a majority element because 2 > 4/2 is false.
```

**Constraints:**

- `1 <= nums.length <= 1000`
- `1 <= nums[i], target <= 109`
- `nums` is sorted in non-decreasing order.

## My Solutions

---

```python
class Solution:
    def leftBinarySearch(self,nums:List[int],target:int) -> int:

        if not nums:
            return

        left = 0
        right = len(nums)

        while left < right:

            mid = left + (right-left)//2

            if nums[mid] == target:
                right = mid
            elif nums[mid] > target:
                right = mid
            else:
                left = mid + 1

        return left

    def rightBinarySearch(self,nums:List[int],target:int) -> int:

        if not nums:
            return

        left = 0
        right = len(nums)

        while left < right:

            mid = left + (right-left)//2

            if nums[mid] == target:
                left = mid + 1
            elif nums[mid] > target:
                right = mid
            else:
                left = mid + 1

        return left

    def isMajorityElement(self, nums: List[int], target: int) -> bool:

        """
        - Establish Search Range
        - Binary Search Left boundary
        - Binary Search Right boundary
        - Determine if L - R > len(nums)/2
        """

        
        left_bound = self.leftBinarySearch(nums,target) 
        right_bound = self.rightBinarySearch(nums,target)

        return (right_bound - left_bound) > len(nums)//2

        
```

```python

```

## Optimal Solutions

---

### Problem Description

Given an array `nums` sorted in non-decreasing order and an integer `target`, return `true` if `target` is a majority element, or `false` otherwise. A majority element in an array `nums` is an element that appears more than `n / 2` times, where `n` is the length of the array.

### Example

```python
Input: nums = [2,4,5,5,5,5,5,6,6], target = 5
Output: true

Input: nums = [10,100,101,101], target = 101
Output: false
```

### Optimal Solution and Explanation

To determine if the target is a majority element, we can leverage the fact that the array is sorted. This allows us to use binary search to efficiently find the target and count its occurrences.

### Steps:

1. **Binary Search for First and Last Occurrence**:
    - Use binary search to find the first occurrence of the target in the array.
    - Use binary search to find the last occurrence of the target in the array.
2. **Count Occurrences**:
    - Calculate the number of occurrences of the target using the indices of the first and last occurrences.
    - Check if the count is greater than `n / 2`.

### Python Code

Here's the Python code to achieve this:

```python
def isMajorityElement(nums, target):
    def findFirst(nums, target):
        left, right = 0, len(nums) - 1
        while left < right:
            mid = (left + right) // 2
            if nums[mid] < target:
                left = mid + 1
            else:
                right = mid
        return left if nums[left] == target else -1

    def findLast(nums, target):
        left, right = 0, len(nums) - 1
        while left < right:
            mid = (left + right + 1) // 2
            if nums[mid] > target:
                right = mid - 1
            else:
                left = mid
        return left if nums[left] == target else -1

    first = findFirst(nums, target)
    if first == -1:
        return False

    last = findLast(nums, target)
    count = last - first + 1

    return count > len(nums) // 2

# Example usage
print(isMajorityElement([2, 4, 5, 5, 5, 5, 5, 6, 6], 5))  # Output: true
print(isMajorityElement([10, 100, 101, 101], 101))         # Output: false
```

### Explanation

1. **Binary Search for First Occurrence**:
    - `findFirst(nums, target)` uses binary search to find the first occurrence of the target. It narrows the search range until `left` is the first position where `target` occurs.
2. **Binary Search for Last Occurrence**:
    - `findLast(nums, target)` uses binary search to find the last occurrence of the target. It narrows the search range until `left` is the last position where `target` occurs.
3. **Count Occurrences**:
    - If the first occurrence is `1`, the target is not in the array, so return `false`.
    - Calculate the number of occurrences of the target by subtracting the index of the first occurrence from the index of the last occurrence and adding 1.
    - Check if this count is greater than `n / 2`.

### Time Complexity Analysis

- **Time Complexity**: `O(log n)`
    - Finding the first and last occurrences of the target using binary search each take `O(log n)` time.
    - The total time complexity is `O(log n)`.

### Space Complexity Analysis

- **Space Complexity**: `O(1)`
    - The algorithm uses a constant amount of extra space for the pointers and variables.

This approach efficiently determines if the target is a majority element in a sorted array using binary search, resulting in a logarithmic time complexity.

## Notes

---

 

## Related Videos

---

[https://www.notion.so](https://www.notion.so)