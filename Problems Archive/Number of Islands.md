# Number of Islands

Problem: 200
Official Difficulty: medium
My Understanding: I Have No Idea
Feels Like : hard
Topic: Breadth-First Search(BFS), Depth-First Search (DFS), Matrix, array, union find
Link: https://leetcode.com/problems/number-of-islands/description/
Completed On : February 20, 2024
Last Review: February 20, 2024
Days Since Review: 6

## Problem

---

Given an `m x n` 2D binary grid `grid` which represents a map of `'1'`s (land) and `'0'`s (water), return *the number of islands*.

An **island** is surrounded by water and is formed by 
connecting adjacent lands horizontally or vertically. You may assume all
 four edges of the grid are all surrounded by water.

**Example 1:**

```
Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
```

**Example 2:**

```
Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
```

**Constraints:**

- `m == grid.length`
- `n == grid[i].length`
- `1 <= m, n <= 300`
- `grid[i][j]` is `'0'` or `'1'`.

## My Solutions

---

I did the padding with zero part but chatgpt did the rest and namely the recursion 

```python
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if not grid:
            return 0
        
        zero_grid = ['0'] * (len(grid[0]) + 2)
        new_grid = [zero_grid]

        for array in grid:
            temp = array.copy()
            temp.insert(0, '0')
            temp.append('0')
            new_grid.append(temp)
        
        new_grid.append(zero_grid)
        
        def dfs(i, j):
            if i < 0 or i >= len(new_grid) or j < 0 or j >= len(new_grid[0]) or new_grid[i][j] == '0':
                return
            new_grid[i][j] = '0'
            dfs(i + 1, j)
            dfs(i - 1, j)
            dfs(i, j + 1)
            dfs(i, j - 1)
        
        count = 0
        for i in range(1, len(new_grid) - 1):
            for j in range(1, len(new_grid[0]) - 1):
                if new_grid[i][j] == '1':
                    dfs(i, j)
                    count += 1
        
        return count
```

```python

```

## Optimal Solutions

---

The "Number of Islands" problem is a classic example of a depth-first search (DFS) application in a grid. Given a 2D grid map of `'1'`s (land) and `'0'`s (water), the task is to count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

### Problem Statement

Count the number of islands in the given 2D grid.

### Solution Approach

A straightforward way to solve this problem is by using DFS to explore each piece of land and mark it as visited, then continue to explore all connecting lands recursively. Once we start a DFS from a piece of unvisited land, we can mark all reachable lands (part of the same island) as visited. The number of times we initiate a DFS search gives us the number of islands.

### Python Implementation

```python
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if not grid:
            return 0

        num_islands = 0
        rows, cols = len(grid), len(grid[0])

        def dfs(r, c):
            if r < 0 or c < 0 or r >= rows or c >= cols or grid[r][c] == '0':
                return
            grid[r][c] = '0'  # Mark as visited by setting to '0'
            dfs(r+1, c)  # Down
            dfs(r-1, c)  # Up
            dfs(r, c+1)  # Right
            dfs(r, c-1)  # Left

        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == '1':
                    dfs(r, c)
                    num_islands += 1  # Increase for each successful DFS call

        return num_islands

```

### Explanation

- **DFS Function (`dfs`)**: The `dfs` function marks the current land (`'1'`) as visited by setting it to `'0'`. It then recursively calls itself for all four directions (up, down, left, right) to visit all connecting pieces of land.
- **Main Logic**: Iterate through each cell in the grid. When an unvisited piece of land (`'1'`) is found, initiate a DFS search from that cell to mark all connected lands as visited. Increment the `num_islands` counter each time a new DFS search is started.
- **Edge Case Handling**: The DFS search includes boundary checks to ensure we don't go outside the grid. It also checks whether the current cell is water (`'0'`), in which case the search returns immediately without further exploration.

### Complexity Analysis

- **Time Complexity**: O(M*N), where M is the number of rows and N is the number of columns in the grid. In the worst case, all cells in the grid might be lands, necessitating a visit to each cell.
- **Space Complexity**: O(M*N) in the worst case due to the recursion stack. This would be the case for a grid full of lands where DFS goes as deep as the total number of cells in the grid.

## Notes

---

 

## Related Videos

---

[https://www.youtube.com/watch?v=pV2kpPD66nE](https://www.youtube.com/watch?v=pV2kpPD66nE)