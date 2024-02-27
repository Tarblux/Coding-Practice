# Calculate Money in Leetcode Bank

Problem: 1716
Official Difficulty: easy
My Understanding: Fully Understand
Feels Like : medium
Topic: Math, simulation
Link: https://leetcode.com/problems/calculate-money-in-leetcode-bank/description/
Completed On : February 23, 2024
Last Review: February 23, 2024
Days Since Review: 3

## Problem

---

Hercy wants to save money for his first car. He puts money in the Leetcode bank **every day**.

He starts by putting in `$1` on Monday, the first day. Every day from Tuesday to Sunday, he will put in `$1` more than the day before. On every subsequent Monday, he will put in `$1` more than the **previous Monday**.

Given `n`, return *the total amount of money he will have in the Leetcode bank at the end of the* `nth` *day.*

**Example 1:**

```
Input: n = 4
Output: 10
Explanation: After the 4th day, the total is 1 + 2 + 3 + 4 = 10.
```

**Example 2:**

```
Input: n = 10
Output: 37
Explanation: After the 10th day, the total is (1 + 2 + 3 + 4 + 5 + 6 + 7) + (2 + 3 + 4) = 37. Notice that on the 2nd Monday, Hercy only puts in $2.
```

**Example 3:**

```
Input: n = 20
Output: 96
Explanation: After the 20th day, the total is (1 + 2 + 3 + 4 + 5 + 6 + 7) + (2 + 3 + 4 + 5 + 6 + 7 + 8) + (3 + 4 + 5 + 6 + 7 + 8) = 96.
```

**Constraints:**

- `1 <= n <= 1000`

## My Solutions

---

```python
class Solution:
    def totalMoney(self, n: int) -> int:

        if n == 0 :

            return 0

        last_monday = 1

        leetcode_bank = [1]

        for i in range(1,n) : 

            day = i % 7 

            if day == 0 : 

                last_monday += 1

                leetcode_bank.append(last_monday)

                continue

            leetcode_bank.append(leetcode_bank[i-1] + 1)

        return sum(leetcode_bank)
```

**this would be if you add as you go :** 

To modify the given code to calculate the total money without appending to an array, you can directly accumulate the total money as you iterate through the days. Here's how you can do it:

```python
class Solution:
    def totalMoney(self, n: int) -> int:
        if n == 0:
            return 0

        last_monday = 1
        total_money = 1  # Initialize total money with the money saved on the first day

        for i in range(1, n):
            day = i % 7

            if day == 0:
                last_monday += 1  # It's a new week, increase the money saved on Monday by 1
                total_money += last_monday  # Add this Monday's saving to the total
            else:
                # Add money saved on the current day, which is 1 more than the previous day
                total_money += (last_monday + day)

        return total_money

```

### Explanation:

- **Initialization**: Start with `last_monday` set to 1, representing the money saved on the first Monday. `total_money` is also initialized to 1, representing the total money saved on the first day.
- **Iterate Through Days**: For each day `i` from 1 to `n-1`, calculate the day of the week (`day = i % 7`). If `day == 0`, it's a new week, so increment `last_monday` by 1 and add it to `total_money`. For other days, add `(last_monday + day)` to `total_money`, which represents saving 1 more than the previous day within the same week.
- **Accumulate Total Money**: Instead of storing daily savings in an array, directly add each day's savings to `total_money`.
- **Return Total Money**: After iterating through all `n` days, return `total_money` as the result.

This approach calculates the total savings without needing an array to track daily amounts, thereby reducing space complexity from O(n) to O(1), while maintaining O(n) time complexity.

## Optimal Solutions

---

### Solution Approach

1. **Weekly Pattern**: Notice that the amount saved in the first week is `1 + 2 + 3 + 4 + 5 + 6 + 7 = 28`. For subsequent weeks, this pattern repeats, but starting from a higher value than $1.
2. **Complete Weeks Calculation**: Calculate the total savings for complete weeks (7 days). Each new week starts with an amount that is $1 more than the start of the previous week.
3. **Partial Week Calculation**: Calculate the savings for the remaining days after the last complete week.

### Python Implementation

```python
class Solution:
    def totalMoney(self, n: int) -> int:
        # Calculate the number of complete weeks and the remaining days
        complete_weeks, remaining_days = divmod(n, 7)

        # Calculate savings for complete weeks
        # First week savings: 1+2+3+4+5+6+7 = 28
        # Incremental savings each week due to the pattern
        total_savings = (28 * complete_weeks) + (complete_weeks * (complete_weeks - 1) // 2) * 7

        # Calculate savings for the remaining days in the partial week
        # Starting amount for the partial week is increased by the number of complete weeks
        for day in range(remaining_days):
            total_savings += (1 + complete_weeks) + day

        return total_savings
```

### Explanation

- **Complete Weeks**: The total savings for complete weeks are calculated using the formula for the sum of an arithmetic series, considering that each week starts saving $1 more than the start of the previous week.
- **Partial Week**: For the remaining days, calculate each day's savings based on how much more than $1 is saved on the corresponding Monday. The starting amount for the days of the partial week increases by the number of complete weeks.
- **Total Savings**: Sum the savings from complete weeks and the remaining days for the total savings.

This solution efficiently calculates the total amount of money saved in the Leetcode bank after N days, with a time complexity of O(1) due to the arithmetic nature of the solution, significantly optimizing over iterative approaches.

## Notes

---

 

## Related Videos

---

[https://www.youtube.com/watch?v=tKK7gvPCQfs](https://www.youtube.com/watch?v=tKK7gvPCQfs)