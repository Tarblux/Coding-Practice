# Minimum Falling Path Sum I

Problem: 931
Official Difficulty: medium
Feels Like : medium
My Understanding: Needs Review
Topic: array, dynamic programming, hash table
Link: https://leetcode.com/problems/minimum-falling-path-sum/description/
Completed On : August 10, 2024
Last Review: August 10, 2024
Days Since Review: 1

## Problem

---

Given an `n x n` array of integers `matrix`, return *the **minimum sum** of any **falling path** through* `matrix`.

A **falling path** starts at any element in the first 
row and chooses the element in the next row that is either directly 
below or diagonally left/right. Specifically, the next element from 
position `(row, col)` will be `(row + 1, col - 1)`, `(row + 1, col)`, or `(row + 1, col + 1)`.

**Example 1:**

![https://assets.leetcode.com/uploads/2021/11/03/failing1-grid.jpg](https://assets.leetcode.com/uploads/2021/11/03/failing1-grid.jpg)

```
Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
Output: 13
Explanation: There are two falling paths with a minimum sum as shown.
```

**Example 2:**

![https://assets.leetcode.com/uploads/2021/11/03/failing2-grid.jpg](https://assets.leetcode.com/uploads/2021/11/03/failing2-grid.jpg)

```
Input: matrix = [[-19,57],[-40,-5]]
Output: -59
Explanation: The falling path with a minimum sum is shown.
```

**Constraints:**

- `n == matrix.length == matrix[i].length`
- `1 <= n <= 100`
- `100 <= matrix[i][j] <= 100`

## My Solutions

---

```python
class Solution:
    def minFallingPathSum(self, matrix: List[List[int]]) -> int:

        n = len(matrix)

        if n < 2 : 
            return min(matrix[0])

        for r in range(1,n):
            for c in range(n):

                above = matrix[r-1][c]

                if c == 0:
                    top_left = float('inf')
                else: 
                    top_left = matrix[r-1][c-1] 
                
                if c == n - 1:
                    top_right = float('inf')
                else:
                    top_right = matrix[r-1][c+1]

                best_option = min(above,top_left,top_right)

                matrix[r][c] += best_option

        return min(matrix[-1])
```

## Refactored to try and do the edge cases more gracefully

Certainly! Let's refactor the code to handle the boundary conditions more gracefully without explicitly checking the indices using multiple `if` statements.

### Key Idea:

Instead of using multiple `if` statements, we can create a helper function that returns a large number (`float('inf')`) if the index is out of bounds. This allows you to focus on the main logic without worrying about boundaries.

Here’s the updated solution:

```python
class Solution:
    def minFallingPathSum(self, matrix: List[List[int]]) -> int:
        n = len(matrix)

        def get_value(r, c):
            if 0 <= c < n:
                return matrix[r][c]
            else:
                return float('inf')

        for r in range(1, n):
            for c in range(n):
                # Get values from the row above
                top_left = get_value(r-1, c-1)
                above = get_value(r-1, c)
                top_right = get_value(r-1, c+1)

                # Update current cell with the minimum path sum
                matrix[r][c] += min(top_left, above, top_right)

        # The result is the minimum value in the last row
        return min(matrix[-1])

```

### Explanation:

1. **Helper Function `get_value`**:
    - This function abstracts away the boundary checking. It returns the value from `matrix[r][c]` if the column index `c` is within bounds, otherwise it returns `float('inf')` to effectively ignore out-of-bounds indices.
2. **Using `get_value` in the Main Loop**:
    - The main loop becomes much cleaner because `get_value` handles the boundary conditions internally.
    - This avoids multiple `if-else` conditions in the loop, making the code easier to read and maintain.
3. **Update the Matrix**:
    - For each cell `matrix[r][c]`, you calculate the minimum sum path by considering the three possible paths (left diagonal, above, right diagonal).
    - The matrix is updated in place with the minimum sum path up to that cell.
4. **Result**:
    - After processing all rows, the minimum value in the last row of the matrix is returned as the result.

This approach keeps your logic clean and focuses on the key operations, while the helper function takes care of edge cases.

## Optimal Solutions

---

### Problem Description

Given an `n x n` grid of integers, find the minimum sum of any falling path through the grid. A falling path starts at any element in the first row and chooses one element from each row. The next row's choice must be in a column that is either the same, or adjacent to the previous row's column.

### Example

```python
Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
Output: 13
Explanation: The falling path with the minimum sum is 1 -> 4 -> 8, which gives a sum of 13.

Input: matrix = [[-19,57],[-40,-5]]
Output: -59
Explanation: The falling path with the minimum sum is -19 -> -40, which gives a sum of -59.
```

### Approach

To solve this problem, we can use dynamic programming (DP). The idea is to keep track of the minimum falling path sum up to each element in the grid. We can start from the second row and for each element in that row, update its value to be the sum of itself and the minimum of the three possible elements from the previous row that it can connect to (directly above, above-left, and above-right).

### Dynamic Programming Steps

1. **Initialization**:
    - We start from the second row of the matrix. The first row remains unchanged because it represents the base case (falling paths that consist of only one row).
2. **DP Transition**:
    - For each element `matrix[i][j]` in the current row `i`, we update it by adding the minimum value from the possible elements in the previous row that it can connect to:
        - `matrix[i-1][j]` (directly above)
        - `matrix[i-1][j-1]` (above-left, if `j > 0`)
        - `matrix[i-1][j+1]` (above-right, if `j < n-1`)
3. **Result**:
    - After processing all rows, the minimum value in the last row of the matrix will be the minimum falling path sum.

### Python Code

Here's the Python code to implement the solution:

```python
from typing import List

class Solution:
    def minFallingPathSum(self, matrix: List[List[int]]) -> int:
        n = len(matrix)

        # Iterate over the matrix starting from the second row
        for i in range(1, n):
            for j in range(n):
                # Find the minimum of the three possible values from the previous row
                min_prev = matrix[i-1][j]
                if j > 0:
                    min_prev = min(min_prev, matrix[i-1][j-1])
                if j < n-1:
                    min_prev = min(min_prev, matrix[i-1][j+1])

                # Update the current cell
                matrix[i][j] += min_prev

        # The answer is the minimum value in the last row
        return min(matrix[-1])

# Example usage
sol = Solution()
print(sol.minFallingPathSum([[2,1,3],[6,5,4],[7,8,9]]))  # Output: 13
print(sol.minFallingPathSum([[-19,57],[-40,-5]]))        # Output: -59
```

### Explanation

- **Dynamic Programming Transition**:
    - For each element in the matrix, starting from the second row, we update its value to be the sum of the current value and the minimum value from the three possible elements in the previous row.
- **Result Extraction**:
    - After processing all rows, the minimum value in the last row represents the minimum falling path sum.

### Complexity Analysis

- **Time Complexity**: `O(n^2)`
    - We process each element in the `n x n` matrix exactly once, leading to a time complexity of `O(n^2)`.
- **Space Complexity**: `O(1)`
    - The solution is in-place, meaning no additional space proportional to the input size is used, making the space complexity `O(1)`.

This solution efficiently computes the minimum falling path sum using dynamic programming, processing the matrix in-place to achieve optimal space usage.

## Notes

---

 

## Related Videos

---

[https://www.youtube.com/watch?v=b_F3mz9l-uQ&pp=ygUMbGVldGNvZGUgOTMx](https://www.youtube.com/watch?v=b_F3mz9l-uQ&pp=ygUMbGVldGNvZGUgOTMx)