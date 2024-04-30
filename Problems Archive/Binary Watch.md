# Binary Watch

Problem: 401
Official Difficulty: easy
Feels Like : medium
My Understanding: Mostly Understand
Topic: Bit Manipulation, Math, backtracking
Link: https://leetcode.com/problems/binary-watch/description/
Completed On : March 18, 2024
Last Review: March 18, 2024
Days Since Review: 43

## Problem

---

A binary watch has 4 LEDs on the top to represent the hours (0-11), and 6 LEDs on the bottom to represent the minutes (0-59). Each LED represents a zero or one, with the least significant bit on the right.

- For example, the below binary watch reads `"4:51"`.

![https://assets.leetcode.com/uploads/2021/04/08/binarywatch.jpg](https://assets.leetcode.com/uploads/2021/04/08/binarywatch.jpg)

Given an integer `turnedOn` which represents the number of LEDs that are currently on (ignoring the PM), return *all possible times the watch could represent*. You may return the answer in **any order**.

The hour must not contain a leading zero.

- For example, `"01:00"` is not valid. It should be `"1:00"`.

The minute must consist of two digits and may contain a leading zero.

- For example, `"10:2"` is not valid. It should be `"10:02"`.

**Example 1:**

```
Input: turnedOn = 1
Output: ["0:01","0:02","0:04","0:08","0:16","0:32","1:00","2:00","4:00","8:00"]
```

**Example 2:**

```
Input: turnedOn = 9
Output: []
```

**Constraints:**

- `0 <= turnedOn <= 10`

## My Solutions

---

```python
class Solution:

    def countBits(self,n):
        count = 0 

        while n:
            count += n&1
            n >>= 1

        return count
        
    def readBinaryWatch(self, turnedOn: int) -> List[str]:

        possible_times = []
        min_dict = {}

        for i in  range(0,12):

            for j in range(0,60):

                min_dict[j] = min_dict.get(j,self.countBits(j))

                if min_dict[i] + min_dict[j] == turnedOn:

                    cur_time = f'{i}:{j:02}'

                    possible_times.append(cur_time)

        return possible_times

```

```python

```

## Optimal Solutions

---

## Notes

---

 

## Related Videos

---

[https://www.youtube.com/watch?v=shgJvIdbvYM&pp=ygUVYmluYXJ5IHdhdGNoIGxlZXRjb2Rl](https://www.youtube.com/watch?v=shgJvIdbvYM&pp=ygUVYmluYXJ5IHdhdGNoIGxlZXRjb2Rl)