Problem: 1133
Official Difficulty: easy
Link: https://leetcode.com/problems/largest-unique-number/description/
Completed On : 2024-10-06
Feels Like : easy
Topic: array, hash table, sorting
My Understanding: Fully Understand
Last Review: 2024-10-06
Days Since Review: 8
Name: Largest Unique Number

# Largest Unique Number
### Problem
___
Given an integer array `nums`, return *the largest integer that only occurs once*. If no integer occurs once, return `-1`.
**Example 1:**
```plain text
Input: nums = [5,7,3,9,4,9,8,3,1]
Output: 8
Explanation: The maximum integer in the array is 9 but it is repeated. The number 8 occurs only once, so it is the answer.
```
**Example 2:**
```plain text
Input: nums = [9,9,8,8]
Output: -1
Explanation: There is no number that occurs only once.
```
**Constraints:**
- `1 <= nums.length <= 2000`
- `0 <= nums[i] <= 1000`
### My Solutions
___
```python
class Solution:
    def largestUniqueNumber(self, nums: List[int]) -> int:

        largest = -1
        freq = Counter(nums)

        for num in nums:

            if freq[num] > 1:
                continue

            largest = max(num,largest)

        return largest    
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