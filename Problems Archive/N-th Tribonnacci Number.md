# N-th Tribonnacci Number

Problem: 1137
Official Difficulty: easy
Feels Like : easy
My Understanding: Mostly Understand
Topic: Math, dynamic programming, memoization
Link: https://leetcode.com/problems/n-th-tribonacci-number/description/
Completed On : January 10, 2025
Last Review: January 10, 2025
Days Since Review: 51
Neetcode: No

## Problem

---

The Tribonacci sequence Tn is defined as follows:

T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.

Given `n`, return the value of Tn.

**Example 1:**

```
Input: n = 4
Output: 4
Explanation:
T_3 = 0 + 1 + 1 = 2
T_4 = 1 + 1 + 2 = 4
```

**Example 2:**

```
Input: n = 25
Output: 1389537
```

**Constraints:**

- `0 <= n <= 37`
- The answer is guaranteed to fit within a 32-bit integer, ie. `answer <= 2^31 - 1`.

## My Solutions

---

```python

class Solution:
    def tribonacci(self, n: int) -> int:

        memo = {}
        base = [0,1,1]

        def tribo(n):

            if n <= 2:
                return base[n]

            if n in memo:
                return memo[n]

            memo[n] = tribo(n-1) + tribo(n-2) + tribo(n-3)

            return memo[n]

        return tribo(n)
```

```python
class Solution:
    def tribonacci(self, n: int) -> int:

        if n == 0:
            return 0

        dp = [0,1,1] 

        for i in range(3,n+1):

            dp[i%3] = sum(dp)

        return max(dp)
```

## Optimal Solutions

---

**Intuition**

- The Tribonacci sequence generalizes the Fibonacci idea:
    
    T(n)=T(n−1)+T(n−2)+T(n−3)  T(n) = T(n-1) + T(n-2) + T(n-3)
    
- The first three terms are typically defined as , , .
    
    T(0)=0T(0) = 0
    
    T(1)=1T(1) = 1
    
    T(2)=1T(2) = 1
    
- Because each term depends on the previous three, using dynamic programming avoids recalculating subproblems.

---

**Approach**

- **Top-Down (Memoized)**
    1. Recursively compute `tribonacci(n)` = `tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3)`.
    2. Use a dictionary or array to store computed results so each state is solved only once.
- **Bottom-Up (Tabulated)**
    1. Build a `dp` array from `0` up to `n`.
    2. Initialize `dp[0]=0`, `dp[1]=1`, `dp[2]=1`.
    3. For each `i` from 3 to `n`, do `dp[i] = dp[i-1] + dp[i-2] + dp[i-3]`.
    4. Return `dp[n]`.

---

## Code

```python
def tribonacci_top_down(n):
    memo = {}

    def helper(k):
        if k == 0:
            return 0
        elif k == 1 or k == 2:
            return 1
        if k in memo:
            return memo[k]

        memo[k] = helper(k-1) + helper(k-2) + helper(k-3)
        return memo[k]

    return helper(n)

def tribonacci_bottom_up(n):
    # For small n, handle directly
    if n == 0:
        return 0
    elif n == 1 or n == 2:
        return 1

    dp = [0] * (n+1)
    dp[0] = 0
    dp[1] = 1
    dp[2] = 1

    for i in range(3, n+1):
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3]

    return dp[n]

```

---

## Testcase

```
Input:  n = 4

```

### Test Result

- **Top-Down**: `tribonacci_top_down(4)` → 4
- **Bottom-Up**: `tribonacci_bottom_up(4)` → 4

---

## Testcase

```
Input:  n = 25

```

### Test Result

- **Top-Down**: `tribonacci_top_down(25)` → 1389537
- **Bottom-Up**: `tribonacci_bottom_up(25)` → 1389537

---

**Note**: Both methods return the same value; the difference lies in how they compute it (recursively with memoization vs. iteratively with tabulation).

## Notes

---

 

## Related Videos

---

[https://www.notion.so](https://www.notion.so)