Problem: 215
Official Difficulty: medium
Link: https://leetcode.com/problems/kth-largest-element-in-an-array/description/
Completed On : 2024-10-19
Feels Like : easy
Topic: array, Divide and Conquer, sorting, Heap(Priority Queue), quickselect
My Understanding: Fully Understand
Last Review: 2024-10-19
Days Since Review: 1
Name: Kth Largest Element in an Array

# Kth Largest Element in an Array
### Problem
___
Given an integer array `nums` and an integer `k`, return *the* `kth` *largest element in the array*.
Note that it is the `kth` largest element in the sorted order, not the `kth` distinct element.
Can you solve it without sorting?
**Example 1:**
```plain text
Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
```
**Example 2:**
```plain text
Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4
```
**Constraints:**
- `1 <= k <= nums.length <= 105`
- `104 <= nums[i] <= 104`
### My Solutions
___
```python
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:

        heap = []

        for num in nums:
            heapq.heappush(heap,num)

        return heapq.nlargest(k+1,heap)[k-1]
```

Time Complexity :
```python

```

Time Complexity : 
### Optimal Solutions
___

### Notes
___
 
### Related Videos 
___
[]()