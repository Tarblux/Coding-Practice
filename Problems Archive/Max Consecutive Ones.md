# Max Consecutive Ones

Problem: 485
Official Difficulty: easy
Feels Like : easy
Topic: array
Link: https://leetcode.com/problems/max-consecutive-ones/description/
Completed On : January 6, 2024
My Understanding: Fully Understand
Last Review: January 6, 2024
Days Since Review: 35

## Problem

---

Given a binary array `nums`, return *the maximum number of consecutive* `1`*'s in the array*.

**Example 1:**

```
Input: nums = [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.

```

**Example 2:**

```
Input: nums = [1,0,1,1,0,1]
Output: 2

```

**Constraints:**

- `1 <= nums.length <= 105`
- `nums[i]` is either `0` or `1`.

## My Solutions

---

```python
class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:

        counter = 0 

        max_count = 0

        for num in nums : 

            if num == 0 : 

                counter = 0

            if num == 1 : 

                counter += 1

            max_count = max(counter , max_count)

        return max_count
```

```python

```

## Optimal Solutions

---

The "Max Consecutive Ones" problem is a common question in coding interviews and practices. It's typically solved using a straightforward linear scan approach. The goal is to find the maximum number of consecutive `1`s in a binary array.

### Problem Statement

Given a binary array `nums` (an array where each element is either a `0` or a `1`), return the maximum number of consecutive `1`s in the array.

### Solution Approach: Linear Scan

The most efficient way to solve this problem is to iterate through the array while keeping track of the number of consecutive `1`s. Whenever you encounter a `0`, you reset the count and update the maximum count if necessary.

### Python Implementation

```python
class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        max_count = 0
        current_count = 0

        for num in nums:
            if num == 1:
                current_count += 1
                max_count = max(max_count, current_count)
            else:
                current_count = 0

        return max_count

```

### Explanation

- Iterate through each number in the array.
- If the number is `1`, increment `current_count`. Update `max_count` if `current_count` is greater than the current `max_count`.
- If the number is `0`, reset `current_count` to `0`.
- After completing the iteration, `max_count` will contain the maximum number of consecutive `1`s.

### Complexity Analysis

- **Time Complexity**: O(n), where `n` is the number of elements in `nums`. The solution requires a single pass through the array.
- **Space Complexity**: O(1), as the solution uses a fixed amount of space regardless of the input size.

This approach is efficient and straightforward, effectively solving the problem with a single pass through the array and minimal space usage.

## Notes

---

 Remember greedy algorithms

## Related Videos

---

[https://www.notion.so](https://www.notion.so)