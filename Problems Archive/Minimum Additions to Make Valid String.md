# Minimum Additions to Make Valid String

Problem: 2645
Official Difficulty: medium
Feels Like : medium
My Understanding: Mostly Understand
Topic: Stack, dynamic programming, greedy, string
Link: https://leetcode.com/problems/minimum-additions-to-make-valid-string/description/
Completed On : February 1, 2025
Last Review: February 1, 2025
Days Since Review: 29
Neetcode: No

## Problem

---

Given a string `word` to which you can insert letters "a", "b" or "c" anywhere and any number of times, return *the minimum number of letters that must be inserted so that `word` becomes **valid**.*

A string is called **valid** if it can be formed by concatenating the string "abc" several times.

**Example 1:**

```
Input: word = "b"
Output: 2
Explanation: Insert the letter "a" right before "b", and the letter "c" right next to "b" to obtain the valid string "abc".
```

**Example 2:**

```
Input: word = "aaa"
Output: 6
Explanation: Insert letters "b" and "c" next to each "a" to obtain the valid string "abcabcabc".
```

**Example 3:**

```
Input: word = "abc"
Output: 0
Explanation: word is already valid. No modifications are needed.
```

**Constraints:**

- `1 <= word.length <= 50`
- `word` consists of letters "a", "b" and "c" only.

## My Solutions

---

```python
class Solution:
    def addMinimum(self, word: str) -> int:
        
        it = 0
        result = 0
        while it < len(word) :
            if word[it:it+3] == "abc":
                it += 3  
            elif word[it:it+2] in ["ab","ac","bc"]:
                result += 1
                it += 2
            else:
                result += 2
                it += 1
        return result
```

```python

```

## Optimal Solutions

---

## Notes

---

 

## Related Videos

---

[https://www.notion.so](https://www.notion.so)