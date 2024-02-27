# Swapping Nodes in a Linked List

Problem: 1721
Official Difficulty: medium
My Understanding: Fully Understand
Feels Like : easy
Topic: linked list, two pointers
Link: https://leetcode.com/problems/swapping-nodes-in-a-linked-list/description/
Completed On : February 21, 2024
Last Review: February 21, 2024
Days Since Review: 5

## Problem

---

You are given the `head` of a linked list, and an integer `k`.

Return *the head of the linked list after **swapping** the values of the* `kth` *node from the beginning and the* `kth` *node from the end (the list is **1-indexed**).*

**Example 1:**

![https://assets.leetcode.com/uploads/2020/09/21/linked1.jpg](https://assets.leetcode.com/uploads/2020/09/21/linked1.jpg)

```
Input: head = [1,2,3,4,5], k = 2
Output: [1,4,3,2,5]
```

**Example 2:**

```
Input: head = [7,9,6,6,7,8,3,0,9,5], k = 5
Output: [7,9,6,6,8,7,3,0,9,5]
```

**Constraints:**

- The number of nodes in the list is `n`.
- `1 <= k <= n <= 105`
- `0 <= Node.val <= 100`

## My Solutions

---

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapNodes(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:

        array = []

        current = head

        current_2 = head

        while current : 

            array.append(current.val)

            current = current.next

        array[k-1] , array[-k] = array[-k] , array[k-1]

        print(array)

        for val in array : 

            current_2.val = val

            current_2 = current_2.next

        return head
```

```python

```

## Optimal Solutions

---

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapNodes(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        
        # Initialize two pointers for finding the k-th node from the start and end.
        first = last = head
        fast = slow = head

        # Move fast pointer k-1 steps ahead
        for _ in range(k - 1):
            fast = fast.next

        # Mark the k-th node from the beginning
        first = fast

        # Move fast to the end to find the k-th node from the end
        while fast.next:
            slow = slow.next
            fast = fast.next

        # Slow is now at the k-th node from the end
        last = slow

        # Swap values
        first.val, last.val = last.val, first.val

        return head
```

This solution to the "Swapping Nodes in a Linked List" problem swaps the values of the k-th nodes from the beginning and the end of a singly linked list, rather than swapping the nodes themselves. Here's a breakdown of how it works:

### Steps in the Solution

1. **Initialize Pointers**: The solution starts with two pointers, `first` and `last`, both initially pointing to the head of the list. Additionally, it uses `fast` and `slow` pointers to help find the nodes to swap.
2. **Move `fast` Pointer**: The `fast` pointer is moved `k-1` steps forward from the head. This is because we're counting steps, not nodes, and moving `k-1` steps forward positions the `fast` pointer on the k-th node from the start.
3. **Mark the k-th Node from the Beginning**: After moving the `fast` pointer, it now points to the k-th node from the beginning of the list. This node is marked by assigning `fast` to `first`.
4. **Find the k-th Node from the End**: To find the k-th node from the end, the algorithm continues moving `fast` towards the end of the list, but now also moves `slow` from the head at the same pace as `fast`. Since `fast` already has a head start of `k-1` nodes, when `fast` reaches the end of the list, `slow` will be at the k-th node from the end. This works because the distance between `slow` and the end of the list (traversed by `fast`) is the same as the distance from the head to the k-th node from the end.
5. **Swap Values**: With `first` pointing to the k-th node from the start and `slow` (now assigned to `last`) pointing to the k-th node from the end, the solution swaps the values of these two nodes. It's important to note that it's the values that are being swapped, not the nodes themselves. This distinction is critical in understanding that the structure of the list remains unchanged; only the data within the nodes is swapped.
6. **Return the Modified List**: Finally, the head of the modified list is returned, reflecting the swaps made.

### Example

Consider a list `[1, 2, 3, 4, 5]` with `k = 2`. The k-th node from the start is `2`, and the k-th node from the end is `4`. Following the algorithm:

- `fast` moves to `2` (`k-1` steps).
- `first` is marked at `2`.
- `fast` proceeds to the end while `slow` starts moving. When `fast` reaches `5`, `slow` is at `4`.
- The values at `first` (2) and `last` (4) are swapped, resulting in `[1, 4, 3, 2, 5]`.

### Complexity Analysis

- **Time Complexity**: O(N), where N is the length of the linked list. The list is traversed twice at most: once to find the k-th node from the start and to position `fast` at the end, and once to move `slow` to the k-th node from the end.
- **Space Complexity**: O(1), as the solution uses a constant amount of space (a few pointers) regardless of the input size.

## Notes

---

 

## Related Videos

---

[https://www.notion.so](https://www.notion.so)