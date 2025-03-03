# Decode Ways

Problem: 91
Official Difficulty: medium
Feels Like : hard
My Understanding: Mostly Understand
Topic: dynamic programming, string
Link: https://leetcode.com/problems/decode-ways/description/
Completed On : January 27, 2025
Last Review: January 27, 2025
Days Since Review: 34
Neetcode: Yes

## Problem

---

You have intercepted a secret message encoded as a string of numbers. The message is **decoded** via the following mapping:

`"1" -> 'A'
"2" -> 'B'
...
"25" -> 'Y'
"26" -> 'Z'`

However, while decoding the message, you realize that there are many different ways you can decode the message because some codes are contained in other codes (`"2"` and `"5"` vs `"25"`).

For example, `"11106"` can be decoded into:

- `"AAJF"` with the grouping `(1, 1, 10, 6)`
- `"KJF"` with the grouping `(11, 10, 6)`
- The grouping `(1, 11, 06)` is invalid because `"06"` is not a valid code (only `"6"` is valid).

Note: there may be strings that are impossible to decode.

Given a string s containing only digits, return the **number of ways** to **decode** it. If the entire string cannot be decoded in any valid way, return `0`.

The test cases are generated so that the answer fits in a **32-bit** integer.

**Example 1:**

**Input:** s = "12"

**Output:** 2

**Explanation:**

"12" could be decoded as "AB" (1 2) or "L" (12).

**Example 2:**

**Input:** s = "226"

**Output:** 3

**Explanation:**

"226" could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).

**Example 3:**

**Input:** s = "06"

**Output:** 0

**Explanation:**

"06" cannot be mapped to "F" because of the leading zero ("6" is different from "06"). In this case, the string is not a valid encoding, so return 0.

**Constraints:**

- `1 <= s.length <= 100`
- `s` contains only digits and may contain leading zero(s).

## My Solutions

---

```python
class Solution:

    def validDoubledigit(self,num:str):

        if num[0] == '0':
            return False

        return 10 <= int(num) <= 26

    def numDecodings(self, s: str) -> int:

        if not s or s[0] == '0':
            return 0

        n = len(s)
        dp = [0] * (n+1)
        dp[0] = 1
        dp[1] = 1

        for i in range(2,n+1):
            
            cur_digit = s[i-1]
            if cur_digit != '0':
                dp[i] = dp[i-1]

            double_digit = s[i-2:i]
            if self.validDoubledigit(double_digit):
                dp[i] += dp[i-2]

        return dp[n]
        
```

```python

```

## Optimal Solutions

---

**Intuition**

- We want the total number of ways to decode a numeric string (e.g., `"12" -> "AB" (1,2)` or `"L" (12)`), where `'1' -> 'A' ... '26' -> 'Z'`.
- If a digit is `'0'`, it cannot be decoded alone—it must be paired with a leading `'1'` or `'2'` (i.e., `"10"` or `"20"`).
- We can either decode one digit at a time (if it’s not `'0'`) or two digits at a time (if it’s between `"10"` and `"26"`).

---

**Approach**

1. **Top-Down (Memoized)**
    - Define a recursive function `decode(i)` that calculates the number of ways to decode the substring starting at index `i`.
    - If `s[i] == '0'`, return 0 immediately.
    - Otherwise, try:
        - Taking **one** digit: `decode(i+1)`.
        - Taking **two** digits (if `s[i..i+1]` is between `"10"` and `"26"`): `decode(i+2)`.
    - Use a memo dictionary to store results of `decode(i)`.
2. **Bottom-Up (Tabulated)**
    - Let `dp[i]` represent the number of ways to decode the substring `s[i..]`.
    - Base initialization:
        - `dp[n] = 1` (where `n = len(s)`), representing an empty substring has 1 way to be “decoded” (the “do nothing” way).
        - We fill `dp` from the end (right to left).
    - For `i` from `n-1` down to `0`:
        - If `s[i] == '0'`, then `dp[i] = 0`.
        - Else, `dp[i] += dp[i+1]`.
        - Additionally, if `s[i..i+1]` is between `"10"` and `"26"`, then `dp[i] += dp[i+2]`.
    - The answer is `dp[0]`.

---

## Code

```python
def decodeWays_top_down(s):
    memo = {}
    n = len(s)

    def dfs(i):
        # If we've reached the end, there's 1 valid way (complete decode)
        if i == n:
            return 1
        # If we exceed the length, no valid decode
        if i > n:
            return 0
        # If string at i starts with '0', can't decode
        if s[i] == '0':
            return 0
        if i in memo:
            return memo[i]

        # Decode 1 digit
        ways = dfs(i + 1)

        # Decode 2 digits if it forms a valid number 10..26
        if i + 1 < n:
            two_digit = int(s[i:i+2])
            if 10 <= two_digit <= 26:
                ways += dfs(i + 2)

        memo[i] = ways
        return ways

    return dfs(0)

def decodeWays_bottom_up(s):
    n = len(s)
    # dp[i] = number of ways to decode s[i..]
    dp = [0] * (n + 1)
    dp[n] = 1  # Base case: empty string has 1 way

    for i in range(n - 1, -1, -1):
        if s[i] == '0':
            dp[i] = 0  # Can't decode '0' alone
        else:
            # Always add the ways from i+1
            dp[i] = dp[i + 1]
            # Check if two-digit decode is possible
            if i + 1 < n:
                two_digit = int(s[i:i+2])
                if 10 <= two_digit <= 26:
                    dp[i] += dp[i + 2]

    return dp[0]

```

---

## Testcase

```
s = "12"

```

- **Top-Down**: `decodeWays_top_down("12")` → **2**
- **Bottom-Up**: `decodeWays_bottom_up("12")` → **2**
Explanation: "12" can decode to "AB" (1,2) or "L" (12).

---

## Testcase

```
s = "226"

```

- **Top-Down**: `decodeWays_top_down("226")` → **3**
- **Bottom-Up**: `decodeWays_bottom_up("226")` → **3**
Explanation: "226" can decode to "BBF" (2,2,6), "BZ" (2,26), or "VF" (22,6).

---

## Testcase

```
s = "06"

```

- **Top-Down**: `decodeWays_top_down("06")` → **0**
- **Bottom-Up**: `decodeWays_bottom_up("06")` → **0**
Explanation: Can't start with '0' in a valid way.

---

**Summary**

- We handle invalid cases (leading '0') by returning zero ways.
- We sum ways from decoding one digit plus ways from decoding two digits if valid.
- Time Complexity: .
    
    O(n)O(n)
    
- Space Complexity: .
    
    O(n)O(n)
    

## Notes

---

 

## Related Videos

---

[https://youtu.be/6aEyTjOwlJU](https://youtu.be/6aEyTjOwlJU)