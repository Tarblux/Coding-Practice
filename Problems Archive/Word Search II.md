# Word Search II

Problem: 212
Official Difficulty: hard
Feels Like : hard
My Understanding: Needs Review
Topic: Matrix, Trie, array, backtracking, string
Link: https://leetcode.com/problems/word-search-ii/description/?envType=problem-list-v2&envId=amidiy65
Completed On : September 21, 2024
Last Review: September 21, 2024
Days Since Review: 12

## Problem

---

Given an `m x n` `board` of characters and a list of strings `words`, return *all words on the board*.

Each word must be constructed from letters of sequentially adjacent cells, where **adjacent cells** are horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

**Example 1:**

![https://assets.leetcode.com/uploads/2020/11/07/search1.jpg](https://assets.leetcode.com/uploads/2020/11/07/search1.jpg)

```
Input: board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words = ["oath","pea","eat","rain"]
Output: ["eat","oath"]
```

**Example 2:**

![https://assets.leetcode.com/uploads/2020/11/07/search2.jpg](https://assets.leetcode.com/uploads/2020/11/07/search2.jpg)

```
Input: board = [["a","b"],["c","d"]], words = ["abcb"]
Output: []
```

**Constraints:**

- `m == board.length`
- `n == board[i].length`
- `1 <= m, n <= 12`
- `board[i][j]` is a lowercase English letter.
- `1 <= words.length <= 3 * 104`
- `1 <= words[i].length <= 10`
- `words[i]` consists of lowercase English letters.
- All the strings of `words` are unique.

## My Solutions

---

```python
class TrieNode:

    def __init__(self):
        self.children = {}
        self.eow = False

class Trie:

    def __init__(self):
        self.root = TrieNode()
    
    def addWord(self,word):

        node = self.root 

        for char in word:
            if char not in node.children:
                node.children[char] = TrieNode()
            node = node.children[char]

        node.eow = True

    def search(self,word):

        node = self.root

        for char in word:
            if char not in node.children:
                return False
            node = node.children[char]

        return node.eow == True

class Solution:

    def neighbors(self,board,r,c,visited):

        directions = [(0,-1),(0,1),(-1,0),(1,0)]

        for dr , dc in directions:
            nr = r + dr
            nc = c + dc
            if (0 <= nr < len(board) and 0 <= nc < len(board[0]) and (nr,nc) not in visited):
                yield (nr,nc)

    def dfs(self,board,r,c,node,path,visited,output):

        if node.eow:
            output.add(path)

        visited.add((r,c))

        for nr,nc in self.neighbors(board,r,c,visited):
            char = board[nr][nc]
            if char in node.children:
                self.dfs(board,nr,nc,node.children[char],path + char , visited , output)

        visited.remove((r,c))

    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:

        trie = Trie()
        for word in words:
            trie.addWord(word)

        output = set()
        
        for r in range(len(board)):
            for c in range(len(board[0])):
                char = board[r][c]
                if char in trie.root.children:
                    self.dfs(board,r,c,trie.root.children[char], char, set(), output)

        return list(output)
```

```python

```

## Optimal Solutions

---

The **"Word Search II"** problem requires us to find all words from a given list that are present in a 2D board of characters. Each word must be constructed from letters of sequentially adjacent cells, where "adjacent" cells are horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

### Problem Breakdown:

1. **Input**:
    - A 2D board of characters.
    - A list of words to search for in the board.
2. **Output**:
    - A list of all words found in the board.

### Key Concepts:

1. **Trie (Prefix Tree)**:
    - A Trie is an efficient structure to store the list of words and quickly access prefixes. This helps in reducing unnecessary searches.
2. **Backtracking**:
    - Use DFS and backtracking to explore all possible paths on the board. If a path doesn’t lead to a word in the Trie, backtrack to explore other paths.

### Approach:

1. **Build a Trie**:
    - Insert all the words into a Trie. This will allow us to quickly prune paths that don't lead to any valid word.
2. **DFS with Backtracking**:
    - For each cell in the board, initiate a DFS if the cell matches the beginning of any word in the Trie.
    - Keep track of visited cells to ensure no cell is reused in the same word path.
    - If a valid word is found, add it to the result list.
3. **Optimization**:
    - Use the Trie to quickly terminate searches when no possible words match the current path.
    - Remove words from the Trie once found to prevent redundant searches.

### Python Code Implementation:

```python
from typing import List
from collections import defaultdict

class TrieNode:
    def __init__(self):
        self.children = defaultdict(TrieNode)
        self.word = None  # To store the word ending at this node

class Solution:
    def __init__(self):
        self.result = []

    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        # Step 1: Build the Trie from the list of words
        root = TrieNode()
        for word in words:
            node = root
            for char in word:
                node = node.children[char]
            node.word = word  # Mark the end of the word

        # Step 2: Define the DFS backtracking function
        def dfs(node, i, j):
            char = board[i][j]

            # Check if we reached a node corresponding to a word
            if node.word:
                self.result.append(node.word)
                node.word = None  # Avoid duplicate entries by removing the word

            # Mark the current cell as visited
            board[i][j] = '#'

            # Explore neighbors in 4 directions
            for di, dj in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
                ni, nj = i + di, j + dj
                if 0 <= ni < len(board) and 0 <= nj < len(board[0]) and board[ni][nj] in node.children:
                    dfs(node.children[board[ni][nj]], ni, nj)

            # Restore the original value of the cell for backtracking
            board[i][j] = char

        # Step 3: Start backtracking for each cell in the board
        for i in range(len(board)):
            for j in range(len(board[0])):
                if board[i][j] in root.children:
                    dfs(root.children[board[i][j]], i, j)

        return self.result

```

### Explanation:

1. **Building the Trie**:
    - Insert each word into the Trie. Each character is added as a child node. The `word` attribute at a node indicates the end of a word.
2. **DFS Function** (`dfs`):
    - The `dfs` function is called for each starting cell if the cell's character matches a Trie prefix.
    - The function marks the current cell as visited by setting it to `#`.
    - For each neighboring cell, the function recursively explores further characters if they match the next character in any word in the Trie.
    - If a complete word is found (node has a `word`), it is added to the result and removed from the Trie to avoid duplicate searches.
3. **Backtracking**:
    - After exploring a cell, the original value is restored to allow other paths to use this cell again.
4. **Main Logic**:
    - For each cell in the board, initiate a DFS if the cell matches the start of any word in the Trie.
    - The result is a list of all words found on the board.

### Time Complexity:

1. **Trie Construction**:
    - `O(M)`, where `M` is the total number of characters in all words combined.
2. **Backtracking**:
    - In the worst case, each cell is visited and explored up to 4 directions, giving `O(N * 4^L)`, where `N` is the number of cells in the board and `L` is the length of the longest word.
3. **Overall**:
    - The solution is efficient compared to naive searches because it prunes invalid paths early using the Trie.

### Space Complexity:

1. **Trie Storage**:
    - `O(M)` for storing all characters in the Trie.
2. **Recursion Stack and Result Storage**:
    - The recursion stack can go up to `O(L)` for the longest word, and the result list can be up to `O(W)` for all found words, where `W` is the number of words found.

### Example Usage:

```python
sol = Solution()
board = [
    ['o','a','a','n'],
    ['e','t','a','e'],
    ['i','h','k','r'],
    ['i','f','l','v']
]
words = ["oath","pea","eat","rain"]
print(sol.findWords(board, words))  # Output: ["oath", "eat"]

```

- "oath" and "eat" are found in the board, so they are returned as the result.

### Conclusion:

This solution efficiently uses the Trie structure combined with DFS and backtracking to find all the words from the list that are present in the 2D board, ensuring optimal performance for large inputs.

## Notes

---

 

## Related Videos

---

[https://youtu.be/asbcE9mZz_U](https://youtu.be/asbcE9mZz_U)