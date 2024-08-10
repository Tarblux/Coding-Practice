# Find Valid Matrix Given Row

Problem: 1605
Official Difficulty: medium
Feels Like : hard
My Understanding: Mostly Understand, Needs Review
Topic: Matrix, array, greedy
Link: https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums/description/
Completed On : August 9, 2024
Last Review: August 9, 2024
Days Since Review: 0

## Problem

---

You are given two arrays `rowSum` and `colSum` of non-negative integers where `rowSum[i]` is the sum of the elements in the `ith` row and `colSum[j]` is the sum of the elements of the `jth`
 column of a 2D matrix. In other words, you do not know the elements of 
the matrix, but you do know the sums of each row and column.

Find any matrix of **non-negative** integers of size `rowSum.length x colSum.length` that satisfies the `rowSum` and `colSum` requirements.

Return *a 2D array representing **any** matrix that fulfills the requirements*. It's guaranteed that **at least one** matrix that fulfills the requirements exists.

**Example 1:**

```
Input: rowSum = [3,8], colSum = [4,7]
Output: [[3,0],
         [1,7]]
Explanation:
0th row: 3 + 0 = 3 == rowSum[0]
1st row: 1 + 7 = 8 == rowSum[1]
0th column: 3 + 1 = 4 == colSum[0]
1st column: 0 + 7 = 7 == colSum[1]
The row and column sums match, and all matrix elements are non-negative.
Another possible matrix is: [[1,2],
                             [3,5]]

```

**Example 2:**

```python
Input: rowSum = [5,7,10], colSum = [8,6,8]
Output: [[0,5,0],
         [6,1,0],
         [2,0,8]]
```

**Constraints:**

- `1 <= rowSum.length, colSum.length <= 500`
- `0 <= rowSum[i], colSum[i] <= 108`
- `sum(rowSum) == sum(colSum)`

## My Solutions

---

This wrong due a small nuance , make sure to fill across the row first and not the column 

```python
class Solution:
    def restoreMatrix(self, rowSum: List[int], colSum: List[int]) -> List[List[int]]:

        grid  = [[0 for _ in range(len(colSum))] for _ in range(len(rowSum))]

        for i in range(len(colSum)):
            for j in range(len(rowSum)):

                val = min(colSum[i],rowSum[j])
                grid[i][j] = val
                
                colSum[i] -= val
                rowSum[j] -= val

        return grid
```

The core idea behind the algorithm is to ensure that each cell in the matrix contributes to reducing both the corresponding row sum (`rowSum[i]`) and the column sum (`colSum[j]`) in a way that maintains the integrity of the remaining sums.

### Why Iterating Over Rows First Works:

1. **Row-First Iteration**:
    - When you iterate over `rowSum` first, you fill the matrix row by row. For each row, you allocate as much as possible to each column without exceeding the remaining sum in that row or column.
    - This approach ensures that by the time you move on to the next row, the previous row’s sum is completely satisfied, and the columns' remaining sums are updated accordingly.
    - By doing this, you maintain control over the remaining sums in both rows and columns, ensuring that the sums are met exactly by the end of the process.
2. **Column-First Iteration**:
    - If you iterate over `colSum` first, you attempt to fill the matrix column by column. This means you're trying to satisfy the column sums first before moving on to the next column.
    - However, because rows are not fully satisfied before moving to the next column, there's a risk that later row sums might not align well with the remaining column sums, leading to potential misalignment or incomplete satisfaction of the constraints.

### Summary:

- **Row-First Iteration**: It ensures that each row sum is satisfied in full, one at a time, while also adjusting the column sums to reflect what has been used. This approach aligns well with the problem's constraints.
- **Column-First Iteration**: While it might seem symmetrical, it doesn't guarantee that the remaining row sums will align properly with the remaining column sums as you progress, potentially leading to incorrect results.

Therefore, iterating over rows first (i.e., outer loop over `rowSum`) is crucial for ensuring that all the constraints are correctly satisfied.

```python
class Solution:
    def restoreMatrix(self, rowSum: List[int], colSum: List[int]) -> List[List[int]]:

        grid  = [[0 for _ in range(len(colSum))] for _ in range(len(rowSum))]

        for i in range(len(rowSum)):
            for j in range(len(colSum)):

                val = min(colSum[j],rowSum[i])
                grid[i][j] = val

                rowSum[i] -= val
                colSum[j] -= val
                
        return grid
```

```python
class Solution:
    def restoreMatrix(self, rowSum: List[int], colSum: List[int]) -> List[List[int]]:
        num_rows = len(rowSum)
        num_cols = len(colSum)
        res = [[0] * num_cols for _ in range(num_rows)]
        i, j = 0, 0
        while i < num_rows and j < num_cols:
            val = min(rowSum[i], colSum[j])
            res[i][j] = val
            rowSum[i] -= val
            colSum[j] -= val
            if rowSum[i] == 0:
                i += 1
            if colSum[j] == 0:
                j += 1
        return res            
```

## Optimal Solutions

---

### Problem Description

Given two arrays `rowSum` and `colSum` of integers where:

- `rowSum[i]` is the sum of the elements in the `i-th` row of a matrix.
- `colSum[j]` is the sum of the elements in the `j-th` column of a matrix.

Your task is to find any matrix of non-negative integers that satisfies the given row and column sums.

### Example

```python
Input: rowSum = [3, 8], colSum = [4, 7]
Output: [[3, 0],
         [1, 7]]

Input: rowSum = [5, 7, 10], colSum = [8, 6, 8]
Output: [[5, 0, 0],
         [3, 4, 0],
         [0, 2, 8]]

```

### Solution Approach

The problem can be approached greedily:

1. Initialize an empty matrix with dimensions corresponding to the lengths of `rowSum` and `colSum`.
2. Fill the matrix by iterating through each cell:
    - For each cell `(i, j)`, assign the minimum value between `rowSum[i]` and `colSum[j]`.
    - Subtract this value from both `rowSum[i]` and `colSum[j]`.
    - Continue until all cells are filled.

### Python Code

Here's the Python code to achieve this:

```python
from typing import List

class Solution:
    def restoreMatrix(self, rowSum: List[int], colSum: List[int]) -> List[List[int]]:
        m, n = len(rowSum), len(colSum)
        matrix = [[0] * n for _ in range(m)]

        for i in range(m):
            for j in range(n):
                # Determine the value to place in matrix[i][j]
                val = min(rowSum[i], colSum[j])

                # Assign the value
                matrix[i][j] = val

                # Update the rowSum and colSum
                rowSum[i] -= val
                colSum[j] -= val

        return matrix

# Example usage
sol = Solution()
print(sol.restoreMatrix([3, 8], [4, 7]))
# Output: [[3, 0], [1, 7]]

print(sol.restoreMatrix([5, 7, 10], [8, 6, 8]))
# Output: [[5, 0, 0], [3, 4, 0], [0, 2, 8]]

```

### Explanation

1. **Initialize the Matrix**:
    - `matrix = [[0] * n for _ in range(m)]` initializes an `m x n` matrix filled with zeros.
2. **Filling the Matrix**:
    - The nested loop iterates over each cell `(i, j)`.
    - For each cell, it assigns the minimum value between `rowSum[i]` and `colSum[j]` to the cell `matrix[i][j]`.
    - The corresponding row and column sums are then updated by subtracting this value.
3. **Why This Works**:
    - This approach ensures that we never exceed the required row or column sums while filling the matrix. By always taking the minimum available value, we can distribute the required sums effectively.

### Time Complexity Analysis

- **Time Complexity**: `O(m * n)`
    - The algorithm iterates over each cell of the matrix exactly once, where `m` is the number of rows and `n` is the number of columns.
- **Space Complexity**: `O(m * n)`
    - The space complexity is dominated by the storage required for the matrix, which is `O(m * n)`.

This solution efficiently constructs a valid matrix that satisfies the given row and column sums using a greedy approach.

## Notes

---

 

## Related Videos

---

[https://www.youtube.com/watch?v=Ks6fGnXkHPg](https://www.youtube.com/watch?v=Ks6fGnXkHPg)