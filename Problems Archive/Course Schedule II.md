# Course Schedule II

Problem: 210
Official Difficulty: medium
Feels Like : medium
My Understanding: Mostly Understand
Topic: Breadth-First Search(BFS), Depth-First Search (DFS), Topological Sort, graph
Link: https://leetcode.com/problems/course-schedule-ii/description/
Completed On : September 4, 2024
Last Review: September 4, 2024
Days Since Review: 0

## Problem

---

There are a total of `numCourses` courses you have to take, labeled from `0` to `numCourses - 1`. You are given an array `prerequisites` where `prerequisites[i] = [ai, bi]` indicates that you **must** take course `bi` first if you want to take course `ai`.

- For example, the pair `[0, 1]`, indicates that to take course `0` you have to first take course `1`.

Return *the ordering of courses you should take to finish all courses*. If there are many valid answers, return **any** of them. If it is impossible to finish all courses, return **an empty array**.

**Example 1:**

```
Input: numCourses = 2, prerequisites = [[1,0]]
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].
```

**Example 2:**

```
Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
Output: [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].
```

**Example 3:**

```
Input: numCourses = 1, prerequisites = []
Output: [0]
```

**Constraints:**

- `1 <= numCourses <= 2000`
- `0 <= prerequisites.length <= numCourses * (numCourses - 1)`
- `prerequisites[i].length == 2`
- `0 <= ai, bi < numCourses`
- `ai != bi`
- All the pairs `[ai, bi]` are **distinct**.

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
            return True

        if node in self.visited:
            return True

        self.curstack.add(node)

        for neighbor in graph[node]:
            if neighbor not in self.curstack:
                self.dfs(graph,neighbor)
            else:
                return True

        self.curstack.remove(node)
        self.visited.add(node)

        self.order.append(node)

    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:

        if not prerequisites:
            return [course for course in range(numCourses)]

        graph = defaultdict(list)

        for course , prereq in prerequisites: 
            graph[prereq].append(course)

        for i in range(numCourses):
            if i not in self.visited:
                cycle = self.dfs(graph,i)
                if cycle:
                    return []

        if len(self.order) < numCourses:
            return []

        return self.order[::-1]
        
```

```python

```

## Optimal Solutions

---

### Course Schedule II

In the "Course Schedule II" problem, you are asked to return a valid ordering of courses you should take to finish all courses, given a number of courses and a list of prerequisites. If it is impossible to finish all courses (due to a cycle), return an empty list.

### Approach: Topological Sort

To solve this problem, we need to perform **topological sorting** on the courses, represented as nodes in a directed graph. This can be done using either **DFS** (Depth-First Search) or **Kahn’s Algorithm** (BFS). Here, I'll provide the solution using both methods.

---

### Solution 1: Kahn's Algorithm (BFS) Approach

### Steps:

1. **Build the Graph**:
    - Create an adjacency list to represent the graph where each course is a node, and a directed edge from course `b` to course `a` means you must complete course `b` before course `a`.
2. **Compute Indegree**:
    - Maintain an array `indegree[]` where `indegree[i]` represents the number of prerequisites for course `i`.
3. **Initialize Queue**:
    - Add all nodes (courses) with no prerequisites (`indegree[i] == 0`) to a queue. These are the starting points.
4. **BFS Traversal**:
    - Process each course in the queue, adding it to the result list (the order of courses).
    - For each course processed, reduce the indegree of its neighbors. If any neighbor’s indegree becomes zero, add it to the queue.
5. **Cycle Detection**:
    - If the number of processed courses is less than the total number of courses, there is a cycle, and it's impossible to finish all courses.

### Python Code (Kahn's Algorithm):

```python
from collections import deque, defaultdict
from typing import List

class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        # Step 1: Initialize adjacency list and indegree array
        adj = defaultdict(list)
        indegree = [0] * numCourses

        # Step 2: Populate adjacency list and indegree array
        for course, prereq in prerequisites:
            adj[prereq].append(course)
            indegree[course] += 1

        # Step 3: Initialize the queue with nodes that have indegree 0
        queue = deque([i for i in range(numCourses) if indegree[i] == 0])
        order = []

        # Step 4: Process the nodes in the queue (BFS)
        while queue:
            node = queue.popleft()
            order.append(node)

            # For each neighbor, reduce indegree by 1
            for neighbor in adj[node]:
                indegree[neighbor] -= 1
                if indegree[neighbor] == 0:
                    queue.append(neighbor)

        # Step 5: Check if a valid ordering exists (i.e., no cycle)
        if len(order) == numCourses:
            return order
        else:
            return []  # Cycle detected, return an empty list

# Example usage
sol = Solution()
print(sol.findOrder(4, [[1, 0], [2, 0], [3, 1], [3, 2]]))  # Output: [0, 1, 2, 3]
print(sol.findOrder(2, [[1, 0], [0, 1]]))  # Output: [] (cycle detected)

```

### Explanation:

1. **Building the Graph**:
    - For each prerequisite pair `[a, b]`, we add an edge from `b` to `a` in the graph and increment the `indegree` of `a`.
2. **BFS with Kahn's Algorithm**:
    - We process all nodes (courses) with `indegree == 0` and reduce the indegree of their neighbors. If a neighbor's indegree becomes zero, it is added to the queue, ensuring we respect dependencies.
3. **Cycle Detection**:
    - If after processing all nodes the number of nodes processed is less than the total number of courses, we know there's a cycle, and we return an empty list.

---

### Solution 2: DFS Approach (Using Postorder Traversal)

In the DFS approach, we perform a **postorder traversal** where we recursively visit all the descendants of a node (course) before marking the node itself as visited. This ensures that each course appears after all its prerequisites in the result list.

### Steps:

1. **Build the Graph**:
    - Same as before: create an adjacency list to represent the graph.
2. **Perform DFS**:
    - Use a `visited` array to track the state of each node:
        - `0` means unvisited.
        - `1` means visiting (i.e., currently in the recursion stack, indicating a potential cycle).
        - `2` means fully visited.
    - If a cycle is detected, return an empty list.
3. **Cycle Detection**:
    - If any node is revisited while it’s in the recursion stack (i.e., while `visited[node] == 1`), a cycle is detected.
4. **Topological Sort**:
    - The topological sort is formed by pushing nodes onto a stack after all their neighbors have been processed.

### Python Code (DFS Approach):

```python
from typing import List
from collections import defaultdict

class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        adj = defaultdict(list)
        for course, prereq in prerequisites:
            adj[prereq].append(course)

        visited = [0] * numCourses  # 0 = unvisited, 1 = visiting, 2 = fully visited
        order = []

        def dfs(node):
            if visited[node] == 1:  # Cycle detected
                return False
            if visited[node] == 2:  # Already processed
                return True

            visited[node] = 1  # Mark as visiting
            for neighbor in adj[node]:
                if not dfs(neighbor):
                    return False
            visited[node] = 2  # Mark as fully visited
            order.append(node)  # Add to the order in postorder

            return True

        for course in range(numCourses):
            if visited[course] == 0:
                if not dfs(course):
                    return []  # Cycle detected

        return order[::-1]  # Reverse the order to get the correct topological sort

# Example usage
sol = Solution()
print(sol.findOrder(4, [[1, 0], [2, 0], [3, 1], [3, 2]]))  # Output: [0, 2, 1, 3]
print(sol.findOrder(2, [[1, 0], [0, 1]]))  # Output: [] (cycle detected)

```

### Explanation:

1. **DFS with Postorder Traversal**:
    - We recursively visit all the neighbors of a node before adding the node to the result list.
2. **Cycle Detection**:
    - If we encounter a node that is currently being visited (`visited[node] == 1`), a cycle is detected, and we return an empty list.
3. **Topological Sort**:
    - The result list is constructed in reverse postorder, so we reverse it before returning the result.

---

### Complexity Analysis

For both BFS (Kahn's algorithm) and DFS approaches:

- **Time Complexity**: `O(V + E)`, where `V` is the number of courses (nodes), and `E` is the number of prerequisites (edges). We process each node and edge once.
- **Space Complexity**: `O(V + E)` for the adjacency list and the `visited`/`indegree` arrays.

Both approaches work efficiently and provide the correct topological order of courses (if possible), or return an empty list if a cycle is detected.

## Notes

---

 

## Related Videos

---

[https://www.youtube.com/watch?v=Akt3glAwyfY&pp=ygUadG9wb2xvZ2ljYWwgc29ydCBhbGdvcml0aG0%3D](https://www.youtube.com/watch?v=Akt3glAwyfY&pp=ygUadG9wb2xvZ2ljYWwgc29ydCBhbGdvcml0aG0%3D)