# Odd Even Linked List

Problem: 328
Official Difficulty: medium
Feels Like : easy
Topic: linked list
Link: https://leetcode.com/explore/interview/card/top-interview-questions-medium/107/linked-list/784/
Completed On : January 13, 2024
My Understanding: Mostly Understand
Last Review: January 13, 2024
Days Since Review: 28

## Problem

---

Given the `head` of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return *the reordered list*.

The **first** node is considered **odd**, and the **second** node is **even**, and so on.

Note that the relative order inside both the even and odd groups should remain as it was in the input.

You must solve the problem in `O(1)` extra space complexity and `O(n)` time complexity.

**Example 1:**

![https://assets.leetcode.com/uploads/2021/03/10/oddeven-linked-list.jpg](https://assets.leetcode.com/uploads/2021/03/10/oddeven-linked-list.jpg)

```
Input: head = [1,2,3,4,5]
Output: [1,3,5,2,4]
```

**Example 2:**

![https://assets.leetcode.com/uploads/2021/03/10/oddeven2-linked-list.jpg](https://assets.leetcode.com/uploads/2021/03/10/oddeven2-linked-list.jpg)

```
Input: head = [2,1,3,5,6,4,7]
Output: [2,3,6,7,1,5,4]
```

**Constraints:**

- The number of nodes in the linked list is in the range `[0, 104]`.
- `106 <= Node.val <= 106`

## My Solutions

---

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def oddEvenList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        
        if not head or not head.next : 
            
            return head
        
        even = head.next
        
        odd = head
        
        og_even = even
        
        while even and even.next :
            
            odd.next = even.next
            
            odd = odd.next
            
            even.next = odd.next
            
            even = even.next
            
        
        odd.next = og_even
        
        return head
```

```python

```

## Optimal Solutions

---

The most optimal solution for the "Odd Even Linked List" problem involves rearranging the nodes of the given linked list so that all nodes at odd positions come before all nodes at even positions, while preserving the relative order of both odd and even positioned nodes. This can be efficiently achieved in a single pass through the list using constant extra space.

### Solution Approach

1. **Separate Odd and Even Nodes**: Maintain two pointers, `odd` and `even`, to group odd and even positioned nodes separately.
2. **Retain the Head of the Even List**: Store the head of the even list to connect it back to the odd list at the end.
3. **Iterate and Rearrange**: Traverse the list, rearranging nodes such that `odd` pointers skip over even nodes and `even` pointers skip over odd nodes.
4. **Connect Odd and Even Lists**: After the rearrangement, connect the last node of the odd list to the head of the even list.

### Python Implementation

```python
class Solution:
    def oddEvenList(self, head: ListNode) -> ListNode:
        if not head or not head.next:
            return head

        odd = head
        even = head.next
        evenHead = even

        while even and even.next:
            odd.next = even.next
            odd = odd.next
            even.next = odd.next
            even = even.next

        odd.next = evenHead
        return head

```

### Explanation

- Initialize `odd` to the head of the list and `even` to the second node.
- `evenHead` stores the starting node of the even list.
- In the `while` loop, `odd.next` is set to `even.next` (skipping the even node) and similarly, `even.next` is set to `odd.next` (skipping the next odd node).
- Move `odd` and `even` forward.
- After the loop, connect the end of the odd list (`odd.next`) to the head of the even list (`evenHead`).

### Complexity Analysis

- **Time Complexity**: O(n), where n is the number of nodes in the linked list. The solution requires a single traversal of the list.
- **Space Complexity**: O(1), as the rearrangement is done in place without using any additional data structures.

This solution is optimal in terms of both time and space complexity. It efficiently reorganizes the list in a single pass while using constant extra space.

## Notes

---

 Pretty standard linked list movements , they are slowly starting to make a lot of sense if you understand their structure.

## Related Videos

---

[https://www.youtube.com/watch?v=qf6qp7GzD5Q&pp=ygUVb2RkIGV2ZW4gbGlua2VkIGxpc3Qg](https://www.youtube.com/watch?v=qf6qp7GzD5Q&pp=ygUVb2RkIGV2ZW4gbGlua2VkIGxpc3Qg)