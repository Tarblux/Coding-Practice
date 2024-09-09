# Find the Student that will replace the chalk

Problem: 1894
Official Difficulty: medium
Feels Like : easy
My Understanding: Fully Understand
Topic: array, binary search, prefix sum, simulation
Link: https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk/description/?envType=daily-question&envId=2024-09-02
Completed On : September 2, 2024
Last Review: September 2, 2024
Days Since Review: 6

## Problem

---

There are `n` students in a class numbered from `0` to `n - 1`. The teacher will give each student a problem starting with the student number `0`, then the student number `1`, and so on until the teacher reaches the student number `n - 1`. After that, the teacher will restart the process, starting with the student number `0` again.

You are given a **0-indexed** integer array `chalk` and an integer `k`. There are initially `k` pieces of chalk. When the student number `i` is given a problem to solve, they will use `chalk[i]` pieces of chalk to solve that problem. However, if the current number of chalk pieces is **strictly less** than `chalk[i]`, then the student number `i` will be asked to **replace** the chalk.

Return *the **index** of the student that will **replace** the chalk pieces*.

**Example 1:**

```
Input: chalk = [5,1,5], k = 22
Output: 0
Explanation:The students go in turns as follows:
- Student number 0 uses 5 chalk, so k = 17.
- Student number 1 uses 1 chalk, so k = 16.
- Student number 2 uses 5 chalk, so k = 11.
- Student number 0 uses 5 chalk, so k = 6.
- Student number 1 uses 1 chalk, so k = 5.
- Student number 2 uses 5 chalk, so k = 0.
Student number 0 does not have enough chalk, so they will have to replace it.
```

**Example 2:**

```
Input: chalk = [3,4,1,2], k = 25
Output: 1
Explanation:The students go in turns as follows:
- Student number 0 uses 3 chalk so k = 22.
- Student number 1 uses 4 chalk so k = 18.
- Student number 2 uses 1 chalk so k = 17.
- Student number 3 uses 2 chalk so k = 15.
- Student number 0 uses 3 chalk so k = 12.
- Student number 1 uses 4 chalk so k = 8.
- Student number 2 uses 1 chalk so k = 7.
- Student number 3 uses 2 chalk so k = 5.
- Student number 0 uses 3 chalk so k = 2.
Student number 1 does not have enough chalk, so they will have to replace it.
```

**Constraints:**

- `chalk.length == n`
- `1 <= n <= 105`
- `1 <= chalk[i] <= 105`
- `1 <= k <= 109`

## My Solutions

---

```python
class Solution:
    def chalkReplacer(self, chalk: List[int], k: int) -> int:

        total = sum(chalk)

        k -= total * (k//total)
        k %= total  
        
        i = 0

        while k > 0:
            
            if chalk[i] > k:
                return i

            k -= chalk[i]
            i += 1
            i %= len(chalk)

        return i
```

```python

```

## Optimal Solutions

---

### Approach

The key to solving this problem efficiently is to recognize that once the total chalk required in one complete cycle exceeds `k`, the chalk usage can be reduced modulo the total chalk used in one cycle. This prevents unnecessary looping over students.

### Steps

1. **Calculate the Total Chalk Usage**:
    - Sum the entire array `chalk` to determine the total amount of chalk used in one full cycle.
2. **Reduce `k` Modulo Total Chalk**:
    - Instead of running multiple cycles, reduce `k` by taking `k % total_chalk`. This gives us the effective amount of chalk left after all complete cycles are taken into account.
3. **Determine the Student**:
    - Iterate through the `chalk` array, subtracting each student's chalk usage from `k` until `k` becomes less than the chalk required by the current student. That student is the one who will run out of chalk.

### Python Implementation

```python
from typing import List

class Solution:
    def chalkReplacer(self, chalk: List[int], k: int) -> int:
        total_chalk = sum(chalk)
        k %= total_chalk

        for i, usage in enumerate(chalk):
            if k < usage:
                return i
            k -= usage

# Example usage
sol = Solution()
print(sol.chalkReplacer([5,1,5], 22))  # Output: 0
print(sol.chalkReplacer([3,4,1,2], 25))  # Output: 1

```

### Explanation

1. **Calculate Total Chalk**:
    - `total_chalk = sum(chalk)` computes the total chalk used by all students in one cycle.
2. **Reduce `k`**:
    - `k %= total_chalk` reduces the problem to considering only the leftover chalk after full cycles.
3. **Find the Student**:
    - We iterate through the `chalk` list. If `k` is less than the chalk required by the current student, that student is the answer. If not, we subtract the chalk used by the current student and continue.

### Complexity Analysis

- **Time Complexity**: `O(n)`, where `n` is the number of students. The time complexity is linear because we traverse the `chalk` list twice: once for summing and once for finding the student.
- **Space Complexity**: `O(1)`, as we are using only a few extra variables regardless of the input size.

This approach ensures that we efficiently find the student who will run out of chalk without needing to simulate the entire chalk distribution process multiple times.

## Notes

---

 

## Related Videos

---

[https://www.notion.so](https://www.notion.so)