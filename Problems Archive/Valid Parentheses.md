# Valid Parentheses

Problem: 20
Official Difficulty: easy
Feels Like : easy
Topic: Stack, string
Link: https://leetcode.com/problems/valid-parentheses/
Completed On : December 11, 2023
My Understanding: Mostly Understand
Last Review: December 11, 2023
Days Since Review: 61

## Problem

---

Given a string `s` containing just the characters `'('`, `')'`, `'{'`, `'}'`, `'['` and `']'`, determine if the input string is valid.

An input string is valid if:

1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.
3. Every close bracket has a corresponding open bracket of the same type.

**Example 1:**

```
Input: s = "()"
Output: true

```

**Example 2:**

```
Input: s = "()[]{}"
Output: true

```

**Example 3:**

```
Input: s = "(]"
Output: false

```

**Constraints:**

- `1 <= s.length <= 104`
- `s` consists of parentheses only `'()[]{}'`.

## My Solutions

---

```python
class Solution:
    def isValid(self, s: str) -> bool:
           
        dict = {
            
            ')' : '(' ,
            ']' : '[' ,
            '}' : '{'           
        }
        
        stacky = []

        for i in range (0,len(s)) : 
            
            if s[i] not in dict : 
                
                stacky.append(s[i]) 
                
            else : 
                
                if len(stacky) != 0 and dict[s[i]] == stacky[-1] : 
                    
                    stacky.pop()
                    
                else : 
                    
                    stacky.append(s[i])
                
        if not stacky : 
            
            return True 
        
        else : 
            
            return False
```

### Sanya

```python
class Solution:
    def isValid(self, s: str) -> bool:
        
        dict = {
            ")" : "(",
            "]" : "[",
            "}" : "{"
        }
        
        stack = []
        
        for char in s:
            if len(stack) > 0 and char in dict and stack[-1] == dict[char]:
                stack.pop()
            else: 
                stack.append(char)
                
        return len(stack) == 0
```

## Optimal Solutions

---

The "Valid Parentheses" problem requires checking if a string containing characters '(', ')', '{', '}', '[' and ']' is valid. A string is valid if:

- Open brackets must be closed by the same type of brackets.
- Open brackets must be closed in the correct order.

### Solution Approach

A common approach to solve this problem is to use a stack data structure. The basic idea is:

1. Initialize an empty stack.
2. Iterate over each character in the string.
    - If the character is an opening bracket ('(', '{', or '['), push it onto the stack.
    - If the character is a closing bracket (')', '}', or ']'), check the element at the top of the stack. If the top element is the corresponding opening bracket, pop it from the stack; otherwise, the string is not valid.
3. After processing all characters, if the stack is empty, the string is valid. If the stack is not empty, it means there are unmatched opening brackets, so the string is not valid.

### Python Implementation

```python
class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        mapping = {")": "(", "}": "{", "]": "["}

        for char in s:
            if char in mapping:
                top_element = stack.pop() if stack else '#'
                if mapping[char] != top_element:
                    return False
            else:
                stack.append(char)

        return not stack

```

### Explanation

- A `mapping` dictionary is used to map each closing bracket to its corresponding opening bracket.
- We iterate over each character in the string:
    - If it's a closing bracket, we check if the last element in the stack is the matching opening bracket. If it's not, or if the stack is empty (handled by `top_element = stack.pop() if stack else '#'`), the string is not valid.
    - If it's an opening bracket, we push it onto the stack.
- Finally, if the stack is empty, then all brackets were matched correctly, and the string is valid. If there are any unmatched brackets left in the stack, the string is not valid.

### Complexity Analysis

- **Time Complexity**: O(n), where `n` is the length of the input string. We process each character exactly once.
- **Space Complexity**: O(n) in the worst case (if all characters are opening brackets), as we store them all in the stack.

## Notes

---

 

## Related Videos

---

[https://www.notion.so](https://www.notion.so)