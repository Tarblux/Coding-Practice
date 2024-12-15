Problem: 3
Official Difficulty: medium
Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
Completed On : 2024-12-13
Feels Like : easy
Topic: sliding window, set, hash table
My Understanding: Fully Understand
Last Review: 2024-12-13
Days Since Review: 2
Name: Longest Substring Without Repeating Characters

# Longest Substring Without Repeating Characters
### Problem
___
Given a string `s`, find the length of the **longest substring **without repeating characters.
**Example 1:**
```plain text
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
```
**Example 2:**
```plain text
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
```
**Example 3:**
```plain text
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
```
**Constraints:**
- `0 <= s.length <= 5 * 104`
- `s` consists of English letters, digits, symbols and spaces.
### My Solutions
___
```python
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:

        if not s:
            return 0
        
        max_string = float('-inf')
        cur_string = set()
        start = 0

        for end in range(len(s)):

            while s[end] in cur_string:

                cur_string.remove(s[start])
                start += 1

            cur_string.add(s[end])
            max_string = max(max_string,end - start + 1)

        return max_string

```

Time Complexity :
```python

```

Time Complexity : 
### Optimal Solutions
___
We use a sliding window with a frequency map (or index map) to keep track of characters currently in the substring. As we move the right pointer over the string:
- If we encounter a character not in the current window, we add it and update the maximum length if needed.
- If we encounter a character that's already in the window, we shrink the window from the left until that character is no longer duplicated.
This ensures that each window we consider has unique characters. Since each character is visited at most twice (once when extending the window and once when shrinking it), the algorithm runs in O(n) time.
**Steps:**
1. Initialize `left` and `max_len` to 0, and use a dictionary `last_index` to store the last seen index of each character.
2. Iterate `right` through each character in `s`:
	- If `s[right]` is in `last_index` and `last_index[s[right]] >= left`, it means `s[right]` is a duplicate in the current window. Update `left` to be `last_index[s[right]] + 1` to remove the previous occurrence from the window.
	- Update `last_index[s[right]]` to the current `right` index.
	- Update `max_len` to be the maximum of its current value and `right - left + 1`.
**Code:**
```python
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        last_index = {}
        left = 0
        max_len = 0

        for right, ch in enumerate(s):
            if ch in last_index and last_index[ch] >= left:
                left = last_index[ch] + 1
            last_index[ch] = right
            max_len = max(max_len, right - left + 1)

        return max_len
```
### Notes
___
 
### Related Videos 
___
[gqXU1UyA8pk](https://youtu.be/gqXU1UyA8pk)