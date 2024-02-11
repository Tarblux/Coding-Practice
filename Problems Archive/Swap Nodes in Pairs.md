# Swap Nodes in Pairs

Problem: 24
Official Difficulty: medium
Feels Like : medium
Topic: linked list, recursion
Link: https://leetcode.com/problems/swap-nodes-in-pairs/description/
Completed On : February 7, 2024
My Understanding: Mostly Understand, Needs Review
Last Review: February 7, 2024
Days Since Review: 3

## Problem

---

Given 
a linked list, swap every two adjacent nodes and return its head. You 
must solve the problem without modifying the values in the list's nodes 
(i.e., only nodes themselves may be changed.)

**Example 1:**

![https://assets.leetcode.com/uploads/2020/10/03/swap_ex1.jpg](https://assets.leetcode.com/uploads/2020/10/03/swap_ex1.jpg)

```
Input: head = [1,2,3,4]
Output: [2,1,4,3]

```

**Example 2:**

```
Input: head = []
Output: []
```

**Example 3:**

```
Input: head = [1]
Output: [1]
```

**Constraints:**

- The number of nodes in the list is in the range `[0, 100]`.
- `0 <= Node.val <= 100`

## My Solutions

---

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:

    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:

        if not head : 

            return

        filler_node = ListNode()

				filler_node.next = head

        current = head

        prev = filler_node

        while current and current.next : 

            # Store Nodes

            third_node = current.next.next

            second_node = current.next

            # Swaps

            second_node.next = current

            current.next = third_node

            prev.next = second_node

            # Move

            prev = current 

            current = third_node

        return filler_node.next
```

```python

```

## Optimal Solutions

---

### Problem Statement

Given a linked list, swap every two adjacent nodes and return its head. You may not modify the values in the list's nodes, only nodes itself may be changed.

### Iterative Solution

The iterative solution involves traversing the list and swapping nodes by changing their `next` pointers. A dummy node can be used to simplify edge cases, especially handling the head of the list.

### Python Implementation

```python
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        # Create a dummy node that points to the head of the list
        dummy = ListNode(-1)
        dummy.next = head
        prev_node = dummy

        while head and head.next:
            # Nodes to be swapped
            first_node = head
            second_node = head.next

            # Swapping
            prev_node.next = second_node
            first_node.next = second_node.next
            second_node.next = first_node

            # Reinitializing the head and prev_node for the next swap
            prev_node = first_node
            head = first_node.next

        # Return the modified list
        return dummy.next
```

### Recursive Solution

Alternatively, the problem can be solved recursively by swapping the first two nodes and then recursively calling the function on the rest of the list.

### Python Implementation

```python
class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        # Base case: if the list is empty or has a single node, no swap needed
        if not head or not head.next:
            return head

        # Nodes to be swapped
        first_node = head
        second_node = head.next

        # Swapping
        first_node.next = self.swapPairs(second_node.next)
        second_node.next = first_node

        # Now the head is the second node
        return second_node
```

### Explanation

- **Iterative Solution**: A dummy node is used to handle swaps at the head of the list. The algorithm iterates through the list, swapping pairs of nodes by adjusting their `next` pointers. The `prev_node` helps in relinking the swapped pairs with the rest of the list.
- **Recursive Solution**: The recursive approach swaps the first two nodes and then makes a recursive call to swap the remaining pairs. The base case for the recursion is when the list is empty (`head` is `None`) or has only one node (`head.next` is `None`), in which case the list is returned as is.

### Complexity Analysis

- **Time Complexity**: O(n) for both solutions, where n is the number of nodes in the list. Each node is visited/processed exactly once.
- **Space Complexity**: O(1) for the iterative solution, as it only uses a few pointers. O(n) for the recursive solution due to the recursion call stack, where n is the list's length divided by 2 (for each pair).

## Notes

---

 

## Related Videos

---

[https://youtu.be/o811TZLAWOo](https://youtu.be/o811TZLAWOo)