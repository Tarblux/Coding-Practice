# Set Matrix Zeroes

Problem: 73
Official Difficulty: medium
Feels Like : easy
Topic: Matrix, array, hash table
Link: https://leetcode.com/problems/set-matrix-zeroes/description/?envType=study-plan-v2&envId=programming-skills
Completed On : February 8, 2024
My Understanding: Fully Understand
Last Review: February 8, 2024
Days Since Review: 2

## Problem

---

Given an `m x n` integer matrix `matrix`, if an element is `0`, set its entire row and column to `0`'s.

You must do it [in place](https://en.wikipedia.org/wiki/In-place_algorithm).

**Example 1:**

![https://assets.leetcode.com/uploads/2020/08/17/mat1.jpg](https://assets.leetcode.com/uploads/2020/08/17/mat1.jpg)

```
Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
```

**Example 2:**

![https://assets.leetcode.com/uploads/2020/08/17/mat2.jpg](https://assets.leetcode.com/uploads/2020/08/17/mat2.jpg)

```
Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
```

**Constraints:**

- `m == matrix.length`
- `n == matrix[0].length`
- `1 <= m, n <= 200`
- `231 <= matrix[i][j] <= 231 - 1`

**Follow up:**

- A straightforward solution using `O(mn)` space is probably a bad idea.
- A simple improvement uses `O(m + n)` space, but still not the best solution.
- Could you devise a constant space solution?

## My Solutions

---

```python
class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """

        cols = set([])

        rows = set([])

        n = len(matrix[0])

        for i in range(0,len(matrix)) :

            for j in range(0,n) :

                if matrix[i][j] == 0 : 

                    cols.add(j)

                    rows.add(i)

        for i in range(0,len(matrix)) :

            for j in range(0,n) :

                if i in rows : 

                    for k in range(len(matrix[i])): 

                        matrix[i][k] = 0

                if j in cols : 

                    matrix[i][j] = 0
```

```python

```

## Optimal Solutions

---

### Solution Approach

A straightforward approach would involve using auxiliary space to keep track of the rows and columns that must be set to zero. However, to optimize for space, we can use the first row and the first column of the matrix itself to keep track of this information.

### Python Implementation

```python
class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        rows, cols = len(matrix), len(matrix[0])
        first_row_has_zero = any(matrix[0][col] == 0 for col in range(cols))
        first_col_has_zero = any(matrix[row][0] == 0 for row in range(rows))

        # Use first row and column as markers
        for r in range(1, rows):
            for c in range(1, cols):
                if matrix[r][c] == 0:
                    matrix[0][c] = 0
                    matrix[r][0] = 0

        # Set zeroes based on markers
        for r in range(1, rows):
            for c in range(1, cols):
                if matrix[0][c] == 0 or matrix[r][0] == 0:
                    matrix[r][c] = 0

        # Handle the first row
        if first_row_has_zero:
            for c in range(cols):
                matrix[0][c] = 0

        # Handle the first column
        if first_col_has_zero:
            for r in range(rows):
                matrix[r][0] = 0
```

### Explanation

1. **Detect Zeros in the First Row and Column**: First, determine if the first row and/or first column contain any zeros. This information is necessary because later steps will modify the first row and column to use them as markers.
2. **Mark Rows and Columns for Zeroing**: Iterate through the rest of the matrix (excluding the first row and column). For any cell `(r, c)` that is 0, mark its corresponding position in the first row and first column by setting `matrix[0][c] = 0` and `matrix[r][0] = 0`.
3. **Set Zeros Based on Markers**: Use the markers set in the first row and column to zero out cells in the rest of the matrix.
4. **Handle the First Row and Column**: Finally, if the original first row or column had any zeros, zero out the entire first row or column, respectively.

### Complexity Analysis

- **Time Complexity**: O(m * n), where `m` is the number of rows and `n` is the number of columns in the matrix. Each cell is visited a constant number of times.
- **Space Complexity**: O(1), as the solution uses the first row and column of the input matrix itself for marking, without using any additional data structures for storage.

## Notes

---

 

## Related Videos

---

[https://www.youtube.com/watch?v=T41rL0L3Pnw&pp=ygUQc3dhcCBtYXRyaXggemVybw%3D%3D](https://www.youtube.com/watch?v=T41rL0L3Pnw&pp=ygUQc3dhcCBtYXRyaXggemVybw%3D%3D)