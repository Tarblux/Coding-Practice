Problem: 143
Official Difficulty: medium
Link: https://leetcode.com/problems/reorder-list/description/
Completed On : 2024-12-17
Feels Like : medium
Topic: linked list, two pointers, Stack, recursion
My Understanding: Needs Review
Last Review: 2024-12-17
Days Since Review: 5
Name: Reorder List

# Reorder List
### Problem
___
You are given the head of a singly linked-list. The list can be represented as:
```plain text
L0 → L1 → … → Ln - 1 → Ln
```
*Reorder the list to be on the following form:*
```plain text
L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
```
You may not modify the values in the list's nodes. Only nodes themselves may be changed.
**Example 1:**
![reorder1linked-list.jpg](https://assets.leetcode.com/uploads/2021/03/04/reorder1linked-list.jpg)
```plain text
Input: head = [1,2,3,4]
Output: [1,4,2,3]
```
**Example 2:**
![reorder2-linked-list.jpg](https://assets.leetcode.com/uploads/2021/03/09/reorder2-linked-list.jpg)
```plain text
Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]
```
**Constraints:**
- The number of nodes in the list is in the range `[1, 5 * 104]`.
- `1 <= Node.val <= 1000`
### My Solutions
___
```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:

        extracted = []
        current = head

        while current:
            extracted.append(current)
            current = current.next

        left = 0
        right = len(extracted) - 1

        # while left < right:
            
        #     extracted[left].next = extracted[right]
        #     left += 1
            
        #     if left == right:
        #         break 

        #     extracted[right].next = extracted[left]
        #     right -= 1

        for i in range(len(extracted)):

            

        extracted[left].next = None

        """
        Do not return anything, modify head in-place instead.
        """
```

Time Complexity :
```python

```

Time Complexity : 
### Optimal Solutions
___
Here’s how to solve **LeetCode 143: Reorder List** using a three-step approach:
___
#### **Approach**
The task is to reorder a singly linked list by rearranging its nodes as follows:
From `L0 → L1 → L2 → ... → Ln-1 → Ln`
To `L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → ...`.
This can be accomplished in three main steps:
___
#### **1. Find the Middle of the List**
Using the **two-pointer technique**, find the middle node of the list:
- Slow pointer (`slow`) moves one step at a time.
- Fast pointer (`fast`) moves two steps at a time.
- When `fast` reaches the end, `slow` points to the middle of the list.
___
#### **2. Reverse the Second Half of the List**
Once the middle is found:
- Reverse the second half of the list starting from the node after the middle.
- This ensures that the second half is in reverse order and ready for interleaving with the first half.
___
#### **3. Merge the Two Halves**
- Use two pointers:
	- `first` to traverse the first half (starting from the head).
	- `second` to traverse the reversed second half.
- Merge them alternately:
	- Connect `first` to `second`.
	- Connect `second` to `first.next`.
	- Move both pointers forward.
___
#### **Code Implementation**
```python
class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        if not head or not head.next:
            return

        # Step 1: Find the middle of the list
        slow, fast = head, head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next

        # Step 2: Reverse the second half of the list
        prev, curr = None, slow.next
        slow.next = None  # Disconnect the first half from the second half
        while curr:
            next_temp = curr.next
            curr.next = prev
            prev = curr
            curr = next_temp

        # Step 3: Merge the two halves
        first, second = head, prev
        while second:
            tmp1, tmp2 = first.next, second.next
            first.next = second
            second.next = tmp1
            first, second = tmp1, tmp2

```
___
#### **Explanation**
1. **Find the Middle:**
	- For `head = [1, 2, 3, 4, 5]`, after finding the middle, `slow` points to `3`.
2. **Reverse the Second Half:**
	- The second half `[4, 5]` becomes `[5, 4]`.
3. **Merge the Halves:**
	- Start merging:
		- `1 → 5 → 2 → 4 → 3`.
___
#### **Complexity Analysis**
- **Time Complexity:** O(n)
	- Finding the middle takes O(n).
	- Reversing the second half takes O(n/2).
	- Merging the two halves takes O(n/2).
	- Total is O(n).
- **Space Complexity:** O(1)
	- Reordering is done in-place, so no extra space is used.
___
#### **Example Execution**
**Input:**
`head = [1, 2, 3, 4, 5]`
**Steps:**
4. Find the middle: `slow` points to `3`.
5. Reverse the second half: `[4, 5] → [5, 4]`.
6. Merge:
	- `1 → 5 → 2 → 4 → 3`.
**Output:**
`[1, 5, 2, 4, 3]`
This method effectively reorders the list in-place with optimal time and space complexity.
### Notes
___
 
### Related Videos 
___
[5Y2EiZST97Y](https://youtu.be/5Y2EiZST97Y)
