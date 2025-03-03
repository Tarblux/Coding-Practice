# Permutations II

Problem: 47
Official Difficulty: medium
Feels Like : easy
My Understanding: Fully Understand
Topic: array, backtracking
Link: https://leetcode.com/problems/permutations-ii/submissions/1510108069/
Completed On : January 15, 2025
Last Review: January 15, 2025
Days Since Review: 46
Neetcode: No

## Problem

---

Given a collection of numbers, `nums`, that might contain duplicates, return *all possible unique permutations **in any order**.*

**Example 1:**

```
Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]

```

**Example 2:**

```
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

```

**Constraints:**

- `1 <= nums.length <= 8`
- `10 <= nums[i] <= 10`

## My Solutions

---

```python
class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
  
        permutations = []
        nums.sort()

        def backtrack(bank,path):

            if not bank:
                permutations.append(path)
                return

            for i in range(len(bank)):

                if i > 0 and bank[i] == bank[i-1]:
                    continue

                backtrack(bank[:i] + bank[i+1:],path + [bank[i]])

        backtrack(nums,[])

        return permutations
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