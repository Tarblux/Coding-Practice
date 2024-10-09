# Count the Number of Consistent Strings

Problem: 1684
Official Difficulty: easy
Feels Like : easy breazy
My Understanding: Fully Understand
Topic: Bit Manipulation, Counting, array, set, string
Link: https://leetcode.com/problems/count-the-number-of-consistent-strings/description/
Completed On : September 11, 2024
Last Review: September 11, 2024
Days Since Review: 5

## Problem

---

You are given a string `allowed` consisting of **distinct** characters and an array of strings `words`. A string is **consistent** if all characters in the string appear in the string `allowed`.

Return *the number of **consistent** strings in the array* `words`.

**Example 1:**

```
Input: allowed = "ab", words = ["ad","bd","aaab","baa","badab"]
Output: 2
Explanation: Strings "aaab" and "baa" are consistent since they only contain characters 'a' and 'b'.
```

**Example 2:**

```
Input: allowed = "abc", words = ["a","b","c","ab","ac","bc","abc"]
Output: 7
Explanation: All strings are consistent.
```

**Example 3:**

```
Input: allowed = "cad", words = ["cc","acd","b","ba","bac","bad","ac","d"]
Output: 4
Explanation: Strings "cc", "acd", "ac", and "d" are consistent.
```

**Constraints:**

- `1 <= words.length <= 104`
- `1 <= allowed.length <= 26`
- `1 <= words[i].length <= 10`
- The characters in `allowed` are **distinct**.
- `words[i]` and `allowed` contain only lowercase English letters.

## My Solutions

---

```python
class Solution:
    def countConsistentStrings(self, allowed: str, words: List[str]) -> int:

        sub = set(allowed)
        output = 0

        for word in words:
            if sub >= set(word):
                output += 1

        return output
        
```

```python

```

## Optimal Solutions

---

To solve the "Count the Number of Consistent Strings" problem, we are given two inputs:

1. **`allowed`**: A string consisting of unique characters that are allowed in the consistent strings.
2. **`words`**: A list of words.

A word is considered **consistent** if every character in the word is also in the `allowed` string. The task is to count how many strings in the `words` list are consistent.

### Approach:

1. **Convert `allowed` to a Set**:
    - Since checking membership in a set is `O(1)`, converting the `allowed` string to a set allows us to efficiently check if each character in a word is allowed.
2. **Iterate Over Each Word**:
    - For each word, check if all of its characters are in the `allowed` set.
    - If all characters of the word are in the `allowed` set, increment the count of consistent words.
3. **Return the Count**:
    - After processing all words, return the total number of consistent words.

### Python Code Implementation:

```python
from typing import List

class Solution:
    def countConsistentStrings(self, allowed: str, words: List[str]) -> int:
        # Step 1: Convert the allowed string to a set for O(1) lookups
        allowed_set = set(allowed)

        # Step 2: Count how many words are consistent
        consistent_count = 0

        for word in words:
            if all(char in allowed_set for char in word):
                consistent_count += 1

        return consistent_count

# Example usage:
sol = Solution()
allowed = "ab"
words = ["ad","bd","aaab","baa","badab"]
print(sol.countConsistentStrings(allowed, words))  # Output: 2

allowed = "abc"
words = ["a","b","c","ab","ac","bc","abc"]
print(sol.countConsistentStrings(allowed, words))  # Output: 7

```

### Explanation:

1. **Convert `allowed` to a Set**:
    - We convert the `allowed` string to a set called `allowed_set` so that checking if a character is in the `allowed` set can be done in constant time.
2. **Iterate Over Each Word**:
    - For each word in `words`, we check if **all** characters in the word are in the `allowed_set`. This is done using the `all()` function, which returns `True` if all characters meet the condition.
    - If the word is consistent (all its characters are allowed), we increment the count `consistent_count`.
3. **Return the Count**:
    - After processing all the words, we return `consistent_count`, which is the total number of consistent strings.

### Time Complexity:

- **Time Complexity**: `O(n * m)`, where:
    - `n` is the number of words in the `words` list.
    - `m` is the average length of the words. For each word, we check each character in constant time due to the set lookup.
- **Space Complexity**: `O(k)`, where `k` is the number of characters in the `allowed` string, as we are storing the characters in a set.

This solution efficiently counts how many strings in the `words` list are consistent with the `allowed` string.

## Notes

---

 

## Related Videos

---

[https://www.notion.so](https://www.notion.so)