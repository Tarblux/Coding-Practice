# Insert Greatest Common Divisors in Linked List

Problem: 2807
Official Difficulty: medium
Feels Like : easy
My Understanding: Fully Understand
Topic: Math, linked list, number theory
Link: https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/description/
Completed On : September 9, 2024
Last Review: September 9, 2024
Days Since Review: 7

## Problem

---

Given the head of a linked list `head`, in which each node contains an integer value.

Between every pair of adjacent nodes, insert a new node with a value equal to the **greatest common divisor** of them.

Return *the linked list after insertion*.

The **greatest common divisor** of two numbers is the largest positive integer that evenly divides both numbers.

**Example 1:**

![https://assets.leetcode.com/uploads/2023/07/18/ex1_copy.png](https://assets.leetcode.com/uploads/2023/07/18/ex1_copy.png)

```
Input: head = [18,6,10,3]
Output: [18,6,6,2,10,1,3]
Explanation: The 1st diagram denotes the initial linked list and the 2nd diagram denotes the linked list after inserting the new nodes (nodes in blue are the inserted nodes).
- We insert the greatest common divisor of 18 and 6 = 6 between the 1st and the 2nd nodes.
- We insert the greatest common divisor of 6 and 10 = 2 between the 2nd and the 3rd nodes.
- We insert the greatest common divisor of 10 and 3 = 1 between the 3rd and the 4th nodes.
There are no more adjacent nodes, so we return the linked list.

```

**Example 2:**

![https://assets.leetcode.com/uploads/2023/07/18/ex2_copy1.png](https://assets.leetcode.com/uploads/2023/07/18/ex2_copy1.png)

```
Input: head = [7]
Output: [7]
Explanation: The 1st diagram denotes the initial linked list and the 2nd diagram denotes the linked list after inserting the new nodes.
There are no pairs of adjacent nodes, so we return the initial linked list.

```

**Constraints:**

- The number of nodes in the list is in the range `[1, 5000]`.
- `1 <= Node.val <= 1000`

## My Solutions

---

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:

    def gcd(self,a,b):

        while b != 0:
            a, b = b,a%b
        return a

    def insertGreatestCommonDivisors(self, head: Optional[ListNode]) -> Optional[ListNode]:

        if not head.next:
            return head

        prev = head
        current = head.next

        while current:

            gcd = self.gcd(prev.val,current.val)
            dummy = ListNode(gcd,current)

            prev.next = dummy
            prev = current
            current = current.next

        return head
```

```python

```

## Optimal Solutions

---

To implement a function that inserts the greatest common divisor (GCD) of adjacent nodes into a linked list, you'll need to modify the linked list structure as you traverse it. Let's first define the structure of a singly linked list and then provide a Python function to perform the required task.

### Defining the Linked List Node

Here’s a basic class definition for a node in a singly linked list:

```python
class ListNode:
    def __init__(self, value=0, next=None):
        self.value = value
        self.next = next

```

### Python Function to Insert GCDs

We’ll create a function to traverse the linked list, calculate the GCD of adjacent nodes, and insert this GCD value between them. We'll use the Euclidean algorithm to find the GCD:

```python
import math

def insert_gcd(head):
    def gcd(a, b):
        while b != 0:
            a, b = b, a % b
        return a

    current = head
    while current and current.next:
        # Compute GCD of current node and next node
        gcd_value = gcd(current.value, current.next.value)

        # Create a new node with the GCD value
        new_node = ListNode(gcd_value, current.next)

        # Insert the new node between current and current.next
        current.next = new_node

        # Move to the next pair (skip over the newly inserted node)
        current = new_node.next

    return head

# Helper function to print the list
def print_list(node):
    while node:
        print(node.value, end=" -> ")
        node = node.next
    print("None")

# Example usage
head = ListNode(24, ListNode(18, ListNode(12, ListNode(30))))
print("Original list:")
print_list(head)

print("Modified list with GCDs:")
head = insert_gcd(head)
print_list(head)

```

### Explanation

1. **GCD Function**: We define a helper function `gcd` using the Euclidean algorithm to find the greatest common divisor of two numbers.
2. **Traverse and Modify**: We iterate through the linked list, compute the GCD of the current node and its next node, and insert a new node with this GCD value between them.
3. **Skipping Nodes**: After inserting the GCD node, we skip to the next original node by setting `current = new_node.next` to continue the process with the next pair of original nodes.
4. **Output Functions**: `print_list` is a utility function to display the contents of the list, helping to visualize the changes.

This approach effectively transforms the linked list by inserting the GCD values where required, while maintaining the structural integrity of the list.

## Notes

---

 

## Related Videos

---

[https://www.notion.so](https://www.notion.so)