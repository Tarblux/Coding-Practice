# Divisor Game

Problem: 1025
Official Difficulty: easy
Feels Like : medium
My Understanding: Needs Review
Topic: Math, brainteaser, dynamic programming, game theory
Link: https://leetcode.com/problems/divisor-game/description/
Completed On : May 9, 2024
Last Review: May 9, 2024
Days Since Review: 3

## Problem

---

Alice and Bob take turns playing a game, with Alice starting first.

Initially, there is a number `n` on the chalkboard. On each player's turn, that player makes a move consisting of:

- Choosing any `x` with `0 < x < n` and `n % x == 0`.
- Replacing the number `n` on the chalkboard with `n - x`.

Also, if a player cannot make a move, they lose the game.

Return `true` *if and only if Alice wins the game, assuming both players play optimally*.

**Example 1:**

```
Input: n = 2
Output: true
Explanation: Alice chooses 1, and Bob has no more moves.

```

**Example 2:**

```
Input: n = 3
Output: false
Explanation: Alice chooses 1, Bob chooses 1, and Alice has no more moves.

```

**Constraints:**

- `1 <= n <= 1000`

## My Solutions

---

```python
class Solution:
    def divisorGame(self, n: int) -> bool:

        return n % 2 == 0
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