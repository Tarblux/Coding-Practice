<<<<<<< Updated upstream
Problem: 23
Official Difficulty: hard
Link: https://leetcode.com/problems/merge-k-sorted-lists/description/
Completed On : 2024-12-28
Feels Like : medium
Topic: linked list, Divide and Conquer, Heap(Priority Queue), merge sort
My Understanding: Fully Understand
Last Review: 2024-12-28
Days Since Review: 1
Name: Merge K Sorted Lists

# Merge K Sorted Lists
### Problem
___
You are given an array of `k` linked-lists `lists`, each linked-list is sorted in ascending order.
*Merge all the linked-lists into one sorted linked-list and return it.*
**Example 1:**
```plain text
=======
# Merge K Sorted Lists

Problem: 23
Official Difficulty: hard
Feels Like : medium
My Understanding: Fully Understand
Topic: Divide and Conquer, Heap(Priority Queue), linked list, merge sort
Link: https://leetcode.com/problems/merge-k-sorted-lists/description/
Completed On : December 28, 2024
Last Review: December 28, 2024
Days Since Review: 64
Neetcode: Yes

## Problem

---

You are given an array of `k` linked-lists `lists`, each linked-list is sorted in ascending order.

*Merge all the linked-lists into one sorted linked-list and return it.*

**Example 1:**

```
>>>>>>> Stashed changes
Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6

```
<<<<<<< Updated upstream
**Example 2:**
```plain text
=======

**Example 2:**

```
>>>>>>> Stashed changes
Input: lists = []
Output: []

```
<<<<<<< Updated upstream
**Example 3:**
```plain text
=======

**Example 3:**

```
>>>>>>> Stashed changes
Input: lists = [[]]
Output: []

```
<<<<<<< Updated upstream
**Constraints:**
=======

**Constraints:**

>>>>>>> Stashed changes
- `k == lists.length`
- `0 <= k <= 104`
- `0 <= lists[i].length <= 500`
- `104 <= lists[i][j] <= 104`
- `lists[i]` is sorted in **ascending order**.
- The sum of `lists[i].length` will not exceed `104`.
<<<<<<< Updated upstream
### My Solutions
___
=======

## My Solutions

---

>>>>>>> Stashed changes
```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:

        if not lists:
            return None

        heap = []

        for head in lists:

            while head:

                heapq.heappush(heap,head.val)
                head = head.next

        dummy = ListNode()
        output = dummy

        while heap:

            cur = ListNode(heapq.heappop(heap))
            dummy.next = cur
            dummy = dummy.next

        return output.next

```

<<<<<<< Updated upstream
Time Complexity :
=======
>>>>>>> Stashed changes
```python

```

<<<<<<< Updated upstream
Time Complexity : 
### Optimal Solutions
___
___
#### **Approach: Min-Heap**
1. **Use a Min-Heap to Track the Smallest Element:**
	- Insert the head of each list into the heap, storing both the value and a reference to the node.
	- The heap allows us to efficiently retrieve the smallest node among all lists.
2. **Iteratively Build the Result:**
	- Pop the smallest node from the heap.
	- Add it to the result list.
	- If the popped node has a next node, push it into the heap.
	- Repeat until the heap is empty.
3. **Return the Result List:**
	- The result list contains all nodes in sorted order.
___
#### **Code Implementation**
=======
## Optimal Solutions

---

---

### **Approach: Min-Heap**

1. **Use a Min-Heap to Track the Smallest Element:**
    - Insert the head of each list into the heap, storing both the value and a reference to the node.
    - The heap allows us to efficiently retrieve the smallest node among all lists.
2. **Iteratively Build the Result:**
    - Pop the smallest node from the heap.
    - Add it to the result list.
    - If the popped node has a next node, push it into the heap.
    - Repeat until the heap is empty.
3. **Return the Result List:**
    - The result list contains all nodes in sorted order.

---

### **Code Implementation**

>>>>>>> Stashed changes
```python
from heapq import heappush, heappop

class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        if not lists:
            return None

        # Min-heap to store (value, index, node)
        heap = []

        # Initialize the heap with the head of each list
        for i, l in enumerate(lists):
            if l:
                heappush(heap, (l.val, i, l))

        # Dummy node to build the result list
        dummy = ListNode(0)
        current = dummy

        # Extract the smallest element and process
        while heap:
            val, idx, node = heappop(heap)
            current.next = node
            current = current.next

            # If there is a next node, push it into the heap
            if node.next:
                heappush(heap, (node.next.val, idx, node.next))

        return dummy.next

```
<<<<<<< Updated upstream
___
#### **Explanation**
4. **Heap Storage:**
	- The heap stores tuples `(value, index, node)`. The `index` ensures the heap can differentiate between nodes with the same value.
5. **Efficiency:**
	- Inserting and extracting from the heap is O(log k), where `k` is the number of lists.
	- Over `n` total nodes, the total complexity is O(n log k).
6. **Dummy Node:**
	- A dummy node simplifies constructing the result list by providing a fixed starting point.
___
#### **Complexity Analysis**
- **Time Complexity:**
	- Building the heap initially: O(k log k), where `k` is the number of lists.
	- Extracting nodes and pushing next nodes into the heap: O(n log k), where `n` is the total number of nodes.
	- Total: **O(n log k)**.
- **Space Complexity:**
	- The heap stores up to `k` nodes: **O(k)**.
___
#### **Example Walkthrough**
**Input:**
```plain text
=======

---

### **Explanation**

1. **Heap Storage:**
    - The heap stores tuples `(value, index, node)`. The `index` ensures the heap can differentiate between nodes with the same value.
2. **Efficiency:**
    - Inserting and extracting from the heap is O(log k), where `k` is the number of lists.
    - Over `n` total nodes, the total complexity is O(n log k).
3. **Dummy Node:**
    - A dummy node simplifies constructing the result list by providing a fixed starting point.

---

### **Complexity Analysis**

- **Time Complexity:**
    - Building the heap initially: O(k log k), where `k` is the number of lists.
    - Extracting nodes and pushing next nodes into the heap: O(n log k), where `n` is the total number of nodes.
    - Total: **O(n log k)**.
- **Space Complexity:**
    - The heap stores up to `k` nodes: **O(k)**.

---

### **Example Walkthrough**

**Input:**

```
>>>>>>> Stashed changes
lists = [
    [1, 4, 5],
    [1, 3, 4],
    [2, 6]
]

```
<<<<<<< Updated upstream
**Execution:**
7. Initialize heap: `[(1, 0, ListNode(1)), (1, 1, ListNode(1)), (2, 2, ListNode(2))]`.
8. Pop smallest (1 from list 0), push next (4 from list 0).
9. Result so far: `1`.
10. Repeat:
	- Pop (1 from list 1), push next (3 from list 1).
	- Pop (2 from list 2), push next (6 from list 2).
	- ...
**Output:** `[1, 1, 2, 3, 4, 4, 5, 6]`.
___
#### **Alternative Approach: Divide and Conquer**
Another efficient approach is to repeatedly merge pairs of lists using the **merge two sorted lists** function.
**Steps:**
11. Merge lists in pairs until only one list remains.
12. Use a divide-and-conquer strategy to reduce the number of lists logarithmically.
**Time Complexity:**
- Each merge takes O(n) for `n` nodes.
- There are O(log k) levels of merging.
- Total: **O(n log k)**.
___
**Divide and Conquer Code:**
=======

**Execution:**

1. Initialize heap: `[(1, 0, ListNode(1)), (1, 1, ListNode(1)), (2, 2, ListNode(2))]`.
2. Pop smallest (1 from list 0), push next (4 from list 0).
3. Result so far: `1`.
4. Repeat:
    - Pop (1 from list 1), push next (3 from list 1).
    - Pop (2 from list 2), push next (6 from list 2).
    - ...

**Output:** `[1, 1, 2, 3, 4, 4, 5, 6]`.

---

### **Alternative Approach: Divide and Conquer**

Another efficient approach is to repeatedly merge pairs of lists using the **merge two sorted lists** function.

**Steps:**

1. Merge lists in pairs until only one list remains.
2. Use a divide-and-conquer strategy to reduce the number of lists logarithmically.

**Time Complexity:**

- Each merge takes O(n) for `n` nodes.
- There are O(log k) levels of merging.
- Total: **O(n log k)**.

---

**Divide and Conquer Code:**

>>>>>>> Stashed changes
```python
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        if not lists:
            return None

        def mergeTwoLists(l1, l2):
            dummy = ListNode(0)
            current = dummy
            while l1 and l2:
                if l1.val < l2.val:
                    current.next = l1
                    l1 = l1.next
                else:
                    current.next = l2
                    l2 = l2.next
                current = current.next
            current.next = l1 if l1 else l2
            return dummy.next

        while len(lists) > 1:
            merged_lists = []
            for i in range(0, len(lists), 2):
                l1 = lists[i]
                l2 = lists[i + 1] if i + 1 < len(lists) else None
                merged_lists.append(mergeTwoLists(l1, l2))
            lists = merged_lists

        return lists[0]

```
<<<<<<< Updated upstream
___
#### **Comparison of Methods**

|**Approach**|**Time Complexity**|**Space Complexity**|**When to Use**|
|---|---|---|---|
|Min-Heap|O(n log k)|O(k)|Many small lists|
|Divide and Conquer|O(n log k)|O(1)|Fewer but larger lists|
Both methods are efficient, but the **min-heap** approach is generally easier to implement and works well for typical use cases.
### Notes
___
 
### Related Videos 
___
[]()
=======

---

### **Comparison of Methods**

| **Approach** | **Time Complexity** | **Space Complexity** | **When to Use** |
| --- | --- | --- | --- |
| Min-Heap | O(n log k) | O(k) | Many small lists |
| Divide and Conquer | O(n log k) | O(1) | Fewer but larger lists |

Both methods are efficient, but the **min-heap** approach is generally easier to implement and works well for typical use cases.

## Notes

---

 

## Related Videos

---

[https://www.notion.so](https://www.notion.so)
>>>>>>> Stashed changes
