# Sqrt(x)

Problem: 69
Official Difficulty: easy
Feels Like : medium
My Understanding: Needs Review
Topic: Math, binary search
Link: https://leetcode.com/problems/sqrtx/description/
Completed On : March 17, 2024
Last Review: March 17, 2024
Days Since Review: 44

## Problem

---

Given a non-negative integer `x`, return *the square root of* `x` *rounded down to the nearest integer*. The returned integer should be **non-negative** as well.

You **must not use** any built-in exponent function or operator.

- For example, do not use `pow(x, 0.5)` in c++ or `x ** 0.5` in python.

**Example 1:**

```
Input: x = 4
Output: 2
Explanation: The square root of 4 is 2, so we return 2.
```

**Example 2:**

```
Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.
```

**Constraints:**

- `0 <= x <= 231 - 1`

## My Solutions

---

```python
class Solution:
    def mySqrt(self, x: int) -> int:

        l,r = 0,x
        output= 0

        while l<=r:
            m = l + ((r-l)//2)

            if m*m > x:
                r = m - 1
            elif m*m < x:
                l = m + 1
                output = m
            else:
                return m
        
        return output
```

```python

```

## Optimal Solutions

---

To compute the integer part of the square root of a given non-negative integer `x`, you can use binary search due to the sorted nature of the range `[0, x]`. The idea is to find the largest number `y` such that `y*y <= x`.

Here's how you can implement it:

### Algorithm:

1. **Initialize**: Set two pointers, `left = 0` and `right = x`. The answer will be within this range.
2. **Binary Search**: While `left <= right`, do the following:
    - Compute the middle of the current range, `mid = left + (right - left) // 2`.
    - Compare `mid * mid` with `x` to decide if you need to search in the left half (`mid * mid > x`) or the right half (`mid * mid <= x`). The right half includes `mid` because even if `mid * mid == x`, `mid` is a valid square root.
    - If `mid * mid <= x`, update `left` to `mid + 1` and keep track of `mid` as a potential answer.
    - Else, update `right` to `mid - 1`.
3. **Result**: After the loop, `left` will be just greater than the square root of `x`. Since we are looking for the integer part, return `right`, which will be the largest integer whose square is less than or equal to `x`.

### Implementation:

```python
class Solution:
    def mySqrt(self, x: int) -> int:
        if x < 2:
            return x

        left, right = 1, x // 2
        while left <= right:
            mid = left + (right - left) // 2
            if mid * mid <= x:
                left = mid + 1
            else:
                right = mid - 1
        return right
```

### Explanation:

- **Special Case**: If `x` is less than 2, its square root is itself (`0` or `1`), so return `x`.
- **Optimization**: For `x >= 2`, the square root is always less than or equal to `x // 2` (integer division). Hence, the initial range is `[1, x // 2]`.
- **Binary Search**: The binary search reduces the search space by half at each step, finding the largest `mid` such that `mid * mid <= x`.
- **Return Value**: `right` is returned because, at the end of the loop, `right` is the highest value meeting the condition `mid * mid <= x`.

### Complexity Analysis:

- **Time Complexity**: O(log x), since the algorithm uses binary search, cutting the search space in half at each step.
- **Space Complexity**: O(1), as the solution uses a constant amount of space.

## Notes

---

 

## Related Videos

---

[https://www.youtube.com/watch?v=zdMhGxRWutQ](https://www.youtube.com/watch?v=zdMhGxRWutQ)