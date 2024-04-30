# Integer Break

Problem: 343
Official Difficulty: medium
Feels Like : medium
My Understanding: Needs Review
Topic: Math, dynamic programming
Link: https://leetcode.com/problems/integer-break/description/
Completed On : April 2, 2024
Last Review: April 2, 2024
Days Since Review: 28

## Problem

---

Given an integer `n`, break it into the sum of `k` **positive integers**, where `k >= 2`, and maximize the product of those integers.

Return *the maximum product you can get*.

**Example 1:**

```
Input: n = 2
Output: 1
Explanation: 2 = 1 + 1, 1 × 1 = 1.
```

**Example 2:**

```
Input: n = 10
Output: 36
Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.
```

**Constraints:**

- `2 <= n <= 58`

## My Solutions

---

```python
class Solution:
    def integerBreak(self, n: int) -> int:

        producto = 1

        if n < 3: return 1

        if n == 3 : return 2
        
        while n > 4:

            producto *= 3

            n -= 3

        return producto * n
```

```python

```

## Optimal Solutions

---

The "Integer Break" problem is a classic optimization problem that can be solved using dynamic programming or mathematical observations. Given a positive integer `n`, the task is to break it into at least two positive integers that add up to `n` and then maximize the product of those integers.

### Dynamic Programming Approach

The dynamic programming approach involves breaking down the problem into smaller subproblems. For each integer `i` from 1 to `n`, you determine the maximum product you can get by breaking `i`. You use these subproblem solutions to build up the solution to the original problem.

Here's how you can implement the dynamic programming solution:

```python
def integerBreak(n: int) -> int:
    # dp[i] will store the maximum product we can get by breaking the number i
    dp = [0] * (n + 1)
    for i in range(2, n + 1):
        for j in range(1, i):
            # Break i into j and i-j, and choose the max between not breaking i-j further
            # (i.e., using j * (i-j)) and breaking i-j further (i.e., using j * dp[i-j])
            dp[i] = max(dp[i], j * (i - j), j * dp[i - j])
    return dp[n]

```

### Mathematical Approach

A mathematical observation shows that the maximum product can be obtained by breaking the integer into as many 3s as possible. If the remainder is 1, instead of having one 3 and one 1 (which multiplies to 3), it's better to have two 2s (which multiplies to 4). If the remainder is 2, it's simply added to the product.

Here's how you can implement the mathematical solution:

```python
def integerBreak(n: int) -> int:
    if n <= 3:
        return n - 1
    # Quotient and remainder when n is divided by 3
    quotient, remainder = divmod(n, 3)
    if remainder == 0:
        return 3 ** quotient
    elif remainder == 1:
        return 3 ** (quotient - 1) * 4
    else:  # remainder == 2
        return 3 ** quotient * 2

```

### Complexity Analysis

- **Dynamic Programming Approach**:
    - Time Complexity: O(n^2), because for each number up to `n`, we perform a linear number of comparisons.
    - Space Complexity: O(n), due to the storage requirements of the DP array.
- **Mathematical Approach**:
    - Time Complexity: O(1), as the solution involves simple arithmetic operations.
    - Space Complexity: O(1), as it only uses a fixed amount of space.

While the dynamic programming solution is more general and teaches important concepts, the mathematical solution is more efficient for this specific problem.

## Notes

---

 

## Related Videos

---

[https://www.youtube.com/watch?v=in6QbUPMJ3I](https://www.youtube.com/watch?v=in6QbUPMJ3I)