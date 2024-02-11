# Palindrome Linked List

Problem: 234
Official Difficulty: easy
Topic: linked list, two pointers
Link: https://leetcode.com/problems/palindrome-linked-list/
Completed On : November 30, 2023
My Understanding: Mostly Understand
Last Review: November 30, 2023
Days Since Review: 72

## Problem

---

Given the head of a singly linked list, return true if it is a palindrome.

A palindrome is a word, number, phrase, or other sequences of characters that reads the same forward and backward.

Example 1:

```vbnet
Input: head = [1,2,2,1]
Output: true
```

Example 2:

```vbnet
Input: head = [1,2]
Output: false
```

Constraints:

- The number of nodes in the list is in the range [1, 10^5].
- 0 <= Node.val <= 9

**Follow-up:**
Could you do it in O(n) time and O(1) space?

## My Solutions

---

```python
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        
        values = [] 
    
        current = head
    
        while current:
            
            values.append(current.val)
            
            current = current.next

        return values == values[::-1]
```

```python

```

## Optimal Solutions

---

```java
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        if not head or not head.next:
            return True

        # Find the middle of the linked list
        slow, fast = head, head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next

        # Reverse the second half of the linked list
        prev = None
        while slow:
            next_node = slow.next
            slow.next = prev
            prev = slow
            slow = next_node

        # Compare the reversed second half with the first half
        while prev:
            if head.val != prev.val:
                return False
            head, prev = head.next, prev.next

        return True
```

## Notes

---

 

## Related Videos

---

[https://www.youtube.com/watch?v=yOzXms1J6Nk](https://www.youtube.com/watch?v=yOzXms1J6Nk)