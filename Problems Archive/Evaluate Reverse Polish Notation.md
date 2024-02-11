# Evaluate Reverse Polish Notation

Problem: 150
Official Difficulty: medium
Feels Like : medium
Topic: Stack
Link: https://leetcode.com/problems/evaluate-reverse-polish-notation/description/
Completed On : December 26, 2023
My Understanding: Needs Review
Last Review: December 26, 2023
Days Since Review: 46

## Problem

---

You are given an array of strings `tokens` that represents an arithmetic expression in a [Reverse Polish Notation](http://en.wikipedia.org/wiki/Reverse_Polish_notation).

Evaluate the expression. Return *an integer that represents the value of the expression*.

**Note** that:

- The valid operators are `'+'`, `'-'`, `'*'`, and `'/'`.
- Each operand may be an integer or another expression.
- The division between two integers always **truncates toward zero**.
- There will not be any division by zero.
- The input represents a valid arithmetic expression in a reverse polish notation.
- The answer and all the intermediate calculations can be represented in a **32-bit** integer.

**Example 1:**

```
Input: tokens = ["2","1","+","3","*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9

```

**Example 2:**

```
Input: tokens = ["4","13","5","/","+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6

```

**Example 3:**

```
Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
Output: 22
Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22

```

**Constraints:**

- `1 <= tokens.length <= 104`
- `tokens[i]` is either an operator: `"+"`, `"-"`, `"*"`, or `"/"`, or an integer in the range `[-200, 200]`.

## My Solutions

---

```python
class Solution:
    def evalRPN(self, tokens: List[str]) -> int:

        def add(a,b):

            sum = a + b
            
            return sum

        def sub(a,b):

            diff = b - a

            return diff
        
        def mul(a,b):

            mul = a * b

            return mul
        
        def div(a,b):

            div = math.trunc(b/a)

            return div

        dict = { 
            '+' : add ,
            '-' : sub ,
            '*' : mul ,
            '/' : div ,
        
        }

        stack = []

        for i in range (len(tokens)) : 

            if tokens[i] not in dict : 

                stack.append(tokens[i]) 

            else :

                a = int(stack.pop())

                b = int(stack.pop())

                result = dict[tokens[i]](a,b)

                stack.append(result)

        return int(stack.pop())
```

```python

```

## Optimal Solutions

---

The problem "150. Evaluate Reverse Polish Notation" is about evaluating arithmetic expressions written in Reverse Polish notation (RPN). In RPN, operators follow their operands; for instance, to add 3 and 4, one would write "3 4 +" rather than "3 + 4".

### Problem Statement

Given an array of strings, each string being a token representing an integer or an arithmetic operator, evaluate the expression to obtain the integer result.

Operators are binary and include addition (+), subtraction (-), multiplication (*), and division (/). It is guaranteed that the division is between two integers and results in an integer (e.g., 6 / 2 equals 3, not 3.0).

### Solution Approach: Stack

The optimal way to solve this problem is to use a stack, which is a fundamental data structure for processing RPN:

1. **Iterate Through Tokens**: Go through each token (string) in the array.
2. **Process Numbers and Operators**:
    - If the token is a number, push it onto the stack.
    - If the token is an operator, pop the top two elements from the stack, apply the operator, and push the result back onto the stack.
3. **Result**: After processing all tokens, the stack will contain one element, which is the final result.

### Python Implementation

```python
class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []

        for token in tokens:
            if token in "+-*/":
                b, a = stack.pop(), stack.pop()
                if token == '+':
                    stack.append(a + b)
                elif token == '-':
                    stack.append(a - b)
                elif token == '*':
                    stack.append(a * b)
                else:
                    # Integer division adjustment
                    stack.append(int(a / b))
            else:
                stack.append(int(token))

        return stack.pop()

```

### Explanation

- For each token, check if it is an operator (`+-*/`) or an operand (number).
- If it's an operator, pop the top two numbers from the stack, apply the operation, and push the result back onto the stack.
- If it's an operand, convert it to an integer and push onto the stack.
- After processing all tokens, the remaining item on the stack is the result.

### Complexity Analysis

- **Time Complexity**: O(n), where n is the number of tokens. Each token is processed once.
- **Space Complexity**: O(n) for the stack in the worst case, where all tokens are numbers.

This stack-based approach efficiently evaluates expressions in Reverse Polish notation.

## Notes

---

 [https://www.w3schools.com/python/ref_math_trunc.asp](https://www.w3schools.com/python/ref_math_trunc.asp)

Once Alex showed me that you can store a function as a dictionary the intuition became a little more straightforward , more explanation here : 

[https://www.geeksforgeeks.org/python-store-function-as-dictionary-value/#](https://www.geeksforgeeks.org/python-store-function-as-dictionary-value/#)

## Related Videos

---

[https://youtu.be/iu0082c4HDE](https://youtu.be/iu0082c4HDE)