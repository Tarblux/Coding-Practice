# Repeated Sub-string Pattern

Problem: 459
Official Difficulty: easy
Feels Like : medium
Topic: string, string matching
Link: https://leetcode.com/problems/repeated-substring-pattern/description/?envType=study-plan-v2&envId=programming-skills
Completed On : January 8, 2024
My Understanding: Needs Review
Last Review: January 8, 2024
Days Since Review: 33

## Problem

---

Given a string `s`, check if it can be constructed by taking a substring of it and appending multiple copies of the substring together.

**Example 1:**

```
Input: s = "abab"
Output: true
Explanation: It is the substring "ab" twice.

```

**Example 2:**

```
Input: s = "aba"
Output: false

```

**Example 3:**

```
Input: s = "abcabcabcabc"
Output: true
Explanation: It is the substring "abc" four times or the substring "abcabc" twice.

```

**Constraints:**

- `1 <= s.length <= 104`
- `s` consists of lowercase English letters.

## My Solutions

---

This Wrong

```python
class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:

        if len(s) < 2 : 

            return False 

        substring = ''

        for i in range(0,len(s)) : 

            if s[i] not in substring : 

                substring += s[i]

        s_split = s.split(substring)

        print(s_split)

        for string in s_split : 

            if string != '' : 

                return False 

        return True
```

```python

```

## Optimal Solutions

---

### Optimized Approach: Checking Prefix and Suffix

A string `s` has a repeated substring pattern if and only if it can be constructed by repeating a substring. This means if you concatenate the string with itself (`s + s`) and remove the first and the last character, the original string `s` should appear within this new string. This is because the repeated pattern will align at least once in the middle after removing the first and last characters.

### Python Implementation

```python
class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        if len(s) < 2:
            return False

        double_s = s + s
        return s in double_s[1:-1]

```

### Explanation

- Concatenate `s` with itself. This will create a string where if `s` is made of repeating substrings, one of these repetitions will appear fully in the middle.
- Check if `s` is a substring of `double_s` with the first and last characters removed. If it is, then `s` is composed of a repeating pattern.

### Complexity Analysis

- **Time Complexity**: O(n), where `n` is the length of the string `s`. The concatenation operation and substring check are linear in the size of the string.
- **Space Complexity**: O(n), due to the creation of `double_s`, which is twice the length of `s`.

This optimized approach efficiently checks for a repeating pattern with a clever use of string concatenation and avoids unnecessary generation and checking of all substrings.

## Notes

---

 Feels like the only way to know this is by knowing the pattern above

## Related Videos

---

[https://www.youtube.com/watch?v=2qEmA76Unm4](https://www.youtube.com/watch?v=2qEmA76Unm4)