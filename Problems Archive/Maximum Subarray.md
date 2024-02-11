# Maximum Subarray

Problem: 53
Official Difficulty: medium
Feels Like : medium
Topic: Divide and Conquer, array, dynamic programming
Link: https://leetcode.com/problems/maximum-subarray/description/
Completed On : January 7, 2024
My Understanding: Mostly Understand
Last Review: January 7, 2024
Days Since Review: 34

## Problem

---

Given an integer array `nums`, find the subarray with the largest sum, and return *its sum*

.

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

```python

```

## Optimal Solutions

---

The "Maximum Subarray" problem, also known as Kadane's algorithm, is a classic problem in computer science. The goal is to find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

### Problem Statement

Given an integer array `nums`, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

### Solution Approach

Kadane's algorithm involves iterating through the array and at each step, calculating the maximum subarray sum ending at that position. This is achieved by maintaining a running sum and resetting it whenever it becomes negative.

### Python Implementation

```python
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        max_sum = current_sum = nums[0]

        for num in nums[1:]:
            current_sum = max(num, current_sum + num)
            max_sum = max(max_sum, current_sum)

        return max_sum
```

### Explanation

- Initialize `max_sum` and `current_sum` with the first element of `nums`. This handles the case where `nums` contains only one element or all non-positive numbers.
- Iterate through the array starting from the second element.
- Update `current_sum` by taking the maximum of the current number (`num`) and the sum of `current_sum` and `num`. This effectively "resets" the running sum if it becomes negative, as a negative running sum would only decrease the sum of any subsequent subarrays.
- Update `max_sum` to be the maximum of itself and the new `current_sum`. This ensures that `max_sum` always holds the largest sum encountered so far.

### Complexity Analysis

- **Time Complexity**: O(n), where n is the number of elements in `nums`. Each element is processed once.
- **Space Complexity**: O(1), as only a constant amount of extra space is used.

Kadane's algorithm is efficient and elegant, and it's the standard approach for solving the "Maximum Subarray" problem due to its optimal time complexity and straightforward implementation.

## Notes

---

 

## Related Videos

---

[https://www.youtube.com/watch?v=5WZl3MMT0Eg](https://www.youtube.com/watch?v=5WZl3MMT0Eg)