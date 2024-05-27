# Valid Word Square

Problem: 422
Official Difficulty: easy
Feels Like : easy breazy
My Understanding: Fully Understand
Topic: Matrix, array, string, string matching
Link: https://leetcode.com/problems/valid-word-square/description/
Completed On : May 19, 2024
Last Review: May 19, 2024
Days Since Review: 7

## Problem

---

Given an array of strings `words`, return `true` *if it forms a valid **word square***.

A sequence of strings forms a valid **word square** if the `kth` row and column read the same string, where `0 <= k < max(numRows, numColumns)`.

**Example 1:**

![https://assets.leetcode.com/uploads/2021/04/09/validsq1-grid.jpg](https://assets.leetcode.com/uploads/2021/04/09/validsq1-grid.jpg)

```
Input: words = ["abcd","bnrt","crmy","dtye"]
Output: true
Explanation:
The 1st row and 1st column both read "abcd".
The 2nd row and 2nd column both read "bnrt".
The 3rd row and 3rd column both read "crmy".
The 4th row and 4th column both read "dtye".
Therefore, it is a valid word square.
```

**Example 2:**

![https://assets.leetcode.com/uploads/2021/04/09/validsq2-grid.jpg](https://assets.leetcode.com/uploads/2021/04/09/validsq2-grid.jpg)

```
Input: words = ["abcd","bnrt","crm","dt"]
Output: true
Explanation:
The 1st row and 1st column both read "abcd".
The 2nd row and 2nd column both read "bnrt".
The 3rd row and 3rd column both read "crm".
The 4th row and 4th column both read "dt".
Therefore, it is a valid word square.
```

**Example 3:**

![https://assets.leetcode.com/uploads/2021/04/09/validsq3-grid.jpg](https://assets.leetcode.com/uploads/2021/04/09/validsq3-grid.jpg)

```
Input: words = ["ball","area","read","lady"]
Output: false
Explanation:
The 3rd row reads "read" while the 3rd column reads "lead".
Therefore, it is NOT a valid word square.
```

**Constraints:**

- `1 <= words.length <= 500`
- `1 <= words[i].length <= 500`
- `words[i]` consists of only lowercase English letters.

## My Solutions

---

```python
from typing import List
from itertools import zip_longest

class Solution:
    def validWordSquare(self, words: List[str]) -> bool:
        
        if not words:
            return True

        col_words = list(zip_longest(*words, fillvalue=None))

        for i in range(len(col_words)):

            cur_word = ''.join(filter(None, col_words[i]))

            if cur_word != words[i]:
                return False

        return True
```

```python

```

## Optimal Solutions

---

### Problem Description

Given an array of strings `words`, determine if it forms a valid word square. A word square is a special type of matrix where the k-th row and k-th column read the exact same string, for all valid k.

### Example

```python
Input: words = ["abcd", "bnrt", "crmy", "dtye"]
Output: True

Input: words = ["abcd", "bnrt", "crm", "dt"]
Output: True

Input: words = ["ball","area","read","lady"]
Output: False

```

### Optimal Solution and Explanation

To determine if the given list of strings forms a valid word square, we can follow these steps:

1. Check the number of rows and columns.
2. Ensure that for each row `i`, the characters in the row at index `j` match the characters in the column at index `j` for all possible indices.

### Iterative Solution

Here’s the Python code for the iterative solution:

```python
def validWordSquare(words):
    for i in range(len(words)):
        for j in range(len(words[i])):
            if j >= len(words) or i >= len(words[j]) or words[i][j] != words[j][i]:
                return False
    return True

# Example usage
print(validWordSquare(["abcd", "bnrt", "crmy", "dtye"]))  # Output: True
print(validWordSquare(["abcd", "bnrt", "crm", "dt"]))     # Output: True
print(validWordSquare(["ball","area","read","lady"]))     # Output: False

```

### Explanation

1. **Iterate through each row `i`**: For each row, iterate through each character at index `j`.
2. **Check boundaries and values**: Ensure that:
    - `j` is within the bounds of the number of rows.
    - `i` is within the bounds of the length of the current word in row `j`.
    - The character at `words[i][j]` matches the character at `words[j][i]`.
3. **Return False if any check fails**: If any of the above conditions are not met, return `False`.
4. **Return True if all checks pass**: If all conditions are met for all rows and columns, return `True`.

### Explain Like I'm Five (ELI5)

Imagine you have a grid of letters, and you want to make sure that if you read any row from left to right, it looks the same as if you read the same column from top to bottom.

1. **Check each letter**: For each letter in each row, find its corresponding letter in the column.
2. **Match the letters**: Make sure the letters match. If any pair of letters doesn't match, it's not a valid word square.
3. **Done**: If all the letters match, then you have a valid word square!

By following these steps, you ensure that the grid of letters forms a word square, where rows and columns correspond perfectly.

## Notes

---

 

## Related Videos

---

[https://www.notion.so](https://www.notion.so)