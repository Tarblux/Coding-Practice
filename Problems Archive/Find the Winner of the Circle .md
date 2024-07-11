# Find the Winner of the Circle

Official Difficulty: medium
Feels Like : medium
My Understanding: Needs Review
Topic: Math, Queue, array, recursion, simulation
Link: https://leetcode.com/problems/find-the-winner-of-the-circular-game/description/
Completed On : July 8, 2024
Last Review: July 8, 2024
Days Since Review: 3

## Problem

---

There are `n` friends that are playing a game. The friends are sitting in a circle and are numbered from `1` to `n` in **clockwise order**. More formally, moving clockwise from the `ith` friend brings you to the `(i+1)th` friend for `1 <= i < n`, and moving clockwise from the `nth` friend brings you to the `1st` friend.

The rules of the game are as follows:

1. **Start** at the `1st` friend.
2. Count the next `k` friends in the clockwise direction **including** the friend you started at. The counting wraps around the circle and may count some friends more than once.
3. The last friend you counted leaves the circle and loses the game.
4. If there is still more than one friend in the circle, go back to step `2` **starting** from the friend **immediately clockwise** of the friend who just lost and repeat.
5. Else, the last friend in the circle wins the game.

Given the number of friends, `n`, and an integer `k`, return *the winner of the game*.

**Example 1:**

![https://assets.leetcode.com/uploads/2021/03/25/ic234-q2-ex11.png](https://assets.leetcode.com/uploads/2021/03/25/ic234-q2-ex11.png)

```
Input: n = 5, k = 2
Output: 3
Explanation: Here are the steps of the game:
1) Start at friend 1.
2) Count 2 friends clockwise, which are friends 1 and 2.
3) Friend 2 leaves the circle. Next start is friend 3.
4) Count 2 friends clockwise, which are friends 3 and 4.
5) Friend 4 leaves the circle. Next start is friend 5.
6) Count 2 friends clockwise, which are friends 5 and 1.
7) Friend 1 leaves the circle. Next start is friend 3.
8) Count 2 friends clockwise, which are friends 3 and 5.
9) Friend 5 leaves the circle. Only friend 3 is left, so they are the winner.
```

**Example 2:**

```
Input: n = 6, k = 5
Output: 1
Explanation: The friends leave in this order: 5, 4, 6, 2, 3. The winner is friend 1.

```

**Constraints:**

- `1 <= k <= n <= 500`

**Follow up:**

Could you solve this problem in linear time with constant space?

## My Solutions

---

```python
class Solution:
    def findTheWinner(self, n: int, k: int) -> int:

        players = [n for n in range(1,n+1)]
        i = 0

        while len(players) > 1:

            i = (i + k - 1)%len(players)
            players.pop(i)

        return players.pop()
      
```

```python

```

## Optimal Solutions

---

### Problem Description

In the circular game, `n` people stand in a circle and are numbered from `1` to `n`. The game starts with person `1` and proceeds to eliminate every `k`-th person until only one person remains. The task is to determine the winner of the game.

### Example

```python
Input: n = 5, k = 2
Output: 3

Input: n = 6, k = 5
Output: 1
```

### Optimal Solution and Explanation

To solve this problem, we can use the Josephus problem solution. The Josephus problem is a theoretical problem related to a certain elimination game.

The position of the last remaining person can be found using a recursive relation or an iterative approach.

### Recursive Solution

The recursive formula for the Josephus problem is:

- `J(n, k) = (J(n-1, k) + k) % n` with the base case `J(1, k) = 0`.

### Iterative Solution

We can also solve this problem iteratively to avoid potential recursion depth issues in Python.

### Python Code for Iterative Solution

Here's the Python code to achieve this:

```python
class Solution:
    def findTheWinner(self, n: int, k: int) -> int:
        winner = 0  # Josephus position for 1 person is 0 (0-indexed)
        for i in range(2, n + 1):
            winner = (winner + k) % i
        return winner + 1  # Convert to 1-indexed

# Example usage
sol = Solution()
print(sol.findTheWinner(5, 2))  # Output: 3
print(sol.findTheWinner(6, 5))  # Output: 1
```

### Explanation

1. **Initialization**:
    - Start with `winner = 0`, which is the position of the winner when there is only 1 person (0-indexed).
2. **Iterative Calculation**:
    - Iterate from 2 to `n`, updating the winner's position using the formula `(winner + k) % i`. This simulates the elimination process in a circular manner.
    - The formula ensures that after each elimination, the position of the winner is updated correctly within the new circle size.
3. **1-Indexed Conversion**:
    - Since the problem expects a 1-indexed result, return `winner + 1`.

### Time Complexity Analysis

- **Time Complexity**: `O(n)`
    - The loop runs `n-1` times, making the time complexity linear with respect to the number of people `n`.

### Space Complexity Analysis

- **Space Complexity**: `O(1)`
    - The algorithm uses a constant amount of extra space for the variables `winner` and the loop counter.

This iterative approach is efficient and avoids the potential pitfalls of recursion in Python, such as hitting the recursion depth limit for large inputs.

## Notes

---

 

## Related Videos

---

[https://www.youtube.com/watch?v=PBBQgW_75e0](https://www.youtube.com/watch?v=PBBQgW_75e0)