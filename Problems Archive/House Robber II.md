# House Robber II

Problem: 213
Official Difficulty: medium
Feels Like : medium
My Understanding: Mostly Understand, Needs Review
Topic: array, dynamic programming
Link: https://leetcode.com/problems/house-robber-ii/description/?envType=problem-list-v2&envId=m7475vs1
Completed On : January 14, 2025
Last Review: January 14, 2025
Days Since Review: 47
Neetcode: Yes

## Problem

---

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are **arranged in a circle.** That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and **it will automatically contact the police if two adjacent houses were broken into on the same night**.

Given an integer array `nums` representing the amount of money of each house, return *the maximum amount of money you can rob tonight **without alerting the police***.

**Example 1:**

```
Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
```

**Example 2:**

```
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
```

**Example 3:**

```
Input: nums = [1,2,3]
Output: 3
```

**Constraints:**

- `1 <= nums.length <= 100`
- `0 <= nums[i] <= 1000`

## My Solutions

---

```python
class Solution:
    def rob(self, nums: List[int]) -> int:

        if len(nums) <= 3:

            return max(nums)

        n = len(nums)

        def robRange(low,high):

            size = high - low + 1

            dp = [0] * (size + 1)
            dp[1] = nums[low]

            for i in range(2,size + 1):

                dp[i] = max(dp[i-1], nums[low + i - 1] + dp[i-2])

            return dp[-1]

        
        return max(robRange(0,n-2),robRange(1,n-1))
```

```python

```

## Optimal Solutions

---

**Intuition**

- This is a variation of the classic “House Robber” problem, but the houses are arranged in a circle.
- We can’t rob both the first and last houses because they’re adjacent in a circular arrangement.
- Therefore, we **split** the problem into two linear robberies:
    1. Rob houses in the range  (exclude the last house),
        
        [0,…,n−2][0, \dots, n-2]
        
    2. Rob houses in the range  (exclude the first house),
    and **take the maximum** of these two results.
        
        [1,…,n−1][1, \dots, n-1]
        

---

**Approach**

1. Write a helper function (for both top-down and bottom-up) to solve the **linear** version of the house robber problem.
2. In the main function:
    - If `n == 1`, just return `nums[0]` (only one house).
    - Otherwise, compute:
        - `rob_linear(nums, 0, n-2)` (robbing from house 0 to house n-2)
        - `rob_linear(nums, 1, n-1)` (robbing from house 1 to house n-1)
    - Return the maximum of these two.

---

## Code

```python
def houseRobberII_top_down(nums):
    def rob_linear_top_down(arr):
        memo = {}

        def helper(i):
            if i >= len(arr):
                return 0
            if i in memo:
                return memo[i]
            # Option 1: Skip current house
            skip = helper(i + 1)
            # Option 2: Rob current house + skip the next one
            rob = arr[i] + helper(i + 2)
            memo[i] = max(skip, rob)
            return memo[i]

        return helper(0)

    n = len(nums)
    if n == 0:
        return 0
    if n == 1:
        return nums[0]

    # Case 1: Rob from house 0 to house n-2
    case1 = rob_linear_top_down(nums[:-1])  # exclude last
    # Case 2: Rob from house 1 to house n-1
    case2 = rob_linear_top_down(nums[1:])   # exclude first

    return max(case1, case2)

def houseRobberII_bottom_up(nums):
    def rob_linear_bottom_up(arr):
        if not arr:
            return 0
        if len(arr) == 1:
            return arr[0]

        dp = [0] * len(arr)
        dp[0] = arr[0]
        dp[1] = max(arr[0], arr[1])

        for i in range(2, len(arr)):
            dp[i] = max(dp[i - 1], arr[i] + dp[i - 2])

        return dp[-1]

    n = len(nums)
    if n == 0:
        return 0
    if n == 1:
        return nums[0]

    # Case 1: Rob from house 0 to house n-2
    case1 = rob_linear_bottom_up(nums[:-1])
    # Case 2: Rob from house 1 to house n-1
    case2 = rob_linear_bottom_up(nums[1:])

    return max(case1, case2)

```

---

## Testcase

```
nums = [2, 3, 2]

```

### Test Result

- **Top-Down**: `houseRobberII_top_down([2, 3, 2])` → `3`
- **Bottom-Up**: `houseRobberII_bottom_up([2, 3, 2])` → `3`

---

## Testcase

```
nums = [1, 2, 3, 1]

```

### Test Result

- **Top-Down**: `houseRobberII_top_down([1, 2, 3, 1])` → `4`
- **Bottom-Up**: `houseRobberII_bottom_up([1, 2, 3, 1])` → `4`

---

**Explanation**

- We handle the circle by splitting into two possible linear scenarios.
- In each linear scenario, the standard DP (or memoized recursion) for House Robber applies:
    - **Top-Down**: Recursively choose to skip or rob a house and store results in a memo.
    - **Bottom-Up**: Iteratively build a `dp` array, where `dp[i]` is the max you can rob up to index `i`.
- The final answer is the max between excluding the last house or excluding the first house.

## Notes

---

 

## Related Videos

---

[https://www.notion.so](https://www.notion.so)