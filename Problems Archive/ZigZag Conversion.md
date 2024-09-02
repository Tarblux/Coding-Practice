# ZigZag Conversion

Problem: 6
Official Difficulty: medium
Feels Like : medium
My Understanding: Mostly Understand
Topic: string
Link: https://leetcode.com/problems/zigzag-conversion/description/
Completed On : August 26, 2024
Last Review: August 26, 2024
Days Since Review: 6

## Problem

---

The string `"PAYPALISHIRING"`
 is written in a zigzag pattern on a given number of rows like this: 
(you may want to display this pattern in a fixed font for better 
legibility)

```
P   A   H   N
A P L S I I G
Y   I   R
```

And then read line by line: `"PAHNAPLSIIGYIR"`

Write the code that will take a string and make this conversion given a number of rows:

```
string convert(string s, int numRows);
```

**Example 1:**

```
Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
```

**Example 2:**

```
Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I
```

**Example 3:**

```
Input: s = "A", numRows = 1
Output: "A"
```

**Constraints:**

- `1 <= s.length <= 1000`
- `s` consists of English letters (lower-case and upper-case), `','` and `'.'`.
- `1 <= numRows <= 1000`

## My Solutions

---

```python
class Solution:
    def convert(self, s: str, numRows: int) -> str:

        if numRows < 2:
            return s
        
        per_cycle = numRows + (numRows - 2)
        
        total_cycles = len(s) // per_cycle
        remaining_chars = len(s) % per_cycle
        
        if remaining_chars > 0:
            extra_cols = (remaining_chars if remaining_chars <= numRows 
                          else remaining_chars - numRows + 1)
        else:
            extra_cols = 0
        
        cols = total_cycles * (numRows - 1) + extra_cols

        grid = [[' ' for _ in range(cols)] for _ in range(numRows)]

        i = 0
        r = c = 0 

        while i < len(s):
            
            for down in range(numRows):
                if i >= len(s):  
                    break
                grid[r][c] = s[i]
                r += 1
                i += 1
            
            r -= 2
            c += 1

            for diag in range(numRows - 2):
                if i >= len(s): 
                    break
                grid[r][c] = s[i]
                r -= 1
                c += 1
                i += 1
            

            r = 0

        print(grid)
        output = ''
        for row in grid:
            output += ''.join(filter(lambda x: x != ' ', row))

        return output
```

```python
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        
        rows = defaultdict(str)
        output = ''
        i = 0
        r = 0
        
        while i < len(s):
            
            for down in range(numRows):
                
                if i >= len(s):
                    break
        
                rows[r] += s[i]
                r += 1
                i += 1
                
            r -= 2
                
            for diag in range(numRows- 2):
                
                if i >= len(s):
                    break
                
                rows[r] += s[i]
                r -= 1
                i += 1
        
        for row in rows.values():
            output += row
            
        return output
```

The code you've written is correct, but it can be optimized for performance. Here are the key areas where improvements can be made:

1. **Using `defaultdict(str)` for `rows`:**
    - While `defaultdict(str)` is convenient, it's not necessary here. You can use a simple list of strings instead, which is generally faster than using a dictionary.
2. **String Concatenation in a Loop:**
    - String concatenation with `+=` in Python is inefficient because strings are immutable, and each concatenation creates a new string. Instead, it's better to use a list to collect all the substrings and then join them at the end.
3. **Redundant Logic in the Zigzag Pattern:**
    - The current approach has separate loops for going down and for diagonal movement, but this can be simplified with a single loop that handles both directions by adjusting the index `r` appropriately.

Here's a more optimized version of your code:

```python
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1 or numRows >= len(s):
            return s

        # Use a list of strings to store each row
        rows = [''] * numRows
        r = 0
        direction = -1

        for char in s:
            rows[r] += char
            # Change direction when you reach the top or bottom row
            if r == 0 or r == numRows - 1:
                direction *= -1
            r += direction

        # Join all rows into one string
        return ''.join(rows)

# Example usage
sol = Solution()
print(sol.convert("PAYPALISHIRING", 3))  # Output: "PAHNAPLSIIGYIR"
print(sol.convert("PAYPALISHIRING", 4))  # Output: "PINALSIGYAHRPI"

```

### Explanation of Changes

1. **List Instead of `defaultdict`:**
    - `rows = [''] * numRows` is more efficient than using `defaultdict(str)` because it avoids the overhead of managing a dictionary and provides direct access to each row.
2. **Optimized String Concatenation:**
    - Instead of concatenating strings directly within the loop, we accumulate characters in a list of strings (`rows`). After processing, we use `''.join(rows)` to efficiently combine the rows into the final result.
3. **Single Loop with Direction Control:**
    - The zigzag pattern is controlled using a single loop with a `direction` variable. This variable toggles between `1` and `1` to move up and down between rows, eliminating the need for two separate loops.

### Complexity Analysis

- **Time Complexity:** `O(n)`, where `n` is the length of the input string `s`. The string is processed in a single pass.
- **Space Complexity:** `O(n)`, for storing the intermediate rows and the final result.

This optimized version should be faster and more memory-efficient, especially for longer input strings.

## Optimal Solutions

---

### Approach

The zigzag pattern can be visualized by placing characters in a grid of rows, and then reading the characters row by row. The characters in the string are placed diagonally downwards, then diagonally upwards, repeatedly.

### Steps to Implement

1. **Base Case**:
    - If `numRows` is 1 or greater than the length of `s`, return `s` as is.
2. **Simulate Zigzag Placement**:
    - Use an array of strings to store characters for each row.
    - Traverse the string `s` and place each character in the appropriate row.
    - Use a variable to track the current row and another to track the direction (up or down).
3. **Concatenate Rows**:
    - After all characters have been placed in the rows, concatenate all rows to form the final string.

### Python Implementation

Here's how you can implement the solution in Python:

```python
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1 or numRows >= len(s):
            return s

        # Create an array for each row
        rows = [''] * min(numRows, len(s))
        current_row = 0
        going_down = False

        # Place each character in the appropriate row
        for char in s:
            rows[current_row] += char
            if current_row == 0 or current_row == numRows - 1:
                going_down = not going_down
            current_row += 1 if going_down else -1

        # Concatenate all rows to form the final string
        return ''.join(rows)

# Example usage
sol = Solution()
print(sol.convert("PAYPALISHIRING", 3))  # Output: "PAHNAPLSIIGYIR"
print(sol.convert("PAYPALISHIRING", 4))  # Output: "PINALSIGYAHRPI"

```

### Explanation

1. **Handling Edge Cases**:
    - If `numRows` is 1, the zigzag pattern is just a straight line, so we return the string as it is.
    - If `numRows` is greater than or equal to the length of the string, each character will be placed in its own row, so again, the string is returned as is.
2. **Placing Characters in Rows**:
    - We initialize a list `rows` with empty strings, one for each row.
    - As we iterate through the string `s`, we place each character in the appropriate row.
    - The `going_down` boolean variable helps to switch directions when we reach either the top or bottom row.
3. **Concatenating Rows**:
    - After processing all characters, we join all the rows to form the final output string.

### Complexity Analysis

- **Time Complexity**: `O(n)`, where `n` is the length of the string `s`. We iterate through the string once.
- **Space Complexity**: `O(n)`, since we store each character in a list of strings and then join them together.

This approach effectively simulates the zigzag pattern and efficiently constructs the final string by placing characters in the appropriate rows.

## Notes

---

 

## Related Videos

---

[https://www.youtube.com/watch?v=Q2Tw6gcVEwc&pp=ygUfemlnemFnIGNvbnZlcnNpb24gbGVldGNvZGUgamF2YQ%3D%3D](https://www.youtube.com/watch?v=Q2Tw6gcVEwc&pp=ygUfemlnemFnIGNvbnZlcnNpb24gbGVldGNvZGUgamF2YQ%3D%3D)