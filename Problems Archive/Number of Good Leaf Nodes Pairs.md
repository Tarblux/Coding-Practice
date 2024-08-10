# Number of Good Leaf Nodes Pairs

Problem: 1530
Official Difficulty: medium
Feels Like : Brain Damage
My Understanding: I Have No Idea
Topic: Depth-First Search (DFS), binary tree, tree
Link: https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/description/
Completed On : August 9, 2024
Last Review: August 9, 2024
Days Since Review: 0

## Problem

---

You are given the `root` of a binary tree and an integer `distance`. A pair of two different **leaf** nodes of a binary tree is said to be good if the length of **the shortest path** between them is less than or equal to `distance`.

Return *the number of good leaf node pairs* in the tree.

**Example 1:**

![https://assets.leetcode.com/uploads/2020/07/09/e1.jpg](https://assets.leetcode.com/uploads/2020/07/09/e1.jpg)

```
Input: root = [1,2,3,null,4], distance = 3
Output: 1
Explanation: The leaf nodes of the tree are 3 and 4 and the length of the shortest path between them is 3. This is the only good pair.
```

**Example 2:**

![https://assets.leetcode.com/uploads/2020/07/09/e2.jpg](https://assets.leetcode.com/uploads/2020/07/09/e2.jpg)

```
Input: root = [1,2,3,4,5,6,7], distance = 3
Output: 2
Explanation: The good pairs are [4,5] and [6,7] with shortest path = 2. The pair [4,6] is not good because the length of ther shortest path between them is 4.
```

**Example 3:**

```
Input: root = [7,1,4,6,null,5,3,null,null,null,null,null,2], distance = 3
Output: 1
Explanation: The only good pair is [2,5].
```

**Constraints:**

- The number of nodes in the `tree` is in the range `[1, 210].`
- `1 <= Node.val <= 100`
- `1 <= distance <= 10`

## My Solutions

---

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def collect_leaves_and_paths(self, node: TreeNode, path: List[TreeNode], leaves: List[TreeNode], node_to_path: defaultdict) -> None:
        if not node:
            return

        path.append(node)
        if not node.left and not node.right:
            leaves.append(node)
            node_to_path[node] = path.copy()
        else:
            self.collect_leaves_and_paths(node.left, path, leaves, node_to_path)
            self.collect_leaves_and_paths(node.right, path, leaves, node_to_path)
        path.pop()

    def calculate_distance(self, path1: List[TreeNode], path2: List[TreeNode]) -> int:
        i = 0
        while i < min(len(path1), len(path2)) and path1[i] == path2[i]:
            i += 1
        return (len(path1) - i) + (len(path2) - i)
    def countPairs(self, root: Optional[TreeNode], distance: int) -> int:
        if not root:
            return 0

        node_to_path = defaultdict(list)
        leaves = []
        self.collect_leaves_and_paths(root, [], leaves, node_to_path)

        res = 0
        for i in range(len(leaves)):
            for j in range(i + 1, len(leaves)):
                one_path = node_to_path[leaves[i]]
                two_path = node_to_path[leaves[j]]
                dis = self.calculate_distance(one_path, two_path)
                if dis <= distance:
                    res += 1

        return res
```

```python

```

## Optimal Solutions

---

### Problem Description

Given the root of a binary tree and an integer `distance`, a pair of two different leaf nodes is considered "good" if the shortest path between them in the tree is less than or equal to `distance`.

Return the number of good leaf node pairs in the tree.

### Example

```python
Input: root = [1,2,3,null,4], distance = 3
Output: 1

Explanation:
- The tree looks like this:
    1
   / \\
  2   3
   \\
    4

- There is 1 good leaf node pair: (4, 3) with a distance of 3.

```

### Solution Approach

To solve this problem, we can use a depth-first search (DFS) approach. The idea is to calculate the number of good leaf node pairs for each subtree. As we process the tree, we can pass information about the distances from leaf nodes up to their parent nodes.

### Detailed Steps

1. **DFS Traversal**:
    - Perform a DFS traversal of the tree.
    - At each node, calculate the distances of its leaf nodes to itself.
    - If a node is a leaf, its distance is 0 (since it's at itself).
2. **Combine Distances**:
    - For each non-leaf node, combine the distances of its left and right subtrees.
    - If the sum of any two distances from the left and right subtrees is less than or equal to the given `distance`, then those two leaf nodes form a good pair.
3. **Pass Distances Up**:
    - Pass the distances of the current node's leaf nodes up to its parent by incrementing the distance by 1.
4. **Count Good Pairs**:
    - Keep a running total of all the good pairs found during the traversal.

### Python Code

Here's the Python code implementing the solution:

```python
from typing import Optional, List
from collections import defaultdict

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def countPairs(self, root: Optional[TreeNode], distance: int) -> int:
        self.result = 0

        def dfs(node):
            if not node:
                return []

            # Leaf node
            if not node.left and not node.right:
                return [1]  # Distance of 1 from itself

            # Get distances from leaf nodes in left and right subtrees
            left_distances = dfs(node.left)
            right_distances = dfs(node.right)

            # Count good pairs
            for ld in left_distances:
                for rd in right_distances:
                    if ld + rd <= distance:
                        self.result += 1

            # Pass up the current node's leaf distances, incremented by 1
            return [d + 1 for d in left_distances + right_distances if d + 1 <= distance]

        dfs(root)
        return self.result

# Example usage
root = TreeNode(1)
root.left = TreeNode(2)
root.right = TreeNode(3)
root.left.right = TreeNode(4)

sol = Solution()
print(sol.countPairs(root, 3))  # Output: 1

```

### Explanation

1. **DFS Traversal**:
    - We perform a DFS on the binary tree using the helper function `dfs(node)`. This function returns a list of distances of all leaf nodes in the subtree rooted at `node` to `node`.
    - For leaf nodes, this list contains a single element `[1]`, representing the distance from the leaf node to itself (with the intention to increment as we move up the tree).
2. **Counting Good Pairs**:
    - For each node, after computing the distances of leaf nodes in the left and right subtrees, we check all pairs of distances from the left and right subtrees. If the sum of a pair is less than or equal to `distance`, it is counted as a good pair.
    - We increment `self.result` each time a good pair is found.
3. **Passing Distances Up**:
    - After processing the current node, we return a list of updated distances (incremented by 1) for the leaf nodes to the parent node.
    - This allows the parent node to combine these distances with those from its other subtree and continue the process.
4. **Final Count**:
    - The final count of good pairs is stored in `self.result`, which is returned after the DFS completes.

### Time Complexity Analysis

- **Time Complexity**: `O(n * k)` where `n` is the number of nodes and `k` is the maximum number of distances that need to be checked (related to the `distance` parameter).
    - Each node processes the distances from its left and right subtrees, leading to potentially `O(k^2)` comparisons at each node. However, since `distance` is typically small, the actual runtime is closer to `O(n)` in practice.
- **Space Complexity**: `O(h + k)` where `h` is the height of the tree (for recursion stack) and `k` is the space used for storing the distances at each node.

This solution efficiently counts the number of good leaf node pairs by leveraging DFS and passing distance information up the tree.

## Notes

---

 This can go suck it ma

## Related Videos

---

[https://www.youtube.com/watch?v=f_epkBeS1LQ](https://www.youtube.com/watch?v=f_epkBeS1LQ)