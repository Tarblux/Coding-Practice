# Build Binary Tree From Description

Problem: 2196
Official Difficulty: medium
Feels Like : hard
My Understanding: Mostly Understand, Needs Review
Topic: array, binary tree, hash table, tree
Link: https://leetcode.com/problems/create-binary-tree-from-descriptions/description/
Completed On : August 9, 2024
Last Review: August 9, 2024
Days Since Review: 0

## Problem

---

You are given a 2D integer array `descriptions` where `descriptions[i] = [parenti, childi, isLefti]` indicates that `parenti` is the **parent** of `childi` in a **binary** tree of **unique** values. Furthermore,

- If `isLefti == 1`, then `childi` is the left child of `parenti`.
- If `isLefti == 0`, then `childi` is the right child of `parenti`.

Construct the binary tree described by `descriptions` and return *its **root***.

The test cases will be generated such that the binary tree is **valid**.

**Example 1:**

```
Input: descriptions = [[20,15,1],[20,17,0],[50,20,1],[50,80,0],[80,19,1]]
Output: [50,20,80,15,17,19]
Explanation: The root node is the node with value 50 since it has no parent.
The resulting binary tree is shown in the diagram.
```

**Example 2:**

![https://assets.leetcode.com/uploads/2022/02/09/example2drawio.png](https://assets.leetcode.com/uploads/2022/02/09/example2drawio.png)

```
Input: descriptions = [[1,2,1],[2,3,0],[3,4,1]]
Output: [1,2,null,null,3,4]
Explanation: The root node is the node with value 1 since it has no parent.
The resulting binary tree is shown in the diagram.
```

**Constraints:**

- `1 <= descriptions.length <= 104`
- `descriptions[i].length == 3`
- `1 <= parenti, childi <= 105`
- `0 <= isLefti <= 1`
- The binary tree described by `descriptions` is valid.

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
    def createBinaryTree(
        self, descriptions: List[List[int]]
    ) -> Optional[TreeNode]:

        children = set()
        all_parents = set()
        god = 0

        parentToChildren = defaultdict(list)

        for d in descriptions:
            parent, child, isLeft = d
            all_parents.add(parent)
            all_parents.add(child)
            children.add(child)

            parentToChildren[parent].append((child, isLeft))

        for parent in all_parents:
            if parent not in children:
                god = parent

        root = TreeNode(god)

        queue = deque([root])

        while queue:
            parent = queue.popleft()
            for childValue, isLeft in parentToChildren[parent.val]:
                child = TreeNode(childValue)
                queue.append(child)
                if isLeft == 1:
                    parent.left = child
                else:
                    parent.right = child

        return root
```

### Thorough Explanation

The task is to construct a binary tree from a given set of descriptions, where each description specifies a parent-child relationship and whether the child is the left or right child of the parent.

### Step-by-Step Explanation

Let's break down the code provided into detailed steps to understand how it constructs the binary tree.

### 1. **Data Structures Initialization**

```python
children = set()
all_parents = set()
god = 0
parentToChildren = defaultdict(list)

```

- **`children`**: A set to store all the nodes that are identified as children in the descriptions. This helps in determining the root node later.
- **`all_parents`**: A set to store all nodes that appear either as parents or children. This helps in identifying the root node.
- **`god`**: A variable to store the root of the binary tree. Initially, it is set to `0` but will be updated to the correct root node.
- **`parentToChildren`**: A dictionary where the key is the parent node value and the value is a list of tuples. Each tuple contains a child node value and a flag (`isLeft`) indicating whether the child is a left child (1) or a right child (0).

### 2. **Processing the Descriptions**

```python
for d in descriptions:
    parent, child, isLeft = d
    all_parents.add(parent)
    all_parents.add(child)
    children.add(child)

    parentToChildren[parent].append((child, isLeft))

```

- **Loop Over Descriptions**: The code iterates over each description in the `descriptions` list. Each description `d` contains three values: `parent`, `child`, and `isLeft`.
    - `parent`: The parent node's value.
    - `child`: The child node's value.
    - `isLeft`: A flag that indicates whether the child is the left child (`1`) or the right child (`0`).
- **Update Sets**:
    - The parent and child are both added to the `all_parents` set to keep track of all nodes.
    - The child is added to the `children` set, which helps identify nodes that are children (i.e., not the root).
- **Update Dictionary**:
    - For each `parent`, the code adds the `child` and `isLeft` information to the `parentToChildren` dictionary. This dictionary will later be used to build the tree.

### 3. **Identifying the Root Node**

```python
for parent in all_parents:
    if parent not in children:
        god = parent

```

- **Finding the Root**:
    - The root of the binary tree is the node that is a parent but not a child in any description.
    - The code iterates over the `all_parents` set. If a node is in `all_parents` but not in `children`, it means this node is not a child of any other node, so it must be the root.
    - The `god` variable is updated with this node's value.

### 4. **Constructing the Binary Tree**

```python
root = TreeNode(god)
queue = deque([root])

while queue:
    parent = queue.popleft()
    for childValue, isLeft in parentToChildren[parent.val]:
        child = TreeNode(childValue)
        queue.append(child)
        if isLeft == 1:
            parent.left = child
        else:
            parent.right = child

```

- **Initialize the Root**:
    - A new `TreeNode` is created for the root node (`god`), and a `queue` is initialized with this root node. The `queue` will be used for a breadth-first construction of the tree.
- **Breadth-First Tree Construction**:
    - The code uses a breadth-first approach to build the tree.
    - It dequeues a `parent` node from the `queue`.
    - For each `childValue` and `isLeft` pair in the `parentToChildren` dictionary:
        - A new `TreeNode` is created for the `child`.
        - This child is added to the `queue` to further process its children in subsequent iterations.
        - If `isLeft` is `1`, the child is assigned as the left child of the parent; otherwise, it is assigned as the right child.

### 5. **Return the Root**

```python
return root

```

- After constructing the entire binary tree, the root node (`root`) is returned as the output.

### Summary

- **Key Concepts**:
    - The code first identifies the root by distinguishing between nodes that are only parents and not children.
    - It then constructs the binary tree using a breadth-first approach, ensuring that each parent-child relationship is correctly represented.
- **Efficiency**:
    - The solution is efficient, with time complexity approximately `O(n)`, where `n` is the number of nodes, as it processes each node and description exactly once.
    - The space complexity is also `O(n)` due to the use of dictionaries and sets to store node information and relationships.

This solution effectively constructs the binary tree from the provided parent-child relationships, ensuring that the structure of the tree matches the given descriptions.

## Optimal Solutions

---

### Solution Approach

To solve this problem, follow these steps:

1. **Create Nodes**: Create nodes for every unique value in the descriptions. Use a dictionary to map each value to its corresponding node.
2. **Build the Tree**: Using the descriptions, link each parent to its child based on whether it is a left or right child.
3. **Identify the Root**: The root of the tree is the node that is never a child. Track all nodes that are children and subtract them from the set of all nodes to find the root.
4. **Return the Root**: Once the tree is built, return the root node.

### Python Code

Here's the Python code to achieve this:

```python
from typing import List, Optional
from collections import defaultdict

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def createBinaryTree(self, descriptions: List[List[int]]) -> Optional[TreeNode]:
        nodes = {}
        children = set()

        # Create nodes and build relationships
        for parent_val, child_val, is_left in descriptions:
            if parent_val not in nodes:
                nodes[parent_val] = TreeNode(parent_val)
            if child_val not in nodes:
                nodes[child_val] = TreeNode(child_val)

            parent = nodes[parent_val]
            child = nodes[child_val]

            if is_left:
                parent.left = child
            else:
                parent.right = child

            children.add(child_val)

        # The root is the node that is not a child of any node
        root_val = (set(nodes.keys()) - children).pop()
        return nodes[root_val]

# Example usage
sol = Solution()
descriptions = [[20,15,1],[20,17,0],[50,20,1],[50,80,0],[80,19,1]]
root = sol.createBinaryTree(descriptions)

def print_tree(root):
    if not root:
        return
    print(root.val, end=' ')
    print_tree(root.left)
    print_tree(root.right)

print_tree(root)  # Output: 50 20 15 17 80 19

```

### Explanation

1. **Creating Nodes**:
    - A dictionary `nodes` is used to store `TreeNode` objects, keyed by their values. If a node does not exist in `nodes`, it is created and added to the dictionary.
2. **Building Relationships**:
    - For each description, the corresponding parent and child nodes are linked according to whether the child is a left or right child.
3. **Identifying the Root**:
    - The root node is the one that never appears as a child in the descriptions. By tracking all child nodes in a set `children`, the root can be found by subtracting this set from the set of all node values.
4. **Return the Root**:
    - Once the tree is constructed, the root node is identified and returned.
    
    ![https://assets.leetcode.com/uploads/2022/02/09/example1drawio.png](https://assets.leetcode.com/uploads/2022/02/09/example1drawio.png)
    

### Time Complexity Analysis

- **Time Complexity**: `O(n)`
    - Each description is processed once, and the dictionary operations (insertions, lookups) are average `O(1)`.
- **Space Complexity**: `O(n)`
    - The space required is proportional to the number of nodes, as we store each node in the `nodes` dictionary and keep track of all children.

This approach ensures that the binary tree is constructed efficiently and correctly, with the root node identified through a set difference operation.

# With Default dict

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def createBinaryTree(self, descriptions: List[List[int]]) -> Optional[TreeNode]:

        nodes = defaultdict(TreeNode)
        children = set()

        for parent_val, child_val, is_left in descriptions:

            parent = nodes[parent_val]
            parent.val = parent_val
            child = nodes[child_val]
            child.val = child_val

            if is_left:
                parent.left = child
            else:
                parent.right = child

            children.add(child_val)

        # The root is the node that is not a child of any node
        root_val = (set(nodes.keys()) - children).pop()
        return nodes[root_val]
```

## Notes

---

 

## Related Videos

---

[https://www.youtube.com/watch?v=yWkrFfqO7NA](https://www.youtube.com/watch?v=yWkrFfqO7NA)