# Alien Dictionary

Problem: 269
Official Difficulty: hard
Feels Like : Brain Damage
My Understanding: I Have No Idea
Topic: Breadth-First Search(BFS), Depth-First Search (DFS), Topological Sort, array, graph, string
Link: https://leetcode.com/problems/alien-dictionary/description/?envType=problem-list-v2&envId=m3a0vf7e
Completed On : September 17, 2024
Last Review: September 17, 2024
Days Since Review: 6

## Problem

---

There is a new alien language that uses the English alphabet. However, the order of the letters is unknown to you.

You are given a list of strings `words` from the alien language's dictionary. Now it is claimed that the strings in `words` are

**sorted lexicographically**

by the rules of this new language.

If this claim is incorrect, and the given arrangement of string in `words` cannot correspond to any order of letters, return `"".`

Otherwise, return *a string of the unique letters in the new alien language sorted in **lexicographically increasing order** by the new language's rules.* If there are multiple solutions, return ***any of them***.

**Example 1:**

```
Input: words = ["wrt","wrf","er","ett","rftt"]
Output: "wertf"
```

**Example 2:**

```
Input: words = ["z","x"]
Output: "zx"
```

**Example 3:**

```
Input: words = ["z","x","z"]
Output: ""
Explanation: The order is invalid, so return"".
```

**Constraints:**

- `1 <= words.length <= 100`
- `1 <= words[i].length <= 100`
- `words[i]` consists of only lowercase English letters.

## My Solutions

---

```python
class Solution:
    def alienOrder(self, words: List[str]) -> str:

        graph = {c:set() for w in words for c in w}

        for i in range(len(words)-1):
            w1,w2 = words[i] , words[i+1]
            min_length = min(len(w1),len(w2))

            if len(w1) > len(w2) and w1[:min_length] == w2[:min_length]:
                return ''

            for j in range(min_length):

                if w1[j] != w2[j]:
                    graph[w1[j]].add(w2[j])
                    break

        visit = {}
        output = []

        def dfs(c):

            if c in visit:
                return visit[c]

            visit[c] = True

            for nei in graph[c]:
                if dfs(nei):
                    return True

            visit[c] = False
            output.append(c)

        for c in graph:
            if dfs(c):
                return ''

        output = output[::-1]

        return ''.join(output)  
        
```

```python

```

## Optimal Solutions

---

The **Alien Dictionary** problem involves determining the correct order of letters in an alien language based on a sorted list of words. The order of letters in the alien language may be different from the order in the English alphabet, and we need to deduce this order.

### Problem Breakdown:

1. You are given a sorted list of words according to the alien language.
2. You need to derive the correct order of letters in this alien language.
3. If no valid order exists (due to a cycle in the ordering), return an empty string.

### Key Concepts:

This is essentially a **topological sorting** problem, where:

- Each letter is treated as a node.
- A directed edge from node `u` to node `v` means that `u` comes before `v` in the alien alphabet.
- The goal is to find a topological ordering of nodes (letters).

### Approach:

1. **Build the Graph**:
    - For each pair of consecutive words in the list, determine the first different character. This gives a constraint on the relative order of two letters.
    - Build a graph where each letter is a node, and an edge from `u` to `v` means `u` comes before `v` in the alien language.
2. **Topological Sorting**:
    - Once the graph is built, perform a topological sort using **Kahn's algorithm** (BFS) or **DFS** to determine the correct order of the letters.
    - If there's a cycle in the graph (i.e., conflicting constraints), return an empty string.

### Steps:

1. **Graph Construction**:
    - Build a graph where each node represents a letter.
    - For each pair of consecutive words, compare them letter by letter. The first differing letter defines the order of those two letters.
    - Use an **indegree** array to keep track of the number of edges pointing to each node (letter).
2. **Topological Sorting**:
    - Use Kahn's Algorithm (BFS) to perform the topological sorting:
        - Start with nodes (letters) that have no incoming edges (indegree = 0).
        - Process each node, adding it to the result, and reduce the indegree of its neighbors.
        - If at the end there are still letters left to process, this indicates a cycle.

### Python Code Implementation:

```python
from collections import defaultdict, deque

class Solution:
    def alienOrder(self, words):
        # Step 1: Build the graph
        graph = defaultdict(set)
        indegree = {char: 0 for word in words for char in word}  # initialize all chars with 0 indegree

        # Step 2: Find all edges by comparing adjacent words
        for i in range(len(words) - 1):
            word1, word2 = words[i], words[i + 1]
            min_len = min(len(word1), len(word2))

            # Check for invalid order like ["abc", "ab"]
            if len(word1) > len(word2) and word1[:min_len] == word2[:min_len]:
                return ""

            for j in range(min_len):
                if word1[j] != word2[j]:
                    if word2[j] not in graph[word1[j]]:
                        graph[word1[j]].add(word2[j])
                        indegree[word2[j]] += 1
                    break

        # Step 3: Topological Sort using BFS (Kahn's Algorithm)
        # Queue for nodes with 0 indegree
        queue = deque([char for char in indegree if indegree[char] == 0])
        result = []

        while queue:
            char = queue.popleft()
            result.append(char)

            # Reduce the indegree of all neighbors
            for neighbor in graph[char]:
                indegree[neighbor] -= 1
                if indegree[neighbor] == 0:
                    queue.append(neighbor)

        # If we processed all the characters, return the result
        if len(result) == len(indegree):
            return ''.join(result)
        else:
            return ""  # Cycle detected, invalid input

```

### Explanation:

1. **Graph Construction**:
    - We initialize a graph using a defaultdict, where each node is a letter, and the edges define the relative order between letters.
    - We also create an `indegree` dictionary to track how many edges point to each letter.
2. **Edge Creation**:
    - We iterate through pairs of consecutive words and compare them character by character. The first different character in two words defines the order of those two characters. This gives us a directed edge from the first character to the second.
    - If we encounter an invalid case, such as when one word is a prefix of another (like `["abc", "ab"]`), we immediately return an empty string.
3. **Topological Sorting**:
    - We use **Kahn's Algorithm** (BFS):
        - Start with all nodes (letters) that have zero indegree.
        - Process each node, append it to the result, and decrease the indegree of its neighbors.
        - If a neighbor's indegree becomes zero, add it to the queue.
4. **Cycle Detection**:
    - If we can't process all nodes (letters), it means there is a cycle in the graph (a contradiction in the order), and we return an empty string.

### Example:

```python
sol = Solution()

words1 = ["wrt", "wrf", "er", "ett", "rftt"]
print(sol.alienOrder(words1))  # Output: "wertf"

words2 = ["z", "x", "z"]
print(sol.alienOrder(words2))  # Output: "" (cycle detected)

```

### Time Complexity:

- **Time Complexity**: `O(C)`, where `C` is the total number of characters in all words combined. This includes building the graph and performing topological sorting.
- **Space Complexity**: `O(1)` excluding the space used for storing the graph and result, which are bounded by the number of unique letters (at most 26).

### Conclusion:

This solution uses topological sorting to deduce the order of letters in the alien language. If there are cycles or invalid inputs, the function returns an empty string, ensuring that only valid orders are returned.

## Notes

---

 

## Related Videos

---

[https://youtu.be/6kTZYvNNyps](https://youtu.be/6kTZYvNNyps)