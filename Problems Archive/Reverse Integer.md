# Reverse Integer

Problem: 7
Official Difficulty: medium
Feels Like : easy
Topic: Math
Link: https://leetcode.com/problems/reverse-integer/
Completed On : November 18, 2023
My Understanding: Mostly Understand
Last Review: November 18, 2023
Days Since Review: 84

## Problem

---

Given a signed 32-bit integer `x`, return `x` *with its digits reversed*. If reversing `x` causes the value to go outside the signed 32-bit integer range `[-231, 231 - 1]`, then return `0`.

**Assume the environment does not allow you to store 64-bit integers (signed or unsigned).**

## My Solutions

---

### Tariq

```python
class Solution(object):
    def reverse(self, x):
        
        x_string = str(x)
        
        negative = x_string[0] == '-'
        
        if negative == False :
        
           reverse = x_string[::-1]
        
        else : 
            
            reverse = '-' + x_string[:0:-1]
            
        result = int(reverse)
        
        if result < -2**31 or result > 2**31 - 1:
            
            return 0
        
        return result
```

```python

```

## Optimal Solutions

---

The approach you've implemented to reverse an integer is quite efficient and close to optimal. You're correctly handling both positive and negative numbers, as well as checking for 32-bit integer overflow. Here's a quick breakdown:

1. **Convert to String**: You convert the integer `x` to a string to make reversal easier.
2. **Check for Negativity**: You correctly identify if the number is negative and handle it accordingly.
3. **Reverse the String**: You reverse the string using slicing. For negative numbers, you exclude the negative sign during reversal and then add it back.
4. **Convert Back to Integer and Overflow Check**: You convert the reversed string back to an integer and check if it falls within the 32-bit signed integer range.

### Possible Optimization:

While your method is already efficient, you can make the code slightly more concise. Python's string slicing is powerful enough to handle negative numbers without the need for separate handling:

```python
class Solution(object):
    def reverse(self, x):
        # Reverse the string representation of x
        reversed_x = str(x)[::-1]

        # Handle negative numbers
        if x < 0:
            result = int('-' + reversed_x[:-1])
        else:
            result = int(reversed_x)

        # Check for 32-bit integer overflow
        if result < -2**31 or result > 2**31 - 1:
            return 0

        return result

```

### Explanation:

- The simplification comes from directly reversing the string representation of `x`. The slicing `[::-1]` works correctly even for negative numbers, although it will include the minus sign at the end of the reversed string.
- For negative numbers, the minus sign is re-added to the start of the reversed string, and the last character (which is the original minus sign) is omitted using `[:-1]`.
- The overflow check and the conversion back to integer remain the same.

This optimized version reduces the lines of code and avoids explicit comparison to check if `x` is negative. The core logic remains the same, ensuring that the function correctly reverses the integer within the bounds of a 32-bit signed integer.

## Notes

---

Overflow is different in python so look into that more 

## Related Videos

---

[https://www.youtube.com/watch?v=HAgLH58IgJQ](https://www.youtube.com/watch?v=HAgLH58IgJQ)