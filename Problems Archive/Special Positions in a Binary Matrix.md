# Special Positions in a Binary Matrix

Problem: 1582
Official Difficulty: easy
Feels Like : easy
My Understanding: Fully Understand
Topic: Matrix, array
Link: https://leetcode.com/problems/special-positions-in-a-binary-matrix/description/
Completed On : May 28, 2024
Last Review: May 28, 2024
Days Since Review: 6

## Problem

---

Given an `m x n` binary matrix `mat`, return *the number of special positions in* `mat`*.*

A position `(i, j)` is called **special** if `mat[i][j] == 1` and all other elements in row `i` and column `j` are `0` (rows and columns are **0-indexed**).

**Example 1:**

![https://assets.leetcode.com/uploads/2021/12/23/special1.jpg](https://assets.leetcode.com/uploads/2021/12/23/special1.jpg)

```
Input: mat = [[1,0,0],[0,0,1],[1,0,0]]
Output: 1
Explanation: (1, 2) is a special position because mat[1][2] == 1 and all other elements in row 1 and column 2 are 0.
```

**Example 2:**

![https://assets.leetcode.com/uploads/2021/12/24/special-grid.jpg](https://assets.leetcode.com/uploads/2021/12/24/special-grid.jpg)

```
Input: mat = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3
Explanation: (0, 0), (1, 1) and (2, 2) are special positions.
```

**Constraints:**

- `m == mat.length`
- `n == mat[i].length`
- `1 <= m, n <= 100`
- `mat[i][j]` is either `0` or `1`.

## My Solutions

---

```python
**class Solution:
    def numSpecial(self, mat: List[List[int]]) -> int:

        special = 0

        for i in range(len(mat)):
            for j in range(len(mat[0])):

                if mat[i][j] == 1: 

                    if sum(mat[i]) == 1 and sum(list(zip(*mat))[j]) == 1 :

                        special += 1

        return special**
```

```python

```

## Optimal Solutions

---

### Problem Description

Given a `m x n` binary matrix `mat`, return the number of special positions in the matrix. A position `(i, j)` is called special if `mat[i][j] == 1` and all other elements in row `i` and column `j` are `0`.

### Example

```python
Input: mat = [[1,0,0],
              [0,0,1],
              [1,0,0]]
Output: 1

Input: mat = [[1,0,0],
              [0,1,0],
              [0,0,1]]
Output: 3

```

### Optimal Solution and Explanation

To solve this problem, we can follow these steps:

1. **Count Rows and Columns**: Iterate through the matrix and count the number of `1`s in each row and each column.
2. **Identify Special Positions**: A position `(i, j)` is special if:
    - `mat[i][j] == 1`
    - There is exactly one `1` in row `i`
    - There is exactly one `1` in column `j`

### Steps:

1. **Count the number of `1`s in each row and column**:
    - Use two arrays `row_count` and `col_count` to keep track of the number of `1`s in each row and column respectively.
2. **Iterate through the matrix again to check for special positions**:
    - For each position `(i, j)` where `mat[i][j] == 1`, check if `row_count[i] == 1` and `col_count[j] == 1`.

### Python Code

Here's the Python code to achieve this:

```python
def numSpecial(mat):
    m = len(mat)
    n = len(mat[0])

    row_count = [0] * m
    col_count = [0] * n

    # Count the number of 1s in each row and column
    for i in range(m):
        for j in range(n):
            if mat[i][j] == 1:
                row_count[i] += 1
                col_count[j] += 1

    # Check for special positions
    special_count = 0
    for i in range(m):
        for j in range(n):
            if mat[i][j] == 1 and row_count[i] == 1 and col_count[j] == 1:
                special_count += 1

    return special_count

# Example usage
mat1 = [[1,0,0],
        [0,0,1],
        [1,0,0]]
print(numSpecial(mat1))  # Output: 1

mat2 = [[1,0,0],
        [0,1,0],
        [0,0,1]]
print(numSpecial(mat2))  # Output: 3

```

### Explanation

1. **Counting Rows and Columns**:
    - We iterate through each element in the matrix.
    - For each `1` encountered, increment the corresponding entry in `row_count` and `col_count`.
2. **Checking Special Positions**:
    - We iterate through each element in the matrix again.
    - For each `1` encountered, check if the count of `1`s in its row and column is exactly one. If so, it is a special position.

### Time Complexity Analysis

- **Counting Phase**: We iterate through the matrix once to count the `1`s in each row and column, which takes `O(m * n)` time.
- **Checking Phase**: We iterate through the matrix again to check for special positions, which also takes `O(m * n)` time.
- **Overall Time Complexity**: `O(m * n)`

### Space Complexity Analysis

- **Space for `row_count` and `col_count`**: We use two additional arrays of size `m` and `n` respectively, resulting in `O(m + n)` space.
- **Overall Space Complexity**: `O(m + n)`

### Explain Like I'm Five (ELI5)

Imagine you have a grid of seats in a theater, and some seats have a VIP guest (marked as `1`). You want to find seats that have exactly one VIP in their row and exactly one VIP in their column.

1. **Count VIPs**: First, count the number of VIPs in each row and each column.
2. **Find Special Seats**: Then, check each seat. If a seat has a VIP and it's the only VIP in its row and column, it's a special seat.

By counting first and then checking, you can efficiently find all the special seats in the theater.

## Notes

---

 

## Related Videos

---

[https://www.notion.so](https://www.notion.so)