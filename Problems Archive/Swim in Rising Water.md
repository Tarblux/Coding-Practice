# Swim in Rising Water

Problem: 778
Official Difficulty: hard
Feels Like : hard
My Understanding: Needs Review
Topic: Breadth-First Search(BFS), Depth-First Search (DFS), Heap(Priority Queue), Matrix, array, binary search, union find
Link: https://leetcode.com/problems/swim-in-rising-water/description/
Completed On : September 17, 2024
Last Review: September 17, 2024
Days Since Review: 0

## Problem

---

You are given an `n x n` integer matrix `grid` where each value `grid[i][j]` represents the elevation at that point `(i, j)`.

The rain starts to fall. At time `t`, the depth of the water everywhere is `t`.
 You can swim from a square to another 4-directionally adjacent square 
if and only if the elevation of both squares individually are at most `t`. You can swim infinite distances in zero time. Of course, you must stay within the boundaries of the grid during your swim.

Return *the least time until you can reach the bottom right square* `(n - 1, n - 1)` *if you start at the top left square* `(0, 0)`.

**Example 1:**

![https://assets.leetcode.com/uploads/2021/06/29/swim1-grid.jpg](https://assets.leetcode.com/uploads/2021/06/29/swim1-grid.jpg)

```
Input: grid = [[0,2],[1,3]]
Output: 3
Explanation:
At time 0, you are in grid location (0, 0).
You cannot go anywhere else because 4-directionally adjacent neighbors have a higher elevation than t = 0.
You cannot reach point (1, 1) until time 3.
When the depth of water is 3, we can swim anywhere inside the grid
```

**Example 2:**

![https://assets.leetcode.com/uploads/2021/06/29/swim2-grid-1.jpg](https://assets.leetcode.com/uploads/2021/06/29/swim2-grid-1.jpg)

```
Input: grid = [[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]
Output: 16
Explanation: The final route is shown.
We need to wait until time 16 so that (0, 0) and (4, 4) are connected.
```

**Constraints:**

- `n == grid.length`
- `n == grid[i].length`
- `1 <= n <= 50`
- `0 <= grid[i][j] < n2`
- Each value `grid[i][j]` is **unique**.

## My Solutions

---

```python
class Solution:

    def neighbors(self,grid:List[List[int]],r:int,c:int,visited):

        directions = [(-1,0),(1,0),(0,-1),(0,1)]

        for dr,dc in directions:
            nr = r + dr
            nc = c + dc

            if nr >= 0 and nr < len(grid) and nc >= 0 and nc < len(grid[0]) and (nr,nc) not in visited:
                yield (nr,nc)

    def swimInWater(self, grid: List[List[int]]) -> int:
        

        visited = set()
        distances = defaultdict(lambda:float('inf'))
        distances[(0,0)] = grid[0][0]
        n = len(grid)

        visited.add((0,0))
        heap = [(grid[0][0],0,0)] # (maxheight/Time,r,c)

        while heap:

            t , r , c = heapq.heappop(heap)
            
            if r == n-1 and c == n-1:
                return t

            for nr , nc in self.neighbors(grid,r,c,visited):
                
                visited.add((nr,nc))
                new_time = max(grid[nr][nc],t)
                heapq.heappush(heap,(new_time,nr,nc))

        return 0
```

```python

```

## Optimal Solutions

---

The **"Swim in Rising Water"** problem can be solved using **Dijkstra's algorithm** or **Binary Search with BFS/DFS**. Here's an explanation of how to solve it using **Dijkstra's algorithm** as it's one of the most intuitive ways to approach this problem.

### Problem Overview:

Given an `n x n` grid where each cell has a height, water levels rise with time, and you can swim from one cell to another if and only if the water level at time `T` is at least as large as the larger of the two cells' heights. Your goal is to find the minimum time `T` at which you can swim from the top-left corner `(0, 0)` to the bottom-right corner `(n-1, n-1)`.

### Approach:

The problem can be visualized as a **shortest path problem** on a grid. Each cell `(i, j)` in the grid is like a node in a graph, and you can move to any of the neighboring nodes (up, down, left, right) as long as the water level `T` is at least the maximum height of the cells you've visited.

- The goal is to **minimize the maximum height** encountered along the path from the top-left corner to the bottom-right corner.
- This can be achieved by using **Dijkstra's algorithm**, where instead of minimizing the distance, we minimize the maximum height encountered.

### Dijkstra's Algorithm Approach:

1. **Min-Heap (Priority Queue)**:
    - We use a min-heap to store cells `(height, x, y)`, where `height` is the maximum height encountered so far, and `(x, y)` is the current position.
    - The priority queue ensures that we always explore the cell with the smallest maximum height first.
2. **Track Visited Cells**:
    - Use a set to track which cells have already been visited, so we don't process them multiple times.
3. **Explore Neighbors**:
    - For each cell, explore its neighboring cells (up, down, left, right), and push them into the heap if they haven't been visited yet.
4. **Early Exit**:
    - As soon as we reach the bottom-right corner `(n-1, n-1)`, we return the current maximum height encountered along the path, which is the minimum time `T` needed to swim from the top-left to the bottom-right.

### Python Code Implementation:

```python
import heapq

class Solution:
    def swimInWater(self, grid):
        n = len(grid)

        # Min-Heap to store (max_height, x, y)
        min_heap = [(grid[0][0], 0, 0)]  # Start from the top-left corner
        visited = set([(0, 0)])  # Keep track of visited cells
        directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]  # Directions: right, left, down, up

        while min_heap:
            max_height, x, y = heapq.heappop(min_heap)

            # If we reached the bottom-right corner, return the result
            if x == n - 1 and y == n - 1:
                return max_height

            # Explore all neighbors
            for dx, dy in directions:
                nx, ny = x + dx, y + dy
                if 0 <= nx < n and 0 <= ny < n and (nx, ny) not in visited:
                    visited.add((nx, ny))
                    # Push the maximum height we encounter
                    heapq.heappush(min_heap, (max(max_height, grid[nx][ny]), nx, ny))

        return -1  # Should never be reached

```

### Explanation:

1. **Min-Heap Initialization**:
    - We initialize the min-heap with the starting cell `(grid[0][0], 0, 0)`, which represents the top-left corner of the grid.
2. **Visited Set**:
    - We use a `visited` set to track which cells we have already processed. This prevents reprocessing the same cell.
3. **Direction Handling**:
    - The `directions` array specifies the four possible moves (right, left, down, up). For each move, we calculate the new position `(nx, ny)` and check if it is valid (within bounds and not visited).
4. **Heap Operations**:
    - For each valid move, we push the new cell into the heap with the maximum height encountered so far. The heap ensures that we always process the cell with the smallest maximum height first, which leads to finding the minimum time required to swim across the grid.
5. **Early Exit**:
    - As soon as we reach the bottom-right corner, we return the current `max_height`, which represents the minimum time required to reach that point.

### Time Complexity:

- **Time Complexity**: `O(n^2 log n)`, where `n` is the number of rows (or columns) in the grid. There are `n^2` cells, and for each cell, we perform a `log n` operation when pushing or popping from the heap.
- **Space Complexity**: `O(n^2)` for the heap and the visited set, as we need to store the maximum number of elements (all the cells in the grid).

### Example:

```python
sol = Solution()
grid = [[0, 2], [1, 3]]
print(sol.swimInWater(grid))  # Output: 3

grid = [
    [0, 1, 2, 3, 4],
    [24, 23, 22, 21, 5],
    [12, 13, 14, 15, 16],
    [11, 17, 18, 19, 20],
    [10, 9, 8, 7, 6]
]
print(sol.swimInWater(grid))  # Output: 16

```

In the second example, the minimum time to swim from the top-left corner to the bottom-right corner is `16`, as we need to wait until the water level reaches `16` to safely traverse the grid.

### Alternative Approach (Binary Search + DFS/BFS):

Another way to solve this problem is to use **binary search** on the water level `T` and check if it's possible to reach the bottom-right corner using **DFS** or **BFS** with that water level. This approach can also be efficient, but **Dijkstra's algorithm** is more intuitive and directly handles the "minimizing maximum height" requirement.

## Notes

---

 

## Related Videos

---

[https://youtu.be/amvrKlMLuGY](https://youtu.be/amvrKlMLuGY)