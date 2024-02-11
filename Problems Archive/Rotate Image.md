# Rotate Image

Problem: 48
Official Difficulty: medium
Topic: Math, Matrix, array
Link: https://leetcode.com/problems/rotate-image/
Completed On : November 29, 2023
My Understanding: I Have No Idea
Last Review: November 29, 2023
Days Since Review: 73

## Problem

---

You are given an `n x n` 2D `matrix` representing an image, rotate the image by **90** degrees (clockwise).

You have to rotate the image **[in-place](https://en.wikipedia.org/wiki/In-place_algorithm)**, which means you have to modify the input 2D matrix directly. **DO NOT** allocate another 2D matrix and do the rotation.

![Untitled](Rotate%20Image%200eebf0d4353e4e179b11115df0766a64/Untitled.jpeg)

```
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]
```

![Untitled](Rotate%20Image%200eebf0d4353e4e179b11115df0766a64/Untitled%201.jpeg)

```
Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
```

## My Solutions

---

### Aleksandr

```python
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        
        l = len(matrix)
        for rowI in range(0, l // 2):
            for colI in range(rowI, (l - 1 - rowI)):
                first = matrix[rowI][colI]
                second = matrix[colI][l - 1 - rowI]
                third = matrix[l - 1 - rowI][l - 1 - colI]
                fourth = matrix[l - 1 - colI][rowI]

                matrix[rowI][colI] = fourth
                matrix[colI][l - 1 - rowI] = first
                matrix[l - 1 - rowI][l - 1 - colI] = second
                matrix[l - 1 - colI][rowI] = third
```

```python

```

## Optimal Solutions

---

The optimal solution for the "Rotate Image" problem involves a two-step process:

1. **Transpose the Matrix**: First, transpose the matrix, which means converting all rows into columns or vice versa. In mathematical terms, this means setting `matrix[i][j] = matrix[j][i]` for all `i` and `j`.
2. **Reverse Each Row**: Then, reverse each row of the matrix. This can be done in place and changes the transposed matrix into its rotated form.

This approach is optimal because it accomplishes the task with a time complexity of O(n^2) (where n is the number of rows/columns in the matrix) and does not require any additional space, achieving O(1) space complexity.

Here’s how you can implement this solution in Python:

```python
class Solution(object):
    def rotate(self, matrix):
        n = len(matrix)

        # Transpose the matrix
        for i in range(n):
            for j in range(i + 1, n):
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]

        # Reverse each row
        for i in range(n):
            matrix[i].reverse()

```

### Explanation:

1. **Transposing the Matrix**:
    - The nested loop iterates through the elements above the main diagonal (i.e., where `j > i`). This is important to avoid re-swapping elements that have already been transposed.
2. **Reversing Each Row**:
    - The second loop reverses each row of the matrix. In Python, this can be easily done with the `reverse()` method.

This method works effectively for square matrices of any size and rotates the matrix 90 degrees clockwise in place.

## Notes

---

## Related Videos

---

[https://www.youtube.com/watch?v=fMSJSS7eO1w](https://www.youtube.com/watch?v=fMSJSS7eO1w)

[https://www.youtube.com/watch?v=Z0R2u6gd3GU](https://www.youtube.com/watch?v=Z0R2u6gd3GU)