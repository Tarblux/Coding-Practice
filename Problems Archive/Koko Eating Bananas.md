# Koko Eating Bananas

Problem: 875
Official Difficulty: medium
Feels Like : hard
My Understanding: Needs Review
Topic: array, binary search
Link: https://leetcode.com/problems/koko-eating-bananas/
Completed On : May 30, 2024
Last Review: May 30, 2024
Days Since Review: 4

## Problem

---

Koko loves to eat bananas. There are `n` piles of bananas, the `ith` pile has `piles[i]` bananas. The guards have gone and will come back in `h` hours.

Koko can decide her bananas-per-hour eating speed of `k`. Each hour, she chooses some pile of bananas and eats `k` bananas from that pile. If the pile has less than `k` bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return *the minimum integer* `k` *such that she can eat all the bananas within* `h` *hours*.

**Example 1:**

```
Input: piles = [3,6,7,11], h = 8
Output: 4
```

**Example 2:**

```
Input: piles = [30,11,23,4,20], h = 5
Output: 30
```

**Example 3:**

```
Input: piles = [30,11,23,4,20], h = 6
Output: 23
```

**Constraints:**

- `1 <= piles.length <= 104`
- `piles.length <= h <= 109`
- `1 <= piles[i] <= 109`

## My Solutions

---

```python
class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:

        left = 1
        right = max(piles)

        min_speed = right

        while left < right:

            mid = left + (right-left)//2
            total_time = 0

            for pile in piles:
                total_time += math.ceil(float(pile)/mid)

            if total_time <= h:
                min_speed = min(min_speed,mid)
                right = mid
            else:
                left = mid + 1

        return min_speed
```

```python

```

## Optimal Solutions

---

### Problem Description

Koko loves to eat bananas. There are `n` piles of bananas, where the `i-th` pile has `piles[i]` bananas. The guards have gone and will come back in `h` hours. Koko can decide her bananas-per-hour eating speed `k`. Each hour, she chooses some pile of bananas and eats `k` bananas from that pile. If the pile has less than `k` bananas, she eats all of them instead, and then the pile is empty. Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer `k` such that she can eat all the bananas within `h` hours.

### Example

```python
Input: piles = [3, 6, 7, 11], h = 8
Output: 4

Input: piles = [30, 11, 23, 4, 20], h = 5
Output: 30

Input: piles = [30, 11, 23, 4, 20], h = 6
Output: 23
```

### Optimal Solution and Explanation

To find the minimum eating speed `k` such that Koko can eat all bananas within `h` hours, we can use a binary search approach. The key insight is to determine if a given speed `k` is sufficient by simulating the total hours required to eat all the bananas at that speed.

### Steps:

1. **Binary Search Setup**:
    - The minimum possible speed `k` is 1 (if she eats very slowly).
    - The maximum possible speed `k` is the maximum number of bananas in any pile (if she eats all the bananas in one pile per hour).
2. **Binary Search Execution**:
    - Use binary search to find the minimum speed `k` that allows Koko to finish eating all the bananas within `h` hours.
    - For each mid value in the binary search, calculate the total hours needed to eat all the bananas at that speed.
    - Adjust the search range based on whether the current speed is sufficient.
3. **Hour Calculation**:
    - For a given speed `k`, calculate the total hours required by summing up the time taken for each pile, where the time is the ceiling value of `piles[i] / k`.

### Python Code

Here's the Python code to achieve this:

```python
import math

def minEatingSpeed(piles, h):
    def canEatAllBananas(k):
        total_hours = 0
        for pile in piles:
            total_hours += math.ceil(pile / k)
        return total_hours <= h

    left, right = 1, max(piles)
    while left < right:
        mid = (left + right) // 2
        if canEatAllBananas(mid):
            right = mid
        else:
            left = mid + 1

    return left

# Example usage
piles1 = [3, 6, 7, 11]
h1 = 8
print(minEatingSpeed(piles1, h1))  # Output: 4

piles2 = [30, 11, 23, 4, 20]
h2 = 5
print(minEatingSpeed(piles2, h2))  # Output: 30

piles3 = [30, 11, 23, 4, 20]
h3 = 6
print(minEatingSpeed(piles3, h3))  # Output: 23

```

### Explanation

1. **Binary Search Setup**:
    - Initialize `left` to 1 (slowest possible speed) and `right` to `max(piles)` (fastest possible speed).
2. **Binary Search Execution**:
    - Compute `mid` as the average of `left` and `right`.
    - Use the helper function `canEatAllBananas(mid)` to check if Koko can eat all bananas within `h` hours at speed `mid`.
    - If she can, narrow the search range to the left half (`right = mid`).
    - If she cannot, narrow the search range to the right half (`left = mid + 1`).
3. **Hour Calculation**:
    - For each pile, calculate the time to eat all bananas in that pile at speed `k` using `math.ceil(pile / k)`.
    - Sum the times for all piles and check if the total is within `h` hours.

### Time Complexity Analysis

- **Binary Search**: The binary search runs in `O(log(max(piles)))` time.
- **Hour Calculation**: For each speed `k` in the binary search, we calculate the total hours in `O(n)` time, where `n` is the number of piles.
- **Overall Time Complexity**: `O(n log(max(piles)))`

### Space Complexity Analysis

- **Space Complexity**: `O(1)`
    - We use a constant amount of additional space for variables and the helper function.

### Explain Like I'm Five (ELI5)

Imagine you have a bunch of candy piles, and you want to find out the slowest way to eat all the candies within a certain time limit. You want to test different eating speeds to see which one lets you finish just in time:

1. **Start Slow**: Begin with a very slow speed.
2. **Speed Up**: Gradually increase the speed and check if you can finish all the candies within the time limit.
3. **Find the Sweet Spot**: Use a clever way to narrow down the speeds quickly (binary search) until you find the slowest speed that still lets you finish on time.

By testing different speeds and narrowing down the possibilities, you can find the best speed to eat all the candies just in time!

## Notes

---

 

## Related Videos

---

[https://youtu.be/U2SozAs9RzA](https://youtu.be/U2SozAs9RzA)