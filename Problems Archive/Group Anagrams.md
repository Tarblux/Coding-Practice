# Group Anagrams

Problem: 49
Official Difficulty: medium
Feels Like : medium
Topic: hash table, string
Link: https://leetcode.com/problems/group-anagrams/
Completed On : December 12, 2023
My Understanding: Mostly Understand
Last Review: December 12, 2023
Days Since Review: 60

## Problem

---

Given an array of strings `strs`, group **the anagrams** together. You can return the answer in **any order**.

An **Anagram** is a word or phrase formed by rearranging
 the letters of a different word or phrase, typically using all the 
original letters exactly once.

**Example 1:**

```
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
```

**Example 2:**

```
Input: strs = [""]
Output: [[""]]
```

**Example 3:**

```
Input: strs = ["a"]
Output: [["a"]]
```

**Constraints:**

- `1 <= strs.length <= 104`
- `0 <= strs[i].length <= 100`
- `strs[i]` consists of lowercase English letters.

## My Solutions

---

```python
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:

        dict = {}

        output = []

        for st in strs :

            cur_str = ''.join(sorted(st))

            if cur_str not in dict :

                dict[cur_str] = [st]

            else : 

                dict[cur_str].append(st)

        for val in dict.values() :

            output.append(val)

        return output
```

```python

```

## Optimal Solutions

---

The "Group Anagrams" problem involves grouping strings from an array such that strings that are anagrams of each other are in the same group. An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

### Solution Approach

A common approach to solve this problem is to use a hash table (dictionary in Python) where each key is a canonical form of a word, and the value is a list of words which are anagrams of this canonical form. The canonical form could be, for example, the word sorted in alphabetical order.

### Python Implementation

Here's a Python implementation of this approach:

```python
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        anagrams = {}

        for word in strs:
            # Sort the word to get its canonical form
            sorted_word = ''.join(sorted(word))

            # Add the word to the correct anagram group
            if sorted_word not in anagrams:
                anagrams[sorted_word] = [word]
            else:
                anagrams[sorted_word].append(word)

        # Return the grouped anagrams
        return list(anagrams.values())

```

### Explanation

- We iterate over each word in the given list.
- We sort each word alphabetically to determine its canonical form. Anagrams will have the same canonical form when sorted.
- We use this sorted word as a key in a dictionary. The value for each key is a list of words (anagrams) that share this sorted form.
- After processing all words, we return the values of the dictionary, which are lists of anagram groups.

### Complexity Analysis

- **Time Complexity**: O(n * k log k), where `n` is the number of strings in the input list and `k` is the maximum length of a string. Sorting each string takes O(k log k) time.
- **Space Complexity**: O(n * k), to store the `anagrams` dictionary. In the worst case, all words are different, and we store each word once in the dictionary.

## Notes

---

 

## Related Videos

---

[https://www.youtube.com/watch?v=vzdNOK2oB2E](https://www.youtube.com/watch?v=vzdNOK2oB2E)