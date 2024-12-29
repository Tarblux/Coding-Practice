Problem: 138
Official Difficulty: medium
Link: https://leetcode.com/problems/copy-list-with-random-pointer/description/
Completed On : 2024-12-22
Feels Like : medium
Topic: linked list, hash table
My Understanding: Mostly Understand
Last Review: 2024-12-22
Days Since Review: 7
Name: Copy List With Random Pointer

# Copy List With Random Pointer
### Problem
___
A linked list of length `n` is given such that each node contains an additional random pointer, which could point to any node in the list, or `null`.
Construct a **[deep copy](https://en.wikipedia.org/wiki/Object_copying#Deep_copy)** of the list. The deep copy should consist of exactly `n` **brand new** nodes, where each new node has its value set to the value of its corresponding original node. Both the `next` and `random` pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. **None of the pointers in the new list should point to nodes in the original list**.
For example, if there are two nodes `X` and `Y` in the original list, where `X.random --> Y`, then for the corresponding two nodes `x` and `y` in the copied list, `x.random --> y`.
Return *the head of the copied linked list*.
The linked list is represented in the input/output as a list of `n` nodes. Each node is represented as a pair of `[val, random_index]` where:
- `val`: an integer representing `Node.val`
- `random_index`: the index of the node (range from `0` to `n-1`) that the `random` pointer points to, or `null` if it does not point to any node.
Your code will **only** be given the `head` of the original linked list.
**Example 1:**
![e1.png](https://assets.leetcode.com/uploads/2019/12/18/e1.png)
```plain text
Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
```
**Example 2:**
![e2.png](https://assets.leetcode.com/uploads/2019/12/18/e2.png)
```plain text
Input: head = [[1,1],[2,1]]
Output: [[1,1],[2,1]]
```
**Example 3:**
![e3.png](https://assets.leetcode.com/uploads/2019/12/18/e3.png)
```plain text
Input: head = [[3,null],[3,0],[3,null]]
Output: [[3,null],[3,0],[3,null]]
```
**Constraints:**
- `0 <= n <= 1000`
- `104 <= Node.val <= 104`
- `Node.random` is `null` or is pointing to some node in the linked list.
### My Solutions
___
```python
"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':

        if not head:
            return None

        old_nodes = {}
        new_nodes = {}

        current = head

        new_head = Node(0)
        new_cur = new_head

        while current:
            
            node = Node(current.val)
            new_cur.next = node
            new_cur = new_cur.next

            old_nodes[current] = node
            new_nodes[node] = current

            current = current.next

        cur = new_head.next

        while cur:

            old_random = new_nodes[cur].random
            cur.random = old_nodes.get(old_random,None)
            cur = cur.next

        return new_head.next

```

Time Complexity :
```python

```

Time Complexity : 
### Optimal Solutions
___
Here’s how to solve **LeetCode 138: Copy List with Random Pointer** efficiently using a **three-step approach**:
___
#### **Approach**
The task is to create a deep copy of a linked list where each node contains:
1. A `val` (node value).
2. A `next` pointer to the next node in the list.
3. A `random` pointer that points to any node in the list (or `null`).
The solution avoids extra space for a hash map by interleaving new nodes with the original list and then separating them.
___
#### **Steps**
#### **1. Interleave the Original and Cloned Nodes**
- Create new nodes by interleaving them with the original nodes:
	- For each node in the original list:
		- Create a new node with the same value.
		- Insert the new node immediately after the original node in the list.
#### **2. Copy the **`**random**`** Pointers**
- For each node in the interleaved list:
	- If the original node’s `random` pointer is not `null`, set the cloned node’s `random` pointer to `original.random.next` (i.e., the cloned node of the original random target).
#### **3. Separate the Two Lists**
- Split the interleaved list into the original list and the cloned list:
	- Restore the `next` pointers of the original list.
	- Link the `next` pointers of the cloned list.
___
#### **Code Implementation**
```python
class Node:
    def __init__(self, val, next=None, random=None):
        self.val = val
        self.next = next
        self.random = random

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        if not head:
            return None

        # Step 1: Interleave original and cloned nodes
        current = head
        while current:
            new_node = Node(current.val)
            new_node.next = current.next
            current.next = new_node
            current = new_node.next

        # Step 2: Copy random pointers
        current = head
        while current:
            if current.random:
                current.next.random = current.random.next
            current = current.next.next

        # Step 3: Separate the two lists
        current = head
        new_head = head.next
        while current:
            clone = current.next
            current.next = clone.next
            current = current.next
            if clone.next:
                clone.next = clone.next.next

        return new_head

```
___
#### **Example Walkthrough**
**Input:**
```plain text
Original List:
1 -> 2 -> 3
Random Pointers:
1.random = 3, 2.random = 1, 3.random = null

```
**Execution:**
4. **Step 1: Interleave Nodes**
```plain text
1 -> 1' -> 2 -> 2' -> 3 -> 3'

```
5. **Step 2: Copy Random Pointers**
```plain text
1'.random = 3', 2'.random = 1', 3'.random = null

```
6. **Step 3: Separate Lists**
```plain text
Original: 1 -> 2 -> 3
Cloned:   1' -> 2' -> 3'

```
**Output:** A deep copy of the list.
___
#### **Complexity Analysis**
- **Time Complexity:** O(n)
	- Each of the three steps (interleaving, copying `random` pointers, and separating lists) involves a single traversal of the list.
- **Space Complexity:** O(1)
	- No extra space is used beyond the cloned nodes and the pointers.
This in-place interleaving method is efficient and avoids the overhead of using a hash map.
### Notes
___
 
### Related Videos 
___
[5Y2EiZST97Y](https://youtu.be/5Y2EiZST97Y)