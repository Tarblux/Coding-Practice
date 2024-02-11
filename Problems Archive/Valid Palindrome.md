# Valid Palindrome

Problem: 125
Official Difficulty: easy
Feels Like : easy
Topic: string, two pointers
Link: https://leetcode.com/problems/valid-palindrome/
Completed On : November 20, 2023
My Understanding: Fully Understand
Last Review: November 20, 2023
Days Since Review: 82

## Problem

---

A phrase is a **palindrome** if, after converting all 
uppercase letters into lowercase letters and removing all 
non-alphanumeric characters, it reads the same forward and backward. 
Alphanumeric characters include letters and numbers.

Given a string `s`, return `true` *if it is a **palindrome**, or* `false` *otherwise*.

## My Solutions

---

```python
class Solution(object):
    def isPalindrome(self, s):
        
        s_array = []
        
        s = s.lower()
        
        if len(s) == 0 : 
            
            return True
        
        for i in range (0,len(s)) : 
            
            if s[i].isalnum() == True : 
                
                s_array.append(s[i])
                
        for i in range (0,len(s_array)//2) : 
            
            j = len(s_array) - 1 - i 
                    
            if s_array[i] != s_array[j] : 

                return False   
                    
        return True
```

### Aleksandr

```python
class Solution:
    def isPalindrome(self, s: str) -> bool:

        s = s.lower()   
        left = 0
        right = len(s) - 1

        while (left < right):
            l = s[left]
            r = s[right]
            
            if l.isalnum() == False:
                left +=1
                continue

            if r.isalnum() == False:
                right -= 1
                continue

            if s[left] != s[right]:
                return False
                    
            right -= 1
            left += 1
                    
        return True
```

### Lelo

```java
class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = [char for char in s.lower() if char.isalnum()]
        t = s[::-1]
        return s == t
```

## Optimal Solutions

---

The most optimal approach to determine if a string `s` is a palindrome (after converting all uppercase letters into lowercase and removing all non-alphanumeric characters) is to use a two-pointer technique. This approach eliminates the need for extra space and only requires one pass through the string, resulting in O(n) time complexity, where n is the length of the string.

Here's a step-by-step method:

1. **Initialize Two Pointers**: Start with two pointers, one at the beginning of the string and one at the end.
2. **Convert to Lowercase**: Optionally, you can convert the entire string to lowercase at the beginning to simplify comparisons. This avoids repetitive case conversions during the comparison process.
3. **Skip Non-Alphanumeric Characters**: Move each pointer inward, skipping any non-alphanumeric characters.
4. **Compare Characters**: Compare the characters at each pointer. If they are different, return `false`.
5. **Move Pointers**: If they are the same, move the pointers closer to each other and continue the comparison.
6. **Terminate When Pointers Meet or Cross**: Continue until the pointers meet or cross each other.
7. **Return True**: If the loop completes without finding any mismatch, return `true`.

Here's how you can implement this in Python:

```python
class Solution(object):
    def isPalindrome(self, s):
        # Convert to lowercase and initialize pointers
        s = s.lower()
        left, right = 0, len(s) - 1

        while left < right:
            # Skip non-alphanumeric characters
            while left < right and not s[left].isalnum():
                left += 1
            while left < right and not s[right].isalnum():
                right -= 1

            # Check if characters are equal
            if s[left] != s[right]:
                return False

            # Move pointers
            left += 1
            right -= 1

        return True

```

This code efficiently checks for palindrome properties in the given string `s`, adhering to the specified conditions.

## Notes

---

Remember to account for upper and lower case situations 

## Related Videos

---

[https://youtu.be/jJXJ16kPFWg?si=JLF4JkrEQRrBaCn5](https://youtu.be/jJXJ16kPFWg?si=JLF4JkrEQRrBaCn5)