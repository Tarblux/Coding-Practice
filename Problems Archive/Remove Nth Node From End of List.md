# Remove Nth Node From End of List

Problem: 19
Official Difficulty: medium
Feels Like : medium
Topic: linked list, two pointers
Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
Completed On : December 30, 2023
My Understanding: Needs Review
Last Review: December 30, 2023
Days Since Review: 42

## Problem

---

Given the `head` of a linked list, remove the `nth` node from the end of the list and return its head.

**Example 1:**

![https://assets.leetcode.com/uploads/2020/10/03/remove_ex1.jpg](https://assets.leetcode.com/uploads/2020/10/03/remove_ex1.jpg)

```
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

```

**Example 2:**

```
Input: head = [1], n = 1
Output: []

```

**Example 3:**

```
Input: head = [1,2], n = 1
Output: [1]

```

**Constraints:**

- The number of nodes in the list is `sz`.
- `1 <= sz <= 30`
- `0 <= Node.val <= 100`
- `1 <= n <= sz`

**Follow up:** Could you do this in one pass?

## My Solutions

---

```python
class Solution(object):
    
    def removeNthFromEnd(self, head, n):
        
        array = []
        
        cur = head
        
        t = 0
        
        while cur != None :
            
            array.append(cur.val)
            
            cur = cur.next

        array.pop(-n)
        
        new = ListNode(1,None)
        
        cur = new
        
        for value in array : 
            
            cur.next = ListNode(value)
            cur = cur.next
            
        return new.next
```

### Aleksandr

```python
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        
        #find the max
        total = 1
        node = head
        while (node.next != None):
            node = node.next
            total += 1
    
        # remove the first node
        if total == n:
            return head.next
        
        # find the node
        node = head
        n = total - n - 1
        while(n != 0):
            node = node.next
            n -= 1
            
        node.next = node.next.next
  
        return head
```

## Optimal Solutions

---

To remove the `nth` node from the end of a linked list optimally, you can use the two-pointer technique. This approach eliminates the need for a preliminary pass to count the total number of nodes in the list. The idea is to maintain two pointers, initially both pointing to the head of the list, and then advance one pointer so that it is `n` nodes ahead of the other. Then, move both pointers at the same speed until the leading pointer reaches the end of the list. At this point, the trailing pointer will be just before the node that needs to be removed.

Here's how to implement it:

```python
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def removeNthFromEnd(self, head, n):
        # Create a dummy node to simplify edge cases
        dummy = ListNode(0, head)
        first = second = dummy

        # Advance the first pointer by n+1 steps
        for i in range(n + 1):
            first = first.next

        # Move first to the end, maintaining the gap
        while first:
            first = first.next
            second = second.next

        # Skip the nth node from the end
        second.next = second.next.next

        return dummy.next

```

### Explanation:

- A dummy node is used to handle cases where the node to be removed might be the head of the list.
- The `first` pointer is advanced by `n + 1` steps from the dummy node, so it's `n` nodes ahead of the `second` pointer.
- Both `first` and `second` pointers are then moved together until `first` reaches the end of the list.
- At this point, `second.next` is the node to be removed. So, `second.next` is updated to `second.next.next` to skip the `nth` node from the end.
- Finally, the function returns `dummy.next`, which is the new head of the list.

This method effectively removes the `nth` node from the end in a single pass, with a time complexity of O(L) (where L is the length of the list) and constant space complexity, O(1).

## Notes

---

 

## Related Videos

---

[https://www.youtube.com/watch?v=XVuQxVej6y8](https://www.youtube.com/watch?v=XVuQxVej6y8)