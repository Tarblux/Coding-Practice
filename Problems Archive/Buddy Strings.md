# Buddy Strings

Problem: 859
Official Difficulty: easy
Feels Like : medium
My Understanding: Needs Review
Topic: hash table, string
Link: https://leetcode.com/problems/buddy-strings/description
Completed On : June 12, 2024
Last Review: June 12, 2024
Days Since Review: 4

## Problem

---

Given two strings `s` and `goal`, return `true` *if you can swap two letters in* `s` *so the result is equal to* `goal`*, otherwise, return* `false`*.*

Swapping letters is defined as taking two indices `i` and `j` (0-indexed) such that `i != j` and swapping the characters at `s[i]` and `s[j]`.

- For example, swapping at indices `0` and `2` in `"abcd"` results in `"cbad"`.

**Example 1:**

```
Input: s = "ab", goal = "ba"
Output: true
Explanation: You can swap s[0] = 'a' and s[1] = 'b' to get "ba", which is equal to goal.

```

**Example 2:**

```
Input: s = "ab", goal = "ab"
Output: false
Explanation: The only letters you can swap are s[0] = 'a' and s[1] = 'b', which results in "ba" != goal.

```

**Example 3:**

```
Input: s = "aa", goal = "aa"
Output: true
Explanation: You can swap s[0] = 'a' and s[1] = 'a' to get "aa", which is equal to goal.

```

**Constraints:**

- `1 <= s.length, goal.length <= 2 * 104`
- `s` and `goal` consist of lowercase letters.

## My Solutions

---

```python
class Solution:
    def buddyStrings(self, s: str, goal: str) -> bool:

        if len(s) != len(goal):
            return False

        diff = 0

        for i in range(len(s)):
            if s[i] != goal[i]:
                diff += 1

        if diff == 2:
            return Counter(goal) == Counter(s)
        elif diff == 0:
            return not len(set(goal)) == len(goal)
        else:
            return False
        
```

```python

```

## Optimal Solutions

---

### Problem Description

Given two strings `s` and `goal`, return `true` if you can swap two letters in `s` so the result is equal to `goal`, otherwise, return `false`.

Swapping letters is defined as taking two indices `i` and `j` (0-indexed) such that `i != j` and swapping the characters at `s[i]` and `s[j]`.

### Example

```python
Input: s = "ab", goal = "ba"
Output: true

Input: s = "ab", goal = "ab"
Output: false

Input: s = "aa", goal = "aa"
Output: true

Input: s = "aaaaaaabc", goal = "aaaaaaacb"
Output: true

Input: s = "", goal = "aa"
Output: false

```

### Optimal Solution and Explanation

To solve this problem, we need to consider a few cases:

1. **Length Check**: If the lengths of `s` and `goal` are different, return `false` immediately.
2. **Identical Strings**:
    - If `s` and `goal` are identical, check if there is at least one character that appears more than once. If such a character exists, we can swap the duplicate characters to get the same string, so return `true`.
3. **Different Strings**:
    - Find the indices where `s` and `goal` differ.
    - If there are exactly two differences and swapping the characters at these indices in `s` makes it equal to `goal`, return `true`.
    - Otherwise, return `false`.

### Python Code

Here's the Python code to achieve this:

```python
def buddyStrings(s, goal):
    # If lengths of s and goal are different, return False
    if len(s) != len(goal):
        return False

    # If s and goal are the same, check for any duplicate characters
    if s == goal:
        seen = set()
        for char in s:
            if char in seen:
                return True
            seen.add(char)
        return False

    # Find indices where s and goal differ
    diff = []
    for i in range(len(s)):
        if s[i] != goal[i]:
            diff.append(i)

    # There must be exactly two differences and they must be swappable
    return len(diff) == 2 and s[diff[0]] == goal[diff[1]] and s[diff[1]] == goal[diff[0]]

# Example usage
print(buddyStrings("ab", "ba"))  # Output: true
print(buddyStrings("ab", "ab"))  # Output: false
print(buddyStrings("aa", "aa"))  # Output: true
print(buddyStrings("aaaaaaabc", "aaaaaaacb"))  # Output: true
print(buddyStrings("", "aa"))  # Output: false

```

### Explanation

1. **Length Check**:
    - If `s` and `goal` have different lengths, return `false`.
2. **Identical Strings**:
    - If `s` and `goal` are the same, iterate through `s` and check for any duplicate characters. If a duplicate character is found, return `true`. If no duplicates are found, return `false`.
3. **Different Strings**:
    - Create a list `diff` to store the indices where `s` and `goal` differ.
    - Iterate through the strings and append the indices of differing characters to `diff`.
    - If there are exactly two differing indices and swapping the characters at these indices makes `s` equal to `goal`, return `true`.
    - Otherwise, return `false`.

### Time Complexity Analysis

- **Time Complexity**: `O(n)`, where `n` is the length of the strings.
    - We iterate through the strings a constant number of times.

### Space Complexity Analysis

- **Space Complexity**: `O(n)` in the worst case for storing the set of seen characters and the list of differing indices.

### Explain Like I'm Five (ELI5)

Imagine you have two strings made up of letters and you want to see if you can make the first string look like the second one by swapping just two letters:

1. **Check Sizes**: First, make sure both strings are the same length. If not, it's not possible.
2. **Check for Duplicates**: If the strings are exactly the same, check if there's any letter that appears more than once. If yes, you can swap the duplicates to get the same string.
3. **Find Differences**: If the strings are different, find the positions where they differ. If there are exactly two differences and swapping these makes the strings the same, then it works. If not, it doesn't.

By following these steps, you can figure out if you can make one string look like the other by swapping just two letters.

## Notes

---

 

## Related Videos

---

[https://www.youtube.com/watch?v=wA3ZE0iZgG8&pp=ygUNYnVkZHkgc3RyaW5ncw%3D%3D](https://www.youtube.com/watch?v=wA3ZE0iZgG8&pp=ygUNYnVkZHkgc3RyaW5ncw%3D%3D)