# Rotting Oranges

Problem: 994
Official Difficulty: medium
Feels Like : easy
My Understanding: Fully Understand
Topic: Breadth-First Search(BFS), Matrix, array
Link: https://leetcode.com/problems/rotting-oranges/description/
Completed On : August 31, 2024
Last Review: August 31, 2024
Days Since Review: 1

## Problem

---

You are given an `m x n` `grid` where each cell can have one of three values:

- `0` representing an empty cell,
- `1` representing a fresh orange, or
- `2` representing a rotten orange.

Every minute, any fresh orange that is **4-directionally adjacent** to a rotten orange becomes rotten.

Return *the minimum number of minutes that must elapse until no cell has a fresh orange*. If *this is impossible, return* `-1`.

**Example 1:**

![https://assets.leetcode.com/uploads/2019/02/16/oranges.png](https://assets.leetcode.com/uploads/2019/02/16/oranges.png)

```
Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4

```

**Example 2:**

```
Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.

```

**Example 3:**

```
Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.

```

**Constraints:**

- `m == grid.length`
- `n == grid[i].length`
- `1 <= m, n <= 10`
- `grid[i][j]` is `0`, `1`, or `2`.

## My Solutions

---

```python
class Solution:

    """
    - Use a bfs 
    - Enque all rotten oranges and start a multisource bfs from each 
    - Count the number of times(minutes) the while loop runs for
    """

    def neighbor(self,matrix,r,c,minute):

        directions = [(-1,0),(1,0),(0,-1),(0,1)]

        for dr,dc in directions:

            nr = r + dr
            nc = c + dc
            
            if (nr >= 0 and nr < len(matrix) and nc >= 0 
            and nc < len(matrix[0]) and matrix[nr][nc] == 1):

                yield (nr,nc,minute + 1) 

    def orangesRotting(self, grid: List[List[int]]) -> int:

        if not grid:
            return -1

        queue = deque()
        rows = len(grid)
        cols = len(grid[0])

        minutes = -1
        fresh = 0

        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == 2:
                    queue.append((r,c,0))
                elif grid[r][c] == 1:
                    fresh += 1

        if not queue and fresh == 0:
            return 0

        while queue:

            cr , cc , cm = queue.popleft()

            minutes = cm

            for nr , nc , nm in self.neighbor(grid,cr,cc,cm):
                grid[nr][nc] = 2
                fresh -= 1
                queue.append((nr,nc,nm))

        if fresh > 0:
            return -1
        
        return minutes 
```

```python

```

## Optimal Solutions

---

Here is the solution for the "Rotting Oranges" problem using Breadth-First Search (BFS):

```python
from collections import deque
from typing import List

class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        if not grid:
            return -1

        rows, cols = len(grid), len(grid[0])
        queue = deque()
        fresh_oranges = 0

        # Step 1: Initialize the queue with all rotten oranges and count fresh oranges
        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == 2:
                    queue.append((r, c))
                elif grid[r][c] == 1:
                    fresh_oranges += 1

        # Edge case: If there are no fresh oranges
        if fresh_oranges == 0:
            return 0

        # Step 2: Perform BFS to simulate the rotting process
        directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        minutes_passed = 0

        while queue and fresh_oranges > 0:
            minutes_passed += 1
            for _ in range(len(queue)):
                r, c = queue.popleft()
                for dr, dc in directions:
                    nr, nc = r + dr, c + dc
                    if 0 <= nr < rows and 0 <= nc < cols and grid[nr][nc] == 1:
                        grid[nr][nc] = 2  # Mark the orange as rotten
                        fresh_oranges -= 1
                        queue.append((nr, nc))

        # Step 3: Check if there are any fresh oranges left
        return minutes_passed if fresh_oranges == 0 else -1

```

### Explanation:

1. **Initialization**:
    - We start by initializing a queue that will hold all the rotten oranges' positions. We also count the number of fresh oranges.
2. **BFS Execution**:
    - We perform BFS, where each level in the BFS corresponds to a minute passing. For each rotten orange, we try to infect its neighboring fresh oranges in all four directions (up, down, left, right).
    - Each fresh orange that gets infected is added to the queue to potentially infect other oranges in subsequent minutes.
3. **Result Determination**:
    - The BFS continues until no more fresh oranges can be infected. If all fresh oranges have been infected by the end, we return the number of minutes passed. Otherwise, if there are still fresh oranges left, return `1`.

### Complexity:

- **Time Complexity**: `O(m * n)`, where `m` is the number of rows and `n` is the number of columns in the grid. Each cell is processed at most once.
- **Space Complexity**: `O(m * n)` for the queue that stores the positions of the rotten oranges.

This approach efficiently simulates the spread of rot in the grid and ensures that the minimum time needed to rot all the oranges (if possible) is computed.

## Notes

---

 Realize that in my solution I passed what level the bfs was at each time but that is a little unnecessary since the while loop  keeps track of that since it runs once per level

## Related Videos

---

[https://youtu.be/y704fEOx0s0](https://youtu.be/y704fEOx0s0)