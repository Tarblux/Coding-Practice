# 2 Keys Keyboard

Problem: 650
Official Difficulty: medium
Feels Like : hard
My Understanding: Needs Review
Topic: Math, dynamic programming
Link: https://leetcode.com/problems/2-keys-keyboard/description/
Completed On : August 19, 2024
Last Review: August 19, 2024
Days Since Review: 7

## Problem

---

There is only one character `'A'` on the screen of a notepad. You can perform one of two operations on this notepad for each step:

- Copy All: You can copy all the characters present on the screen (a partial copy is not allowed).
- Paste: You can paste the characters which are copied last time.

Given an integer `n`, return *the minimum number of operations to get the character* `'A'` *exactly* `n` *times on the screen*.

**Example 1:**

```
Input: n = 3
Output: 3
Explanation: Initially, we have one character 'A'.
In step 1, we use Copy All operation.
In step 2, we use Paste operation to get 'AA'.
In step 3, we use Paste operation to get 'AAA'.
```

**Example 2:**

```
Input: n = 1
Output: 0
```

**Constraints:**

- `1 <= n <= 1000`

## My Solutions

---

```python
class Solution:
    def minSteps(self, n: int) -> int:

        output = 0
        lst_factor = 0

        if n == 1:
            return 0

        for i in range(2,n+1):
            if n % i == 0:
                ls_factor = i
                break

        if n == ls_factor:
            return n

        for i in range(ls_factor,n+1):
            while n % i == 0:
                n //= i
                output += i

        return output

```

```python

```

## Optimal Solutions

---

### Approach

The problem can be broken down into understanding that to achieve `n` 'A's on the notepad with the minimum number of operations, you need to consider the factors of `n`. Each factor `f` of `n` represents a point at which you can perform a "Copy All" operation, followed by multiple "Paste" operations.

### Key Insight

If `n` can be broken down into smaller factors, then the number of operations required is the sum of those factors:

- For example, for `n = 6`, the optimal sequence is:
    - `1 -> 2 -> 4 -> 6`, corresponding to factors `2, 3`.
    - This gives us a sequence of "Copy All" followed by a series of "Paste" operations.

### Dynamic Programming Approach

We can solve this problem using dynamic programming:

1. **DP State**: Let `dp[i]` represent the minimum number of operations needed to get exactly `i` 'A's on the notepad.
2. **DP Transition**:
    - To fill `dp[i]`, we consider all possible factors `j` of `i` (`j < i`), such that `i = j * k` for some `k`.
    - The number of operations to reach `i` would then be `dp[j] + k`, where `k = i // j`.
3. **Initialization**:
    - Start with `dp[1] = 0` because we already have one 'A' on the notepad.

### Python Code

Here's the Python code implementing the dynamic programming approach:

```python
class Solution:
    def minSteps(self, n: int) -> int:
        # Base case: If n is 1, no operations are needed.
        if n == 1:
            return 0

        dp = [0] * (n + 1)

        for i in range 2, n + 1:
            dp[i] = i  # Maximum i operations needed (Copy All + i-1 pastes)

            for j in range 1, i // 2 + 1:
                if i % j == 0:  # j is a factor of i
                    dp[i] = min(dp[i], dp[j] + (i // j))

        return dp[n]

# Example usage
sol = Solution()
print(sol.minSteps(3))  # Output: 3
print(sol.minSteps(6))  # Output: 5

```

### Explanation

1. **Initialization**:
    - We initialize `dp[i]` with the maximum possible value, `i`, which corresponds to performing `i-1` paste operations after one "Copy All".
2. **DP Transition**:
    - For each `i`, we check all factors `j` of `i`. If `j` is a factor, it means we can generate `i` 'A's by first getting `j` 'A's and then performing `i/j` paste operations.
3. **Final Answer**:
    - The value `dp[n]` gives the minimum number of operations required to obtain `n` 'A's on the notepad.

### Complexity Analysis

- **Time Complexity**: `O(n^2)`
    - For each `i`, we check all possible factors, leading to a nested loop with `O(n^2)` complexity.
- **Space Complexity**: `O(n)`
    - The space complexity is `O(n)` for storing the `dp` array.

This dynamic programming approach efficiently computes the minimum number of operations required to achieve `n` 'A's on the notepad.

## Notes

---

 

## Related Videos

---

[https://www.youtube.com/watch?v=jNfZH3mdjOA&t=29s](https://www.youtube.com/watch?v=jNfZH3mdjOA&t=29s)