# Spiral Matrix

Problem: 54
Official Difficulty: medium
Feels Like : medium
My Understanding: Mostly Understand
Topic: Matrix, array, simulation
Link: https://leetcode.com/problems/spiral-matrix/description/
Completed On : January 29, 2024
Last Review: June 13, 2024
Days Since Review: 57

## Problem

---

Given an `m x n` `matrix`, return *all elements of the* `matrix` *in spiral order*.

**Example 1:**

![https://assets.leetcode.com/uploads/2020/11/13/spiral1.jpg](https://assets.leetcode.com/uploads/2020/11/13/spiral1.jpg)

```
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
```

**Example 2:**

![https://assets.leetcode.com/uploads/2020/11/13/spiral.jpg](https://assets.leetcode.com/uploads/2020/11/13/spiral.jpg)

```
Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
```

**Constraints:**

- `m == matrix.length`
- `n == matrix[i].length`
- `1 <= m, n <= 10`
- `100 <= matrix[i][j] <= 100`

## My Solutions

---

## The solution below is better so don’t medz this

```python
class Solution:

    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:

        if not matrix or not matrix[0]:

            return []

        rows, cols = len(matrix), len(matrix[0])

        output = []

        # Top Row

        for col in range(cols):

            output.append(matrix[0][col])

        # Right Column

        for row in range(1, rows):

            output.append(matrix[row][cols - 1])

        # Bottom Row

        if rows > 1:

            for col in range(cols - 2, -1, -1):

                output.append(matrix[rows - 1][col])

        # Left Column

        if cols > 1:

            for row in range(rows - 2, 0, -1):

                output.append(matrix[row][0])

        # Handle inner matrix if it exists

        if rows > 2 and cols > 2:

            inner_matrix = [row[1:-1] for row in matrix[1:-1]]
            
            output.extend(self.spiralOrder(inner_matrix))

        return output
```

```python
class Solution:

    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:

        output = []

        while matrix:

            # Add Top row 
            output += matrix.pop(0)
            
						# Flip Matrix
            if matrix:
                matrix = list(zip(*matrix))[::-1]

        return output
```

### Solution Explanation

### Step-by-Step Explanation

1. **Initialize the Output List:**
    
    ```python
    output = []
    ```
    
    This list will store the elements of the matrix in spiral order.
    
2. **While Loop to Process the Matrix:**
    
    ```python
    while matrix:
    
    ```
    
    This loop runs as long as there are elements in the matrix. The idea is to peel off the outer layer of the matrix in each iteration.
    
3. **Add the First Row to Output:**
    
    ```python
    output += matrix.pop(0)
    
    ```
    
    This line takes the first row of the matrix, removes it, and adds its elements to the `output` list.
    
4. **Rotate the Matrix Counterclockwise:**
    
    ```python
    if matrix:
        matrix = list(zip(*matrix))[::-1]
    
    ```
    
    - `zip(*matrix)` transposes the matrix (turns rows into columns and vice versa).
    - `[::-1]` reverses the order of the rows to simulate a counterclockwise rotation.
    This prepares the remaining part of the matrix for the next iteration of the loop.
5. **Return the Output:**
    
    ```python
    return output
    
    ```
    
    Once all layers have been peeled off and added to `output`, the function returns the final list.
    

### Walkthrough with Example Matrix

Let's walk through the solution using the example matrix `[[1,2,3],[4,5,6],[7,8,9]]`.

**Initial Matrix:**

```
1 2 3
4 5 6
7 8 9

```

**First Iteration:**

- `output = []`
- `output += matrix.pop(0)`:
    - `matrix.pop(0)` gives `[1, 2, 3]`
    - `output = [1, 2, 3]`
- Matrix after removing the first row:

```
4 5 6
7 8 9

```

- Rotate the remaining matrix:
    - Transpose:
    
    ```
    4 7
    5 8
    6 9
    
    ```
    
    - Reverse rows:
    
    ```
    6 9
    5 8
    4 7
    
    ```
    

**Second Iteration:**

- `output = [1, 2, 3]`
- `output += matrix.pop(0)`:
    - `matrix.pop(0)` gives `[6, 9]`
    - `output = [1, 2, 3, 6, 9]`
- Matrix after removing the first row:

```
5 8
4 7

```

- Rotate the remaining matrix:
    - Transpose:
    
    ```
    5 4
    8 7
    
    ```
    
    - Reverse rows:
    
    ```
    8 7
    5 4
    
    ```
    

**Third Iteration:**

- `output = [1, 2, 3, 6, 9]`
- `output += matrix.pop(0)`:
    - `matrix.pop(0)` gives `[8, 7]`
    - `output = [1, 2, 3, 6, 9, 8, 7]`
- Matrix after removing the first row:

```
5 4

```

- Rotate the remaining matrix:
    - Transpose:
    
    ```
    5
    4
    
    ```
    
    - Reverse rows:
    
    ```
    4
    5
    
    ```
    

**Fourth Iteration:**

- `output = [1, 2, 3, 6, 9, 8, 7]`
- `output += matrix.pop(0)`:
    - `matrix.pop(0)` gives `[4]`
    - `output = [1, 2, 3, 6, 9, 8, 7, 4]`
- Matrix after removing the first row:

```
5

```

- Rotate the remaining matrix:
    - Transpose:
    
    ```
    5
    
    ```
    
    - Reverse rows:
    
    ```
    5
    
    ```
    

**Fifth Iteration:**

- `output = [1, 2, 3, 6, 9, 8, 7, 4]`
- `output += matrix.pop(0)`:
    - `matrix.pop(0)` gives `[5]`
    - `output = [1, 2, 3, 6, 9, 8, 7, 4, 5]`
- Matrix after removing the first row:

```
(empty)

```

- Matrix is now empty, so the loop exits.

**Final Output:**

```
[1, 2, 3, 6, 9, 8, 7, 4, 5]

```

### Time Complexity Analysis

- Each element is visited exactly once, so the time complexity is O(m*n), where m is the number of rows and n is the number of columns.
- The space complexity is also O(m*n) due to the storage required for the output list and the intermediate transformations.

This thorough explanation and step-by-step walkthrough should give you a clear understanding of how the solution works.

## Time Complexity

Let's revisit the original solution and break down its time complexity step-by-step. Here's the original solution again:

```python
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        output = []

        while matrix:
            output += matrix.pop(0)

            if matrix:
                matrix = list(zip(*matrix))[::-1]

        return output

```

### Steps of the Algorithm

1. **Initialization:**
    
    ```python
    output = []
    
    ```
    
    This step initializes an empty list `output`. The complexity is O(1).
    
2. **While Loop to Process the Matrix:**
    
    ```python
    while matrix:
    
    ```
    
    This loop runs as long as there are elements in the matrix.
    
3. **Remove and Append the First Row:**
    
    ```python
    output += matrix.pop(0)
    
    ```
    
    This line removes the first row of the matrix and appends its elements to `output`. The complexity of removing the first row is O(n), where n is the number of columns in the current iteration. Appending a list to another list in Python can be considered O(k), where k is the length of the list being appended. Here, k = n, so this operation is O(n).
    
4. **Rotate the Remaining Matrix:**
    
    ```python
    if matrix:
        matrix = list(zip(*matrix))[::-1]
    
    ```
    
    - `zip(*matrix)` transposes the matrix (turns rows into columns and vice versa). Transposing an m x n matrix takes O(m * n) time.
    - `[::-1]` reverses the order of the rows, which is O(m), where m is the number of rows after the first row is removed.
    
    Therefore, the total complexity for rotating the matrix is O(m * n) for the transposition plus O(m) for the reversal, which simplifies to O(m * n).
    

### Total Complexity per Layer

Each complete iteration of the while loop processes one layer of the matrix (an outer ring). For each layer:

- **Remove the first row**: O(n)
- **Transpose and reverse**: O(m * n)

### Total Complexity for All Layers

The entire matrix is processed layer by layer, with each layer reducing the size of the matrix. Let's analyze how many times the loop runs and the work done in each iteration:

1. **First Layer:**
    - Remove the first row: O(n)
    - Transpose and reverse: O(m * n)
2. **Second Layer (smaller submatrix):**
    - Remove the first row: O(n')
    - Transpose and reverse: O(m' * n')
    
    Here, n' and m' are the dimensions of the submatrix after the first layer is removed.
    

The size of the matrix decreases with each iteration. However, the most significant operation is the transpose and reverse, which has a complexity of O(m * n) for each iteration until the matrix is empty.

### Summing Up

- For the first layer, the complexity is O(m * n) (since we're transposing and reversing the entire matrix).
- For the second layer, the matrix size is smaller, but the complexity is still significant: O(m' * n').

When we sum up the complexities of each layer, we essentially touch each element once during the transposition and reversal across all iterations. The dominant factor is the repeated transposition and reversal.

Therefore, the total time complexity is:
\[ O(m \times n) \]

### Summary

- **Time Complexity:** O(m * n), where m is the number of rows and n is the number of columns in the matrix. This is because each element is processed exactly once, and the dominant operation (transposing and reversing) is performed on the entire matrix.
- **Space Complexity:** O(m * n), considering the storage required for the `output` list and intermediate transformations (though the list `matrix` itself is being modified in place).

This detailed explanation clarifies why the time complexity of the original solution is O(m * n).

## Optimal Solutions

---

## This is horeshit compared to another solution I came up with using zip so just worry about above and leave this alone 👹

The "Spiral Matrix" problem involves traversing a 2D matrix in a spiral pattern and collecting the elements in the order of their visitation. The traversal starts from the top-left corner and initially proceeds rightward. The pattern is right, down, left, and up, repeating until all elements are visited.

### Problem Statement

Given an `m x n` matrix, return all elements of the matrix in spiral order.

### Solution Approach

To solve this problem, keep track of the boundaries - top, bottom, left, and right - and iterate through the matrix. Update these boundaries after traversing each edge to avoid revisiting elements.

### Python Implementation

```python
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        if not matrix:
            return []

        result = []
        left, right, top, bottom = 0, len(matrix[0]), 0, len(matrix)

        while left < right and top < bottom:
            # Traverse from left to right
            for i in range(left, right):
                result.append(matrix[top][i])
            top += 1

            # Traverse downwards
            for i in range(top, bottom):
                result.append(matrix[i][right - 1])
            right -= 1

            if not (left < right and top < bottom):
                break

            # Traverse from right to left
            for i in range(right - 1, left - 1, -1):
                result.append(matrix[bottom - 1][i])
            bottom -= 1

            # Traverse upwards
            for i in range(bottom - 1, top - 1, -1):
                result.append(matrix[i][left])
            left += 1

        return result
```

### Explanation

- Initialize `left`, `right`, `top`, and `bottom` to denote the boundaries of the matrix.
- The outer `while` loop runs as long as `left < right` and `top < bottom`.
- Iterate rightwards, downwards, leftwards, and then upwards, appending elements to `result`.
- After each traversal of an edge, adjust the respective boundary inward to prevent revisiting elements.
- Break the loop when the boundaries cross, indicating all elements have been visited.

### Complexity Analysis

- **Time Complexity**: O(m * n), where m is the number of rows and n is the number of columns in the matrix. Each element is visited exactly once.
- **Space Complexity**: O(1), if the output array is not considered as extra space. Otherwise, it's O(m * n) for the output array.

This implementation provides an efficient way to traverse the matrix in a spiral order and collect its elements.

---

## Notes

---

 

## Related Videos

---

[https://www.youtube.com/watch?v=BJnMZNwUk1M&pp=ygUNc3BpcmFsIG1hdHJpeA%3D%3D](https://www.youtube.com/watch?v=BJnMZNwUk1M&pp=ygUNc3BpcmFsIG1hdHJpeA%3D%3D)