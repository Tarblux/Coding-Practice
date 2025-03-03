<<<<<<< Updated upstream
Problem: 297
Official Difficulty: hard
Link: https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/
Completed On : 2024-12-27
Feels Like : medium
Topic: string, tree, Depth-First Search (DFS), Breadth-First Search(BFS), design, binary tree
My Understanding: Mostly Understand
Last Review: 2024-12-27
Days Since Review: 2
Name: Serialize and Deserialize Binary Tree

# Serialize and Deserialize Binary Tree
### Problem
___
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.
Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.
**Clarification:** The input/output format is the same as [how LeetCode serializes a binary tree](https://support.leetcode.com/hc/en-us/articles/32442719377939-How-to-create-test-cases-on-LeetCode#h_01J5EGREAW3NAEJ14XC07GRW1A). You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.
**Example 1:**
![serdeser.jpg](https://assets.leetcode.com/uploads/2020/09/15/serdeser.jpg)
```plain text
Input: root = [1,2,3,null,null,4,5]
Output: [1,2,3,null,null,4,5]
```
**Example 2:**
```plain text
Input: root = []
Output: []
```
**Constraints:**
- The number of nodes in the tree is in the range `[0, 104]`.
- `1000 <= Node.val <= 1000`
### My Solutions
___
=======
# Serialize and Deserialize Binary Tree

Problem: 297
Official Difficulty: hard
Feels Like : medium
My Understanding: Mostly Understand
Topic: Breadth-First Search(BFS), Depth-First Search (DFS), binary tree, design, string, tree
Link: https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/
Completed On : December 27, 2024
Last Review: December 27, 2024
Days Since Review: 65
Neetcode: Yes

## Problem

---

Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

**Clarification:** The input/output format is the same as [how LeetCode serializes a binary tree](https://support.leetcode.com/hc/en-us/articles/32442719377939-How-to-create-test-cases-on-LeetCode#h_01J5EGREAW3NAEJ14XC07GRW1A). You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

**Example 1:**

![](https://assets.leetcode.com/uploads/2020/09/15/serdeser.jpg)

```
Input: root = [1,2,3,null,null,4,5]
Output: [1,2,3,null,null,4,5]
```

**Example 2:**

```
Input: root = []
Output: []
```

**Constraints:**

- The number of nodes in the tree is in the range `[0, 104]`.
- `1000 <= Node.val <= 1000`

## My Solutions

---

>>>>>>> Stashed changes
```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:

    def serialize(self, root):

        # n represents null node

        if not root:
            return ''

        self.serialized = []
        queue = deque([root])

        while queue:

            node = queue.popleft()

            if node != 'n ': 
                self.serialized.append(str(node.val) + ' ')
            else:
                self.serialized.append('n ')
                continue

            if not node.left:
                queue.append('n ')
            else:
                queue.append(node.left)

            if not node.right:
                queue.append('n ')
            else:
                queue.append(node.right)

        return ''.join(self.serialized)

        """Encodes a tree to a single string.
        :type root: TreeNode
        :rtype: str
        """
        

    def deserialize(self, data):
        
        if not data:
            return None

        tokens = data.split()

        if tokens[0] == 'n':
            return None

        root = TreeNode(int(tokens[0]))
        queue = deque([root])

        i = 1

        while queue and i < len(tokens):
            node = queue.popleft()

            if tokens[i] != 'n':
                node.left = TreeNode(int(tokens[i]))
                queue.append(node.left)
            i += 1

            if i < len(tokens):
                if tokens[i] != 'n':
                    node.right = TreeNode(int(tokens[i]))
                    queue.append(node.right)
                i += 1

        return root

        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        

# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# ans = deser.deserialize(ser.serialize(root))
```

<<<<<<< Updated upstream
Time Complexity :
=======
>>>>>>> Stashed changes
```python

```

<<<<<<< Updated upstream
Time Complexity : 
### Optimal Solutions
___
To solve **Serialize and Deserialize Binary Tree** (LeetCode 297), we can use a **Breadth-First Search (BFS)** or **Depth-First Search (DFS)** approach.
#### **Problem Overview**
- **Serialization:** Convert a binary tree into a string format so it can be stored or transmitted.
- **Deserialization:** Reconstruct the binary tree from the serialized string.
___
#### **Approach 1: BFS (Level Order Traversal)**
#### **Serialization:**
1. Use a queue to traverse the tree level by level.
2. Add node values to the result string in level order.
3. Use a placeholder (e.g., `"null"`) for missing children to maintain the structure.
#### **Deserialization:**
4. Parse the serialized string.
5. Use a queue to rebuild the tree.
6. Assign children to each node in level order using placeholders for null nodes.
___
#### Code Implementation (BFS)
=======
## Optimal Solutions

---

To solve **Serialize and Deserialize Binary Tree** (LeetCode 297), we can use a **Breadth-First Search (BFS)** or **Depth-First Search (DFS)** approach.

### **Problem Overview**

- **Serialization:** Convert a binary tree into a string format so it can be stored or transmitted.
- **Deserialization:** Reconstruct the binary tree from the serialized string.

---

### **Approach 1: BFS (Level Order Traversal)**

### **Serialization:**

1. Use a queue to traverse the tree level by level.
2. Add node values to the result string in level order.
3. Use a placeholder (e.g., `"null"`) for missing children to maintain the structure.

### **Deserialization:**

1. Parse the serialized string.
2. Use a queue to rebuild the tree.
3. Assign children to each node in level order using placeholders for null nodes.

---

### Code Implementation (BFS)

>>>>>>> Stashed changes
```python
from collections import deque

class Codec:
    def serialize(self, root):
        """Encodes a tree to a single string."""
        if not root:
            return "null"

        result = []
        queue = deque([root])

        while queue:
            node = queue.popleft()
            if node:
                result.append(str(node.val))
                queue.append(node.left)
                queue.append(node.right)
            else:
                result.append("null")

        return ",".join(result)

    def deserialize(self, data):
        """Decodes your encoded data to tree."""
        if data == "null":
            return None

        values = data.split(",")
        root = TreeNode(int(values[0]))
        queue = deque([root])
        i = 1

        while queue:
            node = queue.popleft()
            if values[i] != "null":
                node.left = TreeNode(int(values[i]))
                queue.append(node.left)
            i += 1

            if values[i] != "null":
                node.right = TreeNode(int(values[i]))
                queue.append(node.right)
            i += 1

        return root

```
<<<<<<< Updated upstream
___
#### **Approach 2: DFS (Preorder Traversal)**
#### **Serialization:**
7. Perform a preorder traversal.
8. Append node values to the serialized string.
9. Use a placeholder (e.g., `"null"`) for missing children.
#### **Deserialization:**
10. Use a recursive function to reconstruct the tree.
11. Consume the serialized string values one at a time in preorder.
___
#### Code Implementation (DFS)
=======

---

### **Approach 2: DFS (Preorder Traversal)**

### **Serialization:**

1. Perform a preorder traversal.
2. Append node values to the serialized string.
3. Use a placeholder (e.g., `"null"`) for missing children.

### **Deserialization:**

1. Use a recursive function to reconstruct the tree.
2. Consume the serialized string values one at a time in preorder.

---

### Code Implementation (DFS)

>>>>>>> Stashed changes
```python
class Codec:
    def serialize(self, root):
        """Encodes a tree to a single string."""
        def dfs(node):
            if not node:
                result.append("null")
                return
            result.append(str(node.val))
            dfs(node.left)
            dfs(node.right)

        result = []
        dfs(root)
        return ",".join(result)

    def deserialize(self, data):
        """Decodes your encoded data to tree."""
        def dfs():
            val = next(values)
            if val == "null":
                return None
            node = TreeNode(int(val))
            node.left = dfs()
            node.right = dfs()
            return node

        values = iter(data.split(","))
        return dfs()

```
<<<<<<< Updated upstream
___
#### **Comparison**

|**Approach**|**Serialization**|**Deserialization**|**Space Complexity**|**Use Case**|
|---|---|---|---|---|
|**BFS**|Level-order traversal|Rebuild using a queue|O(n)|Trees with more levels|
|**DFS (Preorder)**|Preorder traversal|Rebuild recursively|O(h) (recursion stack)|More intuitive for recursion|
___
#### **Complexity Analysis**
- **Time Complexity:**
	- Serialization: O(n) (visit every node once).
	- Deserialization: O(n) (process every value once).
- **Space Complexity:**
	- BFS: O(n) for the queue during traversal.
	- DFS: O(h) for the recursion stack (h is the height of the tree).
___
#### **Example Walkthrough**
#### **Input Tree:**
```plain text
=======

---

### **Comparison**

| **Approach** | **Serialization** | **Deserialization** | **Space Complexity** | **Use Case** |
| --- | --- | --- | --- | --- |
| **BFS** | Level-order traversal | Rebuild using a queue | O(n) | Trees with more levels |
| **DFS (Preorder)** | Preorder traversal | Rebuild recursively | O(h) (recursion stack) | More intuitive for recursion |

---

### **Complexity Analysis**

- **Time Complexity:**
    - Serialization: O(n) (visit every node once).
    - Deserialization: O(n) (process every value once).
- **Space Complexity:**
    - BFS: O(n) for the queue during traversal.
    - DFS: O(h) for the recursion stack (h is the height of the tree).

---

### **Example Walkthrough**

### **Input Tree:**

```
>>>>>>> Stashed changes
       1
      / \
     2   3
        / \
       4   5

```
<<<<<<< Updated upstream
**Serialized String (BFS):**
```plain text
"1,2,3,null,null,4,5"

```
**Serialized String (DFS):**
```plain text
"1,2,null,null,3,4,null,null,5,null,null"

```
**Deserialization Result:**
Restores the input tree structure.
Both methods achieve the same result, but the choice depends on your preference for BFS or DFS traversal.
### Notes
___
 
### Related Videos 
___
[]()
=======

**Serialized String (BFS):**

```
"1,2,3,null,null,4,5"

```

**Serialized String (DFS):**

```
"1,2,null,null,3,4,null,null,5,null,null"

```

**Deserialization Result:**
Restores the input tree structure.

Both methods achieve the same result, but the choice depends on your preference for BFS or DFS traversal.

## Notes

---

 

## Related Videos

---

[https://www.notion.so](https://www.notion.so)
>>>>>>> Stashed changes
