Problem: 239
Official Difficulty: hard
Link: https://leetcode.com/problems/sliding-window-maximum/description/
Completed On : 2024-12-14
Feels Like : Brain Damage
Topic: array, Queue, sliding window, Heap(Priority Queue), monotonic queue
My Understanding: Needs Review
Last Review: 2024-12-14
Days Since Review: 8
Name: Sliding Window Maximum

# Sliding Window Maximum
### Problem
___
You are given an array of integers `nums`, there is a sliding window of size `k` which is moving from the very left of the array to the very right. You can only see the `k` numbers in the window. Each time the sliding window moves right by one position.
Return *the max sliding window*.
**Example 1:**
```plain text
Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation:
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  73
 1 [3  -1  -3] 5  3  6  73
 1  3 [-1  -3  5] 3  6  7 5
 1  3  -1 [-3  5  3] 6  75
 1  3  -1  -3 [5  3  6] 76
 1  3  -1  -3  5 [3  6  7]7
```
**Example 2:**
```plain text
Input: nums = [1], k = 1
Output: [1]

```
**Constraints:**
- `1 <= nums.length <= 105`
- `104 <= nums[i] <= 104`
- `1 <= k <= nums.length`
### My Solutions
___
```python
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:

        window = deque() 
        result = []
        
        for i in range(len(nums)):

            if window and window[0] == i - k:
                window.popleft()
            
            while window and nums[window[-1]] < nums[i]:
                window.pop()
            
            window.append(i)
            
            if i >= k - 1:
                result.append(nums[window[0]])
        
        return result
```

Time Complexity :
```python

```

Time Complexity : 
### Optimal Solutions
___
We use a **monotonic deque** approach to solve the sliding window maximum in O(n) time. The idea is to maintain a deque of indices that always represent potential maximum elements for the current window. The deque is kept in decreasing order of values (front holds the largest element):
**Steps:**
1. Iterate over indices `i` in `nums`:
	- While the deque is not empty and `nums[i]` is greater than or equal to the element at the back of the deque, pop from the back. This ensures that elements that can no longer be a maximum due to the new larger element are removed.
	- Append `i` to the deque.
	- If `i` is at least `k-1`, we have our first full window. The front of the deque gives the index of the maximum in the current window. Append `nums[deque[0]]` to the result.
	- Also, if the front of the deque is out of the current window (index < i-k+1), pop it from the front.
**Code:**
```python
from collections import deque

class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        dq = deque()
        res = []

        for i, val in enumerate(nums):
            # Remove elements smaller than current
            while dq and nums[dq[-1]] <= val:
                dq.pop()

            dq.append(i)

            # Ensure the window size
            if i >= k and dq[0] == i - k:
                dq.popleft()

            # Start adding to results once the first window is formed
            if i >= k - 1:
                res.append(nums[dq[0]])

        return res

```
### Notes
___
 
### Related Videos 
___
[DfljaUwZsOk](https://youtu.be/DfljaUwZsOk)