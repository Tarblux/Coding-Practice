Problem: 51
Official Difficulty: hard
Link: https://leetcode.com/problems/n-queens/description/
Completed On : 2024-10-21
Feels Like : medium
Topic: backtracking, string, array
My Understanding: Needs Review
Last Review: 2024-10-21
Days Since Review: 6
Name: N-Queens

# N-Queens
### Problem
___
The **n-queens** puzzle is the problem of placing `n` queens on an `n x n` chessboard such that no two queens attack each other.
Given an integer `n`, return *all distinct solutions to the ****n-queens puzzle***. You may return the answer in **any order**.
Each solution contains a distinct board configuration of the n-queens' placement, where `'Q'` and `'.'` both indicate a queen and an empty space, respectively.
**Example 1:**
![queens.jpg](https://assets.leetcode.com/uploads/2020/11/13/queens.jpg)
```plain text
Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above

```
**Example 2:**
```plain text
Input: n = 1
Output: [["Q"]]

```
**Constraints:**
- `1 <= n <= 9`
### My Solutions
___
```python
class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:

        col = set()
        pos_diag = set()
        neg_diag = set()

        output = []
        board = [['.' for i in range(n)] for i in range(n)]

        def backtrack(r):

            if r == n:
                cur_state = [''.join(row) for row in board]
                output.append(cur_state)
                return

            for c in range(n):

                if c in col or (r + c) in pos_diag or (r-c) in neg_diag:
                    continue

                col.add(c)
                pos_diag.add(r+c)
                neg_diag.add(r-c)

                board[r][c] = 'Q'

                backtrack(r + 1)

                col.remove(c)
                pos_diag.remove(r+c)
                neg_diag.remove(r-c)
                board[r][c] = '.'

        backtrack(0)

        return output
```

Time Complexity :
```python

```

Time Complexity : 
### Optimal Solutions
___

### Notes
___
 
### Related Videos 
___
[Ph95IHmRp5M](https://youtu.be/Ph95IHmRp5M)