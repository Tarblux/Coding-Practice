# Check if Every Row and Column Contains All Numbers

Problem: 2133
Official Difficulty: easy
Feels Like : easy breazy
My Understanding: Fully Understand
Topic: Matrix, array, set
Link: https://leetcode.com/problems/check-if-every-row-and-column-contains-all-numbers/
Completed On : May 23, 2024
Last Review: May 23, 2024
Days Since Review: 3

## Problem

---

An `n x n` matrix is **valid** if every row and every column contains **all** the integers from `1` to `n` (**inclusive**).

Given an `n x n` integer matrix `matrix`, return `true` *if the matrix is **valid**.* Otherwise, return `false`.

**Example 1:**

![https://assets.leetcode.com/uploads/2021/12/21/example1drawio.png](https://assets.leetcode.com/uploads/2021/12/21/example1drawio.png)

```
Input: matrix = [[1,2,3],[3,1,2],[2,3,1]]
Output: true
Explanation: In this case, n = 3, and every row and column contains the numbers 1, 2, and 3.
Hence, we return true.

```

**Example 2:**

![https://assets.leetcode.com/uploads/2021/12/21/example2drawio.png](https://assets.leetcode.com/uploads/2021/12/21/example2drawio.png)

```
Input: matrix = [[1,1,1],[1,2,3],[1,2,3]]
Output: false
Explanation: In this case, n = 3, but the first row and the first column do not contain the numbers 2 or 3.
Hence, we return false.

```

**Constraints:**

- `n == matrix.length == matrix[i].length`
- `1 <= n <= 100`
- `1 <= matrix[i][j] <= n`

## My Solutions

---

```python
class Solution:
    def checkValid(self, matrix: List[List[int]]) -> bool:

        n = len(matrix)
        expected_sum = n * (n+1)
        expected_sum /= 2
        
        for row in matrix:
            if len(set(row)) != n:
                return False 

        for col in zip(*matrix):
            if len(set(col)) != n:
                return False

        return True
```

```python
class Solution:
    def checkValid(self, matrix: List[List[int]]) -> bool:

        n = len(matrix)
        expected_sum = n * (n+1)
        expected_sum //= 2
        
        for row in matrix:
            if sum(row) != expected_sum:
                return False 

        for col in zip(*matrix):
            if sum(col) != expected_sum:
                return False

        return True
```

## Optimal Solutions

---

## Notes

---

 

## Related Videos

---

[https://www.notion.so](https://www.notion.so)