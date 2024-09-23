# Network Delay Time

Problem: 743
Official Difficulty: medium
Feels Like : medium
My Understanding: Mostly Understand
Topic: Breadth-First Search(BFS), Depth-First Search (DFS), Heap(Priority Queue), graph, shortest path
Link: https://leetcode.com/problems/network-delay-time/description/?envType=problem-list-v2&envId=m3a0vf7e
Completed On : September 17, 2024
Last Review: September 17, 2024
Days Since Review: 6

## Problem

---

You are given a network of `n` nodes, labeled from `1` to `n`. You are also given `times`, a list of travel times as directed edges `times[i] = (ui, vi, wi)`, where `ui` is the source node, `vi` is the target node, and `wi` is the time it takes for a signal to travel from source to target.

We will send a signal from a given node `k`. Return *the **minimum** time it takes for all the* `n` *nodes to receive the signal*. If it is impossible for all the `n` nodes to receive the signal, return `-1`.

**Example 1:**

![https://assets.leetcode.com/uploads/2019/05/23/931_example_1.png](https://assets.leetcode.com/uploads/2019/05/23/931_example_1.png)

```
Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
Output: 2
```

**Example 2:**

```
Input: times = [[1,2,1]], n = 2, k = 1
Output: 1
```

**Example 3:**

```
Input: times = [[1,2,1]], n = 2, k = 2
Output: -1
```

**Constraints:**

- `1 <= k <= n <= 100`
- `1 <= times.length <= 6000`
- `times[i].length == 3`
- `1 <= ui, vi <= n`
- `ui != vi`
- `0 <= wi <= 100`
- All the pairs `(ui, vi)` are **unique**. (i.e., no multiple edges.)

## My Solutions

---

```python
class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        
        graph = defaultdict(list)
        distances = {node:float('inf') for node in range(1,n+1)}
        distances[k] = 0

        for u,v,w in times:
            graph[u].append((v,w))

        min_heap = [(0,k)]

        while min_heap:

            cur_dist , cur_node = heapq.heappop(min_heap)

            if cur_dist > distances[cur_node]:
                continue

            for n , w in graph[cur_node]:
                distance = cur_dist + w
                if distance < distances[n]:
                    distances[n] = distance
                    heapq.heappush(min_heap,(distance,n))

        max_dist = max(distances.values())

        return max_dist if max_dist != float('inf') else -1

            

```

```python

```

## Optimal Solutions

---

To solve the **Network Delay Time** problem, we need to determine how long it will take for a signal to reach all nodes in a network, given that the signal is sent from a starting node and travels through directed edges with specific time delays.

### Problem:

- We are given:
    - A list of directed edges `times`, where each element is `(u, v, w)` representing a signal traveling from node `u` to node `v` in `w` units of time.
    - `n`, the number of nodes in the network.
    - `k`, the starting node from where the signal is sent.
- We need to find the time it takes for the signal to reach all nodes. If it’s impossible to reach all nodes, return `1`.

### Approach:

The problem can be viewed as finding the shortest time to reach each node from the source node `k`, which is a typical **single-source shortest path** problem. Given that all the edge weights are positive, **Dijkstra's algorithm** is an ideal fit for solving this.

### Steps:

1. **Use a Priority Queue (Min-Heap)**:
    - We use a **min-heap (priority queue)** to always explore the node with the shortest current known time to ensure that we're processing nodes in increasing order of their distance from the source.
2. **Graph Representation**:
    - We represent the graph using an adjacency list where each node points to a list of its neighbors and the travel time to each neighbor.
3. **Track Visited Nodes**:
    - To avoid reprocessing nodes, we keep track of which nodes we have already visited.
4. **Return the Maximum Time**:
    - After processing all nodes, if some nodes are unreachable, return `1`. Otherwise, return the maximum time taken to reach any node.

### Python Code Implementation:

```python
import heapq
from collections import defaultdict
from typing import List

class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        # Step 1: Build the graph as an adjacency list
        graph = defaultdict(list)
        for u, v, w in times:
            graph[u].append((v, w))

        # Step 2: Min-heap to store (time, node), initialized with the source node k
        min_heap = [(0, k)]
        # Dictionary to keep track of the shortest time to reach each node
        distances = {i: float('inf') for i in range(1, n + 1)}
        distances[k] = 0

        # Step 3: Use Dijkstra's algorithm
        while min_heap:
            cur_time, node = heapq.heappop(min_heap)

            # If we have already processed this node with a shorter time, skip it
            if cur_time > distances[node]:
                continue

            # Explore neighbors
            for neighbor, travel_time in graph[node]:
                new_time = cur_time + travel_time

                # Only consider this new path if it's better
                if new_time < distances[neighbor]:
                    distances[neighbor] = new_time
                    heapq.heappush(min_heap, (new_time, neighbor))

        # Step 4: Get the maximum time to reach any node
        max_time = max(distances.values())

        # If any node is unreachable, return -1
        return max_time if max_time != float('inf') else -1
```

### Explanation:

1. **Graph Representation**:
    - The graph is built as an adjacency list where `graph[u]` contains a list of tuples `(v, w)`, representing that there is an edge from node `u` to node `v` with a time delay of `w`.
2. **Priority Queue**:
    - We initialize the priority queue with the source node `k` and a travel time of `0`. The priority queue stores tuples `(current_time, node)`, where `current_time` is the time taken to reach `node`.
    - We always pop the node with the smallest current time from the queue.
3. **Dijkstra's Algorithm**:
    - For each node popped from the queue, we explore its neighbors and calculate the new time to reach each neighbor.
    - If we find a shorter path to a neighbor, we update the shortest time to reach that neighbor and push it into the priority queue.
4. **Final Result**:
    - After processing all nodes, we take the maximum time to reach any node from the `distances` dictionary.
    - If any node remains unreachable (`float('inf')`), we return `1`. Otherwise, we return the maximum time.

### Time Complexity:

- **Time Complexity**: `O((V + E) log V)`, where `V` is the number of nodes (vertices) and `E` is the number of edges. The complexity comes from processing each node and its neighbors in the priority queue, with each heap operation taking `log V`.
- **Space Complexity**: `O(V + E)` for storing the graph and the distances.

### Example Usage:

```python
sol = Solution()
times = [[2, 1, 1], [2, 3, 1], [3, 4, 1]]
n = 4
k = 2
print(sol.networkDelayTime(times, n, k))  # Output: 2
```

In this example:

- The signal starts at node `2`.
- It takes `1` unit of time to reach node `1` and `1` unit of time to reach node `3`.
- From node `3`, it takes `1` more unit of time to reach node `4`.
- The signal reaches all nodes within `2` units of time, so the result is `2`.

## Notes

---

 

## Related Videos

---

[https://youtu.be/EaphyqKU4PQ](https://youtu.be/EaphyqKU4PQ)