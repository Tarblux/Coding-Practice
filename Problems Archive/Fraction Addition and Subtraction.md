# Fraction Addition and Subtraction

Problem: 592
Official Difficulty: medium
Feels Like : medium
My Understanding: Mostly Understand
Topic: Math, Stack, simulation, string
Link: https://leetcode.com/problems/fraction-addition-and-subtraction/description/
Completed On : August 23, 2024
Last Review: August 23, 2024
Days Since Review: 3

## Problem

---

Given a string `expression` representing an expression of fraction addition and subtraction, return the calculation result in string format.

The final result should be an [irreducible fraction](https://en.wikipedia.org/wiki/Irreducible_fraction). If your final result is an integer, change it to the format of a fraction that has a denominator `1`. So in this case, `2` should be converted to `2/1`.

**Example 1:**

```
Input: expression = "-1/2+1/2"
Output: "0/1"
```

**Example 2:**

```
Input: expression = "-1/2+1/2+1/3"
Output: "1/3"
```

**Example 3:**

```
Input: expression = "1/3-1/2"
Output: "-1/6"
```

**Constraints:**

- The input string only contains `'0'` to `'9'`, `'/'`, `'+'` and `'-'`. So does the output.
- Each fraction (input and output) has the format `±numerator/denominator`. If the first input fraction or the output is positive, then `'+'` will be omitted.
- The input only contains valid **irreducible fractions**, where the **numerator** and **denominator** of each fraction will always be in the range `[1, 10]`. If the denominator is `1`, it means this fraction is actually an integer in a fraction format defined above.
- The number of given fractions will be in the range `[1, 10]`.
- The numerator and denominator of the **final result** are guaranteed to be valid and in the range of **32-bit** int.

## My Solutions

---

```python
class Solution:

    def normalize(self,n1,d1,n2,d2):

        frac1 = [n1*d2,d1*d2]
        frac2 = [n2*d1,d2*d1]

        return [frac1,frac2]

    def compute(self,fractions):

        f1 , f2 = fractions

        numerator = f1[0] + f2[0]
        denominator  = f1[1]
        gcd = math.gcd(numerator, denominator)

        return str(numerator // gcd) + '/' + str(denominator // gcd)

    def fractionAddition(self, expression: str) -> str:

        new_expression = ''

        for char in expression:

            if char in "+-":
                new_expression += ' ' + char
            else:
                new_expression += char

        fractions = new_expression.split()

        stack = [fractions[0]]

        output = 0 

        for i in range(1,len(fractions)):

            f1 = stack[0]
            f2 = fractions[i]

            n1 , d1 = [int(val) for val in f1.split('/')]
            n2 , d2 = [int(val) for val in f2.split('/')]

            data = self.normalize(n1,d1,n2,d2)
            last = self.compute(data)

            stack[0] = last

        return stack.pop()
            
```

Sanya

```python
class Solution:
    def fractionAddition(self, expression: str) -> str:
        
        # PREPARE THE MEMO
        memo = defaultdict(list)
        
        sign = None
        top = None
        bottom = None
        index = 0
        while index < len(expression):
            char = expression[index]
            if not sign:
                if char == '-':
                    sign = -1
                    index += 1
                    continue
                elif char == '+':
                    sign = 1
                    index += 1
                    continue
                else:
                    sign = 1
            if char == '/':
                index += 1
                continue
            number = 0
            while char.isdigit():
                number = number * 10 + int(char)
                index += 1
                if index >= len(expression): break
                char = expression[index]
            if not top:
                top = number
            else:
                bottom = number
            if sign and top and bottom:
                memo[bottom].append((sign, top, bottom))
                sign, top, bottom = None, None, None
                continue
            index += 1
        
        # CALCULATE
        sign, top, bottom = None, None, None

        # def gcd(a, b):
        #     while b:
        #         a, b = b, a % b
        #     return a

        def add(s1, t1, b1, s2, t2, b2):
            if b1 == b2:
                top = (s1 * t1) + (s2 * t2)
                sign = 1 if top >= 0 else -1
                bottom = b1
            else:
                top = (s1 * b2 * t1) + (s2 * b1 * t2)
                sign = 1 if top >= 0 else -1
                bottom = b1 * b2
            
            top = abs(top)
            
            d = math.gcd(top, bottom)
            top //= d
            bottom //= d
                
            return (sign, top, bottom)

        sign, top, bottom = 1, 0, 1
        for key in memo:
            items = memo[key]
            local_s, local_t, local_b = 1, 0, 1
            for item in items:
                local_s, local_t, local_b = add(local_s, local_t, local_b, item[0], item[1], item[2])
            sign, top, bottom = add(sign, top, bottom, local_s, local_t, local_b)        

        sign_char = ''
        if sign == -1:
            sign_char = '-'
        
        return sign_char + str(top) + "/" + str(bottom)
```

```python

```

## Optimal Solutions

---

### Problem Description

You are given a string `expression` representing an expression of fraction addition and subtraction. The fractions are in the format `±a/b`, where `a` and `b` are integers, and the expression may contain multiple fractions connected by `+` or `-` operators.

Your task is to return the result of the expression as a simplified fraction.

### Example

```python
Input: expression = "-1/2+1/2+1/3"
Output: "1/3"

Input: expression = "1/3-1/2"
Output: "-1/6"

Input: expression = "5/3+1/3"
Output: "2/1"

```

### Approach

To solve the problem, we need to:

1. Parse the input string to extract the fractions.
2. Perform the addition and subtraction of these fractions.
3. Simplify the resulting fraction.

### Steps

1. **Parsing the Expression**:
    - Split the expression into individual fractions considering the signs.
2. **Finding the Least Common Denominator (LCD)**:
    - To add or subtract fractions, we need a common denominator. The easiest way to find a common denominator is to use the least common denominator (LCD), which is the least common multiple (LCM) of the denominators.
3. **Summing the Fractions**:
    - Convert each fraction to have the common denominator and then sum up the numerators.
4. **Simplifying the Result**:
    - After summing up the fractions, simplify the result by dividing the numerator and denominator by their greatest common divisor (GCD).

### Python Implementation

Here's how you can implement this solution in Python:

```python
import re
from math import gcd
from functools import reduce

class Solution:
    def fractionAddition(self, expression: str) -> str:
        # Find all the fractions in the expression
        fractions = re.findall(r'[+-]?\\d+/\\d+', expression)

        # Initialize numerator and denominator
        numerator, denominator = 0, 1

        for fraction in fractions:
            num, denom = map(int, fraction.split('/'))
            # Update the current numerator and denominator
            numerator = numerator * denom + num * denominator
            denominator *= denom
            # Simplify the result so far
            g = gcd(abs(numerator), denominator)
            numerator //= g
            denominator //= g

        # If the numerator is 0, return "0/1"
        if numerator == 0:
            return "0/1"

        # Ensure the denominator is positive
        if denominator < 0:
            numerator = -numerator
            denominator = -denominator

        return f"{numerator}/{denominator}"

# Example usage
sol = Solution()
print(sol.fractionAddition("-1/2+1/2+1/3"))  # Output: "1/3"
print(sol.fractionAddition("1/3-1/2"))       # Output: "-1/6"
print(sol.fractionAddition("5/3+1/3"))       # Output: "2/1"

```

### Explanation

1. **Parsing**:
    - We use a regular expression (`re.findall`) to extract all fractions from the input string. Each fraction is of the form `±a/b`.
2. **Adding/Subtracting Fractions**:
    - For each fraction, update the cumulative numerator and denominator. The common denominator approach is used to sum fractions.
    - After each addition, simplify the fraction using the GCD of the numerator and denominator.
3. **Simplifying**:
    - The `gcd` function from the `math` module is used to simplify the fraction by dividing both the numerator and denominator by their GCD.
    - Special care is taken to ensure that the denominator is positive, as required by the problem constraints.
4. **Final Output**:
    - Return the simplified fraction as a string in the format `numerator/denominator`.

### Complexity Analysis

- **Time Complexity**: `O(n)` where `n` is the length of the expression. We iterate through the expression once to extract fractions and once again to sum them up.
- **Space Complexity**: `O(1)` for storing the numerator and denominator.

This implementation efficiently parses the input, handles the fraction arithmetic, and simplifies the result, ensuring that the solution is both correct and optimal.

## Notes

---

 

## Related Videos

---

[https://www.notion.so](https://www.notion.so)