# Valid Anagram

Problem: 242
Official Difficulty: easy
Topic: hash table, sorting, string
Link: https://leetcode.com/problems/valid-anagram/
Completed On : December 12, 2023
My Understanding: Fully Understand
Last Review: December 12, 2023
Days Since Review: 60

## Problem

---

Given two strings `s` and `t`, return `true` *if* `t` *is an anagram of* `s`*, and* `false` *otherwise*.

An **Anagram** is a word or phrase formed by rearranging
 the letters of a different word or phrase, typically using all the 
original letters exactly once.

**Example 1:**

```
Input: s = "anagram", t = "nagaram"
Output: true
```

**Example 2:**

```
Input: s = "rat", t = "car"
Output: false
```

**Constraints:**

- `1 <= s.length, t.length <= 5 * 104`
- `s` and `t` consist of lowercase English letters.

## My Solutions

---

Aleksandr:

```python
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:

        if (len(s) != len(t)):
            return False
        
        dict = {}
        for char in s:
            if char in dict:
                dict[char] += 1
            else:
                dict[char] = 1
                
        for char in t:
            
            if (len(dict) == 0):
                return False
            
            if char in dict:
                dict[char] -= 1
                if dict[char] == 0:
                    dict.pop(char)
                    
        if len(dict) == 0:
            return True
        return False
        
#         if (len(s) != len(t)):
#             return False
                
#         s = sorted(s)
#         t = sorted(t)
        
#         for i in range(0, len(s)):
#             if s[i] != t[i]:
#                 return False
#         return True
```

```python

```

Zwea:

```python
if len(s) != len(t):
   return False
        
return sorted(list(s)) == sorted(list(t))
```

## Optimal Solutions

---

```python

```

## Notes

---

Lorem Ipsum 

## Related Videos

---

[https://www.youtube.com/watch?v=9UtInBqnCgA&pp=ygUNdmFsaWQgYW5hZ3JhbQ%3D%3D](https://www.youtube.com/watch?v=9UtInBqnCgA&pp=ygUNdmFsaWQgYW5hZ3JhbQ%3D%3D)