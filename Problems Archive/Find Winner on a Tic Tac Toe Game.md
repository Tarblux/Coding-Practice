# Find Winner on a Tic Tac Toe Game

Problem: 1275
Official Difficulty: easy
Feels Like : medium
Topic: Matrix, array, hash table, simulation
Link: https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game/description/?envType=study-plan-v2&envId=programming-skills
Completed On : January 30, 2024
My Understanding: Mostly Understand
Last Review: January 30, 2024
Days Since Review: 11

## Problem

---

**Tic-tac-toe** is played by two players `A` and `B` on a `3 x 3` grid. The rules of Tic-Tac-Toe are:

- Players take turns placing characters into empty squares `' '`.
- The first player `A` always places `'X'` characters, while the second player `B` always places `'O'` characters.
- `'X'` and `'O'` characters are always placed into empty squares, never on filled ones.
- The game ends when there are **three** of the same (non-empty) character filling any row, column, or diagonal.
- The game also ends if all squares are non-empty.
- No more moves can be played if the game is over.

Given a 2D integer array `moves` where `moves[i] = [rowi, coli]` indicates that the `ith` move will be played on `grid[rowi][coli]`. return *the winner of the game if it exists* (`A` or `B`). In case the game ends in a draw return `"Draw"`. If there are still movements to play return `"Pending"`.

You can assume that `moves` is valid (i.e., it follows the rules of **Tic-Tac-Toe**), the grid is initially empty, and `A` will play first.

**Example 1:**

![https://assets.leetcode.com/uploads/2021/09/22/xo1-grid.jpg](https://assets.leetcode.com/uploads/2021/09/22/xo1-grid.jpg)

```
Input: moves = [[0,0],[2,0],[1,1],[2,1],[2,2]]
Output: "A"
Explanation: A wins, they always play first.

```

**Example 2:**

![https://assets.leetcode.com/uploads/2021/09/22/xo2-grid.jpg](https://assets.leetcode.com/uploads/2021/09/22/xo2-grid.jpg)

```
Input: moves = [[0,0],[1,1],[0,1],[0,2],[1,0],[2,0]]
Output: "B"
Explanation: B wins.

```

**Example 3:**

![https://assets.leetcode.com/uploads/2021/09/22/xo3-grid.jpg](https://assets.leetcode.com/uploads/2021/09/22/xo3-grid.jpg)

```
Input: moves = [[0,0],[1,1],[2,0],[1,0],[1,2],[2,1],[0,1],[0,2],[2,2]]
Output: "Draw"
Explanation: The game ends in a draw since there are no moves to make.

```

**Constraints:**

- `1 <= moves.length <= 9`
- `moves[i].length == 2`
- `0 <= rowi, coli <= 2`
- There are no repeated elements on `moves`.
- `moves` follow the rules of tic tac toe.

## My Solutions

---

```python
class Solution:
    def tictactoe(self, moves: List[List[int]]) -> str:

        row_dict  , col_dict = {} , {}

        diag1 , diag2 = '' , ''

        X , O = 'XXX' , 'OOO'

        for i , [row,col] in enumerate(moves): 

            symbol = 'X' if i % 2 == 0 else 'O'

            row_dict[row] = row_dict.get(row, '') + symbol

            col_dict[col] = col_dict.get(col, '') + symbol

            if row == col : 

                diag1 += symbol 

            if row + col == 2 : 

                diag2 += symbol

            if X in (row_dict[row], col_dict[col], diag1, diag2):

                return "A"

            if O in (row_dict[row], col_dict[col], diag1, diag2):

                return "B"

        if len(moves) == 9:

            return "Draw"

        else:

            return "Pending"
```

```python

```

## Optimal Solutions

---

### Solution Approach

To solve this problem, maintain a 3x3 matrix to represent the Tic Tac Toe board and process each move made by the players. After each move, check if it results in a win or if the board is full.

### Python Implementation

```python
class Solution:
    def tictactoe(self, moves: List[List[int]]) -> str:
        def check_winner(player_moves):
            # Check rows, columns, and diagonals for a win
            return any(all(board[r][c] == player_moves for c in range(3)) for r in range(3)) \\
                or any(all(board[r][c] == player_moves for r in range(3)) for c in range(3)) \\
                or all(board[i][i] == player_moves for i in range(3)) \\
                or all(board[i][2 - i] == player_moves for i in range(3))

        # Initialize the board
        board = [[0] * 3 for _ in range(3)]

        # Process moves
        for i, (r, c) in enumerate(moves):
            board[r][c] = 'A' if i % 2 == 0 else 'B'
            if check_winner(board[r][c]):
                return board[r][c]

        # Check for draw or pending
        return "Draw" if len(moves) == 9 else "Pending"

```

### Explanation

- For each move in `moves`, place 'A' if it's an even turn (starting with 0), or 'B' if it's an odd turn.
- After each move, call `check_winner` to check if the current player has won.
- `check_winner` checks all rows, all columns, and both diagonals to see if any of them contain the same player's mark.
- If a player wins, return 'A' or 'B' accordingly.
- After all moves, if the number of moves is 9 (board is full), return "Draw". Otherwise, return "Pending".

### Complexity Analysis

- **Time Complexity**: O(1), as the board size is fixed (3x3), and we perform a constant number of checks.
- **Space Complexity**: O(1), as the space used does not depend on the input size and is limited to the 3x3 board.

This solution efficiently determines the result of a Tic Tac Toe game given a sequence of moves.

### Explain Like I am Five (ELI5)

---

## Notes

---

 

## Related Videos

---

[https://www.notion.so](https://www.notion.so)