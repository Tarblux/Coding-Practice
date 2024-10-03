# Sum of Prefix Scores of Strings

Problem: 2416
Official Difficulty: hard
Feels Like : medium
My Understanding: Fully Understand
Topic: Counting, Trie, array, string
Link: https://leetcode.com/problems/sum-of-prefix-scores-of-strings/description/
Completed On : September 24, 2024
Last Review: September 24, 2024
Days Since Review: 9

## Problem

---

You are given an array `words` of size `n` consisting of **non-empty** strings.

We define the **score** of a string `word` as the **number** of strings `words[i]` such that `word` is a **prefix** of `words[i]`.

- For example, if `words = ["a", "ab", "abc", "cab"]`, then the score of `"ab"` is `2`, since `"ab"` is a prefix of both `"ab"` and `"abc"`.

Return *an array* `answer` *of size* `n` *where* `answer[i]` *is the **sum** of scores of every **non-empty** prefix of* `words[i]`.

**Note** that a string is considered as a prefix of itself.

**Example 1:**

```
Input: words = ["abc","ab","bc","b"]
Output: [5,4,3,2]
Explanation: The answer for each string is the following:
- "abc" has 3 prefixes: "a", "ab", and "abc".
- There are 2 strings with the prefix "a", 2 strings with the prefix "ab", and 1 string with the prefix "abc".
The total is answer[0] = 2 + 2 + 1 = 5.
- "ab" has 2 prefixes: "a" and "ab".
- There are 2 strings with the prefix "a", and 2 strings with the prefix "ab".
The total is answer[1] = 2 + 2 = 4.
- "bc" has 2 prefixes: "b" and "bc".
- There are 2 strings with the prefix "b", and 1 string with the prefix "bc".
The total is answer[2] = 2 + 1 = 3.
- "b" has 1 prefix: "b".
- There are 2 strings with the prefix "b".
The total is answer[3] = 2.

```

**Example 2:**

```
Input: words = ["abcd"]
Output: [4]
Explanation:
"abcd" has 4 prefixes: "a", "ab", "abc", and "abcd".
Each prefix has a score of one, so the total is answer[0] = 1 + 1 + 1 + 1 = 4.

```

**Constraints:**

- `1 <= words.length <= 1000`
- `1 <= words[i].length <= 1000`
- `words[i]` consists of lowercase English letters.

## My Solutions

---

```python
class TrieNode:
    def __init__(self):
        self.children = {}
        self.hits = 0

class Trie:

    def __init__(self):
        self.root = TrieNode()

    def addWord(self,word:str) -> None:

        node = self.root

        for char in word:
            if char not in node.children:
                node.children[char] = TrieNode()
                node.children[char].hits = 1
            else:
                node.children[char].hits += 1
            node = node.children[char]

    def getSum(self,word:str) -> int:

        node = self.root
        total = 0

        for char in word:
            if char not in node.children:
                return total
            total += node.children[char].hits
            node = node.children[char]

        return total

class Solution:
    def sumPrefixScores(self, words: List[str]) -> List[int]:

        trie = Trie()
        output = [0]*len(words)

        for word in words:
            trie.addWord(word)

        for i in range(len(words)):
            output[i] += trie.getSum(words[i])

        return output
```

```python

```

## Optimal Solutions

---

The **"Sum of Prefix Scores of Strings"** problem asks us to calculate a score for each string in a given list. The score of a string is defined as the sum of the number of times each of its prefixes appears as a prefix in the list of strings. We need to compute the prefix score for each string and return these scores.

### Problem Breakdown:

1. **Prefix**:
    - A prefix of a string is a substring that starts from the beginning of the string.
    - For example, the prefixes of "abc" are "a", "ab", and "abc".
2. **Score of a String**:
    - The score of a string is the sum of counts of all its prefixes appearing in other strings.
    - For example, if we have the string "abc" and another string "abx", the prefixes "a" and "ab" are shared, contributing to the score.
3. **Goal**:
    - Calculate the prefix score for each string in the list and return these scores in the same order.

### Approach:

To efficiently solve this problem, we can use a **Trie (Prefix Tree)** data structure. The Trie allows us to efficiently count occurrences of prefixes for all strings in the list.

1. **Build a Trie**:
    - Insert each string into a Trie.
    - Keep track of the number of times each prefix is encountered using a counter at each node.
2. **Calculate Scores Using the Trie**:
    - For each string, traverse the Trie and sum up the counts for all its prefixes to calculate its score.
3. **Efficient Prefix Counting**:
    - While inserting each string into the Trie, increment the count for each node to represent how many times the prefix ending at that node has been seen.

### Python Implementation:

```python
from collections import defaultdict

class TrieNode:
    def __init__(self):
        self.children = defaultdict(TrieNode)
        self.count = 0  # Count how many times this prefix has been inserted

class Solution:
    def sumPrefixScores(self, words):
        # Build the Trie
        root = TrieNode()
        for word in words:
            node = root
            for char in word:
                node = node.children[char]
                node.count += 1  # Increment the count of this prefix

        # Calculate the score for each word
        result = []
        for word in words:
            node = root
            score = 0
            for char in word:
                node = node.children[char]
                score += node.count  # Add the count of this prefix to the score
            result.append(score)

        return result

# Example usage
sol = Solution()
words = ["abc", "ab", "bc", "b"]
print(sol.sumPrefixScores(words))  # Output: [5, 4, 3, 2]

```

### Explanation:

1. **TrieNode Class**:
    - `children`: A dictionary mapping each character to its child node.
    - `count`: Keeps track of how many times this prefix has been seen while inserting words.
2. **Building the Trie**:
    - For each word in the `words` list, traverse the Trie from the root node.
    - For each character in the word, move to the child node. If it doesn’t exist, create it.
    - Increment the `count` at each node to indicate that this prefix has been encountered.
3. **Calculating Scores**:
    - For each word, traverse the Trie again.
    - For each character in the word, add the `count` at the current node to the score.
    - Append the final score for the word to the result list.
4. **Result**:
    - The `result` list contains the prefix scores of all the words in the input list.

### Complexity Analysis:

1. **Time Complexity**:
    - **Building the Trie**: `O(n * m)`, where `n` is the number of words and `m` is the average length of the words. Each character of each word is processed once.
    - **Calculating Scores**: `O(n * m)`, as each word is traversed again to calculate its score.
    - Overall time complexity is `O(n * m)`.
2. **Space Complexity**:
    - The space complexity is also `O(n * m)` for storing the Trie structure, where each node represents a unique prefix of a word in the list.

### Example Walkthrough:

1. **For the input `["abc", "ab", "bc", "b"]`**:
    - Build the Trie:
        - "abc" increments counts for "a", "ab", "abc".
        - "ab" increments counts for "a", "ab".
        - "bc" increments counts for "b", "bc".
        - "b" increments count for "b".
    - Calculate Scores:
        - "abc": Score is 3 (for "a") + 2 (for "ab") + 1 (for "abc") = 6.
        - "ab": Score is 3 (for "a") + 2 (for "ab") = 5.
        - "bc": Score is 2 (for "b") + 1 (for "bc") = 3.
        - "b": Score is 2 (for "b") = 2.

This method efficiently calculates the prefix scores for each word using the Trie structure, providing an optimized solution for the problem.

## Notes

---

 

## Related Videos

---

[https://www.youtube.com/watch?v=F-5cmvhLw90](https://www.youtube.com/watch?v=F-5cmvhLw90)