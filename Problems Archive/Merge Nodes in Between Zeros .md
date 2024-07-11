# Merge Nodes in Between Zeros

Problem: 2181
Official Difficulty: medium
Feels Like : easy
My Understanding: Mostly Understand
Topic: linked list, simulation
Link: https://leetcode.com/problems/merge-nodes-in-between-zeros/description/?envType=daily-question&envId=2024-07-04
Completed On : July 4, 2024
Last Review: July 4, 2024
Days Since Review: 7

## Problem

---

You are given the `head` of a linked list, which contains a series of integers **separated** by `0`'s. The **beginning** and **end** of the linked list will have `Node.val == 0`.

For **every** two consecutive `0`'s, **merge** all the nodes lying in between them into a single node whose value is the **sum** of all the merged nodes. The modified list should not contain any `0`'s.

Return *the* `head` *of the modified linked list*.

**Example 1:**

![https://assets.leetcode.com/uploads/2022/02/02/ex1-1.png](https://assets.leetcode.com/uploads/2022/02/02/ex1-1.png)

```
Input: head = [0,3,1,0,4,5,2,0]
Output: [4,11]
Explanation:
The above figure represents the given linked list. The modified list contains
- The sum of the nodes marked in green: 3 + 1 = 4.
- The sum of the nodes marked in red: 4 + 5 + 2 = 11.

```

**Example 2:**

![https://assets.leetcode.com/uploads/2022/02/02/ex2-1.png](https://assets.leetcode.com/uploads/2022/02/02/ex2-1.png)

```
Input: head = [0,1,0,3,0,2,2,0]
Output: [1,3,4]
Explanation:
The above figure represents the given linked list. The modified list contains
- The sum of the nodes marked in green: 1 = 1.
- The sum of the nodes marked in red: 3 = 3.
- The sum of the nodes marked in yellow: 2 + 2 = 4.

```

**Constraints:**

- The number of nodes in the list is in the range `[3, 2 * 105]`.
- `0 <= Node.val <= 1000`
- There are **no** two consecutive nodes with `Node.val == 0`.
- The **beginning** and **end** of the linked list have `Node.val == 0`.

## My Solutions

---

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:

        current = head.next
        cur_sum = 0
        dummy = ListNode()
        output = dummy

        while current:

            if current.val == 0:
                new_node = ListNode(cur_sum , None)
                dummy.next = new_node
                dummy = dummy.next
                cur_sum = 0
            else :
                cur_sum += current.val
    
            current = current.next

        return output.next
```

**Recursive Solution by Aleksandr :**

**Time Complexity:** O(n)  |  **Space Complexity:** O(n)

We can also approach the problem recursively by breaking it into fragments, where we find the sum of values between `0`-valued nodes. In our design, we can guarantee that the head is either `0` or `None`. We modify the head’s value to store the sum and recursively process the list from the next `0`-valued node.

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
 
        if not head:
            return None
        
        node = head.next
        node_sum = 0
        while node and node.val != 0:
            node_sum += node.val
            node = node.next
 
        head.val = node_sum
        head.next = self.mergeNodes(node)
 
        return head.next if head.val == 0 else head
```

**IN-PLACE SOLUTION**

```python
from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def mergeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
        cur = head  # Initialize cur to the head of the linked list

        while cur.next:  # Iterate through the linked list
            node = cur.next  # Set node to the next node after cur (first node in the segment)
            cur = cur.next  # Move cur to the next node (start of the segment)

            while cur.next.val != 0:  # Sum values in the current segment until a zero is encountered
                node.val += cur.next.val  # Add the value of the next node to node.val
                cur = cur.next  # Move cur to the next node

            cur = cur.next  # Skip the zero node
            node.next = cur.next  # Link the node with the summed value to the next segment

        return head.next  # Return the modified list starting from head.next

# Helper function to create a linked list from a list
def create_linked_list(values):
    dummy = ListNode()
    current = dummy
    for value in values:
        current.next = ListNode(value)
        current = current.next
    return dummy.next

# Helper function to print linked list values
def print_linked_list(node):
    values = []
    while node:
        values.append(node.val)
        node = node.next
    print(values)

# Example usage
head = create_linked_list([0,3,1,0,4,5,2,0])
sol = Solution()
result = sol.mergeNodes(head)
print_linked_list(result)  # Output: [4, 11]

```

### Explanation

1. **Initialization**:
    - The function `mergeNodes` takes a `head` of a linked list as input and initializes a pointer `cur` to the `head`.
2. **Outer While Loop**:
    - The outer `while` loop iterates through the linked list as long as `cur.next` is not `None`.
    - Within the loop, `node` is set to `cur.next` (the first node in the segment to be summed).
    - `cur` is then moved to `cur.next`.
3. **Inner While Loop**:
    - The inner `while` loop continues as long as the value of `cur.next` is not zero. This loop is used to sum the values of the nodes in the current segment.
    - For each node in the segment, the value of `cur.next.val` is added to `node.val`.
    - The `cur` pointer is then moved to `cur.next`.
4. **Linking the Summed Node**:
    - After exiting the inner while loop (when a zero is encountered), `cur` is moved to `cur.next` to skip the zero.
    - The `next` pointer of the `node` (which holds the summed value) is set to `cur.next`, effectively skipping over all the nodes that were summed and linking directly to the next segment.
5. **Returning the Result**:
    - Finally, the modified list starting from `head.next` is returned. This skips the initial zero node.

### Time Complexity Analysis

- **Time Complexity**: `O(n)` where `n` is the number of nodes in the linked list. Each node is visited exactly once.
- **Space Complexity**: `O(1)` as no additional space proportional to the input size is used.

This solution efficiently merges nodes between zeros, maintaining the desired properties of the linked list.

## Optimal Solutions

---

### Problem Description

Given the head of a linked list where each node's value is either `0` or a positive integer, we need to merge nodes in between zeros. For this task, the linked list has the following special format:

- The first node is always a zero, indicating the start.
- Consecutive nodes up until the next zero are considered a segment.
- Each segment should be merged by summing all values between two zero nodes, and the segment is replaced by a single node containing this sum.

After merging all nodes between zeros, return the head of the modified linked list.

### Example

```python
Input: head = [0,3,1,0,4,5,2,0]
Output: [4,11]

Input: head = [0,1,0,3,0,2,2,0]
Output: [1,3,4]

```

### Explanation

For each segment between two zeros, sum the values and replace the segment with a single node having that sum. Continue this process for the entire linked list.

### Solution Approach - Two Pointer Technique

The idea is to use two pointers, `start` and `end`, to traverse the linked list. The `start` pointer points to the zero at the beginning of each segment, and `end` moves to find the next zero. The values between these pointers are summed, and the nodes between them are replaced by a single node with the sum value.

### Python Code

```python
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def mergeNodes(self, head: ListNode) -> ListNode:
        dummy = ListNode()  # Create a dummy node to handle edge cases easily
        tail = dummy  # This will be the tail of our resulting linked list

        current = head.next  # Start with the first node after the initial zero
        current_sum = 0  # To store the sum of nodes between zeros

        while current:
            if current.val == 0:
                if current_sum > 0:  # If there's a non-zero sum, create a new node
                    tail.next = ListNode(current_sum)
                    tail = tail.next  # Move the tail to the new node
                    current_sum = 0  # Reset the sum
            else:
                current_sum += current.val  # Add the current value to the sum

            current = current.next  # Move to the next node

        return dummy.next  # The first node of the modified list

# Helper function to create a linked list from a list
def create_linked_list(values):
    dummy = ListNode()
    current = dummy
    for value in values:
        current.next = ListNode(value)
        current = current.next
    return dummy.next

# Helper function to print linked list values
def print_linked_list(node):
    values = []
    while node:
        values.append(node.val)
        node = node.next
    print(values)

# Example usage
head = create_linked_list([0,3,1,0,4,5,2,0])
sol = Solution()
result = sol.mergeNodes(head)
print_linked_list(result)  # Output: [4, 11]

```

### Explanation

1. **Initialization**:
    - A dummy node is created to simplify edge case management, and a `tail` pointer is used to build the result linked list.
2. **Traversal and Summation**:
    - Traverse the list starting after the first zero.
    - Sum values until another zero is encountered.
    - If a zero is found and there is a non-zero sum, create a new node with that sum and add it to the result list.
    - Reset the sum and continue.
3. **Result Construction**:
    - Return the linked list starting after the dummy node, which contains the sums between zeros.

### Time Complexity Analysis

- **Time Complexity**: `O(n)`
    - The list is traversed once, where `n` is the number of nodes in the linked list.

### Space Complexity Analysis

- **Space Complexity**: `O(m)`
    - A new list is created where `m` is the number of segments between zeros. In the worst case, this could be `O(n)` if all values are zero except the segments.

## Notes

---

 

## Related Videos

---

[https://youtu.be/jrSav7fulJY](https://youtu.be/jrSav7fulJY)