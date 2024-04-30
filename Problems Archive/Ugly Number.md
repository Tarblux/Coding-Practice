# Ugly Number

Problem: 263
Official Difficulty: easy
Feels Like : medium
My Understanding: Needs Review
Topic: Math
Link: https://leetcode.com/problems/ugly-number/description/
Completed On : March 12, 2024
Last Review: March 12, 2024
Days Since Review: 49

## Problem

---

An **ugly number** is a positive integer whose prime factors are limited to `2`, `3`, and `5`.

Given an integer `n`, return `true` *if* `n` *is an **ugly number***.

**Example 1:**

```
Input: n = 6
Output: true
Explanation: 6 = 2 × 3
```

**Example 2:**

```
Input: n = 1
Output: true
Explanation: 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.
```

**Example 3:**

```
Input: n = 14
Output: false
Explanation: 14 is not ugly since it includes the prime factor 7.
```

**Constraints:**

- `231 <= n <= 231 - 1`

## My Solutions

---

```python
class Solution:
    def isUgly(self, n: int) -> bool:

        if n <= 0:
            return False 

        factors = [2,3,5]

        for factor in factors:

            while n % factor == 0:

                n = n // factor

        return n == 1
```

```python
class Solution:
    def isUgly(self, n: int) -> bool:
        while n >= 1:
            if n%2 == 0:
                n=n//2
            elif n%3 == 0:
                n=n//3
            elif n%5 == 0:
                n=n//5
            elif n == 1:
                return True
            else:
                return False
```

## Optimal Solutions

---

An "Ugly Number" is a positive number whose prime factors only include 2, 3, and 5. The first 10 ugly numbers are 1, 2, 3, 4, 5, 6, 8, 9, 10, and 12. By convention, 1 is typically treated as an ugly number.

### Problem Statement:

Write a program to check whether a given number is an ugly number.

### Solution Approach:

To determine if a number is an ugly number, we can repeatedly divide the number by 2, 3, and 5 (the only prime factors for an ugly number) as long as it is divisible by these numbers. If we end up with 1, then the number is an ugly number. If we end up with a number other than 1, the number is not an ugly number.

Here's how you can implement it in Python:

```python
class Solution:
    def isUgly(self, num: int) -> bool:
        if num <= 0:  # Check for non-positive numbers
            return False

        # Divide num by 2, 3, and 5 as long as possible
        for p in [2, 3, 5]:
            while num % p == 0:
                num //= p

        # If we end up with 1, then it's an ugly number
        return num == 1

```

### Explanation:

1. **Handle Non-positive Numbers**: First, check if the number is less than or equal to 0. If so, return `False` because an ugly number has to be positive.
2. **Divide by Prime Factors**: Loop through a list containing 2, 3, and 5. For each prime factor `p`, use a `while` loop to divide `num` by `p` as long as `num` is divisible by `p`. This strips off factors of 2, 3, and 5 from `num`.
3. **Check for Ugliness**: After the division process, if `num` has been reduced to 1, then it only had 2, 3, and/or 5 as its prime factors, and we return `True`. If `num` is anything other than 1, it had other prime factors, so we return `False`.

### Complexity Analysis:

- **Time Complexity**: O(log n), where n is the input number. The time complexity depends on the number of times we can divide `num` by 2, 3, or 5, which in practice results in a logarithmic time complexity with respect to `num`.
- **Space Complexity**: O(1), as the algorithm uses a constant amount of space regardless of the input size.

## Notes

---

 

## Related Videos

---

[https://www.notion.so](https://www.notion.so)