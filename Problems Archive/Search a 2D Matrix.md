# Search a 2D Matrix

Problem: 74
Official Difficulty: medium
Feels Like : easy
My Understanding: Fully Understand
Topic: Matrix, array, binary search
Link: https://leetcode.com/problems/search-a-2d-matrix/
Completed On : May 29, 2024
Last Review: May 29, 2024
Days Since Review: 5

## Problem

---

You are given an `m x n` integer matrix `matrix` with the following two properties:

- Each row is sorted in non-decreasing order.
- The first integer of each row is greater than the last integer of the previous row.

Given an integer `target`, return `true` *if* `target` *is in* `matrix` *or* `false` *otherwise*.

You must write a solution in `O(log(m * n))` time complexity.

**Example 1:**

![https://assets.leetcode.com/uploads/2020/10/05/mat.jpg](https://assets.leetcode.com/uploads/2020/10/05/mat.jpg)

```
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
```

**Example 2:**

![https://assets.leetcode.com/uploads/2020/10/05/mat2.jpg](https://assets.leetcode.com/uploads/2020/10/05/mat2.jpg)

```
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false
```

**Constraints:**

- `m == matrix.length`
- `n == matrix[i].length`
- `1 <= m, n <= 100`
- `104 <= matrix[i][j], target <= 104`

## My Solutions

---

```python
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:

        if not matrix:
            return False

        row = 0

        # Determine Row to search
        while row < len(matrix):

            if target > matrix[row][-1]:
                row += 1
            else:
                break

        if row == len(matrix): 
            return False

        # Instantiate Search Interval 
        left = 0
        right = len(matrix[row])

        # Search and return True if found 
        while left < right:

            mid = left + (right-left)//2

            if target == matrix[row][mid]:
                return True
            elif target < matrix[row][mid]:
                right = mid
            else:
                left = mid + 1
        # Return false if not found

        return False
```

```python

```

## Optimal Solutions

---

### Problem Description

Write an efficient algorithm that searches for a value in an `m x n` matrix. This matrix has the following properties:

- Integers in each row are sorted in ascending order from left to right.
- The first integer of each row is greater than the last integer of the previous row.

### Example

```python
Input: matrix = [
  [1, 3, 5, 7],
  [10, 11, 16, 20],
  [23, 30, 34, 60]
], target = 3
Output: true

Input: matrix = [
  [1, 3, 5, 7],
  [10, 11, 16, 20],
  [23, 30, 34, 60]
], target = 13
Output: false

```

### Optimal Solution and Explanation

The matrix can be thought of as a sorted array, and we can use binary search to achieve an efficient solution. Since each row's last element is less than the next row's first element, the matrix can be treated as a flattened sorted list.

### Steps:

1. **Matrix Dimensions**: Let `m` be the number of rows and `n` be the number of columns.
2. **Binary Search**: Perform binary search over the range `0` to `m * n - 1`.
    - Calculate the middle index of the flattened matrix.
    - Convert the middle index back to 2D indices to access the element in the matrix.
    - Compare the middle element with the target:
        - If equal, return `True`.
        - If less than the target, search the right half.
        - If greater than the target, search the left half.
3. **Return Result**: If the target is not found, return `False`.

### Python Code

Here's the Python code to achieve this:

```python
def searchMatrix(matrix, target):
    if not matrix or not matrix[0]:
        return False

    m, n = len(matrix), len(matrix[0])
    left, right = 0, m * n - 1

    while left <= right:
        mid = (left + right) // 2
        mid_value = matrix[mid // n][mid % n]

        if mid_value == target:
            return True
        elif mid_value < target:
            left = mid + 1
        else:
            right = mid - 1

    return False

# Example usage
matrix1 = [
  [1, 3, 5, 7],
  [10, 11, 16, 20],
  [23, 30, 34, 60]
]
print(searchMatrix(matrix1, 3))  # Output: True
print(searchMatrix(matrix1, 13))  # Output: False

```

### Explanation

1. **Binary Search Setup**:
    - Define the initial search range with `left = 0` and `right = m * n - 1`.
    - Calculate the middle index `mid` and convert it to the 2D indices using `mid // n` (row) and `mid % n` (column).
2. **Comparison**:
    - If `matrix[mid // n][mid % n]` equals the target, return `True`.
    - If `matrix[mid // n][mid % n]` is less than the target, narrow the search to the right half by setting `left = mid + 1`.
    - If `matrix[mid // n][mid % n]` is greater than the target, narrow the search to the left half by setting `right = mid - 1`.
3. **Return Result**: If the loop exits without finding the target, return `False`.

### Time Complexity Analysis

- **Time Complexity**: `O(log(m * n))`
    - This is because binary search runs in logarithmic time with respect to the number of elements, which is `m * n`.

### Space Complexity Analysis

- **Space Complexity**: `O(1)`
    - This is because the algorithm uses a constant amount of additional space.

### Explain Like I'm Five (ELI5)

Imagine you have a book with all the numbers in order, but instead of one long list, the numbers are arranged in a grid (like a calendar). You want to find a number quickly:

1. **Flatten the Grid**: Think of the grid as one long list.
2. **Binary Search**: Use the trick of dividing the long list in the middle to see if the number is to the left or right.
3. **Check and Move**: Keep narrowing down where the number could be until you find it or run out of places to look.

By treating the grid as a single list and using binary search, you can quickly find the number you're looking for!

## Notes

---

 

## Related Videos

---

[https://www.youtube.com/watch?v=Ber2pi2C0j0&pp=ygUQc2VhcmNoIDJkIG1hdHJpeA%3D%3D](https://www.youtube.com/watch?v=Ber2pi2C0j0&pp=ygUQc2VhcmNoIDJkIG1hdHJpeA%3D%3D)