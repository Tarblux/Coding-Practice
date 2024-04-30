# Remove Duplicates from Sorted List

Problem: 83
Official Difficulty: easy
Feels Like : easy
My Understanding: Mostly Understand
Topic: linked list
Link: https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/
Completed On : March 13, 2024
Last Review: March 13, 2024
Days Since Review: 48

## Problem

---

Given the `head` of a sorted linked list, *delete all duplicates such that each element appears only once*. Return *the linked list **sorted** as well*.

**Example 1:**

![https://assets.leetcode.com/uploads/2021/01/04/list1.jpg](https://assets.leetcode.com/uploads/2021/01/04/list1.jpg)

```
Input: head = [1,1,2]
Output: [1,2]

```

**Example 2:**

![https://assets.leetcode.com/uploads/2021/01/04/list2.jpg](https://assets.leetcode.com/uploads/2021/01/04/list2.jpg)

```
Input: head = [1,1,2,3,3]
Output: [1,2,3]

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

        if not head :

            return None

        current = head.next
        prev = head

        while current:

            if prev.val == current.val:
                
                prev.next = current.next
                current = current.next
            else:
                prev = current
                current = current.next

        return head

```

```python

```

## Optimal Solutions

---

To remove duplicates from a sorted linked list, you need to iterate through the list and remove any nodes that have the same value as the node immediately preceding them. This is a relatively straightforward process because the list is already sorted, meaning all duplicates are adjacent.

Here's how you could implement this in Python, assuming you have a singly linked list structure defined like so:

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
        current = head
        while current and current.next:
            if current.val == current.next.val:
                current.next = current.next.next  # Skip the duplicate
            else:
                current = current.next  # Move to the next distinct element
        return head
```

### Explanation:

- **Initialization**: Start with a pointer `current` set to the `head` of the list.
- **Traversal**: Use a `while` loop to traverse the list as long as `current` and `current.next` are not `None`. This ensures you have at least two elements to compare and that you're not at the end of the list.
- **Duplicate Check**: Within each iteration, check if the value of the current node (`current.val`) is equal to the value of the next node (`current.next.val`). If they are equal, it means there's a duplicate.
- **Removing Duplicates**: To remove a duplicate, you simply adjust the `next` pointer of the `current` node to skip the duplicate node. Specifically, set `current.next` to `current.next.next`. This effectively removes the duplicate node from the list by excluding it from the chain of `next` pointers.
- **Advancement**: If there is no duplicate (i.e., `current.val` is not equal to `current.next.val`), move the `current` pointer forward to the next node by setting `current` to `current.next`.
- **Return**: Finally, return the `head` of the modified list. Since the changes were made in place, the `head` of the list remains the same unless the list was empty or had only one element (in which case it would not have duplicates).

### Complexity Analysis:

- **Time Complexity**: O(N), where N is the number of nodes in the linked list. Each node in the list is visited once.
- **Space Complexity**: O(1), as no additional space is used proportionally to the input size. The removal of duplicates is done in place by adjusting pointers.

## Notes

---

 

## Related Videos

---

[https://www.youtube.com/watch?v=p10f-VpO4nE](https://www.youtube.com/watch?v=p10f-VpO4nE)