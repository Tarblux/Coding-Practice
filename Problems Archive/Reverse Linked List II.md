# Reverse Linked List II

Problem: 92
Official Difficulty: medium
Feels Like : medium
My Understanding: Mostly Understand
Topic: linked list
Link: https://leetcode.com/problems/reverse-linked-list-ii/description/
Completed On : April 3, 2024
Last Review: April 3, 2024
Days Since Review: 27

## Problem

---

Given the `head` of a singly linked list and two integers `left` and `right` where `left <= right`, reverse the nodes of the list from position `left` to position `right`, and return *the reversed list*.

**Example 1:**

![https://assets.leetcode.com/uploads/2021/02/19/rev2ex2.jpg](https://assets.leetcode.com/uploads/2021/02/19/rev2ex2.jpg)

```
Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]
```

**Example 2:**

```
Input: head = [5], left = 1, right = 1
Output: [5]
```

**Constraints:**

- The number of nodes in the list is `n`.
- `1 <= n <= 500`
- `500 <= Node.val <= 500`
- `1 <= left <= right <= n`

**Follow up:**

Could you do it in one pass?

## My Solutions

---

```python
class Solution:
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:

        if not head or left == right:
            return head

        current = head
        prev = None
        i = 1

        while i < left:
            prev = current
            current = current.next
            i += 1

        last_node_before_left = prev
        last_reversed_node = current

        while i <= right:

            temp = current.next
            current.next = prev
            prev = current
            current = temp
            i += 1

        # if left == 1 and right == i :

        #     return prev

        if last_node_before_left:
            last_node_before_left.next = prev
        else:
            head = prev  

        last_reversed_node.next = current

        return head

```

```python

```

## Optimal Solutions

---

To reverse a portion of a singly linked list from position `left` to `right`, you can follow a precise set of steps to isolate the segment to be reversed and then carefully reconnect the reversed segment with the rest of the list. Below is a step-by-step guide and implementation for reversing a sublist within a linked list, considering 1-based indexing for positions `left` and `right`.

### Implementation:

```python
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def reverseBetween(self, head: ListNode, left: int, right: int) -> ListNode:
        if not head or left == right:
            return head

        # Initialize dummy node and set it to point to the head of the list
        dummy = ListNode(0)
        dummy.next = head
        prev = dummy

        # Move 'prev' to the node just before 'left'
        for _ in range(left - 1):
            prev = prev.next

        # Start reversing from 'left' to 'right'
        # 'current' points to the current node to be reversed
        current = prev.next
        # 'next' will temporarily store the next node to reverse
        next = None

        # Perform the actual reversal
        for _ in range(right - left + 1):
            next = current.next
            current.next = next.next
            next.next = prev.next
            prev.next = next

        return dummy.next

```

### Step-by-Step Explanation:

1. **Handle Edge Cases**: If the head is `None` or `left` equals `right`, there's no need to do anything. Simply return the head.
2. **Initialize a Dummy Node**: A dummy node is helpful for simplifying edge cases, especially when the reversal starts from the head. It also ensures that we always have a non-null node pointing to the head of the list, making it easier to return the modified list at the end.
3. **Find the Node Before `left`**: Traverse the list to find the node right before the start of the segment to be reversed (`left`). This node is important because its `next` pointer will need to be adjusted after the reversal.
4. **Reverse the Segment**: To reverse the segment between `left` and `right`, iteratively adjust the pointers within this sublist. During each iteration of the reversal:
    - Temporarily store the next node (`next`) to be processed.
    - Adjust the `next` pointer of the current node to point to the node following `next`.
    - Move the node pointed to by `next` to the front of the segment being reversed.
    - Update `prev`'s `next` pointer to point to `next`, effectively moving `next` to the front of the sublist.
5. **Reconnect the Reversed Segment**: The loop handles reconnecting the reversed segment with the rest of the list automatically. The `prev` node's `next` pointer correctly points to the new head of the reversed segment, and the original head of the segment (`prev.next` before the reversal) now correctly points to the node following the reversed segment.
6. **Return the New Head**: Finally, return `dummy.next`, which points to the head of the potentially modified list.

This solution methodically reverses a specified segment of the list and handles reconnections in a way that preserves the overall structure of the list outside the reversed segment.

## Notes

---

 

## Related Videos

---

[https://www.notion.so](https://www.notion.so)