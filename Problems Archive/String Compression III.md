Problem: 3163
Official Difficulty: medium
Link: https://leetcode.com/problems/string-compression-iii/description/?envType=daily-question&envId=2024-11-04
Completed On : 2024-11-03
Feels Like : medium
Topic: hash table, string
My Understanding: Needs Review
Last Review: 2024-11-03
Days Since Review: 7
Name: String Compression III

# String Compression III
### Problem
___
Given a string `word`, compress it using the following algorithm:
- Begin with an empty string `comp`. While `word` is **not** empty, use the following operation:
	- Remove a maximum length prefix of `word` made of a *single character* `c` repeating **at most** 9 times.
	- Append the length of the prefix followed by `c` to `comp`.
Return the string `comp`.
**Example 1:**
**Input:** word = "abcde"
**Output:** "1a1b1c1d1e"
**Explanation:**
Initially, `comp = ""`. Apply the operation 5 times, choosing `"a"`, `"b"`, `"c"`, `"d"`, and `"e"` as the prefix in each operation.
For each prefix, append `"1"` followed by the character to `comp`.
**Example 2:**
**Input:** word = "aaaaaaaaaaaaaabb"
**Output:** "9a5a2b"
**Explanation:**
Initially, `comp = ""`. Apply the operation 3 times, choosing `"aaaaaaaaa"`, `"aaaaa"`, and `"bb"` as the prefix in each operation.
- For prefix `"aaaaaaaaa"`, append `"9"` followed by `"a"` to `comp`.
- For prefix `"aaaaa"`, append `"5"` followed by `"a"` to `comp`.
- For prefix `"bb"`, append `"2"` followed by `"b"` to `comp`.
**Constraints:**
- `1 <= word.length <= 2 * 105`
- `word` consists only of lowercase English letters.
### My Solutions
___
Doesn’t work , see if you know why
```python
class Solution:
    def compressedString(self, word: str) -> str:

        counts = Counter(word)
        comp = ''

        for letter in counts:

            while counts[letter] > 0:
                
                removeable = min(9,counts[letter])
                comp += str(removeable) + letter

                counts[letter] -= removeable

        return comp
```

Time Complexity :
```python

```

Time Complexity : 
### Optimal Solutions
___
To solve **LeetCode Problem 3163: String Compression III**, the most optimal approach is to iterate through the string while keeping track of consecutive repeating characters, ensuring that no group exceeds 9 consecutive characters of the same kind.
___
#### **Optimal Algorithm: Linear Traversal with Count Limitation**
#### **Algorithm Overview**
- **Objective:** Compress the input string `word` by replacing groups of repeating characters with the count followed by the character, where each count does not exceed 9.
- **Approach:** Use a single-pass algorithm to traverse the string, counting consecutive occurrences of each character up to a maximum of 9, and build the compressed string accordingly.
#### **Algorithm Steps**
1. **Initialize Variables:**
	- Create an empty list `comp` to build the compressed string efficiently.
	- Set a pointer `i = 0` to iterate through the string.
	- Determine the length of the string `n = len(word)`.
2. **Iterate Through the String:**
	- While `i < n`, perform the following steps:
		- **Set Current Character:**
			- Let `c = word[i]`, the current character.
		- **Initialize Count:**
			- Initialize a counter `count = 0` to count occurrences of `c`.
		- **Count Consecutive Characters:**
			- While `i < n`, `word[i] == c`, and `count < 9`:
				- Increment `count` by 1.
				- Increment `i` by 1.
		- **Append to Compressed String:**
			- Append `str(count)` followed by `c` to the `comp` list.
		- **Note on Count Limitation:**
			- The count is limited to a maximum of 9 to satisfy the problem constraint.
3. **Construct the Final String:**
	- Join the elements of the `comp` list to form the compressed string.
```python
compressed_string = ''.join(comp)

```
4. **Return the Compressed String:**
	- Return `compressed_string` as the result.
#### **Code Implementation**
```python
def compressString(word):
    comp = []
    n = len(word)
    i = 0  # Pointer to iterate through the word
    while i < n:
        c = word[i]
        count = 0
        # Count up to 9 consecutive occurrences of c
        while i < n and word[i] == c and count < 9:
            count += 1
            i += 1
        # Append the count and character to comp
        comp.append(str(count))
        comp.append(c)
    return ''.join(comp)

```
#### **Example Usage**
```python
# Example 1
word1 = "abcde"
print(compressString(word1))  # Output: "1a1b1c1d1e"

# Example 2
word2 = "aaaaaaaaaaaaaabb"
print(compressString(word2))  # Output: "9a5a2b"

```
___
#### **Time and Space Complexity Analysis**
#### **Time Complexity:** O(n)
- **Explanation:**
	- The algorithm traverses the string `word` exactly once.
	- The inner while loop increments `i` each time, ensuring each character is processed only once.
	- All operations inside the loop are O(1).
	- Therefore, the total time complexity is linear with respect to the length of `word`.
#### **Space Complexity:** O(n)
- **Explanation:**
	- The `comp` list stores the compressed string.
	- In the worst-case scenario (e.g., all unique characters), the compressed string can be up to twice the length of the input (`2n` characters).
	- Therefore, the space used is proportional to `n`.
___
#### **Alternative Approach: Using itertools.groupby (Python Specific)**
#### **Algorithm Overview**
- **Objective:** Use the `groupby` function from the `itertools` module to group consecutive repeating characters.
- **Approach:** Group the characters and process each group, splitting larger groups into chunks of at most 9 characters.
#### **Algorithm Steps**
5. **Import groupby:**
	- `from itertools import groupby`
6. **Group Consecutive Characters:**
	- Use `groupby` to group consecutive characters in `word`.
```python
groups = [(char, sum(1 for _ in group)) for char, group in groupby(word)]

```
7. **Process Each Group:**
	- Initialize an empty list `comp` to store the compressed parts.
	- For each `(char, count)` in `groups`:
		- While `count > 0`:
			- Set `chunk_size = min(count, 9)`.
			- Append `str(chunk_size)` followed by `char` to `comp`.
			- Decrease `count` by `chunk_size`.
8. **Construct the Final String:**
	- Join the elements of `comp` to form the compressed string.
#### **Code Implementation**
```python
from itertools import groupby

def compressString(word):
    comp = []
    for char, group in groupby(word):
        count = sum(1 for _ in group)
        while count > 0:
            chunk_size = min(count, 9)
            comp.append(str(chunk_size))
            comp.append(char)
            count -= chunk_size
    return ''.join(comp)

```
#### **Time Complexity:** O(n)
- **Explanation:**
	- Grouping consecutive characters with `groupby` is O(n).
	- Summing the counts and processing each group is O(n).
	- Therefore, the overall time complexity is linear.
#### **Space Complexity:** O(n)
- **Explanation:**
	- Similar to the first method, storing the compressed string requires O(n) space.
___
#### **Comparison and Recommendation**
- **First Method (Linear Traversal):**
	- **Pros:**
		- Simple and efficient.
		- Directly processes the string without additional overhead.
	- **Cons:**
		- Slightly more code compared to using built-in functions.
- **Second Method (Using **`**groupby**`**):**
	- **Pros:**
		- Utilizes Python's built-in functions for grouping.
		- Code can be more concise.
	- **Cons:**
		- May have additional overhead due to generator expressions and function calls.
		- Less efficient if the overhead of `groupby` is significant for large inputs.
**Recommendation:**
- The **first method** is recommended as it is straightforward, efficient, and avoids the overhead associated with `groupby`.
- It provides better control over the processing of the string and can be easily adapted to other programming languages.
___
#### **Final Code Solution**
```python
def compressString(word):
    comp = []
    n = len(word)
    i = 0  # Pointer to iterate through the word
    while i < n:
        c = word[i]
        count = 0
        # Count up to 9 consecutive occurrences of c
        while i < n and word[i] == c and count < 9:
            count += 1
            i += 1
        # Append the count and character to comp
        comp.append(str(count))
        comp.append(c)
    return ''.join(comp)

```
___
#### **Test Cases**
```python
# Test Case 1
word = "abcde"
assert compressString(word) == "1a1b1c1d1e"

# Test Case 2
word = "aaaaaaaaaaaaaabb"
assert compressString(word) == "9a5a2b"

# Test Case 3
word = "aabbccddeeffgg"
assert compressString(word) == "2a2b2c2d2e2f2g"

# Test Case 4
word = "zzzzzzzzzzzzzzzzzzzz"
assert compressString(word) == "9z9z2z"

# Test Case 5
word = "qwertyuiopasdfghjklzxcvbnm"
assert compressString(word) == "1q1w1e1r1t1y1u1i1o1p1a1s1d1f1g1h1j1k1l1z1x1c1v1b1n1m"

```
___
#### **Conclusion**
- The provided algorithm efficiently compresses the input string according to the specified rules.
- It operates in linear time and uses space proportional to the length of the input.
- By carefully managing the count of consecutive characters and limiting it to 9, the algorithm adheres to the problem constraints.
- The solution is suitable for large input strings within the given constraints.
### Notes
___
 
### Related Videos 
___
[]()