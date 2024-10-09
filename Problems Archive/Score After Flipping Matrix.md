# Score After Flipping Matrix

Problem: 861
Official Difficulty: medium
Feels Like : medium
My Understanding: Mostly Understand
Topic: Bit Manipulation, Matrix, array, greedy
Link: https://leetcode.com/problems/score-after-flipping-matrix/description/?envType=daily-question&envId=2024-05-13
Completed On : May 13, 2024
Last Review: May 13, 2024
Days Since Review: 6

## Problem

---

You are given an `m x n` binary matrix `grid`.

A **move** consists of choosing any row or column and toggling each value in that row or column (i.e., changing all `0`'s to `1`'s, and all `1`'s to `0`'s).

Every row of the matrix is interpreted as a binary number, and the **score** of the matrix is the sum of these numbers.

Return *the highest possible **score** after making any number of **moves** (including zero moves)*.

**Example 1:**

![https://assets.leetcode.com/uploads/2021/07/23/lc-toogle1.jpg](https://assets.leetcode.com/uploads/2021/07/23/lc-toogle1.jpg)

```
Input: grid = [[0,0,1,1],[1,0,1,0],[1,1,0,0]]
Output: 39
Explanation: 0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39
```

**Example 2:**

```
Input: grid = [[0]]
Output: 1
```

**Constraints:**

- `m == grid.length`
- `n == grid[i].length`
- `1 <= m, n <= 20`
- `grid[i][j]` is either `0` or `1`.

## My Solutions

---

```python
class Solution:

    def toggle(self, array:List[int]) -> List[int]:

        for i in range(len(array)):
            if not array[i]:
                array[i] = 1
            else:
                array[i] = 0
        return array

    def toInteger(self,array:List[int]) -> int:

        integer = 0
        power = len(array) - 1
        for pos in array:
            integer += pos * (2**power)
            power -= 1
        return integer

    def matrixScore(self, grid: List[List[int]]) -> int:

        maxwyn = 0

        for row in grid:
            if row[0] != 1:
                self.toggle(row)

        for i, col in enumerate(zip(*grid)):
            col = list(col)
            if col.count(1) < col.count(0):
                col = self.toggle(col)
                for j in range(len(grid)):
                    grid[j][i] = col[j]

        for row in grid:
            maxwyn += self.toInteger(row)

        return maxwyn
```

```python

```

## Optimal Solutions

---

The LeetCode problem "Score After Flipping Matrix" involves flipping rows and columns of a binary matrix to maximize the score, which is calculated by interpreting each row as a binary number and summing these numbers.

Here's a thorough explanation and solution:

## Problem Statement

Given a binary matrix `A`, you can perform any number of row and column flips. Flipping a row means turning all 0s into 1s and all 1s into 0s in that row. Similarly, flipping a column means turning all 0s into 1s and all 1s into 0s in that column. The goal is to maximize the sum of the matrix, where each row is interpreted as a binary number.

## Optimal Solution Approach

To maximize the score, the leftmost column should have as many 1s as possible, as this column has the highest weight in the binary representation. After ensuring the leftmost column is maximized, for each subsequent column, we should flip the column if it increases the number of 1s.

### Detailed Steps

1. **Maximize the Leftmost Column**:
    - Ensure the first column has all 1s by flipping any row that starts with a 0.
2. **Optimize Each Column**:
    - For each subsequent column, count the number of 1s and 0s.
    - If there are more 0s than 1s, flip the column to maximize the number of 1s.
3. **Calculate the Total Score**:
    - Convert each row from binary to its decimal representation.
    - Sum these values to get the total score.

### Code Implementation

```python
def matrixScore(A):
    rows, cols = len(A), len(A[0])

    # Step 1: Ensure the first column is all 1s by flipping rows as necessary
    for row in range(rows):
        if A[row][0] == 0:
            for col in range(cols):
                A[row][col] ^= 1

    # Step 2: Optimize each column to have the maximum number of 1s
    for col in range(1, cols):
        count_ones = sum(A[row][col] for row in range(rows))
        if count_ones < rows / 2:
            for row in range(rows):
                A[row][col] ^= 1

    # Step 3: Calculate the total score
    total_score = 0
    for row in range(rows):
        row_value = 0
        for col in range(cols):
            row_value = (row_value << 1) | A[row][col]
        total_score += row_value

    return total_score

```

### Explanation

1. **Ensure the Leftmost Column is All 1s**:
    - We flip entire rows where the first element is 0. This ensures that the most significant bit of each row contributes maximally to the total score.
2. **Optimize Each Column**:
    - For each column (except the first), count how many 1s there are. If there are fewer 1s than 0s, we flip the column. This increases the number of 1s and thus the overall score.
3. **Calculate the Score**:
    - Convert each row's binary representation to its decimal form and sum these values.

### Explain Like I'm Five

Imagine you have a game board with rows of light switches, and each switch can be on (1) or off (0). Your goal is to make the lights show the highest possible numbers.

First, you make sure that every row starts with a switch that's on because the first switch is the most important and makes the biggest difference in the score.

Next, you look at each column of switches, and if more than half of the switches in a column are off, you flip all the switches in that column. This way, you get more switches turned on, which increases your score.

Finally, you look at the rows, treat the on and off switches as binary numbers, and add up the values to get your final score.

## Notes

---

 

## Related Videos

---

[https://www.youtube.com/watch?v=FbhzRA5den8&pp=ygUkc2NvcmUgYWZ0ZXIgZmxpcHBpbmcgbWF0cml4IGxlZXRjb2Rl](https://www.youtube.com/watch?v=FbhzRA5den8&pp=ygUkc2NvcmUgYWZ0ZXIgZmxpcHBpbmcgbWF0cml4IGxlZXRjb2Rl)