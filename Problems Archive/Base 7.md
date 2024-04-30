# Base 7

Problem: 504
Official Difficulty: easy
Feels Like : easy
My Understanding: Mostly Understand
Topic: Math
Link: https://leetcode.com/problems/base-7/description/
Completed On : April 22, 2024
Last Review: April 22, 2024
Days Since Review: 8

## Problem

---

Given an integer `num`, return *a string of its **base 7** representation*.

**Example 1:**

```
Input: num = 100
Output: "202"
```

**Example 2:**

```
Input: num = -7
Output: "-10"
```

**Constraints:**

- `107 <= num <= 107`

## My Solutions

---

```python
class Solution:
    def convertToBase7(self, num: int) -> str:

        if num == 0 : 
            return '0'

        negative = num < 0
        num = abs(num)
        output = ''

        while num :

            output += str(num%7)
            num //= 7

        return output[::-1] if not negative else '-' + output[::-1]
```

```python

```

## Optimal Solutions

---

## Notes

---

 

## Related Videos

---

[https://www.notion.so](https://www.notion.so)