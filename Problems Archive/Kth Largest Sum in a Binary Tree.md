Problem: 2583
Official Difficulty: medium
Link: https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree/description/?envType=daily-question&envId=2024-10-23
Completed On : 2024-10-22
Feels Like : easy
Topic: tree, Breadth-First Search(BFS), sorting, binary tree
My Understanding: Fully Understand
Last Review: 2024-10-22
Days Since Review: 5
Name: Kth Largest Sum in a Binary Tree 

# Kth Largest Sum in a Binary Tree 
### Problem
___
You are given the `root` of a binary tree and a positive integer `k`.
The **level sum** in the tree is the sum of the values of the nodes that are on the **same** level.
Return* the *`kth`* ****largest**** level sum in the tree (not necessarily distinct)*. If there are fewer than `k` levels in the tree, return `-1`.
**Note** that two nodes are on the same level if they have the same distance from the root.
**Example 1:**
![binaryytreeedrawio-2.png](https://assets.leetcode.com/uploads/2022/12/14/binaryytreeedrawio-2.png)
```plain text
Input: root = [5,8,9,2,1,3,7,4,6], k = 2
Output: 13
Explanation: The level sums are the following:
- Level 1: 5.
- Level 2: 8 + 9 = 17.
- Level 3: 2 + 1 + 3 + 7 = 13.
- Level 4: 4 + 6 = 10.
The 2nd largest level sum is 13.

```
**Example 2:**
![treedrawio-3.png](https://assets.leetcode.com/uploads/2022/12/14/treedrawio-3.png)
```plain text
Input: root = [1,2,null,3], k = 1
Output: 3
Explanation: The largest level sum is 3.

```
**Constraints:**
- The number of nodes in the tree is `n`.
- `2 <= n <= 105`
- `1 <= Node.val <= 106`
- `1 <= k <= n`
### My Solutions
___
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def kthLargestLevelSum(self, root: Optional[TreeNode], k: int) -> int:

        queue = deque([(root,0)])
        levels = defaultdict(int)
        heap = []

        while queue:

            node,level = queue.popleft()
            levels[level] += node.val

            if node.left:
                queue.append((node.left,level + 1))
            if node.right:
                queue.append((node.right,level + 1))
            
        for s in levels.values():
            heapq.heappush(heap,-s)

        if k > len(heap) or k <= 0:
            return -1 

        for _ in range(k - 1):
            heapq.heappop(heap)

        return -heapq.heappop(heap)
```

Time Complexity :
## Improved version of above : 
Yes, you can use `heapq.nlargest(k, heap)[-1]` to find the k-th largest element. However, since `heapq.nlargest` works on any iterable and not just heaps, you don't need to push the level sums into a heap first. Instead, you can work directly with the list of level sums.
Here's how you can modify your code:
```python
from collections import deque, defaultdict
import heapq

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def kthLargestLevelSum(self, root: Optional[TreeNode], k: int) -> int:

        queue = deque([(root, 0)])
        levels = defaultdict(int)

        while queue:

            node, level = queue.popleft()
            levels[level] += node.val

            if node.left:
                queue.append((node.left, level + 1))
            if node.right:
                queue.append((node.right, level + 1))

        # Collect all level sums into a list
        level_sums = list(levels.values())

        # Check if k is valid
        if k > len(level_sums) or k <= 0:
            return -1  # or handle according to the problem's specifications

        # Use heapq.nlargest to find the k largest sums and get the last one
        kth_largest_sum = heapq.nlargest(k, level_sums)[-1]
        return kth_largest_sum

```
#### Explanation:
- **Collect Level Sums:**
	- After computing the sums for each level, store them in a list called `level_sums`.
	- Example: If the level sums are 10, 20, and 15, then `level_sums = [10, 20, 15]`.
- **Validate **`**k**`**:**
	- Ensure that `k` is within the valid range (i.e., `1 <= k <= number of levels`).
	- If `k` is invalid, return `1` or handle it as per the problem's requirements.
- **Find the k-th Largest Sum:**
	- Use `heapq.nlargest(k, level_sums)` to get a list of the k largest sums in descending order.
		- For example, `heapq.nlargest(2, [10, 20, 15])` returns `[20, 15]`.
	- Access the last element of this list to get the k-th largest sum.
		- Continuing the example, `[20, 15][-1]` gives `15`, which is the 2nd largest sum.
#### Why This Works:
- **Efficiency:**
	- `heapq.nlargest` is efficient for finding the k largest elements without sorting the entire list.
	- It works well even when the number of levels is large.
- **Simplicity:**
	- Avoids unnecessary use of a heap since the level sums are already in a list.
	- Makes the code cleaner and more readable.
#### Important Notes:
- **No Need for a Heap Variable:**
	- The `heap` variable in your original code isn't necessary when using `heapq.nlargest`.
	- You can remove the heap altogether and work directly with `level_sums`.
- **Edge Cases:**
	- Always check if `k` is valid to prevent index errors.
	- Decide how to handle cases where `k` is out of bounds based on the problem's specifications.
- **Alternative Approach (Sorting):**
	- If the number of levels is small, you could sort the `level_sums` list in descending order and pick the k-th element.
```python
level_sums.sort(reverse=True)
kth_largest_sum = level_sums[k - 1]
return kth_largest_sum

```
	- However, using `heapq.nlargest` is more efficient for larger datasets.
#### Example:
Suppose the level sums are `[5, 11, 15]`, and you want the 2nd largest sum:
```python
level_sums = [5, 11, 15]
k = 2
kth_largest_sum = heapq.nlargest(k, level_sums)[-1]  # Returns 11

```
#### Conclusion:
Using `heapq.nlargest(k, level_sums)[-1]` is an effective way to find the k-th largest level sum in the tree. It simplifies your code and leverages built-in Python functions for efficiency.
___
Let me know if you have any more questions or need further clarification!
### Optimal Solutions
___
#### **Approach 2: Level Order Traversal + Min Heap**
#### **Intuition**
In Approach 1, our max heap stored sums for all levels of the tree, making heap operations costly. In Approach 2, we use a min heap instead, where the smallest level sum is at the top. As we add new level sums, if the heap size exceeds `k`, we remove the top element. This ensures that, after processing all level sums, our heap contains the `k` largest sums, with the `k-th` largest at the top, which we can return. All smaller sums would have been evicted earlier whenever the heap size exceeded `k`. By limiting the heap size to `k`, where *k*≤log*N*, we reduce the overall time complexity.
#### **Algorithm**
1. Initialize a min heap/priority queue `pq`
2. Initialize a queue `bfsQueue` to maintain the ordering of which nodes to visit for our level order traversal
3. Start by adding `root` to `bfsQueue`
4. Perform level order traversal. While `bfsQueue` is not empty:
	- Initialize `size` to be the current number of nodes of `bfsQueue`, which are all the nodes for the current level that we want to visit
	- For `size` iterations:
		- Initialize `sum` to `0`
		- Visit the next node by removing the next node in `bfsQueue`. Store it in `poppedNode`
		- Update `sum`: `sum += poppedNode.val`
		- Add the left and right children of `poppedNode` to the queue, if they exist. These children will be a part of the next level of the tree that will be visited in the next iteration.
	- `sum` now contains a level order sum. Add it to `pq`
	- If size of `pq` now exceeds `k` elements, remove the top element.
5. If `pq` has less than `k` sums, then return -1 because we have less than `k` levels in our tree
6. Top element is the `k-th` largest sum so return it: `pq.peek()`
```javascript
class Solution:
    def kthLargestLevelSum(self, root, k):
        # min heap of size k
        # at the end, top element is kth largest
        pq = []
        bfs_queue = deque()
        bfs_queue.append(root)

        while bfs_queue:
            # level order traversal
            size = len(bfs_queue)
            sum_val = 0
            for _ in range(size):
                popped_node = bfs_queue.popleft()
                sum_val += popped_node.val
                if popped_node.left is not None:
                    # add left child
                    bfs_queue.append(popped_node.left)
                if popped_node.right is not None:
                    # add right child
                    bfs_queue.append(popped_node.right)

            heapq.heappush(pq, sum_val)
            if len(pq) > k:
                # evict top element
                heapq.heappop(pq)
        if len(pq) < k:
            return -1
        return pq[0]
```
### Notes
___
 
### Related Videos 
___
[]()