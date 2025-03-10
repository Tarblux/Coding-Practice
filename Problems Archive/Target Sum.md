# Target Sum

Problem: 494
Official Difficulty: medium
Feels Like : medium
My Understanding: Mostly Understand, Needs Review
Topic: array, backtracking, dynamic programming
Link: https://leetcode.com/problems/target-sum/
Completed On : March 8, 2025
Last Review: March 8, 2025
Days Since Review: 1
Neetcode: Yes

## Problem

---

You are given an integer array `nums` and an integer `target`.

You want to build an **expression** out of nums by adding one of the symbols `'+'` and `'-'` before each integer in nums and then concatenate all the integers.

- For example, if `nums = [2, 1]`, you can add a `'+'` before `2` and a `'-'` before `1` and concatenate them to build the expression `"+2-1"`.

Return the number of different **expressions** that you can build, which evaluates to `target`.

**Example 1:**

```
Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3
```

**Example 2:**

```
Input: nums = [1], target = 1
Output: 1
```

**Constraints:**

- `1 <= nums.length <= 20`
- `0 <= nums[i] <= 1000`
- `0 <= sum(nums[i]) <= 1000`
- `1000 <= target <= 1000`

## My Solutions

---

```python
class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:

        @cache
        def dfs(target,index):

            if index == len(nums):
                return 0 if target != 0 else 1

            ways = dfs(target - nums[index],index+1) + dfs(target + nums[index],index+1) 

            return ways

        return dfs(target,0)
        
```

```python

```

## Optimal Solutions

---

**Intuition**

- We want to assign a “+” or “–” sign to each element in `nums` such that the final expression equals a given `target`.
- If the sum of all elements is , and we let  be the sum of elements assigned “+”, and  be the sum of elements assigned “–”, then:
    
    S=∑numsS = \sum nums
    
    PP
    
    NN
    
    P−N=target,P+N=S⟹2P=S+target⟹P=S+target2.  P - N = \text{target}, \quad P + N = S \quad \Longrightarrow \quad 2P = S + \text{target} \quad \Longrightarrow \quad P = \frac{S + \text{target}}{2}.
    
- Thus, counting the ways to reach `target` is the same as counting the ways to form a subset with sum  (assuming  is even and non-negative).
    
    PP
    
    S+targetS + \text{target}
    

---

**Approach**

1. **Check feasibility**: If  is **odd** or , return 0 immediately because it’s impossible to have a non-integer or negative subset sum.
    
    (S+target)(S + \text{target})
    
    (S+target)/2<0(S + \text{target})/2 < 0
    
2. **Transform the problem to “count the number of subsets with sum = P.”**

### 1) Top-Down (Memoized)

- Define a function `countSubsets(i, remain)` = number of ways to pick from `nums[i..]` so that the sum of chosen elements equals `remain`.
- At each index `i`, we can either:
    - **Include** `nums[i]` (if `remain - nums[i]` isn’t negative).
    - **Exclude** `nums[i]`.
- Memoize `(i, remain)` to avoid repeated computations.

### 2) Bottom-Up (Tabulated)

- Create an array `dp` of size `P+1` (where `P = (S + target)//2`), where `dp[x]` = number of ways to form sum `x` using some subset of elements.
- Initialize `dp[0] = 1` (one way to form sum 0: pick nothing).
- For each `num` in `nums`, iterate `x` from `P` down to `num` (to avoid double counting in the same iteration), and update `dp+= dp[x - num]`.

---

## Code

```python
def findTargetSumWays_top_down(nums, target):
    from functools import lru_cache
    total_sum = sum(nums)

    # If S + target is odd or negative after dividing by 2, no solutions
    if (total_sum + target) % 2 != 0 or (total_sum + target) < 0:
        return 0

    # Subset sum we need
    subset_sum = (total_sum + target) // 2

    @lru_cache(None)
    def countSubsets(i, remain):
        if remain == 0:
            return 1
        if i == len(nums) or remain < 0:
            return 0

        # Ways to include nums[i]
        ways_incl = countSubsets(i + 1, remain - nums[i])
        # Ways to exclude nums[i]
        ways_excl = countSubsets(i + 1, remain)

        return ways_incl + ways_excl

    return countSubsets(0, subset_sum)

def findTargetSumWays_bottom_up(nums, target):
    total_sum = sum(nums)

    # If S + target is odd or negative after dividing by 2, no solutions
    if (total_sum + target) % 2 != 0 or (total_sum + target) < 0:
        return 0

    subset_sum = (total_sum + target) // 2

    # dp[x] = number of ways to form sum x
    dp = [0] * (subset_sum + 1)
    dp[0] = 1  # Base case: one way to form 0 sum (pick no elements)

    for num in nums:
        # Go backwards to avoid counting multiple times in one iteration
        for x in range(subset_sum, num - 1, -1):
            dp[x] += dp[x - num]

    return dp[subset_sum]

```

---

## Testcases

```python
# Example 1
nums1 = [1,1,1,1,1]
target1 = 3
# Top-Down
print(findTargetSumWays_top_down(nums1, target1))   # Output: 5
# Bottom-Up
print(findTargetSumWays_bottom_up(nums1, target1))  # Output: 5

# Example 2
nums2 = [1,2,7,9]
target2 = 6
# Top-Down
print(findTargetSumWays_top_down(nums2, target2))   # Output varies
# Bottom-Up
print(findTargetSumWays_bottom_up(nums2, target2))  # Output matches top-down

```

- In the first example, `S = 5`. We need `P = (5 + 3)/2 = 4`. The ways to pick elements that sum to 4 in `[1,1,1,1,1]` is 5.
- In the second example, the exact result depends on the feasible subsets that reach `(S + target)/2`.

## Notes

---

 

## Related Videos

---

[https://www.notion.so](https://www.notion.so)