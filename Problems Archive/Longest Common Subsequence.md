# Longest Common Subsequence

Problem: 1143
Official Difficulty: medium
Feels Like : medium
My Understanding: Fully Understand
Topic: dynamic programming
Link: https://leetcode.com/problems/longest-common-subsequence/description/
Completed On : March 6, 2025
Last Review: March 6, 2025
Days Since Review: 3
Neetcode: Yes

## Problem

---

Given two strings `text1` and `text2`, return *the length of their longest **common subsequence**.* If there is no **common subsequence**, return `0`.

A **subsequence** of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

- For example, `"ace"` is a subsequence of `"abcde"`.

A **common subsequence** of two strings is a subsequence that is common to both strings.

**Example 1:**

```
Input: text1 = "abcde", text2 = "ace"
Output: 3
Explanation: The longest common subsequence is "ace" and its length is 3.

```

**Example 2:**

```
Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.

```

**Example 3:**

```
Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.

```

**Constraints:**

- `1 <= text1.length, text2.length <= 1000`
- `text1` and `text2` consist of only lowercase English characters.

## My Solutions

---

```python
class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:

        memo = {}

        def topdown(i,j):

            if i == len(text1) or j == len(text2):
                return 0

            if (i,j) in memo:
                return memo[(i,j)]

            if text1[i] == text2[j]:
                memo[(i,j)] = 1 + topdown(i+1,j+1) 
            else:
                memo[(i,j)] = max(topdown(i+1,j),topdown(i,j+1))

            return memo[(i,j)]

            
        return topdown(0,0)
```

```python

```

## Optimal Solutions

---

**Intuition**

- We want the length of the longest sequence that appears in **both** strings `text1` and `text2` while maintaining **relative order** (not necessarily contiguity).
- A common technique for such sequence comparisons is **dynamic programming** since each position’s best answer depends on previous overlapping sub-results.

---

**Approach**

1. **Top-Down (Memoized)**
    - Define a recursive function `LCS(i, j)` that returns the length of the LCS of `text1[i..]` and `text2[j..]`.
    - If `text1[i] == text2[j]`, then `1 + LCS(i+1, j+1)`.
    - Otherwise, the result is the max of skipping one character from either string:
        
        max⁡(LCS(i+1,j), LCS(i,j+1)).  \max\bigl(LCS(i+1, j),\, LCS(i, j+1)\bigr).
        
    - Use a memo dictionary to store `(i, j) -> LCS length`, so each subproblem is solved once.
2. **Bottom-Up (Tabulated)**
    - Create a 2D array `dp` with dimensions `(len(text1)+1) x (len(text2)+1)`, where `dp[i][j]` will represent the LCS of `text1[:i]` and `text2[:j]`.
    - Fill this table row by row (or column by column).
    - If `text1[i-1] == text2[j-1]`, then `dp[i][j] = dp[i-1][j-1] + 1`.
    - Otherwise, `dp[i][j] = max(dp[i-1][j], dp[i][j-1])`.
    - The answer is in `dp[len(text1)][len(text2)]`.

---

## Solutions

```python
def longestCommonSubsequence_top_down(text1: str, text2: str) -> int:
    from functools import lru_cache
    n1, n2 = len(text1), len(text2)

    @lru_cache(None)
    def LCS(i, j):
        if i == n1 or j == n2:
            return 0
        if text1[i] == text2[j]:
            return 1 + LCS(i + 1, j + 1)
        else:
            return max(LCS(i + 1, j), LCS(i, j + 1))

    return LCS(0, 0)

def longestCommonSubsequence_bottom_up(text1: str, text2: str) -> int:
    n1, n2 = len(text1), len(text2)
    # dp[i][j]: LCS of text1[:i] and text2[:j]
    dp = [[0] * (n2 + 1) for _ in range(n1 + 1)]

    for i in range(1, n1 + 1):
        for j in range(1, n2 + 1):
            if text1[i - 1] == text2[j - 1]:
                dp[i][j] = dp[i - 1][j - 1] + 1
            else:
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])

    return dp[n1][n2]

```

---

## Testcases

1. `text1 = "abcde", text2 = "ace"`
    - **Top-Down**: `longestCommonSubsequence_top_down("abcde", "ace")` → **3**
    - **Bottom-Up**: `longestCommonSubsequence_bottom_up("abcde", "ace")` → **3**
    Explanation: LCS is `"ace"` with length 3.
2. `text1 = "abc", text2 = "abc"`
    - **Top-Down**: → **3**
    - **Bottom-Up**: → **3**
    Explanation: Both strings are the same; LCS is `"abc"` itself.
3. `text1 = "abc", text2 = "def"`
    - **Top-Down**: → **0**
    - **Bottom-Up**: → **0**
    Explanation: No common subsequence, so LCS length is 0.

---

**Key Points**

- **Time Complexity**:  for both top-down (due to memoization of each `(i,j)`) and bottom-up.
    
    O(n1×n2)O(n_1 \times n_2)
    
- **Space Complexity**:  in both approaches (memo or table), though you can optimize the bottom-up approach to  by only storing two rows (or columns) at a time.
    
    O(n1×n2)O(n_1 \times n_2)
    
    O(min⁡(n1,n2))O(\min(n_1, n_2))
    

## Notes

---

 

## Related Videos

---

[https://youtu.be/Ua0GhsJSlWM](https://youtu.be/Ua0GhsJSlWM)