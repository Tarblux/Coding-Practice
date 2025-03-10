# Longest Increasing Path in Matrix

Problem: 329
Official Difficulty: hard
Feels Like : hard
My Understanding: Needs Review
Topic: Breadth-First Search(BFS), Depth-First Search (DFS), Matrix, Topological Sort, array, dynamic programming, graph, memoization
Link: https://leetcode.com/problems/longest-increasing-path-in-a-matrix/description/
Completed On : March 8, 2025
Last Review: March 8, 2025
Days Since Review: 1
Neetcode: Yes

## Problem

---

Given an `m x n` integers `matrix`, return *the length of the longest increasing path in* `matrix`.

From each cell, you can either move in four directions: left, right, up, or down. You **may not** move **diagonally** or move **outside the boundary** (i.e., wrap-around is not allowed).

**Example 1:**

![](https://assets.leetcode.com/uploads/2021/01/05/grid1.jpg)

```
Input: matrix = [[9,9,4],[6,6,8],[2,1,1]]
Output: 4
Explanation: The longest increasing path is[1, 2, 6, 9].
```

**Example 2:**

![](https://assets.leetcode.com/uploads/2021/01/27/tmp-grid.jpg)

```
Input: matrix = [[3,4,5],[3,2,6],[2,2,1]]
Output: 4
Explanation:The longest increasing path is[3, 4, 5, 6]. Moving diagonally is not allowed.
```

**Example 3:**

```
Input: matrix = [[1]]
Output: 1
```

**Constraints:**

- `m == matrix.length`
- `n == matrix[i].length`
- `1 <= m, n <= 200`
- `0 <= matrix[i][j] <= 231 - 1`

## My Solutions

---

```python

```

```
class Solution:
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:

        if not matrix or not matrix[0]:
            return 0

        rows, cols = len(matrix), len(matrix[0])

        def neighbors(r, c):
            # up, down, left, right
            for dr, dc in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
                nr, nc = r + dr, c + dc
                if 0 <= nr < rows and 0 <= nc < cols:
                    yield nr, nc

        @cache
        def dfs(r, c):

            max_length = 1
            for nr, nc in neighbors(r, c):

                if matrix[nr][nc] > matrix[r][c]:
                    max_length = max(max_length, 1 + dfs(nr, nc))
            return max_length

        
        max_length = float('-inf')
        for r in range(rows):
            for c in range(cols):
                length = dfs(r,c)
                max_length = max(max_length,length)

        return max_length
```

```python

```

## Optimal Solutions

---

## Notes

---

 

## Related Videos

---

[https://www.notion.so](https://www.notion.so)