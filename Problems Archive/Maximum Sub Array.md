# Maximum Sub Array

Problem: 53
Official Difficulty: easy
Feels Like : medium
Topic: Divide and Conquer, array, dynamic programming
Link: https://leetcode.com/problems/maximum-subarray/
Completed On : December 4, 2023
My Understanding: I Have No Idea
Last Review: December 4, 2023
Days Since Review: 68

## Problem

---

Given an integer array `nums`, find the subarray with the largest sum, and return *its sum*.

**Example 1:**

```
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.

```

**Example 2:**

```
Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.

```

**Example 3:**

```
Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.

```

**Constraints:**

- `1 <= nums.length <= 105`
- `104 <= nums[i] <= 104`

**Follow up:** If you have figured out the `O(n)` solution, try coding another solution using the **divide and conquer** approach, which is more subtle.

## My Solutions

---

```python
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        
        if not nums:
            return 0

        max_sum = nums[0]  
        current_sum = nums[0]  

        for num in nums[1:]:
            current_sum = max(num, current_sum + num)  
            max_sum = max(max_sum, current_sum)  

        return max_sum
```

This was my original solution but it is too slow , apparently I only need to do the shrink from both sides instead of from left or right

```python
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        
        
        
        total_sum = sum(nums)
        
        size = len(nums)
        
        max_sum1 = total_sum 
        
        max_sum2 = total_sum 
        
        max_sum3 = total_sum  
        
#         # Shrink from the right
#         for i in range(size):
            
#             new_sum = sum(nums[:size - i])
            
#             max_sum1 = max(max_sum1, new_sum)
        
#         # Shrink from left
#         for i in range(size):
            
#             new_sum = sum(nums[i:])
            
#             max_sum2 = max(max_sum2, new_sum)
        
        # Shrink from both sides
        for i in range(size):
            
            for j in range(i, size):
                
                new_sum = sum(nums[i:size - j + i])
                
                max_sum3 = max(max_sum3, new_sum)
                
        return max(max_sum1, max_sum2, max_sum3)
```

## Optimal Solutions

---

"Maximum Subarray" is a famous problem in computer science, often solved using dynamic programming or divide-and-conquer approaches. The problem statement is as follows:

Given an integer array `nums`, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

### Solution Approach: Kadane's Algorithm

The most efficient way to solve this problem is to use Kadane's Algorithm. This algorithm maintains a running sum of the maximum subarray ending at each position in the array. It then updates the global maximum sum found so far.

### Algorithm

1. Initialize two variables, `max_current` and `max_global`, to the first element of the array.
2. Iterate over the array starting from the second element. For each element `nums[i]`:
    - Update `max_current` to be the maximum of `nums[i]` and `max_current + nums[i]`. This step decides whether to extend the current subarray or start a new subarray from the current element.
    - Update `max_global` if `max_current` is greater than `max_global`.
3. After iterating through the array, `max_global` contains the sum of the maximum subarray.

### Complexity Analysis

- **Time Complexity**: O(n), where n is the length of the array. We scan the array only once.
- **Space Complexity**: O(1), as we only use a constant amount of extra space.

### Python Implementation

```python
def maxSubArray(nums):
    if not nums:
        return 0

    max_current = max_global = nums[0]

    for i in range(1, len(nums)):
        max_current = max(nums[i], max_current + nums[i])
        if max_current > max_global:
            max_global = max_current

    return max_global

```

### Explanation

The key idea of Kadane's Algorithm is to maintain a running sum (`max_current`) of the maximum subarray ending at each index. We compare each element of the array with the sum of `max_current` and itself, and choose the larger one to decide whether to extend the current subarray or start a new one. Simultaneously, we keep track of the maximum sum seen so far in `max_global`. This algorithm efficiently finds the maximum sum subarray with a single pass through the input array.

## Notes

---

## Related Videos

---

[https://www.youtube.com/watch?v=5WZl3MMT0Eg](https://www.youtube.com/watch?v=5WZl3MMT0Eg)