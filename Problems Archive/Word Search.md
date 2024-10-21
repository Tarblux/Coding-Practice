Problem: 79
Official Difficulty: medium
Link: https://leetcode.com/problems/word-search/description/?envType=problem-list-v2&envId=a2nl34vi
Completed On : 2024-10-16
Feels Like : medium
Topic: array, string, backtracking, Matrix
My Understanding: Fully Understand
Last Review: 2024-10-16
Days Since Review: 4
Name: Word Search

# Word Search
### Problem
___
Given an `m x n` grid of characters `board` and a string `word`, return `true` *if* `word` *exists in the grid*.
The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.
**Example 1:**
![word2.jpg](https://assets.leetcode.com/uploads/2020/11/04/word2.jpg)
```plain text
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true
```
**Example 2:**
![word-1.jpg](https://assets.leetcode.com/uploads/2020/11/04/word-1.jpg)
```plain text
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true
```
**Example 3:**
![word3.jpg](https://assets.leetcode.com/uploads/2020/10/15/word3.jpg)
```plain text
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false
```
**Constraints:**
- `m == board.length`
- `n = board[i].length`
- `1 <= m, n <= 6`
- `1 <= word.length <= 15`
- `board` and `word` consists of only lowercase and uppercase English letters.
**Follow up:** Could you use search pruning to make your solution faster with a larger `board`?
### My Solutions
___
```python
class Solution:
    
    def __init__(self):
        self.visited = set()
        
    def neighbors(self, board, r, c):
        directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        
        for dr, dc in directions:
            nr = r + dr
            nc = c + dc
            if 0 <= nr < len(board) and 0 <= nc < len(board[0]) and (nr, nc) not in self.visited:
                yield (nr, nc)
                
    def dfs(self, board, r, c, word, idx):
        
        found = False
        
        if word[idx] != board[r][c]:
            return False
        
        if idx == len(word) - 1:
            return True
        
        self.visited.add((r, c))
        
        for nr, nc in self.neighbors(board, r, c):
            found = self.dfs(board, nr, nc, word, idx + 1)
            if found:
                return True
        
        self.visited.remove((r, c))
        
        return found
    
    def exist(self, board: List[List[str]], word: str) -> bool:
        for r in range(len(board)):
            for c in range(len(board[0])):
                if board[r][c] == word[0]:
                    found = self.dfs(board, r, c, word, 0)
                    if found:
                        return True
        
        return False
        
```

Time Complexity :
```python

```

Time Complexity : 
### Optimal Solutions
___
To solve **LeetCode Problem 79: Word Search**, the most optimal approach is to use **backtracking with depth-first search (DFS)**. Below is a detailed explanation of the algorithm along with its time and space complexities.
___
#### **Algorithm: Backtracking with DFS**
**Algorithm Steps:**
1. **Iterate Over Each Cell:**
	- Loop through each cell in the grid.
	- If the character in the cell matches the first character of the `word`, initiate a DFS from that cell.
2. **Depth-First Search Function:**
	- The DFS function checks if the current cell `(i, j)` can lead to a valid path that matches the `word` starting from index `k`.
	- **Base Case:**
		- If `k` equals the length of the `word`, return `True` (the entire word has been found).
	- **Boundary and Validity Checks:**
		- Ensure the current cell is within the grid boundaries.
		- Check if the character in the current cell matches `word[k]`.
		- Check that the cell hasn't been visited in the current path (to avoid cycles).
	- **Mark as Visited:**
		- Temporarily mark the current cell as visited (e.g., by replacing it with a special character like `'#'`).
	- **Explore Adjacent Cells:**
		- Recursively call DFS for adjacent cells (up, down, left, right).
	- **Backtrack:**
		- Restore the original character in the cell after exploring all paths from it.
3. **Return the Result:**
	- If any DFS call returns `True`, the word exists in the grid.
	- If no valid path is found after exploring all starting cells, return `False`.
**Code Example:**
```python
class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        if not board:
            return False

        rows, cols = len(board), len(board[0])

        def dfs(i, j, k):
            # Base case: all characters matched
            if k == len(word):
                return True
            # Boundary and validity checks
            if i < 0 or i >= rows or j < 0 or j >= cols:
                return False
            if board[i][j] != word[k]:
                return False
            # Mark the current cell as visited
            temp = board[i][j]
            board[i][j] = '#'
            # Explore all possible directions
            found = (dfs(i+1, j, k+1) or
                     dfs(i-1, j, k+1) or
                     dfs(i, j+1, k+1) or
                     dfs(i, j-1, k+1))
            # Backtrack by restoring the original value
            board[i][j] = temp
            return found

        for i in range(rows):
            for j in range(cols):
                # Start DFS if the first character matches
                if board[i][j] == word[0]:
                    if dfs(i, j, 0):
                        return True
        return False

```
**Time Complexity:** O(M \* N \* 3<sup>L</sup>)
- **Explanation:**
	- *M \ N*: We may start from every cell in the grid.
	- **3<sup>L</sup>**: At each step, we have up to 3 choices (excluding the cell we came from).
	- **L**: Length of the `word`.
- Although the time complexity is exponential with respect to the length of the word, the small constraints (board size up to 6x6 and word length up to 15) make it acceptable.
**Space Complexity:** O(L)
- **Explanation:**
	- The maximum depth of the recursion stack is equal to the length of the `word`.
	- Additional space is used for the recursion stack and for marking cells as visited.
___
#### **Alternative Approach: Optimized Backtracking with Pruning**
While the standard backtracking approach is optimal for this problem, you can introduce optimizations to prune unnecessary paths:
4. **Early Termination with Character Count:**
	- Before starting the DFS, compare the frequency of each character in the `word` with those in the `board`.
	- If the `board` lacks sufficient occurrences of any character, return `False` immediately.
5. **Order of Exploration:**
	- Start DFS from cells where the character matches and where the subsequent characters are more likely to be found (e.g., cells with higher connectivity).
**However**, these optimizations might not lead to significant improvements given the small input size and could add unnecessary complexity.
___
#### **Summary**
- The **backtracking with DFS** approach is the most efficient and straightforward solution for the Word Search problem.
- It systematically explores all possible paths, backtracking when a path does not lead to a solution.
- The algorithm operates within acceptable time and space constraints due to the problem's limitations.
___
**Note:** The trie-based optimization is more suitable for problems where multiple words need to be searched simultaneously (e.g., Word Search II). For a single word, the backtracking DFS method remains the optimal choice.
### Notes
___
 
### Related Videos 
___
[pfiQ_PS1g8E](https://youtu.be/pfiQ_PS1g8E)