# Surrounded Regions

Problem: 130
Official Difficulty: medium
Feels Like : medium
My Understanding: Needs Review
Topic: Breadth-First Search(BFS), Depth-First Search (DFS), Matrix, array, union find
Link: https://leetcode.com/problems/surrounded-regions/description/?envType=problem-list-v2&envId=m748i2u3
Completed On : August 31, 2024
Last Review: August 31, 2024
Days Since Review: 1

## Problem

---

You are given an `m x n` matrix `board` containing **letters** `'X'` and `'O'`, **capture regions** that are **surrounded**:

- **Connect**: A cell is connected to adjacent cells horizontally or vertically.
- **Region**: To form a region **connect every** `'O'` cell.
- **Surround**: The region is surrounded with `'X'` cells if you can **connect the region** with `'X'` cells and none of the region cells are on the edge of the `board`.

A **surrounded region is captured** by replacing all `'O'`s with `'X'`s in the input matrix `board`.

**Example 1:**

**Input:** board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]

**Output:** [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]

**Explanation:**

![https://assets.leetcode.com/uploads/2021/02/19/xogrid.jpg](https://assets.leetcode.com/uploads/2021/02/19/xogrid.jpg)

In the above diagram, the bottom region is not captured because it is on the edge of the board and cannot be surrounded.

**Example 2:**

**Input:** board = [["X"]]

**Output:** [["X"]]

**Constraints:**

- `m == board.length`
- `n == board[i].length`
- `1 <= m, n <= 200`
- `board[i][j]` is `'X'` or `'O'`.

## My Solutions

---

```python
from typing import List

class Solution:

    def __init__(self):
        self.visited = set()

    def dfs(self, board, r, c):
        if r < 0 or r >= len(board) or c < 0 or c >= len(board[0]) or board[r][c] != 'O':
            return

        # Temporarily mark this cell as visited
        board[r][c] = 'T'  
        directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]

        for dr, dc in directions:
            self.dfs(board, r + dr, c + dc)

    def solve(self, board: List[List[str]]) -> None:
        if not board:
            return

        rows, cols = len(board), len(board[0])

        # Start DFS from the borders to mark non-surrounded regions
        for r in range(rows):
            for c in [0, cols - 1]:
                self.dfs(board, r, c)

        for c in range(cols):
            for r in [0, rows - 1]:
                self.dfs(board, r, c)

        # Convert all remaining 'O's to 'X's and 'T's back to 'O's
        for r in range(rows):
            for c in range(cols):
                if board[r][c] == 'O':
                    board[r][c] = 'X'
                elif board[r][c] == 'T':
                    board[r][c] = 'O'
```

```python

```

## Optimal Solutions

---

Here's the solution for the "Surrounded Regions" problem using Depth-First Search (DFS):

```python
from typing import List

class Solution:
    def solve(self, board: List[List[str]]) -> None:
        if not board or not board[0]:
            return

        rows, cols = len(board), len(board[0])

        def dfs(r, c):
            if r < 0 or c < 0 or r >= rows or c >= cols or board[r][c] != 'O':
                return
            board[r][c] = 'E'  # Mark the cell as 'E' (escaped)
            # Explore all four directions
            dfs(r + 1, c)
            dfs(r - 1, c)
            dfs(r, c + 1)
            dfs(r, c - 1)

        # Start DFS from the boundary cells to mark all connected 'O's
        for r in range(rows):
            for c in [0, cols - 1]:  # Left and right boundaries
                if board[r][c] == 'O':
                    dfs(r, c)
        for r in [0, rows - 1]:
            for c in range(cols):  # Top and bottom boundaries
                if board[r][c] == 'O':
                    dfs(r, c)

        # Process the board to flip surrounded regions
        for r in range(rows):
            for c in range(cols):
                if board[r][c] == 'O':
                    board[r][c] = 'X'  # Flip surrounded 'O' to 'X'
                elif board[r][c] == 'E':
                    board[r][c] = 'O'  # Restore escaped 'O'

```

### Key Steps:

1. **DFS to Mark Escaped Regions**:
    - Start DFS from any 'O' on the boundary and mark all connected 'O's as 'E' (escaped).
    - This prevents them from being flipped since they are not surrounded.
2. **Flipping Process**:
    - After marking the escape regions, iterate through the board:
        - Flip all remaining 'O's to 'X' because they are surrounded.
        - Convert 'E' back to 'O' to restore the unflipped regions.

### Complexity:

- **Time Complexity**: `O(m * n)`, where `m` is the number of rows and `n` is the number of columns.
- **Space Complexity**: `O(m * n)` in the worst case due to recursion stack usage.

This approach ensures that only regions of 'O' fully surrounded by 'X' are flipped, while regions connected to the boundary remain unchanged.

## Notes

---

 The main key is to reverse how you think about the question and first mark the cells at the edge and there connected cells temporarily which this give you certainty that all other Os must be surrounded and then after marking those we just need to mark the other Os as surrounded and then change the edges back

## Related Videos

---

[https://youtu.be/9z2BunfoZ5Y](https://youtu.be/9z2BunfoZ5Y)