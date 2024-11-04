Problem: 1957
Official Difficulty: easy
Link: https://leetcode.com/problems/delete-characters-to-make-fancy-string/?envType=daily-question&envId=2024-11-01
Completed On : 2024-10-31
Feels Like : easy
Topic: string
My Understanding: Fully Understand
Last Review: 2024-10-31
Days Since Review: 4
Name: Delete Characters to Make Fancy String

# Delete Characters to Make Fancy String
### Problem
___
A **fancy string** is a string where no **three** **consecutive** characters are equal.
Given a string `s`, delete the **minimum** possible number of characters from `s` to make it **fancy**.
Return *the final string after the deletion*. It can be shown that the answer will always be **unique**.
**Example 1:**
```plain text
Input: s = "leeetcode"
Output: "leetcode"
Explanation:
Remove an 'e' from the first group of 'e's to create "leetcode".
No three consecutive characters are equal, so return "leetcode".
```
**Example 2:**
```plain text
Input: s = "aaabaaaa"
Output: "aabaa"
Explanation:
Remove an 'a' from the first group of 'a's to create "aabaaaa".
Remove two 'a's from the second group of 'a's to create "aabaa".
No three consecutive characters are equal, so return "aabaa".

```
**Example 3:**
```plain text
Input: s = "aab"
Output: "aab"
Explanation: No three consecutive characters are equal, so return "aab".
```
**Constraints:**
- `1 <= s.length <= 105`
- `s` consists only of lowercase English letters.
### My Solutions
___
```python
class Solution:
    def makeFancyString(self, s: str) -> str:

        if len(s) < 3:
            return s

        new = ''
        prevs = ['','']

        for i in range(len(s)):

            if prevs[0] == s[i] and prevs[1] == s[i]:
                continue

            prevs[i%2] = s[i]

            new += s[i]

        return new
```

Time Complexity :
```python

```

Time Complexity : 
### Optimal Solutions
___
To solve **LeetCode Problem 1957: Delete Characters to Make Fancy String**, the most efficient approach is to iterate through the string while keeping track of consecutive identical characters to ensure no three consecutive characters are the same.
___
#### **Optimal Algorithm: Linear Traversal with Consecutive Character Check**
**Algorithm Steps:**
1. **Initialize** an empty list `result` to build the fancy string.
2. **Iterate** over each character `c` in the input string `s`:
	- **If** the last two characters in `result` are equal to `c`, **skip** adding `c` to `result` (since adding it would create three consecutive identical characters).
	- **Else**, **append** `c` to `result`.
3. **Join** the characters in `result` to form the final string.
**Code Example:**
```python
def makeFancyString(s):
    result = []
    for c in s:
        if len(result) >= 2 and c == result[-1] == result[-2]:
            continue
        result.append(c)
    return ''.join(result)

```
**Time Complexity:** O(n)
- **Explanation:** We traverse the string once, where `n` is the length of `s`.
**Space Complexity:** O(n)
- **Explanation:** The `result` list stores up to `n` characters in the worst case.
___
#### **Alternative Algorithm: In-Place Modification Using Two-Pointer Technique**
**Algorithm Steps:**
4. **Convert** the string `s` to a list `chars` to allow in-place modification (since strings are immutable).
5. **Initialize** a pointer `i = 0` to track the position for the next valid character.
6. **Iterate** over each character `c` in `chars`:
	- **If** `i >= 2` and `c` is equal to the previous two characters (`chars[i - 1]` and `chars[i - 2]`), **skip** adding `c`.
	- **Else**, assign `chars[i] = c` and increment `i` by 1.
7. **Return** the substring `chars[:i]` joined into a string.
**Code Example:**
```python
def makeFancyString(s):
    chars = list(s)
    i = 0  # Position for the next valid character
    for c in chars:
        if i >= 2 and c == chars[i - 1] == chars[i - 2]:
            continue
        chars[i] = c
        i += 1
    return ''.join(chars[:i])

```
**Time Complexity:** O(n)
- **Explanation:** We traverse the list `chars` once.
**Space Complexity:** O(n)
- **Explanation:** Modifies the list in place, but since we convert the string to a list, it uses O(n) additional space.
___
#### **Summary**
- Both algorithms efficiently remove characters to prevent three consecutive identical characters.
- The first method is straightforward and easy to implement.
- The second method may offer slight space benefits in languages that allow in-place string modification.
___
**Example Usage:**
```python
s = "aaabaaaa"
print(makeFancyString(s))  # Output: "aabaa"

```
This code ensures that the resulting string has no three consecutive identical characters, adhering to the requirements of the problem.
### Notes
___
 
### Related Videos 
___
[]()