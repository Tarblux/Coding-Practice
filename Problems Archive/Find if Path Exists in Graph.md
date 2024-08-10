# Find if Path Exists in Graph

Problem: 1971
Official Difficulty: easy
Feels Like : medium
My Understanding: Mostly Understand
Topic: Breadth-First Search(BFS), Depth-First Search (DFS), graph, union find
Link: https://leetcode.com/problems/find-if-path-exists-in-graph/description/
Completed On : June 27, 2024
Last Review: June 27, 2024
Days Since Review: 43

## Problem

---

There is a **bi-directional** graph with `n` vertices, where each vertex is labeled from `0` to `n - 1` (**inclusive**). The edges in the graph are represented as a 2D integer array `edges`, where each `edges[i] = [ui, vi]` denotes a bi-directional edge between vertex `ui` and vertex `vi`. Every vertex pair is connected by **at most one** edge, and no vertex has an edge to itself.

You want to determine if there is a **valid path** that exists from vertex `source` to vertex `destination`.

Given `edges` and the integers `n`, `source`, and `destination`, return `true` *if there is a **valid path** from* `source` *to* `destination`*, or* `false` *otherwise.*

**Example 1:**

![https://assets.leetcode.com/uploads/2021/08/14/validpath-ex1.png](https://assets.leetcode.com/uploads/2021/08/14/validpath-ex1.png)

```
Input: n = 3, edges = [[0,1],[1,2],[2,0]], source = 0, destination = 2
Output: true
Explanation: There are two paths from vertex 0 to vertex 2:
- 0 → 1 → 2
- 0 → 2
```

**Example 2:**

![https://assets.leetcode.com/uploads/2021/08/14/validpath-ex2.png](https://assets.leetcode.com/uploads/2021/08/14/validpath-ex2.png)

```
Input: n = 6, edges = [[0,1],[0,2],[3,5],[5,4],[4,3]], source = 0, destination = 5
Output: false
Explanation: There is no path from vertex 0 to vertex 5.
```

**Constraints:**

- `1 <= n <= 2 * 105`
- `0 <= edges.length <= 2 * 105`
- `edges[i].length == 2`
- `0 <= ui, vi <= n - 1`
- `ui != vi`
- `0 <= source, destination <= n - 1`
- There are no duplicate edges.
- There are no self edges.

## My Solutions

---

```python
class Solution:

    def __init__(self):
        self.visited = set()

    def dfs(self, nodes:Dict[int,List[int]],node:int,end:int):

        if node in self.visited:
            return False

        self.visited.add(node)

        if node == end:
            return True

        for ne in nodes[node]:

            found = False
            if ne not in self.visited:
                found = self.dfs(nodes,ne,end)

            if found:
                return True
        
        return False

    def validPath(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:

        if not edges:
            return source == destination

        nodes = defaultdict(list)

        for u,v in edges:

            nodes[v].append(u)
            nodes[u].append(v)

        return self.dfs(nodes,source,destination)

```

```python

```

## Optimal Solutions

---

### Problem Description

Given an undirected graph represented by an integer `n` (the number of nodes) and an array `edges` where `edges[i] = [a, b]` indicates that there is an edge between `a` and `b`, and two nodes `source` and `destination`, return `true` if there is a valid path between `source` and `destination`, or `false` otherwise.

### Example

```python
Input: n = 3, edges = [[0,1],[1,2],[2,0]], source = 0, destination = 2
Output: true

Input: n = 6, edges = [[0,1],[0,2],[3,5],[5,4],[4,3]], source = 0, destination = 5
Output: false

```

### Optimal Solution and Explanation

To solve this problem, we can use both BFS and DFS approaches to check if there is a path between the `source` and `destination` nodes in the graph.

### Steps:

1. **Graph Representation**:
    - Use an adjacency list to represent the graph.
2. **BFS (Breadth-First Search)**:
    - Use a queue to explore nodes level by level starting from the `source` node.
    - Use a set to keep track of visited nodes to avoid revisiting them.
3. **DFS (Depth-First Search)**:
    - Use a stack (iterative) or recursion (recursive) to explore nodes starting from the `source` node.
    - Use a set to keep track of visited nodes to avoid revisiting them.

### Python Code for BFS

Here's the Python code to achieve this using BFS:

```python
from collections import deque, defaultdict

def validPath(n, edges, source, destination):
    if source == destination:
        return True

    # Build the graph
    graph = defaultdict(list)
    for u, v in edges:
        graph[u].append(v)
        graph[v].append(u)

    # BFS initialization
    queue = deque([source])
    visited = set([source])

    while queue:
        node = queue.popleft()

        for neighbor in graph[node]:
            if neighbor == destination:
                return True
            if neighbor not in visited:
                visited.add(neighbor)
                queue.append(neighbor)

    return False

# Example usage
print(validPath(3, [[0,1],[1,2],[2,0]], 0, 2))  # Output: true
print(validPath(6, [[0,1],[0,2],[3,5],[5,4],[4,3]], 0, 5))  # Output: false

```

### Python Code for DFS

Here's the Python code to achieve this using DFS:

### Iterative DFS

```python
def validPath(n, edges, source, destination):
    if source == destination:
        return True

    # Build the graph
    graph = defaultdict(list)
    for u, v in edges:
        graph[u].append(v)
        graph[v].append(u)

    # DFS initialization
    stack = [source]
    visited = set([source])

    while stack:
        node = stack.pop()

        for neighbor in graph[node]:
            if neighbor == destination:
                return True
            if neighbor not in visited:
                visited.add(neighbor)
                stack.append(neighbor)

    return False

# Example usage
print(validPath(3, [[0,1],[1,2],[2,0]], 0, 2))  # Output: true
print(validPath(6, [[0,1],[0,2],[3,5],[5,4],[4,3]], 0, 5))  # Output: false

```

### Recursive DFS

```python
def validPath(n, edges, source, destination):
    def dfs(node, destination, graph, visited):
        if node == destination:
            return True
        visited.add(node)
        for neighbor in graph[node]:
            if neighbor not in visited:
                if dfs(neighbor, destination, graph, visited):
                    return True
        return False

    if source == destination:
        return True

    # Build the graph
    graph = defaultdict(list)
    for u, v in edges:
        graph[u].append(v)
        graph[v].append(u)

    visited = set()
    return dfs(source, destination, graph, visited)

# Example usage
print(validPath(3, [[0,1],[1,2],[2,0]], 0, 2))  # Output: true
print(validPath(6, [[0,1],[0,2],[3,5],[5,4],[4,3]], 0, 5))  # Output: false

```

### Explanation

1. **Graph Representation**:
    - Use an adjacency list (`defaultdict(list)`) to represent the graph, where each node points to its neighbors.
2. **BFS Approach**:
    - Use a queue to explore nodes level by level.
    - Start from the `source` node, mark it as visited, and add it to the queue.
    - For each node, explore its neighbors. If a neighbor is the `destination`, return `True`.
    - If a neighbor hasn't been visited, mark it as visited and add it to the queue.
    - Continue until the queue is empty. If the `destination` is not found, return `False`.
3. **DFS Approach**:
    - **Iterative DFS**: Use a stack to explore nodes. Similar to BFS, but uses a stack instead of a queue.
    - **Recursive DFS**: Use recursion to explore nodes. If a node is the `destination`, return `True`. Otherwise, recursively explore its neighbors.

### Time Complexity Analysis

- **Time Complexity**: `O(V + E)`, where `V` is the number of vertices (nodes) and `E` is the number of edges (connections) in the graph.
    - Each node and edge is processed once.

### Space Complexity Analysis

- **Space Complexity**: `O(V)`
    - Additional space is used for the adjacency list, the queue/stack for BFS/DFS, and the visited set.

Both BFS and DFS approaches efficiently determine if there is a valid path between the `source` and `destination` nodes in the graph.

## Notes

---

 

## Related Videos

---

[https://www.youtube.com/watch?v=hBeFkdxvHIU](https://www.youtube.com/watch?v=hBeFkdxvHIU)