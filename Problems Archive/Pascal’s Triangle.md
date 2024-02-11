# Pascal’s Triangle

Problem: 118
Official Difficulty: easy
Feels Like : medium
Topic: array, dynamic programming
Link: https://leetcode.com/problems/pascals-triangle/
Completed On : December 10, 2023
My Understanding: Needs Review
Last Review: December 10, 2023
Days Since Review: 62

## Problem

---

Given an integer `numRows`, return the first numRows of **Pascal's triangle**.

In **Pascal's triangle**, each number is the sum of the two numbers directly above it as shown:

![https://upload.wikimedia.org/wikipedia/commons/0/0d/PascalTriangleAnimated2.gif](https://upload.wikimedia.org/wikipedia/commons/0/0d/PascalTriangleAnimated2.gif)

**Example 1:**

```
Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

```

**Example 2:**

```
Input: numRows = 1
Output: [[1]]

```

**Constraints:**

- `1 <= numRows <= 30`

## My Solutions

---

```python
class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        
        output = [[1]]
        
        if numRows == 1 : 
            
            return output
      
                        
        for i in range (1,numRows) : 
            
            arr = [1] 
            
            for j in range(1,i): 
                
                arr.append(output[i-1][j-1] + output[i-1][j])
                
            arr.append(1) 
            
            output.append(arr)
        
        return output
```

```python

```

## Optimal Solutions

---

The most optimal solution for generating Pascal's Triangle up to a given number of rows involves using a simple iterative approach. Each row of Pascal's Triangle is constructed based on the previous row, with the understanding that each element (except the first and last in each row) is the sum of the two numbers directly above it. The first and last elements in each row are always 1.

### Algorithm

1. **Initialize**: Start with a list containing a single row: `[1]`.
2. **Iterate for Each Row**:
    - For each new row (starting from the second row), initialize the row with `[1]`.
    - Fill in the middle elements. Each element is the sum of the two elements above it in the previous row. That is, for `i`th element in the new row, add the `(i-1)`th and `i`th elements of the previous row.
    - Append `[1]` at the end of the row since the last element is always 1.
    - Add this new row to your list of rows.
3. **Repeat** until you have the required number of rows.

### Python Implementation

```python
def generate_pascals_triangle(num_rows):
    if num_rows == 0:
        return []

    triangle = [[1]]

    for i in range(1, num_rows):
        row = [1]
        for j in range(1, i):
            row.append(triangle[i - 1][j - 1] + triangle[i - 1][j])
        row.append(1)
        triangle.append(row)

    return triangle

```

### Explanation

- We start with a triangle containing only the first row `[1]`.
- For each subsequent row, we create a new list with the first element as `1`.
- We then calculate the values of the subsequent elements by summing the appropriate elements from the previous row.
- Finally, we append `1` at the end of each row and add this row to the triangle.
- This process is repeated until we reach the desired number of rows.

### Complexity Analysis

- **Time Complexity**: O(n²), where `n` is the number of rows. This is because for each row, we perform a number of operations proportional to the row index.
- **Space Complexity**: O(n²), as we store all rows of the triangle. Each row grows linearly with the number of rows, leading to quadratic space usage.

## Notes

---

 

## Related Videos

---

[https://www.youtube.com/watch?v=nPVEaB3AjUM](https://www.youtube.com/watch?v=nPVEaB3AjUM)