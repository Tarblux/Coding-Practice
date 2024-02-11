# Reverse Linked List

Problem: 206
Official Difficulty: easy
Feels Like : easy
Topic: linked list, recursion
Link: https://leetcode.com/problems/reverse-linked-list/
Completed On : December 29, 2023
My Understanding: Mostly Understand
Last Review: December 29, 2023
Days Since Review: 43

## Problem

---

Given the `head` of a singly linked list, reverse the list, and return *the reversed list*.

**Example 1:**

![https://assets.leetcode.com/uploads/2021/02/19/rev1ex1.jpg](https://assets.leetcode.com/uploads/2021/02/19/rev1ex1.jpg)

```
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]

```

**Example 2:**

![https://assets.leetcode.com/uploads/2021/02/19/rev1ex2.jpg](https://assets.leetcode.com/uploads/2021/02/19/rev1ex2.jpg)

```
Input: head = [1,2]
Output: [2,1]

```

**Example 3:**

```
Input: head = []
Output: []

```

**Constraints:**

- The number of nodes in the list is the range `[0, 5000]`.
- `5000 <= Node.val <= 5000`

**Follow up:** A linked list can be reversed either iteratively or recursively. Could you implement both?

## My Solutions

---

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution(object):
    def reverseList(self, head):
        
        prev = None 
        current = head
        
        while current:
            
            next_node = current.next
            
            current.next = prev
            
            prev = current
            
            current = next_node

        return prev
```

```python

```

## Optimal Solutions

---

Above is most efficient

## Notes

---

 

## Related Videos

---

[https://www.youtube.com/watch?v=G0_I-ZF0S38&pp=ygUTcmV2ZXJzZSBsaW5rZWQgbGlzdA%3D%3D](https://www.youtube.com/watch?v=G0_I-ZF0S38&pp=ygUTcmV2ZXJzZSBsaW5rZWQgbGlzdA%3D%3D)