# Linked List Cycle

Problem: 141
Official Difficulty: easy
Feels Like : medium
Topic: linked list, two pointers
Link: https://leetcode.com/problems/linked-list-cycle/
Completed On : December 30, 2023
My Understanding: Fully Understand
Last Review: December 30, 2023
Days Since Review: 42

## Problem

---

Given `head`, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the `next` pointer. Internally, `pos` is used to denote the index of the node that tail's `next` pointer is connected to. **Note that `pos` is not passed as a parameter**.

Return `true` *if there is a cycle in the linked list*. Otherwise, return `false`.

**Example 1:**

![https://assets.leetcode.com/uploads/2018/12/07/circularlinkedlist.png](https://assets.leetcode.com/uploads/2018/12/07/circularlinkedlist.png)

```
Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).

```

**Example 2:**

![https://assets.leetcode.com/uploads/2018/12/07/circularlinkedlist_test2.png](https://assets.leetcode.com/uploads/2018/12/07/circularlinkedlist_test2.png)

```
Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.

```

**Example 3:**

![https://assets.leetcode.com/uploads/2018/12/07/circularlinkedlist_test3.png](https://assets.leetcode.com/uploads/2018/12/07/circularlinkedlist_test3.png)

```
Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.

```

**Constraints:**

- The number of the nodes in the list is in the range `[0, 104]`.
- `105 <= Node.val <= 105`
- `pos` is `1` or a **valid index** in the linked-list.

**Follow up:** Can you solve it using `O(1)` (i.e. constant) memory?

## My Solutions

---

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        
        if not head : 
            
            return False
        
        slow , fast = head , head
        
        while fast and fast.next : 
            
            slow = slow.next 
            fast  = fast.next.next
            
            if slow == fast : 
                
                return True 
        
        return False
```

surprisingly this and the one above are both correct but the condition that is checking if they are the same are above and below which is kind of weird tbh 

```python
class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:

        if not head :

            return False

        slow  = head

        fast = head.next

        while fast and fast.next : 

            if slow == fast : 

                return True

            slow = slow.next

            fast = fast.next.next

        return False
```

## Optimal Solutions

---

The optimal solution for detecting a cycle in a linked list is to use Floyd's Tortoise and Hare algorithm, which is an efficient method with a two-pointer approach. This approach involves using two pointers, commonly referred to as the "slow" and "fast" pointers, that move through the list at different speeds.

### Algorithm: Floyd's Tortoise and Hare

1. **Initialize Two Pointers**: Start with two pointers, `slow` and `fast`, both pointing to the head of the linked list.
2. **Iterate Through the List**:
    - In each step of the loop, move the `slow` pointer by one node and the `fast` pointer by two nodes.
    - If the linked list has a cycle, the `fast` pointer will eventually meet the `slow` pointer somewhere within the cycle.
3. **Check for Cycle**:
    - If at any point, `fast` or `fast.next` becomes `None`, it means the list does not have a cycle (as you've reached the end of the list).
    - If `slow` and `fast` meet (i.e., `slow == fast`), a cycle is detected.

### Python Implementation

```python
class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        if not head or not head.next:
            return False

        slow = head
        fast = head.next

        while fast != slow:
            if not fast or not fast.next:
                return False
            slow = slow.next
            fast = fast.next.next

        return True

```

### Explanation

- Both pointers start at the head of the list. The `fast` pointer moves twice as fast as the `slow` pointer.
- If there's no cycle, the `fast` pointer will reach the end of the list (`None`), and the function returns `False`.
- If there's a cycle, at some point, the `fast` pointer will catch up to the `slow` pointer, and the function returns `True`.

### Complexity Analysis

- **Time Complexity**: O(n). In the worst case, the algorithm might have to visit each node once (for a non-cyclic list) or traverse the cycle once (for a cyclic list), where `n` is the number of nodes in the list.
- **Space Complexity**: O(1). The space complexity is constant as it only uses two pointers regardless of the size of the input linked list.

This approach is the most efficient way to detect a cycle in a linked list, as it does not require any additional storage and operates in linear time.

## Notes

---

 Pay special attention to the while loop condition because the faith of the very universe depends on it. Basically just make sure that you don’t try to access a value that has a pointer of non in the while loop because that will throw an attribute error.

## Related Videos

---

[https://www.youtube.com/watch?v=gBTe7lFR3vc&pp=ygURbGlua2VkIGxpc3QgY3ljbGU%3D](https://www.youtube.com/watch?v=gBTe7lFR3vc&pp=ygURbGlua2VkIGxpc3QgY3ljbGU%3D)