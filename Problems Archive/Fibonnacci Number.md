Problem: 509
Official Difficulty: easy
Link: https://leetcode.com/problems/fibonacci-number/description/
Completed On : 2024-11-25
Feels Like : easy breazy
Topic: Math, dynamic programming, recursion, memoization
My Understanding: Fully Understand
Last Review: 2024-11-25
Days Since Review: 6
Name: Fibonnacci Number

# Fibonnacci Number
### Problem
___
The **Fibonacci numbers**, commonly denoted `F(n)` form a sequence, called the **Fibonacci sequence**, such that each number is the sum of the two preceding ones, starting from `0` and `1`. That is,
```plain text
F(0) = 0, F(1) = 1
F(n) = F(n - 1) + F(n - 2), for n > 1.
```
Given `n`, calculate `F(n)`.
**Example 1:**
```plain text
Input: n = 2
Output: 1
Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.
```
**Example 2:**
```plain text
Input: n = 3
Output: 2
Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.
```
**Example 3:**
```plain text
Input: n = 4
Output: 3
Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.
```
**Constraints:**
- `0 <= n <= 30`
### My Solutions
___
```python
class Solution:
    def fib(self, n: int) -> int:

        if n <= 1:
            return n

        return self.fib(n-1) + self.fib(n-2)
```

Time Complexity :
```python
class Solution:
    def fib(self, N: int) -> int:
        if N <= 1:
            return N
        
        cache = [0] * (N + 1)
        cache[1] = 1
        for i in range(2, N + 1):
            cache[i] = cache[i - 1] + cache[i - 2]

        return cache[N]
```

Time Complexity : 
### Optimal Solutions
___

### Notes
___
 
### Related Videos 
___
[watch](https://www.youtube.com/watch?v=dDokMfPpfu4&t=232s&pp=ygUVNTA5LiBmaWJvbmFjY2kgbnVtYmVy)