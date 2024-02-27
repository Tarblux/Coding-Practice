# Cheapest Flights Within K Stops

Problem: 787
Official Difficulty: medium
My Understanding: I Have No Idea
Feels Like : hard
Topic: Breadth-First Search(BFS), Depth-First Search (DFS), Heap, dynamic programming, graph, shortest path
Link: https://leetcode.com/problems/cheapest-flights-within-k-stops/description/?envType=daily-question&envId=2024-02-23
Completed On : February 24, 2024
Last Review: February 24, 2024
Days Since Review: 2

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

```

## Optimal Solutions

---

## Notes

---

 

## Related Videos

---

[https://www.youtube.com/watch?v=5eIK3zUdYmE&pp=ygUfY2hlYXBlc3QgZmxpZ2h0cyB3aXRoaW4gayBzdG9wcw%3D%3D](https://www.youtube.com/watch?v=5eIK3zUdYmE&pp=ygUfY2hlYXBlc3QgZmxpZ2h0cyB3aXRoaW4gayBzdG9wcw%3D%3D)