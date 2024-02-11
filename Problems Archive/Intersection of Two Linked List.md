# Intersection of Two Linked List

Problem: 160
Official Difficulty: easy
Feels Like : easy
Topic: hash table, linked list, two pointers
Link: https://leetcode.com/problems/intersection-of-two-linked-lists/description/
Completed On : January 14, 2024
My Understanding: Mostly Understand
Last Review: January 14, 2024
Days Since Review: 27

## Problem

---

Given the heads of two singly linked-lists `headA` and `headB`, return *the node at which the two lists intersect*. If the two linked lists have no intersection at all, return `null`.

For example, the following two linked lists begin to intersect at node `c1`:

![https://assets.leetcode.com/uploads/2021/03/05/160_statement.png](https://assets.leetcode.com/uploads/2021/03/05/160_statement.png)

The test cases are generated such that there are no cycles anywhere in the entire linked structure.

**Note** that the linked lists must **retain their original structure** after the function returns.

**Custom Judge:**

The inputs to the **judge** are given as follows (your program is **not** given these inputs):

- `intersectVal` - The value of the node where the intersection occurs. This is `0` if there is no intersected node.
- `listA` - The first linked list.
- `listB` - The second linked list.
- `skipA` - The number of nodes to skip ahead in `listA` (starting from the head) to get to the intersected node.
- `skipB` - The number of nodes to skip ahead in `listB` (starting from the head) to get to the intersected node.

The judge will then create the linked structure based on these inputs and pass the two heads, `headA` and `headB` to your program. If you correctly return the intersected node, then your solution will be **accepted**.

**Example 1:**

![https://assets.leetcode.com/uploads/2021/03/05/160_example_1_1.png](https://assets.leetcode.com/uploads/2021/03/05/160_example_1_1.png)

```
Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
Output: Intersected at '8'
Explanation: The intersected node's value is 8 (note that this must not be 0 if the two lists intersect).
From the head of A, it reads as [4,1,8,4,5]. From the head of B, it reads as [5,6,1,8,4,5]. There are 2 nodes before the intersected node in A; There are 3 nodes before the intersected node in B.
- Note that the intersected node's value is not 1 because the nodes with value 1 in A and B (2nd node in A and 3rd node in B) are different node references. In other words, they point to two different locations in memory, while the nodes with value 8 in A and B (3rd node in A and 4th node in B) point to the same location in memory.
```

**Example 2:**

![https://assets.leetcode.com/uploads/2021/03/05/160_example_2.png](https://assets.leetcode.com/uploads/2021/03/05/160_example_2.png)

```
Input: intersectVal = 2, listA = [1,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
Output: Intersected at '2'
Explanation: The intersected node's value is 2 (note that this must not be 0 if the two lists intersect).
From the head of A, it reads as [1,9,1,2,4]. From the head of B, it reads as [3,2,4]. There are 3 nodes before the intersected node in A; There are 1 node before the intersected node in B.
```

**Example 3:**

![https://assets.leetcode.com/uploads/2021/03/05/160_example_3.png](https://assets.leetcode.com/uploads/2021/03/05/160_example_3.png)

```
Input: intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
Output: No intersection
Explanation: From the head of A, it reads as [2,6,4]. From the head of B, it reads as [1,5]. Since the two lists do not intersect, intersectVal must be 0, while skipA and skipB can be arbitrary values.
Explanation: The two lists do not intersect, so return null.

```

**Constraints:**

- The number of nodes of `listA` is in the `m`.
- The number of nodes of `listB` is in the `n`.
- `1 <= m, n <= 3 * 104`
- `1 <= Node.val <= 105`
- `0 <= skipA < m`
- `0 <= skipB < n`
- `intersectVal` is `0` if `listA` and `listB` do not intersect.
- `intersectVal == listA[skipA] == listB[skipB]` if `listA` and `listB` intersect.

**Follow up:**

Could you write a solution that runs in O(m + n) time and use only O(1) memory?

## My Solutions

---

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:

        curA = headA
        curB = headB

        dict = {}

        while curA : 

            if curA not in dict : 

                dict[curA] = True 

            curA = curA.next

        while curB : 

            if curB in dict : 

                return curB

            curB = curB.next

        return None
```

```python

```

## Optimal Solutions

---

The "Intersection of Two Linked Lists" problem asks to find the node at which the intersection of two singly linked lists begins. It's assumed that there are no cycles anywhere in the entire linked structure and that the lists may intersect at some point.

### Problem Statement

Given the heads of two singly linked lists `headA` and `headB`, return the node where the two lists intersect. If the two linked lists have no intersection, return `null`.

### Solution Approach: Two Pointers

A very efficient solution to this problem uses two pointers. The key idea is to have two pointers traverse through the lists, and when they reach the end, switch them to the head of the other list. If the lists intersect, the pointers will meet at the intersection node; otherwise, they will both reach the end (`null`).

### Python Implementation

Assuming the definition of a ListNode is given as:

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
```

Here's the implementation:

```python
class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        if not headA or not headB:
            return None

        pointerA, pointerB = headA, headB

        while pointerA != pointerB:
            pointerA = pointerA.next if pointerA else headB
            pointerB = pointerB.next if pointerB else headA

        return pointerA
```

### Explanation

- Initialize two pointers, `pointerA` and `pointerB`, at the heads of `headA` and `headB`, respectively.
- Traverse through the lists. If either pointer reaches the end, switch it to the head of the other list.
- If the lists intersect, `pointerA` and `pointerB` will meet at the intersection node. Otherwise, they will both eventually reach `null`.

### Complexity Analysis

- **Time Complexity**: O(m + n), where `m` and `n` are the lengths of the two linked lists. Each list is traversed at most twice.
- **Space Complexity**: O(1), as no extra space is used beyond the two pointers.

This two-pointer approach effectively solves the problem without needing extra space or complex calculations. The pointers either meet at the intersection node or at the end (`null`), allowing us to determine whether an intersection exists and, if so, where it is.

## Notes

---

 

## Related Videos

---

[https://www.youtube.com/watch?v=D0X0BONOQhI](https://www.youtube.com/watch?v=D0X0BONOQhI)