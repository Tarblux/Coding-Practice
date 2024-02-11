# Longest Repeating Character  Replacement

Problem: 424
Official Difficulty: medium
Feels Like : hard
Topic: hash table, sliding window, string
Link: https://leetcode.com/problems/longest-repeating-character-replacement/
Completed On : December 23, 2023
My Understanding: Needs Review
Last Review: December 23, 2023
Days Since Review: 49

## Problem

---

You are given a string `s` and an integer `k`.
 You can choose any character of the string and change it to any other 
uppercase English character. You can perform this operation at most `k` times.

Return *the length of the longest sub-string containing the same letter you can get after performing the above operations*.

**Example 1:**

```
Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.

```

**Example 2:**

```
Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
There may exists other ways to achieve this answer too.
```

**Constraints:**

- `1 <= s.length <= 105`
- `s` consists of only uppercase English letters.
- `0 <= k <= s.length`

## My Solutions

---

```python
class Solution:
    def characterReplacement(self, s: str, k: int) -> int:

        dict = {}

        output = 0

        l = 0 

        for r in range (0,len(s)) : 

            if s[r] not in dict : 

                dict[s[r]] = 1

            else : 

                dict[s[r]] += 1

            while (r - l + 1) - max(dict.values()) > k : 

                dict[s[l]] -= 1
                l += 1

            output = max(r - l + 1 , output )

        return output
```

### Sanya (Faster)

```python
class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
    
        alphabet = {}
        res = 0
        l = 0 
        maxCounter = 0

        for r, char in enumerate(s):
            alphabet[char] = alphabet.get(char, 0) + 1
            if alphabet[char] > maxCounter:
                maxCounter = alphabet[char]

            while (r - l + 1) - maxCounter > k:
                alphabet[s[l]] -= 1
                l += 1
            
            res = max(res, r - l + 1)

        return res
```

## Optimal Solutions

---

The most optimal solution for the problem "424. Longest Repeating Character Replacement" involves using the sliding window technique along with a character frequency count within the current window. The key idea is to maintain a window that can contain a sub-string where the most frequent character plus `k` replacements can fill the entire window.

### Solution Approach: Sliding Window

1. **Character Frequency Count**: Keep a hash map or array to count the frequency of each character in the current window.
2. **Sliding Window**: Two pointers (`left` and `right`) define the current window's bounds. The `right` pointer expands the window, and the `left` pointer shrinks it.
3. **Maintain the Window Validity**: The window is considered valid as long as the length of the window minus the frequency of the most frequent character in it is less than or equal to `k`. This condition implies that we can replace all other characters with the most frequent character using `k` or fewer replacements.
4. **Update the Maximum Length**: As the window expands, update the maximum length of the valid window seen so far.

### Python Implementation

```python
class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        count = {}
        max_count = 0
        max_length = 0
        left = 0

        for right in range(len(s)):
            count[s[right]] = count.get(s[right], 0) + 1
            max_count = max(max_count, count[s[right]])

            if (right - left + 1) - max_count > k:
                count[s[left]] -= 1
                left += 1

            max_length = max(max_length, right - left + 1)

        return max_length

```

### Explanation

- We use a hash map `count` to keep track of the number of times each character appears in the current window.
- `max_count` keeps track of the count of the most frequent character in the current window.
- The window expands by moving `right`, and if the window becomes invalid (`(right - left + 1) - max_count > k`), we shrink it from the `left`.
- `max_length` keeps track of the size of the largest valid window.

### Complexity Analysis

- **Time Complexity**: O(n), where `n` is the length of the string `s`. Each character is visited at most twice, once by the `right` pointer and once by the `left`.
- **Space Complexity**: O(1), as the hash map `count` will contain at most 26 key-value pairs (for each letter in the English alphabet).

This approach is efficient and effective for solving the "Longest Repeating Character Replacement" problem.

## Notes

---

 Since I feel like many solutions didn't explain clearly why it was called "sliding window" (or I was too dumb to understand), here's my attempt to explain in simplest of terms:

First, if you start from the beginning (first character of string), intuitively you know that we want to keep looking down the string until there are `k` characters that are different from the most popular. This is "expanding the window until it's not a valid window anymore". This means moving the right pointer to the right, one by one, until `(length of the substring) - (the "count of most popular character") = k`. We monitor the condition by keeping track of the most popular character with `maxCount`. Simply, when we see a character, we increment its count, and check if it's greater than `maxCount`. If it is, we update `maxCount`.

At this point, we have a window from `start` to `end`, and it has `maxCount` + `k` characters in it. We know we can't keep expanding the window (since there are already `k` characters different from our most popular one). So what do we do? We just slide the entire window down. **Why?** Because the window represents our best answer so far, and anything less than this window we don't care about (remember, we're trying to find the largest window in this string). So it doesn't make sense to shrink the window. While we slide the window, we do 2 things: 1) we see a new character at `end`, and add that to the `count` array. 2) We also decrement the count of the character at `start`, which is now out of the window.

At this point, we only need to know whether the total count of the new character at `end` (which represents the accurate count of this character within the window) is greater than our `maxCount`, which represents the most popular character count **for the current window size** that we have seen. If any new character's count exceeds the `maxCount`, that means: we have found a character in the current window that is even more popular for **this given window size**. Which means, we should now expand the window until we have `k` "weirdos" again! We do this be extending out `end` by 1, and now we have a bigger window and a new `maxCount`. Any new character we see will have to beat this `maxCount` for us to expand the window again. Every step, you move the `end` pointer down the string. If you can expand the window, then you move the `end` and nothing else. If you can't expand the window without violating the rule, then you slide the window by also moving the `start` forward.

Don't forget, the "size of the window" is basically the value that we are trying to find the biggest value for. As you slide the window down, you're basically saying something like: "I have a window of length 4, where 2 of the characters were the same (the `maxCount` characters). Can I find any other window with the same length, but more characters that are the same?If so, then I can expand my window and I've found a larger window. Save this window length as my current best 
answer. Now repeat until I get to the end. Then return the largest window I saw in this string."

## Related Videos

---

[https://youtu.be/gqXU1UyA8pk](https://youtu.be/gqXU1UyA8pk)