# Middle of Linked List

Problem: 707
Official Difficulty: easy
Feels Like : easy
My Understanding: Mostly Understand
Topic: linked list, two pointers
Link: https://leetcode.com/problems/middle-of-the-linked-list/
Completed On : April 17, 2024
Last Review: April 17, 2024
Days Since Review: 13

## Problem

---

Given the `head` of a singly linked list, return *the middle node of the linked list*.

If there are two middle nodes, return **the second middle** node.

**Example 1:**

![https://assets.leetcode.com/uploads/2021/07/23/lc-midlist1.jpg](https://assets.leetcode.com/uploads/2021/07/23/lc-midlist1.jpg)

```
Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.
```

**Example 2:**

![https://assets.leetcode.com/uploads/2021/07/23/lc-midlist2.jpg](https://assets.leetcode.com/uploads/2021/07/23/lc-midlist2.jpg)

```
Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.
```

**Constraints:**

- The number of nodes in the list is in the range `[1, 100]`.
- `1 <= Node.val <= 100`

## My Solutions

---

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:

        current = head 
        middle = head
        length = 0

        while current:

            current = current.next
            length += 1

        for _ in range((length//2)):

            middle = middle.next

        return middle
```

```python

```

## Optimal Solutions

---

```python
class Solution:
    def middleNode(self, head):
        slow = fast = head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        return slow
```

## Notes

---

 

## Related Videos

---

[https://www.notion.so](https://www.notion.so)