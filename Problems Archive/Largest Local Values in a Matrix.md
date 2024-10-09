# Largest Local Values in a Matrix

Problem: 2373
Official Difficulty: easy
Feels Like : easy
My Understanding: Needs Review
Topic: Matrix, array
Link: https://leetcode.com/problems/largest-local-values-in-a-matrix/description/?envType=daily-question&envId=2024-05-12
Completed On : May 12, 2024
Last Review: May 12, 2024
Days Since Review: 7

## Problem

---

You are given an `n x n` integer matrix `grid`.

Generate an integer matrix `maxLocal` of size `(n - 2) x (n - 2)` such that:

- `maxLocal[i][j]` is equal to the **largest** value of the `3 x 3` matrix in `grid` centered around row `i + 1` and column `j + 1`.

In other words, we want to find the largest value in every contiguous `3 x 3` matrix in `grid`.

Return *the generated matrix*.

**Example 1:**

![https://assets.leetcode.com/uploads/2022/06/21/ex1.png](https://assets.leetcode.com/uploads/2022/06/21/ex1.png)

```
Input: grid = [[9,9,8,1],[5,6,2,6],[8,2,6,4],[6,2,2,2]]
Output: [[9,9],[8,6]]
Explanation: The diagram above shows the original matrix and the generated matrix.
Notice that each value in the generated matrix corresponds to the largest value of a contiguous 3 x 3 matrix in grid.
```

**Example 2:**

![https://assets.leetcode.com/uploads/2022/07/02/ex2new2.png](https://assets.leetcode.com/uploads/2022/07/02/ex2new2.png)

```
Input: grid = [[1,1,1,1,1],[1,1,1,1,1],[1,1,2,1,1],[1,1,1,1,1],[1,1,1,1,1]]
Output: [[2,2,2],[2,2,2],[2,2,2]]
Explanation: Notice that the 2 is contained within every contiguous 3 x 3 matrix in grid.

```

**Constraints:**

- `n == grid.length == grid[i].length`
- `3 <= n <= 100`
- `1 <= grid[i][j] <= 100`

## My Solutions

---

```python
class Solution:
    def largestLocal(self, grid: List[List[int]]) -> List[List[int]]:

        output = []

        for i in range(1,len(grid)-1):

            cur_row = []

            for j in range(1,len(grid)-1):

                cur_max = max(grid[i-1][j-1],grid[i-1][j],grid[i-1][j+1]
                              ,grid[i][j-1],grid[i][j],grid[i][j+1]
                              ,grid[i+1][j-1],grid[i+1][j],grid[i+1][j+1])

                cur_row.append(cur_max)

            output.append(cur_row)

        return output
```

```python

```

## Optimal Solutions

---

The problem "2373. Largest Local Values in a Matrix" involves extracting the maximum value from every contiguous 3x3 submatrix within a given 2D grid and forming a new matrix of these local maximums.

### Problem Statement:

You are given an `n x n` integer matrix `grid`, where `n >= 3`. For each `3 x 3` submatrix in `grid`, find the largest value and create a new matrix where each element represents the largest value from the corresponding `3 x 3` submatrix.

### Examples:

- **Input**: `grid = [[9,9,8,1],[5,6,2,6],[8,2,6,4],[6,2,2,2]]`
- **Output**: `[[9,9],[8,6]]`
- **Explanation**: The largest values from each `3x3` submatrix form a `2x2` matrix.

### Solution Approach:

### Sliding Window Technique:

This approach involves iterating over all possible `3 x 3` submatrices within the given matrix and computing the maximum for each submatrix.

1. **Determine Size of Resultant Matrix**: Given an `n x n` matrix, the resultant matrix of local maximums will be of size `(n-2) x (n-2)` because a `3 x 3` submatrix can only be formed starting up to the `(n-2)th` row and column.
2. **Iterate Through Submatrices**: For each position in the original matrix that can be the top-left corner of a `3 x 3` submatrix, compute the maximum within that submatrix.
3. **Populate Resultant Matrix**: Store each local maximum in the new matrix at the corresponding position.

### Code Implementation:

```python
class Solution:
    def largestLocal(self, grid: List[List[int]]) -> List[List[int]]:
        n = len(grid)
        result = [[0] * (n - 2) for _ in range(n - 2)]

        # Iterate over each possible top-left corner of a 3x3 submatrix
        for i in range(n - 2):
            for j in range(n - 2):
                # Find the maximum in the current 3x3 submatrix
                max_val = 0
                for x in range(3):
                    for y in range(3):
                        max_val = max(max_val, grid[i + x][j + y])
                result[i][j] = max_val

        return result

# Example usage
sol = Solution()
print(sol.largestLocal([[9,9,8,1],[5,6,2,6],[8,2,6,4],[6,2,2,2]]))  # Output: [[9,9],[8,6]]

```

### Complexity Analysis:

- **Time Complexity**: \(O((n-2)^2 \times 3^2)\) or simplified as \(O(n^2)\) assuming the inner constant operations due to the `3x3` submatrix are negligible. Essentially, you process each element in each `3x3` submatrix of the original `n x n` grid.
- **Space Complexity**: \(O(n-2)^2\) for the output matrix, but since we consider only extra space that doesn't include the output, the space complexity is \(O(1)\) for additional variables used.

This solution methodically calculates the maximum of each submatrix using a simple nested loop approach, ensuring that all areas of the matrix are covered and the results are stored efficiently.

## Notes

---

 

## Related Videos

---

[https://www.youtube.com/watch?v=wdTRu9sarFA](https://www.youtube.com/watch?v=wdTRu9sarFA)