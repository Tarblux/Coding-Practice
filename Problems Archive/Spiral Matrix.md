# Spiral Matrix

Problem: 54
Official Difficulty: medium
Feels Like : medium
Topic: Matrix, array, simulation
Link: https://leetcode.com/problems/spiral-matrix/description/
Completed On : January 29, 2024
My Understanding: Needs Review
Last Review: January 29, 2024
Days Since Review: 12

## Problem

---

Given an `m x n` `matrix`, return *all elements of the* `matrix` *in spiral order*.

**Example 1:**

![https://assets.leetcode.com/uploads/2020/11/13/spiral1.jpg](https://assets.leetcode.com/uploads/2020/11/13/spiral1.jpg)

```
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
```

**Example 2:**

![https://assets.leetcode.com/uploads/2020/11/13/spiral.jpg](https://assets.leetcode.com/uploads/2020/11/13/spiral.jpg)

```
Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
```

**Constraints:**

- `m == matrix.length`
- `n == matrix[i].length`
- `1 <= m, n <= 10`
- `100 <= matrix[i][j] <= 100`

## My Solutions

---

```python
class Solution:

    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:

        if not matrix or not matrix[0]:

            return []

        rows, cols = len(matrix), len(matrix[0])

        output = []

        # Top Row

        for col in range(cols):

            output.append(matrix[0][col])

        # Right Column

        for row in range(1, rows):

            output.append(matrix[row][cols - 1])

        # Bottom Row

        if rows > 1:

            for col in range(cols - 2, -1, -1):

                output.append(matrix[rows - 1][col])

        # Left Column

        if cols > 1:

            for row in range(rows - 2, 0, -1):

                output.append(matrix[row][0])

        # Handle inner matrix if it exists

        if rows > 2 and cols > 2:

            inner_matrix = [row[1:-1] for row in matrix[1:-1]]
            
            output.extend(self.spiralOrder(inner_matrix))

        return output
```

```python

```

## Optimal Solutions

---

The "Spiral Matrix" problem involves traversing a 2D matrix in a spiral pattern and collecting the elements in the order of their visitation. The traversal starts from the top-left corner and initially proceeds rightward. The pattern is right, down, left, and up, repeating until all elements are visited.

### Problem Statement

Given an `m x n` matrix, return all elements of the matrix in spiral order.

### Solution Approach

To solve this problem, keep track of the boundaries - top, bottom, left, and right - and iterate through the matrix. Update these boundaries after traversing each edge to avoid revisiting elements.

### Python Implementation

```python
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        if not matrix:
            return []

        result = []
        left, right, top, bottom = 0, len(matrix[0]), 0, len(matrix)

        while left < right and top < bottom:
            # Traverse from left to right
            for i in range(left, right):
                result.append(matrix[top][i])
            top += 1

            # Traverse downwards
            for i in range(top, bottom):
                result.append(matrix[i][right - 1])
            right -= 1

            if not (left < right and top < bottom):
                break

            # Traverse from right to left
            for i in range(right - 1, left - 1, -1):
                result.append(matrix[bottom - 1][i])
            bottom -= 1

            # Traverse upwards
            for i in range(bottom - 1, top - 1, -1):
                result.append(matrix[i][left])
            left += 1

        return result
```

### Explanation

- Initialize `left`, `right`, `top`, and `bottom` to denote the boundaries of the matrix.
- The outer `while` loop runs as long as `left < right` and `top < bottom`.
- Iterate rightwards, downwards, leftwards, and then upwards, appending elements to `result`.
- After each traversal of an edge, adjust the respective boundary inward to prevent revisiting elements.
- Break the loop when the boundaries cross, indicating all elements have been visited.

### Complexity Analysis

- **Time Complexity**: O(m * n), where m is the number of rows and n is the number of columns in the matrix. Each element is visited exactly once.
- **Space Complexity**: O(1), if the output array is not considered as extra space. Otherwise, it's O(m * n) for the output array.

This implementation provides an efficient way to traverse the matrix in a spiral order and collect its elements.

### Explain Like I am Five (ELI5)

---

## Notes

---

 

## Related Videos

---

[https://www.youtube.com/watch?v=BJnMZNwUk1M&pp=ygUNc3BpcmFsIG1hdHJpeA%3D%3D](https://www.youtube.com/watch?v=BJnMZNwUk1M&pp=ygUNc3BpcmFsIG1hdHJpeA%3D%3D)