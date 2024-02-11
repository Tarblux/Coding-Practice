# Add Two Numbers

Problem: 2
Official Difficulty: medium
Feels Like : medium
Topic: Math, linked list, recursion
Link: https://leetcode.com/problems/add-two-numbers/description/
Completed On : January 12, 2024
My Understanding: Needs Review
Last Review: January 12, 2024
Days Since Review: 29

## Problem

---

You are given two **non-empty** linked lists representing two non-negative integers. The digits are stored in **reverse order**, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

**Example 1:**

![https://assets.leetcode.com/uploads/2020/10/02/addtwonumber1.jpg](https://assets.leetcode.com/uploads/2020/10/02/addtwonumber1.jpg)

```
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
```

**Example 2:**

```
Input: l1 = [0], l2 = [0]
Output: [0]
```

**Example 3:**

```
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
```

**Constraints:**

- The number of nodes in each linked list is in the range `[1, 100]`.
- `0 <= Node.val <= 9`
- It is guaranteed that the list represents a number that does not have leading zeros.

## My Solutions

---

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        
        l3 = ListNode()
        
        l1_array , l2_array = [] , []
        
        
        def convert (linkedlist):
            
            string = ''
            
            while linkedlist : 
                
                string += str(linkedlist.val)
                
                linkedlist = linkedlist.next
                
            return int(string[::-1])
        
        added = convert(l1) + convert(l2)
        
        added = str(added)
        
        cur = l3
        
        for i in range (len(added)-1 , -1 , -1) :
            
            temp = ListNode(val = added[i])
            
            l3.next = temp
            
            l3 = l3.next
            

        return cur.next
```

```python

```

## Optimal Solutions

---

"Add Two Numbers" is a common algorithm problem, often involving linked lists. In this problem, you're given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. You're asked to add the two numbers and return the sum as a linked list.

### Problem Statement

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each node contains a single digit. Add the two numbers and return the sum as a linked list.

### Solution Approach

The idea is to traverse both linked lists and keep track of the carry from each sum. A new linked list is created to store the result.

### Python Implementation

Suppose the linked list node is defined as follows:

```python
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
```

Here's how you might implement the solution:

```python
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        dummy_head = ListNode(0)
        current = dummy_head
        carry = 0

        while l1 or l2 or carry:
            val1 = (l1.val if l1 else 0)
            val2 = (l2.val if l2 else 0)
            carry, out = divmod(val1 + val2 + carry, 10)

            current.next = ListNode(out)
            current = current.next

            if l1:
                l1 = l1.next
            if l2:
                l2 = l2.next

        return dummy_head.next
```

### Explanation

- Initialize a dummy head for the result linked list.
- Use a variable `carry` to keep track of the carry from each digit addition.
- Iterate through both linked lists (`l1` and `l2`), adding corresponding digits along with the `carry`.
- The `divmod` function is used to split the sum into the next `carry` and the digit to store in the current node.
- Advance the pointers in `l1` and `l2` as well as the current pointer in the result linked list.
- Continue the process until both `l1` and `l2` have been fully traversed and there's no carry left.
- Return the next node of dummy head which points to the start of the actual result linked list.

### Complexity Analysis

- **Time Complexity**: O(max(n, m)), where `n` and `m` are the lengths of `l1` and `l2`. Each list is traversed at most once.
- **Space Complexity**: O(max(n, m)), as a new linked list is created to store the result. The length of the result list is at most max(n, m) + 1.

This solution efficiently adds the two numbers represented by the linked lists, handling carry and different lengths of input lists.

## Notes

---

 

## Related Videos

---

[https://www.youtube.com/watch?v=wgFPrzTjm7s&pp=ygUfYWRkIHR3byBudW1iZXJzIGxlZXRjb2RlIHB5dGhvbg%3D%3D](https://www.youtube.com/watch?v=wgFPrzTjm7s&pp=ygUfYWRkIHR3byBudW1iZXJzIGxlZXRjb2RlIHB5dGhvbg%3D%3D)