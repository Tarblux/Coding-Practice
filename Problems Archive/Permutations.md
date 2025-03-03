# Permutations

Problem: 42
Official Difficulty: medium
Feels Like : medium
My Understanding: Mostly Understand
Topic: array, backtracking
Link: https://leetcode.com/problems/permutations/description/
Completed On : March 6, 2024
Last Review: October 15, 2024
Days Since Review: 138
Neetcode: Yes

## Problem

---

Given an array `nums` of distinct integers, return *all the possible permutations*. You can return the answer in **any order**.

**Example 1:**

```
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
```

**Example 2:**

```
Input: nums = [0,1]
Output: [[0,1],[1,0]]
```

**Example 3:**

```
Input: nums = [1]
Output: [[1]]
```

**Constraints:**

- `1 <= nums.length <= 6`
- `10 <= nums[i] <= 10`
- All the integers of `nums` are **unique**.

## My Solutions

---

My solution

```python
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        
        permutations = []

        def backtrack(bank,path):

            if not bank:
                permutations.append(path)
                return

            for i in range(len(bank)):
                backtrack(bank[:i] + bank[i+1:],path + [bank[i]])

        backtrack(nums,[])

        return permutations
```

Neetcode Solution

```python
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:

        result = []

        if len(nums) == 1:
            return [nums[:]]

        for i in range(len(nums)):
            n = nums.pop(0)
            perms = self.permute(nums)

            for perm in perms:
                perm.append(n)
            result.extend(perms)
            nums.append(n)
        
        return result
```

## Optimal Solutions

---

To generate all permutations of a list of numbers, you can use a classic backtracking algorithm. The idea is to build permutations by swapping elements at each position with every other element and then recursively doing the same for the next positions.

Here's how you can implement this in Python:

```python
from typing import List

class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        def backtrack(first=0):
            # If all integers are used up, add the permutation to the output
            if first == n:
                output.append(nums[:])
                return
            for i in range(first, n):
                # Place i-th integer first in the current permutation
                nums[first], nums[i] = nums[i], nums[first]
                # Use next integers to complete the permutations
                backtrack(first + 1)
                # Backtrack
                nums[first], nums[i] = nums[i], nums[first]

        n = len(nums)
        output = []
        backtrack()
        return output

# Example usage
nums = [1, 2, 3]
solution = Solution()
permutations = solution.permute(nums)
print(permutations)

```

### Explanation:

- The function `permute` defines a nested helper function `backtrack` which takes one argument `first`. The `first` argument represents the index in `nums` at which to start generating permutations for the current recursive call.
- The base case for the recursion occurs when `first` equals `n`, meaning the current permutation of `nums` is complete and can be added to the output list.
- The algorithm generates permutations by iterating through the indices `i` from `first` to `n - 1`. For each `i`, it swaps the element at `first` with the element at `i`, recursively calls `backtrack` with `first + 1` to generate permutations with the element at `i` fixed in the first position, and then swaps back to restore the original order of `nums` for the next iteration.
- This process generates all possible permutations by ensuring that each number gets to occupy the first position in the list, followed by each subsequent number getting the chance to be in the next position, and so on.

### Complexity Analysis:

- **Time Complexity**: O(n!), where n is the number of elements in the list. There are n! permutations in total for a list of n elements.
- **Space Complexity**: O(n), for the recursion call stack. In the worst case, the depth of the recursion tree is n. Additionally, O(n) space is used to store the current permutation.

## Notes

---

 

## Related Videos

---

[https://youtu.be/s7AvT7cGdSo](https://youtu.be/s7AvT7cGdSo)