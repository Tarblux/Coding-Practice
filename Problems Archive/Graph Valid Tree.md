# Graph Valid Tree

Problem: 261
Official Difficulty: medium
Feels Like : medium
My Understanding: Mostly Understand
Topic: Breadth-First Search(BFS), Depth-First Search (DFS), graph, union find
Link: https://leetcode.com/problems/graph-valid-tree/description/?envType=problem-list-v2&envId=m748i2u3
Completed On : September 5, 2024
Last Review: September 5, 2024
Days Since Review: 3

## Problem

---

You have a graph of `n` nodes labeled from `0` to `n - 1`. You are given an integer n and a list of `edges` where `edges[i] = [ai, bi]` indicates that there is an undirected edge between nodes `ai` and `bi` in the graph.

Return `true` *if the edges of the given graph make up a valid tree, and* `false` *otherwise*.

**Example 1:**

![https://assets.leetcode.com/uploads/2021/03/12/tree1-graph.jpg](https://assets.leetcode.com/uploads/2021/03/12/tree1-graph.jpg)

```
Input: n = 5, edges = [[0,1],[0,2],[0,3],[1,4]]
Output: true
```

**Example 2:**

![https://assets.leetcode.com/uploads/2021/03/12/tree2-graph.jpg](https://assets.leetcode.com/uploads/2021/03/12/tree2-graph.jpg)

```
Input: n = 5, edges = [[0,1],[1,2],[2,3],[1,3],[1,4]]
Output: false
```

**Constraints:**

- `1 <= n <= 2000`
- `0 <= edges.length <= 5000`
- `edges[i].length == 2`
- `0 <= ai, bi < n`
- `ai != bi`
- There are no self-loops or repeated edges.

## My Solutions

---

```python
class Solution:

    def __init__(self):
        self.visited = set()
        self.curstack = set()

    def dfs(self,graph,node,parent):

        if node in self.visited:
            return False # Already visit and neva find cycle yah so

        self.curstack.add(node)
        self.visited.add(node)

        for neighbor in graph[node]:
            if neighbor == parent:
                continue
            if neighbor not in self.curstack:
                # send everything back up the call stack after finding cycle
                if self.dfs(graph,neighbor,node):
                    return True
            else:
                return True # Cycle detected (neighbor is already in the current call stack / DFS path)

        self.curstack.remove(node)
    
        return False

    def validTree(self, n: int, edges: List[List[int]]) -> bool:

        # valid tree has one root(have n - 1 edges for n nodes) , no cycles , fully connected

        graph = defaultdict(list)
        total_edges = 0
        components = 0

        for u,v in edges:
            graph[u].append(v)
            graph[v].append(u)
            total_edges += 1

        #check for n - 1 edges
        if total_edges != n-1:
            return False

        #check for cycles
        for node in range(n):
            if node not in self.visited:
                cycle = self.dfs(graph,node,None)
                components += 1
                if cycle:
                    return False

        #check for disconnections
        if components != 1:
            return False

        return True

```

```python

```

## Optimal Solutions

---

In order to determine if a given graph is a **valid tree**, you need to check two key properties:

1. **No Cycles**: A valid tree cannot contain any cycles.
2. **Connected**: A valid tree must be fully connected, meaning there must be exactly one connected component. All nodes must be reachable from any other node.

Additionally, for a graph with `n` nodes to be a valid tree, it must have **exactly `n-1` edges**. If there are more or fewer edges, the graph is either disconnected or contains cycles, and thus it cannot be a tree.

### Steps to Solve the Problem:

1. **Check the Edge Count**: If the number of edges is not `n-1`, return `False` immediately since the graph cannot be a valid tree.
2. **Check for Cycles and Connectivity**: Use DFS or BFS to verify if the graph contains any cycles and that all nodes are connected.

### Approach Using DFS:

Here’s how you can implement this:

```python
from collections import defaultdict

class Solution:

    def __init__(self):
        self.visited = set()

    def dfs(self, graph, node, parent):
        self.visited.add(node)

        for neighbor in graph[node]:
            if neighbor == parent:
                continue  # Skip the node we came from (parent)
            if neighbor in self.visited:
                return False  # Cycle detected
            if not self.dfs(graph, neighbor, node):
                return False

        return True

    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        # A valid tree has exactly n - 1 edges
        if len(edges) != n - 1:
            return False

        # Build the graph
        graph = defaultdict(list)
        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)

        # Perform DFS to check for cycles and connectivity
        if not self.dfs(graph, 0, -1):  # Start DFS from node 0 with no parent
            return False

        # Check if all nodes were visited (i.e., the graph is connected)
        return len(self.visited) == n

```

### Explanation:

1. **Graph Construction**:
    - The graph is represented as an adjacency list using `defaultdict(list)`.
2. **DFS Function**:
    - The `dfs` function recursively explores the graph, marking nodes as visited. It checks for cycles by making sure that no node is visited more than once unless it's the parent node.
    - If it detects a cycle (i.e., revisiting a node that isn't the parent), it returns `False`.
3. **Cycle Detection**:
    - The DFS skips the parent node (the node we came from) to avoid falsely detecting a cycle between a node and its parent.
4. **Edge Count Check**:
    - Before running DFS, we check if the number of edges is exactly `n-1`, since a valid tree must have exactly `n-1` edges.
5. **Connectivity Check**:
    - After the DFS traversal, we check if all nodes have been visited by comparing the size of the `visited` set to `n`. If the number of visited nodes is less than `n`, the graph is not fully connected.

### Time Complexity:

- **O(V + E)**, where `V` is the number of vertices (`n`) and `E` is the number of edges (`n-1`). This is because we are visiting each node and each edge exactly once.

### Space Complexity:

- **O(V + E)** for storing the adjacency list and the visited set.

### Example:

```python
# Test case 1
solution = Solution()
n = 5
edges = [[0,1],[0,2],[0,3],[1,4]]
print(solution.validTree(n, edges))  # Output: True

# Test case 2
solution = Solution()
n = 5
edges = [[0,1],[1,2],[2,3],[1,3],[1,4]]
print(solution.validTree(n, edges))  # Output: False (has a cycle)

```

### Key Points:

- A graph with `n` nodes and exactly `n-1` edges is a tree if and only if it is connected and has no cycles.
- DFS (or BFS) can be used to check for cycles and connectivity.

## Notes

---

 

## Related Videos

---

[https://youtu.be/bXsUuownnoQ](https://youtu.be/bXsUuownnoQ)