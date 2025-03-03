# Best Sightseeing Pair

Problem: 1014
Official Difficulty: medium
Feels Like : easy
My Understanding: Needs Review
Topic: array, dynamic programming
Link: https://leetcode.com/problems/best-sightseeing-pair/description/?envType=daily-question&envId=2024-12-27
Completed On : December 26, 2024
Last Review: December 26, 2024
Days Since Review: 66
Neetcode: No

## Problem

---

You are given an integer array `values` where values[i] represents the value of the `ith` sightseeing spot. Two sightseeing spots `i` and `j` have a **distance** `j - i` between them.

The score of a pair (`i < j`) of sightseeing spots is `values[i] + values[j] + i - j`: the sum of the values of the sightseeing spots, minus the distance between them.

Return *the maximum score of a pair of sightseeing spots*.

**Example 1:**

```
Input: values = [8,1,5,2,6]
Output: 11
Explanation: i = 0, j = 2, values[i] + values[j] + i - j = 8 + 5 + 0 - 2 = 11

```

**Example 2:**

```
Input: values = [1,2]
Output: 2

```

**Constraints:**

- `2 <= values.length <= 5 * 104`
- `1 <= values[i] <= 1000`

## My Solutions

---

```python
class Solution:
    def maxScoreSightseeingPair(self, values: List[int]) -> int:
        best_plus_i = values[0] + 0 # best (values[i] + i) so far
        max_score = float('-inf')
        
        for j in range(1, len(values)):
            # The current possible score is (best_plus_i) + (values[j] - j)
            candidate_score = best_plus_i + values[j] - j
            max_score = max(max_score, candidate_score)
            
            # Update best_plus_i with current values[j] + j if it's larger
            best_plus_i = max(best_plus_i, values[j] + j)
            
        return max_score

```

```python

```

## Optimal Solutions

---

## Notes

---

 

## Related Videos

---

[https://www.notion.so](https://www.notion.so)