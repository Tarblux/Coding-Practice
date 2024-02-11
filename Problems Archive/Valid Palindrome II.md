# Valid Palindrome II

Problem: 680
Official Difficulty: easy
Feels Like : medium
Topic: greedy, string, two pointers
Link: https://leetcode.com/problems/valid-palindrome-ii/description/
Completed On : February 3, 2024
My Understanding: Mostly Understand
Last Review: February 3, 2024
Days Since Review: 7

## Problem

---

Given a string `s`, return `true` *if the* `s` *can be palindrome after deleting **at most one** character from it*.

**Example 1:**

```
Input: s = "aba"
Output: true
```

**Example 2:**

```
Input: s = "abca"
Output: true
Explanation: You could delete the character 'c'.
```

**Example 3:**

```
Input: s = "abc"
Output: false
```

**Constraints:**

- `1 <= s.length <= 105`
- `s` consists of lowercase English letters.

## My Solutions

---

Thought I made a big brain move here but this ends up being O(n^2) because of the slicing checks so it ends up with time limit exceeded for larger outputs 

```python
class Solution:
    def validPalindrome(self, s: str) -> bool:

        for i in range(len(s)):

            cur_string = s[:i] + s[i+1:]

            if  cur_string == cur_string[::-1] : 

                return True

        return False
```

```python

```

## Optimal Solutions

---

### Integrated Approach

In this method, when a mismatch is found, you check the two possible substrings (skipping the mismatched character from either end) directly within the loop by extending the two-pointer technique to each substring.

### Python Implementation

```python
class Solution:
    def validPalindrome(self, s: str) -> bool:
        def checkPalindrome(start, end):
            while start < end:
                if s[start] != s[end]:
                    return False
                start += 1
                end -= 1
            return True

        left, right = 0, len(s) - 1
        while left < right:
            if s[left] != s[right]:
                # Check two substrings: one skipping the left character, another skipping the right character
                skipLeft = checkPalindrome(left + 1, right)
                skipRight = checkPalindrome(left, right - 1)
                return skipLeft or skipRight
            left += 1
            right -= 1
        return True

```

### Explanation

- This solution defines an inner function `checkPalindrome` that checks if a substring of `s` defined by `start` and `end` indexes is a palindrome.
- The main logic iterates through the string `s` using two pointers (`left` and `right`). Upon encountering a mismatch, it uses `checkPalindrome` to verify if skipping the character at `left` or `right` results in a palindrome.
- If either skipping the left character or skipping the right character results in a palindrome (`skipLeft or skipRight`), the function returns `True`.
- If no mismatch is encountered throughout the loop, the entire string is a palindrome, and the function returns `True`.

### Key Difference

- The key difference in this approach compared to the previous one is how the palindrome check for the substring is integrated directly into the main function logic. This reduces the need for separate function calls to handle the case where a character might be skipped.

### Complexity Analysis

- **Time Complexity**: O(n), where `n` is the length of the string. The worst-case scenario involves checking almost the entire string twice, once for each substring created by skipping a character.
- **Space Complexity**: O(1), as the solution only uses a few extra variables for its logic, without any additional data structures based on the input size.

Both methods provide efficient solutions to the problem, with slight variations in how they structure the palindrome check logic.

### Explain Like I am Five (ELI5)

---

## Notes

---

 

## Related Videos

---

[https://www.notion.so](https://www.notion.so)