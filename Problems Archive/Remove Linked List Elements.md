# Remove Linked List Elements

Problem: 203
Official Difficulty: easy
Feels Like : easy
My Understanding: Fully Understand
Topic: linked list
Link: https://leetcode.com/problems/remove-linked-list-elements/description/
Completed On : March 15, 2024
Last Review: March 15, 2024
Days Since Review: 46

## Problem

---

Given the `head` of a linked list and an integer `val`, remove all the nodes of the linked list that has `Node.val == val`, and return *the new head*.

**Example 1:**

![https://assets.leetcode.com/uploads/2021/03/06/removelinked-list.jpg](https://assets.leetcode.com/uploads/2021/03/06/removelinked-list.jpg)

```
Input: head = [1,2,6,3,4,5,6], val = 6
Output: [1,2,3,4,5]
```

**Example 2:**

```
Input: head = [], val = 1
Output: []
```

**Example 3:**

```
Input: head = [7,7,7,7], val = 7
Output: []
```

**Constraints:**

- The number of nodes in the list is in the range `[0, 104]`.
- `1 <= Node.val <= 50`
- `0 <= val <= 50`

## My Solutions

---

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeElements(self, head: Optional[ListNode], val: int) -> Optional[ListNode]:

        while head and head.val == val :

            head = head.next

        current = head
        prev = None
        

        while current:

            if current.val == val:

                prev.next = current.next
                
            else :
                prev = current 
            
            current = current.next

        return head
```

```python

```

## Optimal Solutions

---

To remove all elements from a linked list that have a specific value, you need to iterate through the list, keeping track of the previous node so you can adjust pointers when a node with the target value is encountered. It's crucial to handle the cases where the nodes to be removed are at the beginning of the list, in the middle, or at the end. Here's a step-by-step approach:

### Step 1: Remove Leading Target Nodes

First, remove all nodes from the beginning of the list that need to be deleted. This is necessary because the head of the list might change if the head node(s) have the target value.

### Step 2: Remove Middle and Trailing Target Nodes

Next, iterate through the rest of the list starting from the new head, removing any nodes with the target value by adjusting the pointers of their previous nodes to skip them.

### Implementation:

Here's a concise and effective implementation:

```python
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def removeElements(self, head: ListNode, val: int) -> ListNode:
        # First, handle the case where the head needs to be removed.
        while head and head.val == val:
            head = head.next

        # 'current' will traverse the list, 'prev' will track the node before 'current'.
        current = head
        prev = None
        while current:
            if current.val == val:
                # Remove 'current' by linking 'prev.next' to 'current.next'.
                prev.next = current.next
            else:
                # 'current' has a different value, so move 'prev' forward.
                prev = current
            # Move 'current' forward in either case.
            current = current.next

        return head

```

### Explanation:

- The initial `while` loop ensures that any nodes at the start of the list that match the target value are skipped, potentially updating `head` to a new starting point.
- Within the main `while` loop, `current` points to the node being examined, and `prev` points to the node immediately before `current`.
- If `current.val` matches the target value, `prev.next` is adjusted to skip over `current`, effectively removing it from the list.
- If `current.val` does not match, `prev` is simply advanced to `current`.
- In both cases, `current` advances to the next node in the list.

### Complexity Analysis:

- **Time Complexity**: O(N), where N is the number of nodes in the linked list. Each node is examined exactly once to determine if it needs to be removed.
- **Space Complexity**: O(1), since the removal is performed in place and does not require additional space proportional to the size of the input list.

## Notes

---

 

## Related Videos

---

[https://www.notion.so](https://www.notion.so)