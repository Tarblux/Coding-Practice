Problem: 1290
Official Difficulty: easy
Link: https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/description/?envType=problem-list-v2&envId=linked-list
Completed On : 2024-11-21
Feels Like : easy breazy
Topic: linked list, Math
My Understanding: Fully Understand
Last Review: 2024-11-21
Days Since Review: 3
Name: Convert Binary Number in a Linked List to Integer

# Convert Binary Number in a Linked List to Integer
### Problem
___
Given `head` which is a reference node to a singly-linked list. The value of each node in the linked list is either `0` or `1`. The linked list holds the binary representation of a number.
Return the *decimal value* of the number in the linked list.
The **most significant bit** is at the head of the linked list.
**Example 1:**
![graph-1.png](https://assets.leetcode.com/uploads/2019/12/05/graph-1.png)
```plain text
Input: head = [1,0,1]
Output: 5
Explanation: (101) in base 2 = (5) in base 10
```
**Example 2:**
```plain text
Input: head = [0]
Output: 0
```
**Constraints:**
- The Linked List is not empty.
- Number of nodes will not exceed `30`.
- Each node's value is either `0` or `1`.
### My Solutions
___
```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def getDecimalValue(self, head: Optional[ListNode]) -> int:

        number = ''
        while head:

            number += str(head.val)
            head = head.next

        return int(number,2)
        
```

Time Complexity :
```python

```

Time Complexity : 
### Optimal Solutions
___
#### **Overview**
Here we have two subproblems:
- To parse a non-empty linked list and to retrieve the digit sequence that represents a binary number.
- To convert this sequence into the number in decimal representation.
The first subproblem is easy because the linked list is guaranteed to be non-empty.
The second subproblem is to convert (101)2​ into 1×22+0×21+1×20=5. It could be solved in two ways. Using classical arithmetic is more straightforward
![try1.png](https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/Figures/1290/try1.png)
*Figure 1. Approach 1: num = num * 2 + x*
and to use bitwise operators is faster
![try2.png](https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/Figures/1290/try2.png)
*Figure 2. Approach 2: num = (num << 1) | x*
___
#### **Approach 1: Binary Representation**
![try1.png](https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/Figures/1290/try1.png)
*Figure 3. Approach 1: num = num * 2 + x.*
- Initialize the result number to be equal to the head value: `num = head.val`. This operation is safe because the list is guaranteed to be non-empty.
- Parse linked list starting from the head: `while head.next`:
	- The current value is `head.next.val`. Update the result by shifting it by one to the left and adding the current value: `num = num * 2 + head.next.val`.
- Return `num`.
**Implementation**
```python
class Solution:
    def getDecimalValue(self, head: ListNode) -> int:
        num = head.val
        while head.next:
            num = num * 2 + head.next.val
            head = head.next
        return num
```
**Complexity Analysis**
- Time complexity: O(*N*).
- Space complexity: O(1).

#### **Approach 2: Bit Manipulation**
![try2.png](https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/Figures/1290/try2.png)
*Figure 4. Approach 2: num = (num << 1) | x*
- Initialize the result number to be equal to the head value: `num = head.val`. This operation is safe because the list is guaranteed to be non-empty.
- Parse linked list starting from the head: `while head.next`:
	- The current value is `head.next.val`. Update the result by shifting it by one to the left and adding the current value using logical OR: `num = (num << 1) | head.next.val`.
- Return `num`.
**Implementation**
```python
class Solution:
    def getDecimalValue(self, head: ListNode) -> int:
        num = head.val
        while head.next:
            num = (num << 1) | head.next.val
            head = head.next
        return num
```
**Complexity Analysis**
- Time complexity: O(*N*).
- Space complexity: O(1).
### Notes
___
 
### Related Videos 
___
[]()