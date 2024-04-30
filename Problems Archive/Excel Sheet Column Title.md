# Excel Sheet Column Title

Problem: 168
Official Difficulty: easy
Feels Like : medium
My Understanding: Mostly Understand
Topic: Math, string
Link: https://leetcode.com/problems/excel-sheet-column-title/description/
Completed On : April 25, 2024
Last Review: April 25, 2024
Days Since Review: 5

## Problem

---

Given an integer `columnNumber`, return *its corresponding column title as it appears in an Excel sheet*.

For example:

```
A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28
...
```

**Example 1:**

```
Input: columnNumber = 1
Output: "A"
```

**Example 2:**

```
Input: columnNumber = 28
Output: "AB"
```

**Example 3:**

```
Input: columnNumber = 701
Output: "ZY"
```

**Constraints:**

- `1 <= columnNumber <= 231 - 1`

## My Solutions

---

```python
class Solution:
    def convertToTitle(self, columnNumber: int) -> str:

        output = ''
        start = ord('A')

        while columnNumber > 0:

            # Helps to make sure when we do the mod we cycle through 0-25, thus fit in the ascii 65-90
            columnNumber -= 1

            letter = chr(start + ((columnNumber)%26))

            columnNumber //= 26

            output += letter

        return output[::-1]

```

```python

```

## Optimal Solutions

---

The problem "Excel Sheet Column Title" involves converting a given integer to the corresponding column title as it appears in an Excel sheet. This problem is essentially about converting a number into a base-26 numeral system, where each digit is represented by letters A to Z instead of numerals.

### Solution Approach:

The key to solving this problem is to understand that Excel titles are a form of base-26 number system but with some peculiarities:

1. It's 1-indexed rather than 0-indexed. This means 'A' corresponds to 1, not 0.
2. When the number is exactly divisible by 26 (like 26, 52, ...), in the usual base systems, you expect the last digit to be '0' (or 'Z' in this case), but here it needs special handling to wrap around to 'Z' correctly and adjust the next significant digit properly.

### Steps to Solve:

1. While the number is greater than zero, extract the remainder of the division of the number by 26.
2. Adjust for the 1-indexed nature by subtracting 1 from the number before the modulo operation. This transformation makes '1' become '0', '2' become '1', ..., and '26' become '25'.
3. Convert this number (0-25) to its corresponding character from 'A' to 'Z'.
4. Prepend this character to the result (since we're constructing the string from least significant value to the most).
5. Update the number by dividing it by 26.
6. If a remainder of the division operation is zero (meaning the number was exactly divisible by 26), special handling is needed to make it wrap around to 'Z'.

### Pseudo Code:

```
function convertToTitle(columnNumber):
    string result = ""
    while columnNumber > 0:
        columnNumber -= 1
        remainder = columnNumber % 26
        result = char('A' + remainder) + result
        columnNumber //= 26
    return result

```

### Implementation in Python:

```python
class Solution:
    def convertToTitle(self, columnNumber: int) -> str:
        result = []
        while columnNumber > 0:
           columnNumber -= 1  # Decrement first to adjust for 1-indexing
            remainder = columnNumber % 26
            result.append(chr(remainder + ord('A')))
            columnNumber //= 26
        return ''.join(reversed(result))

# Example Usage
sol = Solution()
print(sol.convertToTitle(1))  # Output: "A"
print(sol.convertToTitle(28))  # Output: "AB"
print(sol.convertToTitle(701))  # Output: "ZY"

```

### Explanation of the Code:

- The line `columnNumber -= 1` adjusts the number to effectively treat the alphabet as a "zero-based" system for easier calculations.
- Characters are prepended to the result list to construct the title from right to left.
- The result is reversed at the end to correct the order of characters for the final output.

This approach efficiently computes the Excel column title corresponding to a given integer with a time complexity of \(O(\log_{26}(n))\), where \(n\) is the column number, because each iteration reduces the number by approximately a factor of 26.

## Notes

---

 

## Related Videos

---

[https://www.youtube.com/watch?v=X_vJDpCCuoA](https://www.youtube.com/watch?v=X_vJDpCCuoA)