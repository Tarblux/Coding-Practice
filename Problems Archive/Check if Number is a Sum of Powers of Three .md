# Check if Number is a Sum of  Powers of Three

Problem: 1780
Official Difficulty: medium
Feels Like : medium
My Understanding: Mostly Understand, Needs Review
Topic: Math
Link: https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three/description/?envType=daily-question&envId=2025-03-04
Completed On : March 3, 2025
Last Review: March 3, 2025
Days Since Review: 6
Neetcode: No

## Problem

---

Given an integer `n`, return `true` *if it is possible to represent* `n` *as the sum of distinct powers of three.* Otherwise, return `false`.

An integer `y` is a power of three if there exists an integer `x` such that `y == 3x`.

**Example 1:**

```
Input: n = 12
Output: true
Explanation: 12 = 31 + 32
```

**Example 2:**

```
Input: n = 91
Output: true
Explanation: 91 = 30 + 32 + 34
```

**Example 3:**

```
Input: n = 21
Output: false
```

**Constraints:**

- `1 <= n <= 107`

## My Solutions

---

```python
class Solution:
    def checkPowersOfThree(self, n: int) -> bool:

        valid_ternary = [0,1]

        while n > 0:

            remainder = n % 3 
            if remainder not in valid_ternary:
                return False
            n //= 3

        return True     
```

```python

```

## Optimal Solutions

---

### **Approach 3: Ternary Representation**

### **Intuition**

First, let's break the problem down into a more familiar one. We know that every number can be written as a sum of distinct powers of 2 — in other words, every number has a unique binary representation. A simple way to find the binary representation of a number is by repeatedly taking its remainder when divided by 2 (mod 2) and then dividing the number by 2 to move to the next bit. This method is similar to the two’s complement approach.

In this problem, we apply the same logic but in base 3 instead of base 2. We construct the ternary representation of the given number by taking its remainder when divided by 3 (mod 3) and then dividing it by 3 to proceed to the next digit. If any of these remainders equals 2, we would need to use a power of 3 twice, which is not allowed. In that case, we immediately return `false`.

### **Algorithm**

- While `n` is greater than `0`:
    - If `n % 3 == 2`, we would have to use the current power twice, so return `false`.
    - Divide `n` by `3`.
- If the loop ends without returning `false`, it means that `n` has a ternary representation consisting only of `0` and `1`, so it can be written as a sum of distinct powers of `3`; return `true`.

```python
class Solution:
    def checkPowersOfThree(self, n: int) -> bool:
        while n > 0:
            # Check if this power should be used twice
            if n % 3 == 2:
                return False
            # Divide n by 3 to move to the next greater power
            n //= 3
        # The ternary representation of n consists only of 0s and 1s
        return True
```

### **Implementation**

### **Complexity Analysis**

- Time complexity: *O*(log3​*n*)
    
    We enter a loop where we constantly divide *n* by 3 until it reaches 0. The loop will run at most *O*(log3​*n*) times and each iteration performs only constant time operations (modulo, equality check, and division), therefore the total time complexity is *O*(log3​*n*).
    
- Space complexity: *O*(1)
    
    The algorithm does not use any additional space for data structures or recursion and therefore its space complexity is constant (*O*(1)).
    

## Notes

---

 

## Related Videos

---

[https://www.notion.so](https://www.notion.so)