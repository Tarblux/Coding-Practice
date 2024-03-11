# Binary Search

Problem: 704
Official Difficulty: easy
Feels Like : easy
My Understanding: Fully Understand
Topic: array, binary search
Link: https://leetcode.com/problems/binary-search/description/
Completed On : March 5, 2024
Last Review: March 5, 2024
Days Since Review: 5

## Problem

---

Given an array of integers `nums` which is sorted in ascending order, and an integer `target`, write a function to search `target` in `nums`. If `target` exists, then return its index. Otherwise, return `-1`.

You must write an algorithm with `O(log n)` runtime complexity.

**Example 1:**

```
Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4
```

**Example 2:**

```
Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1
```

**Constraints:**

- `1 <= nums.length <= 104`
- `104 < nums[i], target < 104`
- All the integers in `nums` are **unique**.
- `nums` is sorted in ascending order.

## My Solutions

---

```python
class Solution:
    def search(self, nums: List[int], target: int) -> int:

        left = 0
        right = len(nums) - 1
        index = -1

        while left <= right: 

            mid = (left+right)//2

            if target > nums[mid]:
                left = mid + 1
            elif target < nums[mid]:
                right = mid - 1
            elif target == nums[mid] :
                index = mid
                break

        return index
```

```python

```

## Optimal Solutions

---

Binary search is an efficient algorithm for finding an item from a sorted list of items. It works by repeatedly dividing in half the portion of the list that could contain the item until you've narrowed the possible locations to just one.

### How Binary Search Works:

1. **Initialize**: Start with two pointers representing the range of elements to search: `left` (start of the array) and `right` (end of the array).
2. **Midpoint**: Find the midpoint of the current range. The midpoint can be calculated as `mid = left + (right - left) // 2`. The adjustment is made to avoid potential overflow for large values of `left` and `right`.
3. **Compare**: Compare the target value to the value at the midpoint.
    - If the target value is equal to the midpoint value, you've found the item, and you return its index.
    - If the target value is less than the midpoint value, repeat the search on the left subarray (`right = mid - 1`).
    - If the target value is greater than the midpoint value, repeat the search on the right subarray (`left = mid + 1`).
4. **Repeat** steps 2 and 3 until the item is found or the subarray becomes empty (`left > right`), indicating that the item is not in the array.

### Python Implementation:

Here's a simple implementation of binary search in Python:

```python
def binarySearch(arr, target):
    left, right = 0, len(arr) - 1

    while left <= right:
        mid = left + (right - left) // 2

        # Check if target is present at mid
        if arr[mid] == target:
            return mid  # Target found

        # If target is greater, ignore left half
        elif arr[mid] < target:
            left = mid + 1

        # If target is smaller, ignore right half
        else:
            right = mid - 1

    # Target is not present in array
    return -1
```

### Usage:

```python
arr = [2, 5, 6, 8, 9, 10]
target = 9
result = binarySearch(arr, target)
print(f"Index of {target}: {result}")
```

### Complexity Analysis:

- **Time Complexity**: \(O(\log n)\), where \(n\) is the number of elements in the array. With each step, the algorithm reduces the search space by half, leading to a logarithmic time complexity.
- **Space Complexity**: \(O(1)\), as the algorithm uses only a constant amount of extra space for pointers and indices regardless of the input size.

Binary search is a classic example of the divide-and-conquer strategy and is much more efficient than linear search for sorted arrays, especially as the size of the array grows.

## Notes

---

 

## Related Videos

---

[https://www.youtube.com/watch?v=s4DPM8ct1pI&pp=ygUWYmluYXJ5IHNlYXJjaCBsZWV0Y29kZQ%3D%3D](https://www.youtube.com/watch?v=s4DPM8ct1pI&pp=ygUWYmluYXJ5IHNlYXJjaCBsZWV0Y29kZQ%3D%3D)