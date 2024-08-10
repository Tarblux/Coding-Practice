# Lucky Numbers in a Matrix

Problem: 1380
Official Difficulty: easy
Feels Like : medium
My Understanding: Fully Understand
Topic: Matrix, array
Link: https://leetcode.com/problems/lucky-numbers-in-a-matrix/description/
Completed On : August 9, 2024
Last Review: August 9, 2024
Days Since Review: 0

## Problem

---

Given an `m x n` matrix of **distinct** numbers, return *all **lucky numbers** in the matrix in **any** order*.

A **lucky number** is an element of the matrix such that it is the minimum element in its row and maximum in its column.

**Example 1:**

```
Input: matrix = [[3,7,8],[9,11,13],[15,16,17]]
Output: [15]
Explanation: 15 is the only lucky number since it is the minimum in its row and the maximum in its column.
```

**Example 2:**

```
Input: matrix = [[1,10,4,2],[9,3,8,7],[15,16,17,12]]
Output: [12]
Explanation: 12 is the only lucky number since it is the minimum in its row and the maximum in its column.
```

**Example 3:**

```
Input: matrix = [[7,8],[1,2]]
Output: [7]
Explanation: 7 is the only lucky number since it is the minimum in its row and the maximum in its column.
```

**Constraints:**

- `m == mat.length`
- `n == mat[i].length`
- `1 <= n, m <= 50`
- `1 <= matrix[i][j] <= 105`.
- All elements in the matrix are distinct.

## My Solutions

---

```python
class Solution:
    def luckyNumbers(self, matrix: List[List[int]]) -> List[int]:
        
        lucky = []

        row_mins = {i: min(row) for i, row in enumerate(matrix)}

        for j, col in enumerate(zip(*matrix)):
            maxy = max(col)
            for i, val in enumerate(col):
                if val == maxy and row_mins[i] == maxy:
                    lucky.append(maxy)

        return lucky
```

```python

```

## Optimal Solutions

---

### Problem Description

A "lucky number" in a matrix is defined as a number that is the minimum in its row and the maximum in its column. Given a matrix of distinct integers, you need to find all lucky numbers in the matrix.

### Example

```python
Input: matrix = [[3,7,8],[9,11,13],[15,16,17]]
Output: [15]

Input: matrix = [[1,10,4,2],[9,3,8,7],[15,16,17,12]]
Output: [12]

Input: matrix = [[7,8],[1,2]]
Output: [7]

```

### Solution Approach

To find the lucky numbers in the matrix, we can use the following approach:

1. **Find the Minimum of Each Row**: For each row, find the minimum element.
2. **Check Column Maximum**: For each of these minimum elements, check if it is the maximum in its corresponding column.
3. **Store the Lucky Numbers**: If the element satisfies both conditions, add it to the list of lucky numbers.

### Python Code

Here's the Python code to achieve this:

```python
from typing import List

class Solution:
    def luckyNumbers(self, matrix: List[List[int]]) -> List[int]:
        # Step 1: Find the minimum of each row
        min_row = [min(row) for row in matrix]

        # Step 2: Find the maximum of each column
        max_col = [max(col) for col in zip(*matrix)]

        # Step 3: Find lucky numbers
        lucky_numbers = []
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                if matrix[i][j] == min_row[i] and matrix[i][j] == max_col[j]:
                    lucky_numbers.append(matrix[i][j])

        return lucky_numbers

# Example usage
sol = Solution()
print(sol.luckyNumbers([[3,7,8],[9,11,13],[15,16,17]]))  # Output: [15]
print(sol.luckyNumbers([[1,10,4,2],[9,3,8,7],[15,16,17,12]]))  # Output: [12]
print(sol.luckyNumbers([[7,8],[1,2]]))  # Output: [7]

```

### Explanation

1. **Finding the Minimum of Each Row**:
    - `min_row = [min(row) for row in matrix]` creates a list where each entry corresponds to the minimum value of the respective row in the matrix.
2. **Finding the Maximum of Each Column**:
    - `max_col = [max(col) for col in zip(*matrix)]` creates a list where each entry corresponds to the maximum value of the respective column. The `zip(*matrix)` transposes the matrix, allowing column-wise operations.
3. **Identifying Lucky Numbers**:
    - Iterate through the matrix, and for each element, check if it matches both the minimum in its row and the maximum in its column.
    - If it does, it's a lucky number, and it's added to the `lucky_numbers` list.

### Time Complexity Analysis

- **Time Complexity**: `O(m * n)`
    - Finding the minimum of each row takes `O(m * n)` time.
    - Finding the maximum of each column takes `O(m * n)` time.
    - Checking for lucky numbers involves a double loop, also taking `O(m * n)` time.
- **Space Complexity**: `O(m + n)`
    - We store the minimum values of the rows and the maximum values of the columns, which requires `O(m)` and `O(n)` space respectively.

This solution efficiently finds all the lucky numbers in the matrix by first determining the necessary conditions for each element.

## Notes

---

 

## Related Videos

---

[https://www.youtube.com/watch?v=ceuQgACqr78](https://www.youtube.com/watch?v=ceuQgACqr78)