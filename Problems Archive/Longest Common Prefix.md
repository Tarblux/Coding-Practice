# Longest Common Prefix

Problem: 14
Official Difficulty: easy
Feels Like : medium
Topic: string, tree
Link: https://leetcode.com/problems/longest-common-prefix/
Completed On : November 21, 2023
My Understanding: Needs Review
Last Review: November 21, 2023
Days Since Review: 81

## Problem

---

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string `""`.

**Example 1:**

```
Input: strs = ["flower","flow","flight"]
Output: "fl"

```

**Example 2:**

```
Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

```

**Constraints:**

- `1 <= strs.length <= 200`
- `0 <= strs[i].length <= 200`
- `strs[i]` consists of only lowercase English letters.

## My Solutions

---

```python
class Solution(object):
    def longestCommonPrefix(self, strs):
        
        
        if not strs : 
            
            return ""
        
        string_lengths = []
        
        com_pref = ""
        
        for string in strs :
            
            string_lengths.append(len(string))
            
        shortest = min(string_lengths)
        
        for i in range(shortest):
            
            char = strs[0][i]
            match = True

            for s in strs:
                if s[i] != char:
                    
                    match = False
                    
                    break

            if match == True :
                
                com_pref += char
                
            else:
            
                break
                
        return com_pref
```

### Sanya

```python
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        
        #find min length
        min_l = 2 ** 32 - 1
        for word in strs:
            if (min_l > len(word)):
                min_l = len(word)
                
        prefix = ''
        cur = ''
        for i in range(0, min_l):
            for index, word in enumerate(strs):
                if cur == '':
                    cur = word[i]

                if word[i] != cur:
                    return prefix
                
                if index == len(strs) - 1:
                    prefix += cur
            cur = ''
                    
        return prefix
```

## Optimal Solutions

---

To find the longest common prefix among an array of strings, we can follow a simple approach of comparing the characters at each index across all strings until we find a mismatch. Here's how to implement it:

1. **Handle Edge Cases**: If the array is empty, return an empty string.
2. **Find the Shortest String**: The longest possible common prefix cannot be longer than the shortest string in the array.
3. **Iterate and Compare Characters**: Compare characters at each index across all strings. Stop when a mismatch is found.

Here's the implementation in Python:

```python
class Solution:
    def longestCommonPrefix(self, strs):
        # Edge case: if the array is empty
        if not strs:
            return ""

        # Find the shortest string in strs
        shortest = min(strs, key=len)

        # Iterate through the characters of the shortest string
        for i, char in enumerate(shortest):
            # Compare the character with the character at the same position in other strings
            for other in strs:
                if other[i] != char:
                    # Return the substring from the start to the position of mismatch
                    return shortest[:i]

        # If no mismatch is found, the entire shortest string is the common prefix
        return shortest

```

### Explanation:

- The function first checks if the input array `strs` is empty. If it is, it returns an empty string.
- It then finds the shortest string in `strs`, as the common prefix cannot be longer than this string.
- The function iterates over each character in the shortest string and compares it with the characters at the same index in the other strings.
- If a mismatch is found, the function returns the substring from the start of the shortest string to the index of the mismatch.
- If no mismatch is found across all strings, the entire shortest string is the longest common prefix.

## Notes

---

 

## Related Videos

---

[https://www.youtube.com/watch?v=0sWShKIJoo4](https://www.youtube.com/watch?v=0sWShKIJoo4)