# Find Center of Star Graph

Problem: 1791
Official Difficulty: easy
Feels Like : easy
My Understanding: Fully Understand
Topic: graph
Link: https://leetcode.com/problems/find-center-of-star-graph/
Completed On : March 5, 2024
Last Review: March 5, 2024
Days Since Review: 5

## Problem

---

There is an undirected **star** graph consisting of `n` nodes labeled from `1` to `n`. A star graph is a graph where there is one **center** node and **exactly** `n - 1` edges that connect the center node with every other node.

You are given a 2D integer array `edges` where each `edges[i] = [ui, vi]` indicates that there is an edge between the nodes `ui` and `vi`. Return the center of the given star graph.

**Example 1:**

![https://assets.leetcode.com/uploads/2021/02/24/star_graph.png](https://assets.leetcode.com/uploads/2021/02/24/star_graph.png)

```
Input: edges = [[1,2],[2,3],[4,2]]
Output: 2
Explanation: As shown in the figure above, node 2 is connected to every other node, so 2 is the center.
```

**Example 2:**

```
Input: edges = [[1,2],[5,1],[1,3],[1,4]]
Output: 1
```

**Constraints:**

- `3 <= n <= 105`
- `edges.length == n - 1`
- `edges[i].length == 2`
- `1 <= ui, vi <= n`
- `ui != vi`
- The given `edges` represent a valid star graph.

## My Solutions

---

```python
class Solution:
    def findCenter(self, edges: List[List[int]]) -> int:

        first = edges[0]
        second = edges[1]
        count = Counter(first + second)

        for element in count : 

            if count[element] > 1 : 

                return element
  
```

```python

```

## Optimal Solutions

---

## Notes

---

 

## Related Videos

---

[https://www.notion.so](https://www.notion.so)