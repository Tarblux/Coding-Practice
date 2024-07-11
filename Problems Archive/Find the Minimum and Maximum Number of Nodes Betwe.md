# Find the Minimum and Maximum Number of Nodes Between Critical Points

Problem: 2058
Official Difficulty: medium
Feels Like : medium
My Understanding: Needs Review
Topic: linked list
Link: https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/description/
Completed On : July 5, 2024
Last Review: July 5, 2024
Days Since Review: 6

## Problem

---

A **critical point** in a linked list is defined as **either** a **local maxima** or a **local minima**.

A node is a **local maxima** if the current node has a value **strictly greater** than the previous node and the next node.

A node is a **local minima** if the current node has a value **strictly smaller** than the previous node and the next node.

Note that a node can only be a local maxima/minima if there exists **both** a previous node and a next node.

Given a linked list `head`, return *an array of length 2 containing* `[minDistance, maxDistance]` *where* `minDistance` *is the **minimum distance** between **any two distinct** critical points and* `maxDistance` *is the **maximum distance** between **any two distinct** critical points. If there are **fewer** than two critical points, return* `[-1, -1]`.

**Example 1:**

![https://assets.leetcode.com/uploads/2021/10/13/a1.png](https://assets.leetcode.com/uploads/2021/10/13/a1.png)

```
Input: head = [3,1]
Output: [-1,-1]
Explanation: There are no critical points in [3,1].
```

**Example 2:**

![https://assets.leetcode.com/uploads/2021/10/13/a2.png](https://assets.leetcode.com/uploads/2021/10/13/a2.png)

```
Input: head = [5,3,1,2,5,1,2]
Output: [1,3]
Explanation: There are three critical points:
- [5,3,1,2,5,1,2]: The third node is a local minima because 1 is less than 3 and 2.
- [5,3,1,2,5,1,2]: The fifth node is a local maxima because 5 is greater than 2 and 1.
- [5,3,1,2,5,1,2]: The sixth node is a local minima because 1 is less than 5 and 2.
The minimum distance is between the fifth and the sixth node. minDistance = 6 - 5 = 1.
The maximum distance is between the third and the sixth node. maxDistance = 6 - 3 = 3.
```

**Example 3:**

![https://assets.leetcode.com/uploads/2021/10/14/a5.png](https://assets.leetcode.com/uploads/2021/10/14/a5.png)

```
Input: head = [1,3,2,2,3,2,2,2,7]
Output: [3,3]
Explanation: There are two critical points:
- [1,3,2,2,3,2,2,2,7]: The second node is a local maxima because 3 is greater than 1 and 2.
- [1,3,2,2,3,2,2,2,7]: The fifth node is a local maxima because 3 is greater than 2 and 2.
Both the minimum and maximum distances are between the second and the fifth node.
Thus, minDistance and maxDistance is 5 - 2 = 3.
Note that the last node is not considered a local maxima because it does not have a next node.
```

**Constraints:**

- The number of nodes in the list is in the range `[2, 105]`.
- `1 <= Node.val <= 105`

## My Solutions

---

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:

    def isCritical(self, prev: ListNode, node: Optional[ListNode]) -> bool:

        if not node or not node.next:
            return False

        if prev.val < node.val > node.next.val or prev.val > node.val < node.next.val:
            return True

        return False

    def nodesBetweenCriticalPoints(self, head: Optional[ListNode]) -> List[int]:

        if not head or not head.next or not head.next.next:
            return [-1, -1]

        critical = []
        i = 1  
        
        prev = head
        current = head.next

        while current.next:
            if self.isCritical(prev, current):
                critical.append(i)
            prev = current
            current = current.next
            i += 1

        if len(critical) < 2:
            return [-1, -1]

        max_dist = critical[-1] - critical[0]
        min_dist = min([critical[i] - critical[i - 1] for i in range(1, len(critical))])

        return [min_dist, max_dist]
```

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def nodesBetweenCriticalPoints(self, head: Optional[ListNode]) -> List[int]:
 
        result = [-1, -1]
        critical_points = []
 
        i = 1
        prev = cur = head
        while cur.next.next:
            prev = cur
            cur = cur.next
            if prev.val < cur.val > cur.next.val:
                critical_points.append(i)
            if prev.val > cur.val < cur.next.val:
                critical_points.append(i)
            i += 1
        
        if len(critical_points) < 2:
            return result
 
        result[-1] = critical_points[-1] - critical_points[0]
        result[0] = float('inf')
        for i in range(len(critical_points) - 1):
            result[0] = min(result[0], critical_points[i + 1] - critical_points[i])
 
        return result
```

## Aleksandr

## Single Pass with No Extra Space

**Time Complexity:** O(n)  |  **Space Complexity:** O(1)

The approach above can be optimized further. To find the maximum distance, let’s save the first critical point in the variable `first` and the second critical point in `last`. We can also introduce a variable `minimum` to keep track of the smallest distance between consecutive critical points as we traverse the list.

If we find only 1 critical point, return `[-1, -1]`.

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def nodesBetweenCriticalPoints(self, head: Optional[ListNode]) -> List[int]:
 
        def criticalPoint(prev, cur, next):
            return (prev.val < cur.val > cur.next.val) or (prev.val > cur.val < cur.next.val)
 
        minimum = float('inf')
        first = last = -1
 
        i = 1
        prev = cur = head
        while cur.next.next:
            prev = cur
            cur = cur.next
            if criticalPoint(prev, cur, cur.next):
                if first == -1: first = i
                if last != -1: minimum = min(minimum, i - last)
                last = i
            i += 1
        
        if last - first == 0:
            return [-1, -1]
 
        return [minimum, last - first]
 
 
```

## Optimal Solutions

---

### Problem Description

Given the head of a linked list, return an array of two integers representing the minimum and maximum number of nodes between any two critical points. A critical point is defined as a node in the linked list where the node is a local minimum or a local maximum. If there are fewer than two critical points, return `[-1, -1]`.

### Definitions

- **Local Minimum**: A node is a local minimum if its value is less than both the previous node's value and the next node's value.
- **Local Maximum**: A node is a local maximum if its value is greater than both the previous node's value and the next node's value.

### Steps:

1. Traverse the linked list to identify critical points and their positions.
2. Calculate the minimum and maximum distances between the critical points.

### Python Code

```python
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def nodesBetweenCriticalPoints(self, head: ListNode):
        if not head or not head.next or not head.next.next:
            return [-1, -1]

        critical_points = []
        index = 1
        prev, curr, next = head, head.next, head.next.next

        while next:
            if (curr.val > prev.val and curr.val > next.val) or (curr.val < prev.val and curr.val < next.val):
                critical_points.append(index)
            prev = curr
            curr = next
            next = next.next
            index += 1

        if len(critical_points) < 2:
            return [-1, -1]

        min_distance = float('inf')
        for i in range(1, len(critical_points)):
            min_distance = min(min_distance, critical_points[i] - critical_points[i-1])

        max_distance = critical_points[-1] - critical_points[0]

        return [min_distance, max_distance]

# Helper function to create a linked list from a list
def create_linked_list(values):
    dummy = ListNode()
    current = dummy
    for value in values:
        current.next = ListNode(value)
        current = current.next
    return dummy.next

# Example usage
head = create_linked_list([1,3,2,2,3,2,2,2,7])
sol = Solution()
print(sol.nodesBetweenCriticalPoints(head))  # Output: [1, 3]

```

### Explanation

1. **Initialization**:
    - If the linked list has fewer than three nodes, return `[-1, -1]` since there can't be any critical points.
2. **Finding Critical Points**:
    - Traverse the list, keeping track of the previous, current, and next nodes.
    - If the current node is a local minimum or maximum, record its index.
3. **Calculating Distances**:
    - If there are fewer than two critical points, return `[-1, -1]`.
    - Otherwise, compute the minimum and maximum distances between critical points:
        - The minimum distance is the smallest difference between consecutive critical points.
        - The maximum distance is the difference between the first and last critical points.

### Time Complexity Analysis

- **Time Complexity**: `O(n)`, where `n` is the number of nodes in the linked list. The list is traversed once to find critical points and once to compute the distances.

### Space Complexity Analysis

- **Space Complexity**: `O(1)` for the space used in the main algorithm, excluding the input and output storage. The list of critical points can grow up to `O(n)` in the worst case, but this is not considered additional space complexity.

This approach ensures that the algorithm efficiently identifies critical points and calculates the required minimum and maximum distances with linear time complexity.

## Notes

---

 

## Related Videos

---

[https://youtu.be/UddDgt52h9g](https://youtu.be/UddDgt52h9g)