# Add Two Number II

Problem: 445
Official Difficulty: medium
Feels Like : easy
Topic: Math, Stack, linked list
Link: https://leetcode.com/problems/add-two-numbers-ii/description
Completed On : February 6, 2024
My Understanding: Mostly Understand
Last Review: February 6, 2024
Days Since Review: 4

## Problem

---

You are given two **non-empty**
 linked lists representing two non-negative integers. The most 
significant digit comes first and each of their nodes contains a single 
digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

**Example 1:**

![https://assets.leetcode.com/uploads/2021/04/09/sumii-linked-list.jpg](https://assets.leetcode.com/uploads/2021/04/09/sumii-linked-list.jpg)

```
Input: l1 = [7,2,4,3], l2 = [5,6,4]
Output: [7,8,0,7]
```

**Example 2:**

```
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [8,0,7]
```

**Example 3:**

```
Input: l1 = [0], l2 = [0]
Output: [0]
```

**Constraints:**

- The number of nodes in each linked list is in the range `[1, 100]`.
- `0 <= Node.val <= 9`
- It is guaranteed that the list represents a number that does not have leading zeros.

**Follow up:** Could you solve it without reversing the input lists?

## My Solutions

---

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:

    def converter(self,linked_list):

        current = linked_list 

        converted = ''

        while current : 

            converted += str(current.val)

            current = current.next

        return int(converted)

    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:

        addition = str(self.converter(l1) + self.converter(l2))

        l3 = ListNode()

        current = l3

        for i in range(len(addition)): 

            temp = ListNode(val = addition[i])

            current.next = temp 

            current = current.next

        return l3.next
```

```python

```

## Optimal Solutions

---

### Solution Approach

1. **Reverse Both Lists**: Since the numbers are given in forward order, and adding numbers from least significant digit to most significant is easier, we first reverse both lists.
2. **Add Numbers**: Traverse both reversed lists, adding corresponding digits.
3. **Carry Handling**: If the sum of two digits is greater than 9, handle the carry.
4. **Form Result List**: Create new nodes for each sum digit.
5. **Reverse Result List**: Since the sum has been formed in reverse order, reverse it to match the problem's required order.

### Python Implementation

Assuming the definition of the ListNode is:

```python
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

```

Here is how you could implement the solution:

```python
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        # Helper function to reverse a linked list
        def reverseList(head):
            prev = None
            current = head
            while current:
                nxt = current.next
                current.next = prev
                prev = current
                current = nxt
            return prev

        # Reverse both lists
        l1 = reverseList(l1)
        l2 = reverseList(l2)

        # Add numbers
        carry = 0
        dummyHead = ListNode(0)
        current = dummyHead
        while l1 or l2 or carry:
            val1 = (l1.val if l1 else 0)
            val2 = (l2.val if l2 else 0)
            total = val1 + val2 + carry

            carry = total // 10
            total = total % 10

            current.next = ListNode(total)
            current = current.next

            if l1:
                l1 = l1.next
            if l2:
                l2 = l2.next

        # Reverse the result list to get the final sum
        return reverseList(dummyHead.next)

```

### Explanation

- **reverseList**: This helper function reverses a linked list.
- **Adding Numbers**: After reversing `l1` and `l2`, we iterate through them, adding corresponding digits along with any carry from the previous addition.
- **Carry**: If the sum of two digits plus any carry is greater than 9, we calculate the new carry for the next addition.
- **Dummy Head**: A dummy head node is used to simplify edge cases, particularly when the result list is initially empty.
- **Result List**: The result of the sum is initially in reverse order due to the method of addition, so we reverse it before returning.

### Complexity Analysis

- **Time Complexity**: O(max(n, m)), where n and m are the lengths of the two input lists. This is due to the need to traverse both input lists fully.
- **Space Complexity**: O(max(n, m)) for the new list. The space used by the reverse function is O(1), but creating a new list for the result increases the space complexity.

## Notes

---

 Keep an eye on the line with `addition = str(self.converter(l1) + self.converter(l2))` , this was done because an integer is not iterable so we can’t do a for each loop to step through it so we convert it to a string and get the length and do a for index loop

## Related Videos

---

[https://www.notion.so](https://www.notion.so)