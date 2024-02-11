# Fizz Buzz

Problem: 412
Official Difficulty: easy
Feels Like : easy
Topic: Math, string
Link: https://leetcode.com/problems/fizz-buzz/
Completed On : December 6, 2023
My Understanding: Fully Understand
Last Review: December 6, 2023
Days Since Review: 66

## Problem

---

Given an integer `n`, return *a string array* `answer` *(**1-indexed**) where*:

- `answer[i] == "FizzBuzz"` if `i` is divisible by `3` and `5`.
- `answer[i] == "Fizz"` if `i` is divisible by `3`.
- `answer[i] == "Buzz"` if `i` is divisible by `5`.
- `answer[i] == i` (as a string) if none of the above conditions are true.

**Example 1:**

```
Input: n = 3
Output: ["1","2","Fizz"]

```

**Example 2:**

```
Input: n = 5
Output: ["1","2","Fizz","4","Buzz"]

```

**Example 3:**

```
Input: n = 15
Output: ["1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz"]

```

**Constraints:**

- `1 <= n <= 104`

## My Solutions

---

```python
class Solution:
    def fizzBuzz(self, n: int) -> List[str]:
        
        answer = []
        
        for i in range(1,n+1): 
            
            if i % 3 == 0 and i % 5 == 0 : 
                
                answer.append("FizzBuzz")
                
            elif i % 3 == 0 : 
                
                answer.append("Fizz")
                
            elif i % 5 == 0 : 
                
                answer.append("Buzz")
                
            else: 
             
                answer.append(str(i))
                
        return answer
```

```python

```

## Optimal Solutions

---

The "Fizz Buzz" problem is a classic example often used in coding interviews and programming exercises. The problem statement is typically as follows:

Write a program that outputs the string representation of numbers from 1 to `n`.

For multiples of three, output "Fizz" instead of the number, and for the multiples of five, output "Buzz". For numbers which are multiples of both three and five, output "FizzBuzz".

### Solution Approach

The most straightforward way to solve this problem is to iterate over the numbers from 1 to `n`, checking for each of the conditions and concatenating the appropriate strings.

### Algorithm

1. Initialize an empty list to store the results.
2. Iterate over the range from 1 to `n` (inclusive).
3. For each number:
    - Initialize an empty string for the current number.
    - Check if the number is divisible by 3. If so, append "Fizz" to the string.
    - Check if the number is divisible by 5. If so, append "Buzz" to the string.
    - If the string is still empty (the number is neither divisible by 3 nor 5), convert the number to a string and use that.
    - Append the final string to the results list.
4. Return the results list.

### Python Implementation

```python
def fizzBuzz(n):
    result = []
    for i in range(1, n+1):
        current = ''
        if i % 3 == 0:
            current += 'Fizz'
        if i % 5 == 0:
            current += 'Buzz'
        if current == '':
            current = str(i)
        result.append(current)
    return result

```

### Complexity Analysis

- **Time Complexity**: O(n), as we iterate over the range from 1 to `n`.
- **Space Complexity**: O(n), since we store the result for each number in a list.

### Explanation

This implementation uses a loop to go through each number from 1 to `n`. It builds a string for each number based on whether it's divisible by 3, 5, both, or neither. If the number is divisible by 3, "Fizz" is appended to the string. If it's divisible by 5, "Buzz" is appended. If the number is not divisible by either, the number itself (converted to a string) is used. The result for each number is then added to a list, which is returned at the end of the function.

## Notes

---

 Got this in my stryker interview lol 😈

## Related Videos

---

[https://www.youtube.com/watch?v=z3-XFI_nXNM&pp=ygUPZml6emJ1enogcHl0aG9u](https://www.youtube.com/watch?v=z3-XFI_nXNM&pp=ygUPZml6emJ1enogcHl0aG9u)