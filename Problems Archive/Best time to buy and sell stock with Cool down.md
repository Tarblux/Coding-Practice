# Best time to buy and sell stock with Cool down

Problem: 309
Official Difficulty: medium
Feels Like : Brain Damage
My Understanding: Needs Review
Topic: array, dynamic programming
Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/?envType=problem-list-v2&envId=m7475vs1
Completed On : March 8, 2025
Last Review: March 8, 2025
Days Since Review: 1
Neetcode: Yes

## Problem

---

You are given an array `prices` where `prices[i]` is the price of a given stock on the `ith` day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

- After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).

**Note:** You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

**Example 1:**

```
Input: prices = [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]
```

**Example 2:**

```
Input: prices = [1]
Output: 0
```

**Constraints:**

- `1 <= prices.length <= 5000`
- `0 <= prices[i] <= 1000`

## My Solutions

---

```python
class Solution:
    def maxProfit(self, prices: List[int]) -> int:

        n = len(prices) + 1

        if n < 3:
            return 0

        dp = [[0,0] for i in range(n)]
        dp[0][0] = 0
        dp[0][1] = float('-inf')

        dp[1][0] = 0
        dp[1][1] = - prices[0]

        dp[2][0] = max(dp[1][0],dp[1][1] + prices[1])
        dp[2][1] = max(dp[1][1],dp[0][0] - prices[1])

        for i in range(3,n):

            dp[i][0] = max(dp[i-1][0],dp[i-1][1] + prices[i-1])
            dp[i][1] = max(dp[i-1][1],dp[i-2][0] - prices[i-1])

        return dp[n-1][0]
```

```python

```

## Optimal Solutions

---

The problem "Best Time to Buy and Sell Stock with Cool down" asks you to maximize your profit given that you cannot buy a stock on the next day after you sell stock (there's a cool down period of 1 day). You are given an array `prices` where `prices[i]` represents the price of a given stock on the `i-th` day.

### Approach

To solve this problem, you can use dynamic programming to keep track of three states representing the action taken on the `i-th` day:

1. **`hold`**: Maximum profit on day `i` when you have a stock in hand. You could have bought it on day `i` or held it from a previous day.
2. **`sell`**: Maximum profit on day `i` after selling the stock. You cannot buy on the next day due to the cool down.
3. **`cooldown`**: Maximum profit on day `i` when you are in the cool down period, meaning you did not buy or sell stock on this day.

The transitions between these states are as follows:

- **To `hold`**: You could have been holding a stock from the previous day, or you buy a stock today (which means you must have been in the cool down state the day before).
- **To `sell`**: If you are selling today, you must have been holding a stock from the previous day.
- **To `cooldown`**: You enter the cool down state after selling, or you could already be in the cool down state from the previous day.

### Python Implementation

```python
def maxProfit(prices):
    if not prices:
        return 0

    n = len(prices)
    hold, sell, cooldown = [0] * n, [0] * n, [0] * n

    # Initial conditions
    hold[0] = -prices[0]  # Buying on the first day

    for i in range(1, n):
        # Transition from hold or cooldown to hold
        hold[i] = max(hold[i-1], cooldown[i-1] - prices[i])
        # Transition from hold to sell
        sell[i] = hold[i-1] + prices[i]
        # Transition from sell or cooldown to cooldown
        cooldown[i] = max(cooldown[i-1], sell[i-1])

    # The maximum profit would be either in sell or cooldown state on the last day
    return max(sell[n-1], cooldown[n-1])

```

### Explanation

- **Initialization**: On day 0, `hold` represents buying the stock, so it's `prices[0]`. `sell` and `cooldown` are initialized to 0 because you haven't sold anything yet, and you're not in the cooldown period without any prior action.
- **Transitions**:
    - **hold[i]**: Either keep holding (`hold[i-1]`) or buy today after being in cooldown (`cooldown[i-1] - prices[i]`).
    - **sell[i]**: Sell the stock you're holding (`hold[i-1] + prices[i]`).
    - **cooldown[i]**: Either continue cooldown from the previous day (`cooldown[i-1]`) or enter cooldown after selling (`sell[i-1]`).
- **Result**: On the last day, you'll have the maximum profit if you're either in the `sell` or `cooldown` state, as holding a stock wouldn't contribute to the profit unless sold.

### Complexity Analysis

- **Time Complexity**: O(N), where N is the number of days. The solution iterates through the list of prices once.
- **Space Complexity**: O(N), as it maintains three arrays of size N each for `hold`, `sell`, and `cooldown` states. This can be optimized to O(1) by only keeping track of the states for the last two days, as the solution only depends on the immediate previous day's states.

## Notes

---

 

## Related Videos

---

[https://www.notion.so](https://www.notion.so)