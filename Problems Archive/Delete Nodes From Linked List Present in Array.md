# Delete Nodes From Linked List Present in Array

Problem: 3217
Official Difficulty: medium
Feels Like : medium
My Understanding: Needs Review
Topic: hash table, linked list, set
Link: https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/description/?envType=daily-question&envId=2024-09-06
Completed On : September 5, 2024
Last Review: September 5, 2024
Days Since Review: 3

## Problem

---

You are given an array of integers `nums` and the `head` of a linked list. Return the `head` of the modified linked list after **removing** all nodes from the linked list that have a value that exists in `nums`.

**Example 1:**

**Input:** nums = [1,2,3], head = [1,2,3,4,5]

**Output:** [4,5]

**Explanation:**

![https://assets.leetcode.com/uploads/2024/06/11/linkedlistexample0.png](https://assets.leetcode.com/uploads/2024/06/11/linkedlistexample0.png)

Remove the nodes with values 1, 2, and 3.

**Example 2:**

**Input:** nums = [1], head = [1,2,1,2,1,2]

**Output:** [2,2,2]

**Explanation:**

![https://assets.leetcode.com/uploads/2024/06/11/linkedlistexample1.png](https://assets.leetcode.com/uploads/2024/06/11/linkedlistexample1.png)

Remove the nodes with value 1.

**Example 3:**

**Input:** nums = [5], head = [1,2,3,4]

**Output:** [1,2,3,4]

**Explanation:**

![https://assets.leetcode.com/uploads/2024/06/11/linkedlistexample2.png](https://assets.leetcode.com/uploads/2024/06/11/linkedlistexample2.png)

No node has value 5.

**Constraints:**

- `1 <= nums.length <= 105`
- `1 <= nums[i] <= 105`
- All elements in `nums` are unique.
- The number of nodes in the given list is in the range `[1, 105]`.
- `1 <= Node.val <= 105`
- The input is generated such that there is at least one node in the linked list that has a value not present in `nums`.

## My Solutions

---

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def modifiedList(self, nums: List[int], head: Optional[ListNode]) -> Optional[ListNode]:
        
        nums = set(nums)              
        dummy = ListNode(0)
        dummy.next = head
        prev = dummy
        current = head

        while current:

            if current.val in nums:
                prev.next = current.next
            else:
                prev = current
            current = current.next

        return dummy.next
```

```python

```

## Optimal Solutions

---

To solve the problem "Delete Nodes From Linked List Present in Array," we need to delete nodes from a linked list whose values are present in a given array. Here's how to approach this problem step by step:

### Approach

1. **Convert the Array to a Set**:
    - Since searching in an array is `O(n)`, converting the array to a set will allow us to check for the presence of a value in `O(1)` time, significantly improving performance.
2. **Traverse the Linked List**:
    - As we traverse the linked list, check if the current node's value is present in the set. If it is, skip (delete) that node by adjusting the `next` pointer of the previous node.
3. **Edge Cases**:
    - Handle cases where the head node itself needs to be deleted.
    - Handle cases where the list is empty.

### Steps

1. Traverse the list node by node.
2. If a node's value exists in the set, delete it by skipping over it.
3. Ensure that the head node is updated properly if it is among the nodes to be deleted.

### Python Implementation

```python
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def deleteNodes(self, head: ListNode, to_delete: List[int]) -> ListNode:
        # Step 1: Convert the array to a set for O(1) lookups
        delete_set = set(to_delete)

        # Step 2: Create a dummy node to handle edge cases like deleting the head
        dummy = ListNode(0)
        dummy.next = head

        # Step 3: Use two pointers to traverse and modify the list
        prev, curr = dummy, head

        while curr:
            if curr.val in delete_set:
                # Delete the current node by linking the previous node to the next node
                prev.next = curr.next
            else:
                # Move prev only if the current node is not deleted
                prev = curr
            curr = curr.next

        return dummy.next

# Example usage
def print_list(head):
    while head:
        print(head.val, end=" -> ")
        head = head.next
    print("None")

# Creating the linked list: 1 -> 2 -> 3 -> 4 -> 5
head = ListNode(1)
head.next = ListNode(2)
head.next.next = ListNode(3)
head.next.next.next = ListNode(4)
head.next.next.next.next = ListNode(5)

to_delete = [2, 4]

sol = Solution()
new_head = sol.deleteNodes(head, to_delete)

print_list(new_head)  # Output should be: 1 -> 3 -> 5 -> None

```

### Explanation:

1. **Convert to Set**:
    - `to_delete` is converted to a set `delete_set` for faster lookups.
2. **Dummy Node**:
    - A dummy node is used to handle edge cases, such as when the head node needs to be deleted. This ensures we don't lose the reference to the new head of the list.
3. **Traversal**:
    - We traverse the list, and if the current node’s value is found in the `delete_set`, we adjust the previous node's `next` pointer to skip the current node.
4. **Edge Cases**:
    - The head node might be deleted, and this is correctly handled using the dummy node.
    - The list may be empty, in which case we simply return `None`.

### Complexity Analysis

- **Time Complexity**: `O(n)`, where `n` is the number of nodes in the linked list. We traverse each node once and perform constant-time operations for each node.
- **Space Complexity**: `O(m)`, where `m` is the number of elements in the `to_delete` array. We store the elements in a set for fast lookups.

This approach efficiently removes nodes from the linked list that are present in the given array.

## Notes

---

 

## Related Videos

---

[https://www.youtube.com/watch?v=3xZuqYD3EYA](https://www.youtube.com/watch?v=3xZuqYD3EYA)