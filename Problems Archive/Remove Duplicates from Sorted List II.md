# Remove Duplicates from Sorted List II

Problem: 82
Official Difficulty: medium
Feels Like : medium
My Understanding: Mostly Understand, Needs Review
Topic: linked list, two pointers
Link: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/
Completed On : March 13, 2024
Last Review: March 13, 2024
Days Since Review: 48

## Problem

---

Given the `head` of a sorted linked list, *delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list*. Return *the linked list **sorted** as well*.

**Example 1:**

![https://assets.leetcode.com/uploads/2021/01/04/linkedlist1.jpg](https://assets.leetcode.com/uploads/2021/01/04/linkedlist1.jpg)

```
Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]
```

**Example 2:**

![https://assets.leetcode.com/uploads/2021/01/04/linkedlist2.jpg](https://assets.leetcode.com/uploads/2021/01/04/linkedlist2.jpg)

```
Input: head = [1,1,1,2,3]
Output: [2,3]
```

**Constraints:**

- The number of nodes in the list is in the range `[0, 300]`.
- `100 <= Node.val <= 100`
- The list is guaranteed to be **sorted** in ascending order.

## My Solutions

---

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:

        current = head 
        vals = set()
        dupes = set()
        
        while current:

            if current.val in vals:
                dupes.add(current.val)
            vals.add(current.val)
            current = current.next

        while head and head.val in dupes:
            head = head.next

        if not head : 
            return None
        
        cur = head.next
        prev = head

        while cur:

            if cur.val in dupes :
                prev.next = cur.next
                cur = cur.next
            else:
                prev = cur
                cur = cur.next

        return head
```

```python

```

## Optimal Solutions

---

To remove duplicates from a sorted linked list such that all elements that appear more than once are removed, leaving only distinct elements, you need to adjust your approach to handle nodes with duplicate values differently. You cannot simply skip over duplicates; you need to remove all occurrences of a value if it appears more than once.

Here's how you could implement this in Python, given the same definition for a singly linked list node:

```python
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
```

### Implementation:

```python
class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        # Initialize a dummy node with next pointing to head and a prev pointer to track the last node of the distinct elements
        dummy = ListNode(0, head)
        prev = dummy

        while head:
            # If it's a start of duplicates sublist
            # skip all duplicates
            if head.next and head.val == head.next.val:
                # Move head to the end of duplicates sublist
                while head.next and head.val == head.next.val:
                    head = head.next
                # Skip all duplicates
                prev.next = head.next
            else:
                # Otherwise, move prev
                prev = prev.next

            # Move head
            head = head.next

        return dummy.next
```

### Explanation:

1. **Dummy Head**: A dummy node is used to simplify edge cases, such as removing the first list node. It points to the head of the list initially.
2. **Prev Pointer**: `prev` is used to keep track of the last node before the duplicate sequences start or the last confirmed unique node.
3. **Traverse and Detect Duplicates**: Iterate through the list with `head`. If `head` and its next node have the same value, it's the start of a duplicates sequence. Continue moving `head` to skip all duplicates.
4. **Removing Duplicates**: After skipping duplicates, connect `prev.next` to `head.next`, effectively removing the duplicates from the list.
5. **Moving Forward**: If no duplicates were found for the current node, move `prev` to `head` because the current node is confirmed to be unique. Regardless, move `head` to the next node in each iteration.
6. **Return**: Return `dummy.next`, which points to the head of the modified list.

### Complexity Analysis:

- **Time Complexity**: O(N), where N is the number of nodes in the linked list. Each node is visited at most twice — once by the inner while loop for detecting duplicates and once by the outer while loop for advancing the `head`.
- **Space Complexity**: O(1), since no extra space is used proportional to the list's size. The modifications are performed in place.

## Notes

---

 

## Related Videos

---

[https://www.youtube.com/watch?v=82A7Je0dHFA](https://www.youtube.com/watch?v=82A7Je0dHFA)