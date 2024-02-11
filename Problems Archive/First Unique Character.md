# First Unique Character

Problem: 387
Official Difficulty: easy
Topic: Counting, Queue, hash table, string
Link: https://leetcode.com/problems/first-unique-character-in-a-string/
Completed On : November 19, 2023
My Understanding: Mostly Understand
Last Review: November 19, 2023
Days Since Review: 83

## Problem

---

Given a string `s`, *find the first non-repeating character in it and return its index*. If it does not exist, return `-1`.

**Example 1:**

```
Input: s = "leetcode"
Output: 0

```

**Example 2:**

```
Input: s = "loveleetcode"
Output: 2

```

**Example 3:**

```
Input: s = "aabb"
Output: -1

```

## My Solutions

---

### Tariq

```python
class Solution(object):
    def firstUniqChar(self, s):
        
        
        
        dict = {}
        
        for i in range (0,len(s)) : 
            
            if s[i] not in dict : 
                
                dict[s[i]] = 1 
                
            else : 
                
                dict[s[i]] += 1
                
            
            
        for i in range (0,len(s)) : 
            
            if dict[s[i]] == 1 : 
                
                return i
            
        return -1
```

Aleksandr:

```python
class Solution:
    def firstUniqChar(self, s: str) -> int:
        
        dict = {}
        for index, char in enumerate(s):
            if char in dict:
                dict[char].append(index)
            else:
                dict[char] = [index]
                
        for char in dict:
            if len(dict[char]) == 1:
                return dict[char][0]
            
        return -1

        if len(s) == 1:
            return 0

        for i in range(0, len(s)):
            for j in range(0, len(s)):
                if i == j:
                    if j == len(s) - 1:
                        return i    
                    continue
            
                if s[i] == s[j]:
                    break
            
        return -1
```

## Optimal Solutions

---

```python

```

## Notes

---

## Related Videos

---

[https://www.youtube.com/watch?v=wlRezT0b5MI&pp=ygUzZmlyc3QgdW5pcXVlIGNoYXJhY3RlciBpbiBhIHN0cmluZyBsZWV0Y29kZSBweXRob24g](https://www.youtube.com/watch?v=wlRezT0b5MI&pp=ygUzZmlyc3QgdW5pcXVlIGNoYXJhY3RlciBpbiBhIHN0cmluZyBsZWV0Y29kZSBweXRob24g)