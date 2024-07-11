# Water Bottles

Problem: 1518
Official Difficulty: easy
Feels Like : medium
My Understanding: Needs Review
Topic: Math, simulation
Link: https://leetcode.com/problems/water-bottles/description/
Completed On : July 7, 2024
Last Review: July 7, 2024
Days Since Review: 4

## Problem

---

empty water bottles from the market with one full water bottle.

The operation of drinking a full water bottle turns it into an empty bottle.

Given the two integers `numBottles` and `numExchange`, return *the **maximum** number of water bottles you can drink*.

**Example 1:**

![https://assets.leetcode.com/uploads/2020/07/01/sample_1_1875.png](https://assets.leetcode.com/uploads/2020/07/01/sample_1_1875.png)

```
Input: numBottles = 9, numExchange = 3
Output: 13
Explanation: You can exchange 3 empty bottles to get 1 full water bottle.
Number of water bottles you can drink: 9 + 3 + 1 = 13.

```

**Example 2:**

![https://assets.leetcode.com/uploads/2020/07/01/sample_2_1875.png](https://assets.leetcode.com/uploads/2020/07/01/sample_2_1875.png)

```
Input: numBottles = 15, numExchange = 4
Output: 19
Explanation: You can exchange 4 empty bottles to get 1 full water bottle.
Number of water bottles you can drink: 15 + 3 + 1 = 19.

```

**Constraints:**

- `1 <= numBottles <= 100`
- `2 <= numExchange <= 100`

## My Solutions

---

```python
class Solution:
    def numWaterBottles(self, numBottles: int, numExchange: int) -> int:
        output = numBottles

        while numBottles >= numExchange:
            new_bottles = numBottles // numExchange
            empty_bottles = numBottles % numExchange
            numBottles = new_bottles + empty_bottles
            output += new_bottles

        return output
```

```python

```

## Optimal Solutions

---

## Notes

---

 

## Related Videos

---

[https://youtu.be/V4d6xym5efE](https://youtu.be/V4d6xym5efE)