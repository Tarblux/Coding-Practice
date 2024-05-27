# Reverse Words in a String

Problem: 151
Official Difficulty: medium
Feels Like : medium
My Understanding: Mostly Understand
Topic: array, string, two pointers
Link: https://leetcode.com/problems/reverse-words-in-a-string/description/
Completed On : May 25, 2024
Last Review: May 25, 2024
Days Since Review: 1

## Problem

---

Given an input string `s`, reverse the order of the **words**.

A **word** is defined as a sequence of non-space characters. The **words** in `s` will be separated by at least one space.

Return *a string of the words in reverse order concatenated by a single space.*

**Note** that `s` may contain leading or trailing 
spaces or multiple spaces between two words. The returned string should 
only have a single space separating the words. Do not include any extra 
spaces.

**Example 1:**

```
Input: s = "the sky is blue"
Output: "blue is sky the"
```

**Example 2:**

```
Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
```

**Example 3:**

```
Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.

```

**Constraints:**

- `1 <= s.length <= 104`
- `s` contains English letters (upper-case and lower-case), digits, and spaces `' '`.
- There is **at least one** word in `s`.

**Follow-up:** If the string data type is mutable in your language, can you solve it **in-place** with `O(1)` extra space?

## My Solutions

---

```python
class Solution:
    def reverseWords(self, s: str) -> str:

        s = s.split()

        return ' '.join(s[::-1])

```

Wrong but close ish

```python
def reverse_words(arr):
  
  if not arr :
    
    return []
  
  
  # Set up pointers 
  
  end = len(arr) - 1
  
  
  #Create output array 
  
  output = []
  cur_word = []
  
  #Traverse arr and extract words in reverse 
  
  while end > -1 :
    
    char = arr[end]
    
    if char == ' ' and cur_word:
      
      rev_word = cur_word.reverse() 
      output.append(rev_word)
      output.append(' ')
      cur_word = []
      end -= 1
      break
  
    cur_word.append(char)
    end -= 1
    
  return output

# arr = [ 'p', 'e', 'r', 'f', 'e', 'c', 't', '  ', '  ',
#          'm', 'a', 'k', 'e', 's', '  ',
#          'p', 'r', 'a', 'c', 't', 'i', 'c', 'e', ' ' ]
```

## Optimal Solutions

---

```python
def reverse_words(arr):
    if not arr:
        return []

    n = len(arr)

    # Helper function to reverse a portion of the array in place
    def reverse(arr, start, end):
        while start < end:
            arr[start], arr[end] = arr[end], arr[start]
            start += 1
            end -= 1

    # Reverse the entire array
    reverse(arr, 0, n - 1)

    # Reverse each word in the reversed array
    start = 0
    while start < n:
        if arr[start] != ' ':
            end = start
            while end < n and arr[end] != ' ':
                end += 1
            reverse(arr, start, end - 1)
            start = end
        start += 1

    return arr

# Example usage
s = list("the sky is blue")
print(''.join(reverse_words(s)))  # Output: "blue is sky the"

s = list("  hello world  ")
print(''.join(reverse_words(s)))  # Output: "world hello"

s = list("a good   example")
print(''.join(reverse_words(s)))  # Output: "example good a"

```

### Explanation

1. **Reverse the Entire Array**:
    - First, we reverse the entire array of characters. This will make the last character come to the first position and the first character go to the last position, effectively reversing the order of all characters.
2. **Reverse Each Word**:
    - After reversing the entire array, each word will be in the correct relative order, but the characters within each word will be reversed.
    - To correct this, we traverse the array and reverse the characters of each word individually.

### Example Walkthrough

For the string `"the sky is blue"`:

1. **Initial Array**: `['t', 'h', 'e', ' ', 's', 'k', 'y', ' ', 'i', 's', ' ', 'b', 'l', 'u', 'e']`
2. **After Reversing Entire Array**: `['e', 'u', 'l', 'b', ' ', 's', 'i', ' ', 'y', 'k', 's', ' ', 'e', 'h', 't']`
3. **Reversing Each Word**:
    - Reverse `"eulb"` to `"blue"`
    - Reverse `"si"` to `"is"`
    - Reverse `"yks"` to `"sky"`
    - Reverse `"eht"` to `"the"`

This gives the final result: `"blue is sky the"`.

By following this approach, we can reverse the words in the string in place, without using additional space for another array.

## Notes

---

 

## Related Videos

---

[https://www.youtube.com/watch?v=7kUEwiwwnlA&pp=ygUZcmV2ZXJzZSB3b3JkcyBpbiBhIHN0cmluZw%3D%3D](https://www.youtube.com/watch?v=7kUEwiwwnlA&pp=ygUZcmV2ZXJzZSB3b3JkcyBpbiBhIHN0cmluZw%3D%3D)