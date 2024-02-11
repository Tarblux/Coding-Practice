# Matrix Diagonal Sum

Problem: 1572
Official Difficulty: easy
Feels Like : easy
Topic: Matrix, array
Link: https://leetcode.com/problems/matrix-diagonal-sum/description/?envType=study-plan-v2&envId=programming-skills
Completed On : January 29, 2024
My Understanding: Mostly Understand
Last Review: January 29, 2024
Days Since Review: 12

## Problem

---

Given a square matrix `mat`, return the sum of the matrix diagonals.

Only include the sum of all the elements on the primary diagonal and 
all the elements on the secondary diagonal that are not part of the 
primary diagonal.

**Example 1:**

![https://assets.leetcode.com/uploads/2020/08/14/sample_1911.png](https://assets.leetcode.com/uploads/2020/08/14/sample_1911.png)

```
Input: mat = [[1,2,3],
              [4,5,6],
              [7,8,9]]
Output: 25
Explanation:Diagonals sum: 1 + 5 + 9 + 3 + 7 = 25
Notice that element mat[1][1] = 5 is counted only once.

```

**Example 2:**

```
Input: mat = [[1,1,1,1],
              [1,1,1,1],
              [1,1,1,1],
              [1,1,1,1]]
Output: 8
```

**Example 3:**

```
Input: mat = [[5]]
Output: 5
```

**Constraints:**

- `n == mat.length == mat[i].length`
- `1 <= n <= 100`
- `1 <= mat[i][j] <= 100`

## My Solutions

---

```python
class Solution:
    def diagonalSum(self, mat: List[List[int]]) -> int:

        l = 0 

        r = len(mat[0]) - 1 

        odd = (len(mat[0]) % 2) == 1 

        sum = 0

        for array in mat : 

            sum += array[l]

            l += 1

        for array in mat : 

            sum += array[r]

            r -= 1

        if odd : 

            mid = len(mat) // 2 

            sum -= mat[mid][mid]

        return sum
```

```python

```

## Optimal Solutions

---

The "Matrix Diagonal Sum" problem involves calculating the sum of the elements on the main diagonal and the anti-diagonal of a square matrix. The main diagonal runs from the top-left corner to the bottom-right corner, and the anti-diagonal runs from the top-right corner to the bottom-left corner. In the case where a cell is part of both diagonals (which happens for matrices with odd dimensions), it should only be counted once.

### Problem Statement

Given a square matrix `mat`, return the sum of the matrix diagonals.

### Solution Approach

To solve this problem, iterate through the matrix and add the elements that are on the main diagonal (where row index equals column index) and the anti-diagonal (where row index and column index sum to `len(mat) - 1`). If the matrix has an odd length, subtract the central element, as it gets counted in both diagonals.

### Python Implementation

```python
class Solution:
    def diagonalSum(self, mat: List[List[int]]) -> int:
        n = len(mat)
        diag_sum = 0

        for i in range(n):
            diag_sum += mat[i][i]  # Main diagonal
            diag_sum += mat[i][n - 1 - i]  # Anti-diagonal

        # If n is odd, subtract the central element as it was counted twice
        if n % 2 == 1:
            diag_sum -= mat[n // 2][n // 2]

        return diag_sum
```

### Explanation

- Iterate through each row of the matrix `mat`.
- For each row `i`, add the element on the main diagonal (`mat[i][i]`) and the element on the anti-diagonal (`mat[i][n - 1 - i]`) to `diag_sum`.
- If the matrix size `n` is odd, subtract the central element (`mat[n // 2][n // 2]`) from `diag_sum`, as it was counted in both the main and anti-diagonals.
- Return the calculated `diag_sum`.

### Complexity Analysis

- **Time Complexity**: O(n), where `n` is the number of rows (or columns) of the square matrix. Each element on the main and anti-diagonal is visited exactly once.
- **Space Complexity**: O(1), as no additional space is used proportional to the input size.

This solution provides a straightforward and efficient way to calculate the sum of the elements on the diagonals of a square matrix.

### Explain Like I am Five (ELI5)

---

## Notes

---

 The main thing to look out for is the odd cases , also the constraints really helped simplify it but in another life matrix like the one below

## Related Videos

---

[https://www.youtube.com/watch?v=WliTu6gIK7o&pp=ygUTTWF0cml4IERpYWdvbmFsIFN1bQ%3D%3D](https://www.youtube.com/watch?v=WliTu6gIK7o&pp=ygUTTWF0cml4IERpYWdvbmFsIFN1bQ%3D%3D)