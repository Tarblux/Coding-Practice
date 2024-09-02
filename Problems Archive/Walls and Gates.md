# Walls and Gates

Problem: 286
Official Difficulty: medium
Feels Like : medium
My Understanding: Needs Review
Topic: Breadth-First Search(BFS), Matrix, array
Link: https://leetcode.com/problems/walls-and-gates/description/
Completed On : August 27, 2024
Last Review: August 27, 2024
Days Since Review: 5

## Problem

---

You are given an `m x n` grid `rooms` initialized with these three possible values.

- `1` A wall or an obstacle.
- `0` A gate.
- `INF` Infinity means an empty room. We use the value `231 - 1 = 2147483647` to represent `INF` as you may assume that the distance to a gate is less than `2147483647`.

Fill each empty room with the distance to *its nearest gate*. If it is impossible to reach a gate, it should be filled with `INF`.

**Example 1:**

![https://assets.leetcode.com/uploads/2021/01/03/grid.jpg](https://assets.leetcode.com/uploads/2021/01/03/grid.jpg)

```
Input: rooms = [[2147483647,-1,0,2147483647],[2147483647,2147483647,2147483647,-1],[2147483647,-1,2147483647,-1],[0,-1,2147483647,2147483647]]
Output: [[3,-1,0,1],[2,2,1,-1],[1,-1,2,-1],[0,-1,3,4]]
```

**Example 2:**

```
Input: rooms = [[-1]]
Output: [[-1]]
```

**Constraints:**

- `m == rooms.length`
- `n == rooms[i].length`
- `1 <= m, n <= 250`
- `rooms[i][j]` is `1`, `0`, or `231 - 1`.

## My Solutions

---

> This doesn’t quite work but see if you can think about why ,
> 

```python
from typing import List,Tuple,Generator
from collections import deque

class Solution:

    """
    - Build a neighbors helper generator function
    - Use neighbors helper to build a bfs that starts at each gate
    - At each empty cell find the minimum of it's current distance from gate and it's value
    - update the cell with the minimum
    """

    def neighbors(self,matrix:List[List[int]],r:int,c:int,d:int) -> Generator[Tuple[int,int],None,None]:

        directions = [(-1,0),(1,0),(0,-1),(0,1)]

        for dr , dc in directions:
            nr = r + dr
            nc = c + dc

            if nr >= 0 and nr < len(matrix) and nc >= 0 and nc < len(matrix[0]) and matrix[nr][nc] != -1:
                yield (nr,nc,d+1)

    def bfs(self,matrix:List[List[int]],r:int, c:int,d:int) -> int:

        visited = set()
        visited.add((r,c))
        queue = deque([(r,c,d)])

        while queue:

            cr , cc , cd = queue.popleft()

            if matrix[cr][cc] == -1:
                continue

            matrix[cr][cc] = min(cd,matrix[cr][cc])

            for neighbor in self.neighbors(matrix,cr,cc,cd):
                
                nr , nc , _ = neighbor
                
                if (nr,nc) not in visited:
                    visited.add((nr,nc))
                    queue.append(neighbor)

    def wallsAndGates(self, rooms: List[List[int]]) -> None:

        for r in range(len(rooms)):
            for c in range(len(rooms[0])):

                if rooms[r][c] == 0:
                    self.bfs(rooms,r,c,0)
                    

```

### This also doesn’t quite work because we end up not going level by level becuase of when we mark a node/cell as visited , note that with bfs we always need to mark a node as vistited before adding to the queue(enquing) , see : [https://stackoverflow.com/questions/45623722/marking-node-as-visited-on-bfs-when-dequeuing](https://stackoverflow.com/questions/45623722/marking-node-as-visited-on-bfs-when-dequeuing)

```python
from typing import List,Generator,Tuple
from collections import deque

class Solution:

    """
    - Setup bfs to traverse only empty cells ( val = inf)
    - At each empty cell find the minimum of it's current distance from gate and it's value
    - Update the cell with the minimum
    - Do bfs traversal from each each gate by enquing the gates first
    """

    def neighbors(self,matrix:List[List[int]],r:int,c:int,d:int) -> Generator[Tuple[int,int],None,None]:

        directions = [(-1,0),(1,0),(0,-1),(0,1)]

        for dr , dc in directions:
            nr = r + dr
            nc = c + dc

            if nr >= 0 and nr < len(matrix) and nc >= 0 and nc < len(matrix[0]) and matrix[nr][nc] != -1:
                yield (nr,nc,d+1)

    def bfs(self,matrix:List[List[int]],r:int,c:int,d:int) -> int:

        visited = set()
        visited.add((r,c))
        
        queue = deque([(r,c,d)])
        

        while queue:

            cr , cc , cd = queue.popleft()

            matrix[cr][cc] = min(cd,matrix[cr][cc])

            for neighbor in self.neighbors(matrix,cr,cc,cd):

                nr , nc , _ = neighbor
                if (nr,nc) not in visited:
                    visited.add((nr,nc))
                    queue.append(neighbor)
                    

    def wallsAndGates(self, rooms: List[List[int]]) -> None:

        for r in range(len(rooms)):
            for c in range(len(rooms[0])):

                if rooms[r][c] == 0:
                    self.bfs(rooms,r,c,0)
                    
rooms = [[2147483647,-1,0,2147483647],[2147483647,2147483647,2147483647,-1],[2147483647,-1,2147483647,-1],[0,-1,2147483647,2147483647]]
test = Solution()
test.wallsAndGates(rooms)

print ([[3,-1,0,1],[2,2,1,-1],[1,-1,2,-1],[0,-1,3,4]])
print(rooms)

```

1. How does enqueuing all gates at the start mean that BFS is performed from them simultaneously?

When you initialize the BFS queue with all gates at once, you’re effectively running a multi-source BFS. This approach leverages the idea that the BFS algorithm processes nodes level by level. Here’s how it works:

•   Initialization: All gates are enqueued with their initial distance (0).

•   Level-by-Level Processing: BFS processes nodes level by level. In the first level, all gates are processed, setting the initial distances for their immediate neighbors.

•   Simultaneous Expansion: In the next level, the immediate neighbors of all gates are processed, and so on.

This simultaneous expansion ensures that the shortest path to each empty room is found efficiently. Each room’s distance is updated the first time it’s reached because BFS explores all nodes at the current distance before moving to the next distance level.

2. Why can you write this without visited like in your last approach?

In the multi-source BFS approach, the visited set is implicitly handled by the matrix itself. Here’s why:

•   Matrix Updates: Each time a room’s distance is updated (i.e., rooms[nr][nc] = d + 1), it means this room has been visited.

•   Condition Check: The if condition in the neighbors method ensures that only rooms with the value 2147483647 (which signifies an empty room that hasn’t been visited yet) are considered for the next level of BFS.

Because the matrix is updated in place and only unvisited rooms are added to the queue, there’s no need for an explicit visited set. The matrix values serve as the visited markers.

## This works :)

```python
# Walls and Gates

from typing import Generator , List , Tuple
from collections import deque

class Solution:
    
    """
    - Create generator function that produces unvisited neighbor nodes
    - Enque all gates to a queue
    - Start a bfs from each gate and update the cell with the current distance from the gate
    - enque neighbors that have not been visited and continue until all are visited
    """
    
    def neighbors(self,matrix:List[List[int]],r:int,c:int,d:int) -> Generator[Tuple[int,int,int],None,None]:
        
        directions = [(-1,0),(1,0),(0,-1),(0,1)]
        
        for dr , dc in directions:
            
            nr = r + dr
            nc = c + dc 
            
            if nr >= 0 and nr < len(matrix) and nc >= 0 and nc < len(matrix[0]) and matrix[nr][nc] == 2147483647:
                yield(nr,nc,d+1)
                
    def wallsAndGates(self, rooms: List[List[int]]) -> None:
        
        if not rooms:
            return

        queue = deque()
        
        for r in range(len(rooms)):
            for c in range(len(rooms[0])):

                if rooms[r][c] == 0:
                   queue.append((r,c,0))
                   
        while queue:
            
            cr , cc , cd = queue.popleft()

            for nr , nc , nd in self.neighbors(rooms,cr,cc,cd):
                
                rooms[nr][nc] = nd
                queue.append((nr,nc,nd))         
```

## Optimal Solutions

---

### Problem Description

You are given a 2D grid consisting of rooms, walls, and gates. The grid is represented as follows:

- `1` represents a wall or obstacle.
- `0` represents a gate.
- `INF` represents an empty room. (The value of `INF` can be assumed to be a large number, e.g., `2^31 - 1`.)

You need to fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, leave the room's value as `INF`.

### Example

```python
Input:
rooms = [
  [INF, -1,  0,  INF],
  [INF, INF, INF, -1],
  [INF, -1, INF, -1],
  [0, -1, INF, INF]
]

Output:
rooms = [
  [3, -1,  0,  1],
  [2,  2,  1, -1],
  [1, -1,  2, -1],
  [0, -1,  3,  4]
]

```

### Approach

To solve this problem efficiently, we can use a Breadth-First Search (BFS) starting from all the gates simultaneously. BFS is ideal for this problem because it explores all nodes at the present depth level before moving on to nodes at the next depth level, ensuring that the shortest path to each room is found.

### Steps

1. **Initialize a Queue**:
    - Start by adding all gates (cells with value `0`) to a queue. These will be the starting points for our BFS.
2. **Perform BFS**:
    - For each cell in the queue, explore its four possible neighbors (up, down, left, right).
    - If the neighboring cell is an empty room (`INF`), update its value to be the current cell's value plus one (indicating one step further from the gate).
    - Add this neighboring cell to the queue to continue the BFS from this cell.
3. **Terminate when the Queue is Empty**:
    - Continue the BFS until all reachable rooms have been updated.

### Python Implementation

Here's how you can implement this in Python:

```python
from collections import deque

class Solution:
    def wallsAndGates(self, rooms: List[List[int]]) -> None:
        if not rooms:
            return

        INF = 2**31 - 1
        rows, cols = len(rooms), len(rooms[0])
        queue = deque()

        # Step 1: Initialize the queue with all gates
        for r in range(rows):
            for c in range(cols):
                if rooms[r][c] == 0:
                    queue.append((r, c))

        # Directions for moving in the grid (up, down, left, right)
        directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]

        # Step 2: BFS to update distances
        while queue:
            r, c = queue.popleft()
            current_distance = rooms[r][c]

            for dr, dc in directions:
                nr, nc = r + dr, c + dc
                # If the neighbor is within bounds and is an empty room
                if 0 <= nr < rows and 0 <= nc < cols and rooms[nr][nc] == INF:
                    rooms[nr][nc] = current_distance + 1
                    queue.append((nr, nc))

# Example usage
INF = 2**31 - 1
rooms = [
  [INF, -1,  0,  INF],
  [INF, INF, INF, -1],
  [INF, -1, INF, -1],
  [0, -1, INF, INF]
]

sol = Solution()
sol.wallsAndGates(rooms)
print(rooms)  # Output: [[3, -1,  0,  1], [2,  2,  1, -1], [1, -1,  2, -1], [0, -1,  3,  4]]

```

### Explanation

1. **Initialization**:
    - We first identify all gates in the grid and add their positions to the BFS queue.
2. **BFS Traversal**:
    - Starting from each gate, we explore its neighbors. If a neighbor is an empty room (`INF`), we update its distance to be one more than the current room and add it to the queue.
    - This process ensures that each room's value is updated to the shortest distance from any gate.
3. **Directional Movement**:
    - We use a `directions` list to handle the movement to neighboring cells (up, down, left, right).
4. **Efficiency**:
    - The BFS ensures that each room is visited the minimum number of times necessary, providing an optimal solution.

### Complexity Analysis

- **Time Complexity**: `O(m * n)`, where `m` is the number of rows and `n` is the number of columns in the grid. Each cell is processed at most once.
- **Space Complexity**: `O(m * n)` for the queue that stores all the gates and potentially all rooms.

This approach efficiently updates all rooms with the shortest distance to the nearest gate using BFS, ensuring that each room is processed in the minimum number of steps necessary.

## Notes

---

 

## Related Videos

---

[https://youtu.be/e69C6xhiSQE](https://youtu.be/e69C6xhiSQE)