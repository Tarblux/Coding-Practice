Problem: 22
Official Difficulty: medium
Link: https://leetcode.com/problems/generate-parentheses/description/
Completed On : 2024-11-07
Feels Like : medium
Topic: backtracking, string, dynamic programming
My Understanding: Needs Review
Last Review: 2024-11-07
Days Since Review: 3
Name: Generate Prentheses

# Generate Prentheses
### Problem
___
Given `n` pairs of parentheses, write a function to *generate all combinations of well-formed parentheses*.
**Example 1:**
```plain text
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
```
**Example 2:**
```plain text
Input: n = 1
Output: ["()"]
```
**Constraints:**
- `1 <= n <= 8`
### My Solutions
___
```python
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:

        parentheses = []

        def backtrack(state,left,right):

            if len(state) == 2*n:
                parentheses.append(state)

            if left < n:
                backtrack(state + '(' , left + 1 , right)

            if right < left:
                backtrack(state + ')',left,right + 1 )

        backtrack('',0,0)

        return parentheses
```

Time Complexity :
```python

```

Time Complexity : 
### Optimal Solutions
___
To solve **LeetCode Problem 22: Generate Parentheses**, the most efficient approach is to use **backtracking** to generate all combinations of well-formed parentheses.
___
#### **Algorithm: Backtracking**
**Algorithm Overview:**
- **Objective:** Generate all combinations of `n` pairs of well-formed parentheses.
- **Approach:** Use backtracking to build the combinations recursively, ensuring at each step that:
	- The number of opening parentheses used does not exceed `n`.
	- The number of closing parentheses used does not exceed the number of opening parentheses.
**Algorithm Steps:**
1. **Initialize Parameters:**
	- Create an empty list `result` to store valid combinations.
	- Define a recursive function `backtrack(s, open_count, close_count)` where:
		- `s` is the current string being built.
		- `open_count` is the number of `'('` used.
		- `close_count` is the number of `')'` used.
2. **Base Case:**
	- If the length of `s` equals `2 * n`, a valid combination is formed; add `s` to `result`.
3. **Recursive Exploration:**
	- **If **`**open_count < n**`**:**
		- Append `'('` to `s` and call `backtrack(s + '(', open_count + 1, close_count)`.
	- **If **`**close_count < open_count**`**:**
		- Append `')'` to `s` and call `backtrack(s + ')', open_count, close_count + 1)`.
**Code Example:**
```python
def generateParenthesis(n):
    result = []

    def backtrack(s, open_count, close_count):
        if len(s) == 2 * n:
            result.append(s)
            return
        if open_count < n:
            backtrack(s + '(', open_count + 1, close_count)
        if close_count < open_count:
            backtrack(s + ')', open_count, close_count + 1)

    backtrack('', 0, 0)
    return result

```
**Time Complexity:** O(4ⁿ / √n)
- **Explanation:**
	- The total number of valid combinations is given by the Catalan number Cₙ ≈ 4ⁿ / (n√n).
	- Each valid combination is generated in O(n) time.
**Space Complexity:** O(n)
- **Explanation:**
	- The maximum depth of the recursion stack is `2n`.
	- Space used by the `result` list is not counted towards space complexity unless specified.
___
#### **Alternative Algorithm: Dynamic Programming with Closure Number**
**Algorithm Overview:**
- **Objective:** Generate valid combinations by considering the closure number.
- **Approach:** For each number `i` from 0 to `n - 1`, construct combinations by wrapping one set of parentheses around all combinations generated for `i` and concatenating with combinations for `n - 1 - i`.
**Algorithm Steps:**
4. **Define a Recursive Function **`**generate(n)**`** that Returns All Combinations for **`**n**`** Pairs:**
	- Use memoization to store previously computed results.
5. **Base Case:**
	- If `n == 0`, return `['']`.
6. **Recursive Construction:**
	- For each `i` from `0` to `n - 1`:
		- For each combination `left` in `generate(i)`:
			- For each combination `right` in `generate(n - 1 - i)`:
				- Append `'(' + left + ')' + right` to the result list.
**Code Example:**
```python
def generateParenthesis(n):
    memo = {0: ['']}

    def generate(k):
        if k in memo:
            return memo[k]
        result = []
        for i in range(k):
            for left in generate(i):
                for right in generate(k - 1 - i):
                    result.append(f'({left}){right}')
        memo[k] = result
        return result

    return generate(n)

```
**Time Complexity:** O(4ⁿ / √n)
- **Explanation:**
	- The number of combinations follows the Catalan number.
	- Memoization prevents redundant calculations.
**Space Complexity:** O(4ⁿ / √n)
- **Explanation:**
	- Space used to store all valid combinations and memoization data.
___
#### **Recommendation**
- The **backtracking approach** is preferred due to its simplicity and direct implementation.
- It efficiently generates all valid combinations without redundant computations.
___
**Final Code Solution:**
```python
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        result = []

        def backtrack(s, open_count, close_count):
            if len(s) == 2 * n:
                result.append(s)
                return
            if open_count < n:
                backtrack(s + '(', open_count + 1, close_count)
            if close_count < open_count:
                backtrack(s + ')', open_count, close_count + 1)

        backtrack('', 0, 0)
        return result

```
**Time Complexity:** O(4ⁿ / √n)
**Space Complexity:** O(n)
___
By using backtracking, we explore all possible combinations in a controlled manner, ensuring only valid parentheses strings are added to the result.
### Notes
___
 
### Related Videos 
___
[]()