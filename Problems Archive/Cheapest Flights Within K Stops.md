# Cheapest Flights Within K Stops

Problem: 787
Official Difficulty: medium
Feels Like : hard
My Understanding: I Have No Idea
Topic: Breadth-First Search(BFS), Depth-First Search (DFS), Heap(Priority Queue), dynamic programming, graph, shortest path
Link: https://leetcode.com/problems/cheapest-flights-within-k-stops/description/?envType=daily-question&envId=2024-02-23
Completed On : February 24, 2024
Last Review: September 12, 2024
Days Since Review: 5

## Problem

---

There are `n` cities connected by some number of flights. You are given an array `flights` where `flights[i] = [fromi, toi, pricei]` indicates that there is a flight from city `fromi` to city `toi` with cost `pricei`.

You are also given three integers `src`, `dst`, and `k`, return ***the cheapest price** from* `src` *to* `dst` *with at most* `k` *stops.* If there is no such route, return **`-1`.

**Example 1:**

![https://assets.leetcode.com/uploads/2022/03/18/cheapest-flights-within-k-stops-3drawio.png](https://assets.leetcode.com/uploads/2022/03/18/cheapest-flights-within-k-stops-3drawio.png)

```
Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
Output: 700
Explanation:
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 3 is marked in red and has cost 100 + 600 = 700.
Note that the path through cities [0,1,2,3] is cheaper but is invalid because it uses 2 stops.

```

**Example 2:**

![https://assets.leetcode.com/uploads/2022/03/18/cheapest-flights-within-k-stops-1drawio.png](https://assets.leetcode.com/uploads/2022/03/18/cheapest-flights-within-k-stops-1drawio.png)

```
Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1
Output: 200
Explanation:
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 2 is marked in red and has cost 100 + 100 = 200.

```

**Example 3:**

![https://assets.leetcode.com/uploads/2022/03/18/cheapest-flights-within-k-stops-2drawio.png](https://assets.leetcode.com/uploads/2022/03/18/cheapest-flights-within-k-stops-2drawio.png)

```
Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 0
Output: 500
Explanation:
The graph is shown above.
The optimal path with no stops from city 0 to 2 is marked in red and has cost 500.

```

**Constraints:**

- `1 <= n <= 100`
- `0 <= flights.length <= (n * (n - 1) / 2)`
- `flights[i].length == 3`
- `0 <= fromi, toi < n`
- `fromi != toi`
- `1 <= pricei <= 104`
- There will not be any multiple flights between two cities.
- `0 <= src, dst, k < n`
- `src != dst`

## My Solutions

---

```python
class Database:
    def __init__(self, n):
        self.prices = [[ -1 for _ in range(n)] for _ in range(n)]
        self.airports = {}

class Node:
    def __init__(self, cur):
        self.cur = cur
        self.next = []
        self.price = -1

    def addConnection(self, nextStop):
        self.next.append(nextStop)
        

    def str(self):
        connections = [f"  Next Stops: {self.next}", f"  Price: {self.price}"]
        return f"Node {self.cur}:\n" + "\n".join(connections)

class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:

        data = Database(n)

        for i in range(n):
            new_airport = Node(i)
            data.airports[i] = new_airport

        for fr, to, price in flights:

            data.airports[fr].addConnection(to)

            data.prices[fr][to] = price

        visited = set()
        def iterate(airport, fr, total_price, level):    
            if (level - 1) > k: return 
            visited.add(airport.cur)

            price = data.prices[fr][airport.cur]
            if price == -1:
                price = 0

            if airport.price == -1:
                total = total_price + price
            else:
                total = min(total_price + price, airport.price)
            
            airport.price = total

            print('Level: ' + str(level))
            print(airport)
                
            ids = airport.next
            for i in ids:
                child = data.airports[i]
                iterate(child, airport.cur, total, level + 1)
        

        airport = data.airports[src]
        iterate(airport, src, 0, 0)

        return data.airports[dst].price
```

```python
from typing import List
from collections import defaultdict

class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:

        distances = defaultdict(lambda: float('inf'))
        distances[src] = 0

        for i in range(k + 1):
            updated = False
            new_distances = distances.copy()

            for u, v, w in flights:
                if distances[u] != float('inf') and distances[u] + w < new_distances[v]:
                    new_distances[v] = distances[u] + w
                    updated = True

            distances = new_distances

            if not updated:
                break

        return distances[dst] if distances[dst] != float('inf') else -1

```

## Optimal Solutions

---

The problem **Cheapest Flights Within K Stops** asks us to find the cheapest price to fly from a given source city to a destination city with at most `K` stops, considering a set of flights between cities with given costs.

### Problem Breakdown:

- We are given:
    - `n`: The number of cities (nodes).
    - `flights`: A list of flights where each flight is represented as `(u, v, w)`, meaning there is a flight from city `u` to city `v` with cost `w`.
    - `src`: The starting city.
    - `dst`: The destination city.
    - `k`: The maximum number of stops.

The goal is to find the cheapest flight path from `src` to `dst` with at most `k` stops. If there is no such path, return `-1`.

### Approach: BFS / Dijkstra's with a Priority Queue

A good way to approach this problem is by using a **modified Dijkstra's algorithm** or a **Breadth-First Search (BFS)** approach, where the key difference is that we also track the number of stops made. The idea is to explore each possible flight while keeping track of the current cost and the number of stops made, and we maintain the cheapest path with the least stops.

### Steps:

1. **Use a Priority Queue (Min-Heap)**:
    - The priority queue will store tuples of the form `(current_cost, current_city, stops)`, where:
        - `current_cost` is the total cost to reach `current_city`.
        - `stops` is the number of stops made to reach `current_city`.
2. **Graph Representation**:
    - Use an adjacency list to represent the flights.
3. **Early Termination**:
    - If we find the destination city within `k+1` stops, return the cost immediately.
4. **Relaxation of Edges**:
    - For each city, explore all its neighbors and update the cost if the path through the current city offers a cheaper price and the number of stops is within the allowed limit.

### Python Code Implementation:

```python
import heapq
from collections import defaultdict
from typing import List

class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        # Step 1: Build the adjacency list for the graph
        graph = defaultdict(list)
        for u, v, w in flights:
            graph[u].append((v, w))

        # Step 2: Priority Queue (Min-Heap) to store (cost, city, stops)
        min_heap = [(0, src, 0)]  # (cost, current_city, stops)

        # Step 3: Distance dictionary to track the minimum cost with at most k stops
        distances = {(src, 0): 0}

        # Step 4: Explore cities with priority queue
        while min_heap:
            cost, city, stops = heapq.heappop(min_heap)

            # If we reach the destination city
            if city == dst:
                return cost

            # If we still have stops left (stops <= k)
            if stops <= k:
                # Explore neighbors
                for neighbor, price in graph[city]:
                    new_cost = cost + price

                    # Only push the neighbor if the number of stops is valid
                    if new_cost < distances.get((neighbor, stops + 1), float('inf')):
                        distances[(neighbor, stops + 1)] = new_cost
                        heapq.heappush(min_heap, (new_cost, neighbor, stops + 1))

        # If the destination is unreachable within k stops
        return -1

```

### Explanation:

1. **Graph Representation**:
    - The `graph` is built as an adjacency list, where `graph[u] = [(v, w)]` means there is a flight from city `u` to city `v` with cost `w`.
2. **Priority Queue**:
    - We initialize the priority queue with the tuple `(0, src, 0)`, representing the cost `0`, starting city `src`, and `0` stops.
    - We process each node by popping the smallest element (based on the cost) from the queue.
3. **Processing Neighbors**:
    - For each city, if the number of stops is less than or equal to `k`, we explore its neighbors and calculate the new cost for reaching the neighbor.
    - We push the neighbor into the priority queue if we find a cheaper path to that neighbor with the given number of stops.
4. **Early Exit**:
    - As soon as we reach the destination city, we return the current cost. This guarantees the minimum cost since we are using a priority queue (which always processes the smallest cost first).
5. **Stops Constraint**:
    - We ensure that the number of stops used to reach a city does not exceed `k` by checking it before pushing the city into the queue.

### Time Complexity:

- **Time Complexity**: `O((n + E) log n)`, where `n` is the number of cities, and `E` is the number of flights. The complexity is driven by the number of nodes processed and the heap operations.
- **Space Complexity**: `O(n + E)` for storing the graph, distances, and the priority queue.

### Example Usage:

```python
sol = Solution()
n = 4
flights = [[0, 1, 100], [1, 2, 100], [2, 0, 100], [1, 3, 600], [2, 3, 200]]
src = 0
dst = 3
k = 1
print(sol.findCheapestPrice(n, flights, src, dst, k))  # Output: 700

```

In this example, the cheapest flight path from city `0` to city `3` with at most `1` stop is `0 -> 1 -> 3`, with a cost of `700`.

## Notes

---

 

## Related Videos

---

[https://www.youtube.com/watch?v=5eIK3zUdYmE&pp=ygUfY2hlYXBlc3QgZmxpZ2h0cyB3aXRoaW4gayBzdG9wcw%3D%3D](https://www.youtube.com/watch?v=5eIK3zUdYmE&pp=ygUfY2hlYXBlc3QgZmxpZ2h0cyB3aXRoaW4gayBzdG9wcw%3D%3D)