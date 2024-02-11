# Convert Sorted Array to Binary Search Tree

Problem: 108
Official Difficulty: easy
Feels Like : medium
Topic: Divide and Conquer, array, binary search tree, binary tree
Link: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/
Completed On : January 18, 2024
My Understanding: I Have No Idea
Last Review: January 18, 2024
Days Since Review: 23

## Problem

---

Given an integer array `nums` where the elements are sorted in **ascending order**, convert *it to a*

***height-balanced** binary search tree*.

**Example 1:**

![https://assets.leetcode.com/uploads/2021/02/18/btree1.jpg](https://assets.leetcode.com/uploads/2021/02/18/btree1.jpg)

```
Input: nums = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: [0,-10,5,null,-3,null,9] is also accepted:
```

![https://assets.leetcode.com/uploads/2021/02/18/btree2.jpg](https://assets.leetcode.com/uploads/2021/02/18/btree2.jpg)

**Example 2:**

![https://assets.leetcode.com/uploads/2021/02/18/btree.jpg](https://assets.leetcode.com/uploads/2021/02/18/btree.jpg)

```
Input: nums = [1,3]
Output: [3,1]
Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.
```

**Constraints:**

- `1 <= nums.length <= 104`
- `104 <= nums[i] <= 104`
- `nums` is sorted in a **strictly increasing** order.

## My Solutions

---

- Neetcode

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
        
        def helper (l,r) : 
            
            if l > r : 
                
                return None
            
            m = (l + r ) // 2
            
            root = TreeNode(nums[m])
            
            root.left = helper(l,m-1)
            
            root.right = helper(m+1,r)
            
            return root
        
        return helper(0,len(nums)-1)
```

```python

```

## Optimal Solutions

---

The "Convert Sorted Array to Binary Search Tree" problem asks you to create a height-balanced binary search tree (BST) from a sorted array. A height-balanced BST is a binary tree in which the depth of the two subtrees of every node never differs by more than one.

### Problem Statement

Given an integer array `nums` where the elements are sorted in ascending order, convert it to a height-balanced BST.

### Solution Approach

The key to solving this problem is to always choose the middle element of the current array (or subarray) as the root. This ensures that the tree remains height-balanced. The process is recursive: after choosing the middle element as the root, the left subtree is built from the elements to the left of the middle element, and the right subtree is built from the elements to the right of the middle element.

### Python Implementation

Assuming you have a TreeNode class defined as follows:

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

```

Here's an implementation of the solution:

```python
class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> TreeNode:
        def buildBST(left, right):
            if left > right:
                return None

            mid = (left + right) // 2
            root = TreeNode(nums[mid])
            root.left = buildBST(left, mid - 1)
            root.right = buildBST(mid + 1, right)

            return root

        return buildBST(0, len(nums) - 1)

```

### Explanation

- The function `buildBST` takes two parameters, `left` and `right`, which define the current subarray's boundaries.
- If `left` is greater than `right`, the current subarray is empty, and it should return `None`.
- Find the middle element of the current subarray and make it the root.
- Recursively build the left subtree using the elements to the left of the middle element and the right subtree using the elements to the right of the middle element.
- Return the root.

### Complexity Analysis

- **Time Complexity**: O(n), where n is the number of elements in `nums`. Each element is visited once to create a corresponding node.
- **Space Complexity**: O(log n) for the recursive stack. In the best case (the tree is balanced), the height of the tree is log n, and hence the recursive stack will also be of height log n.

This approach efficiently builds a height-balanced BST from a sorted array by ensuring that the tree is constructed in a way that maintains the BST properties and balance.

## Notes

---

 F Recursion !!!!

## Related Videos

---

[https://youtu.be/0K0uCMYq5ng](https://youtu.be/0K0uCMYq5ng)