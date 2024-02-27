# Time Needed to Buy Tickets

Problem: 2073
Official Difficulty: easy
My Understanding: Needs Review
Feels Like : medium
Topic: Queue, array, simulation
Link: https://leetcode.com/problems/time-needed-to-buy-tickets/description/
Completed On : February 26, 2024
Last Review: February 26, 2024
Days Since Review: 0

## Problem

---

There are `n` people in a line queuing to buy tickets, where the `0th` person is at the **front** of the line and the `(n - 1)th` person is at the **back** of the line.

You are given a **0-indexed** integer array `tickets` of length `n` where the number of tickets that the `ith` person would like to buy is `tickets[i]`.

Each person takes **exactly 1 second** to buy a ticket. A person can only buy **1 ticket at a time** and has to go back to **the end** of the line (which happens **instantaneously**) in order to buy more tickets. If a person does not have any tickets left to buy, the person will **leave** the line.

Return *the **time taken** for the person at position* `k` ***(0-indexed)*** *to finish buying tickets*.

**Example 1:**

```
Input: tickets = [2,3,2], k = 2
Output: 6
Explanation:
- In the first pass, everyone in the line buys a ticket and the line becomes [1, 2, 1].
- In the second pass, everyone in the line buys a ticket and the line becomes [0, 1, 0].
The person at position 2 has successfully bought 2 tickets and it took 3 + 3 = 6 seconds.
```

**Example 2:**

```
Input: tickets = [5,1,1,1], k = 0
Output: 8
Explanation:
- In the first pass, everyone in the line buys a ticket and the line becomes [4, 0, 0, 0].
- In the next 4 passes, only the person in position 0 is buying tickets.
The person at position 0 has successfully bought 5 tickets and it took 4 + 1 + 1 + 1 + 1 = 8 seconds.
```

**Constraints:**

- `n == tickets.length`
- `1 <= n <= 100`
- `1 <= tickets[i] <= 100`
- `0 <= k < n`

## My Solutions

---

```python
class Solution:

    def moveToEnd(self,queue):

        cur_customer = queue.popleft()
        queue.append(cur_customer)

    def timeRequiredToBuy(self, tickets: List[int], k: int) -> int:

        selling_time = 0 
        tickets = deque(tickets)

        while tickets[k] > 0:
            cur_customer = tickets[0]

            if cur_customer != 0:
                tickets[0] -= 1
                self.moveToEnd(tickets)

                selling_time += 1
                k = (k - 1) % len(tickets)

            else:
                self.moveToEnd(tickets)
                k = (k - 1) % len(tickets)
                
        return selling_time
```

```python

```

## Optimal Solutions

---

To optimize your program for speed, consider minimizing the operations inside the loop. Your current implementation has a time complexity of O(n^2) in the worst case because it involves dequeuing and enqueuing for each ticket purchase, and adjusting the index `k` in each iteration. For large inputs, this can become inefficient.

A more efficient approach would calculate the time required without simulating each ticket purchase. This can be done by directly calculating the number of rounds needed for the queue to reach the `k`th person and how many times the queue goes around before the `k`th person buys all their tickets.

Here's a more efficient approach:

1. **Calculate time directly**: Instead of simulating each person buying a ticket one by one, calculate the time required for the `k`th person to buy all their tickets by summing up the minimum of each person's ticket count and the ticket count of the `k`th person. This reduces the problem to a single pass through the list, significantly lowering the time complexity.
2. **Reduce redundant calculations**: By avoiding deque operations for each ticket and instead using arithmetic to find the total time, you significantly reduce the computational overhead.

Here's how you could implement these optimizations:

```python
def timeRequiredToBuy(tickets, k):
    time = 0
    # Loop through each person in the queue
    for i, ticket in enumerate(tickets):
        if i <= k:
            # For people before and including k, time is increased by the lesser of their ticket count or the k's ticket count
            time += min(ticket, tickets[k])
        else:
            # For people after k, time is increased by the lesser of their ticket count - 1 (since k will be served before them) or the k's ticket count
            time += min(ticket, tickets[k] - 1)
    return time
```

This approach does the following:

- For each person in the queue before or at `k`, it adds either their ticket count or the ticket count of the `k`th person (whichever is smaller) to `time`.
- For each person in the queue after `k`, it considers that the `k`th person will have been served once when it's their turn, so it adds the minimum of their ticket count or one less than the `k`th person's ticket count to `time`.

This implementation runs in O(n) time, where n is the number of people in the queue, because it only requires a single pass through the `tickets` list to compute the total time, making it significantly faster for large inputs.

## why  tickets[k] - 1 ?

The reasoning for using `tickets[k] - 1` when calculating the time for people standing after the `k`th person in the queue comes from the observation of how the queue progresses:

1. **For people before and including `k`**: Each person will get to buy their tickets until it's the turn of the `k`th person. Therefore, the contribution to the total time from each of these people is the lesser of their ticket count or the ticket count of the `k`th person, because the `k`th person will leave the queue once their tickets are all bought.
2. **For people after `k`**: By the time the queue has advanced to these people, the `k`th person has already been served once. This is because the queue cycles through each person in order, decrementing their ticket count by 1 each cycle. Therefore, when considering the time contributed by people after `k`, we should account for the fact that the `k`th person's need is reduced by 1 ticket by the time we start considering those behind them. This leads to two scenarios:
    - If someone behind `k` has more tickets than `k`, they will still be in the queue after `k` buys their last ticket, but we only count up to `k`'s ticket count minus one for these people because `k` gets served before them in each cycle.
    - If someone behind `k` has fewer tickets than `k`, then their contribution to the total time is just their ticket count, because they will leave the queue before `k` finishes.

Using `tickets[k] - 1` for those behind `k` correctly adjusts for the fact that `k` is decremented once before these individuals start contributing to the time calculation. It ensures the calculation does not overestimate the time by assuming those after `k` could possibly wait for `k` to be served an extra time that actually isn't needed for them to buy their tickets.

This adjustment is crucial for accurately computing the total time required for everyone up to and including the `k`th person to buy their tickets, reflecting the nuanced behavior of the queue as it processes each person's ticket purchases.

## Notes

---

 

## Related Videos

---

[https://www.notion.so](https://www.notion.so)