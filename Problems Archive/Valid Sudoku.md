# Valid Sudoku

Problem: 36
Official Difficulty: medium
Topic: Matrix, array, hash table
Link: https://leetcode.com/problems/valid-sudoku/
Completed On : November 16, 2023
My Understanding: Mostly Understand
Last Review: November 16, 2023
Days Since Review: 86

## Problem

---

Determine if a `9 x 9` Sudoku board is valid. Only the filled cells need to be validated **according to the following rules**:

1. Each row must contain the digits `1-9` without repetition.
2. Each column must contain the digits `1-9` without repetition.
3. Each of the nine `3 x 3` sub-boxes of the grid must contain the digits `1-9` without repetition.

**Note:**

- A Sudoku board (partially filled) could be valid but is not necessarily solvable.
- Only the filled cells need to be validated according to the mentioned rules.

**Example 1:**

![Untitled](Valid%20Sudoku%20f54b4525d18c4d8398fbddc803d23f78/Untitled.png)

```
Input: board =
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: true
```

## My Solutions

---

```python
class Solution(object):
    def isValidSudoku(self, board):
        
        
        row_dict = {}
        col_dict = {}
        cell_dict = {}
        
        for i in range (0,9): 
            
            for j in range (0,9) : 
                
                cell = board[i][j]
                
                key = (i//3) * 10 + (j//3)
            
                if cell != '.' :
                    
                    if j not in col_dict :
                        
                        col_dict[j] = [cell]
                        
                    else : 
                        
                        array = col_dict[j]
                        
                        if cell in array : 
                            
                            return False
                        
                        col_dict[j].append(cell)
                
                    if i not in row_dict :    
                        
                        row_dict[i] = [cell]
                        
                    else : 
                        
                        array = row_dict[i]
                        
                        if cell in array : 
                            
                            return False
                        
                        row_dict[i].append(cell)
                    
                    if key not in cell_dict : 
                        
                        cell_dict [key] = [cell]
                        
                    else : 
                        
                        array = cell_dict[key]
                        
                        if cell in array : 
                            
                            return False 
                        
                        cell_dict[key].append(cell)
                        
        
        return True
```

```python

```

## Optimal Solutions

---

The most optimal way to determine if a 9x9 Sudoku board is valid involves checking all three conditions (rows, columns, and 3x3 sub-boxes) simultaneously in a single pass through the board. This can be efficiently done using hash sets to keep track of the numbers seen in each row, each column, and each sub-box.

Here's a step-by-step approach:

### Step-by-Step Approach:

1. **Create Data Structures for Tracking**:
    - Initialize three lists of sets: one for rows, one for columns, and one for sub-boxes. Each list will contain 9 sets corresponding to the 9 rows, 9 columns, and 9 sub-boxes.
2. **Iterate Over Each Cell of the Board**:
    - Go through each cell in the board using a nested loop.
3. **Check and Update Sets for Each Cell**:
    - For each cell that is not empty (contains a digit):
        - Calculate the index of the sub-box. This can be done using `box_index = (row // 3) * 3 + col // 3`.
        - Check if the digit is already present in the corresponding row set, column set, or sub-box set.
        - If the digit is found in any of these sets, the board is invalid.
        - If not, add the digit to the appropriate sets.
4. **Return Validity**:
    - If the entire board is traversed without finding any duplicates in rows, columns, and sub-boxes, then the board is valid.

### Implementation in Python:

```python
class Solution(object):
    def isValidSudoku(self, board):
        rows = [set() for _ in range(9)]
        cols = [set() for _ in range(9)]
        boxes = [set() for _ in range(9)]

        for row in range(9):
            for col in range(9):
                num = board[row][col]
                if num != '.':
                    box_index = (row // 3) * 3 + col // 3
                    if num in rows[row] or num in cols[col] or num in boxes[box_index]:
                        return False
                    rows[row].add(num)
                    cols[col].add(num)
                    boxes[box_index].add(num)

        return True

```

In this implementation:

- We use three lists (`rows`, `cols`, and `boxes`) to track the digits seen in each row, column, and 3x3 sub-box.
- The `box_index` calculation determines which of the 9 sub-boxes the current cell belongs to.
- We add the current number to the appropriate sets after confirming it's not already present in any of them.
- If we encounter a duplicate, we immediately return `False`.
- If no duplicates are found, the function returns `True`, indicating the board is valid.

This approach efficiently validates the Sudoku board in a single pass with O(1) lookups for each cell, making it an optimal solution.

## Notes

---

## Related Videos

---

[https://www.youtube.com/watch?v=TjFXEUCMqI8](https://www.youtube.com/watch?v=TjFXEUCMqI8)