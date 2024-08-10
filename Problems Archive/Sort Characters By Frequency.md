# Sort Characters By Frequency

Problem: 451
Official Difficulty: medium
Feels Like : medium
My Understanding: Mostly Understand
Topic: Counting, Heap(Priority Queue), bucket sort, hash table, sorting, string
Link: https://leetcode.com/problems/sort-characters-by-frequency/description/
Completed On : July 23, 2024
Last Review: July 23, 2024
Days Since Review: 17

## Problem

---

Given a string `s`, sort it in **decreasing order** based on the **frequency** of the characters. The **frequency** of a character is the number of times it appears in the string.

Return *the sorted string*. If there are multiple answers, return *any of them*.

**Example 1:**

```
Input: s = "tree"
Output: "eert"
Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
```

**Example 2:**

```
Input: s = "cccaaa"
Output: "aaaccc"
Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
Note that "cacaca" is incorrect, as the same characters must be together.
```

**Example 3:**

```
Input: s = "Aabb"
Output: "bbAa"
Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.

```

**Constraints:**

- `1 <= s.length <= 5 * 105`
- `s` consists of uppercase and lowercase English letters and digits.

## My Solutions

---

```python
class Solution:
    def frequencySort(self, s: str) -> str:

        counts = Counter(s)
        flipped = sorted(s,reverse = True, key = lambda x : (counts[x],x))

        return ''.join(flipped)
        
```

```python

```

## Optimal Solutions

---

```python
from collections import Counter
import heapq

class Solution:
    def frequencySort(self, s: str) -> str:
        # Count the frequency of each character
        freq = Counter(s)

        # Create a max heap based on the frequencies
        max_heap = [(-count, char) for char, count in freq.items()]
        heapq.heapify(max_heap)

        # Build the result string
        result = []
        while max_heap:
            count, char = heapq.heappop(max_heap)
            result.append(char * (-count))  # Multiply the character by its frequency

        return ''.join(result)

# Example usage
sol = Solution()
print(sol.frequencySort("tree"))  # Output: "eert"
print(sol.frequencySort("cccaaa"))  # Output: "aaaccc"
print(sol.frequencySort("Aabb"))  # Output: "bbAa"

```

### Explanation

1. **Count Frequencies**:
    - Use `Counter` from the `collections` module to count the frequency of each character in the string `s`.
    - `freq = Counter(s)` creates a dictionary-like object where the keys are characters and the values are their respective counts.
2. **Create a Max Heap**:
    - We need a max heap to get the character with the highest frequency first. However, Python's `heapq` module only supports min heaps. To simulate a max heap, we store negative frequencies.
    - `[(-count, char) for char, count in freq.items()]` creates a list of tuples with negative counts.
    - `heapq.heapify(max_heap)` transforms the list into a heap.
3. **Build the Result String**:
    - Initialize an empty list `result`.
    - While the heap is not empty, repeatedly pop the element with the highest frequency (i.e., the smallest negative count).
    - `char * (-count)` repeats the character `char` `count` times.
    - Append the repeated character to the `result` list.
4. **Join the Result**:
    - Use `''.join(result)` to concatenate the list into a single string and return it.

### Time Complexity Analysis

- **Time Complexity**: `O(n log n)`
    - Counting frequencies takes `O(n)` time.
    - Creating and heapifying the list takes `O(n log n)` time.
    - Building the result string involves `O(n log n)` operations due to heap operations.
- **Space Complexity**: `O(n)`
    - Storing the frequency count and the result string requires `O(n)` space.

This solution efficiently sorts the characters by frequency using a heap, ensuring optimal performance for large strings.

## Notes

---

 

## Related Videos

---

[https://www.notion.so](https://www.notion.so)