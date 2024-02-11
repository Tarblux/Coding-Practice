# Minimum Area Rectangle

Problem: 939
Official Difficulty: medium
Feels Like : medium
Topic: Math, array, geometry, hash table, sorting
Link: https://leetcode.com/problems/minimum-area-rectangle/description/
Completed On : January 24, 2024
My Understanding: Needs Review
Last Review: January 24, 2024
Days Since Review: 17

## Problem

---

You are given an array of points in the **X-Y** plane `points` where `points[i] = [xi, yi]`.

Return *the minimum area of a rectangle formed from these points, with sides parallel to the X and Y axes*. If there is not any such rectangle, return `0`.

**Example 1:**

![https://assets.leetcode.com/uploads/2021/08/03/rec1.JPG](https://assets.leetcode.com/uploads/2021/08/03/rec1.JPG)

```
Input: points = [[1,1],[1,3],[3,1],[3,3],[2,2]]
Output: 4
```

**Example 2:**

![https://assets.leetcode.com/uploads/2021/08/03/rec2.JPG](https://assets.leetcode.com/uploads/2021/08/03/rec2.JPG)

```
Input: points = [[1,1],[1,3],[3,1],[3,3],[4,1],[4,3]]
Output: 2
```

**Constraints:**

- `1 <= points.length <= 500`
- `points[i].length == 2`
- `0 <= xi, yi <= 4 * 104`
- All the given points are **unique**.

## My Solutions

---

```python
class Solution:
    def minAreaRect(self, points: List[List[int]]) -> int:

        horizontal_lines = {}

        vertical_lines = {}

        min_area = float('inf')

        for x, y in points:

            if y not in horizontal_lines:

                horizontal_lines[y] = []

            horizontal_lines[y].append(x)

            if x not in vertical_lines:

                vertical_lines[x] = []
                
            vertical_lines[x].append(y)

        for line in horizontal_lines.values():

            line.sort()

        for line in vertical_lines.values():

            line.sort()

        for x, y in points:

            for prev_x in horizontal_lines[y]:

                if prev_x >= x:

                    continue

                for prev_y in vertical_lines[x]:

                    if prev_y >= y:

                        continue

                    if prev_y in vertical_lines[prev_x]:

                        min_area = min(min_area, abs(x - prev_x) * abs(y - prev_y))

        return 0 if min_area == float('inf') else min_area
```

```python

```

## Optimal Solutions

---

The "Minimum Area Rectangle" problem involves finding the rectangle with the smallest area formed from a set of points on a 2D plane. If no rectangle can be formed, the area is considered to be 0.

### Correct Approach

To solve this problem, you can use a combination of sorting and hashing. The key idea is to consider each pair of points that can potentially form the opposite corners of a rectangle and then check if the other two corners exist.

### Python Implementation

Here's an implementation of this approach:

```python
class Solution:
    def minAreaRect(self, points: List[List[int]]) -> int:
        point_set = set(map(tuple, points))
        min_area = float('inf')
        found = False

        for i in range(len(points)):
            for j in range(i + 1, len(points)):
                x1, y1 = points[i]
                x2, y2 = points[j]

                # Check if points can be diagonal corners of a rectangle
                if x1 != x2 and y1 != y2:
                    if (x1, y2) in point_set and (x2, y1) in point_set:
                        area = abs(x1 - x2) * abs(y1 - y2)
                        if area < min_area:
                            min_area = area
                            found = True

        return min_area if found else 0

```

### Explanation

- Store all points in a set `point_set` for O(1) lookup.
- Iterate through each pair of points. For each pair (`points[i]` and `points[j]`), check if they can form diagonal corners of a rectangle (`x1 != x2 and y1 != y2`).
- If they can be diagonal corners, check if the other two corners of the rectangle (`(x1, y2)` and `(x2, y1)`) exist in `point_set`.
- If a valid rectangle is found, calculate its area and update `min_area` if this area is smaller.
- If at least one rectangle is found, return `min_area`; otherwise, return 0.

### Complexity Analysis

- **Time Complexity**: O(n^2) in the worst case, where `n` is the number of points. This is due to the nested iteration over pairs of points.
- **Space Complexity**: O(n) for the set storing the points.

This solution efficiently finds the smallest area of any rectangle that can be formed from the given points. It handles the case where no rectangle can be formed by returning an area of 0.

### Explain Like I am Five (ELI5)

---

## Notes

---

 

## Related Videos

---

[https://www.youtube.com/watch?v=IQKIm0wEu4w](https://www.youtube.com/watch?v=IQKIm0wEu4w)