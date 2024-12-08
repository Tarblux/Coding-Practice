Problem: 938
Official Difficulty: easy
Link: https://leetcode.com/problems/range-sum-of-bst/description/?envType=company&envId=facebook&favoriteSlug=facebook-thirty-days
Completed On : 2024-12-07
Feels Like : easy breazy
Topic: tree, Depth-First Search (DFS), binary search tree, binary tree
My Understanding: Fully Understand
Last Review: 2024-12-07
Days Since Review: 1
Name: Range Sum of BST

# Range Sum of BST
### Problem
___
Given the `root` node of a binary search tree and two integers `low` and `high`, return *the sum of values of all nodes with a value in the ****inclusive**** range *`[low, high]`.
**Example 1:**
![bst1.jpg](https://assets.leetcode.com/uploads/2020/11/05/bst1.jpg)
```plain text
Input: root = [10,5,15,3,7,null,18], low = 7, high = 15
Output: 32
Explanation: Nodes 7, 10, and 15 are in the range [7, 15]. 7 + 10 + 15 = 32.
```
**Example 2:**
![bst2.jpg](https://assets.leetcode.com/uploads/2020/11/05/bst2.jpg)
```plain text
Input: root = [10,5,15,3,7,13,18,1,null,6], low = 6, high = 10
Output: 23
Explanation: Nodes 6, 7, and 10 are in the range [6, 10]. 6 + 7 + 10 = 23.
```
**Constraints:**
- The number of nodes in the tree is in the range `[1, 2 * 104]`.
- `1 <= Node.val <= 105`
- `1 <= low <= high <= 105`
- All `Node.val` are **unique**.
### My Solutions
___
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rangeSumBST(self, root: Optional[TreeNode], low: int, high: int) -> int:

        if not root:
            return 0

        left = self.rangeSumBST(root.left,low,high)
        right = self.rangeSumBST(root.right,low,high)

        if  low <= root.val <= high:
            return root.val + left + right
        else:
            return left + right
```

Time Complexity :
```python

```

Time Complexity : 
### Optimal Solutions
___

### Notes
___
 
### Related Videos 
___
[]()