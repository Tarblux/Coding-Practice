# Coin Change

Problem: 322
Official Difficulty: medium
Feels Like : hard
Topic: Breadth-First Search(BFS), array, dynamic programming
Link: https://leetcode.com/problems/coin-change/description/
Completed On : January 21, 2024
My Understanding: I Have No Idea
Last Review: January 21, 2024
Days Since Review: 20

## Problem

---

You are given an integer array `coins` representing coins of different denominations and an integer `amount` representing a total amount of money.

Return *the fewest number of coins that you need to make up that amount*. If that amount of money cannot be made up by any combination of the coins, return `-1`.

You may assume that you have an infinite number of each kind of coin.

**Example 1:**

```
Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
```

**Example 2:**

```
Input: coins = [2], amount = 3
Output: -1
```

**Example 3:**

```
Input: coins = [1], amount = 0
Output: 0
```

**Constraints:**

- `1 <= coins.length <= 12`
- `1 <= coins[i] <= 231 - 1`
- `0 <= amount <= 104`

## My Solutions

---

```python

```

```python

```

## Optimal Solutions

---

The "Coin Change" problem is a classic example of a dynamic programming question. Given an array of distinct denominations (coins) and a total amount, the task is to find the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

### Problem Statement

Given an integer array `coins` representing coins of different denominations and an integer `amount` representing a total amount of money, return the fewest number of coins that you need to make up that amount. If that amount cannot be made up by any combination of the coins, return -1.

### Solution Approach: Dynamic Programming (Bottom-Up)

A bottom-up dynamic programming approach is well-suited for this problem. The idea is to build up a table `dp` where each entry `dp[i]` represents the minimum number of coins needed to make the amount `i`.

### Python Implementation

```python
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        # Initialize the dp array with a value larger than the possible maximum
        dp = [float('inf')] * (amount + 1)
        dp[0] = 0  # Base case: no coins needed for amount 0

        for coin in coins:
            for x in range(coin, amount + 1):
                dp[x] = min(dp[x], dp[x - coin] + 1)

        return dp[amount] if dp[amount] != float('inf') else -1

```

### Explanation

- Create a list `dp` with a length of `amount + 1`, initialized with `float('inf')`, which acts as a placeholder for an unreachable amount.
- Set `dp[0]` to 0 since no coins are needed to make the amount 0.
- Iterate over each coin, then iterate over all amounts from that coin value up to the total amount.
- Update `dp[x]` to be the minimum of its current value and `dp[x - coin] + 1`.
- Finally, check if `dp[amount]` is still `float('inf')`. If it is, the amount cannot be reached; return -1. Otherwise, return `dp[amount]`.

### Complexity Analysis

- **Time Complexity**: O(n * m), where n is the number of denominations and m is the total amount. This is because for each coin, we iterate through all amounts up to `m`.
- **Space Complexity**: O(m), where m is the total amount. The extra space is used for the `dp` table.

This solution effectively computes the minimum number of coins needed for each amount up to the target amount, ensuring an optimal solution is found if it exists.

## Explain Like I Am Five (ELI5)

---

## Notes

---

 

## Related Videos

---

[https://www.youtube.com/watch?v=H9bfqozjoqs](https://www.youtube.com/watch?v=H9bfqozjoqs)