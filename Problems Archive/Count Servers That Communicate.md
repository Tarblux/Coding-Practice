# Count Servers That Communicate

Problem: 1267
Official Difficulty: medium
Feels Like : easy
My Understanding: Fully Understand
Topic: Breadth-First Search(BFS), Depth-First Search (DFS), array
Link: https://leetcode.com/problems/count-servers-that-communicate/description/?envType=daily-question&envId=2025-01-23
Completed On : January 22, 2025
Last Review: January 22, 2025
Days Since Review: 39
Neetcode: No

## Problem

---

You are given a map of a server center, represented as a `m * n` integer matrix `grid`, where 1 means that on that cell there is a server and 0 means that it is no server. Two servers are said to communicate if they are on the same row or on the same column.

Return the number of servers that communicate with any other server.

**Example 1:**

![](https://assets.leetcode.com/uploads/2019/11/14/untitled-diagram-6.jpg)

```
Input: grid = [[1,0],[0,1]]
Output: 0
Explanation: No servers can communicate with others.
```

**Example 2:**

![](https://assets.leetcode.com/uploads/2019/11/13/untitled-diagram-4.jpg)

```
Input: grid = [[1,0],[1,1]]
Output: 3
Explanation: All three servers can communicate with at least one other server.

```

**Example 3:**

![](https://assets.leetcode.com/uploads/2019/11/14/untitled-diagram-1-3.jpg)

```
Input: grid = [[1,1,0,0],[0,0,1,0],[0,0,1,0],[0,0,0,1]]
Output: 4
Explanation: The two servers in the first row can communicate with each other. The two servers in the third column can communicate with each other. The server at right bottom corner can't communicate with any other server.

```

**Constraints:**

- `m == grid.length`
- `n == grid[i].length`
- `1 <= m <= 250`
- `1 <= n <= 250`
- `grid[i][j] == 0 or 1`

## My Solutions

---

```python
class Solution:
    def countServers(self, grid: List[List[int]]) -> int:

        rows = defaultdict(int)
        cols = defaultdict(int)

        total_servers = 0
        isolated = 0

        for r in range(len(grid)):
            for c in range(len(grid[0])):

                if grid[r][c] == 1:

                    total_servers += 1

                    rows[r] += 1
                    cols[c] += 1

        for r in range(len(grid)):
            for c in range(len(grid[0])):

                if grid[r][c] == 1 and rows[r] == 1 and cols[c] == 1:
                    isolated += 1

        return total_servers - isolated
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