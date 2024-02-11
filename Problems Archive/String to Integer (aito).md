# String to Integer (aito)

Problem: 8
Official Difficulty: medium
Feels Like : medium
Topic: string, two pointers
Link: https://leetcode.com/problems/string-to-integer-atoi
Completed On : November 20, 2023
My Understanding: I Have No Idea
Last Review: November 20, 2023
Days Since Review: 82

## Problem

---

Implement the `myAtoi(string s)` function, which converts a string to a 32-bit signed integer (similar to C/C++'s `atoi` function).

The algorithm for `myAtoi(string s)` is as follows:

1. Read in and ignore any leading whitespace.
2. Check if the next character (if not already at the end of the string) is `'-'` or `'+'`. Read this character in if it is either. This determines if the final
result is negative or positive respectively. Assume the result is
positive if neither is present.
3. Read in next the characters until the next non-digit character or
the end of the input is reached. The rest of the string is ignored.
4. Convert these digits into an integer (i.e. `"123" -> 123`, `"0032" -> 32`). If no digits were read, then the integer is `0`. Change the sign as necessary (from step 2).
5. If the integer is out of the 32-bit signed integer range `[-231, 231 - 1]`, then clamp the integer so that it remains in the range. Specifically, integers less than `231` should be clamped to `231`, and integers greater than `231 - 1` should be clamped to `231 - 1`.
6. Return the integer as the final result.

**Note:**

- Only the space character `' '` is considered a whitespace character.
- **Do not ignore** any characters other than the leading whitespace or the rest of the string after the digits.

**Example 1:**

```
Input: s = "42"
Output: 42
Explanation: The underlined characters are what is read in, the caret is the current reader position.
Step 1: "42" (no characters read because there is no leading whitespace)
         ^
Step 2: "42" (no characters read because there is neither a '-' nor '+')
         ^
Step 3: "42" ("42" is read in)
           ^
The parsed integer is 42.
Since 42 is in the range [-231, 231 - 1], the final result is 42.

```

**Example 2:**

```
Input: s = "   -42"
Output: -42
Explanation:
Step 1: "-42" (leading whitespace is read and ignored)
            ^
Step 2: "-42" ('-' is read, so the result should be negative)
             ^
Step 3: "   -42" ("42" is read in)
               ^
The parsed integer is -42.
Since -42 is in the range [-231, 231 - 1], the final result is -42.

```

**Example 3:**

```
Input: s = "4193 with words"
Output: 4193
Explanation:
Step 1: "4193 with words" (no characters read because there is no leading whitespace)
         ^
Step 2: "4193 with words" (no characters read because there is neither a '-' nor '+')
         ^
Step 3: "4193 with words" ("4193" is read in; reading stops because the next character is a non-digit)
             ^
The parsed integer is 4193.
Since 4193 is in the range [-231, 231 - 1], the final result is 4193.

```

## My Solutions

---

```python

```

### Aleksandr

```python
class Solution:
    def myAtoi(self, s: str) -> int:
        index = 0

        for i in range(index, len(s)):
            char = s[i]
            if char == ' ':
                continue
            else:
                index = i
                break

        if index >= len(s):
            return 0

        sign = 1
        char = s[index]
        if char == '-' or char == '+':
            index += 1
            if char == '-':
                sign = -1

        number = 0
        min_v = -1 * 2 ** 31
        max_v = 2 ** 31 - 1
        for i in range(index, len(s)):
            char = s[i]
            if char.isdigit() == False:
                break
            if number > (max_v - int(char)) // 10:
                if sign == -1:
                    return min_v
                return max_v
            number = number * 10 + int(char)

        return sign * number
```

## Optimal Solutions

---

To implement the `myAtoi` function according to the specified algorithm, we'll follow each of the steps closely. Here's the implementation in Python:

```python
class Solution:
    def myAtoi(self, s):
        # Step 1: Read in and ignore any leading whitespace
        s = s.lstrip()

        # Step 2: Check for '-' or '+'
        negative = False
        if s and (s[0] == '-' or s[0] == '+'):
            negative = s[0] == '-'
            s = s[1:]

        # Step 3: Read in the next characters until a non-digit character
        result = 0
        for char in s:
            if char.isdigit():
                result = result * 10 + int(char)
            else:
                break  # Stop reading when a non-digit is encountered

        # Step 4: Apply the sign
        result = -result if negative else result

        # Step 5: Clamp the integer to the 32-bit signed integer range
        INT_MIN, INT_MAX = -2**31, 2**31 - 1
        if result < INT_MIN:
            return INT_MIN
        elif result > INT_MAX:
            return INT_MAX

        # Step 6: Return the integer
        return result

```

### Explanation:

- **Step 1**: Leading white spaces are removed using `lstrip()`.
- **Step 2**: We check if the first character is a sign (`'-'` or `'+'`). If it is, we set a flag (`negative`) and remove this character.
- **Step 3**: We iterate over the remaining characters. We build the result by multiplying the current result by `10` and adding the digit value of the current character. The loop stops when a non-digit character is encountered.
- **Step 4**: If `negative` is `True`, we negate the result.
- **Step 5**: We clamp the result to the range of 32-bit signed integers.
- **Step 6**: The processed integer is returned.

This implementation closely follows the steps outlined in the problem statement, ensuring the string is correctly parsed and converted to a 32-bit signed integer as per the `atoi` function's behavior.

## Notes

---

 Follow the instructions step by step to avoid having to deal with the edge cases , following it by the book will magically skip edge cases 

## Related Videos

---

[https://youtu.be/YA0LYrKI1CQ?si=RN10xTycaeCUfnzs](https://youtu.be/YA0LYrKI1CQ?si=RN10xTycaeCUfnzs)