# Most Stones Removed With Same Row or Column

Problem: 947
Official Difficulty: medium
Feels Like : medium
My Understanding: Mostly Understand
Topic: Depth-First Search (DFS), graph, hash table, union find
Link: https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/description/
Completed On : August 29, 2024
Last Review: August 29, 2024
Days Since Review: 3

## Problem

---

On a 2D plane, we place `n` stones at some integer coordinate points. Each coordinate point may have at most one stone.

A stone can be removed if it shares either **the same row or the same column** as another stone that has not been removed.

Given an array `stones` of length `n` where `stones[i] = [xi, yi]` represents the location of the `ith` stone, return *the largest possible number of stones that can be removed*.

**Example 1:**

```
Input: stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
Output: 5
Explanation: One way to remove 5 stones is as follows:
1. Remove stone [2,2] because it shares the same row as [2,1].
2. Remove stone [2,1] because it shares the same column as [0,1].
3. Remove stone [1,2] because it shares the same row as [1,0].
4. Remove stone [1,0] because it shares the same column as [0,0].
5. Remove stone [0,1] because it shares the same row as [0,0].
Stone [0,0] cannot be removed since it does not share a row/column with another stone still on the plane.
```

**Example 2:**

```
Input: stones = [[0,0],[0,2],[1,1],[2,0],[2,2]]
Output: 3
Explanation: One way to make 3 moves is as follows:
1. Remove stone [2,2] because it shares the same row as [2,0].
2. Remove stone [2,0] because it shares the same column as [0,0].
3. Remove stone [0,2] because it shares the same row as [0,0].
Stones [0,0] and [1,1] cannot be removed since they do not share a row/column with another stone still on the plane.
```

**Example 3:**

```
Input: stones = [[0,0]]
Output: 0
Explanation: [0,0] is the only stone on the plane, so you cannot remove it.
```

**Constraints:**

- `1 <= stones.length <= 1000`
- `0 <= xi, yi <= 104`
- No two stones are at the same coordinate point.

## My Solutions

---

```python
class Solution:

    def __init__(self):
        self.visited = set()

    def dfs(self,node:Tuple[int,int],adj_list:defaultdict) -> None:

        self.visited.add(node)

        for neighbor in adj_list[node]:
            if neighbor not in self.visited:
                self.dfs(neighbor,adj_list)

    def removeStones(self, stones: List[List[int]]) -> int:

        adj_list = defaultdict(list)
        
        rows = defaultdict(list)
        cols = defaultdict(list)
        
        for r, c in stones:
            rows[r].append((r, c))
            cols[c].append((r, c))
        
        for r, c in stones:
            for neighbor in rows[r]:
                if neighbor != (r, c):  
                    adj_list[(r, c)].append(neighbor)
            for neighbor in cols[c]:
                if neighbor != (r, c):  
                    adj_list[(r, c)].append(neighbor)

        total_graphs = 0

        for x,y in stones:
            
            if (x,y) not in self.visited:
                self.dfs((x,y),adj_list)
                total_graphs += 1

        return len(stones) - total_graphs
```

```python

```

## Optimal Solutions

---

### Approach

The problem can be visualized as finding connected components in a graph. Each stone is a node, and there is an edge between two stones if they share the same row or the same column. The goal is to find the size of each connected component and determine how many stones can be removed from each.

If a connected component has `k` stones, then `k - 1` stones can be removed, leaving one stone behind.

### Union-Find (Disjoint Set Union) Approach

We can solve the problem using a Union-Find (also known as Disjoint Set Union) data structure. The key steps are:

1. **Union Operation**:
    - Union stones if they are in the same row or column.
2. **Counting Connected Components**:
    - Use the Union-Find data structure to find the number of unique connected components.
3. **Calculate Removable Stones**:
    - If there are `k` stones in a connected component, `k - 1` stones can be removed.

### Python Implementation

```python
class UnionFind:
    def __init__(self):
        self.parent = {}
        self.rank = {}
        self.count = 0

    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def union(self, x, y):
        rootX = self.find(x)
        rootY = self.find(y)

        if rootX != rootY:
            if self.rank[rootX] > self.rank[rootY]:
                self.parent[rootY] = rootX
            elif self.rank[rootX] < self.rank[rootY]:
                self.parent[rootX] = rootY
            else:
                self.parent[rootY] = rootX
                self.rank[rootX] += 1
            self.count -= 1

    def add(self, x):
        if x not in self.parent:
            self.parent[x] = x
            self.rank[x] = 0
            self.count += 1

    def get_count(self):
        return self.count

class Solution:
    def removeStones(self, stones: List[List[int]]) -> int:
        uf = UnionFind()

        for x, y in stones:
            # Treat row and column indices separately by using row and column offsets
            uf.add(x)
            uf.add(~y)  # Use ~y to distinguish between rows and columns
            uf.union(x, ~y)

        return len(stones) - uf.get_count()

# Example usage
sol = Solution()
print(sol.removeStones([[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]))  # Output: 5

```

### Explanation

1. **Union-Find Initialization**:
    - We initialize the Union-Find structure with an empty parent and rank dictionary.
2. **Union Operation**:
    - For each stone, we union the row index with a unique column index (using `~y` as a trick to distinguish between row and column indices).
    - This union operation helps connect all stones that share either the same row or column.
3. **Counting Components**:
    - The `get_count()` method returns the number of unique connected components in the Union-Find structure. Each connected component represents a set of stones that are interconnected by row or column.
4. **Calculate Removable Stones**:
    - The number of stones that can be removed is the total number of stones minus the number of connected components.

### Complexity Analysis

- **Time Complexity**: `O(n * α(n))`, where `n` is the number of stones and `α(n)` is the inverse Ackermann function (which grows very slowly), making it nearly constant in practice.
- **Space Complexity**: `O(n)`, for storing the parent and rank of each stone in the Union-Find structure.

This approach efficiently computes the maximum number of stones that can be removed using the Union-Find data structure.

## Notes

---

 

## Related Videos

---

[https://www.youtube.com/watch?v=VIsMSzJgl58](https://www.youtube.com/watch?v=VIsMSzJgl58)