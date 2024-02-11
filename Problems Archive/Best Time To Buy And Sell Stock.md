# Best Time To Buy And Sell Stock

Problem: 121
Official Difficulty: easy
Feels Like : medium
Topic: array, dynamic programming
Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
Completed On : December 3, 2023
My Understanding: Needs Review
Last Review: December 3, 2023
Days Since Review: 69

## Problem

---

You are given an array `prices` where `prices[i]` is the price of a given stock on the `ith` day.

You want to maximize your profit by choosing a **single day** to buy one stock and choosing a **different day in the future** to sell that stock.

Return *the maximum profit you can achieve from this transaction*. If you cannot achieve any profit, return `0`.

**Example 1:**

```
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

```

**Example 2:**

```
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.

```

**Constraints:**

- `1 <= prices.length <= 105`
- `0 <= prices[i] <= 104`

## My Solutions

---

This exceeds the space complexity cuz it makes an array for each num which is kinda poor 

```python
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
                
        
        if len(prices) < 2 : 
            
            return 0
        
        profits = {}
        
        max_profits = []
        
        for i in range (len(prices)) :
            
            profits[prices[i]] = []
            
        for i in range (len(prices)-1):
            
            for j in range(i ,len(prices)) : 
                
                if i!=j :
                
                    profit = prices[j] - prices[i]
                
                    profits[prices[i]].append(profit)
        
        return profits
                    
        for val in profits.values() : 
            
            if val :
            
                max_profits.append(max(val))
            
            else : 
                
                continue
                
        if max(max_profits) <= 0 :
        
            return 0
            
        return max(max_profits)
```

### Brenda

```python
class Solution(object):
    def maxProfit(self, prices):
        left = 0;
        right = 0;
        maxprof = 0;
        while( right < len(prices)):
            if(maxprof < (prices[right] - prices[left])):
                maxprof = prices[right] - prices[left]
            if prices[right] < prices[left]:
                left = right
                right = right + 1
            else:
                right = right + 1
        return maxprof

'''
TC = O(N)
SC = O(1)
'''
```

## Optimal Solutions

---

"Best Time to Buy and Sell Stock" is a classic problem in algorithmic trading and dynamic programming. The problem is usually stated as follows:

You are given an array `prices` where `prices[i]` is the price of a given stock on the `i`th day. You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock. Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

### Solution Approach

The most optimal solution for this problem involves a single pass through the array, keeping track of the minimum price seen so far and the maximum profit that can be achieved.

### Algorithm

1. Initialize two variables, `min_price` and `max_profit`. Set `min_price` to the first element in the array and `max_profit` to 0.
2. Iterate over the array starting from the second element. For each price:
    - Update `min_price` if the current price is less than `min_price`.
    - Calculate the profit by subtracting `min_price` from the current price.
    - Update `max_profit` if the calculated profit is greater than `max_profit`.
3. After the loop, `max_profit` will contain the maximum profit that can be achieved.

### Complexity Analysis

- **Time Complexity**: O(n), where n is the number of days. This is because we are going through the list of prices once.
- **Space Complexity**: O(1), as we are only using two variables regardless of the input size.

### Python Implementation

```python
def maxProfit(prices):
    if not prices:
        return 0

    min_price = prices[0]
    max_profit = 0

    for price in prices:
        if price < min_price:
            min_price = price
        elif price - min_price > max_profit:
            max_profit = price - min_price

    return max_profit

```

### Explanation

In this implementation, the `min_price` is updated whenever a lower price is found. The profit is calculated as the difference between the current price and the `min_price`. If this profit is higher than the `max_profit` recorded so far, `max_profit` is updated. The final answer is the `max_profit` after iterating through all the prices.

## Notes

---

 

## Related Videos

---

[https://www.youtube.com/watch?v=1pkOgXD63yU&t=64s](https://www.youtube.com/watch?v=1pkOgXD63yU&t=64s)