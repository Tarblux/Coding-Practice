# Longest Palindromic Substring

Problem: 5
Official Difficulty: medium
Feels Like : medium
Topic: dynamic programming, string
Link: https://leetcode.com/problems/longest-palindromic-substring/description/
Completed On : January 9, 2024
My Understanding: Mostly Understand
Last Review: January 9, 2024
Days Since Review: 32

## Problem

---

Given a string `s`, return *the longest* *palindromic* *substring* in `s`.

**Example 1:**

```
Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.

```

**Example 2:**

```
Input: s = "cbbd"
Output: "bb"

```

**Constraints:**

- `1 <= s.length <= 1000`
- `s` consist of only digits and English letters.

## My Solutions

---

```python
class Solution:
    
    def palini(self,s): 
        
        return s == s[::-1]
 
    
    def longestPalindrome(self, s: str) -> str:

        if len(s) <= 1 :
            
            return s 
 
        longest = ''
        
        max_length = 0
            
        for i in range (0,len(s)): 
            
            for j in range (i+1,len(s)):
                
                if s[i] == s[j] : 
                    
                    length = (j - i) + 1
                
                    if self.palini(s[i:j+1]) == True and length >= max_length : 
                        
                        max_length = length
                        
                        longest = s[i:j+1]
    
        
        return longest if len(longest) > 0 else s[0]
```

```python

```

## Optimal Solutions

---

### Solution 1: Dynamic Programming

The idea is to create a table `dp` where `dp[i][j]` will be `True` if the sub string `s[i:j+1]` is a palindrome.

```python
class Solution:
    def longestPalindrome(self, s: str) -> str:
        n = len(s)
        if n < 2:
            return s

        dp = [[False] * n for _ in range(n)]
        start, max_length = 0, 1

        # Every single character is a palindrome
        for i in range(n):
            dp[i][i] = True

        for end in range(n):
            for start in range(end):
                # Check for palindrome
                if s[start] == s[end] and (end - start == 1 or dp[start + 1][end - 1]):
                    dp[start][end] = True
                    if max_length < end - start + 1:
                        max_length = end - start + 1
                        longest_start = start

        return s[longest_start:longest_start + max_length]
```

Dynamic Programming (DP) is a method for solving complex problems by breaking them down into simpler subproblems. In the context of finding the longest palindromic substring, the DP approach involves solving for smaller substrings and building up to the solution for the entire string.

### Detailed Explanation

1. **DP Table Initialization**:
    - Create a 2D table `dp` of size `n x n`, where `n` is the length of the string `s`.
    - `dp[i][j]` is `True` if the substring `s[i:j+1]` is a palindrome.
2. **Base Cases**:
    - Single characters are always palindromes, so set `dp[i][i]` to `True` for all `i`.
    - Two-character substrings are palindromes if both characters are the same. Set `dp[i][i+1]` accordingly.
3. **Filling the DP Table**:
    - Iterate over the substrings of `s`, starting from length 3 up to the length of `s`.
    - For each substring `s[i:j+1]`, it's a palindrome if `s[i] == s[j]` and the substring `s[i+1:j]` is a palindrome (`dp[i+1][j-1]` is `True`).
    - Update `max_length` and `start` index if you find a longer palindrome.
4. **Return the Longest Palindrome**:
    - Extract the longest palindromic substring using the `start` index and `max_length`.
    
    ### Complexity Analysis
    
    - **Time Complexity**: O(n^2). We iterate over all possible substrings (`n(n+1)/2`) and perform O(1) work for each.
    - **Space Complexity**: O(n^2), for the DP table.
    
    ### Solution 2: Expand Around Center
    
    This approach involves treating every index in the string (and every gap between indices) as the center of a potential palindrome and expanding outwards from these centers.
    
    ```python
    class Solution:
        def longestPalindrome(self, s: str) -> str:
            def expandAroundCenter(left, right):
                while left >= 0 and right < len(s) and s[left] == s[right]:
                    left -= 1
                    right += 1
                return s[left + 1:right]
    
            longest = ""
            for i in range(len(s)):
                # Odd length palindrome
                odd_palindrome = expandAroundCenter(i, i)
                if len(odd_palindrome) > len(longest):
                    longest = odd_palindrome
                
                # Even length palindrome
                even_palindrome = expandAroundCenter(i, i + 1)
                if len(even_palindrome) > len(longest):
                    longest = even_palindrome
    
            return longest
    ```
    
    ### Detailed Explanation
    
    1. **Helper Function for Expansion**:
        - The function `expandAroundCenter` takes two indices, `left` and `right`, and expands outwards while the characters at these indices are equal.
        - The function returns the palindrome identified.
    2. **Iterating Over the String**:
        - Iterate through each index in `s`.
        - For each index, treat it as the center of an odd-length and an even-length palindrome.
    3. **Odd and Even Length Palindromes**:
        - For odd-length, call `expandAroundCenter(i, i)`.
        - For even-length, call `expandAroundCenter(i, i + 1)`.
    4. **Keep Track of the Longest Palindrome**:
        - Compare the length of the newly found palindrome with the longest one found so far.
        - Update the longest palindrome if a longer one is found.
    5. **Return the Result**:
        - After iterating through the string, return the longest palindromic substring.
    
    ### Complexity Analysis
    
    - **Time Complexity**: O(n^2). Each expansion can take up to O(n) time, and there are O(n) potential centers.
    - **Space Complexity**: O(1). The space used is independent of the input size.
    
    ### Conclusion
    
    Both approaches have their merits. The DP approach is a classic example of solving a problem by breaking it down into sub problems, while the Expand Around Center approach is more space-efficient and arguably more intuitive once understood. The choice of approach depends on the specific constraints of the problem (like memory limitations) and personal preference.
    

## Notes

---

 

## Related Videos

---

[https://www.youtube.com/watch?v=XYQecbcd6_c&pp=ygUdbG9uZ2VzdCBwYWxpbmRyb21pYyBzdWJzdHJpbmc%3D](https://www.youtube.com/watch?v=XYQecbcd6_c&pp=ygUdbG9uZ2VzdCBwYWxpbmRyb21pYyBzdWJzdHJpbmc%3D)