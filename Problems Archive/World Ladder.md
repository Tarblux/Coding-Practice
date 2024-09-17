# World Ladder

Problem: 127
Official Difficulty: hard
Feels Like : medium
My Understanding: Fully Understand
Topic: Breadth-First Search(BFS), hash table, string
Link: https://leetcode.com/problems/word-ladder/description/
Completed On : September 8, 2024
Last Review: September 8, 2024
Days Since Review: 8

## Problem

---

A **transformation sequence** from word `beginWord` to word `endWord` using a dictionary `wordList` is a sequence of words `beginWord -> s1 -> s2 -> ... -> sk` such that:

- Every adjacent pair of words differs by a single letter.
- Every `si` for `1 <= i <= k` is in `wordList`. Note that `beginWord` does not need to be in `wordList`.
- `sk == endWord`

Given two words, `beginWord` and `endWord`, and a dictionary `wordList`, return *the **number of words** in the **shortest transformation sequence** from* `beginWord` *to* `endWord`*, or* `0` *if no such sequence exists.*

**Example 1:**

```
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.
```

**Example 2:**

```
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: 0
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
```

**Constraints:**

- `1 <= beginWord.length <= 10`
- `endWord.length == beginWord.length`
- `1 <= wordList.length <= 5000`
- `wordList[i].length == beginWord.length`
- `beginWord`, `endWord`, and `wordList[i]` consist of lowercase English letters.
- `beginWord != endWord`
- All the words in `wordList` are **unique**.

## My Solutions

---

```python
class Solution:

    def __init__(self):
        self.visited = set()

    def neighbors(self,word:str,wordList:Set[str],depth:int)-> Generator[Tuple[str,int],None,None]:

        for i in range(len(word)):
            for j in range(97,123):
                neighbor = word[:i] + chr(j) + word[i+1:]
                if neighbor in wordList:
                    yield (neighbor , depth+1)

    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:

        wordList = set(wordList)
        self.visited.add((beginWord))
        queue = deque([(beginWord,1)])

        while queue:

            cur_word,cur_depth = queue.popleft()

            if cur_word == endWord:
                return cur_depth

            for word , depth in self.neighbors(cur_word,wordList,cur_depth):
                if word not in self.visited:
                    self.visited.add(word)
                    queue.append((word,depth))

        return 0      
```

```python

```

## Optimal Solutions

---

To solve the "Word Ladder" problem (LeetCode problem 127), the goal is to find the length of the shortest transformation sequence from the `beginWord` to the `endWord`, where:

- Each transformed word must exist in the `wordList`.
- Only one letter can be changed at a time.
- The transformation process must lead to the `endWord`.

### Approach

This problem can be treated as a **graph traversal** problem, where each word is a node, and an edge exists between two nodes if they differ by exactly one character. The task is to find the shortest path from the `beginWord` to the `endWord`. **Breadth-First Search (BFS)** is an ideal approach here since it explores all nodes level by level and guarantees the shortest path in an unweighted graph.

### Steps

1. **Create the Graph**:
    - Instead of creating the entire graph explicitly, we can dynamically generate neighbors (words that differ by one character) during the BFS process.
2. **Breadth-First Search (BFS)**:
    - Use BFS to explore all possible word transformations level by level, starting from `beginWord`.
    - If `endWord` is reached, return the current transformation length.
    - Keep track of visited words to avoid cycles and redundant processing.
3. **Generate Neighbors**:
    - For each word, change each letter to every possible letter from 'a' to 'z' and check if the resulting word exists in the `wordList`. These are the possible neighbors of the word.
4. **Early Exit**:
    - If `endWord` is not in the `wordList`, return `0` immediately since the transformation is impossible.

### Python Implementation

```python
from collections import deque
from typing import List

class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        word_set = set(wordList)  # Convert wordList to a set for O(1) lookups

        if endWord not in word_set:
            return 0  # If endWord is not in the word list, return 0

        # Step 1: Initialize the queue for BFS
        queue = deque([(beginWord, 1)])  # (current word, current transformation length)
        visited = set()  # To avoid revisiting the same word

        # Step 2: Start BFS
        while queue:
            current_word, length = queue.popleft()

            if current_word == endWord:
                return length  # We have reached the end word, return the transformation length

            # Step 3: Generate all possible one-letter transformations (neighbors)
            for i in range(len(current_word)):
                for char in 'abcdefghijklmnopqrstuvwxyz':
                    next_word = current_word[:i] + char + current_word[i+1:]

                    if next_word in word_set and next_word not in visited:
                        visited.add(next_word)
                        queue.append((next_word, length + 1))

        return 0  # If we exhaust the BFS and never reach endWord, return 0

# Example usage
sol = Solution()
beginWord = "hit"
endWord = "cog"
wordList = ["hot", "dot", "dog", "lot", "log", "cog"]
print(sol.ladderLength(beginWord, endWord, wordList))  # Output: 5

```

### Explanation:

1. **Initialization**:
    - Convert the `wordList` into a `set` for fast lookups, as checking membership in a set is O(1).
    - If `endWord` is not in the `wordList`, we return `0` immediately since the transformation is impossible.
2. **Breadth-First Search (BFS)**:
    - We initialize a queue for BFS, starting with the `beginWord` and an initial transformation length of `1`.
    - For each word, we generate all possible neighbors by changing each character one at a time.
    - If a valid neighbor exists in the `wordList` and hasn't been visited, we add it to the queue with an incremented transformation length.
3. **Generating Neighbors**:
    - For each position in the current word, we try replacing it with every letter from 'a' to 'z'. If the resulting word exists in the word set, it's a valid transformation.
4. **Termination**:
    - If during the BFS we reach the `endWord`, we return the current transformation length.
    - If the queue is exhausted without finding the `endWord`, we return `0`.

### Complexity Analysis:

- **Time Complexity**: `O(M * N)`, where:
    - `M` is the length of each word.
    - `N` is the total number of words in the `wordList`.
    - For each word, we generate `M * 26` possible transformations, and we do this for each word in the `wordList`.
- **Space Complexity**: `O(M * N)`, for storing the `wordList` and the BFS queue, where each word is of length `M` and we might store up to `N` words in the queue.

This approach efficiently finds the shortest transformation sequence using BFS while ensuring that only valid transformations are considered.

## Notes

---

 

## Related Videos

---

[https://youtu.be/h9iTnkgv05E](https://youtu.be/h9iTnkgv05E)