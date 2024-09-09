# Number of Connected Components

Problem: 323
Official Difficulty: medium
Feels Like : easy
My Understanding: Fully Understand
Topic: Breadth-First Search(BFS), Depth-First Search (DFS), graph, union find
Link: https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/description/?envType=problem-list-v2&envId=m748i2u3
Completed On : September 5, 2024
Last Review: September 5, 2024
Days Since Review: 3

## Problem

---

You have a graph of `n` nodes. You are given an integer `n` and an array `edges` where `edges[i] = [ai, bi]` indicates that there is an edge between `ai` and `bi` in the graph.

Return *the number of connected components in the graph*.

**Example 1:**

![https://assets.leetcode.com/uploads/2021/03/14/conn1-graph.jpg](https://assets.leetcode.com/uploads/2021/03/14/conn1-graph.jpg)

```
Input: n = 5, edges = [[0,1],[1,2],[3,4]]
Output: 2
```

**Example 2:**

![https://assets.leetcode.com/uploads/2021/03/14/conn2-graph.jpg](https://assets.leetcode.com/uploads/2021/03/14/conn2-graph.jpg)

```
Input: n = 5, edges = [[0,1],[1,2],[2,3],[3,4]]
Output: 1
```

**Constraints:**

- `1 <= n <= 2000`
- `1 <= edges.length <= 5000`
- `edges[i].length == 2`
- `0 <= ai <= bi < n`
- `ai != bi`
- There are no repeated edges.

## My Solutions

---

```python
class Solution:

    def __init__(self):
        self.visited = set()

    def dfs(self,graph,node):

        if node in self.visited:
            return 

        self.visited.add(node) 

        for neighbor in graph[node]:
            if neighbor not in self.visited:
                self.dfs(graph,neighbor)

        
    def countComponents(self, n: int, edges: List[List[int]]) -> int:

        graph = defaultdict(list)
        components = 0

        for u,v in edges:
            graph[u].append(v)
            graph[v].append(u)

        for node in range(n):
            if node not in self.visited:
                self.dfs(graph,node)
                components += 1

        return components

        
```

```python

```

## Optimal Solutions

---

To solve the "Number of Connected Components in an Undirected Graph" problem, we need to determine how many distinct connected components exist in a given undirected graph.

### Steps to Solve

Given the number of nodes `n` and a list of edges representing the connections between them, we can approach the problem using either **Depth-First Search (DFS)** or **Union-Find (Disjoint Set Union)**. Both methods will help us determine the number of connected components.

---

### Solution 1: DFS Approach

The idea is to traverse the graph using DFS. Each time we find an unvisited node, we initiate a DFS traversal to mark all the nodes connected to it. Every time we initiate a new DFS, it means we have found a new connected component.

### Steps:

1. **Create an Adjacency List**:
    - Build the graph representation using an adjacency list.
2. **DFS Traversal**:
    - Use a `visited` array to track which nodes have been visited.
    - For each unvisited node, initiate a DFS traversal to mark all nodes connected to it. Every DFS initiation corresponds to finding a new connected component.

### Python Code (DFS Approach):

```python
from typing import List

class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        # Step 1: Build the adjacency list
        adj = {i: [] for i in range(n)}
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)

        # Step 2: Initialize the visited array
        visited = [False] * n

        def dfs(node):
            visited[node] = True
            for neighbor in adj[node]:
                if not visited[neighbor]:
                    dfs(neighbor)

        # Step 3: Count the number of connected components
        num_components = 0
        for i in range(n):
            if not visited[i]:
                dfs(i)
                num_components += 1

        return num_components

# Example usage
sol = Solution()
print(sol.countComponents(5, [[0, 1], [1, 2], [3, 4]]))  # Output: 2
print(sol.countComponents(5, [[0, 1], [1, 2], [2, 3], [3, 4]]))  # Output: 1

```

### Explanation:

1. **Building the Graph**:
    - We create an adjacency list where each node points to its neighboring nodes (nodes it has an edge with).
2. **DFS Traversal**:
    - Each time we encounter an unvisited node, we initiate a DFS traversal to mark all nodes connected to it.
3. **Counting Components**:
    - For each DFS initiation, we increment the number of connected components.

---

### Solution 2: Union-Find (Disjoint Set Union) Approach

The **Union-Find** (or **Disjoint Set Union, DSU**) approach is another efficient way to solve this problem. The idea is to treat each node as a separate component initially. As we process each edge, we "union" the components containing the two nodes. In the end, the number of unique components is the number of connected components.

### Steps:

1. **Initialize the Union-Find Structure**:
    - Each node starts as its own component.
2. **Union Operation**:
    - For each edge, we perform a union operation to merge the components containing the two nodes.
3. **Find Operation**:
    - We use the find operation to determine the root of each component.
4. **Counting Components**:
    - After processing all edges, count the number of unique components.

### Python Code (Union-Find Approach):

```python
class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        parent = list(range(n))
        rank = [1] * n

        def find(x):
            if parent[x] != x:
                parent[x] = find(parent[x])  # Path compression
            return parent[x]

        def union(x, y):
            rootX = find(x)
            rootY = find(y)

            if rootX != rootY:
                # Union by rank
                if rank[rootX] > rank[rootY]:
                    parent[rootY] = rootX
                elif rank[rootX] < rank[rootY]:
                    parent[rootX] = rootY
                else:
                    parent[rootY] = rootX
                    rank[rootX] += 1

        # Step 3: Process all edges and perform union operations
        for u, v in edges:
            union(u, v)

        # Step 4: Count the number of unique components
        components = len(set(find(i) for i in range(n)))
        return components

# Example usage
sol = Solution()
print(sol.countComponents(5, [[0, 1], [1, 2], [3, 4]]))  # Output: 2
print(sol.countComponents(5, [[0, 1], [1, 2], [2, 3], [3, 4]]))  # Output: 1

```

### Explanation:

1. **Union-Find Initialization**:
    - Each node starts as its own parent, and the rank array is initialized to `1` for each node.
2. **Union and Find Operations**:
    - The `find` function finds the root of a node using path compression to flatten the structure.
    - The `union` function merges two components using union by rank to keep the tree balanced.
3. **Counting Components**:
    - After processing all edges, we find the root of each node and count the number of unique roots (components).

---

### Complexity Analysis

### DFS Approach:

- **Time Complexity**: `O(n + e)`, where `n` is the number of nodes and `e` is the number of edges. We visit each node and each edge once.
- **Space Complexity**: `O(n + e)` for storing the adjacency list and the `visited` array.

### Union-Find Approach:

- **Time Complexity**: `O(n + e * α(n))`, where `α(n)` is the inverse Ackermann function (which is nearly constant in practice), `n` is the number of nodes, and `e` is the number of edges.
- **Space Complexity**: `O(n)` for storing the parent and rank arrays.

Both methods efficiently solve the problem. The Union-Find approach is often more efficient in practice for large inputs due to the near-constant time complexity for union and find operations with path compression.

## Notes

---

 

## Related Videos

---

[https://youtu.be/8f1XPm4WOUc](https://youtu.be/8f1XPm4WOUc)