# Word Break

Problem: 139
Official Difficulty: medium
Feels Like : medium
My Understanding: Needs Review
Topic: array, dynamic programming, hash table
Link: https://leetcode.com/problems/word-break/description/
Completed On : February 13, 2025
Last Review: February 13, 2025
Days Since Review: 17
Neetcode: Yes

## Problem

---

Given a string `s` and a dictionary of strings `wordDict`, return `true` if `s` can be segmented into a space-separated sequence of one or more dictionary words.

**Note** that the same word in the dictionary may be reused multiple times in the segmentation.

**Example 1:**

```
Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
```

**Example 2:**

```
Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.
```

**Example 3:**

```
Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false
```

**Constraints:**

- `1 <= s.length <= 300`
- `1 <= wordDict.length <= 1000`
- `1 <= wordDict[i].length <= 20`
- `s` and `wordDict[i]` consist of only lowercase English letters.
- All the strings of `wordDict` are **unique**.

## My Solutions

---

```python
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:

        @cache
        def topdown(i):

            if i < 0:
                return True

            for word in wordDict:
                substring = s[i-len(word)+1:i+1]

                if substring == word and topdown(i-len(word)):
                    return True

            return False

        return topdown(len(s)-1)
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