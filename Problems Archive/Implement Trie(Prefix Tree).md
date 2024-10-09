# Implement Trie(Prefix Tree)

Problem: 208
Official Difficulty: medium
Feels Like : easy
My Understanding: Fully Understand
Topic: Trie, design, hash table, string
Link: https://leetcode.com/problems/implement-trie-prefix-tree/description/?envType=problem-list-v2&envId=amidiy65
Completed On : September 19, 2024
Last Review: September 19, 2024
Days Since Review: 4

## Problem

---

A [**trie**](https://en.wikipedia.org/wiki/Trie) (pronounced as "try") or **prefix tree**
 is a tree data structure used to efficiently store and retrieve keys in
 a dataset of strings. There are various applications of this data 
structure, such as autocomplete and spellchecker.

Implement the Trie class:

- `Trie()` Initializes the trie object.
- `void insert(String word)` Inserts the string `word` into the trie.
- `boolean search(String word)` Returns `true` if the string `word` is in the trie (i.e., was inserted before), and `false` otherwise.
- `boolean startsWith(String prefix)` Returns `true` if there is a previously inserted string `word` that has the prefix `prefix`, and `false` otherwise.

**Example 1:**

```
Input
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
Output
[null, null, true, false, true, null, true]

Explanation
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // return True
trie.search("app");     // return False
trie.startsWith("app"); // return True
trie.insert("app");
trie.search("app");     // return True

```

**Constraints:**

- `1 <= word.length, prefix.length <= 2000`
- `word` and `prefix` consist only of lowercase English letters.
- At most `3 * 104` calls **in total** will be made to `insert`, `search`, and `startsWith`.

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
        
    def insert(self, word: str) -> None:

        cur_node = self.root

        for char in word:
            if char in cur_node.children:
                cur_node = cur_node.children[char]
            else:
                cur_node.children[char] = TrieNode()
                cur_node = cur_node.children[char]

        cur_node.eow = True        

    def search(self, word: str) -> bool:

        i = 0
        cur_node = self.root

        while i < len(word):

            if word[i] in cur_node.children:
                cur_node = cur_node.children[word[i]]
                i += 1
            else:
                break

        return i == len(word) and cur_node.eow == True

    def startsWith(self, prefix: str) -> bool:

        i = 0
        cur_node = self.root

        while i < len(prefix):

            if prefix[i] in cur_node.children:
                cur_node = cur_node.children[prefix[i]]
                i += 1
            else:
                break

        return i == len(prefix)

# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)
```

```python

```

## Optimal Solutions

---

## Notes

---

 

## Related Videos

---

[https://youtu.be/oobqoCJlHA0](https://youtu.be/oobqoCJlHA0)