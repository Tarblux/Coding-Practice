# Palindromic Substrings

Problem: 647
Official Difficulty: medium
Feels Like : medium
My Understanding: Fully Understand
Topic: dynamic programming, string, two pointers
Link: https://leetcode.com/problems/palindromic-substrings/description/
Completed On : January 25, 2025
Last Review: January 25, 2025
Days Since Review: 36
Neetcode: Yes

## Problem

---

Given a string `s`, return *the number of **palindromic substrings** in it*.

A string is a **palindrome** when it reads the same backward as forward.

A **substring** is a contiguous sequence of characters within the string.

**Example 1:**

```
Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
```

**Example 2:**

```
Input: s = "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
```

**Constraints:**

- `1 <= s.length <= 1000`
- `s` consists of lowercase English letters.

## My Solutions

---

```python
class Solution:
    def countSubstrings(self, s: str) -> int:

        output = 0
        n = len(s)

        dp = [[False for _ in range(n)] for _ in range(n)]

        for start in range(n-1,-1,-1):
            for end in range(start,n):

                size  = (end - start) + 1
                if s[start] == s[end] and (size <= 3 or dp[start+1][end-1] == True):
                    
                    dp[start][end] = True
                    output += 1

        return output
```

```python

```

## Optimal Solutions

---

**Intuition**

- We want to count all substrings of a given string that are palindromes.
- A substring  is a palindrome if it reads the same forwards and backwards.
    
    s[i…j]s[i \dots j]
    
- A dynamic programming approach typically involves checking if  and if the inner substring  is also a palindrome.
    
    s[i]==s[j]s[i] == s[j]
    
    s[i+1…j−1]s[i+1 \dots j-1]
    

---

**Approach**

1. **Top-Down (Memoized)**
    - Create a helper function `isPalindrome(i, j)` that returns `True` if  is palindrome.
        
        s[i…j]s[i \dots j]
        
    - Memoize results in a dictionary to avoid re-checking the same substring.
    - Iterate over all possible `(i, j)` pairs and count how many times `isPalindrome(i, j)` is `True`.
2. **Bottom-Up (Tabulated)**
    - Create a 2D DP array `dp[i][j]` that indicates whether  is palindrome.
        
        s[i…j]s[i \dots j]
        
    - Initialize `dp[i][i] = True` for all `i` (single letters are palindromes).
    - Check substrings of length 2, then length 3, etc.
    - Whenever `dp[i][j]` is set to `True`, increment the palindrome count.

Both methods have a time complexity of O(n2)O(n^2) and a space complexity of O(n2)O(n^2), where `n` is the length of the string.

---

## Code

```python
def palindromicSubstrings_top_down(s):
    n = len(s)
    memo = {}  # (i, j) -> bool indicating if s[i..j] is palindrome

    def isPalindrome(i, j):
        if i >= j:  # single char or empty substring
            return True
        if (i, j) in memo:
            return memo[(i, j)]

        if s[i] == s[j]:
            memo[(i, j)] = isPalindrome(i + 1, j - 1)
        else:
            memo[(i, j)] = False

        return memo[(i, j)]

    count = 0
    for i in range(n):
        for j in range(i, n):
            if isPalindrome(i, j):
                count += 1
    return count

def palindromicSubstrings_bottom_up(s):
    n = len(s)
    if n == 0:
        return 0

    dp = [[False] * n for _ in range(n)]
    count = 0

    # Substrings of length 1
    for i in range(n):
        dp[i][i] = True
        count += 1

    # Substrings of length 2
    for i in range(n - 1):
        if s[i] == s[i+1]:
            dp[i][i+1] = True
            count += 1

    # Substrings of length 3 and more
    for length in range(3, n + 1):
        for i in range(n - length + 1):
            j = i + length - 1
            if s[i] == s[j] and dp[i+1][j-1]:
                dp[i][j] = True
                count += 1

    return count

```

---

## Testcase

```
s = "aaa"

```

**Top-Down**: `palindromicSubstrings_top_down("aaa")` → **6**

**Bottom-Up**: `palindromicSubstrings_bottom_up("aaa")` → **6**

Explanation: The palindromic substrings are:

1. "a" (index 0)
2. "a" (index 1)
3. "a" (index 2)
4. "aa" (indices 0..1)
5. "aa" (indices 1..2)
6. "aaa" (indices 0..2)

---

## Testcase

```
s = "abc"

```

**Top-Down**: `palindromicSubstrings_top_down("abc")` → **3**

**Bottom-Up**: `palindromicSubstrings_bottom_up("abc")` → **3**

Explanation: The palindromic substrings are just the single letters: "a", "b", and "c".

## Notes

---

 

## Related Videos

---

[https://youtu.be/4RACzI5-du8](https://youtu.be/4RACzI5-du8)