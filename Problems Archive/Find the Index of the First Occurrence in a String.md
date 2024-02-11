# Find the Index of the First Occurrence in a String

Problem: 28
Official Difficulty: easy
Feels Like : medium
Topic: string, string matching, two pointers
Link: https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/
Completed On : November 21, 2023
My Understanding: Mostly Understand
Last Review: November 21, 2023
Days Since Review: 81

## Problem

---

Given two strings `needle` and `haystack`, return the index of the first occurrence of `needle` in `haystack`, or `-1` if `needle` is not part of `haystack`.

**Example 1:**

```
Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.

```

**Example 2:**

```
Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.

```

**Constraints:**

- `1 <= haystack.length, needle.length <= 104`
- `haystack` and `needle` consist of only lowercase English characters.

## My Solutions

---

```python
class Solution(object):
    def strStr(self, haystack, needle):
        

        firstletter_needle = needle[0]
        
        p_indexes = []
        
        len_needle = len(needle)
        
        substring = ''

        
        if len(haystack) < len(needle):
            
            return -1

        
        for i in range(len(haystack)):
            
            if firstletter_needle == haystack[i]:
                
                p_indexes.append(i)

        
        for index in p_indexes:
    
            if index + len_needle <= len(haystack):
        
                substring = haystack[index:index + len_needle]

        
            if substring == needle:
                
                return index  

        
        return -1
```

### Sanya

```python
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        
        if len(needle) > len(haystack):
            return -1
        
        starts = []
        
        # identify starting points
        for i in range(0, len(haystack) - len(needle) + 1):
            if haystack[i] == needle[0]:
                starts.append(i)
                
        # check all starts
        r = -1
        for start in starts:
            r = start
            for i in range(0, len(needle)): 
                if haystack[start + i] != needle[i]:
                    r = -1
                    break
            if r != -1:
                break
                
        return r
```

## Optimal Solutions

---

For finding the first occurrence of `needle` in `haystack`, the most optimal solution in terms of time complexity typically involves using a string searching algorithm. One of the most efficient algorithms for this purpose is the Knuth-Morris-Pratt (KMP) algorithm, which has a time complexity of O(n + m), where n is the length of `haystack` and m is the length of `needle`. However, KMP is relatively complex to implement.

For many practical purposes, especially when the strings are not extremely long, a simpler approach can be both sufficient and easier to understand. This approach involves checking sub strings of `haystack` that have the same length as `needle` and comparing them to `needle`. This has a time complexity of O(n*m) but is often fast enough for moderate-sized strings.

Here's a straightforward implementation:

```python
class Solution:
    def strStr(self, haystack, needle):
        # Edge cases
        if not needle:
            return 0
        if not haystack or len(needle) > len(haystack):
            return -1

        # Length of needle
        len_needle = len(needle)

        # Iterate over haystack
        for i in range(len(haystack) - len_needle + 1):
            # Check if the substring of haystack starting from i matches needle
            if haystack[i:i+len_needle] == needle:
                return i

        return -1

```

### Explanation:

- First, handle edge cases where `needle` is empty (return 0) or `haystack` is shorter than `needle` (return -1).
- Iterate over `haystack`, only going as far as the last character where `needle` could fully fit.
- For each position `i` in `haystack`, compare the substring of length `len_needle` starting at `i` with `needle`.
- If a match is found, return the index `i`.
- If no match is found by the end of the loop, return -1.

This method is straightforward and effective for many cases. If you're dealing with very large strings and performance is a concern, then you might consider more advanced algorithms like KMP, Boyer-Moore, or Rabin-Karp.

## Notes

---

 Realistically you just need to find the length of the smaller string (needle) and then iterate by those steps from the indexes i picked out 

## Related Videos

---

[https://www.youtube.com/watch?v=Gjkhm1gYIMw](https://www.youtube.com/watch?v=Gjkhm1gYIMw)

[https://www.youtube.com/watch?v=JoF0Z7nVSrA](https://www.youtube.com/watch?v=JoF0Z7nVSrA)