# Average Waiting Time

Problem: 1701
Official Difficulty: medium
Feels Like : medium
My Understanding: Mostly Understand
Topic: array, simulation
Link: https://leetcode.com/problems/average-waiting-time/description/
Completed On : July 9, 2024
Last Review: July 9, 2024
Days Since Review: 2

## Problem

---

There is a restaurant with a single chef. You are given an array `customers`, where `customers[i] = [arrivali, timei]:`

- `arrivali` is the arrival time of the `ith` customer. The arrival times are sorted in **non-decreasing** order.
- `timei` is the time needed to prepare the order of the `ith` customer.

When a customer arrives, he gives the chef his order, and the chef 
starts preparing it once he is idle. The customer waits till the chef 
finishes preparing his order. The chef does not prepare food for more 
than one customer at a time. The chef prepares food for customers **in the order they were given in the input**.

Return *the **average** waiting time of all customers*. Solutions within `10-5` from the actual answer are considered accepted.

**Example 1:**

```
Input: customers = [[1,2],[2,5],[4,3]]
Output: 5.00000
Explanation:
1) The first customer arrives at time 1, the chef takes his order and starts preparing it immediately at time 1, and finishes at time 3, so the waiting time of the first customer is 3 - 1 = 2.
2) The second customer arrives at time 2, the chef takes his order and starts preparing it at time 3, and finishes at time 8, so the waiting time of the second customer is 8 - 2 = 6.
3) The third customer arrives at time 4, the chef takes his order and starts preparing it at time 8, and finishes at time 11, so the waiting time of the third customer is 11 - 4 = 7.
So the average waiting time = (2 + 6 + 7) / 3 = 5.
```

**Example 2:**

```
Input: customers = [[5,2],[5,4],[10,3],[20,1]]
Output: 3.25000
Explanation:
1) The first customer arrives at time 5, the chef takes his order and starts preparing it immediately at time 5, and finishes at time 7, so the waiting time of the first customer is 7 - 5 = 2.
2) The second customer arrives at time 5, the chef takes his order and starts preparing it at time 7, and finishes at time 11, so the waiting time of the second customer is 11 - 5 = 6.
3) The third customer arrives at time 10, the chef takes his order and starts preparing it at time 11, and finishes at time 14, so the waiting time of the third customer is 14 - 10 = 4.
4) The fourth customer arrives at time 20, the chef takes his order and starts preparing it immediately at time 20, and finishes at time 21, so the waiting time of the fourth customer is 21 - 20 = 1.
So the average waiting time = (2 + 6 + 4 + 1) / 4 = 3.25.
```

**Constraints:**

- `1 <= customers.length <= 105`
- `1 <= arrivali, timei <= 104`
- `arrivali <= arrivali+1`

## My Solutions

---

```python
class Solution:
    def averageWaitingTime(self, customers: List[List[int]]) -> float:

        n = len(customers)
        total_wait = customers[0][1]
        cur_time = customers[0][0] + customers[0][1]

        for i in range(1,len(customers)):

            arrival , cook_time = customers[i]

            cur_time = max(cur_time,arrival)

            delay = cur_time - arrival
            total_wait += delay + cook_time 
            cur_time += cook_time

        return total_wait / n
```

```python

```

## Optimal Solutions

---

### Solution

To solve this problem, we need to simulate the process of handling each customer in sequence. We'll keep track of the current time, the finish time of each order, and accumulate the waiting times to compute the average at the end.

### Python Code

```python
from typing import List

class Solution:
    def averageWaitingTime(self, customers: List[List[int]]) -> float:
        current_time = 0
        total_waiting_time = 0

        for arrival, time in customers:
            if current_time < arrival:
                current_time = arrival
            finish_time = current_time + time
            waiting_time = finish_time - arrival
            total_waiting_time += waiting_time
            current_time = finish_time

        return total_waiting_time / len(customers)

# Example usage
sol = Solution()
print(sol.averageWaitingTime([[1, 2], [2, 5], [4, 3]]))  # Output: 5.0
print(sol.averageWaitingTime([[5, 2], [5, 4], [10, 3]]))  # Output: 4.333333333333333

```

### Explanation

1. **Initialization**:
    - `current_time` keeps track of the time at which the cook will be free to start the next order.
    - `total_waiting_time` accumulates the waiting time of each customer.
2. **Processing Each Customer**:
    - For each customer, check if the cook is free before the customer arrives. If so, update the `current_time` to the customer's arrival time.
    - Calculate `finish_time` as the sum of `current_time` and the `time` needed for the order.
    - Calculate `waiting_time` as `finish_time - arrival`.
    - Add `waiting_time` to `total_waiting_time`.
    - Update `current_time` to `finish_time` for processing the next customer.
3. **Compute Average Waiting Time**:
    - Divide `total_waiting_time` by the number of customers to get the average waiting time.

### Time Complexity Analysis

- **Time Complexity**: `O(n)`, where `n` is the number of customers. We iterate through the list of customers once.
- **Space Complexity**: `O(1)`. We use a constant amount of extra space for variables.

This solution efficiently computes the average waiting time for all customers using a simple simulation approach.

## Leetcode Editorial

### Intuition

The chef prepares customer orders as soon as they arrive at the restaurant, provided he isn't already busy. He never takes a rest if there is a queue of pending orders. Therefore, the average waiting time will always be minimal. Also, we are not allowed to change the order of customers. So, we can simulate the process in the provided order, maintaining the time when each customer receives their order. Subtracting this time from the customer's arrival time gives us the 
waiting time for that customer.

There is no waiting time for the first customer apart from the preparation time. Let's say another customer arrives while the chef is preparing this order. How much does this customer need to wait to place their order? The waiting time is given by the time gap between their arrival time and when the first customer receives his order.

In other words, the chef can only start preparing a customer's order when he is idle or when the customer has arrived at the restaurant, whichever happens later. Adding this to the preparation time gives us the time when the customer receives their order. The waiting time for the customer is given by the difference between the order's delivery 
time and the customer's arrival time.

Using this approach, we can calculate the sum of the waiting time for all the customers. Dividing it by the total number of customers gives us the average waiting time per customer. Don't forget to calculate this average in a floating-point/double data type for precision.

### Algorithm

1. Initialize integers `nextIdleTime` and `netWaitTime` with 0.
2. Iterate through the `customers` array:
    - Set `nextIdleTime` as the maximum of customer's arrival time and the current value of `nextIdleTime` plus the order preparation time.
    - Increment `netWaitTime` by the difference of `nextIdleTime` and the customer's arrival time.
3. Divide the `netWaitTime` by `customers.size` to get the `averageWaitTime`.
4. Return the `averageWaitTime`.

```python
class Solution:
    def averageWaitingTime(self, customers: List[List[int]]) -> float:
        next_idle_time = 0
        net_wait_time = 0

        for customer in customers:
            # The next idle time for the chef is given by the time of delivery
            # of current customer's order.
            next_idle_time = max(customer[0], next_idle_time) + customer[1]

            # The wait time for the current customer is the difference between
            # his delivery time and arrival time.
            net_wait_time += next_idle_time - customer[0]

        # Divide by total customers to get average.
        average_wait_time = net_wait_time / len(customers)
        return average_wait_time
```

## Notes

---

## Related Videos

---

[https://www.youtube.com/watch?v=2fN7uIgCIBA](https://www.youtube.com/watch?v=2fN7uIgCIBA)