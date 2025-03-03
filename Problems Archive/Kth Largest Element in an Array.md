# Kth Largest Element in an Array

Problem: 215
Official Difficulty: medium
Feels Like : easy
My Understanding: Fully Understand
Topic: Divide and Conquer, Heap(Priority Queue), array, quickselect, sorting
Link: https://leetcode.com/problems/kth-largest-element-in-an-array/description/
Completed On : October 19, 2024
Last Review: October 19, 2024
Days Since Review: 134
Neetcode: Yes

## Problem

---

Given an integer array `nums` and an integer `k`, return *the* `kth` *largest element in the array*.

Note that it is the `kth` largest element in the sorted order, not the `kth` distinct element.

Can you solve it without sorting?

**Example 1:**

```
Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
```

**Example 2:**

```
Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4
```

**Constraints:**

- `1 <= k <= nums.length <= 105`
- `104 <= nums[i] <= 104`

## My Solutions

---

```python
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:

        heap = []

        for num in nums:
            heapq.heappush(heap,num)

        return heapq.nlargest(k+1,heap)[k-1]
```

```python

```

## Optimal Solutions

---

## Notes

---

 

## Related Videos

---

[https://www.notion.so](https://www.notion.so)