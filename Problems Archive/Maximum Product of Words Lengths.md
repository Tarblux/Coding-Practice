# Maximum Product of Words Lengths

Problem: 318
Official Difficulty: medium
Feels Like : medium
Topic: Bit Manipulation, array, string
Link: https://leetcode.com/problems/maximum-product-of-word-lengths/description/
Completed On : February 14, 2024
My Understanding: Needs Review
Last Review: February 14, 2024
Days Since Review: 0

## Problem

---

Given a string array `words`, return *the maximum value of* `length(word[i]) * length(word[j])` *where the two words do not share common letters*. If no such two words exist, return `0`.

**Example 1:**

```
Input: words = ["abcw","baz","foo","bar","xtfn","abcdef"]
Output: 16
Explanation: The two words can be "abcw", "xtfn".

```

**Example 2:**

```
Input: words = ["a","ab","abc","d","cd","bcd","abcd"]
Output: 4
Explanation: The two words can be "ab", "cd".

```

**Example 3:**

```
Input: words = ["a","aa","aaa","aaaa"]
Output: 0
Explanation: No such pair of words.

```

**Constraints:**

- `2 <= words.length <= 1000`
- `1 <= words[i].length <= 1000`
- `words[i]` consists only of lowercase English letters

## My Solutions

---

```python
class Solution:
    def maxProduct(self, words: List[str]) -> int:

        def word_to_bitmask(word):

            bitmask = 0

            for char in word:

                if 'a' <= char <= 'z':  # Ensure the character is a lowercase letter

                    index = ord(char) - ord('a')  # Find its alphabet index (0 for 'a', 25 for 'z')
                    
                    bitmask |= (1 << index)  # Set the corresponding bit to 1

            return bitmask

        bitWords = [0]*len(words)

        for i in range(len(bitWords)) : 

            bitWords[i] = word_to_bitmask(words[i])

        maximum = 0

        for index , val in enumerate(bitWords) : 

            for index2 , val2 in enumerate(bitWords) : 

                if val2 & val == 0 : 

                    maximum = max(maximum,len(words[index])*len(words[index2]))

        return maximum
```

```python

```

## Optimal Solutions

---

### Solution Approach

1. **Character Set Representation**: Represent each word by a bitmask of length 26 (for each letter in the alphabet). A bit in the mask is set to `1` if the corresponding letter is present in the word. This way, you can efficiently represent and compare the characters used in two words.
2. **Check for Common Characters**: Use bitwise AND to check if two words have common characters. If the result is 0, it means the words have no common characters.
3. **Calculate Maximum Product**: Iterate through all pairs of words, and for each pair with no common characters, calculate the product of their lengths. Keep track of the maximum product found.

### Python Implementation

```python
class Solution:
    def maxProduct(self, words: List[str]) -> int:
        # Initialize the maximum product
        max_product = 0

        # Create a list to store the bitmask representation of each word
        bit_masks = []

        for word in words:
            # Create a bitmask for the current word
            mask = 0
            for char in word:
                # Set the bit corresponding to the char in the mask
                mask |= 1 << (ord(char) - ord('a'))
            bit_masks.append((mask, len(word)))

        # Iterate through all pairs of words to find the maximum product
        for i in range(len(bit_masks)):
            for j in range(i + 1, len(bit_masks)):
                # If the words have no common characters
                if bit_masks[i][0] & bit_masks[j][0] == 0:
                    # Calculate the product of their lengths
                    product = bit_masks[i][1] * bit_masks[j][1]
                    # Update the maximum product
                    max_product = max(max_product, product)

        return max_product

```

### Complexity Analysis

- **Time Complexity**: O(N^2 * L), where `N` is the number of words, and `L` is the average length of the words. The outer double loop contributes O(N^2) complexity, and the inner loop for creating bitmasks contributes up to O(L) for each word.
- **Space Complexity**: O(N), for storing the bitmask and length of each word. The space used for the bitmask of each word is constant, but storing them for all words contributes linear space complexity relative to the number of words.

This solution efficiently finds the maximum product of lengths of two words that do not share any common characters by utilizing bit manipulation to quickly check for shared characters between any two words.

Let's dive deeper into the "Maximum Product of Word Lengths" problem and provide a detailed explanation of the solution, particularly focusing on the use of bit manipulation and its benefits in this context.

### Key Ideas of the Solution

1. **Bitmask Representation**: The core idea is to represent each word by a 26-bit integer bitmask, where each bit corresponds to one letter of the English alphabet ('a' to 'z'). For example, if a word contains the letter 'a', the least significant bit is set to 1. If it contains 'b', the second least significant bit is set, and so on. This compact representation allows us to check for common letters between two words efficiently.
2. **Efficient Character Set Comparison**: The bitwise AND operation (`&`) is used to determine if two words have any letters in common. If the result of `word1_mask & word2_mask` is 0, it means there are no common letters, as no bits are set in the same positions in both masks. This check is much faster than comparing character sets of two words directly, especially for longer words.
3. **Maximizing Product**: The goal is to find two words with no letters in common that maximize the product of their lengths. By iterating through all pairs of words and calculating the product of lengths for pairs without common letters, we can find the maximum product.

### Detailed Steps

- **Initialization**: Start with a maximum product variable set to 0. Also, create an empty list to hold the bitmask and length of each word.
- **Creating Bitmasks**: Iterate through each word in the input list. For each word, create a bitmask by setting bits corresponding to the letters present in the word. Store this bitmask along with the word's length in the list.
- **Finding Maximum Product**: Double loop through the list of bitmasks and lengths. For each pair, check if the bitmasks have no bits in common (using bitwise AND). If they don't, calculate the product of their lengths. Update the maximum product if this product is greater than the current maximum.
- **Return Result**: After checking all pairs, return the maximum product found.

### Benefits of Bit Manipulation

- **Performance**: Checking for common letters with bitmasks and bitwise operations is significantly faster than other methods, like iterating through characters and using sets, especially as the number of words and their length increase.
- **Space Efficiency**: Storing character presence with bitmasks uses much less space than other data structures like arrays or sets for each word.

### Example

Consider `words = ["abc", "def", "ghi"]`:

- The bitmask for "abc" is `000...000111`, for "def" is `000...011100`, and for "ghi" is `000...111000` (assuming the rightmost bit represents 'a').
- No pair of these bitmasks have common bits set, so we calculate the product of lengths for each pair: `3*3 = 9` for ("abc", "def"), ("abc", "ghi"), and ("def", "ghi").
- The maximum product is 9, achieved by any pair since all words have length 3 and no common letters.

### Complexity Analysis Revisited

- **Time Complexity**: O(N^2 * L) for creating bitmasks and O(N^2) for comparing all pairs, where N is the number of words and L is the maximum length of a word. However, the bitwise AND operation itself is O(1), making comparisons efficient.
- **Space Complexity**: O(N), as we store a bitmask and length for each word. The overall space required scales linearly with the number of words, while the bitmask itself uses constant space.

This approach illustrates how bit manipulation can significantly optimize specific problems by reducing both time and space complexity compared to more straightforward character comparison methods.

## Notes

---

 The main thing is to understand the bitmask implementation.

## Related Videos

---

[https://www.notion.so](https://www.notion.so)