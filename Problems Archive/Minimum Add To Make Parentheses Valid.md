Problem: 921
Official Difficulty: medium
Link: https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/description/?envType=daily-question&envId=2024-10-09
Completed On : 2024-10-09
Feels Like : medium
Topic: string, Stack, greedy
My Understanding: Mostly Understand
Last Review: 2024-10-09
Days Since Review: 5
Name: Minimum Add To Make Parentheses Valid

# Minimum Add To Make Parentheses Valid
### Problem
___
A parentheses string is valid if and only if:
- It is the empty string,
- It can be written as `AB` (`A` concatenated with `B`), where `A` and `B` are valid strings, or
- It can be written as `(A)`, where `A` is a valid string.
You are given a parentheses string `s`. In one move, you can insert a parenthesis at any position of the string.
- For example, if `s = "()))"`, you can insert an opening parenthesis to be `"(``**(**``)))"` or a closing parenthesis to be `"())``**)**``)"`.
Return *the minimum number of moves required to make *`s`* valid*.
**Example 1:**
```plain text
Input: s = "())"
Output: 1

```
**Example 2:**
```plain text
Input: s = "((("
Output: 3

```
**Constraints:**
- `1 <= s.length <= 1000`
- `s[i]` is either `'('` or `')'`.
### My Solutions
___
```python
class Solution:
    def minAddToMakeValid(self, s: str) -> int:

        open_brackets = 0
        min_adds= 0

        for paren in s:
            if paren == "(":
                open_brackets += 1
            else:
                if open_brackets > 0:
                    open_brackets -= 1
                else:
                    min_adds += 1

        return open_brackets + min_adds
```

Time Complexity :
```python

```

Time Complexity : 
### Optimal Solutions
___
To solve **LeetCode Problem 921: Minimum Add to Make Parentheses Valid**, the most optimal approach is to track the balance of parentheses using a single-pass algorithm with constant space.
___
#### **Optimal Algorithm: Balance Tracking**
**Algorithm Steps:**
1. **Initialize** two variables:
	- `ans = 0`: Counts the minimum number of parentheses needed to be added.
	- `balance = 0`: Represents the current balance of open and close parentheses.
2. **Iterate** over each character `c` in the string `S`:
	- **If** `c == '('`:
		- Increment `balance` by 1.
	- **Else** (when `c == ')'`):
		- Decrement `balance` by 1.
		- **If** `balance == -1`:
			- Increment `ans` by 1 (indicating an unmatched closing parenthesis).
			- Reset `balance` to 0.
3. **Return** the total additions required:
	- `ans + balance` (unmatched opening parentheses are accounted for by `balance`).
**Time Complexity:** O(n)
- Single iteration over the string of length `n`.
**Space Complexity:** O(1)
- Uses constant extra space regardless of input size.
**Code Example:**
```python
def minAddToMakeValid(S):
    ans = 0
    balance = 0
    for c in S:
        if c == '(':
            balance += 1
        else:  # c == ')'
            balance -= 1
            if balance == -1:
                ans += 1
                balance = 0
    return ans + balance

```
___
#### **Alternate Algorithm: Stack Simulation**
**Algorithm Steps:**
4. **Initialize** an empty stack.
5. **Iterate** over each character `c` in `S`:
	- **If** `c == '('`:
		- **Push** `c` onto the stack.
	- **Else** (when `c == ')'`):
		- **If** the stack is not empty and the top is `'('`:
			- **Pop** from the stack (matching a pair).
		- **Else**:
			- **Push** `c` onto the stack (unmatched closing parenthesis).
6. **Return** the size of the stack, which represents unmatched parentheses.
**Time Complexity:** O(n)
- Single pass through the string.
**Space Complexity:** O(n)
- In the worst case, the stack could store all characters.
**Code Example:**
```python
def minAddToMakeValid(S):
    stack = []
    for c in S:
        if c == '(':
            stack.append(c)
        else:  # c == ')'
            if stack and stack[-1] == '(':
                stack.pop()
            else:
                stack.append(c)
    return len(stack)

```
___
#### **Recommendation**
The **balance tracking** algorithm is preferred due to its optimal space complexity of **O(1)**, making it more efficient for large input strings.
### Notes
___
 
### Related Videos 
___
[]()