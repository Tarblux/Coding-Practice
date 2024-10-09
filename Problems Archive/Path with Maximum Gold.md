# Path with Maximum Gold

Problem: 1219
Official Difficulty: medium
Feels Like : hard
My Understanding: I Have No Idea
Topic: Matrix, array, backtracking
Link: https://leetcode.com/problems/path-with-maximum-gold/description/
Completed On : May 14, 2024
Last Review: May 14, 2024
Days Since Review: 5

## Problem

---

In a gold mine `grid` of size `m x n`, each cell in this mine has an integer representing the amount of gold in that cell, `0` if it is empty.

Return the maximum amount of gold you can collect under the conditions:

- Every time you are located in a cell you will collect all the gold in that cell.
- From your position, you can walk one step to the left, right, up, or down.
- You can't visit the same cell more than once.
- Never visit a cell with `0` gold.
- You can start and stop collecting gold from **any** position in the grid that has some gold.

**Example 1:**

```
Input: grid = [[0,6,0],[5,8,7],[0,9,0]]
Output: 24
Explanation:
[[0,6,0],
 [5,8,7],
 [0,9,0]]
Path to get the maximum gold, 9 -> 8 -> 7.
```

**Example 2:**

```
Input: grid = [[1,0,7],[2,0,6],[3,4,5],[0,3,0],[9,0,20]]
Output: 28
Explanation:
[[1,0,7],
 [2,0,6],
 [3,4,5],
 [0,3,0],
 [9,0,20]]
Path to get the maximum gold, 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7.
```

**Constraints:**

- `m == grid.length`
- `n == grid[i].length`
- `1 <= m, n <= 15`
- `0 <= grid[i][j] <= 100`
- There are at most **25** cells containing gold.

## My Solutions

---

```python
from typing import List, Dict, Tuple
from collections import defaultdict

class Solution:

    def dfs(self, matrix, x, y, current_sum, visited) -> int:
        
        rows, cols = len(matrix), len(matrix[0])

        if x < 0 or y < 0 or x >= rows or y >= cols:
            return current_sum

        if visited[(x, y)] or matrix[x][y] == 0:
            return current_sum

        visited[(x, y)] = True
        current_sum += matrix[x][y]

        max_gold = current_sum

        # Explore the four possible directions
        max_gold = max(max_gold, self.dfs(matrix, x + 1, y, current_sum, visited))
        max_gold = max(max_gold, self.dfs(matrix, x - 1, y, current_sum, visited))
        max_gold = max(max_gold, self.dfs(matrix, x, y + 1, current_sum, visited)) 
        max_gold = max(max_gold, self.dfs(matrix, x, y - 1, current_sum, visited))  

        # Backtrack
        visited[(x, y)] = False
        current_sum -= matrix[x][y]

        return max_gold

    def getMaximumGold(self, grid: List[List[int]]) -> int:

        rows, cols = len(grid), len(grid[0])
        max_gold = 0

        for i in range(rows):
            for j in range(cols):
                if grid[i][j] != 0:
                    visited = defaultdict(bool)
                    max_gold = max(max_gold, self.dfs(grid, i, j, 0, visited))

        return max_gold
```

Sanya

```python
class Solution:
    def getMaximumGold(self, grid: List[List[int]]) -> int:
        
        nodes = defaultdict(list) #(row, col): [(row, col), (row, col)]

        maximum = 0
        for r in range(len(grid)):
            for c in range(len(grid[0])):
                if grid[r][c] == 0:
                    continue
                if c > 0 and grid[r][c - 1] != 0:
                    nodes[(r, c)].append((r, c - 1))
                    nodes[(r, c - 1)].append((r, c))
                if r > 0 and grid[r - 1][c] != 0:
                    nodes[(r, c)].append((r - 1, c))
                    nodes[(r - 1, c)].append((r, c))
                maximum = max(maximum, grid[r][c])

        def dfs(r, c):
            visited.add((r, c))
            max_gold = 0
            for n_r, n_c in nodes[(r, c)]:
                if (n_r, n_c) not in visited:
                    max_gold = max(max_gold, dfs(n_r, n_c))
            visited.remove((r, c))
            return grid[r][c] + max_gold

        for key in nodes:
            r, c = key
            visited = set()
            maximum = max(maximum, dfs(r, c))

        return maximum
```

### 1. Grid Initialization and Adjacency List Creation

- **Adjacency List (`nodes`):** For each cell that contains gold, this list keeps track of its valid neighboring cells that also contain gold.
- **Grid Traversal:** The grid is traversed to populate the adjacency list. If a cell has a left or top neighbor with non-zero gold, those neighbors are added to the adjacency list.
- **Maximum Gold Initialization:** Tracks the highest single-cell gold value.

### 2. Depth-First Search (DFS)

```python
        def dfs(r, c):
            visited.add((r, c))  # Mark the current cell as visited
            max_gold = 0

            # Explore all adjacent cells
            for n_r, n_c in nodes[(r, c)]:
                if (n_r, n_c) not in visited:
                    max_gold = max(max_gold, dfs(n_r, n_c))

            visited.remove((r, c))  # Unmark the current cell (backtrack)
            return grid[r][c] + max_gold

```

- **Visited Set:** Keeps track of cells that have been visited to avoid cycles.
- **Recursive DFS:** Explores all valid paths from the current cell to find the path that yields the maximum gold.
- **Backtracking:** After exploring all paths from a cell, it is unmarked as visited to allow other paths to explore it again.

### 3. Main Function Execution

```python
        for key in nodes:
            r, c = key
            visited = set()
            maximum = max(maximum, dfs(r, c))

        return maximum

```

- **DFS from Each Node:** The function starts a DFS from each cell that contains gold. It initializes an empty `visited` set for each DFS call.
- **Update Maximum Gold:** The result of each DFS call is compared with the current maximum gold and updated accordingly.

### Example Execution

Consider the grid `[[0, 6, 0], [5, 8, 7], [0, 9, 0]]`.

1. **Adjacency List Creation:**
    - Nodes:
        - `(0, 1)`: Connected to `(1, 1)`
        - `(1, 0)`: Connected to `(1, 1)`
        - `(1, 1)`: Connected to `(0, 1)`, `(1, 0)`, `(1, 2)`, `(2, 1)`
        - `(1, 2)`: Connected to `(1, 1)`, `(2, 1)`
        - `(2, 1)`: Connected to `(1, 1)`, `(1, 2)`
2. **DFS Traversal:**
    - Starting from `(0, 1)`:
        - Paths: `(0, 1) -> (1, 1) -> (2, 1) -> (1, 2)`: Total Gold = 6 + 8 + 9 + 7 = 30.
    - Starting from `(1, 0)`:
        - Paths: `(1, 0) -> (1, 1) -> (2, 1) -> (1, 2)`: Total Gold = 5 + 8 + 9 + 7 = 29.
    - And so on for each valid starting cell.

The final maximum gold value is 30, found by the DFS starting from `(0, 1)`.

### Conclusion

The code efficiently constructs an adjacency list and uses DFS with backtracking to explore all possible paths, ensuring all cells with gold are considered. The `maximum` variable tracks the highest sum of gold collected from any starting cell, providing the desired result.

## Optimal Solutions

---

The LeetCode problem "Path with Maximum Gold" involves finding the maximum amount of gold you can collect starting from any cell in a grid and moving to adjacent cells (up, down, left, right), but not revisiting any cell.

Here's a thorough explanation and solution:

## Problem Statement

You are given an `m x n` grid of integers `grid` representing a map where `grid[i][j]` is the amount of gold in the cell `(i, j)`. You can start and stop collecting gold from any cell in the grid that contains gold. From a cell, you can move to any of the four directions (left, right, up, down) to another cell that contains gold. You cannot visit the same cell more than once. Return the maximum amount of gold you can collect.

## Optimal Solution Approach

This problem can be solved using Depth-First Search (DFS). We perform DFS starting from each cell that contains gold, keeping track of the maximum gold collected.

### Detailed Steps

1. **Initialize Variables**:
    - Initialize a variable `max_gold` to keep track of the maximum gold collected.
2. **DFS Function**:
    - Define a recursive DFS function that takes the current cell position and the current amount of gold collected.
    - In the DFS function, mark the current cell as visited by setting it to 0.
    - Explore all four possible directions (up, down, left, right).
    - Recur for each valid move (cells within bounds and containing gold).
    - After exploring all directions, backtrack by resetting the cell to its original value.
    - Update the maximum gold collected.
3. **Iterate Over All Cells**:
    - Iterate over all cells in the grid. If a cell contains gold, start a DFS from that cell.

### Code Implementation

```python
def getMaximumGold(grid):
    def dfs(x, y):
        if x < 0 or x >= len(grid) or y < 0 or y >= len(grid[0]) or grid[x][y] == 0:
            return 0
        current_gold = grid[x][y]
        grid[x][y] = 0  # Mark as visited
        max_gold = 0
        for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
            max_gold = max(max_gold, dfs(x + dx, y + dy))
        grid[x][y] = current_gold  # Backtrack
        return current_gold + max_gold

    max_gold = 0
    for i in range(len(grid)):
        for j in range(len(grid[0])):
            if grid[i][j] != 0:
                max_gold = max(max_gold, dfs(i, j))
    return max_gold

```

### Explanation

1. **DFS Function**:
    - The `dfs` function takes the current cell `(x, y)` as input.
    - If the cell is out of bounds or does not contain gold, it returns 0.
    - It stores the current cell's gold and marks the cell as visited by setting it to 0.
    - It then recursively explores all four possible directions (up, down, left, right) and keeps track of the maximum gold collected from these paths.
    - After exploring, it backtracks by resetting the cell's value to the original gold amount.
    - It returns the total gold collected from the current cell and the maximum gold from the explored paths.
2. **Iterate Over All Cells**:
    - The outer loops iterate over all cells in the grid.
    - For each cell containing gold, it starts a DFS and updates the `max_gold` if a higher amount of gold is collected.

### Explain Like I'm Five

Imagine you are in a garden with paths filled with gold coins. You can start from any path that has gold, and you can walk up, down, left, or right to collect more gold coins. But you can't walk on the same path twice.

You want to find out how much gold you can collect by walking through the garden. So, you try starting from each path with gold, and for each starting point, you walk in all possible directions, collecting as much gold as you can without walking on the same path again. Every time you walk, you remember how much gold you collected and try to find the path that gives you the most gold.

In the end, you figure out the maximum gold you can collect from any starting point and that's your answer.

## Notes

---

 

## Related Videos

---

[https://youtu.be/I1wllM_pozY](https://youtu.be/I1wllM_pozY)