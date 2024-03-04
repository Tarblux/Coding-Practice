# Power of Two

Problem: 231
Official Difficulty: easy
Feels Like : easy
My Understanding: Fully Understand
Topic: Bit Manipulation, Math, recursion
Link: https://leetcode.com/problems/power-of-two/description/
Completed On : February 27, 2024
Last Review: February 27, 2024
Days Since Review: 5

## Problem

---

Given an integer `n`, return *`true` if it is a power of two. Otherwise, return `false`*.

An integer `n` is a power of two, if there exists an integer `x` such that `n == 2x`.

**Example 1:**

```
Input: n = 1
Output: true
Explanation:20 = 1
```

**Example 2:**

```
Input: n = 16
Output: true
Explanation:24 = 16
```

**Example 3:**

```
Input: n = 3
Output: false
```

**Constraints:**

- `231 <= n <= 231 - 1`

**Follow up:**

Could you solve it without loops/recursion?

## My Solutions

---

```python
class Solution:
    def isPowerOfTwo(self, n: int) -> bool:

        if n == 0 : 

            return False

        binaries = 0

        for i in range(33) : 

            if n&1 == True : 

                binaries += 1

                if binaries > 1 : 

                    return False 

            n >>= 1

        return True
```

```python

```

## Optimal Solutions

---

### Approach

There are several ways to solve this problem. Here are two common approaches:

1. **Bit Manipulation**: This is the most efficient approach. A number \(n\) is a power of two if it has exactly one bit set in its binary representation. For example, \(2^3 = 8\) is `1000` in binary, and \(2^5 = 32\) is `100000`. We can use the trick \(n \& (n - 1) = 0\) to check if \(n\) is a power of two. This expression removes the lowest set bit from \(n\). If \(n\) had only one set bit, removing it gives \(0\).
2. **Mathematical**: Check if the logarithm of \(n\) to the base 2 is an integer. However, due to floating-point precision issues, this might not always give accurate results for very large numbers.

### Bit Manipulation Solution

Here's how you can implement the bit manipulation approach in Python:

```python
class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        # A power of two has exactly one bit set, so n & (n-1) should be 0.
        # Also, n should be positive.
        return n > 0 and (n & (n - 1)) == 0

```

### Explanation

- The expression `n > 0` ensures that \(n\) is positive because, by definition, a power of two cannot be negative or zero.
- The expression `(n & (n - 1)) == 0` checks if \(n\) has exactly one bit set:
    - If \(n\) is a power of two, subtracting 1 from it flips all the bits after the rightmost set bit (including the rightmost set bit itself). Therefore, performing an AND operation between \(n\) and \(n - 1\) results in zero because \(n\) has only one set bit and \(n - 1\) has all bits set to the right of that bit.
- Together, these conditions effectively check if \(n\) is a power of two.

### Complexity Analysis

- **Time Complexity**: \(O(1)\) — The time taken is constant as it involves only a few bitwise operations and basic arithmetic, regardless of the size of \(n\).
- **Space Complexity**: \(O(1)\) — No extra space is used except for a few variables, so the space complexity is constant.

## Extra Solution

```python
class Solution:
    # Any power of 2 minus 1 is all ones: (2^N - 1 = 111....b)
    def isPowerOfTwo(self, n: int) -> bool:
        if n <= 0:
            return False
        if n == 1:
            return True
        # Example with 8: 0100 & (0100 - 1) --> (0100 & 0011) --> 0000
        return n & (n - 1) == 0
```

## Notes

---

 

## Related Videos

---

[https://www.youtube.com/watch?v=H2bjttEV4Vc](https://www.youtube.com/watch?v=H2bjttEV4Vc)