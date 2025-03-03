# Minimum Window Substring

Problem: 76
Official Difficulty: hard
Feels Like : hard
My Understanding: Mostly Understand
<<<<<<< Updated upstream
Last Review: 2024-12-14
Days Since Review: 8
Name: Minimum Window Substring
=======
Topic: hash table, sliding window, string
Link: https://leetcode.com/problems/minimum-window-substring/description/
Completed On : December 14, 2024
Last Review: December 14, 2024
Days Since Review: 78
Neetcode: Yes

## Problem

---

Given two strings `s` and `t` of lengths `m` and `n` respectively, return *the **minimum window substring** of* `s`*such that every character in* `t`

*(**including duplicates**) is included in the window*
>>>>>>> Stashed changes

. If there is no such substring, return *the empty string*

The testcases will be generated such that the answer is **unique**.

**Example 1:**

```
Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
```

**Example 2:**

```
Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
```

**Example 3:**

```
Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
```

**Constraints:**

- `m == s.length`
- `n == t.length`
- `1 <= m, n <= 105`
- `s` and `t` consist of uppercase and lowercase English letters.

**Follow up:** Could you find an algorithm that runs in `O(m + n)` time?

## My Solutions

---

```python
class Solution:
    def minWindow(self, s: str, t: str) -> str:

        if not t:
            return ''

        window = Counter()
        need = Counter(t)
        t = Counter(t)
        
        start = 0
        min_window = float('inf')
        result = ''

        for end in range(len(s)):

            window[s[end]] += 1

            if s[end] in need:

                need[s[end]] -= 1

                if need[s[end]] == 0:
                    need.pop(s[end])

            while not need:

                if end - start + 1 < min_window:
                    min_window = end - start + 1
                    result = s[start:end+1]

                window[s[start]] -= 1

                if s[start] in t and window[s[start]] < t[s[start]]:
                    need[s[start]] += 1

                start += 1

        if min_window == float('inf'):
            return ''

        return result     
```

```python

```

## Optimal Solutions

---

This uses a sliding window approach with two pointers and a frequency map to track how many characters from `t` are needed:

1. Build a frequency map `need` for the characters in `t`.
2. Use two pointers `left` and `right` to represent the current window in `s`.
3. Expand `right` and decrement counts in `need` when you encounter a character. If a needed character's count drops to zero or below, it means we've covered that character's requirement.
4. Once all characters of `t` are covered by the window (`formed == required`), attempt to shrink the window from the left to find a smaller valid window.
5. Keep track of the minimum valid window as you go along.

This runs in O(n) time since each character is processed at most twice.

**Code:**

```python
class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if not s or not t:
            return ""

        need = {}
        for ch in t:
            need[ch] = need.get(ch, 0) + 1

        required = len(need)
        formed = 0
        left = right = 0
        window_counts = {}

        min_len = float('inf')
        min_start = 0

        while right < len(s):
            ch = s[right]
            window_counts[ch] = window_counts.get(ch, 0) + 1

            if ch in need and window_counts[ch] == need[ch]:
                formed += 1

            while left <= right and formed == required:
                ch = s[left]
                if right - left + 1 < min_len:
                    min_len = right - left + 1
                    min_start = left

                window_counts[ch] -= 1
                if ch in need and window_counts[ch] < need[ch]:
                    formed -= 1
                left += 1

            right += 1

        return "" if min_len == float('inf') else s[min_start:min_start+min_len]

```

## Notes

---

 

## Related Videos

---

[https://youtu.be/jSto0O4AJbM](https://youtu.be/jSto0O4AJbM)