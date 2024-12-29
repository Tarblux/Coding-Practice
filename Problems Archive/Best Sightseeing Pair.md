Problem: 1014
Official Difficulty: medium
Link: https://leetcode.com/problems/best-sightseeing-pair/description/?envType=daily-question&envId=2024-12-27
Completed On : 2024-12-26
Feels Like : easy
Topic: array, dynamic programming
My Understanding: Needs Review
Last Review: 2024-12-26
Days Since Review: 3
Name: Best Sightseeing Pair

# Best Sightseeing Pair
### Problem
___
You are given an integer array `values` where values[i] represents the value of the `ith` sightseeing spot. Two sightseeing spots `i` and `j` have a **distance** `j - i` between them.
The score of a pair (`i < j`) of sightseeing spots is `values[i] + values[j] + i - j`: the sum of the values of the sightseeing spots, minus the distance between them.
Return *the maximum score of a pair of sightseeing spots*.
**Example 1:**
```plain text
Input: values = [8,1,5,2,6]
Output: 11
Explanation: i = 0, j = 2, values[i] + values[j] + i - j = 8 + 5 + 0 - 2 = 11

```
**Example 2:**
```plain text
Input: values = [1,2]
Output: 2

```
**Constraints:**
- `2 <= values.length <= 5 * 104`
- `1 <= values[i] <= 1000`
### My Solutions
___
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

Time Complexity :
```python

```

Time Complexity : 
### Optimal Solutions
___

### Notes
___
 
### Related Videos 
___
[]()