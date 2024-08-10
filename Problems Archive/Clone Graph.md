# Clone Graph

Problem: 133
Official Difficulty: medium
Feels Like : medium
My Understanding: Needs Review
Topic: Breadth-First Search(BFS), Depth-First Search (DFS), graph, hash table
Link: https://leetcode.com/problems/clone-graph/description/
Completed On : June 19, 2024
Last Review: June 19, 2024
Days Since Review: 51

## Problem

---

Given a reference of a node in a [**connected**](https://en.wikipedia.org/wiki/Connectivity_(graph_theory)#Connected_graph) undirected graph.

Return a [**deep copy**](https://en.wikipedia.org/wiki/Object_copying#Deep_copy) (clone) of the graph.

Each node in the graph contains a value (`int`) and a list (`List[Node]`) of its neighbors.

```
class Node {
    public int val;
    public List<Node> neighbors;
}
```

**Test case format:**

For simplicity, each node's value is the same as the node's index (1-indexed). For example, the first node with `val == 1`, the second node with `val == 2`, and so on. The graph is represented in the test case using an adjacency list.

**An adjacency list** is a collection of unordered **lists** used to represent a finite graph. Each list describes the set of neighbors of a node in the graph.

The given node will always be the first node with `val = 1`. You must return the **copy of the given node** as a reference to the cloned graph.

**Example 1:**

![https://assets.leetcode.com/uploads/2019/11/04/133_clone_graph_question.png](https://assets.leetcode.com/uploads/2019/11/04/133_clone_graph_question.png)

```
Input: adjList = [[2,4],[1,3],[2,4],[1,3]]
Output: [[2,4],[1,3],[2,4],[1,3]]
Explanation: There are 4 nodes in the graph.
1st node (val = 1)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
2nd node (val = 2)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
3rd node (val = 3)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
4th node (val = 4)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).

```

**Example 2:**

![https://assets.leetcode.com/uploads/2020/01/07/graph.png](https://assets.leetcode.com/uploads/2020/01/07/graph.png)

```
Input: adjList = [[]]
Output: [[]]
Explanation: Note that the input contains one empty list. The graph consists of only one node with val = 1 and it does not have any neighbors.

```

**Example 3:**

```
Input: adjList = []
Output: []
Explanation: This an empty graph, it does not have any nodes.

```

**Constraints:**

- The number of nodes in the graph is in the range `[0, 100]`.
- `1 <= Node.val <= 100`
- `Node.val` is unique for each node.
- There are no repeated edges and no self-loops in the graph.
- The Graph is connected and all nodes can be visited starting from the given node.

## My Solutions

---

```python
"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

from typing import Optional
class Solution:

    def __init__(self):
        self.seen = defaultdict(list)

    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:

        if not node:
            return node

        if node in self.seen:
            return self.seen[node]

        clone = Node(node.val,[])

        self.seen[node] = clone

        if node.neighbors:
            clone.neighbors = [self.cloneGraph(node) for node in node.neighbors]

        return clone

```

```python
"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

from typing import Optional
class Solution:

    def __init__(self):
        self.seen = {}

    def dfs(self,node:Optional['Node']) -> Optional['Node']:

        if not node:
            return

        if node in self.seen:
            return self.seen[node]

        clone = Node(node.val)
        self.seen[node] = clone

        for n in node.neighbors:
            clone.neighbors.append(self.dfs(n))

        return clone     

    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:

        return self.dfs(node)
        

        
```

## Optimal Solutions

---

### Problem Description

Given a reference of a node in a connected undirected graph, return a deep copy (clone) of the graph. Each node in the graph contains a value (`int`) and a list (`List[Node]`) of its neighbors.

### Example

```python
Input: adjList = [[2,4],[1,3],[2,4],[1,3]]
Output: [[2,4],[1,3],[2,4],[1,3]]
Explanation: There are 4 nodes in the graph.
             1: 2, 4
             2: 1, 3
             3: 2, 4
             4: 1, 3

```

### Optimal Solution and Explanation

To solve this problem, we can use both BFS and DFS approaches to traverse the graph and create a deep copy of it.

### Steps:

1. **BFS (Breadth-First Search)**:
    - Use a queue to traverse the graph level by level.
    - Use a dictionary to map original nodes to their clones.
    - For each node, clone it and its neighbors.
2. **DFS (Depth-First Search)**:
    - Use a stack (iterative) or recursion (recursive) to traverse the graph.
    - Use a dictionary to map original nodes to their clones.
    - For each node, clone it and its neighbors recursively.

### Python Code for BFS

Here's the Python code to achieve this using BFS:

```python
class Node:
    def __init__(self, val=0, neighbors=None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []

from collections import deque

class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        if not node:
            return None

        # Dictionary to save the cloned nodes
        clones = {node: Node(node.val, [])}

        # Initialize the BFS queue
        queue = deque([node])

        while queue:
            curr = queue.popleft()

            for neighbor in curr.neighbors:
                if neighbor not in clones:
                    # Clone the neighbor
                    clones[neighbor] = Node(neighbor.val, [])
                    # Add the neighbor to the queue
                    queue.append(neighbor)
                # Append the cloned neighbor to the current node's neighbors
                clones[curr].neighbors.append(clones[neighbor])

        return clones[node]

# Example usage
# Creating a simple graph:
# 1 -- 2
# |    |
# 4 -- 3
node1 = Node(1)
node2 = Node(2)
node3 = Node(3)
node4 = Node(4)
node1.neighbors = [node2, node4]
node2.neighbors = [node1, node3]
node3.neighbors = [node2, node4]
node4.neighbors = [node1, node3]

solution = Solution()
cloned_graph = solution.cloneGraph(node1)

```

### Python Code for DFS

Here's the Python code to achieve this using DFS:

### Iterative DFS

```python
class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        if not node:
            return None

        # Dictionary to save the cloned nodes
        clones = {node: Node(node.val, [])}

        # Initialize the DFS stack
        stack = [node]

        while stack:
            curr = stack.pop()

            for neighbor in curr.neighbors:
                if neighbor not in clones:
                    # Clone the neighbor
                    clones[neighbor] = Node(neighbor.val, [])
                    # Add the neighbor to the stack
                    stack.append(neighbor)
                # Append the cloned neighbor to the current node's neighbors
                clones[curr].neighbors.append(clones[neighbor])

        return clones[node]

```

### Recursive DFS

```python
class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        def dfs(node, clones):
            if node in clones:
                return clones[node]

            # Clone the node
            clone = Node(node.val, [])
            clones[node] = clone

            for neighbor in node.neighbors:
                clone.neighbors.append(dfs(neighbor, clones))

            return clone

        if not node:
            return None

        clones = {}
        return dfs(node, clones)

```

### Explanation

1. **BFS Approach**:
    - Use a queue to traverse the graph level by level.
    - Use a dictionary `clones` to map original nodes to their clones.
    - For each node, clone it and its neighbors.
    - Add each unvisited neighbor to the queue for future processing.
2. **DFS Approach**:
    - Use a stack for iterative DFS or recursion for recursive DFS to traverse the graph.
    - Use a dictionary `clones` to map original nodes to their clones.
    - For each node, clone it and its neighbors recursively.

### Time Complexity Analysis

- **Time Complexity**: `O(V + E)`, where `V` is the number of vertices (nodes) and `E` is the number of edges (connections) in the graph.
    - Each node and edge is processed once.

### Space Complexity Analysis

- **Space Complexity**: `O(V)`
    - Additional space is used for the dictionary and the queue/stack used in BFS/DFS.

Both BFS and DFS approaches efficiently clone a graph by leveraging a dictionary to keep track of cloned nodes and ensure each node is processed once.

## Notes

---

https://www.hellointerview.com/learn/code/graphs/copy-graph

## Related Videos

---

[https://www.youtube.com/watch?v=mQeF6bN8hMk&pp=ygULY2xvbmUgZ3JhcGg%3D](https://www.youtube.com/watch?v=mQeF6bN8hMk&pp=ygULY2xvbmUgZ3JhcGg%3D)