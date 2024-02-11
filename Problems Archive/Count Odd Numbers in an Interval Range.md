# Count Odd Numbers in an Interval Range

Problem: 1523
Official Difficulty: easy
Feels Like : easy
Topic: Math
Link: https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/description/?envType=study-plan-v2&envId=programming-skills
Completed On : January 29, 2024
My Understanding: I Have No Idea, Needs Review
Last Review: January 29, 2024
Days Since Review: 12

## Problem

---

Given two non-negative integers `low` and `high`. Return the *count of odd numbers between* `low` *and* `high` *(inclusive)*.

**Example 1:**

```
Input: low = 3, high = 7
Output: 3
Explanation:The odd numbers between 3 and 7 are [3,5,7].
```

**Example 2:**

```
Input: low = 8, high = 10
Output: 1
Explanation:The odd numbers between 8 and 10 are [9].
```

**Constraints:**

- `0 <= low <= high <= 10^9`

## My Solutions

---

```python
class Solution:
    def countOdds(self, low: int, high: int) -> int:

        # Calculate the number of integers between low and high,  inclusive

        count = high - low + 1

        # If low is odd or high is odd, there's one more odd integer

        if low % 2 == 1 or high % 2 == 1:

            count += 1
            
        return count // 2
```

```python

```

## Optimal Solutions (*)

---

The solution provided correctly calculates the number of odd numbers in the range `[low, high]` including both endpoints. The reasoning behind it is based on understanding how integers are distributed between even and odd numbers.

### Understanding the Solution

1. **Calculate the Total Count of Numbers**:
    - The expression `count = high - low + 1` calculates the total number of integers in the range, including both `low` and `high`.
2. **Adjust for Odd Endpoints**:
    - If either `low` or `high` is odd, it means that the distribution of even and odd numbers within the range is slightly skewed towards odd numbers.
    - In a sequence of consecutive numbers, if either the start or the end (or both) is odd, there is an additional odd number compared to even numbers.
    - Adding 1 to `count` when either `low` or `high` is odd adjusts for this skew.
3. **Dividing by 2**:
    - Normally, in a sequence of consecutive integers, half the numbers are odd, and half are even.
    - After adjusting `count` for odd endpoints, dividing by 2 gives the correct number of odd numbers.

### Example: Low = 21, High = 22

- `count = 22 - 21 + 1 = 2`
- Since `21` (low) is odd, `count` is incremented by 1: `count = 2 + 1 = 3`.
- Dividing the adjusted count by 2 gives `3 // 2 = 1`. This is the correct number of odd numbers between 21 and 22.

### Why This Works

The adjustment by 1 for odd endpoints is key. It ensures that if there is an odd number of elements in the range (which happens when either `low` or `high` or both are odd), the extra number is accounted for in the count of odd numbers. The final division by 2 then accurately gives the number of odd numbers in the range.

### Complexity Analysis

- **Time Complexity**: O(1), as the operations involved are basic arithmetic operations, independent of the size of the input range.
- **Space Complexity**: O(1), as the solution only uses a fixed amount of extra space.

### Explain Like I am Five (ELI5)

---

## Notes

---

 

## Related Videos

---

[https://www.notion.so](https://www.notion.so)