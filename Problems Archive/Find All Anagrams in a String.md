Problem: 438
Official Difficulty: medium
Link: https://leetcode.com/problems/find-all-anagrams-in-a-string/description/
Completed On : 2024-12-13
Feels Like : medium
Topic: sliding window, hash table
My Understanding: Mostly Understand, Needs Review
Last Review: 2024-12-13
Days Since Review: 2
Name: Find All Anagrams in a String

# Find All Anagrams in a String
### Problem
___
Given two strings `s` and `p`, return an array of all the start indices of `p`'s
anagrams in `s`.You may return the answer in**any order**

**Example 1:**
```plain text
Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
```
**Example 2:**
```plain text
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
### My Solutions
___
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

Time Complexity :
```python

```

Time Complexity : 
### Optimal Solutions
___

### Notes
___
 
### Related Videos 
___
[]()