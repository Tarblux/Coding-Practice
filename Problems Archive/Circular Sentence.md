Problem: 2490
Official Difficulty: easy
Link: https://leetcode.com/problems/circular-sentence/description/
Completed On : 2024-11-02
Feels Like : easy breazy
Topic: string
My Understanding: Fully Understand
Last Review: 2024-11-02
Days Since Review: 1
Name: Circular Sentence

# Circular Sentence
### Problem
___
A **sentence** is a list of words that are separated by a** single** space with no leading or trailing spaces.
- For example, `"Hello World"`, `"HELLO"`, `"hello world hello world"` are all sentences.
Words consist of **only** uppercase and lowercase English letters. Uppercase and lowercase English letters are considered different.
A sentence is **circular **if:
- The last character of a word is equal to the first character of the next word.
- The last character of the last word is equal to the first character of the first word.
For example, `"leetcode exercises sound delightful"`, `"eetcode"`, `"leetcode eats soul" `are all circular sentences. However, `"Leetcode is cool"`, `"happy Leetcode"`, `"Leetcode"` and `"I like Leetcode"` are **not** circular sentences.
Given a string `sentence`, return `true`* if it is circular*. Otherwise, return `false`.
**Example 1:**
```plain text
Input: sentence = "leetcode exercises sound delightful"
Output: true
Explanation: The words in sentence are ["leetcode", "exercises", "sound", "delightful"].
- leetcode's last character is equal toexercises's first character.
- exercises's last character is equal tosound's first character.
- sound's last character is equal todelightful's first character.
- delightful's last character is equal toleetcode's first character.
The sentence is circular.
```
**Example 2:**
```plain text
Input: sentence = "eetcode"
Output: true
Explanation: The words in sentence are ["eetcode"].
- eetcode's last character is equal toeetcode's first character.
The sentence is circular.
```
**Example 3:**
```plain text
Input: sentence = "Leetcode is cool"
Output: false
Explanation: The words in sentence are ["Leetcode", "is", "cool"].
- Leetcode's last character isnot equal tois's first character.
The sentence isnot circular.
```
**Constraints:**
- `1 <= sentence.length <= 500`
- `sentence` consist of only lowercase and uppercase English letters and spaces.
- The words in `sentence` are separated by a single space.
- There are no leading or trailing spaces.
### My Solutions
___
```python
class Solution:
    def isCircularSentence(self, sentence: str) -> bool:

        split = sentence.split(' ')

        if len(split) == 1:
            return split[0][0] == split[0][-1]

        for i in range(1,len(split)):

            if split[i-1][-1] != split[i][0]:
                return False

        return split[0][0] == split[-1][-1]
```

Time Complexity :
```python

```

Time Complexity : 
### Optimal Solutions
___
To solve the **Circular Sentence** problem efficiently, you can use a straightforward algorithm that processes the sentence in linear time.
#### **Optimal Algorithm: Linear Scan of Words**
**Algorithm Steps:**
1. **Split the Sentence into Words:**
	- Use the `split()` method to divide the sentence into a list of words.
```python
words = sentence.split()

```
2. **Iterate Over the Words:**
	- Loop through each word and compare the last character of the current word with the first character of the next word.
	- Use modulo arithmetic to wrap around and compare the last word with the first word for circularity.
```python
n = len(words)
for i in range(n):
    current_word = words[i]
    next_word = words[(i + 1) % n]
    if current_word[-1].lower() != next_word[0].lower():
        return False

```
		- **Note:** Convert characters to the same case (e.g., lower case) to handle case-insensitive comparisons if needed.
3. **Return the Result:**
	- If all comparisons pass, return `True`; otherwise, return `False`.
**Code Example:**
```python
def isCircularSentence(sentence):
    words = sentence.split()
    n = len(words)
    for i in range(n):
        current_word = words[i]
        next_word = words[(i + 1) % n]
        if current_word[-1].lower() != next_word[0].lower():
            return False
    return True

```
**Time Complexity:** O(n)
- **Explanation:**
	- Splitting the sentence into words takes O(n) time, where `n` is the length of the sentence.
	- The loop runs `n` times, each operation within the loop is O(1).
	- Therefore, the total time complexity is linear.
**Space Complexity:** O(n)
- **Explanation:**
	- The `words` list stores up to `n` characters.
	- Additional variables use constant space.
#### **Example Usage:**
```python
# Example 1
sentence = "Leetcode exercises sound delightful"
print(isCircularSentence(sentence))  # Output: True

# Example 2
sentence = "eetcode"
print(isCircularSentence(sentence))  # Output: True

# Example 3
sentence = "Leetcode is cool"
print(isCircularSentence(sentence))  # Output: False

```
#### **Edge Cases to Consider:**
- **Single Word Sentence:**
	- If the sentence contains only one word, ensure the first and last characters of that word are the same.
```python
if len(words) == 1:
    return words[0][0].lower() == words[0][-1].lower()

```
- **Empty Sentence:**
	- If the sentence is empty, you may return `True` or `False` based on the problem's specifications. In most cases, an empty sentence is not considered circular.
#### **Summary:**
- The algorithm efficiently checks the circularity condition by iterating through the words once.
- It handles both uppercase and lowercase letters by converting characters to a common case.
- The use of modulo arithmetic ensures that the comparison wraps around from the last word to the first word.
___
**Note:** Always refer to the specific problem constraints to handle cases like punctuation, special characters, or different definitions of word boundaries.
### Notes
___
 
### Related Videos 
___
[]()