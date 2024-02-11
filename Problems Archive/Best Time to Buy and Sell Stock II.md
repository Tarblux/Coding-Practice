# Best Time to Buy and Sell Stock II

Problem: 122
Official Difficulty: medium
Topic: array, dynamic programming, greedy
Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
Completed On : November 7, 2023
My Understanding: Mostly Understand
Last Review: November 7, 2023
Days Since Review: 95

## Problem

---

You are given an integer array `prices` where `prices[i]` is the price of a given stock on the `ith` day.

On each day, you may decide to buy and/or sell the stock. You can only hold **at most one** share of the stock at any time. However, you can buy it then immediately sell it on the **same day**.

Find and return *the **maximum** profit you can achieve*.

## My Solutions

---

```python
class Solution(object):
    def maxProfit(self, prices):
        
        
        profit = 0 
        
        if len (prices) < 2 : 
            return profit
        
        for i in range(0 , len(prices)-1) :
            
            if prices[i+1] > prices[i] :
                
                profit += prices [i+1] - prices[i]
                
        
        return profit
```

```python

```

## Optimal Solutions

---

The "Best Time to Buy and Sell Stock II" problem is a classic example of a greedy algorithm. The task is to find the maximum profit you can achieve by making as many transactions as you like (i.e., buy one and sell one share of the stock multiple times). However, you cannot engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

In this problem, the key insight is that we can sum up all the positive differences between consecutive days. In other words, whenever the price of the stock goes up from one day to the next, we consider it a profit and add it to our total profit.

Here's how you can do it:

1. Initialize a variable `profit` to zero.
2. Iterate over the array of prices.
3. For each day, if the price of the stock is higher than the previous day, add the difference to the `profit`.
4. Return the total `profit`.

The intuition behind this approach is that summing up all the positive differences is equivalent to buying at each local minimum and selling at each local maximum.

Here's the Python implementation:

```python
def maxProfit(prices):
    profit = 0
    for i in range(1, len(prices)):
        if prices[i] > prices[i - 1]:
            profit += prices[i] - prices[i - 1]
    return profit

# Example usage
prices = [7, 1, 5, 3, 6, 4]
print(maxProfit(prices))  # Output will be 7 (buy at 1, sell at 5; buy at 3, sell at 6)

```

In this code:

- We loop through the `prices` array starting from the second element.
- If a price is higher than the previous day's price, we consider it a profit opportunity and add the difference to `profit`.
- Finally, we return the total `profit`.

The time complexity of this solution is O(n), where n is the number of days (length of the `prices` array), as we need to iterate through the array once. The space complexity is O(1), as we only use a variable to keep track of the profit and do not use any additional data structures. This makes the solution both time and space efficient.

## Notes

## Related Videos

---

[https://www.youtube.com/watch?v=3SJ3pUkPQMc](https://www.youtube.com/watch?v=3SJ3pUkPQMc)