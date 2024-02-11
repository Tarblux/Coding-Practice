# Reverse String

Problem: 344
Official Difficulty: easy
Feels Like : easy
Topic: string, two pointers
Link: https://leetcode.com/problems/reverse-string/
Completed On : November 20, 2023
My Understanding: Fully Understand
Last Review: November 20, 2023
Days Since Review: 82

## Problem

---

Write a function that reverses a string. The input string is given as an array of characters `s`.

You must do this by modifying the input array [in-place](https://en.wikipedia.org/wiki/In-place_algorithm) with `O(1)` extra memory.

**Example 1:**

```
Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]

```

**Example 2:**

```
Input: s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]

```

## My Solutions

---

```python
class Solution(object):
    def reverseString(self, s):
        
        index = -1
        
        for i in range (0,len(s)//2) : 
            
            
            s[i] , s[index] = s[index] , s[i]
            
            index -= 1
```

## Optimal Solutions

---

The most optimal solution for reversing a string in place (given as an array of characters `s`) involves using the two-pointer technique. This method doesn't require additional memory for another array, ensuring that the space complexity remains O(1). The idea is to swap characters from the beginning of the array with those from the end, progressively moving towards the middle.

Here's how you can implement this in Python:

```python
class Solution:
    def reverseString(self, s):
        left, right = 0, len(s) - 1

        while left < right:
            # Swap the characters at the left and right pointers
            s[left], s[right] = s[right], s[left]

            # Move the pointers towards the center
            left += 1
            right -= 1

```

### Explanation:

- **Two Pointers**: `left` starts at the beginning (0) and `right` starts at the end (`len(s) - 1`) of the array.
- **Swapping Elements**: In each iteration of the loop, the characters at the `left` and `right` positions are swapped.
- **Moving Pointers**: The `left` pointer is incremented, and the `right` pointer is decremented, moving them towards the middle of the array.
- **Termination Condition**: The loop continues until `left` and `right` meet or cross, ensuring that each character has been swapped exactly once.

This method effectively reverses the string in place, and since no additional arrays are created, it uses constant extra memory, meeting the problem's constraints.

## Notes

---

 

## Related Videos

---

[https://www.notion.so](https://www.notion.so)