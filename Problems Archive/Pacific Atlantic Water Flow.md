# Pacific Atlantic Water Flow

Problem: 417
Official Difficulty: medium
Feels Like : medium
My Understanding: Mostly Understand
Topic: Breadth-First Search(BFS), Depth-First Search (DFS), Matrix, array
Link: https://leetcode.com/problems/pacific-atlantic-water-flow/description/
Completed On : August 30, 2024
Last Review: August 30, 2024
Days Since Review: 2

## Problem

---

There is an `m x n` rectangular island that borders both the **Pacific Ocean** and **Atlantic Ocean**. The **Pacific Ocean** touches the island's left and top edges, and the **Atlantic Ocean** touches the island's right and bottom edges.

The island is partitioned into a grid of square cells. You are given an `m x n` integer matrix `heights` where `heights[r][c]` represents the **height above sea level** of the cell at coordinate `(r, c)`.

The island receives a lot of rain, and the rain water can flow to 
neighboring cells directly north, south, east, and west if the 
neighboring cell's height is **less than or equal to** the current cell's height. Water can flow from any cell adjacent to an ocean into the ocean.

Return *a **2D list** of grid coordinates* `result` *where* `result[i] = [ri, ci]` *denotes that rain water can flow from cell* `(ri, ci)` *to **both** the Pacific and Atlantic oceans*.

**Example 1:**

![https://assets.leetcode.com/uploads/2021/06/08/waterflow-grid.jpg](https://assets.leetcode.com/uploads/2021/06/08/waterflow-grid.jpg)

```
Input: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
Output: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
Explanation: The following cells can flow to the Pacific and Atlantic oceans, as shown below:
[0,4]: [0,4] -> Pacific Ocean
       [0,4] -> Atlantic Ocean
[1,3]: [1,3] -> [0,3] -> Pacific Ocean
       [1,3] -> [1,4] -> Atlantic Ocean
[1,4]: [1,4] -> [1,3] -> [0,3] -> Pacific Ocean
       [1,4] -> Atlantic Ocean
[2,2]: [2,2] -> [1,2] -> [0,2] -> Pacific Ocean
       [2,2] -> [2,3] -> [2,4] -> Atlantic Ocean
[3,0]: [3,0] -> Pacific Ocean
       [3,0] -> [4,0] -> Atlantic Ocean
[3,1]: [3,1] -> [3,0] -> Pacific Ocean
       [3,1] -> [4,1] -> Atlantic Ocean
[4,0]: [4,0] -> Pacific Ocean
       [4,0] -> Atlantic Ocean
Note that there are other possible paths for these cells to flow to the Pacific and Atlantic oceans.

```

**Example 2:**

```
Input: heights = [[1]]
Output: [[0,0]]
Explanation: The water can flow from the only cell to the Pacific and Atlantic oceans.

```

**Constraints:**

- `m == heights.length`
- `n == heights[r].length`
- `1 <= m, n <= 200`
- `0 <= heights[r][c] <= 105`

## My Solutions

---

```python
class Solution:
    """
     - Store all atlantic and pacific shores in unique sets
     - Start bfs from each cell and mark shores as visited and if it visits both
       then append to the output

    TC:
    SC:
    """

    def neighbors(self,matrix,r,c):
        
        directions = [(-1,0),(1,0),(0,-1),(0,1)]

        for dr,dc in directions:

            nr = r + dr
            nc = c + dc

            if nr >= 0 and nr < len(matrix) and nc >= 0 and nc < len(matrix[0]) and matrix[nr][nc] <= matrix[r][c]:
                yield (nr,nc) 

    def bfs(self,matrix,r,c,pacific,atlantic):

        visited = set()
        visited.add((r,c))
        queue = deque([[r,c]])

        pushin_p = False
        pushin_a = False

        while queue:

            cr , cc = queue.popleft()

            if (cr,cc) in pacific:
                pushin_p = True

            if (cr,cc) in atlantic:
                pushin_a = True

            if pushin_p and pushin_a:
                return True

            for neighbor in self.neighbors(matrix,cr,cc):

                if neighbor not in visited:
                    visited.add(neighbor)
                    queue.append(neighbor)

        return False

    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:

        output = []
        pacific = set()
        atlantic = set()

        rows = len(heights)
        cols = len(heights[0])

        for i in range(rows):
            pacific.add((i, 0))           
            atlantic.add((i, cols - 1))   

        for j in range(cols):
            pacific.add((0, j))        
            atlantic.add((rows - 1, j)) 

        for r in range(len(heights)):
            for c in range(len(heights[0])):

                if self.bfs(heights,r,c,pacific,atlantic):
                    output.append([r,c])

        return output

```

Your approach to solving the Pacific Atlantic Water Flow problem is correct, and it works. However, there are some optimizations and improvements you can make to enhance both the time complexity and the space complexity.

### Optimizations:

1. **Avoid Repeated BFS:** Currently, you are performing BFS for each cell, which can lead to a high time complexity. Instead, perform BFS from all cells adjacent to the Pacific and Atlantic oceans simultaneously. This way, you only traverse each cell once, marking the cells that can reach the Pacific or Atlantic.
2. **Space Optimization:** You can avoid the `visited` set in the BFS function by utilizing the `pacific` and `atlantic` sets themselves to keep track of visited cells. This reduces the space complexity.
3. **Unifying the BFS Process:** Since the BFS for both oceans is similar, you can create a single BFS function that handles both the Pacific and Atlantic shores to avoid redundancy.

Here's the optimized code:

```python
from collections import deque

class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        if not heights or not heights[0]:
            return []

        rows, cols = len(heights), len(heights[0])

        pacific = set()
        atlantic = set()

        def bfs(starts, visited):
            queue = deque(starts)
            while queue:
                r, c = queue.popleft()
                for dr, dc in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
                    nr, nc = r + dr, c + dc
                    if (
                        0 <= nr < rows and
                        0 <= nc < cols and
                        (nr, nc) not in visited and
                        heights[nr][nc] >= heights[r][c]
                    ):
                        visited.add((nr, nc))
                        queue.append((nr, nc))

        for i in range(rows):
            pacific.add((i, 0))
            atlantic.add((i, cols - 1))

        for j in range(cols):
            pacific.add((0, j))
            atlantic.add((rows - 1, j))

        bfs(list(pacific), pacific)
        bfs(list(atlantic), atlantic)

        return list(pacific & atlantic)

```

Medz that the pacific set is passed into the bfs traversals to track visited and since the queue starts with all the outer pacific cells then any cell we visit from there is considered able to reach the pacific , now from there we do the same with the atlantic and then once we have all of them we can simply return the intersection of the sets which represents the cells that can reach both the atlantic and the pacific

### Explanation:

- **Avoiding Redundant BFS:** By starting the BFS from all Pacific-bordering cells at once and then doing the same for the Atlantic, you reduce the need to repeatedly traverse the grid for each cell.
- **Unified BFS Process:** A single BFS function handles the exploration for both the Pacific and Atlantic oceans, making the code more concise.
- **Intersection of Results:** The final result is obtained by finding the intersection of the cells that can reach both oceans.

### Time Complexity:

- **Time Complexity:** O(m * n) where m is the number of rows and n is the number of columns. Each cell is visited at most twice (once for each BFS).
- **Space Complexity:** O(m * n) for the sets storing visited cells.

This optimized solution should perform better, especially on larger grids.

## Optimal Solutions

---

### Approach

This problem can be solved using Depth-First Search (DFS) or Breadth-First Search (BFS). The main idea is to determine which cells can reach the Pacific Ocean and which cells can reach the Atlantic Ocean. The intersection of these two sets will give us the cells that can reach both oceans.

### Steps

1. **Initialize Two Visited Matrices**:
    - One matrix `pacific_reachable` to track cells that can reach the Pacific Ocean.
    - Another matrix `atlantic_reachable` to track cells that can reach the Atlantic Ocean.
2. **Run DFS from the Ocean Boundaries**:
    - Perform DFS for each cell on the Pacific boundary (top and left edges).
    - Perform DFS for each cell on the Atlantic boundary (bottom and right edges).
    - During the DFS, mark cells that can flow into the respective oceans.
3. **Find the Intersection**:
    - The cells that can reach both oceans are those that are marked as `True` in both `pacific_reachable` and `atlantic_reachable`.

### Python Implementation

Here’s how you can implement the solution using DFS:

```python
from typing import List

class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        if not heights or not heights[0]:
            return []

        rows, cols = len(heights), len(heights[0])
        pacific_reachable = [[False] * cols for _ in range(rows)]
        atlantic_reachable = [[False] * cols for _ in range(rows)]

        def dfs(r, c, reachable):
            reachable[r][c] = True
            directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]

            for dr, dc in directions:
                nr, nc = r + dr, c + dc
                if 0 <= nr < rows and 0 <= nc < cols and not reachable[nr][nc] and heights[nr][nc] >= heights[r][c]:
                    dfs(nr, nc, reachable)

        # Run DFS from all cells adjacent to the Pacific Ocean
        for r in range(rows):
            dfs(r, 0, pacific_reachable)
            dfs(r, cols - 1, atlantic_reachable)

        for c in range(cols):
            dfs(0, c, pacific_reachable)
            dfs(rows - 1, c, atlantic_reachable)

        # Find cells that can reach both oceans
        result = []
        for r in range(rows):
            for c in range(cols):
                if pacific_reachable[r][c] and atlantic_reachable[r][c]:
                    result.append([r, c])

        return result

# Example usage
sol = Solution()
heights = [
  [1,2,2,3,5],
  [3,2,3,4,4],
  [2,4,5,3,1],
  [6,7,1,4,5],
  [5,1,1,2,4]
]
print(sol.pacificAtlantic(heights))  # Output: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]

```

### Explanation

1. **DFS Initialization**:
    - We initialize two matrices `pacific_reachable` and `atlantic_reachable` to track which cells can reach the Pacific and Atlantic oceans, respectively.
2. **DFS Execution**:
    - We perform DFS from all cells adjacent to the Pacific Ocean and mark the cells that can flow to the Pacific.
    - Similarly, we perform DFS from all cells adjacent to the Atlantic Ocean and mark the cells that can flow to the Atlantic.
3. **Finding the Intersection**:
    - Finally, we iterate over all cells and check where both `pacific_reachable` and `atlantic_reachable` are `True`. These cells are added to the result list.

### Complexity Analysis

- **Time Complexity**: `O(m * n)`, where `m` is the number of rows and `n` is the number of columns. Each cell is visited multiple times (once per DFS).
- **Space Complexity**: `O(m * n)` for storing the `pacific_reachable` and `atlantic_reachable` matrices, as well as the recursion stack in DFS.

This solution efficiently determines which cells in the matrix can flow to both the Pacific and Atlantic oceans.

## Notes

---

 First Try 🇨🇨

## Related Videos

---

[https://youtu.be/s-VkcjHqkGI](https://youtu.be/s-VkcjHqkGI)