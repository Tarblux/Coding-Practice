<<<<<<< Updated upstream
Problem: 371
Official Difficulty: medium
Link: https://leetcode.com/problems/sum-of-two-integers/description/
Completed On : 2024-12-18
Feels Like : Brain Damage
Topic: Math, Bit Manipulation
My Understanding: I Have No Idea
Last Review: 2024-12-18
Days Since Review: 4
Name: Sum of Two Integers

# Sum of Two Integers
### Problem
___
Given two integers `a` and `b`, return *the sum of the two integers without using the operators* `+` *and* `-`.
**Example 1:**
```plain text
Input: a = 1, b = 2
Output: 3
```
**Example 2:**
```plain text
Input: a = 2, b = 3
Output: 5
```
**Constraints:**
- `1000 <= a, b <= 1000`
### My Solutions
___
=======
# Sum of Two Integers

Problem: 371
Official Difficulty: medium
Feels Like : Brain Damage
My Understanding: I Have No Idea
Topic: Bit Manipulation, Math
Link: https://leetcode.com/problems/sum-of-two-integers/description/
Completed On : December 18, 2024
Last Review: December 18, 2024
Days Since Review: 74
Neetcode: Yes

## Problem

---

Given two integers `a` and `b`, return *the sum of the two integers without using the operators* `+` *and* `-`.

**Example 1:**

```
Input: a = 1, b = 2
Output: 3
```

**Example 2:**

```
Input: a = 2, b = 3
Output: 5
```

**Constraints:**

- `1000 <= a, b <= 1000`

## My Solutions

---

>>>>>>> Stashed changes
```python
class Solution:
    def getSum(self, a: int, b: int) -> int:
        mask = 0xFFFFFFFF
        
        while b != 0:
            a, b = (a ^ b) & mask, ((a & b) << 1) & mask
        
        max_int = 0x7FFFFFFF
        return a if a < max_int else ~(a ^ mask)
```

<<<<<<< Updated upstream
Time Complexity :
=======
>>>>>>> Stashed changes
```python

```

<<<<<<< Updated upstream
Time Complexity : 
### Optimal Solutions
___

### Notes
___
 
### Related Videos 
___
[]()
=======
## Optimal Solutions

---

## Notes

---

 

## Related Videos

---

[https://www.notion.so](https://www.notion.so)
>>>>>>> Stashed changes
