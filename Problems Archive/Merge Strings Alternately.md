# Merge Strings Alternately

Problem: 1768
Official Difficulty: easy
Feels Like : easy
Topic: string, two pointers
Link: https://leetcode.com/problems/merge-strings-alternately/
Completed On : January 2, 2024
My Understanding: Fully Understand
Last Review: January 2, 2024
Days Since Review: 39

## Problem

---

You are given two strings `word1` and `word2`. Merge the strings by adding letters in alternating order, starting with `word1`. If a string is longer than the other, append the additional letters onto the end of the merged string.

Return *the merged string.*

**Example 1:**

```
Input: word1 = "abc", word2 = "pqr"
Output: "apbqcr"
Explanation: The merged string will be merged as so:
word1:  a   b   c
word2:    p   q   r
merged: a p b q c r

```

**Example 2:**

```
Input: word1 = "ab", word2 = "pqrs"
Output: "apbqrs"
Explanation: Notice that as word2 is longer, "rs" is appended to the end.
word1:  a   b
word2:    p   q   r   s
merged: a p b q   r   s

```

**Example 3:**

```
Input: word1 = "abcd", word2 = "pq"
Output: "apbqcd"
Explanation: Notice that as word1 is longer, "cd" is appended to the end.
word1:  a   b   c   d
word2:    p   q
merged: a p b q c   d

```

**Constraints:**

- `1 <= word1.length, word2.length <= 100`
- `word1` and `word2` consist of lowercase English letters.

## My Solutions

---

```python
class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:

        output = ''

        min_word = min(len(word1),len(word2))

        for i in range(min_word):

            output += word1[i]
            output += word2[i]

        if len(word1) != min_word :

            output += word1[min_word:]

        if len(word2) != min_word : 

            output += word2[min_word:]

        return output
```

### Solutions From Leetcode

```python
two pointers: 

class Solution(object):
    def mergeAlternately(self, word1, word2):
        m = len(word1)
        n = len(word2)
        i = 0
        j = 0
        result = []

        while i < m or j < n:
            if i < m:
                result += word1[i]
                i += 1
            if j < n:
                result += word2[j]
                j += 1

        return "".join(result)
```

```python
one pointer:

class Solution(object):
    def mergeAlternately(self, word1, word2):
        result = []
        n = max(len(word1), len(word2))
        for i in range(n):
            if i < len(word1):
                result += word1[i]
            if i < len(word2):
                result += word2[i]

        return "".join(result)
```

## Optimal Solutions

---

The "Merge Strings Alternately" problem involves combining two strings by alternatingly taking characters from each. Specifically, you construct a new string by taking the first character from the first string, then the first character from the second string, then the second character from the first string, and so on. If one string is longer than the other, you append the remaining characters of the longer string to the end of the merged string.

### Solution Approach

The solution involves iterating over the characters of the two strings, merging them one by one. If the lengths of the strings are not equal, the remaining characters of the longer string are appended at the end.

### Python Implementation

```python
class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        merged = []
        i, j = 0, 0

        # Merge characters alternately
        while i < len(word1) and j < len(word2):
            merged.append(word1[i])
            merged.append(word2[j])
            i += 1
            j += 1

        # Append remaining characters (if any)
        merged.append(word1[i:])
        merged.append(word2[j:])

        return ''.join(merged)

```

### Explanation

- Two pointers, `i` and `j`, are used to iterate over `word1` and `word2`, respectively.
- Characters are appended alternately from `word1` and `word2` to the list `merged`.
- If one string is exhausted before the other, the remaining characters of the longer string are appended to `merged`.
- The list of characters is then joined into a string before being returned.

### Complexity Analysis

- **Time Complexity**: O(n + m), where n is the length of `word1` and m is the length of `word2`. Each character of both strings is visited once.
- **Space Complexity**: O(n + m), for storing the merged characters. The space used by the output string is generally not counted towards the space complexity in most coding interview contexts.

This solution efficiently merges the strings in an alternating fashion, handling strings of different lengths gracefully.

## Notes

---

For whatever reason I knew I should have used a while loop but just couldn’t think of a way because I wanted to have the condition as while word1 or word2 but because of how strings work I couldn’t really make one of them falsy.

## Related Videos

---

[https://www.youtube.com/watch?v=LECWOvTo-Sc](https://www.youtube.com/watch?v=LECWOvTo-Sc)