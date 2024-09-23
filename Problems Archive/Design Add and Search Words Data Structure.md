# Design Add and Search Words Data Structure

Problem: 211
Official Difficulty: medium
Feels Like : medium
My Understanding: Mostly Understand, Needs Review
Topic: Depth-First Search (DFS), Trie, design, string
Link: https://leetcode.com/problems/design-add-and-search-words-data-structure/description/
Completed On : September 21, 2024
Last Review: September 21, 2024
Days Since Review: 2

## Problem

---

Design a data structure that supports adding new words and finding if a string matches any previously added string.

Implement the `WordDictionary` class:

- `WordDictionary()` Initializes the object.
- `void addWord(word)` Adds `word` to the data structure, it can be matched later.
- `bool search(word)` Returns `true` if there is any string in the data structure that matches `word` or `false` otherwise. `word` may contain dots `'.'` where dots can be matched with any letter.

**Example:**

```
Input
["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
Output
[null,null,null,null,false,true,true,true]

Explanation
WordDictionary wordDictionary = new WordDictionary();
wordDictionary.addWord("bad");
wordDictionary.addWord("dad");
wordDictionary.addWord("mad");
wordDictionary.search("pad"); // return False
wordDictionary.search("bad"); // return True
wordDictionary.search(".ad"); // return True
wordDictionary.search("b.."); // return True
```

**Constraints:**

- `1 <= word.length <= 25`
- `word` in `addWord` consists of lowercase English letters.
- `word` in `search` consist of `'.'` or lowercase English letters.
- There will be at most `2` dots in `word` for `search` queries.
- At most `104` calls will be made to `addWord` and `search`.

## My Solutions

---

```python
class TrieNode:
    def __init__(self):
        self.children = {}
        self.eow = False

class WordDictionary:

    def __init__(self):
        self.root = TrieNode()
        
    def addWord(self, word: str) -> None:

        node = self.root

        for char in  word:
            if char not in node.children:
                node.children[char] = TrieNode()
                node.children['.'] = TrieNode()
            node = node.children[char]

        node.eow = True

    def dfs(self,word,index,node):

        if index == len(word):
            return node.eow

        char = word[index]

        if char == '.':

            for char in node.children.values():
                if self.dfs(word,index + 1,char):
                    return True
            return False
        else:

            if char not in node.children:
                return False
            return self.dfs(word,index + 1,node.children[char])

        
    def search(self, word: str) -> bool:

        return self.dfs(word,0,self.root)
            
# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)
```

```python

```

## Optimal Solutions

---

The **"Add and Search Words Data Structure"** problem asks us to design a data structure that supports adding new words and searching for words, where the search operation can include dot (`.`) characters to represent any one letter. This data structure is often referred to as a **Trie** or **Prefix Tree**.

### Problem Requirements:

1. **addWord(word)**: Adds a word to the data structure.
2. **search(word)**: Returns `True` if there is any string in the data structure that matches the given word, considering `.` can represent any single letter. Otherwise, returns `False`.

### Approach: Trie (Prefix Tree) with Backtracking

A **Trie** is a tree-like data structure that efficiently stores a dynamic set of strings, where each node represents a single character of a string. This structure is well-suited for problems involving prefix matching or word searches.

### Steps to Implement:

1. **Trie Node Structure**:
    - Each node in the Trie will represent a character.
    - Each node will have:
        - A dictionary (`children`) to store child nodes.
        - A boolean flag (`isEnd`) to indicate if the current node represents the end of a word.
2. **Add Word Operation**:
    - Traverse the Trie according to each character in the word.
    - Create new nodes as necessary.
    - Mark the last node as the end of a word.
3. **Search Operation**:
    - If the search word contains a `.`, recursively explore all possible children nodes.
    - If the character is not a `.`, continue the search in the corresponding child node.
    - If we reach the end of the word and the node is marked as `isEnd`, return `True`.

### Python Implementation:

```python
class TrieNode:
    def __init__(self):
        self.children = {}
        self.isEnd = False

class WordDictionary:

    def __init__(self):
        self.root = TrieNode()

    def addWord(self, word: str) -> None:
        node = self.root
        for char in word:
            if char not in node.children:
                node.children[char] = TrieNode()
            node = node.children[char]
        node.isEnd = True

    def search(self, word: str) -> bool:
        # Helper function to search in a TrieNode
        def dfs(j, node):
            for i in range(j, len(word)):
                char = word[i]

                if char == '.':
                    # If the current character is a dot, check all possible children
                    for child in node.children.values():
                        if dfs(i + 1, child):
                            return True
                    return False
                else:
                    # If the character is not a dot and not in the children, return False
                    if char not in node.children:
                        return False
                    node = node.children[char]

            return node.isEnd

        return dfs(0, self.root)

# Example usage:
wd = WordDictionary()
wd.addWord("bad")
wd.addWord("dad")
wd.addWord("mad")
print(wd.search("pad"))  # Output: False (no "pad" in the dictionary)
print(wd.search("bad"))  # Output: True (exact match)
print(wd.search(".ad"))  # Output: True ("bad", "dad", "mad" match)
print(wd.search("b.."))  # Output: True ("bad" matches)

```

### Explanation:

1. **TrieNode Class**:
    - Each `TrieNode` has a dictionary `children` to store references to its child nodes and a boolean `isEnd` to indicate if it marks the end of a word.
2. **WordDictionary Class**:
    - The `addWord` method iteratively adds each character of the word to the Trie, creating new nodes as needed and marking the last node as `isEnd`.
    - The `search` method uses a helper function `dfs` to recursively search the Trie:
        - If the current character is a dot (`.`), it recursively checks all child nodes.
        - If the character is not a dot and exists in the children, it moves to that child node.
        - If it reaches the end of the word and `isEnd` is `True`, the word is found.
3. **Example Usage**:
    - Adding words like "bad", "dad", and "mad".
    - Searching for patterns like "pad" (no match), "bad" (exact match), ".ad" (matches all), and "b.." (matches "bad").

### Complexity Analysis:

1. **Time Complexity**:
    - `addWord`: `O(n)`, where `n` is the length of the word being added.
    - `search`: In the worst case, the search can be `O(m * 26^m)`, where `m` is the length of the word, and `26^m` accounts for the case where all characters are `.`.
2. **Space Complexity**:
    - `O(T)`, where `T` is the total number of characters in all words added to the Trie. Each character uses additional space for storing child nodes.

This implementation efficiently handles word additions and searches, supporting complex pattern matching with the `.` wildcard, and is well-suited for dictionary and word search problems.

## Notes

---

 

## Related Videos

---

[https://youtu.be/BTf05gs_8iU](https://youtu.be/BTf05gs_8iU)