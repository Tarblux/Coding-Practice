# Merge Two Sorted Linked Lists

Problem: 21
Official Difficulty: easy
Feels Like : medium
Topic: linked list, recursion
Link: https://leetcode.com/problems/merge-two-sorted-lists/
Completed On : December 29, 2023
My Understanding: I Have No Idea
Last Review: December 29, 2023
Days Since Review: 43

## Problem

---

You are given the heads of two sorted linked lists `list1` and `list2`.

Merge the two lists into one **sorted** list. The list should be made by splicing together the nodes of the first two lists.

Return *the head of the merged linked list*.

**Example 1:**

![https://assets.leetcode.com/uploads/2020/10/03/merge_ex1.jpg](https://assets.leetcode.com/uploads/2020/10/03/merge_ex1.jpg)

```
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]

```

**Example 2:**

```
Input: list1 = [], list2 = []
Output: []

```

**Example 3:**

```
Input: list1 = [], list2 = [0]
Output: [0]

```

**Constraints:**

- The number of nodes in both lists is in the range `[0, 50]`.
- `100 <= Node.val <= 100`
- Both `list1` and `list2` are sorted in **non-decreasing** order.

## My Solutions

---

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        
        
         # list1 = [1,2,4], list2 = [2,5,7,8]

        if not list1 : 

            return list2

        if not list2 : 

            return list1
       
        list3 = ListNode()
    
        current = list3
        
        
        while ( list1 or list2 ) :

            if list1 == None : 
                
                current.next = list2
                
                break
            
            if list2 == None : 
                
                current.next = list1
                
                break
        
            if list1.val < list2.val  : 
                
                current.next = list1
                current = current.next
                list1 = list1.next
            
            else : 
                
                current.next = list2 
                current = current.next
                list2 = list2.next
          
        return list3.next
```

### Sanya

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:

        newList = ListNode()
        node = newList

        while (list1 and list2):
  
            if list1.val < list2.val:
                node.next = list1
                list1 = list1.next
            else:
                node.next = list2
                list2 = list2.next

            node = node.next

        if list1 == None:
            node.next = list2    
        else:
            node.next = list1
                
        return newList.next
```

## Optimal Solutions

---

The most optimal solution for merging two sorted linked lists is the iterative approach. This approach has a time complexity of O(n), where n is the total number of nodes in the merged list, and it uses constant extra space.

Here's an example of the iterative solution in Python:

```python
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def mergeTwoLists(self, l1, l2):
        dummy = ListNode()
        current = dummy

        while l1 and l2:
            if l1.val < l2.val:
                current.next = l1
                l1 = l1.next
            else:
                current.next = l2
                l2 = l2.next
            current = current.next

        # If one of the lists is not empty, append the remaining nodes
        if l1:
            current.next = l1
        elif l2:
            current.next = l2

        return dummy.next

```

This solution maintains a dummy node to simplify the code. It iterates through both lists, comparing the values of the current nodes, and appends the smaller node to the merged list. Finally, it appends the remaining nodes if one of the lists is not empty.

## Notes

---

 Maddest Lyphe

## Related Videos

---

[https://www.youtube.com/watch?v=XIdigk956u0](https://www.youtube.com/watch?v=XIdigk956u0)