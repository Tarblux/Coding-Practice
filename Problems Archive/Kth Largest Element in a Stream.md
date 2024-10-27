Problem: 703
Official Difficulty: easy
Link: https://leetcode.com/problems/kth-largest-element-in-a-stream/description/
Completed On : 2024-10-23
Feels Like : medium
Topic: tree, design, binary search tree, Heap(Priority Queue), binary tree, Data Stream
My Understanding: Mostly Understand
Last Review: 2024-10-23
Days Since Review: 4
Name: Kth Largest Element in a Stream

# Kth Largest Element in a Stream
### Problem
___
You are part of a university admissions office and need to keep track of the `kth` highest test score from applicants in real-time. This helps to determine cut-off marks for interviews and admissions dynamically as new applicants submit their scores.
You are tasked to implement a class which, for a given integer `k`, maintains a stream of test scores and continuously returns the `k`th highest test score **after** a new score has been submitted. More specifically, we are looking for the `k`th highest score in the sorted list of all scores.
Implement the `KthLargest` class:
- `KthLargest(int k, int[] nums)` Initializes the object with the integer `k` and the stream of test scores `nums`.
- `int add(int val)` Adds a new test score `val` to the stream and returns the element representing the `kth` largest element in the pool of test scores so far.
**Example 1:**
**Input:**
["KthLargest", "add", "add", "add", "add", "add"][[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]
**Output:** [null, 4, 5, 5, 8, 8]
**Explanation:**
KthLargest kthLargest = new KthLargest(3, [4, 5, 8, 2]);
kthLargest.add(3); // return 4
kthLargest.add(5); // return 5
kthLargest.add(10); // return 5
kthLargest.add(9); // return 8
kthLargest.add(4); // return 8
**Example 2:**
**Input:**
["KthLargest", "add", "add", "add", "add"][[4, [7, 7, 7, 7, 8, 3]], [2], [10], [9], [9]]
**Output:** [null, 7, 7, 7, 8]
**Explanation:**
KthLargest kthLargest = new KthLargest(4, [7, 7, 7, 7, 8, 3]);
kthLargest.add(2); // return 7
kthLargest.add(10); // return 7
kthLargest.add(9); // return 7
kthLargest.add(9); // return 8
**Constraints:**
- `0 <= nums.length <= 104`
- `1 <= k <= nums.length + 1`
- `104 <= nums[i] <= 104`
- `104 <= val <= 104`
- At most `104` calls will be made to `add`
### My Solutions
___
```python
class KthLargest:

    def __init__(self, k: int, nums: List[int]):

        self.cutoff = k
        self.scores = nums
        heapq.heapify(self.scores)

        while len(self.scores) > self.cutoff:
            heapq.heappop(self.scores)
        
    def add(self, val: int) -> int:
        
        if len(self.scores) < self.cutoff:
            heapq.heappush(self.scores,val)
        else:

            if val < self.scores[0]:
                return self.scores[0]

            heapq.heappop(self.scores)
            heapq.heappush(self.scores,val)

        return self.scores[0]
        
# Your KthLargest object will be instantiated and called as such:
# obj = KthLargest(k, nums)
# param_1 = obj.add(val)
```

Time Complexity :
#### This receives time limit exceeded , see notes below
```python
class KthLargest:

    def __init__(self, k: int, nums: List[int]):

        self.cutoff = k
        self.scores = nums
        heapq.heapify(self.scores)
        
    def add(self, val: int) -> int:

        heapq.heappush(self.scores,val)

        kth_largest = heapq.nlargest(self.cutoff,self.scores)
        return kth_largest[-1]
        
# Your KthLargest object will be instantiated and called as such:
# obj = KthLargest(k, nums)
# param_1 = obj.add(val)
```

Time Complexity : 
The time limit exceeded (TLE) error occurs because your `add` method has a higher time complexity than acceptable for the problem constraints. Specifically, the use of `heapq.nlargest(self.cutoff, self.scores)` inside the `add` method causes the issue.
#### **Explanation of the Issue:**
- **Inefficient Time Complexity:**
	- The `heapq.nlargest(k, iterable)` function has a time complexity of **O(n log k)**, where `n` is the number of elements in `self.scores`.
	- As you keep adding elements to `self.scores`, `n` increases, making the `add` method slower over time.
	- With potentially up to \(10^4\) calls to `add`, each taking O(n log k) time, the total time complexity becomes O(m \* n log k), which is too high for the problem constraints.
#### **Hint for Optimization:**
- **Maintain a Min-Heap of Fixed Size:**
	- Instead of keeping all elements in `self.scores`, maintain a min-heap of size **k**.
	- This way, the smallest element in the heap is the k-th largest element in the stream.
- **Efficient Operations:**
	- When adding a new value:
		- If the heap has fewer than `k` elements, simply push the new value onto the heap.
		- If the new value is greater than the smallest (heap's root), push the new value onto the heap and pop the smallest one.
		- This ensures the heap size remains at most `k`, and the smallest element in the heap is always the k-th largest.
	- Each `add` operation will then have a time complexity of **O(log k)**.
- **Accessing the k-th Largest Element:**
	- After maintaining the heap as described, you can access the k-th largest element directly via `self.heap[0]`.
#### **Why This Works:**
- **Reduced Time Complexity:**
	- By keeping the heap size fixed at `k`, you ensure that each `add` operation takes O(log k) time.
	- This significantly reduces the total time complexity, making it acceptable for the problem constraints.
- **Optimal for Streaming Data:**
	- This approach is suitable for a data stream where you need to continuously track the k-th largest element without storing all elements.
#### **Next Steps:**
- **Modify Your Data Structure:**
	- Initialize `self.scores` as a heap of at most `k` largest elements from `nums`.
	- Remove the use of `heapq.nlargest` in the `add` method.
- **Adjust the **`**add**`** Method Logic:**
	- Implement the logic to maintain the heap size and properties as mentioned above.
By optimizing your approach to maintain a min-heap of size `k`, you'll avoid the time limit exceeded error and meet the efficiency requirements of the problem.
### Optimal Solutions
___
To solve **LeetCode Problem 703: Kth Largest Element in a Stream**, the most efficient approach is to use a **min-heap (priority queue)** to maintain the **k** largest elements seen so far in the stream.
___
#### **Optimal Algorithm: Min-Heap of Size k**
**Algorithm Overview:**
- **Objective:** Design a data structure that efficiently returns the kth largest element in a stream of integers.
- **Approach:** Use a min-heap to keep track of the k largest elements. The root of the min-heap will always be the kth largest element.
**Algorithm Steps:**
1. **Initialize the Min-Heap:**
	- Build a min-heap from the initial elements in `nums`.
	- If the size of `nums` is greater than `k`, maintain only the k largest elements in the heap.
```python
import heapq

class KthLargest:

    def __init__(self, k: int, nums: List[int]):
        self.k = k
        self.heap = nums
        heapq.heapify(self.heap)
        while len(self.heap) > k:
            heapq.heappop(self.heap)

```
2. **Add Method:**
	- When a new value `val` is added:
		- If the heap size is less than `k`, simply push `val` into the heap.
		- Else, compare `val` with the smallest element in the heap (heap[0]):
			- If `val` is larger, replace the smallest element with `val`.
			- If `val` is smaller or equal, do nothing (since it won't affect the kth largest element).
		- Return the root of the heap, which is the kth largest element.
```python
    def add(self, val: int) -> int:
        if len(self.heap) < self.k:
            heapq.heappush(self.heap, val)
        elif val > self.heap[0]:
            heapq.heapreplace(self.heap, val)
        return self.heap[0]

```
**Complete Code:**
```python
import heapq

class KthLargest:

    def __init__(self, k: int, nums: List[int]):
        self.k = k
        self.heap = nums
        heapq.heapify(self.heap)
        # Maintain only k largest elements
        while len(self.heap) > k:
            heapq.heappop(self.heap)

    def add(self, val: int) -> int:
        # If heap has less than k elements, push val
        if len(self.heap) < self.k:
            heapq.heappush(self.heap, val)
        # If val is larger than the smallest in heap, replace it
        elif val > self.heap[0]:
            heapq.heapreplace(self.heap, val)
        # Return the kth largest element
        return self.heap[0]

```
**Time Complexity:**
- **Initialization (**`**__init__**`** method):**
	- Building the heap takes O(n) time, where `n` is the length of `nums`.
	- Reducing the heap size to `k` takes O((n - k) * log n) time due to `heappop` operations.
	- Overall initialization: **O(n) + O((n - k) * log n) ≈ O(n log k)** (since we only maintain a heap of size `k`).
- **Add Method (**`**add**`** method):**
	- Each `add` operation takes O(log k) time because the heap size is maintained at most `k`.
	- The `heappush`, `heappop`, and `heapreplace` operations are all O(log k).
**Space Complexity:**
- **O(k)**
	- The heap stores at most `k` elements regardless of the size of the stream.
___
#### **Alternative Approach: Using Binary Search Tree (BST) or Self-Balancing BST**
**Note:** This approach is generally not as efficient as the min-heap method but is worth mentioning.
**Algorithm Overview:**
- Use a BST to keep track of elements in a sorted manner.
- Each node keeps track of the count of nodes in its left subtree.
- Finding the kth largest element involves navigating the tree based on counts.
**Time Complexity:**
- **Insertion:** O(log n) on average, O(n) in the worst case (unbalanced tree).
- **Finding kth Largest:** O(log n) on average.
- **Overall:** Not optimal compared to the min-heap approach, especially considering the need to balance the tree.
**Space Complexity:**
- **O(n)**
	- Storing all elements in the BST.
**Recommendation:**
- The min-heap approach is preferred due to its efficiency in both time and space for this problem.
___
#### **Summary**
- **Min-Heap Approach:**
	- **Pros:**
		- Efficient `add` operation with O(log k) time complexity.
		- Maintains only `k` elements, optimizing space usage.
	- **Cons:**
		- None significant for this problem.
- **BST Approach:**
	- **Pros:**
		- Can handle additional operations like deletion or finding other order statistics.
	- **Cons:**
		- Higher time and space complexities.
		- More complex to implement.
**Conclusion:**
- The **min-heap approach** is the most optimal solution for **Kth Largest Element in a Stream**, offering efficient time complexity and minimal space usage.
___
**Example Usage:**
```python
# Initialize object
kthLargest = KthLargest(3, [4, 5, 8, 2])

# Adding elements and getting the kth largest
print(kthLargest.add(3))  # Returns 4
print(kthLargest.add(5))  # Returns 5
print(kthLargest.add(10)) # Returns 5
print(kthLargest.add(9))  # Returns 8
print(kthLargest.add(4))  # Returns 8

```
In this example, the heap maintains the three largest elements, and the `add` method efficiently updates and returns the kth largest element after each insertion.
### Notes
___
 
### Related Videos 
___
[hOjcdrqMoQ8](https://youtu.be/hOjcdrqMoQ8)