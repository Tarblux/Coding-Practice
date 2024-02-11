# Richest Customer Wealth

Problem: 1672
Official Difficulty: easy
Feels Like : easy
Topic: Matrix, array
Link: https://leetcode.com/problems/richest-customer-wealth/description/
Completed On : January 29, 2024
My Understanding: Fully Understand
Last Review: January 29, 2024
Days Since Review: 12

## Problem

---

You are given an `m x n` integer grid `accounts` where `accounts[i][j]` is the amount of money the `ith` customer has in the `jth` bank. Return *the **wealth** that the richest customer has.*

A customer's **wealth** is the amount of money they have in all their bank accounts. The richest customer is the customer that has the maximum **wealth**.

**Example 1:**

```
Input: accounts = [[1,2,3],[3,2,1]]
Output: 6
Explanation:1st customer has wealth = 1 + 2 + 3 = 6
2nd customer has wealth = 3 + 2 + 1 = 6
Both customers are considered the richest with a wealth of 6 each, so return 6.
```

**Example 2:**

```
Input: accounts = [[1,5],[7,3],[3,5]]
Output: 10
Explanation:
1st customer has wealth = 6
2nd customer has wealth = 10
3rd customer has wealth = 8
The 2nd customer is the richest with a wealth of 10.
```

**Example 3:**

```
Input: accounts = [[2,8,7],[7,1,3],[1,9,5]]
Output: 17
```

**Constraints:**

- `m == accounts.length`
- `n == accounts[i].length`
- `1 <= m, n <= 50`
- `1 <= accounts[i][j] <= 100`

## My Solutions

---

```python
class Solution:
    def maximumWealth(self, accounts: List[List[int]]) -> int:

        richest = 0

        def sum(array) : 

            sum = 0

            for num in array : 

                sum += num

            return sum

        for acc in accounts : 

            cur_wealth = sum(acc)

            richest = max(richest,cur_wealth)

        return richest
```

```python
class Solution:
    def maximumWealth(self, accounts: List[List[int]]) -> int:

        richest_heap = []

        for account in accounts : 

            heapq.heappush(richest_heap , -sum(account))

        return - richest_heap[0]
```

## Optimal Solutions

---

### Explain Like I am Five (ELI5)

---

## Notes

---

 

## Related Videos

---

[https://www.notion.so](https://www.notion.so)