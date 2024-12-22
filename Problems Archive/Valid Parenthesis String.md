Problem: 678
Official Difficulty: medium
Link: https://leetcode.com/problems/valid-parenthesis-string/description/
Completed On : 2024-12-16
Feels Like : hard
Topic: string, dynamic programming, Stack, greedy
My Understanding: I Have No Idea
Last Review: 2024-12-16
Days Since Review: 6
Name: Valid Parenthesis String

# Valid Parenthesis String
### Problem
___
Given a string `s` containing only three types of characters: `'('`, `')'` and `'*'`, return `true` *if* `s` *is ****valid***.
The following rules define a **valid** string:
- Any left parenthesis `'('` must have a corresponding right parenthesis `')'`.
- Any right parenthesis `')'` must have a corresponding left parenthesis `'('`.
- Left parenthesis `'('` must go before the corresponding right parenthesis `')'`.
- `'*'` could be treated as a single right parenthesis `')'` or a single left parenthesis `'('` or an empty string `""`.
**Example 1:**
```plain text
Input: s = "()"
Output: true
```
**Example 2:**
```plain text
Input: s = "(*)"
Output: true\
```
**Example 3:**
```plain text
Input: s = "(*))"
Output: true
```
**Constraints:**
- `1 <= s.length <= 100`
- `s[i]` is `'('`, `')'` or `'*'`.
### My Solutions
___
```python

```

Time Complexity :
GPT
```python
def checkValidString(s: str) -> bool:
    low = 0  # Minimum possible number of open parentheses
    high = 0 # Maximum possible number of open parentheses

    for char in s:
        if char == '(':
            low += 1
            high += 1
        elif char == ')':
            low -= 1
            high -= 1
        else:  # char == '*'
            low -= 1  # Consider '*' as ')'
            high += 1 # Consider '*' as '('

        if high < 0:
            return False  # Too many ')'

        low = max(low, 0)  # Ensure low doesn't go negative

    return low == 0  # All open parentheses should be matched

# Example usage
s1 = "(*))"
print(checkValidString(s1))  # Output: True

```

Time Complexity : 
### Optimal Solutions
___

### Notes
___
 
Here’s the properly formatted version of your explanation:
___
#### The Reason We Ensure Low Doesn’t Go Negative
The reason we ensure `low` doesn’t go negative is to correctly account for the minimum number of open parentheses necessary to match the closing parentheses encountered so far.
#### Detailed Explanation of Low and High
1. **High:**
	- Represents the maximum possible number of unmatched open parentheses `(`.
	- It increases with `(` and `` (as `` can be treated as `(`).
	- It decreases with `)` (as `)` can match with any of the `(` or `` treated as `(`).
	- If `high` becomes negative, it indicates there are more closing parentheses `)` than could possibly be matched, so the string is invalid.
2. **Low:**
	- Represents the minimum possible number of unmatched open parentheses `(`.
	- It increases with `(` (as it adds an open parenthesis that needs to be matched).
	- It decreases with `)` (as it closes one open parenthesis).
	- It can also decrease with `` (as `` can be treated as `)`).
#### Ensuring Low Doesn’t Go Negative
When processing the string, `low` should never go below zero because a negative `low` would imply more closing parentheses `)` than opening parentheses `(` and `*` combined. This would be invalid since there would be no way to match those extra closing parentheses.
#### Example to Illustrate the Need for Low
Consider the string `(*))`:
3. Initialize `low = 0` and `high = 0`.
4. Process each character:
	- `(`:
		- `low` becomes 1.
		- `high` becomes 1.
	- ``:
		- `low` becomes 0 (considering `` as `)`).
		- `high` becomes 2 (considering `` as `(`).
	- `)`:
		- `low` becomes -1.
		- `high` becomes 1.
At this point, `low` is -1, which indicates an imbalance (more `)` than `(` and `*`), which is invalid unless we correct it. Therefore, we reset `low` to 0:
- `low = max(low, 0)` => `low = 0`.
Continuing:
- `)`:
	- `low` becomes -1.
	- `high` becomes 0.
Again, `low` is -1, so we reset it to 0:
- `low = max(low, 0)` => `low = 0`.
Finally, after processing the entire string, `low` should be 0 to ensure all unmatched opening parentheses are balanced with closing parentheses.
#### Conclusion
Ensuring `low` does not go negative guarantees that at any point in processing the string, we never have more closing parentheses `)` than opening ones `(` and `*` treated as `(`. This helps in maintaining the validity of the parenthesis string.
___
#### Corrected Function with Comments:
```python
def checkValidString(s: str) -> bool:
    low = 0  # Minimum possible number of open parentheses
    high = 0 # Maximum possible number of open parentheses

    for char in s:
        if char == '(':
            low += 1
            high += 1
        elif char == ')':
            low -= 1
            high -= 1
        else:  # char == '*'
            low -= 1  # Consider '*' as ')'
            high += 1 # Consider '*' as '('

        if high < 0:
            return False  # Too many ')'

        low = max(low, 0)  # Ensure low doesn't go negative

    return low == 0  # All open parentheses should be matched

# Example usage
s1 = "(*))"
print(checkValidString(s1))  # Output: True

```
This approach ensures that the string is checked in linear time, O(n), by maintaining the possible range of unmatched open parentheses at each step.
### Related Videos 
___
[]()