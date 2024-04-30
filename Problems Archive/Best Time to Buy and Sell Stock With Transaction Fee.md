# Best Time to Buy and Sell Stock With Transaction Fee

Problem: 714
Official Difficulty: medium
Feels Like : medium
My Understanding: Mostly Understand
Topic: array, dynamic programming, greedy
Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/
Completed On : March 1, 2024
Last Review: March 5, 2024
Days Since Review: 56

## Problem

---

You are given an array `prices` where `prices[i]` is the price of a given stock on the `ith` day, and an integer `fee` representing a transaction fee.

Find the maximum profit you can achieve. You may complete as many 
transactions as you like, but you need to pay the transaction fee for 
each transaction.

**Note:**

- You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
- The transaction fee is only charged once for each stock purchase and sale.

**Example 1:**

```
Input: prices = [1,3,2,8,4,9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
- Buying at prices[0] = 1
- Selling at prices[3] = 8
- Buying at prices[4] = 4
- Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
```

**Example 2:**

```
Input: prices = [1,3,7,5,10,3], fee = 3
Output: 6
```

**Constraints:**

- `1 <= prices.length <= 5 * 104`
- `1 <= prices[i] < 5 * 104`
- `0 <= fee < 5 * 104`

## My Solutions

---

```python
class Solution:
    def maxProfit(self, prices: List[int], fee: int) -> int:

        cur_money = 0

        holding = - prices[0]

        for i in range(1,len(prices)): 

            cur_money = max(cur_money , prices[i] + holding - fee)

            holding = max(holding,cur_money - prices[i])

        return cur_money
```

```python

```

## Optimal Solutions

---

The problem "Best Time to Buy and Sell Stock with Transaction Fee" involves finding the maximum profit you can achieve from making transactions (buying and selling stocks), given that each transaction incurs a fixed transaction fee. You are given an array `prices` where `prices[i]` is the price of a given stock on the `i-th` day, and an integer `fee` representing the transaction fee.

You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction. You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

### Approach

A dynamic programming approach can be used to solve this problem efficiently. The idea is to track two states:

- **`hold`**: The maximum profit on day `i` when you have a stock in hand.
- **`cash`**: The maximum profit on day `i` when you do not have a stock in hand.

On each day, you can either buy a stock, sell a stock you hold, or do nothing. The transitions between the states are as follows:

- To transition to the `hold` state, you can either do nothing (keep holding the stock) or buy a stock (if you were in the `cash` state). Buying a stock costs `prices[i]`.
- To transition to the `cash` state, you can either do nothing (keep the cash) or sell the stock you are holding. Selling the stock earns `prices[i]` minus the transaction fee.

### Python Implementation

```python
def maxProfit(prices, fee):
    # Initialize the two states
    cash, hold = 0, -prices[0]  # Start with 0 cash and buying the first stock

    for i in range(1, len(prices)):
        # Update cash by selling the stock held (if this transaction is profitable)
        cash = max(cash, hold + prices[i] - fee)
        # Update hold by buying a stock (if this transaction is profitable)
        hold = max(hold, cash - prices[i])

    return cash  # The maximum profit is in the cash state at the end
```

### Explanation

- **Initialization**: Initially, `cash` is `0` because you start with no money, and `hold` is `prices[0]` because buying the first stock costs `prices[0]`.
- **Loop through each day**: For each day `i` starting from the second day:
    - **Sell the stock (if profitable)**: Calculate the new `cash` value as the maximum of the current `cash` and the profit from selling the stock held (`hold + prices[i] - fee`). This represents the profit after selling the stock you hold.
    - **Buy a stock (if profitable)**: Update `hold` to the maximum of the current `hold` and the profit after buying a stock (`cash - prices[i]`). This accounts for the cost of buying a new stock.
- **Return the maximum profit**, which is stored in `cash` at the end of the simulation. This is because, to maximize profit, you should not hold any stock at the end (sell any stock you have).

### Complexity Analysis

- **Time Complexity**: O(N), where N is the number of days. The solution iterates through the list of prices once.
- **Space Complexity**: O(1), as the solution uses a constant amount of space regardless of the input size.

## Notes

---

 

## Related Videos

---

[https://www.notion.so](https://www.notion.so)