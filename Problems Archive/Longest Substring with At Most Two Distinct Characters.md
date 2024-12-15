Problem: 159
Official Difficulty: medium
Link: https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/editorial/
Completed On : 2024-12-12
Feels Like : medium
Topic: sliding window, two pointers, hash table
My Understanding: Fully Understand
Last Review: 2024-12-12
Days Since Review: 3
Name: Longest Substring with At Most Two Distinct Characters

# Longest Substring with At Most Two Distinct Characters
### Problem
___
Given a string `s`, return *the length of the longest*
*substring*
*that contains at most ****two distinct characters***
.
**Example 1:**
```plain text
Input: s = "eceba"
Output: 3
Explanation: The substring is "ece" which its length is 3.
```
**Example 2:**
```plain text
Input: s = "ccaabbb"
Output: 5
Explanation: The substring is "aabbb" which its length is 5.
```
**Constraints:**
- `1 <= s.length <= 105`
- `s` consists of English letters.
### My Solutions
___
```python
class Solution:
    def lengthOfLongestSubstringTwoDistinct(self, s: str) -> int:

        longest = float('-inf')
        chars = defaultdict(int)
        start = 0

        for end in range(len(s)):

            chars[s[end]] += 1

            while len(chars) > 2:

                chars[s[start]] -= 1

                if chars[s[start]] == 0:
                    chars.pop(s[start])

                start += 1

            longest = max(end - start + 1,longest)

        return longest 
```

Time Complexity :
```python

```

Time Complexity : 
### Optimal Solutions
___
This can be solved using a sliding window approach combined with a frequency map to track the characters within the current window. We maintain a window that always has at most two distinct characters. As we move a right pointer through the string, we add characters to our frequency map. If we ever have more than two distinct characters, we move the left pointer forward until we're back to two or fewer distinct characters, updating the frequency map and removing characters that drop to zero frequency.
**Key Steps:**
1. Initialize two pointers `left` and `right` at the start of the string, and use a dictionary `freq` to track the count of each character in the current window.
2. Expand `right`, adding `s[right]` to `freq`. If at any point the number of distinct characters in `freq` is more than two, shrink from the left by moving `left` forward and decrementing frequencies until only two distinct characters remain.
3. Track the maximum length of the valid window (at most two distinct characters) throughout the process.
This approach runs in O(n) time since each character is added and removed from the window at most once.
**Code:**
```python
class Solution:
    def lengthOfLongestSubstringTwoDistinct(self, s: str) -> int:
        freq = {}
        left = 0
        max_len = 0

        for right, ch in enumerate(s):
            freq[ch] = freq.get(ch, 0) + 1

            while len(freq) > 2:
                left_char = s[left]
                freq[left_char] -= 1
                if freq[left_char] == 0:
                    del freq[left_char]
                left += 1

            max_len = max(max_len, right - left + 1)

        return max_len

```
### Notes
___
 
### Related Videos 
___
[]()