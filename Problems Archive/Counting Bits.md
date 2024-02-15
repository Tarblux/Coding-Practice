# Counting Bits

Problem: 338
Official Difficulty: easy
Feels Like : easy
Topic: Bit Manipulation, dynamic programming
Link: https://leetcode.com/problems/counting-bits/description/
Completed On : February 13, 2024
My Understanding: Mostly Understand
Last Review: February 13, 2024
Days Since Review: 1

## Problem

---

Given an integer `n`, return *an array* `ans` *of length* `n + 1` *such that for each* `i` **(`0 <= i <= n`)*,* `ans[i]` *is the **number of*** `1`***'s** in the binary representation of* `i`.

**Example 1:**

```
Input: n = 2
Output: [0,1,1]
Explanation:
0 --> 0
1 --> 1
2 --> 10
```

**Example 2:**

```
Input: n = 5
Output: [0,1,1,2,1,2]
Explanation:
0 --> 0
1 --> 1
2 --> 10
3 --> 11
4 --> 100
5 --> 101
```

**Constraints:**

- `0 <= n <= 105`

**Follow up:**

- It is very easy to come up with a solution with a runtime of `O(n log n)`. Can you do it in linear time `O(n)` and possibly in a single pass?
- Can you do it without using any built-in function (i.e., like `__builtin_popcount` in C++)?

## My Solutions

---

```python
class Solution:
    def countBits(self, n: int) -> List[int]:

        def bitCount(num):

            counter = 0

            while num : 

                if num & 1 == True : 

                    counter += 1

                num >>= 1

            return counter

        array = []

        for i in range(0,n+1):

            array.append(bitCount(i))

        return array
```

```python

```

## Optimal Solutions

---

```python
class Solution:
    def countBits(self, n: int) -> List[int]:
        res = [0]*(n+1)
        for i in range(n+1):
            res[i] = res[i>>1]+(i&1)
        return res
```

## Notes

---

 

## Related Videos

---

[https://www.youtube.com/watch?v=RyBM56RIWrM](https://www.youtube.com/watch?v=RyBM56RIWrM)