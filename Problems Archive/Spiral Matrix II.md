# Spiral Matrix II

Problem: 59
Official Difficulty: medium
My Understanding: I Have No Idea
Feels Like : medium
Topic: Matrix, array, simulation
Link: https://leetcode.com/problems/spiral-matrix-ii/description/
Completed On : February 22, 2024
Last Review: February 22, 2024
Days Since Review: 4

## Problem

---

Given a positive integer `n`, generate an `n x n` `matrix` filled with elements from `1` to `n2` in spiral order.

**Example 1:**

![https://assets.leetcode.com/uploads/2020/11/13/spiraln.jpg](https://assets.leetcode.com/uploads/2020/11/13/spiraln.jpg)

```
Input: n = 3
Output: [[1,2,3],[8,9,4],[7,6,5]]
```

**Example 2:**

```
Input: n = 1
Output: [[1]]
```

**Constraints:**

- `1 <= n <= 20`

## My Solutions

---

```python

```

```python

```

## Optimal Solutions

---

To generate a spiral matrix of size `n x n` that's filled with numbers from `1` to `n^2` in spiral order, you can follow a similar approach to traversing a matrix in spiral order. The difference here is that instead of reading values in spiral order, you'll be writing values into the matrix in spiral order.

### Approach:

1. **Initialize the matrix**: Start with an empty matrix of size `n x n`.
2. **Define boundaries**: Keep track of the current top, bottom, left, and right boundaries that define the "active" area of the matrix being filled.
3. **Fill the matrix in spiral order**: Iterate over the matrix in a spiral pattern - right, down, left, and up - updating boundaries as you go, to ensure you're always filling the correct "ring" of the matrix. Stop when you've filled the entire matrix.

### Python Implementation:

```python
def generateMatrix(n):
    # Initialize an n x n matrix filled with zeros
    matrix = [[0] * n for _ in range(n)]

    left, right, top, bottom = 0, n - 1, 0, n - 1
    num = 1  # Start filling with 1

    while left <= right and top <= bottom:
        # Traverse from left to right
        for i in range(left, right + 1):
            matrix[top][i] = num
            num += 1
        top += 1  # Move the top boundary down

        # Traverse from top to bottom
        for i in range(top, bottom + 1):
            matrix[i][right] = num
            num += 1
        right -= 1  # Move the right boundary left

        # Traverse from right to left
        if top <= bottom:
            for i in range(right, left - 1, -1):
                matrix[bottom][i] = num
                num += 1
            bottom -= 1  # Move the bottom boundary up

        # Traverse from bottom to top
        if left <= right:
            for i in range(bottom, top - 1, -1):
                matrix[i][left] = num
                num += 1
            left += 1  # Move the left boundary right

    return matrix

```

### Explanation:

- **Matrix Initialization**: A `n x n` matrix is initialized with all elements set to `0`.
- **Spiral Filling**: The matrix is filled in a spiral order starting from the outermost layer and moving inwards. The variable `num` is incremented after assigning a value to a cell, ensuring sequential filling.
- **Boundary Adjustments**: After each directional fill (right, down, left, up), the respective boundary (`top`, `right`, `bottom`, `left`) is adjusted to move inward for the next layer of the spiral.
- **Condition Check for Directional Fills**: Before filling left or up, checks ensure the `top` hasn't moved below `bottom` and `left` hasn't moved past `right`, respectively, to handle the case when the spiral reaches the center.

### Usage:

```python
n = 3
matrix = generateMatrix(n)
for row in matrix:
    print(row)

```

This code generates a `n x n` matrix filled with numbers from `1` to `n^2` in a spiral order, following the constraints and approach outlined above.

## Notes

---

 

## Related Videos

---

[https://www.notion.so](https://www.notion.so)