# Missing Number

Problem: 268
Official Difficulty: easy
Feels Like : easy
Topic: Bit Manipulation, Math, array
Link: https://leetcode.com/problems/missing-number/
Completed On : December 11, 2023
My Understanding: Fully Understand
Last Review: December 11, 2023
Days Since Review: 61

## Problem

---

Given an array `nums` containing `n` distinct numbers in the range `[0, n]`, return *the only number in the range that is missing from the array.*

**Example 1:**

```
Input: nums = [3,0,1]
Output: 2
Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.

```

**Example 2:**

```
Input: nums = [0,1]
Output: 2
Explanation: n = 2 since there are 2 numbers, so all numbers are in the range [0,2]. 2 is the missing number in the range since it does not appear in nums.

```

**Example 3:**

```
Input: nums = [9,6,4,2,3,5,7,0,1]
Output: 8
Explanation: n = 9 since there are 9 numbers, so all numbers are in the range [0,9]. 8 is the missing number in the range since it does not appear in nums.

```

**Constraints:**

- `n == nums.length`
- `1 <= n <= 104`
- `0 <= nums[i] <= n`
- All the numbers of `nums` are **unique**.

**Follow up:** Could you implement a solution using only `O(1)` extra space complexity and `O(n)` runtime complexity?

## My Solutions

---

```python
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        
        s_nums = sorted(nums)
        
        if s_nums[0] != 0:
            
            return 0
        
        for i in range (0,len(s_nums)-1) : 
            
            if s_nums[i+1] != s_nums[i] + 1 : 
                
                return s_nums[i] + 1 
                   
        return s_nums[-1] + 1
```

### Sanya

```python
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        
        expectedSum = 0
        for i in range(len(nums) + 1):
            expectedSum += i
        realSum = 0
        for i in nums:
            realSum += i
        return  expectedSum - realSum
        
        
#         maxVal = 0
#         minVal = 2 ** 31 - 11
#         total = 0
#         for num in nums: 
#             if minVal > num:
#                 minVal = num
                
#             if maxVal < num:
#                 maxVal = num
            
#             total += num
            
#         for i in range(minVal, maxVal + 1):
#             total -= i
    
#         if total == 0:
#             return maxVal + 1
    
#         if maxVal == minVal:
#             return 0
    
#          return abs(total)
```

### Big Play Zwea

```python
class Solution(object):
    def missingNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # find the size
        size = len(nums)
#         print("the expected sum: ", sum(range(size+1)))
#         print("the actual sum: ", sum(nums))
        
        return sum(range(size+1)) - sum(nums)

```

## Optimal Solutions

---

The "Missing Number" problem is a classic problem in computer science where you're given a sequence containing `n` distinct numbers taken from the range `0` to `n`, and you have to find the number that is missing from the sequence.

### Solution Approach

A very efficient way to solve this problem is to use the property of XOR (exclusive OR). XOR of a number with itself is 0, and XOR of a number with 0 is the number itself. Also, XOR is commutative and associative, which means the order in which you perform XOR operations doesn't matter.

### Python Implementation

```python
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        missing = len(nums)  # Initial value set to n (length of nums)
        for i, num in enumerate(nums):
            missing ^= i ^ num
        return missing

```

### Explanation

- The `missing` variable is initially set to `n` (the length of `nums`), as it's the extra element not present in the index range (0 to n-1).
- We then iterate through the list, XORing the `missing` variable with both the index and the value at that index.
- Since every number and its index will be present exactly once except for the missing number, all those will cancel out, leaving us with the missing number.

### Alternative Approach: Summation

Another approach is to use the sum formula. The sum of the first `n` natural numbers is `n * (n + 1) / 2`. You can find the missing number by subtracting the sum of the array from this total.

```python
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        n = len(nums)
        total_sum = n * (n + 1) // 2
        array_sum = sum(nums)
        return total_sum - array_sum

```

### Complexity Analysis

- **Time Complexity**: O(n), where `n` is the number of elements in the array. We only need to traverse the array once.
- **Space Complexity**: O(1), as no extra space is required beyond variable storage.

## Notes

---

 

## Related Videos

---

[https://www.notion.so](https://www.notion.so)