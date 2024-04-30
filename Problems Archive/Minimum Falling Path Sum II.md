# Minimum Falling Path Sum II

Problem: 1289
Official Difficulty: hard
Feels Like : hard
My Understanding: Mostly Understand, Needs Review
Topic: Matrix, array, dynamic programming
Link: https://leetcode.com/problems/minimum-falling-path-sum-ii/description/
Completed On : April 26, 2024
Last Review: April 26, 2024
Days Since Review: 4

## Problem

---

Given an `n x n` integer matrix `grid`, return *the minimum sum of a **falling path with non-zero shifts***.

A **falling path with non-zero shifts** is a choice of exactly one element from each row of `grid` such that no two elements chosen in adjacent rows are in the same column.

**Example 1:**

![https://assets.leetcode.com/uploads/2021/08/10/falling-grid.jpg](https://assets.leetcode.com/uploads/2021/08/10/falling-grid.jpg)

```
Input: grid = [[1,2,3],[4,5,6],[7,8,9]]
Output: 13
Explanation:
The possible falling paths are:
[1,5,9], [1,5,7], [1,6,7], [1,6,8],
[2,4,8], [2,4,9], [2,6,7], [2,6,8],
[3,4,8], [3,4,9], [3,5,7], [3,5,9]
The falling path with the smallest sum is [1,5,7], so the answer is 13.
```

**Example 2:**

```
Input: grid = [[7]]
Output: 7
```

**Constraints:**

- `n == grid.length == grid[i].length`
- `1 <= n <= 200`
- `99 <= grid[i][j] <= 99`

## My Solutions

---

```python
class Solution:
    def twoSmallest(self,array:List[int]) -> List[int]:

        first = float('inf')
        second = float('inf')
        index_1 = 0
        index_2 = 0

        for i , num in enumerate(array):

            if num < first :
                second = first
                index_2 = index_1
                first = num
                index_1 = i
            elif num < second:
                second = num
                index_2 = i

        return (index_1,index_2)

    def minFallingPathSum(self, grid: List[List[int]]) -> int:

        if len(grid) == 1 :

            return sum(grid[0])

        dp = [[0 for _ in range(len(grid))]for _ in range(len(grid))]

        dp[0] = grid[0].copy()

        idx_1 , idx_2 = self.twoSmallest(grid[0])

        for i in range(1,len(grid)):

            idx_1 , idx_2 = self.twoSmallest(dp[i-1])

            for j in range(len(grid)):

                if j == idx_1:

                    dp[i][j] = grid[i][j] + dp[i-1][idx_2]
                    continue

                elif j == idx_2:

                    dp[i][j] = grid[i][j] + dp[i-1][idx_1]
                    continue

                else:

                    dp[i][j] = grid[i][j] + dp[i-1][idx_1]
                    continue

        return min(dp[-1])
        
```

**Chau**

```python
class Solution:
    def minFallingPathSum(self, grid: List[List[int]]) -> int:
        ROW, COL = len(grid), len(grid[0])
        dp = [[0 for _ in range(ROW)] for _ in range(COL)]
        dp[0] = grid[0]

        for i in range(1, ROW):
            idx1 = dp[i-1].index(min(dp[i-1]))
            idx2 = dp[i-1].index(min(dp[i-1][:idx1] + dp[i-1][idx1+1:]))

            for j in range(COL):
                if j == idx1:
                    dp[i][j] = dp[i-1][idx2] + grid[i][j]
                else:
                    dp[i][j] = dp[i-1][idx1] + grid[i][j]

        return min(dp[-1])
    
```

## Optimal Solutions

---

The "Minimum Falling Path Sum II" problem involves finding the minimum sum of a falling path through a square grid of integers where you can't use the same column for consecutive rows. This problem extends the challenge of the typical Minimum Falling Path Sum by adding the restriction of not being able to select the same column twice in a row.

### Problem Explanation:

Given an `n x n` matrix `arr`, a falling path starts at any element in the first row and chooses one element from each row. The next row's chosen element must be from a column that is different from the previous row's column. The challenge is to find the path with the minimum possible sum.

### Solution Approach:

A dynamic programming approach works well for this problem. The idea is to maintain a `dp` table where `dp[i][j]` represents the minimum falling path sum to reach element `(i, j)`.

### Detailed Steps:

1. **Initialization**: Start by copying the first row of `arr` to `dp` because the first row of `dp` is the same as the first row of `arr`.
2. **Populating the DP Table**:
    - For each cell `(i, j)` in `dp`, calculate the minimum path sum to that cell by considering all cells from the previous row except the cell directly above `(i-1, j)`.
    - To make this efficient, you need to know the minimum and second minimum values from the previous row, because if the minimum value from the previous row is from the same column, you should use the second minimum.
3. **Tracking Minimums Efficiently**:
    - While populating the `dp` table for row `i`, also keep track of the minimum and second minimum values in that row for use in the next row.
4. **Result Calculation**:
    - After filling the `dp` table, the answer will be the minimum value in the last row of `dp`.

### Python Code Example:

```python
from typing import List

class Solution:
    def minFallingPathSum(self, arr: List[List[int]]) -> int:
        n = len(arr)
        dp = [row[:] for row in arr]  # Initialize dp table with the values of arr

        for i in range(1, n):
            # Find the minimum and second minimum values from the previous row
            min1, min2 = float('inf'), float('inf')
            for j in range(n):
                if dp[i-1][j] < min1:
                    min2 = min1
                    min1 = dp[i-1][j]
                elif dp[i-1][j] < min2:
                    min2 = dp[i-1][j]

            # Populate the current row of dp
            for j in range(n):
                if dp[i-1][j] == min1:
                    dp[i][j] = arr[i][j] + min2
                else:
                    dp[i][j] = arr[i][j] + min1

        # The answer is the minimum value in the last row of dp
        return min(dp[-1])

# Example usage
sol = Solution()
matrix = [[2,2,1],[2,3,1],[3,4,1]]
print(sol.minFallingPathSum(matrix))  # Output will depend on the specific matrix

```

### Complexity Analysis:

- **Time Complexity**: \(O(n^2)\) because each entry in the `dp` table is calculated using constant time operations relative to the number of columns.
- **Space Complexity**: \(O(n^2)\) due to the storage of the `dp` table. This can be optimized to \(O(n)\) by only keeping the last row and the minimum values from the previous row.

This solution leverages dynamic programming with a twist of needing to find minimums excluding the directly above column, ensuring an efficient and comprehensive method to solve the problem.

## Notes

---

 

## Related Videos

---

[https://www.youtube.com/watch?v=_b8sptrsFEM](https://www.youtube.com/watch?v=_b8sptrsFEM)