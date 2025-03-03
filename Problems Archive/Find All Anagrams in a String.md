# Find All Anagrams in a String

Problem: 438
Official Difficulty: medium
Feels Like : medium
My Understanding: Mostly Understand, Needs Review
Topic: hash table, sliding window
Link: https://leetcode.com/problems/find-all-anagrams-in-a-string/description/
Completed On : December 13, 2024
Last Review: December 13, 2024
Days Since Review: 79
Neetcode: No

## Problem

---

Given two strings `s` and `p`, return an array of all the start indices of `p`'s

anagrams in `s`.You may return the answer in**any order**

**Example 1:**

```
Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
```

**Example 2:**

```
Input: s = "abab", p = "ab"
Output: [0,1,2]
Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
```

**Constraints:**

- `1 <= s.length, p.length <= 3 * 104`
- `s` and `p` consist of lowercase English letters.

## My Solutions

---

```python
class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:

        start = 0
        p_count = Counter(p)
        window = Counter()
        anagrams = []
        

        for end in range(len(s)):

            window[s[end]] += 1

            if end >= len(p):

                window[s[start]] -= 1
                start += 1

                if window[s[start]] == 0:
                    window.pop(s[start])

            if window == p_count:
                anagrams.append(start)

        return anagrams

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