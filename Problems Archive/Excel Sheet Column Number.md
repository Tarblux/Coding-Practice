# Excel Sheet Column Number

Problem: 171
Official Difficulty: easy
Feels Like : medium
My Understanding: Fully Understand
Topic: Math, string
Link: https://leetcode.com/problems/excel-sheet-column-number/description/
Completed On : April 24, 2024
Last Review: April 24, 2024
Days Since Review: 6

## Problem

---

Given a string `columnTitle` that represents the column title as appears in an Excel sheet, return *its corresponding column number*.

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
Input: columnTitle = "A"
Output: 1
```

**Example 2:**

```
Input: columnTitle = "AB"
Output: 28
```

**Example 3:**

```
Input: columnTitle = "ZY"
Output: 701
```

**Constraints:**

- `1 <= columnTitle.length <= 7`
- `columnTitle` consists only of uppercase English letters.
- `columnTitle` is in the range `["A", "FXSHRXW"]`.

## My Solutions

---

```python
class Solution:
    @cache
    def titleToNumber(self, columnTitle: str) -> int:

        alphabet = [chr(index) for index in range(65,91)]

        index = [num for num in range(1,27)]
        
        excel_dict = dict(zip(alphabet,index))

        column_number = 0
        power = 0

        for i in range(len(columnTitle)-1 , -1 , -1):

            char = columnTitle[i]
            val = excel_dict[char]
            col_val = val * (26**power)

            column_number += col_val
            power += 1

        return column_number
```

```python

```

## Optimal Solutions

---

```python
from functools import cache

class Solution:
    @cache
    def titleToNumber(self, columnTitle: str) -> int:
        # Generate a dictionary mapping A-Z to 1-26
        letter_to_number = {chr(i): index for i, index in zip(range(65, 91), range(1, 27))}

        column_number = 0  # This will accumulate the result
        exponent = 0  # This will track the exponent for 26 (base 26)

        # Reverse iterate over the column title
        for char in reversed(columnTitle):
            value = letter_to_number[char]  # Get the numerical value of the character
            term_value = value * (26 ** exponent)  # Calculate the value of the current term

            column_number += term_value  # Add the term value to the column number
            exponent += 1  # Increment the power for the next higher place

        return column_number
```

The "Excel Sheet Column Number" problem is often given in coding interviews to test understanding of converting a base-26 numbering system (where A=1, B=2, ..., Z=26) to a decimal number. The column titles of Excel sheets are a good example of such a system, where each letter represents a unique number in a columnar format, akin to how hexadecimal numbers work but with base 26.

The challenge lies in converting an Excel column title like "AB" into the equivalent column number. Here's an explanation of how you might approach solving this problem:

### Explanation and Approach:

Excel column titles are similar to a base-26 numeral system, but instead of starting at 0 (like hexadecimal, binary, etc.), it starts at 1. Here’s how the conversion works:

- **Base Conversion**:
    - Each letter has a positional value, with 'A' being 1, 'B' being 2, and so on up to 'Z' being 26.
    - Each position of a letter in a string represents a power of 26. For example, in "AB", 'A' represents \(26^1\) and 'B' represents \(26^0\).
- **Column Number Calculation**:
    - Read the string from right to left or reverse the string and read from left to right.
    - For each character:
        - Convert it from 'A' based character to its corresponding number (i.e., 'A' to 1, 'B' to 2, ..., 'Z' to 26).
        - Multiply the number by \(26^{\text{position}}\), where position starts from 0 and increases.
    - Sum all these values to get the final column number.

This can be implemented efficiently in a few lines of Python code:

### Example Code:

```python
class Solution:
    def titleToNumber(self, columnTitle: str) -> int:
        result = 0
        n = len(columnTitle)
        for i in range(n):
            result *= 26
            result += (ord(columnTitle[i]) - ord('A') + 1)
        return result
```

### Code Explanation:

1. **Initialization**:
    - `result` is initialized to 0. It will hold the final column number.
2. **Iterate Through the String**:
    - Loop through each character in the `columnTitle`.
    - Multiply the current result by 26 to shift it left by one position in base-26 (similar to multiplying by 10 in base-10 for each new digit added on the left in decimal numbers).
    - Convert the character to its numerical equivalent (1 for 'A', 2 for 'B', ..., 26 for 'Z') using `ord()`. The `ord()` function gets the ASCII code of the character, and subtracting the ASCII code of 'A' and adding 1 adjusts it to the range 1-26.
    - Add this value to `result`.
3. **Return Result**:
    - After the loop, `result` contains the numerical equivalent of the Excel column title.

This solution is efficient, with a time complexity of O(n), where n is the length of the `columnTitle`, and it operates in constant space, O(1).

## Notes

---

 I’ve never felt this much joy in ages , felt so good to be able to do this without any help really and applied a lot of concepts I learnt over the last few months 💖

## Related Videos

---

[https://www.notion.so](https://www.notion.so)