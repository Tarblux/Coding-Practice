# Unique Paths

Problem: 62
Official Difficulty: medium
Feels Like : medium
Topic: Math, combinatronics, dynamic programming
Link: https://leetcode.com/problems/unique-paths/description/
Completed On : January 30, 2024
My Understanding: Needs Review
Last Review: January 30, 2024
Days Since Review: 11

## Problem

---

There is a robot on an `m x n` grid. The robot is initially located at the **top-left corner** (i.e., `grid[0][0]`). The robot tries to move to the **bottom-right corner** (i.e., `grid[m - 1][n - 1]`). The robot can only move either down or right at any point in time.

Given the two integers `m` and `n`, return *the number of possible unique paths that the robot can take to reach the bottom-right corner*.

The test cases are generated so that the answer will be less than or equal to `2 * 109`.

**Example 1:**

![https://assets.leetcode.com/uploads/2018/10/22/robot_maze.png](https://assets.leetcode.com/uploads/2018/10/22/robot_maze.png)

```
Input: m = 3, n = 7
Output: 28
```

**Example 2:**

```
Input: m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down
```

**Constraints:**

- `1 <= m, n <= 100`

## My Solutions

---

```python
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:

        grid = [[0 for _ in range(n)] for _ in range(m)]

        def helper (row , col) : 

            if row == 0 or col == 0: 

                return 1

            return grid[row-1][col] + grid[row][col-1]
        

        for i in range (m) :

            for ii in range (n) :

                grid[i][ii] = helper(i,ii)

        return grid[m-1][n-1]
```

```python

```

## Optimal Solutions

---

The "Unique Paths" problem is a classic example of a dynamic programming question. It asks for the number of unique paths from the top-left corner to the bottom-right corner of an `m x n` grid, assuming you can only move either down or right at any point in time.

### Problem Statement

Given two integers `m` and `n`, return the number of possible unique paths from the top-left corner to the bottom-right corner of an `m x n` grid.

### Solution Approach

A dynamic programming approach can be used to solve this problem efficiently. The number of unique paths to reach a cell `(i, j)` in the grid is the sum of the unique paths to reach the cell above it `(i-1, j)` and the cell to its left `(i, j-1)`.

### Python Implementation

```python
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        # Initialize a 2D DP array with 1s
        dp = [[1] * n for _ in range(m)]

        # Iterate over the array, starting from the second row and column
        for i in range(1, m):
            for j in range(1, n):
                dp[i][j] = dp[i-1][j] + dp[i][j-1]

        # The bottom-right corner will have the total unique paths
        return dp[m-1][n-1]
```

### Explanation

- A 2D array `dp` of size `m x n` is initialized with 1s, as there is only 1 way to reach any cell in the first row or first column (either all the way right or all the way down).
- For each cell not in the first row or first column, calculate the number of unique paths by adding the number of paths to the cell directly above and to the cell directly to the left.
- The final answer, the number of unique paths to reach the bottom-right corner, is found at `dp[m-1][n-1]`.

### Complexity Analysis

- **Time Complexity**: O(m * n), as we need to fill each cell in the `m x n` grid once.
- **Space Complexity**: O(m * n), for the 2D DP array. This can be optimized to O(min(m, n)) by using only a single row or column, but that makes the implementation a bit more complex.

This dynamic programming approach efficiently calculates the number of unique paths in a grid, leveraging the fact that the number of paths to each cell is the sum of the paths to the cells above and to the left of it.

### Explain Like I am Five (ELI5)

---

## Notes

---

 

## Related Videos

---

[https://www.youtube.com/watch?v=IlEsdxuD4lY](https://www.youtube.com/watch?v=IlEsdxuD4lY)