# Uncommon Words from Two Sentences

Problem: 884
Official Difficulty: easy
Feels Like : medium
My Understanding: Fully Understand
Topic: Counting, hash table, string
Link: https://leetcode.com/problems/uncommon-words-from-two-sentences/description/?envType=daily-question&envId=2024-09-17
Completed On : September 16, 2024
Last Review: September 16, 2024
Days Since Review: 0

## Problem

---

A **sentence** is a string of single-space separated words where each word consists only of lowercase letters.

A word is **uncommon** if it appears exactly once in one of the sentences, and **does not appear** in the other sentence.

Given two **sentences** `s1` and `s2`, return *a list of all the **uncommon words***. You may return the answer in **any order**.

**Example 1:**

**Input:** s1 = "this apple is sweet", s2 = "this apple is sour"

**Output:** ["sweet","sour"]

**Explanation:**

The word `"sweet"` appears only in `s1`, while the word `"sour"` appears only in `s2`.

**Example 2:**

**Input:** s1 = "apple apple", s2 = "banana"

**Output:** ["banana"]

**Constraints:**

- `1 <= s1.length, s2.length <= 200`
- `s1` and `s2` consist of lowercase English letters and spaces.
- `s1` and `s2` do not have leading or trailing spaces.
- All the words in `s1` and `s2` are separated by a single space.

## My Solutions

---

```python
class Solution:
    def uncommonFromSentences(self, s1: str, s2: str) -> List[str]:

        duplicates = set()

        sen1 = Counter(s1.split())
        for w in s1.split():
           if sen1[w] > 1:
                duplicates.add(w)

        sen2 = Counter(s2.split())
        for w in s2.split():
           if sen2[w] > 1:
                duplicates.add(w)

        s1 = set(s1.split())
        s2 = set(s2.split())
        
        sym_diff = s1 ^ s2

        return sym_diff - duplicates
```

Here's an improved version of your original implementation while still keeping the set-based approach:

### Improvements:

1. **Combine split operations**: Avoid splitting the same sentences multiple times.
2. **Use `Counter` efficiently**: Use `Counter` to directly find the duplicates.
3. **Use set operations directly** to filter uncommon words.

```python
from collections import Counter
from typing import List

class Solution:
    def uncommonFromSentences(self, s1: str, s2: str) -> List[str]:
        # Split sentences and count occurrences
        sen1_words = s1.split()
        sen2_words = s2.split()

        # Count word frequencies in both sentences
        sen1 = Counter(s1_words)
        sen2 = Counter(sen2_words)

        # Create a set of duplicates (words appearing more than once in either sentence)
        duplicates = {w for w in sen1 if sen1[w] > 1}.union({w for w in sen2 if sen2[w] > 1})

        # Create sets for unique words in both sentences
        s1_set = set(sen1_words)
        s2_set = set(sen2_words)

        # Find symmetric difference and remove duplicates
        sym_diff = s1_set ^ s2_set

        # Return the words that are in the symmetric difference but not duplicates
        return list(sym_diff - duplicates)

```

### Key Points:

1. **Single `split`**: We split `s1` and `s2` only once and store the results in `sen1_words` and `sen2_words`.
2. **Efficient duplicate handling**: We use a set comprehension to gather words that occur more than once in either sentence.
3. **Symmetric difference**: We calculate the symmetric difference (`^`) between the unique words in both sentences and subtract any duplicates.

This keeps your set-based approach while optimizing and simplifying the logic.

## Optimal Solutions

---

To find **uncommon words from two sentences**, the goal is to identify words that appear exactly once in **either** sentence but **not both**.

### Approach:

1. **Tokenize** both sentences into words.
2. **Count occurrences** of each word in both sentences.
3. Return the words that appear exactly **once** across both sentences combined.

### Python Code Implementation:

```python
from collections import Counter

class Solution:
    def uncommonFromSentences(self, s1: str, s2: str) -> List[str]:
        # Step 1: Split both sentences into words
        words1 = s1.split()
        words2 = s2.split()

        # Step 2: Count occurrences of all words from both sentences
        word_count = Counter(words1) + Counter(words2)

        # Step 3: Return words that appear exactly once
        return [word for word, count in word_count.items() if count == 1]

# Example usage:
sol = Solution()
s1 = "apple banana apple"
s2 = "banana orange"
print(sol.uncommonFromSentences(s1, s2))  # Output: ['orange']
```

### Explanation:

1. **Tokenization**:
    - Both sentences are split into words using `split()`. For example, `"apple banana apple"` becomes `['apple', 'banana', 'apple']`.
2. **Count Occurrences**:
    - We use `Counter` from the `collections` module to count how many times each word appears in both sentences. The counts from both sentences are summed together using `+`.
3. **Filter Words**:
    - We return the words that have a count of exactly `1` using a list comprehension.

### Example:

```python
s1 = "apple banana apple"
s2 = "banana orange"
```

- Words from `s1`: `apple` (appears 2 times), `banana` (appears 1 time)
- Words from `s2`: `banana` (appears 1 time), `orange` (appears 1 time)

The `Counter` will give:

```
{'apple': 2, 'banana': 2, 'orange': 1}
```

Only `"orange"` appears exactly once, so the result is `['orange']`.

### Time Complexity:

- **Time Complexity**: `O(n + m)`, where `n` is the number of words in the first sentence, and `m` is the number of words in the second sentence.
- **Space Complexity**: `O(n + m)` for storing the words and their counts.

This solution efficiently identifies uncommon words by leveraging Python’s `Counter` to count word frequencies across both sentences.

## Notes

---

 

## Related Videos

---

[https://youtu.be/0mkXY-goacc](https://youtu.be/0mkXY-goacc)