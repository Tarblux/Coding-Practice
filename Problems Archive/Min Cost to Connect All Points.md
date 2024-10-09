# Min Cost to Connect All Points

Problem: 1584
Official Difficulty: medium
Feels Like : medium
My Understanding: Fully Understand
Topic: Minimum Spanning Tree, array, graph, union find
Link: https://leetcode.com/problems/min-cost-to-connect-all-points/description/
Completed On : September 10, 2024
Last Review: September 10, 2024
Days Since Review: 6

## Problem

---

You are given an array `points` representing integer coordinates of some points on a 2D-plane, where `points[i] = [xi, yi]`.

The cost of connecting two points `[xi, yi]` and `[xj, yj]` is the **manhattan distance** between them: `|xi - xj| + |yi - yj|`, where `|val|` denotes the absolute value of `val`.

Return *the minimum cost to make all points connected.* All points are connected if there is **exactly one** simple path between any two points.

**Example 1:**

![https://assets.leetcode.com/uploads/2020/08/26/d.png](https://assets.leetcode.com/uploads/2020/08/26/d.png)

```
Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
Output: 20
Explanation:
We can connect the points as shown above to get the minimum cost of 20.
Notice that there is a unique path between every pair of points.

```

![https://assets.leetcode.com/uploads/2020/08/26/c.png](https://assets.leetcode.com/uploads/2020/08/26/c.png)

**Example 2:**

```
Input: points = [[3,12],[-2,5],[-4,1]]
Output: 18

```

**Constraints:**

- `1 <= points.length <= 1000`
- `106 <= xi, yi <= 106`
- All pairs `(xi, yi)` are distinct.

## My Solutions

---

```python
class UnionFind:
    
    def __init__(self):
        self.parent = {}
        self.rank = defaultdict(lambda:1)
        
    def find(self,x):
        
        if x not in self.parent:
            self.parent[x] = x
            self.rank[x] += 1
            
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
            
        return self.parent[x]
            
    def union(self,x,y):
        
        rootX = self.find(x)
        rootY = self.find(y)
        
        if rootX == rootY:
            return False 
            
        if self.rank[rootX] > self.rank[rootY]:
            self.parent[rootY] = rootX
        elif self.rank[rootX] < self.rank[rootY]:
            self.parent[rootX] = rootY
        else: 
            self.parent[rootY] = rootX
            self.rank[rootX] += 1
                
        return True
        
class Solution:
    
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        
        uf = UnionFind()
        edges = []
        cost = 0
        
        for i in range(len(points)):
            for j in range(i,len(points)):
                if i != j:
                    
                    x1 , y1 = points[i]
                    x2 , y2 = points[j]
                    
                    manhattan_dist = abs(x2-x1) + abs(y2-y1)
                    edges.append((i,j,manhattan_dist))
                    
        edges.sort(key=lambda x : x[2])
        
        for u,v,weight in edges:
            
            if uf.find(u) != uf.find(v):
                uf.union(u,v)
                cost += weight
                
        return cost
```

```python

```

## Optimal Solutions

---

To solve the **"Min Cost to Connect All Points"** problem (similar to Minimum Spanning Tree (MST) problems), the goal is to connect all points using edges with the minimum total cost, where the cost between two points is the Manhattan distance between them.

### Key Concepts:

1. **Graph Representation**: Each point is a node, and each edge between any two points has a cost, which is the Manhattan distance between them.
2. **Manhattan Distance**: The distance between two points `(x1, y1)` and `(x2, y2)` is calculated as `|x1 - x2| + |y1 - y2|`.
3. **Minimum Spanning Tree (MST)**: The problem can be solved by finding a minimum spanning tree (MST) of the graph formed by the points, where the edges represent the cost of connecting two points. Two well-known algorithms for finding MST are **Prim's algorithm** and **Kruskal's algorithm**.

### Prim's Algorithm Approach

We'll use **Prim's algorithm** for this problem. The key idea of Prim's algorithm is to grow the MST one edge at a time, always choosing the smallest edge that connects a new point to the MST.

### Steps to Solve:

1. **Initialize**:
    - Start with any point (node) as part of the MST.
    - Use a priority queue (min-heap) to keep track of the next node to add, based on the smallest edge (distance) from the current MST to the remaining nodes.
2. **Expand the MST**:
    - At each step, choose the edge with the minimum cost that connects a new point (node) to the current MST.
    - Add the cost of this edge to the total cost.
3. **Terminate**:
    - Continue adding nodes to the MST until all nodes are included.

### Python Code Implementation:

```python
import heapq
from typing import List

class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        n = len(points)
        if n == 0:
            return 0

        # Helper function to calculate the Manhattan distance between two points
        def manhattan_distance(point1, point2):
            return abs(point1[0] - point2[0]) + abs(point1[1] - point2[1])

        # Prim's algorithm to find the minimum cost to connect all points
        min_cost = 0
        visited = [False] * n
        min_heap = [(0, 0)]  # (cost, point_index) starting from point 0
        edges_used = 0

        while edges_used < n:
            cost, u = heapq.heappop(min_heap)
            if visited[u]:
                continue
            # Add the node to the MST
            min_cost += cost
            visited[u] = True
            edges_used += 1

            # Push all edges from this node to the min-heap
            for v in range(n):
                if not visited[v]:
                    dist = manhattan_distance(points[u], points[v])
                    heapq.heappush(min_heap, (dist, v))

        return min_cost

# Example usage:
sol = Solution()
points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
print(sol.minCostConnectPoints(points))  # Output: 20

points = [[3,12],[-2,5],[-4,1]]
print(sol.minCostConnectPoints(points))  # Output: 18

```

### Explanation:

1. **Initialization**:
    - We initialize a min-heap (priority queue) starting with point `0` and a cost of `0`.
    - We maintain a `visited` array to mark points that are already part of the MST.
    - `edges_used` tracks how many edges have been added to the MST.
2. **Prim's Algorithm**:
    - We repeatedly extract the minimum cost edge from the heap, which connects a new point to the current MST.
    - We add this point to the MST and increase the total cost by the cost of the edge.
    - We then push all edges connecting the new point to unvisited points into the heap.
3. **Termination**:
    - The algorithm continues until we have added `n` points to the MST (i.e., until `edges_used == n`).

### Time Complexity:

- **Time Complexity**: `O(n^2 * log n)`, where `n` is the number of points. The reason for this complexity is that we push all possible edges for each point into the heap, and the heap operations take `log n` time.
- **Space Complexity**: `O(n^2)` for storing all edges and the heap.

### Kruskal's Algorithm Approach (Alternative)

Another way to solve this problem is using **Kruskal's algorithm**. In Kruskal's algorithm, you first sort all the edges by their cost and then use a **Union-Find** data structure to add edges to the MST, ensuring no cycles are formed.

However, Prim's algorithm is generally more efficient for dense graphs like this problem, where all points are connected to each other.

### Conclusion:

This solution uses **Prim's algorithm** to efficiently compute the minimum cost to connect all points. The Manhattan distance between points serves as the edge weights, and we grow the MST step by step, ensuring that we always choose the smallest edge to connect the next point.

## Notes

---

 

## Related Videos

---

[https://youtu.be/f7JOBJIC-NA](https://youtu.be/f7JOBJIC-NA)