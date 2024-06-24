# Remove vowels from a string

Problem: 1119
Official Difficulty: easy
Feels Like : easy breazy
My Understanding: Fully Understand
Topic: string
Link: https://leetcode.com/problems/remove-vowels-from-a-string/description/
Completed On : June 18, 2024
Last Review: June 18, 2024
Days Since Review: 6

## Problem

---

Given a string `s`, remove the vowels `'a'`, `'e'`, `'i'`, `'o'`, and `'u'` from it, and return the new string.

**Example 1:**

```
Input: s = "leetcodeisacommunityforcoders"
Output: "ltcdscmmntyfrcdrs
```

**Example 2:**

```
Input: s = "aeiou"
Output: ""
```

**Constraints:**

- `1 <= s.length <= 1000`
- `s` consists of only lowercase English letters.

## My Solutions

---

```python
class Solution:
    def removeVowels(self, s: str) -> str:

        """
        - Add Vowels to Dictionary
        - Iterate over s and only append characters not in dictionary
        - use .join method to concatenate individual characters

        TC : O(N)
        SC : O(N)
        """

        if not s:
            return ''

        vowels = {
            'a':1,
            'e':1,
            'i':1,
            'o':1,
            'u':1
        }

        output = []

        for i in range(len(s)):

            if s[i] not in vowels:
                output.append(s[i])

        return ''.join(output)
```

```python

```

## Optimal Solutions

---

### Problem Description

Given a string `s`, remove all the vowels from the string and return the new string. The vowels are 'a', 'e', 'i', 'o', 'u', and their uppercase counterparts.

### Example

```python
Input: s = "leetcodeisacommunityforcoders"
Output: "ltcdscmmntyfrcdrs"

Input: s = "AEIOUaeiou"
Output: ""

```

### Optimal Solution and Explanation

To remove all vowels from the string efficiently, we can follow these steps:

1. **Define Vowels Set**: Create a set containing all the vowels (both lowercase and uppercase) for quick lookup.
2. **Filter Characters**: Iterate through the string and include only the characters that are not in the vowels set.
3. **Join the Result**: Join the filtered characters to form the resulting string without vowels.

### Python Code

Here's the Python code to achieve this:

```python
def removeVowels(s):
    vowels = set('aeiouAEIOU')
    return ''.join([char for char in s if char not in vowels])

# Example usage
print(removeVowels("leetcodeisacommunityforcoders"))  # Output: "ltcdscmmntyfrcdrs"
print(removeVowels("AEIOUaeiou"))                    # Output: ""

```

### Explanation

1. **Define Vowels Set**:
    - `vowels = set('aeiouAEIOU')`: This creates a set of vowels for quick lookup. Sets provide average O(1) time complexity for membership checks, making this operation efficient.
2. **Filter Characters**:
    - `[char for char in s if char not in vowels]`: This list comprehension iterates through each character in the string `s` and includes only those characters that are not in the `vowels` set.
3. **Join the Result**:
    - `''.join(...)`: This joins the filtered characters into a single string without any vowels.

### Time Complexity Analysis

- **Time Complexity**: `O(n)`
    - The algorithm iterates through each character in the string once, where `n` is the length of the string. Checking membership in a set is O(1) on average, so the overall time complexity is linear.

### Space Complexity Analysis

- **Space Complexity**: `O(n)`
    - The algorithm uses a list to store the characters that are not vowels, which in the worst case (when there are no vowels) requires space proportional to the length of the string. The set of vowels requires constant space.

This approach efficiently removes all vowels from the input string in linear time.

## Notes

---

 

## Related Videos

---

[https://www.notion.so](https://www.notion.so)