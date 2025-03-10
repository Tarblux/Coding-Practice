# Distinct Subsequences

Problem: 115
Official Difficulty: hard
Feels Like : Brain Damage
My Understanding: I Have No Idea
Topic: dynamic programming, string
Link: https://leetcode.com/problems/distinct-subsequences/description/
Completed On : March 8, 2025
Last Review: March 8, 2025
Days Since Review: 1
Neetcode: Yes

## Problem

---

Given two strings s and t, return *the number of distinct* ***subsequences** of* s *which equals* t.

The test cases are generated so that the answer fits on a 32-bit signed integer.

**Example 1:**

```
Input: s = "rabbbit", t = "rabbit"
Output: 3
Explanation:
As shown below, there are 3 ways you can generate "rabbit" from s.
rabbbitrabbbitrabbbit
```

**Example 2:**

```
Input: s = "babgbag", t = "bag"
Output: 5
Explanation:
As shown below, there are 5 ways you can generate "bag" from s.
babgbagbabgbagbabgbagbabgbagbabgbag
```

**Constraints:**

- `1 <= s.length, t.length <= 1000`
- `s` and `t` consist of English letters.

## My Solutions

---

```python
class Solution:
    def numDistinct(self, s: str, t: str) -> int:

        if len(s) < len(t):
            return 0

        @cache
        def dfs(i,j):

            if j == len(t):
                return 1
            
            if j != len(t) and i == len(s):
                return 0

            ways = dfs(i+1,j)

            if s[i] == t[j]:
                ways += (dfs(i+1,j+1))

            return ways

        return dfs(0,0)
        
```

Let's break down this solution step by step. The goal is to count how many distinct subsequences of string **s** equal string **t**. In other words, we want to know in how many different ways we can delete characters from **s** (without changing the order of the remaining characters) so that the resulting string is exactly **t**.

### High-Level Idea

We use recursion with two indices:

- **i** to traverse **s**
- **j** to traverse **t**

At each step, we have two choices: either skip the current character in **s** or use it to match the current character in **t** (if they are equal). The function is decorated with `@cache` (a memoization tool) so that we don't recompute the result for the same `(i, j)` pair, ensuring efficiency.

### Detailed Explanation

1. **Initial Check:**
    
    ```python
    if len(s) < len(t):
        return 0
    
    ```
    
    If **s** is shorter than **t**, it's impossible for **t** to be a subsequence of **s**, so we return 0 immediately.
    
2. **Defining the DFS Function:**
    
    ```python
    @cache
    def dfs(i, j):
    
    ```
    
    - **i** represents the current index in **s**.
    - **j** represents the current index in **t**.
    The `@cache` decorator stores the results of each `(i, j)` state so that if we encounter the same state again, we can simply retrieve the stored result instead of recalculating it.
3. **Base Cases:**
    - **All of t is Matched:**
        
        ```python
        if j == len(t):
            return 1
        
        ```
        
        When `j` equals the length of **t**, it means we've successfully matched every character in **t** with some characters from **s**. Since we've found a valid subsequence, we return 1.
        
    - **s is Exhausted Without Matching t:**
        
        ```python
        if j != len(t) and i == len(s):
            return 0
        
        ```
        
        If we've reached the end of **s** (i.e., `i == len(s)`) but **t** has not been fully matched (i.e., `j` is still less than `len(t)`), then there's no way to form **t** from the remaining characters. So, we return 0.
        
4. **Recursive Cases:**
    
    At each call, we consider the character at `s[i]` and decide what to do:
    
    - **Skip the Current Character:**
        
        ```python
        ways = dfs(i+1, j)
        
        ```
        
        Here, we ignore `s[i]` and see how many ways we can match **t** starting from the next character in **s** (keeping the same position in **t**).
        
    - **Match the Current Character:**
        
        ```python
        if s[i] == t[j]:
            ways += dfs(i+1, j+1)
        
        ```
        
        If the current character in **s** matches the current character in **t** (`s[i] == t[j]`), then we can use `s[i]` as part of a valid subsequence. In that case, we move to the next character in both **s** and **t**.
        
        The total number of ways for state `(i, j)` is the sum of the ways when skipping and the ways when matching (if possible).
        
5. **Return the Total Count:**
    
    The final call `dfs(0, 0)` starts the recursion from the beginning of both strings. The computed value is the total number of distinct subsequences of **s** that equal **t**.
    

### Summary

- **Recursion with Two Indices:**
    
    The function `dfs(i, j)` explores all options by either skipping the current character in **s** or, if it matches, using it to match **t**.
    
- **Memoization:**
    
    The `@cache` decorator prevents redundant computations by caching results for each `(i, j)` state.
    
- **Base Cases:**
    
    The recursion stops when either **t** has been fully matched (successful subsequence) or **s** is exhausted without completing the match.
    
- **Combining Results:**
    
    For each state, the answer is the sum of the ways when skipping the current character and the ways when matching (if the characters are equal).
    

This is a top-down dynamic programming solution that efficiently counts the number of ways to form **t** as a subsequence of **s**.

```python

```

## Optimal Solutions

---

## Notes

---

 

## Related Videos

---

[https://www.notion.so](https://www.notion.so)