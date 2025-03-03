# Remove Stars From a String

Problem: 2390
Official Difficulty: medium
Feels Like : easy breazy
My Understanding: Fully Understand
Topic: Stack, simulation, string
Link: https://leetcode.com/problems/removing-stars-from-a-string/description/?envType=problem-list-v2&envId=simulation
Completed On : December 31, 2024
Last Review: December 31, 2024
Days Since Review: 61
Neetcode: No

## Problem

---

You are given a string `s`, which contains stars `*`.

In one operation, you can:

- Choose a star in `s`.
- Remove the closest **non-star** character to its **left**, as well as remove the star itself.

Return *the string after **all** stars have been removed*.

**Note:**

- The input will be generated such that the operation is always possible.
- It can be shown that the resulting string will always be unique.

**Example 1:**

```
Input: s = "leet**cod*e"
Output: "lecoe"
Explanation: Performing the removals from left to right:
- The closest character to the 1st star is 't' in "leet**cod*e". s becomes "lee*cod*e".
- The closest character to the 2nd star is 'e' in "lee*cod*e". s becomes "lecod*e".
- The closest character to the 3rd star is 'd' in "lecod*e". s becomes "lecoe".
There are no more stars, so we return "lecoe".
```

**Example 2:**

```
Input: s = "erase*****"
Output: ""
Explanation: The entire string is removed, so we return an empty string.

```

**Constraints:**

- `1 <= s.length <= 105`
- `s` consists of lowercase English letters and stars ``.
- The operation above can be performed on `s`.

## My Solutions

---

```python
class Solution:
    def removeStars(self, s: str) -> str:

        queue = deque()

        for i in range(len(s)):

            char = s[i]

            if char == '*':
                if queue:
                    queue.pop()
                    continue

            queue.append(char)

        return ''.join(queue)

```

```python

```

## Optimal Solutions

---

The problem can be solved efficiently using a **stack-based approach**.

---

### **Approach**

1. **Use a Stack:**
    - Traverse the string character by character.
    - If the current character is not a star (`'*'`), push it onto the stack.
    - If the current character is a star (`'*'`), pop the top element from the stack (if the stack is not empty). This simulates removing the last character from the result.
2. **Construct the Result:**
    - After processing all characters, the stack contains the final result string (in order).
    - Join the stack to form the output string.

---

### **Why This Works**

The stack effectively maintains the characters of the resulting string. When encountering a star, it removes the last added character (the top of the stack). This approach directly implements the star removal rule in O(n) time.

---

### **Code Implementation**

```python
class Solution:
    def removeStars(self, s: str) -> str:
        stack = []

        for char in s:
            if char == '*':
                if stack:
                    stack.pop()  # Remove the last added character
            else:
                stack.append(char)  # Add the character to the result

        return ''.join(stack)

```

---

### **Complexity Analysis**

- **Time Complexity:** O(n)
    - Each character is processed once. Pushing and popping from the stack are O(1) operations.
- **Space Complexity:** O(n)
    - In the worst case (e.g., no stars), all characters are stored in the stack.

---

### **Example Walkthrough**

**Input:**

`s = "leet**cod*e"`

**Execution:**

1. Traverse the string:
    - `l → stack = ['l']`
    - `e → stack = ['l', 'e']`
    - `e → stack = ['l', 'e', 'e']`
    - `t → stack = ['l', 'e', 'e', 't']`
    - `→ stack = ['l', 'e', 'e']`
    - `→ stack = ['l', 'e']`
    - `c → stack = ['l', 'e', 'c']`
    - `o → stack = ['l', 'e', 'c', 'o']`
    - `d → stack = ['l', 'e', 'c', 'o', 'd']`
    - `→ stack = ['l', 'e', 'c', 'o']`
    - `e → stack = ['l', 'e', 'c', 'o', 'e']`
2. Final stack: `['l', 'e', 'c', 'o', 'e']`.

**Output:**

`"lecoe"`

---

### **Alternative Approach**

An alternative is to directly build the result string without explicitly using a stack by appending/removing characters from a list. However, this approach is functionally the same as the stack-based one.

Both approaches are efficient and straightforward.

## Notes

---

 

## Related Videos

---

[https://www.notion.so](https://www.notion.so)