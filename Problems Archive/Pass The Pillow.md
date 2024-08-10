# Pass The Pillow

Problem: 2582
Official Difficulty: easy
Feels Like : easy breazy
My Understanding: Fully Understand
Topic: Math, simulation
Link: https://leetcode.com/problems/pass-the-pillow/description/
Completed On : July 6, 2024
Last Review: July 6, 2024
Days Since Review: 34

## Problem

---

There are `n` people standing in a line labeled from `1` to `n`.
 The first person in the line is holding a pillow initially. Every 
second, the person holding the pillow passes it to the next person 
standing in the line. Once the pillow reaches the end of the line, the 
direction changes, and people continue passing the pillow in the 
opposite direction.

- For example, once the pillow reaches the `nth` person they pass it to the `n - 1th` person, then to the `n - 2th` person and so on.

Given the two positive integers `n` and `time`, return *the index of the person holding the pillow after* `time` *seconds*.

**Example 1:**

```
Input: n = 4, time = 5
Output: 2
Explanation: People pass the pillow in the following way: 1 -> 2 -> 3 -> 4 -> 3 -> 2.
After five seconds, the 2nd person is holding the pillow.
```

**Example 2:**

```
Input: n = 3, time = 2
Output: 3
Explanation: People pass the pillow in the following way: 1 -> 2 -> 3.
After two seconds, the 3rd person is holding the pillow.
```

**Constraints:**

- `2 <= n <= 1000`
- `1 <= time <= 1000`

## My Solutions

---

```python
class Solution:
    def passThePillow(self, n: int, time: int) -> int:

        dct = 1
        i = 1

        while time:

            if i == n:
                dct = -1
            elif i == 1:
                dct = 1

            i += dct
            time -= 1

        return i
        
```

```python
class Solution:
    def passThePillow(self, n: int, time: int) -> int:

        rolls = time // (n-1)
        rem = time % (n-1)

        return  1 + rem if rolls % 2 == 0 else n - rem  
        
```

## Optimal Solutions

---

## Notes

---

 

## Related Videos

---

[https://www.notion.so](https://www.notion.so)