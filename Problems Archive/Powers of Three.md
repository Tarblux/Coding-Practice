# Powers of Three

Problem: 326
Official Difficulty: easy
Feels Like : easy
Topic: Math
Link: https://leetcode.com/problems/power-of-three/
Completed On : December 7, 2023
My Understanding: Mostly Understand
Last Review: December 7, 2023
Days Since Review: 65

## Problem

---

Given an integer `n`, return *`true` if it is a power of three. Otherwise, return `false`*.

An integer `n` is a power of three, if there exists an integer `x` such that `n == 3x`.

**Example 1:**

```
Input: n = 27
Output: true
Explanation: 27 = 33
```

**Example 2:**

```
Input: n = 0
Output: false
Explanation: There is no x where 3x = 0.

```

**Example 3:**

```
Input: n = -1
Output: false
Explanation: There is no x where 3x = (-1).

```

**Constraints:**

- `231 <= n <= 231 - 1`

**Follow up:**

Could you solve it without loops/recursion?

## My Solutions

---

```python
class Solution:
    def isPowerOfThree(self, n: int) -> bool:
        
        if n == 1 : 
            
            return True
        
        if n % 3 != 0 :
            
            return False 
        
        
        while n > 1 : 
            
            n /= 3 
            
        
        return n == 1
```

```python

```

## Optimal Solutions

---

The "Powers of Three" problem usually involves determining if a given number can be expressed as a power of three. The goal is to check if a number `n` is of the form 3^x, where x is a non-negative integer.

### Solution Approach

To solve this, you can keep dividing the number by 3 as long as it remains an integer, and eventually, if the number can be expressed as a power of three, you will end up with 1. Alternatively, for positive numbers, you can use the properties of logarithms to check if the log base 3 of the number is an integer.

### Python Implementation

Here's a Python implementation using the division approach:

```python
class Solution:
    def isPowerOfThree(self, n: int) -> bool:
        if n < 1:
            return False
        while n % 3 == 0:
            n //= 3
        return n == 1

```

And here's the implementation using logarithms:

```python
import math

class Solution:
    def isPowerOfThree(self, n: int) -> bool:
        if n <= 0:
            return False
        # Calculate the logarithm base 3 and check if it is an integer
        log_res = math.log(n, 3)
        return math.isclose(log_res, round(log_res))

```

### Explanation

1. **Division Approach**:
    - If `n` is less than 1, return `False` since the powers of three are positive numbers.
    - Keep dividing `n` by 3 if it is divisible by 3.
    - After the loop, if `n` becomes 1, it means `n` can be expressed as a power of three, otherwise not.
2. **Logarithmic Approach**:
    - If `n` is less than or equal to 0, return `False`.
    - Calculate the base 3 logarithm of `n`. If `n` is a power of three, this logarithm should be a whole number.
    - Use `math.isclose` to compare the calculated log with its nearest integer value to account for floating-point arithmetic errors.

### Complexity Analysis

- **Time Complexity**:
    - For the division approach, it's O(log_3 n), since you divide the number by 3 in each step.
    - For the logarithmic approach, it's O(1), assuming that the logarithm and `math.isclose` functions are constant time.
- **Space Complexity**: Both methods use O(1) extra space.

## Notes

---

 

## Related Videos

---

[https://youtu.be/GNb8vSyw-WE?si=IQb7TGOkljZOlX3_](https://youtu.be/GNb8vSyw-WE?si=IQb7TGOkljZOlX3_)