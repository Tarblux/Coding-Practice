# Coin Change II

Problem: 518
Official Difficulty: medium
Feels Like : hard
My Understanding: Needs Review
Topic: array, dynamic programming
Link: https://leetcode.com/problems/coin-change-ii/description/
Completed On : March 8, 2025
Last Review: March 8, 2025
Days Since Review: 1
Neetcode: Yes

## Problem

---

You are given an integer array `coins` representing coins of different denominations and an integer `amount` representing a total amount of money.

Return *the number of combinations that make up that amount*. If that amount of money cannot be made up by any combination of the coins, return `0`.

You may assume that you have an infinite number of each kind of coin.

The answer is **guaranteed** to fit into a signed **32-bit** integer.

**Example 1:**

```
Input: amount = 5, coins = [1,2,5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
```

**Example 2:**

```
Input: amount = 3, coins = [2]
Output: 0
Explanation: the amount of 3 cannot be made up just with coins of 2.
```

**Example 3:**

```
Input: amount = 10, coins = [10]
Output: 1
```

**Constraints:**

- `1 <= coins.length <= 300`
- `1 <= coins[i] <= 5000`
- All the values of `coins` are **unique**.
- `0 <= amount <= 5000`

## My Solutions

---

Gets TLE becuase of function calls overhead

```python
class Solution:
    def change(self, amount: int, coins: List[int]) -> int:

        @cache
        def dfs(amount,index):

            if amount == 0:
                return 1

            if amount < 0 or index == len(coins):
                return 0

            ways = 0
            for i in range(index,len(coins)):
                ways += dfs(amount-coins[i],i)

            return ways

        return dfs(amount,0)
```

This solution uses a recursive, depth-first search (DFS) with memoization (caching) to count the number of ways to make up a given amount using a list of coins, where each coin can be used an unlimited number of times. The key idea is to build the solution by exploring different coin choices while ensuring that combinations are counted only once. Here’s a thorough breakdown of the approach:

---

### Function Overview

- **Function Signature:**
    
    The function `dfs(amount, index)` returns the number of combinations to form the remaining `amount` using coins starting from the given `index` in the coins list.
    
    - `amount`: the remaining value we need to form.
    - `index`: the current starting point in the coins list from which we are allowed to pick coins. This enforces an order so that combinations aren’t counted multiple times.
- **Caching:**
    
    The `@cache` decorator (which is equivalent to memoization) stores results for specific pairs of `(amount, index)`. This avoids recalculating the number of combinations for the same subproblem repeatedly, thereby improving efficiency.
    

---

### Base Cases

1. **Exact Match (amount == 0):**
    
    ```python
    if amount == 0:
        return 1
    
    ```
    
    When the remaining amount is exactly 0, it means we have found a valid combination of coins that sums up to the target amount. Thus, we return 1 to count this valid way.
    
2. **Overshot or Out of Coins (amount < 0 or index == len(coins)):**
    
    ```python
    if amount < 0 or index == len(coins):
        return 0
    
    ```
    
    - If `amount < 0`, we’ve overshot the target (used coins that add up to more than the desired amount), so this path cannot lead to a valid combination.
    - If `index == len(coins)`, it means there are no more coins left to consider while we still have a positive amount remaining. This path also yields no valid combinations.

---

### Recursive Case

- **Iterate Over Coins Starting at Current Index:**
    
    ```python
    ways = 0
    for i in range(index, len(coins)):
        ways += dfs(amount - coins[i], i)
    
    ```
    
    For each coin available (from `coins[index]` to the last coin):
    
    - **Subtract the Coin’s Value:**
        
        We reduce the current `amount` by the value of the coin `coins[i]`. This represents choosing the coin `coins[i]` as part of the current combination.
        
    - **Allow Reuse of the Same Coin:**
        
        Notice that in the recursive call `dfs(amount - coins[i], i)`, the index `i` is passed again rather than `i+1`. This means that after choosing coin `coins[i]`, we are allowed to choose it again (since coins are available in unlimited quantity).
        
    - **Maintain Order to Avoid Duplicates:**
        
        The loop iterates from `index` to `len(coins)`. By doing so, we ensure that we never go back to coins that have already been considered in previous steps. This avoids counting the same set of coins in different orders. For example, `[1,2]` and `[2,1]` would be considered the same combination because the recursion always picks coins in a non-decreasing order of their indices.
        
- **Accumulate the Ways:**
    
    Each recursive call returns the number of ways to form the remaining amount with the allowed coins. The sum of these values gives the total number of combinations for the current state.
    

---

### Final Return

- The solution starts the DFS from the full amount and with the first coin (index 0):

This initiates the process, and the final result is the number of ways to form the entire amount using all available coins (in a specific order to avoid duplicates).
    
    ```python
    return dfs(amount, 0)
    
    ```
    

---

### Summary

- **Recursion with Ordering:**
    
    By using an `index` to control which coins can be used, the solution avoids counting the same combination multiple times.
    
- **Unlimited Coin Use:**
    
    The recursive call passes the same index when a coin is chosen, which allows that coin to be used again.
    
- **Memoization:**
    
    The caching ensures that each unique subproblem `(amount, index)` is solved only once, greatly enhancing the performance.
    

This approach is an efficient way to solve the Coin Change II problem by combining recursion, ordering to avoid duplicates, and memoization to handle overlapping subproblems.

## TLE REASON

The algorithm explores every possible combination recursively and, even with caching, it can still generate a huge number of states when the amount is large or the coins are small. Here are some reasons for the time limit exceeded (TLE):

1. **Huge State Space:**
    
    The DFS function is defined with parameters (amount,index)(\text{amount}, \text{index}). Even though there are at most (amount+1)×(len(coins)+1)(\text{amount}+1) \times (\text{len(coins)}+1) distinct states, if the amount is large (for example, 5000) and coins are small (like 1), the number of recursive calls—even with memoization—can be enormous, leading to significant overhead.
    
2. **Recursion Overhead in Python:**
    
    Python’s recursion isn’t very fast, and every recursive call adds function call overhead. Even if many subproblems are cached, the repeated function call overhead and the loop in every call can add up.
    
3. **Inefficient Traversal:**
    
    The DFS structure you have iterates over every coin starting from the current index for each recursive call. Although this ordering avoids duplicates, it still makes many calls that add up in the worst-case scenario.
    

Because of these reasons, the recursive approach with caching (while conceptually correct) may be too slow for some test cases on platforms like LeetCode, which is why you might be getting a time limit exceeded error.

---

### What Can You Do?

For problems like Coin Change II, a bottom-up dynamic programming solution is usually more efficient. A typical iterative solution looks like this:

```python
class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        dp = [0] * (amount + 1)
        dp[0] = 1

        for coin in coins:
            for j in range(coin, amount + 1):
                dp[j] += dp[j - coin]

        return dp[amount]

```

This solution fills in a dp table iteratively, which avoids recursion overhead and often runs much faster in Python for the given constraints.

---

### Summary

- **DFS with caching** is conceptually correct but can run into performance issues due to a very large state space and Python’s recursion overhead.
- **Bottom-up DP** typically has lower overhead and is more efficient for the coin change problem in Python.

Using an iterative dynamic programming approach should help you avoid the TLE issue.

This solution uses a bottom-up dynamic programming approach to count the number of ways to make up the target amount using the given coins. Here’s a detailed explanation:

---

### DP Array Initialization

- **dp = [0] * (amount + 1):**
    
    This creates a list `dp` of length `amount + 1` where each index `j` represents the number of ways to form the amount `j` using the coins seen so far.
    
- **dp[0] = 1:**
    
    There is exactly one way to form the amount 0: by choosing no coins. This acts as the base case for our DP.
    

---

### Outer Loop: Iterating Over Coins

```python
for coin in coins:

```

- The outer loop goes through each coin in the given list. The order of coins is important because it ensures that each combination of coins is only counted once. By processing coins one at a time, we prevent different orders of the same combination from being counted as separate solutions.

---

### Inner Loop: Updating the DP Array

```python
for j in range(coin, amount + 1):
    dp[j] += dp[j - coin]

```

- **Loop Range (coin, amount + 1):**
    
    We start from `coin` because amounts smaller than the coin's value cannot include that coin. For example, if the coin is 5, there’s no way to use it to make amounts 0 through 4.
    
- **dp[j] += dp[j - coin]:**
    
    Here’s what happens in each iteration:
    
    - `dp[j - coin]` represents the number of ways to form the amount `j - coin` using the coins processed so far.
    - If you have a valid way to form `j - coin`, then by adding the current coin (which has value `coin`), you can form the amount `j`.
    - Therefore, you add the number of ways to form `j - coin` to the current count of ways to form `j`.

This update step is the heart of the solution. It builds on smaller subproblems (forming smaller amounts) to solve for larger amounts.

---

### Final Result

- **return dp[amount]:**
After processing all coins and updating the dp array, `dp[amount]` contains the total number of ways to form the target `amount` using any combination of the provided coins.

---

### Summary

1. **Initialization:**
    
    Start with `dp[0] = 1` because there’s one way to have zero amount.
    
2. **Coin Processing:**
    
    Process each coin one by one. For each coin, iterate through possible amounts from the coin’s value up to the target amount.
    
3. **Dynamic Programming Update:**
    
    For each amount `j`, add the number of ways to form `j - coin` to `dp[j]`, which effectively counts the combinations that include the current coin.
    
4. **Result:**
    
    The answer is found in `dp[amount]`, representing the total number of unique combinations to form that amount.
    

This bottom-up approach avoids recursion and efficiently computes the result using iterative updates, which is why it is well-suited for solving the Coin Change II problem.

## Optimal Solutions

---

## Notes

---

 

## Related Videos

---

[https://www.notion.so](https://www.notion.so)