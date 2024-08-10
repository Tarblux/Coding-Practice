# Find Minimum in Rotated Sorted Array

Problem: 153
Official Difficulty: medium
Feels Like : hard
My Understanding: I Have No Idea
Topic: array, binary search
Link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/?envType=problem-list-v2&envId=m74tw92e
Completed On : June 9, 2024
Last Review: June 9, 2024
Days Since Review: 61

## Problem

---

Suppose an array of length `n` sorted in ascending order is **rotated** between `1` and `n` times. For example, the array `nums = [0,1,2,4,5,6,7]` might become:

- `[4,5,6,7,0,1,2]` if it was rotated `4` times.
- `[0,1,2,4,5,6,7]` if it was rotated `7` times.

Notice that **rotating** an array `[a[0], a[1], a[2], ..., a[n-1]]` 1 time results in the array `[a[n-1], a[0], a[1], a[2], ..., a[n-2]]`.

Given the sorted rotated array `nums` of **unique** elements, return *the minimum element of this array*.

You must write an algorithm that runs in `O(log n) time.`

**Example 1:**

```
Input: nums = [3,4,5,1,2]
Output: 1
Explanation: The original array was [1,2,3,4,5] rotated 3 times.
```

**Example 2:**

```
Input: nums = [4,5,6,7,0,1,2]
Output: 0
Explanation: The original array was [0,1,2,4,5,6,7] and it was rotated 4 times.
```

**Example 3:**

```
Input: nums = [11,13,15,17]
Output: 11
Explanation: The original array was [11,13,15,17] and it was rotated 4 times.
```

**Constraints:**

- `n == nums.length`
- `1 <= n <= 5000`
- `5000 <= nums[i] <= 5000`
- All the integers of `nums` are **unique**.
- `nums` is sorted and rotated between `1` and `n` times.

## My Solutions

---

```python
class Solution:
    def findMin(self, nums: List[int]) -> int:

        """
        - Estabslish Search range from nums[0] to nums[-1]

        - Find mid point and adjust range according to value to find min

        - Return left since search ends at mimimum point
        """

        if len(nums) == 1:
            return nums[0]

        
        left = 0
        right = len(nums)-1

        if nums[right] > nums[0]:
            return nums[0]

        while left <= right:

            mid = left + (right-left)//2
            print(mid)

            if nums[mid] > nums[mid +1]:
                return nums[mid+1]

            if nums[mid-1] > nums[mid]:
                return nums[mid]
            

            if nums[mid] > nums[0]:
                left = mid + 1
            elif nums[mid] < nums[0]:
                right = mid - 1 

        return left
```

```python

```

## Optimal Solutions

---

### Problem Description

Suppose an array of length `n` sorted in ascending order is rotated between 1 and `n` times. For example, the array `nums = [0,1,2,4,5,6,7]` might become:

- `[4,5,6,7,0,1,2]` if it was rotated 4 times.
- `[0,1,2,4,5,6,7]` if it was rotated 7 times.

Notice that rotating an array `[a[0], a[1], a[2], ..., a[n-1]]` 1 time results in the array `[a[n-1], a[0], a[1], a[2], ..., a[n-2]]`.

Given the sorted rotated array `nums` of unique elements, return the minimum element of this array.

### Example

```python
Input: nums = [3, 4, 5, 1, 2]
Output: 1

Input: nums = [4, 5, 6, 7, 0, 1, 2]
Output: 0

Input: nums = [11, 13, 15, 17]
Output: 11
```

### Optimal Solution and Explanation

To find the minimum element in a rotated sorted array, we can use a binary search approach. This approach takes advantage of the properties of the rotated sorted array to efficiently find the minimum element in O(log n) time.

### Steps:

1. **Binary Search Initialization**: Set `left` to 0 and `right` to `len(nums) - 1`.
2. **Binary Search Execution**:
    - Calculate the middle index `mid`.
    - Compare the middle element `nums[mid]` with the rightmost element `nums[right]`:
        - If `nums[mid]` is greater than `nums[right]`, the minimum element must be in the right half of the array (excluding `mid`).
        - If `nums[mid]` is less than or equal to `nums[right]`, the minimum element is in the left half of the array (including `mid`).
    - Adjust the `left` and `right` pointers accordingly.
3. **Termination**: The loop terminates when `left` equals `right`, which will point to the minimum element.

### Python Code

Here's the Python code to achieve this:

```python
def findMin(nums):
    left, right = 0, len(nums) - 1

    while left < right:
        mid = (left + right) // 2

        if nums[mid] > nums[right]:
            left = mid + 1
        else:
            right = mid

    return nums[left]

# Example usage
print(findMin([3, 4, 5, 1, 2]))        # Output: 1
print(findMin([4, 5, 6, 7, 0, 1, 2]))  # Output: 0
print(findMin([11, 13, 15, 17]))       # Output: 11
```

### Explanation

1. **Binary Search Setup**:
    - Initialize `left` to 0 and `right` to `len(nums) - 1`.
2. **Binary Search Execution**:
    - Calculate `mid` as `(left + right) // 2`.
    - Compare `nums[mid]` with `nums[right]`:
        - If `nums[mid] > nums[right]`, it means the smallest value is to the right of `mid`, so set `left = mid + 1`.
        - If `nums[mid] <= nums[right]`, it means the smallest value is at `mid` or to the left of `mid`, so set `right = mid`.
    - Continue adjusting `left` and `right` until they converge.
3. **Termination**:
    - When `left` equals `right`, the loop terminates, and `nums[left]` is the minimum element.

### Time Complexity Analysis

- **Time Complexity**: `O(log n)`
    - The binary search runs in logarithmic time relative to the number of elements in the array.

### Space Complexity Analysis

- **Space Complexity**: `O(1)`
    - The algorithm uses a constant amount of additional space.

### Explain Like I'm Five (ELI5)

Imagine you have a bunch of toy cars lined up in a circle, but someone rotated part of the line so the starting point is in a new place. You want to find the smallest car without looking at every single car:

1. **Middle Check**: Check the middle car and compare it with the last car in the line.
2. **Narrow Down**: If the middle car is bigger than the last car, the smallest car must be to the right. If the middle car is smaller, the smallest car must be to the left or could be the middle car itself.
3. **Keep Going**: Keep narrowing down the section where the smallest car could be until you find it.

By doing this smart checking, you find the smallest car much faster than looking at every single car!

## Notes

---

 

## Related Videos

---

[https://youtu.be/nIVW4P8b1VA](https://youtu.be/nIVW4P8b1VA)