# Find First and Last Position of Element in Sorted Array

Problem: 34
Official Difficulty: medium
Feels Like : medium
My Understanding: Mostly Understand
Topic: array, binary search
Link: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
Completed On : March 12, 2024
Last Review: March 12, 2024
Days Since Review: 49

## Problem

---

Given an array of integers `nums` sorted in non-decreasing order, find the starting and ending position of a given `target` value.

If `target` is not found in the array, return `[-1, -1]`.

You must write an algorithm with `O(log n)` runtime complexity.

**Example 1:**

```
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
```

**Example 2:**

```
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
```

**Example 3:**

```
Input: nums = [], target = 0
Output: [-1,-1]
```

**Constraints:**

- `0 <= nums.length <= 105`
- `109 <= nums[i] <= 109`
- `nums` is a non-decreasing array.
- `109 <= target <= 109`

## My Solutions

---

```python
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:

        ranger = [-1,-1]
        l = 0
        r = len(nums)-1
        start = 0
        end = 0

        while l <= r:

            mid = (l+r)//2

            if nums[mid] == target: 
                while mid >= 0 and nums[mid] == target:
                    mid -= 1
                start = mid
                mid += 1
                while mid < len(nums) and nums[mid] == target:
                    mid += 1
                ranger = start + 1, mid - 1
                break
            elif nums[mid] < target:
                l = mid + 1
            elif nums[mid] > target:
                r = mid - 1

        return ranger
```

```python

```

## Optimal Solutions

---

To find the first and last position of an element in a sorted array, you can efficiently use binary search twice. The first binary search is to find the first (leftmost) occurrence of the target element, and the second binary search is to find the last (rightmost) occurrence.

1. **Binary Search for the First Occurrence**: Implement a binary search that focuses on finding the first (leftmost) occurrence of the target. When the target is found, instead of immediately returning, continue the search on the left half to see if there's an even earlier occurrence of the target.
2. **Binary Search for the Last Occurrence**: Implement a second binary search that focuses on finding the last (rightmost) occurrence of the target. Similar to the first search, when the target is found, continue the search on the right half to see if there's a later occurrence of the target.
3. **Modify Binary Search Condition**: For both modified binary searches, adjust your conditions inside the binary search loop to narrow down to the first or last occurrence. This often involves tweaking how you adjust your `left` and `right` pointers based on the comparison with `target`.
4. **Check for Target Absence**: After performing both searches, you need to check if the target was not found at all. This can be done by checking the results of your binary searches against conditions that indicate the target was not present.

```python
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        def binarySearchLeft(nums, target):
            left, right = 0, len(nums) - 1
            while left <= right:
                mid = left + (right - left) // 2
                if nums[mid] < target:
                    left = mid + 1
                else:
                    right = mid - 1
            return left

        def binarySearchRight(nums, target):
            left, right = 0, len(nums) - 1
            while left <= right:
                mid = left + (right - left) // 2
                if nums[mid] <= target:
                    left = mid + 1
                else:
                    right = mid - 1
            return right

        leftIndex = binarySearchLeft(nums, target)
        rightIndex = binarySearchRight(nums, target)

        # Check if the target is not within the range of numbers in the array.
        if leftIndex <= rightIndex:
            return [leftIndex, rightIndex]
        return [-1, -1]

```

### Time Complexity Analysis:

1. **Binary Search Complexity**: The time complexity of binary search is \(O(\log n)\), where \(n\) is the number of elements in the input array. This is because, with each iteration of the binary search, the size of the search space is halved.
2. **Two Binary Searches**: Since the solution involves two separate binary search operations (one for finding the leftmost index and one for the rightmost index of the target element), and each operates independently on the same dataset, the overall time complexity remains \(O(\log n)\). The constant factor introduced by performing two searches does not change the logarithmic nature of the time complexity.
3. **Overall Time Complexity**: Thus, the overall time complexity of the solution is \(O(\log n)\).

### Explanation of the Approach:

- **binarySearchLeft**: Finds the left boundary of the target. It moves the left pointer when the target is greater than or equal to `nums[mid]`, ensuring that the search space is narrowed down to the first occurrence of the target.
- **binarySearchRight**: Finds the right boundary of the target. It differs slightly in condition from `binarySearchLeft` by moving the left pointer when `nums[mid]` is less than or equal to the target, aiming to find the last occurrence.
- **Validation**: After obtaining `leftIndex` and `rightIndex`, the solution checks if `leftIndex <= rightIndex`. This step ensures that the target exists in the array. If the target is not found, `binarySearchLeft` might return a position one past the last index of the target, and `binarySearchRight` might return one less than the first index of the target, making `leftIndex > rightIndex`.

This method efficiently finds the required indices with minimal computations, leveraging the sorted nature of the input array.

## Notes

---

 

## Related Videos

---

[https://www.youtube.com/watch?v=4sQL7R5ySUU](https://www.youtube.com/watch?v=4sQL7R5ySUU)