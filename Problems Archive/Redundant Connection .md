# Redundant Connection

Problem: 684
Official Difficulty: medium
Feels Like : medium
My Understanding: Mostly Understand
Topic: Breadth-First Search(BFS), Depth-First Search (DFS), graph, union find
Link: https://leetcode.com/problems/redundant-connection/description/?envType=problem-list-v2&envId=m748i2u3
Completed On : September 9, 2024
Last Review: September 9, 2024
Days Since Review: 7

## Problem

---

In this problem, a tree is an **undirected graph** that is connected and has no cycles.

You are given a graph that started as a tree with `n` nodes labeled from `1` to `n`, with one additional edge added. The added edge has two **different** vertices chosen from `1` to `n`, and was not an edge that already existed. The graph is represented as an array `edges` of length `n` where `edges[i] = [ai, bi]` indicates that there is an edge between nodes `ai` and `bi` in the graph.

Return *an edge that can be removed so that the resulting graph is a tree of* `n` *nodes*. If there are multiple answers, return the answer that occurs last in the input.

**Example 1:**

![https://assets.leetcode.com/uploads/2021/05/02/reduntant1-1-graph.jpg](https://assets.leetcode.com/uploads/2021/05/02/reduntant1-1-graph.jpg)

```
Input: edges = [[1,2],[1,3],[2,3]]
Output: [2,3]

```

**Example 2:**

![https://assets.leetcode.com/uploads/2021/05/02/reduntant1-2-graph.jpg](https://assets.leetcode.com/uploads/2021/05/02/reduntant1-2-graph.jpg)

```
Input: edges = [[1,2],[2,3],[3,4],[1,4],[1,5]]
Output: [1,4]

```

**Constraints:**

- `n == edges.length`
- `3 <= n <= 1000`
- `edges[i].length == 2`
- `1 <= ai < bi <= edges.length`
- `ai != bi`
- There are no repeated edges.
- The given graph is connected.

## My Solutions

---

```python
class UnionFind:
    def __init__(self, size: int):
        self.parent = [i for i in range(size + 1)]  # Since nodes are 1-indexed
        self.rank = [1] * (size + 1)

    def find(self, x: int) -> int:
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def union(self, x: int, y: int) -> bool:
        rootX = self.find(x)
        rootY = self.find(y)

        if rootX == rootY:
            return False 

        if self.rank[rootX] > self.rank[rootY]:
            self.parent[rootY] = rootX
            self.rank[rootX] += self.rank[rootY]
        elif self.rank[rootX] < self.rank[rootY]:
            self.parent[rootX] = rootY
            self.rank[rootY] += self.rank[rootX]
        else:
            self.parent[rootY] = rootX
            self.rank[rootX] += 1

        return True

class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        uf = UnionFind(len(edges))

        for u, v in edges:
            if not uf.union(u, v):
                return [u, v]

        return []  

```

```python

```

## Optimal Solutions

---

## Notes

---

 

## Related Videos

---

[https://youtu.be/FXWRE67PLL0](https://youtu.be/FXWRE67PLL0)