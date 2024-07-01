# Max Area of Island

Problem: 695
Official Difficulty: medium
Feels Like : medium
My Understanding: Needs Review
Topic: Breadth-First Search(BFS), Depth-First Search (DFS), Matrix, array, union find
Link: https://leetcode.com/problems/max-area-of-island/description/
Completed On : June 30, 2024
Last Review: June 30, 2024
Days Since Review: 1

## Problem

---

You are given an `m x n` binary matrix `grid`. An island is a group of `1`'s (representing land) connected **4-directionally** (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

The **area** of an island is the number of cells with a value `1` in the island.

Return *the maximum **area** of an island in* `grid`. If there is no island, return `0`.

**Example 1:**

![https://assets.leetcode.com/uploads/2021/05/01/maxarea1-grid.jpg](https://assets.leetcode.com/uploads/2021/05/01/maxarea1-grid.jpg)

```
Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
Output: 6
Explanation: The answer is not 11, because the island must be connected 4-directionally.
```

**Example 2:**

```
Input: grid = [[0,0,0,0,0,0,0,0]]
Output: 0
```

**Constraints:**

- `m == grid.length`
- `n == grid[i].length`
- `1 <= m, n <= 50`
- `grid[i][j]` is either `0` or `1`.

## My Solutions

---

```python
class Solution:

    def __init__(self):
        self.visited = set()

    def dfs(self,grid:List[List[int]],r,c) -> int:

        if (r,c) in self.visited:
            return 0

        if r < 0 or r >= len(grid) or c < 0 or c >= len(grid[0]) or grid[r][c] == 0:
            return 0

        # up , down , left , right
        directions = [(-1,0),(1,0),(0,-1),(0,1)]

        self.visited.add((r,c))

        area = 1

        for dr , dc in directions:

            area += self.dfs(grid,r + dr,c + dc)

        return area

    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:

        if not grid:
            return 0

        max_area = 0
        
        for r in range(len(grid)):
            for c in range(len(grid[0])):
                
                if grid[r][c] == 1:
                    max_area = max(max_area,self.dfs(grid,r,c))

                    
        return max_area
```

```python

```

## Optimal Solutions

---

https://neetcode.aleksandrmolchagin.com/Neetcode-150/Graphs/MaxAreaOfIsland

To solve this problem, we can use both BFS and DFS approaches to traverse the grid and calculate the area of each island. The goal is to find the maximum area of all islands.

### Steps:

1. **Graph Representation**:
    - The grid is represented as a 2D list of integers.
2. **BFS/DFS for Island Traversal**:
    - Use BFS or DFS to explore all connected land cells starting from each unvisited land cell.
    - Mark cells as visited to avoid counting them multiple times.
    - Track the area of each island and update the maximum area found.

### Python Code for BFS

Here's the Python code to achieve this using BFS:

```python
from collections import deque

class Solution:
    def maxAreaOfIsland(self, grid):
        if not grid:
            return 0

        def bfs(r, c):
            queue = deque([(r, c)])
            grid[r][c] = 0  # Mark as visited
            area = 0
            while queue:
                x, y = queue.popleft()
                area += 1
                for dx, dy in [(0, 1), (1, 0), (0, -1), (-1, 0)]:
                    nx, ny = x + dx, y + dy
                    if 0 <= nx < len(grid) and 0 <= ny < len(grid[0]) and grid[nx][ny] == 1:
                        grid[nx][ny] = 0  # Mark as visited
                        queue.append((nx, ny))
            return area

        max_area = 0
        for r in range(len(grid)):
            for c in range(len(grid[0])):
                if grid[r][c] == 1:
                    max_area = max(max_area, bfs(r, c))

        return max_area

# Example usage
solution = Solution()
print(solution.maxAreaOfIsland([[0,0,1,0,0,0,0,1,0,0,0,0,0],
                                [0,0,0,0,0,0,0,1,1,1,0,0,0],
                                [0,1,1,0,1,0,0,0,0,0,0,0,0],
                                [0,1,0,0,1,1,0,0,1,0,1,0,0],
                                [0,1,0,0,1,1,0,0,1,1,1,0,0],
                                [0,0,0,0,0,0,0,0,0,0,1,0,0],
                                [0,0,0,0,0,0,0,1,1,1,0,0,0],
                                [0,0,0,0,0,0,0,1,1,0,0,0,0]]))  # Output: 6
print(solution.maxAreaOfIsland([[0,0,0,0,0,0,0,0]]))  # Output: 0

```

### Python Code for DFS

Here's the Python code to achieve this using DFS:

### Iterative DFS

```python
class Solution:
    def maxAreaOfIsland(self, grid):
        if not grid:
            return 0

        def dfs(r, c):
            stack = [(r, c)]
            grid[r][c] = 0  # Mark as visited
            area = 0
            while stack:
                x, y = stack.pop()
                area += 1
                for dx, dy in [(0, 1), (1, 0), (0, -1), (-1, 0)]:
                    nx, ny = x + dx, y + dy
                    if 0 <= nx < len(grid) and 0 <= ny < len(grid[0]) and grid[nx][ny] == 1:
                        grid[nx][ny] = 0  # Mark as visited
                        stack.append((nx, ny))
            return area

        max_area = 0
        for r in range(len(grid)):
            for c in range(len(grid[0])):
                if grid[r][c] == 1:
                    max_area = max(max_area, dfs(r, c))

        return max_area

# Example usage
solution = Solution()
print(solution.maxAreaOfIsland([[0,0,1,0,0,0,0,1,0,0,0,0,0],
                                [0,0,0,0,0,0,0,1,1,1,0,0,0],
                                [0,1,1,0,1,0,0,0,0,0,0,0,0],
                                [0,1,0,0,1,1,0,0,1,0,1,0,0],
                                [0,1,0,0,1,1,0,0,1,1,1,0,0],
                                [0,0,0,0,0,0,0,0,0,0,1,0,0],
                                [0,0,0,0,0,0,0,1,1,1,0,0,0],
                                [0,0,0,0,0,0,0,1,1,0,0,0,0]]))  # Output: 6
print(solution.maxAreaOfIsland([[0,0,0,0,0,0,0,0]]))  # Output: 0

```

### Recursive DFS

```python
class Solution:
    def maxAreaOfIsland(self, grid):
        if not grid:
            return 0

        def dfs(r, c):
            if r < 0 or r >= len(grid) or c < 0 or c >= len(grid[0]) or grid[r][c] == 0:
                return 0
            grid[r][c] = 0  # Mark as visited
            return 1 + dfs(r + 1, c) + dfs(r - 1, c) + dfs(r, c + 1) + dfs(r, c - 1)

        max_area = 0
        for r in range(len(grid)):
            for c in range(len(grid[0])):
                if grid[r][c] == 1:
                    max_area = max(max_area, dfs(r, c))

        return max_area

# Example usage
solution = Solution()
print(solution.maxAreaOfIsland([[0,0,1,0,0,0,0,1,0,0,0,0,0],
                                [0,0,0,0,0,0,0,1,1,1,0,0,0],
                                [0,1,1,0,1,0,0,0,0,0,0,0,0],
                                [0,1,0,0,1,1,0,0,1,0,1,0,0],
                                [0,1,0,0,1,1,0,0,1,1,1,0,0],
                                [0,0,0,0,0,0,0,0,0,0,1,0,0],
                                [0,0,0,0,0,0,0,1,1,1,0,0,0],
                                [0,0,0,0,0,0,0,1,1,0,0,0,0]]))  # Output: 6
print(solution.maxAreaOfIsland([[0,0,0,0,0,0,0,0]]))  # Output: 0

```

### Explanation

1. **Graph Representation**:
    - The grid

is represented as a 2D list of integers.

- Each `1` represents land, and each `0` represents water.
1. **BFS Approach**:
    - Use a queue to explore all connected land cells starting from each unvisited land cell.
    - Mark cells as visited by setting their value to `0`.
    - Track the area of each island and update the maximum area found.
2. **DFS Approach**:
    - **Iterative DFS**: Use a stack to explore all connected land cells.
    - **Recursive DFS**: Use recursion to explore all connected land cells.
    - Mark cells as visited by setting their value to `0`.
    - Track the area of each island and update the maximum area found.

### Time Complexity Analysis

- **Time Complexity**: `O(m * n)`
    - We visit each cell in the grid once, where `m` is the number of rows and `n` is the number of columns.

### Space Complexity Analysis

- **Space Complexity**: `O(m * n)`
    - The space complexity is determined by the size of the queue/stack and the visited set, which can grow up to `m * n` in the worst case.

Both BFS and DFS approaches efficiently calculate the maximum area of an island in the grid using linear time complexity.

## Notes

---

 

## Related Videos

---

[https://www.notion.so](https://www.notion.so)