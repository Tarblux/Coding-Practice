# Min Cost Climbing Stairs

Problem: 746
Official Difficulty: easy
Feels Like : medium
My Understanding: I Have No Idea, Needs Review
Topic: array, dynamic programming, neetcode150
Link: https://leetcode.com/problems/min-cost-climbing-stairs/description/
Completed On : January 10, 2025
Last Review: January 10, 2025
Days Since Review: 51
Neetcode: Yes

## Problem

---

You are given an integer array `cost` where `cost[i]` is the cost of `ith` step on a staircase. Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index `0`, or the step with index `1`.

Return *the minimum cost to reach the top of the floor*.

**Example 1:**

```
Input: cost = [10,15,20]
Output: 15
Explanation: You will start at index 1.
- Pay 15 and climb two steps to reach the top.
The total cost is 15.
```

**Example 2:**

```
Input: cost = [1,100,1,1,1,100,1,1,100,1]
Output: 6
Explanation: You will start at index 0.
- Pay 1 and climb two steps to reach index 2.
- Pay 1 and climb two steps to reach index 4.
- Pay 1 and climb two steps to reach index 6.
- Pay 1 and climb one step to reach index 7.
- Pay 1 and climb two steps to reach index 9.
- Pay 1 and climb one step to reach the top.
The total cost is 6.
```

**Constraints:**

- `2 <= cost.length <= 1000`
- `0 <= cost[i] <= 999`

## My Solutions

---

```python
class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:

        n = len(cost)
        memo = {}

        # min (15 + 0 , 30 + 0)
        # spot[i] = min (spot[i] + spot[i-1], spot[i] + spot[i-2])

        # [10,15,20] 0
        #           ⬆️
        
        
        def topdown(n): 

            # n is the destination

            if n <= 1:
                return 0

            if n in memo:
                return memo[n]

            memo[n] = min(cost[n-1] + topdown(n-1),cost[n-2] + topdown(n-2))

            return memo[n]

        return topdown(n)
```

```python
        cost.append(0)
        n = len(cost)
        
        memo = {}

        def mincost(n):

            # mincost(n) is the minimum cost to reach a step(n)

            if n < 2:
                cases  = [0,cost[0]]
                return cases[n]

            if n in memo:
                return memo[n]

            memo[n] = cost[n-1] + min (mincost(n-1) ,mincost(n-2))

            return memo[n]

        return mincost(n)
```

```python
class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:

        n = len(cost)
        dp = [0] * (n+2)
        dp[1] = cost[0]
        dp[2] = cost[1]

        cost.append(0)

        for i in range(3,n+2):

            dp[i] = cost[i-1]  + min(dp[i-1],dp[i-2])

        return dp[n+1]
```

## Optimal Solutions

---

# Intuition

1. **Choice at Every Step**
    
    When you stand on step `i`, you pay `cost[i]`, and then you can jump either:
    
    - **1 step** ahead (to `i + 1`), or
    - **2 steps** ahead (to `i + 2`).
    Whichever choice leads to a lower *total cost* should be taken.
2. **Equivalent to "Climb from Either Step 0 or 1"**
    
    Before you start climbing, you can effectively place yourself on step 0 or step 1, because you can choose the cheaper cost route from either of these starting positions.
    
3. **Optimal Substructure**
    
    If `dp[i]` represents the minimum cost to get onto step `i`, then to get onto step `i`, you must come from either `i-1` or `i-2`. The cost at `i` is then added to the minimum of these two possible previous states.
    

---

# Approach

We’ll explore two ways to implement this logic: **Top-Down (Memoized)** and **Bottom-Up (Tabulated)**.

## 1. Top-Down (Memoized) DP

### Step-by-Step

1. **Define a recursive function** `dfs(i)` that returns the minimum cost to reach the top starting from step `i`.
2. From step `i`, you can pay `cost[i]` and jump to:
    - Step `i+1`
    - Step `i+2`
3. The cost at `i` is therefore:
\text{total_cost}(i) = cost[i] + \min(\text{dfs}(i+1), \text{dfs}(i+2))
4. **Memoize** `dfs(i)` so that once we compute the minimum cost from step `i`, we don’t recalculate it.
5. The answer is the minimum cost of starting from step `0` or `1`:
    
    min(dfs(0),dfs(1))
    

### Code

```python
def minCostClimbingStairs_top_down(cost):
    n = len(cost)
    memo = {}

    def dfs(i):
        # If we've gone past the last step, no additional cost.
        if i >= n:
            return 0

        # If already computed, use the cached value.
        if i in memo:
            return memo[i]

        # Cost from i + choice of one-step or two-step jump
        one_step = cost[i] + dfs(i + 1)
        two_step = cost[i] + dfs(i + 2)

        memo[i] = min(one_step, two_step)
        return memo[i]

    # We can start at step 0 or step 1
    return min(dfs(0), dfs(1))

```

### Explanation

- **Recursive Exploration**: We recursively check all possible ways to reach the top from step `i`, accumulating the cost.
- **Memoization**: We store the results in `memo`. This cuts down repeated computations.
- **Base Case**: If `i >= n`, we have passed the last step, so cost is 0.

---

## 2. Bottom-Up (Tabulated) DP

### Step-by-Step

1. **Create an array `dp`** of length `n`, where `dp[i]` represents the minimum cost to stand on step `i`.
2. **Initialization**:
    - `dp[0] = cost[0]` (minimum cost to stand on the first step is just `cost[0]`)
    - `dp[1] = cost[1]` (minimum cost to stand on the second step is just `cost[1]`)
3. **Iterate through the steps** from `i = 2` to `n-1`:
    
    dp[i]=cost[i]+min⁡(dp[i−1],dp[i−2])dp[i] = cost[i] + \min(dp[i-1], dp[i-2])
    
4. **Result**: The minimum cost to get to the "top" (just beyond the last step) can be from either step `n-1` or step `n-2`, so we return:
    
    min⁡(dp[n−1],dp[n−2])\min(dp[n-1], dp[n-2])
    

### Code

```python
def minCostClimbingStairs_bottom_up(cost):
    n = len(cost)

    if n == 0:
        return 0
    if n == 1:
        return cost[0]

    dp = [0] * n
    dp[0] = cost[0]
    dp[1] = cost[1]

    for i in range(2, n):
        dp[i] = cost[i] + min(dp[i - 1], dp[i - 2])

    return min(dp[n - 1], dp[n - 2])

```

### Explanation

- **Tabulation**: We build `dp` from the bottom up, starting from known costs at indices 0 and 1.
- **Transition**: Each step’s minimum cost depends on the min cost of the previous two steps.
- **Final Answer**: Minimum of the last two steps’ costs represents the cost to stand on either of them before jumping off to the top.

---

## Complexity Analysis

- **Time Complexity**:  for both top-down and bottom-up, since each step’s result is computed once.
    
    O(n)O(n)
    
- **Space Complexity**:
    - **Top-Down**:  for the recursion stack (worst-case) + memo dictionary.
        
        O(n)O(n)
        
    - **Bottom-Up**:  for the `dp` array.
        
        O(n)O(n)
        

---

### Summary

- **Intuition**: At each step, you decide whether to pay the cost for that step and move 1 step or 2 steps ahead. You want to minimize the total payment.
- **Approach**: Dynamic programming is perfect here because each step’s cost depends on previously computed costs.
- **Implementation**: Use either Top-Down with memoization or Bottom-Up with tabulation to avoid recomputing subproblems and achieve  time.
    
    O(n)O(n)
    

These approaches efficiently compute the minimum total cost to climb the staircase with the given costs.

## Notes

---

 

## Related Videos

---

[https://youtu.be/ktmzAZWkEZ0](https://youtu.be/ktmzAZWkEZ0)