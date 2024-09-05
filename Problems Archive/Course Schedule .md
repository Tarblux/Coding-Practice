# Course Schedule

Problem: 207
Official Difficulty: medium
Feels Like : medium
My Understanding: Mostly Understand
Topic: Breadth-First Search(BFS), Depth-First Search (DFS), Topological Sort, graph
Link: https://leetcode.com/problems/course-schedule/description/?envType=problem-list-v2&envId=m748i2u3
Completed On : September 4, 2024
Last Review: September 4, 2024
Days Since Review: 0

## Problem

---

There are a total of `numCourses` courses you have to take, labeled from `0` to `numCourses - 1`. You are given an array `prerequisites` where `prerequisites[i] = [ai, bi]` indicates that you **must** take course `bi` first if you want to take course `ai`.

- For example, the pair `[0, 1]`, indicates that to take course `0` you have to first take course `1`.

Return `true` if you can finish all courses. Otherwise, return `false`.

**Example 1:**

```
Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take.
To take course 1 you should have finished course 0. So it is possible.
```

**Example 2:**

```
Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take.
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
```

**Constraints:**

- `1 <= numCourses <= 2000`
- `0 <= prerequisites.length <= 5000`
- `prerequisites[i].length == 2`
- `0 <= ai, bi < numCourses`
- All the pairs prerequisites[i] are **unique**.

## My Solutions

---

```python
class Solution:

    def __init__(self):

        self.visited = set()
        self.curstack = set()
        self.order = []
        
    
    def dfs(self,graph,node):

        if node in self.curstack:
            return False

        if node in self.visited:
            return True

        self.curstack.add(node)

        for neighbor in graph[node]:
            if neighbor not in self.curstack:
                self.dfs(graph,neighbor)
            else:
                return False

        self.curstack.remove(node)
        self.visited.add(node)        

        # self.order.append(node)
        return True

    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:

        graph = defaultdict(list)
        
        for course, prereq in prerequisites:
            graph[prereq].append(course)

        for course in range(numCourses):
            if course not in self.visited:
                no_cycle = self.dfs(graph,course)
                if not no_cycle:
                    return False

        return True
```

```python

```

## Optimal Solutions

---

### Depth First Search (DFS)

### Intuition

We can use a Depth-First Search (DFS) traversal to detect cycles in a directed graph. In DFS, we use a recursive function to explore nodes as far as possible along each branch. Upon reaching the end of a branch, we backtrack to the previous node and continue exploring the next branches.

When we encounter an unvisited node, we take one of its neighbors (if it exists) as the next node on this branch. We recursively call the function to take the next node as the "starting node" and solve the subproblem.

A node remains in the DFS recursion stack until all of its branches (i.e., all nodes in its subtree) have been explored. Once we've examined all of a node's branches (visited all the nodes in its subtree), the node is removed from the DFS recursive stack.

If the graph has a cycle, there must be a back edge connecting a node to one of its ancestors while traversing nodes in the DFS manner.

### Cycle Detection

- If a neighboring node has not yet been visited, it cannot be an ancestor (it's a child node).
- If a neighboring node has been visited:
    - If it's an ancestor (i.e., there's a back edge), this means the node is still in the DFS recursive stack, indicating a cycle.
    - If it's visited but not in the recursion stack, it signifies that we've previously explored that node in a different branch, so it doesn't form a cycle in the current branch.

To detect cycles, we track both visited nodes (as in a typical DFS) and the nodes currently in the DFS recursion stack (to detect cycles). We use a boolean array of length `n` to track which nodes are in the recursion stack, allowing us to check for cycles in `O(1)` time.

### Algorithm

1. **Create the Adjacency List**:
    - Create an adjacency list `adj` where `adj[x]` contains all the nodes with an incoming edge from node `x`. Iterate over `prerequisites`, and for each prerequisite `[a, b]`, add an edge from `b` to `a`.
2. **Track Visited Nodes and Stack**:
    - Create two boolean arrays, `visit` and `instack`, each of size `n`.
        - `visit`: Keeps track of nodes that have been visited.
        - `instack`: Tracks nodes currently in the DFS stack, which helps in cycle detection.
3. **DFS Traversal**:
    - For each node, begin a DFS traversal. Implement the DFS method with the following steps:
        - If the node is already present in `instack`, a cycle is detected, and we return `True`.
        - If the node is already visited, return `False` (since we've already processed it without finding a cycle).
        - Mark the node as visited and set `instack[node] = True`.
        - Recursively call DFS for all neighbors. If any neighbor returns `True` (cycle detected), return `True`.
        - After processing all the neighbors, mark `instack[node] = False` (node is out of the stack) and return `False` (no cycle found).
4. **Return Result**:
    - If any DFS call returns `True` (cycle detected), return `False` (indicating it's impossible to finish all courses). Otherwise, return `True`.

This implementation uses DFS to detect cycles in the course dependency graph, and returns `True` if all courses can be completed (no cycles detected), or `False` if a cycle is found.

```python
class Solution:
    def dfs(self, node, adj, visit, inStack):
        # If the node is already in the stack, we have a cycle.
        if inStack[node]:
            return True
        if visit[node]:
            return False
        # Mark the current node as visited and part of current recursion stack.
        visit[node] = True
        inStack[node] = True
        for neighbor in adj[node]:
            if self.dfs(neighbor, adj, visit, inStack):
                return True
        # Remove the node from the stack.
        inStack[node] = False
        return False

    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        adj = [[] for _ in range(numCourses)]
        for prerequisite in prerequisites:
            adj[prerequisite[1]].append(prerequisite[0])

        visit = [False] * numCourses
        inStack = [False] * numCourses
        for i in range(numCourses):
            if self.dfs(i, adj, visit, inStack):
                return False
        return True
```

---

 

## Related Videos

---

[https://www.youtube.com/watch?v=cIBFEhD77b4&pp=ygUadG9wb2xvZ2ljYWwgc29ydCBhbGdvcml0aG0=](https://www.youtube.com/watch?v=cIBFEhD77b4&pp=ygUadG9wb2xvZ2ljYWwgc29ydCBhbGdvcml0aG0=)

[https://www.youtube.com/watch?v=eL-KzMXSXXI&t=707s&pp=ygUadG9wb2xvZ2ljYWwgc29ydCBhbGdvcml0aG0=](https://www.youtube.com/watch?v=eL-KzMXSXXI&t=707s&pp=ygUadG9wb2xvZ2ljYWwgc29ydCBhbGdvcml0aG0=)

[https://www.youtube.com/watch?v=EgI5nU9etnU&pp=ygUYY291cnNlIHNjaGVkdWxlIG5lZXRjb2Rl](https://www.youtube.com/watch?v=EgI5nU9etnU&pp=ygUYY291cnNlIHNjaGVkdWxlIG5lZXRjb2Rl)