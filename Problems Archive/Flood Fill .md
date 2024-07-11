# Flood Fill

Problem: 733
Official Difficulty: easy
Feels Like : medium
My Understanding: Mostly Understand
Topic: Breadth-First Search(BFS), Depth-First Search (DFS), Matrix, array
Link: https://leetcode.com/problems/flood-fill/description/
Completed On : July 2, 2024
Last Review: July 2, 2024
Days Since Review: 9

## Problem

---

An image is represented by an `m x n` integer grid `image` where `image[i][j]` represents the pixel value of the image.

You are also given three integers `sr`, `sc`, and `color`. You should perform a **flood fill** on the image starting from the pixel `image[sr][sc]`.

To perform a **flood fill**, consider the starting pixel, plus any pixels connected **4-directionally** to the starting pixel of the same color as the starting pixel, plus any pixels connected **4-directionally** to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with `color`.

Return *the modified image after performing the flood fill*.

**Example 1:**

![https://assets.leetcode.com/uploads/2021/06/01/flood1-grid.jpg](https://assets.leetcode.com/uploads/2021/06/01/flood1-grid.jpg)

```
Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation: From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected to the starting pixel.
```

**Example 2:**

```
Input: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, color = 0
Output: [[0,0,0],[0,0,0]]
Explanation: The starting pixel is already colored 0, so no changes are made to the image.
```

**Constraints:**

- `m == image.length`
- `n == image[i].length`
- `1 <= m, n <= 50`
- `0 <= image[i][j], color < 216`
- `0 <= sr < m`
- `0 <= sc < n`

## My Solutions

---

```python
class Solution:

    def dfs(self,image,sr,sc,original_color,color):

        if sr < 0 or sr >= len(image) or sc < 0 or sc >= len(image[0]):
            return

        if image[sr][sc] != original_color:
            return

        image[sr][sc] = color

        directions = [(-1,0),(1,0),(0,-1),(0,1)]

        for dr , dc in directions:
            self.dfs(image,sr + dr, sc + dc,original_color,color)

    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:

        original_color = image[sr][sc]

        if original_color == color:
            return image

        self.dfs(image,sr,sc,original_color,color)

        return image
```

```python

```

## Optimal Solutions

---

To solve this problem, we can use both DFS and BFS approaches to perform the flood fill. Here, we'll provide both solutions.

### Steps:

1. **DFS (Depth-First Search)**:
    - Use recursion to explore the image.
    - Start from the pixel at (sr, sc) and replace its color if it matches the original color.
    - Recursively apply the fill to the neighboring pixels (up, down, left, right).
2. **BFS (Breadth-First Search)**:
    - Use a queue to iteratively explore and fill the image.
    - Start from the pixel at (sr, sc) and enqueue it.
    - Dequeue and fill the color, then enqueue the neighboring pixels if they match the original color.

### Python Code for DFS

```python
def floodFill(image, sr, sc, newColor):
    originalColor = image[sr][sc]
    if originalColor == newColor:
        return image

    def dfs(r, c):
        if image[r][c] == originalColor:
            image[r][c] = newColor
            if r >= 1: dfs(r-1, c)
            if r + 1 < len(image): dfs(r+1, c)
            if c >= 1: dfs(r, c-1)
            if c + 1 < len(image[0]): dfs(r, c+1)

    dfs(sr, sc)
    return image
```

### Python Code for BFS

```python
from collections import deque

def floodFill(image, sr, sc, newColor):
    originalColor = image[sr][sc]
    if originalColor == newColor:
        return image
    queue = deque([(sr, sc)])
    while queue:
        r, c = queue.popleft()
        if image[r][c] == originalColor:
            image[r][c] = newColor
            if r >= 1: queue.append((r-1, c))
            if r + 1 < len(image): queue.append((r+1, c))
            if c >= 1: queue.append((r, c-1))
            if c + 1 < len(image[0]): queue.append((r, c+1))

    return image
```

### Explanation

1. **DFS Approach**:
    - A helper function `dfs` is used to apply the flood fill recursively.
    - It checks the current pixel's color and applies the new color if it matches the original color.
    - The function recursively calls itself for the neighboring pixels.
2. **BFS Approach**:
    - A queue is used to hold the pixels to be processed.
    - Pixels are dequeued, filled with the new color if they match the original color, and their neighbors are enqueued.

### Time Complexity Analysis

- **Time Complexity**: `O(m * n)`
    - Each pixel is processed once in both BFS and DFS methods, where `m` and `n` are the dimensions of the image.

### Space Complexity Analysis

- **Space Complexity for DFS**: `O(m * n)`
    - In the worst case, the recursion stack may go as deep as the number of pixels in the image.
- **Space Complexity for BFS**: `O(m * n)`
    - The queue can hold all pixels in the worst case scenario.

Both BFS and DFS are efficient methods for performing a flood fill, with the choice between them often depending on the specific problem constraints and personal preference.

## Notes

---

 

## Related Videos

---

[https://www.youtube.com/watch?v=VuiXOc81UDM&pp=ygUKRmxvb2QgRmlsbA%3D%3D](https://www.youtube.com/watch?v=VuiXOc81UDM&pp=ygUKRmxvb2QgRmlsbA%3D%3D)