# Advanced Graphs

Problem: 332
Official Difficulty: hard
Feels Like : Brain Damage
My Understanding: I Have No Idea
Topic: Depth-First Search (DFS), eulerian circuit, graph
Link: https://leetcode.com/problems/reconstruct-itinerary/description/?envType=problem-list-v2&envId=m3a0vf7e
Completed On : September 18, 2024
Last Review: September 18, 2024
Days Since Review: 5

## Problem

---

You are given a list of airline `tickets` where `tickets[i] = [fromi, toi]` represent the departure and the arrival airports of one flight. Reconstruct the itinerary in order and return it.

All of the tickets belong to a man who departs from `"JFK"`, thus, the itinerary must begin with `"JFK"`.
 If there are multiple valid itineraries, you should return the 
itinerary that has the smallest lexical order when read as a single 
string.

- For example, the itinerary `["JFK", "LGA"]` has a smaller lexical order than `["JFK", "LGB"]`.

You may assume all tickets form at least one valid itinerary. You must use all the tickets once and only once.

**Example 1:**

![https://assets.leetcode.com/uploads/2021/03/14/itinerary1-graph.jpg](https://assets.leetcode.com/uploads/2021/03/14/itinerary1-graph.jpg)

```
Input: tickets = [["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]
Output: ["JFK","MUC","LHR","SFO","SJC"]

```

**Example 2:**

![https://assets.leetcode.com/uploads/2021/03/14/itinerary2-graph.jpg](https://assets.leetcode.com/uploads/2021/03/14/itinerary2-graph.jpg)

```
Input: tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
Explanation: Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"] but it is larger in lexical order.

```

**Constraints:**

- `1 <= tickets.length <= 300`
- `tickets[i].length == 2`
- `fromi.length == 3`
- `toi.length == 3`
- `fromi` and `toi` consist of uppercase English letters.
- `fromi != toi`

## My Solutions

---

```python

```

From Neetcode x GPT

```python
from collections import defaultdict
from typing import List

class Solution:

    def __init__(self):
        self.output = []

    def dfs(self, src: str, graph: defaultdict):
        # While there are destinations left for the current source
        while graph[src]:
            # Pop the last destination (smallest lexicographically due to reverse sort)
            next_dest = graph[src].pop()
            # Recurse to explore the next destination
            self.dfs(next_dest, graph)
        # Append the source after visiting all of its destinations
        self.output.append(src)

    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        graph = defaultdict(list)

        # Build the graph by appending the destinations for each source
        for src, dst in tickets:
            graph[src].append(dst)

        # Sort each source's destinations in reverse lexicographical order
        # so we can pop from the end (which gives us the smallest lexicographical order)
        for src in graph:
            graph[src].sort(reverse=True)

        # Start DFS from 'JFK'
        self.dfs('JFK', graph)

        # Since we are appending in post-order (after visiting all neighbors),
        # we need to reverse the output to get the correct itinerary.
        return self.output[::-1]
```

## Optimal Solutions

---

## Notes

---

 

## Related Videos

---

[https://youtu.be/ZyB_gQ8vqGA](https://youtu.be/ZyB_gQ8vqGA)