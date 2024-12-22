Problem: 371
Official Difficulty: medium
Link: https://leetcode.com/problems/sum-of-two-integers/description/
Completed On : 2024-12-18
Feels Like : Brain Damage
Topic: Math, Bit Manipulation
My Understanding: I Have No Idea
Last Review: 2024-12-18
Days Since Review: 4
Name: Sum of Two Integers

# Sum of Two Integers
### Problem
___
Given two integers `a` and `b`, return *the sum of the two integers without using the operators* `+` *and* `-`.
**Example 1:**
```plain text
Input: a = 1, b = 2
Output: 3
```
**Example 2:**
```plain text
Input: a = 2, b = 3
Output: 5
```
**Constraints:**
- `1000 <= a, b <= 1000`
### My Solutions
___
```python
class Solution:
    def getSum(self, a: int, b: int) -> int:
        mask = 0xFFFFFFFF
        
        while b != 0:
            a, b = (a ^ b) & mask, ((a & b) << 1) & mask
        
        max_int = 0x7FFFFFFF
        return a if a < max_int else ~(a ^ mask)
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