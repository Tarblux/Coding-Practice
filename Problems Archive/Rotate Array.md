# Rotate Array

Problem: 189
Official Difficulty: medium
Topic: Math, array, two pointers
Link: https://leetcode.com/problems/rotate-array/
Completed On : November 7, 2023
My Understanding: I Have No Idea
Last Review: November 7, 2023
Days Since Review: 95

## Problem

---

Given an integer array `nums`, rotate the array to the right by `k` steps, where `k` is non-negative.

**Example 1:**

```
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
```

**Example 2:**

```
Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation:
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
```

**Follow up:**

- Try to come up with as many solutions as you can. There are at least **three** different ways to solve this problem.
- Could you do it in-place with `O(1)` extra space?

## My Solutions

---

```python
class Solution(object):
    def rotate(self, nums, k):
        
        k = k % len (nums) 
        
        moved = []
        
        for i in range (len(nums)-k , len(nums) ) :
            
            moved.append(nums[i])
            
        for i in range (0 , len(nums) - k) : 
            
            moved.append(nums[i])
        
        for i in range (len(nums)) :
            nums[i] = moved [i]
        
        return nums
```

```python

```

## Optimal Solutions

---

To solve the problem of rotating an array to the right by `k` steps, we can use a three-step approach. This approach is efficient and doesn't require extra space for another array. Here's the general idea:

1. **Reverse the entire array**: This step reverses the whole array.
2. **Reverse the first `k` elements**: Since the array has been reversed, the last `k` elements of the original array are now at the beginning. Reverse these to put them in the correct order.
3. **Reverse the remaining `n-k` elements**: Finally, reverse the rest of the array to correct their order.

Note that `k` can be greater than the length of the array. In such cases, rotating the array `k` times is equivalent to rotating it `k % len(nums)` times.

Here's the implementation in Python:

```python
def rotate(nums, k):
    n = len(nums)
    k = k % n  # In case k is larger than the length of the array

    def reverse(start, end):
        while start < end:
            nums[start], nums[end] = nums[end], nums[start]
            start, end = start + 1, end - 1

    # Step 1: Reverse the entire array
    reverse(0, n - 1)

    # Step 2: Reverse the first k elements
    reverse(0, k - 1)

    # Step 3: Reverse the rest of the array
    reverse(k, n - 1)

# Example usage
nums = [1,2,3,4,5,6,7]
k = 3
rotate(nums, k)
print(nums)  # Output will be [5,6,7,1,2,3,4]

```

In this code:

- The `rotate` function first adjusts `k` to ensure it is within the bounds of the array's length.
- The `reverse` function is a helper function that reverses the elements of `nums` between indices `start` and `end`.
- We first reverse the entire array, then reverse the first `k` elements, and finally reverse the remaining `n - k` elements.

This solution has a time complexity of O(n) because each element is moved at most twice (once in the full array reversal and once in one of the partial reversals). The space complexity is O(1) since the reversal is done in place without using any additional data structures.

## Notes

---

Lorem Ipsum 

## Related Videos

---

[https://www.youtube.com/watch?v=BHr381Guz3Y](https://www.youtube.com/watch?v=BHr381Guz3Y)