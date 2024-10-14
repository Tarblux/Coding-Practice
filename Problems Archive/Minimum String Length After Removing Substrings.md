Problem: 2696
Official Difficulty: easy
Link: https://leetcode.com/problems/minimum-string-length-after-removing-substrings/
Completed On : 2024-10-06
Feels Like : easy
Topic: string, Stack, simulation
My Understanding: Mostly Understand
Last Review: 2024-10-06
Days Since Review: 8
Name: Minimum String Length After Removing Substrings

# Minimum String Length After Removing Substrings
### Problem
___
You are given a string `s` consisting only of **uppercase** English letters.
You can apply some operations to this string where, in one operation, you can remove **any** occurrence of one of the substrings `"AB"` or `"CD"` from `s`.
Return *the ****minimum**** possible length of the resulting string that you can obtain*.
**Note** that the string concatenates after removing the substring and could produce new `"AB"` or `"CD"` substrings.
**Example 1:**
```plain text
Input: s = "ABFCACDB"
Output: 2
Explanation: We can do the following operations:
- Remove the substring "ABFCACDB", so s = "FCACDB".
- Remove the substring "FCACDB", so s = "FCAB".
- Remove the substring "FCAB", so s = "FC".
So the resulting length of the string is 2.
It can be shown that it is the minimum length that we can obtain.
```
**Example 2:**
```plain text
Input: s = "ACBBD"
Output: 5
Explanation: We cannot do any operations on the string so the length remains the same.

```
**Constraints:**
- `1 <= s.length <= 100`
- `s` consists only of uppercase English letters.
### My Solutions
___
```python
class Solution:
    def minLength(self, s: str) -> int:
        stack = []

        for char in s:
            if stack and stack[-1] == "A" and char == "B":
                stack.pop()
            elif stack and stack[-1] == "C" and char == "D":
                stack.pop()
            else:
                stack.append(char)

        length = len(stack)
        return length
```

Time Complexity :
```python

```

Time Complexity : 
### Optimal Solutions
___
#### **Optimal Algorithm: Stack-Based Simulation**
**Algorithm Steps:**
1. **Initialize** an empty stack.
2. **Iterate** over each character `c` in the string `s`:
	- **Push** `c` onto the stack.
	- **Check** if the top of the stack forms a substring that needs to be removed:
		- If it does, **pop** the characters corresponding to that substring from the stack.
3. **After processing** all characters, the **stack** contains the remaining characters.
4. **Return** the length of the stack, which is the minimum length after all possible removals.
**Time Complexity:** O(n)
- Each character is **pushed** and potentially **popped** at most once.
- `n` is the length of the input string.
**Space Complexity:** O(n)
- In the worst case, the stack stores all characters if no substrings are removed.
#### **Example Implementation in Python:**
```python
def minLength(s: str) -> int:
    stack = []
    substrings_to_remove = {'AB', 'CD'}  # Example substrings to remove

    for c in s:
        stack.append(c)
        # Check for possible substrings to remove
        if len(stack) >= 2:
            last_two = stack[-2] + stack[-1]
            if last_two in substrings_to_remove:
                stack.pop()
                stack.pop()
    return len(stack)

```
**Note:** Replace `{'AB', 'CD'}` with the actual substrings specified in the problem.
#### **Alternate Approach: Two-Pointer Technique**
If the substrings to remove are of the form where the characters are inverse pairs or can be matched using specific rules, a two-pointer approach can be employed to optimize space usage.
**Algorithm Steps:**
5. **Use** a slow pointer `i` to keep track of the position in the modified string.
6. **Iterate** over the string with a fast pointer `j`:
	- **Copy** character at `j` to position `i`.
	- **Check** if the substring ending at position `i` forms a removable substring.
		- If it does, **remove** it by decrementing `i`.
	- **Increment** `i` for the next character.
7. **Return** `i`, which represents the length of the minimized string.
**Time Complexity:** O(n)
**Space Complexity:** O(1)
**Note:** This approach modifies the string in place if allowed.
___
By using the stack-based method, you achieve an optimal solution with linear time complexity, effectively minimizing the string length after all possible substrings are removed.
### Notes
___
 
### Related Videos 
___
[]()