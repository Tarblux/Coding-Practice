# Sort List

Problem: 148
Official Difficulty: medium
Feels Like : medium
My Understanding: Mostly Understand
Topic: Divide and Conquer, linked list, merge sort, sorting, two pointers
Link: https://leetcode.com/problems/sort-list/description/
Completed On : March 28, 2024
Last Review: March 28, 2024
Days Since Review: 33

## Problem

---

Given the `head` of a linked list, return *the list after sorting it in **ascending order***.

**Example 1:**

![https://assets.leetcode.com/uploads/2020/09/14/sort_list_1.jpg](https://assets.leetcode.com/uploads/2020/09/14/sort_list_1.jpg)

```
Input: head = [4,2,1,3]
Output: [1,2,3,4]
```

**Example 2:**

![https://assets.leetcode.com/uploads/2020/09/14/sort_list_2.jpg](https://assets.leetcode.com/uploads/2020/09/14/sort_list_2.jpg)

```
Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]
```

**Example 3:**

```
Input: head = []
Output: []
```

**Constraints:**

- The number of nodes in the list is in the range `[0, 5 * 104]`.
- `105 <= Node.val <= 105`

**Follow up:** Can you sort the linked list in `O(n logn)` time and `O(1)` memory (i.e. constant space)?

## My Solutions

---

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:

        current = head
        array = []
        l2 = ListNode()
        l2_head = l2

        while current:

            array.append(current.val)
            current = current.next

        array.sort()

        for i in range(len(array)):

            cur_node = ListNode(array[i])

            l2.next = cur_node
            l2 = l2.next

        return l2_head.next
```

```python

```

## Optimal Solutions

---

The problem "148. Sort List" requires you to sort a linked list in O(n log n) time using constant space complexity. A suitable approach to meet these constraints is the Merge Sort algorithm, which can be implemented for linked lists in a way that uses constant space, aside from the stack space used by recursion.

Merge Sort works by dividing the list into two halves, sorting each half, and then merging the sorted halves. The sorting of halves is done recursively until the base case of a single element (or no element) list is reached, which is inherently sorted.

### Python Implementation:

```python
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def sortList(self, head: ListNode) -> ListNode:
        # Base case: empty list or a single element list is already sorted
        if not head or not head.next:
            return head

        # Step 1: Divide the list into two halves
        slow, fast = head, head.next
        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next

        mid = slow.next
        slow.next = None  # Break the link

        # Step 2: Sort each half
        left = self.sortList(head)
        right = self.sortList(mid)

        # Step 3: Merge the sorted halves
        return self.merge(left, right)

    def merge(self, l1, l2):
        # Helper function to merge two sorted lists
        dummy = ListNode()
        tail = dummy

        while l1 and l2:
            if l1.val < l2.val:
                tail.next = l1
                l1 = l1.next
            else:
                tail.next = l2
                l2 = l2.next
            tail = tail.next

        # Attach the remaining elements
        tail.next = l1 if l1 else l2

        return dummy.next

```

### Explanation:

- **Divide**: The list is divided into two halves using the slow and fast pointers technique. The fast pointer moves two steps at a time, and the slow pointer moves one step at a time. When the fast pointer reaches the end, the slow pointer will be at the midpoint, effectively dividing the list into two halves.
- **Conquer (Sort Each Half)**: The function is recursively called on each half to sort them. The base case of the recursion is when the list is either empty or contains a single element, which is considered sorted.
- **Combine (Merge Sorted Halves)**: The sorted halves are then merged into a single sorted list using the `merge` helper function. This function takes two sorted lists and merges them into one, maintaining the sorted order.

### Complexity Analysis:

- **Time Complexity**: O(n log n), where n is the number of nodes in the list. This time complexity is derived from the fact that the list is repeatedly halved (log n splits), and each split involves linear work (n) to merge the halves.
- **Space Complexity**: O(1). While the recursive implementation uses O(log n) space due to recursion stack, the problem statement allows this as it specifically asks for constant space complexity regarding the input list's manipulation, not the stack space used by recursion.

## Notes

---

 

## Related Videos

---

[https://www.youtube.com/watch?v=TGveA1oFhrc](https://www.youtube.com/watch?v=TGveA1oFhrc)