# Climbing Stairs

Problem: 70
Official Difficulty: easy
Feels Like : medium
Topic: dynamic programming
Link: https://leetcode.com/problems/climbing-stairs/
Completed On : December 3, 2023
My Understanding: Mostly Understand
Last Review: December 3, 2023
Days Since Review: 69

## Problem

---

You are climbing a staircase. It takes `n` steps to reach the top.

Each time you can either climb `1` or `2` steps. In how many distinct ways can you climb to the top?

**Example 1:**

```
Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
```

**Example 2:**

```
Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
```

## My Solutions

---

```python
class Solution:
    def climbStairs(self, n: int) -> int:
        
        if n < 2 : 
            
            return 1 
        
        num_wys = [1] * (n + 1)
        
        num_wys [0] = 1
        num_wys [1] = 1
        
        for i  in range (2,n+1):
        
            num_wys[i] = num_wys[i-2] + num_wys[i-1]
            
        return num_wys[n]
```

**Zwea**

```python
def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        memo = {}
        def helper(k):
            if k < 0:
                return 0
            if k == 0:
                return 1       
            if k not in memo:
                memo[k] = helper(k-2) + helper(k-1)
            return memo[k]
        return helper(n)
```

## Optimal Solutions

---

"Climbing Stairs" is a well-known problem in the realm of dynamic programming and combinatorics. The problem statement is typically as follows:

You are climbing a staircase. It takes `n` steps to reach the top. Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

### Solution Approach

This problem is a variation of the Fibonacci sequence. The number of ways to reach the `n`th step is equal to the sum of the ways to reach the `(n-1)`th step and the `(n-2)`th step, because from each of these steps, you can take a single step or a double step to reach the `n`th step.

### Algorithm

1. If `n` is 1 or 2, the number of ways is `n` itself (1 way for 1 step, 2 ways for 2 steps).
2. Initialize two variables, say `first` and `second`, to represent the number of ways to reach the first and second steps, respectively. Set `first = 1` and `second = 2`.
3. Use a loop to calculate the number of ways to reach each subsequent step until `n`. For each `i` from 3 to `n`:
    - The number of ways to reach the `i`th step is `first + second`.
    - Update `first` to `second`, and `second` to the current number of ways.
4. The value in `second` after the loop is the total number of ways to reach the `n`th step.

### Complexity Analysis

- **Time Complexity**: O(n), because we iterate through the steps once.
- **Space Complexity**: O(1), as we are using a constant amount of space.

### Python Implementation

```python
def climbStairs(n):
    if n == 1:
        return 1
    if n == 2:
        return 2

    first, second = 1, 2

    for i in range(3, n + 1):
        third = first + second
        first, second = second, third

    return second

```

### Explanation

In this solution, the `first` and `second` variables initially store the number of ways to reach the first and second steps. As we loop through the rest of the steps, we update these variables to reflect the number of ways to reach the current step (`third = first + second`). After reaching the `n`th step, `second` holds the total number of distinct ways to climb to the top.

## Notes

---

 

## Related Videos

---

[https://www.youtube.com/watch?v=Y0lT9Fck7qI](https://www.youtube.com/watch?v=Y0lT9Fck7qI)