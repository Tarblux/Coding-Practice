# Find the Length of the Longest Common Prefix

Problem: 3043
Official Difficulty: medium
Feels Like : medium
My Understanding: Fully Understand
Topic: Trie, array, hash table, string
Link: https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/description/
Completed On : September 23, 2024
Last Review: September 23, 2024
Days Since Review: 10

## Problem

---

You are given two arrays with **positive** integers `arr1` and `arr2`.

A **prefix** of a positive integer is an integer formed by one or more of its digits, starting from its **leftmost** digit. For example, `123` is a prefix of the integer `12345`, while `234` is **not**.

A **common prefix** of two integers `a` and `b` is an integer `c`, such that `c` is a prefix of both `a` and `b`. For example, `5655359` and `56554` have a common prefix `565` while `1223` and `43456` **do not** have a common prefix.

You need to find the length of the **longest common prefix** between all pairs of integers `(x, y)` such that `x` belongs to `arr1` and `y` belongs to `arr2`.

Return *the length of the **longest** common prefix among all pairs*. *If no common prefix exists among them*, *return* `0`.

**Example 1:**

```
Input: arr1 = [1,10,100], arr2 = [1000]
Output: 3
Explanation: There are 3 pairs (arr1[i], arr2[j]):
- The longest common prefix of (1, 1000) is 1.
- The longest common prefix of (10, 1000) is 10.
- The longest common prefix of (100, 1000) is 100.
The longest common prefix is 100 with a length of 3.

```

**Example 2:**

```
Input: arr1 = [1,2,3], arr2 = [4,4,4]
Output: 0
Explanation: There exists no common prefix for any pair (arr1[i], arr2[j]), hence we return 0.
Note that common prefixes between elements of the same array do not count.

```

**Constraints:**

- `1 <= arr1.length, arr2.length <= 5 * 104`
- `1 <= arr1[i], arr2[i] <= 108`

## My Solutions

---

```python
class TrieNode:
    def __init__(self,depth):
        self.children = {}
        self.depth = depth

class Trie:
    def __init__(self):
        self.root = TrieNode(0)

    def addNumber(self, number: str) -> None:
        node = self.root
        depth = 1
        for digit in number:
            if digit not in node.children:
                node.children[digit] = TrieNode(depth)
            node = node.children[digit]
            depth += 1

    def search(self,number):

        node = self.root
        for digit in number:
            if digit not in node.children:
                return node.depth
            node = node.children[digit]

        return node.depth

class Solution:
    def longestCommonPrefix(self, arr1: List[int], arr2: List[int]) -> int:

        longest = 0

        trie = Trie()

        for num in arr1:
            trie.addNumber(str(num))

        for num in arr2:
            longest = max(longest,trie.search(str(num)))

        return longest

```

```python

```

## Optimal Solutions

---

To find the length of the longest common prefix among an array of strings, you can follow these steps:

### Problem:

Given an array of strings, find the longest common prefix (LCP) among all the strings. The LCP is the longest substring that is common at the start of all the strings.

### Approach:

1. **Vertical Scanning**:
    - Compare characters of each string one by one in a vertical manner.
    - If all strings have the same character at the current position, continue to the next character.
    - If a mismatch is found or any string ends, stop and return the length of the common prefix found so far.
2. **Horizontal Scanning**:
    - Start with the first string as the initial prefix.
    - Compare this prefix with each subsequent string, updating the prefix by cutting it down until it matches the beginning of each string.
3. **Divide and Conquer**:
    - Split the array of strings into two halves.
    - Find the LCP for each half and then find the common prefix of the two halves.
    - This is a recursive approach.
4. **Binary Search**:
    - Use binary search on the length of the common prefix.
    - Check if a prefix of a certain length is common to all strings, and adjust the binary search range accordingly.

### Python Implementation using Vertical Scanning:

```python
def longestCommonPrefix(strs):
    if not strs:
        return 0

    # Find the minimum length of strings in the list
    min_length = min(len(s) for s in strs)

    # Iterate through each character position up to the minimum length
    for i in range(min_length):
        # Check if all strings have the same character at position i
        current_char = strs[0][i]
        for s in strs:
            if s[i] != current_char:
                return i  # Return the index where the mismatch occurs

    # If we finish the loop without finding any mismatches, return min_length
    return min_length

# Example usage:
strs = ["flower", "flow", "flight"]
print(longestCommonPrefix(strs))  # Output: 2 ("fl")

strs = ["dog", "racecar", "car"]
print(longestCommonPrefix(strs))  # Output: 0 (no common prefix)

```

### Explanation:

1. **Empty Input Check**:
    - If the input list `strs` is empty, return `0` as there is no common prefix.
2. **Minimum Length Calculation**:
    - Calculate the minimum length of the strings in the array. This helps to avoid index out-of-bounds errors when comparing characters.
3. **Character Comparison**:
    - Iterate through each character position up to the minimum length.
    - For each position `i`, check if all strings have the same character at that position.
    - If a mismatch is found, return the current index `i` as the length of the common prefix.
4. **No Mismatch**:
    - If no mismatches are found and all strings match up to the minimum length, return `min_length`.

### Example Walkthrough:

1. For the input `["flower", "flow", "flight"]`:
    - Common prefix characters: 'f' at position `0`, 'l' at position `1`.
    - Mismatch at position `2` (flower has 'o', flow has 'o', but flight has 'i').
    - Return `2` as the length of the common prefix ("fl").
2. For the input `["dog", "racecar", "car"]`:
    - No common prefix at position `0`.
    - Return `0` since no common characters at the start.

### Complexity Analysis:

1. **Time Complexity**:
    - `O(n * m)`, where `n` is the number of strings and `m` is the length of the shortest string. We may compare each character of each string up to `m` times.
2. **Space Complexity**:
    - `O(1)` since no additional data structures are used apart from variables.

This solution efficiently finds the length of the longest common prefix among an array of strings by directly comparing characters vertically, stopping as soon as a mismatch is found.

## Notes

---

 

## Related Videos

---

[https://youtu.be/06dIUJwdHlQ](https://youtu.be/06dIUJwdHlQ)