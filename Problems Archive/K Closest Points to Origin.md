# K Closest Points to Origin

Problem: 973
Official Difficulty: medium
Feels Like : medium
Topic: Divide and Conquer, Heap, Math, array, geometry, quickselect, sorting
Link: https://leetcode.com/problems/k-closest-points-to-origin/description/
Completed On : January 23, 2024
My Understanding: Needs Review
Last Review: January 23, 2024
Days Since Review: 18

## Problem

---

Given an array of `points` where `points[i] = [xi, yi]` represents a point on the **X-Y** plane and an integer `k`, return the `k` closest points to the origin `(0, 0)`.

The distance between two points on the **X-Y** plane is the Euclidean distance (i.e., `√(x1 - x2)2 + (y1 - y2)2`).

You may return the answer in **any order**. The answer is **guaranteed** to be **unique** (except for the order that it is in).

**Example 1:**

![https://assets.leetcode.com/uploads/2021/03/03/closestplane1.jpg](https://assets.leetcode.com/uploads/2021/03/03/closestplane1.jpg)

```
Input: points = [[1,3],[-2,2]], k = 1
Output: [[-2,2]]
Explanation:
The distance between (1, 3) and the origin is sqrt(10).
The distance between (-2, 2) and the origin is sqrt(8).
Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
We only want the closest k = 1 points from the origin, so the answer is just [[-2,2]].

```

**Example 2:**

```
Input: points = [[3,3],[5,-1],[-2,4]], k = 2
Output: [[3,3],[-2,4]]
Explanation: The answer [[-2,4],[3,3]] would also be accepted.

```

**Constraints:**

- `1 <= k <= points.length <= 104`
- `104 <= xi, yi <= 10`

## My Solutions

---

```python
class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:

        def euclidean(point):

            return point[0]**2 + point[1]**2

        distance_dict = {}

        for point in points:

            distance = euclidean(point)

            if distance not in distance_dict:

                distance_dict[distance] = []

            distance_dict[distance].append(point)

        

        
        sorted_distances = sorted(distance_dict.keys())

        output = []

        for distance in sorted_distances:

            output.extend(distance_dict[distance])

            if len(output) >= k:  

                break

        print(sorted_distances)

        print(distance_dict)

        return output[:k]
```

```python

```

## Optimal Solutions

---

### Explain Like I am Five (ELI5)

---

## Notes

---

 

## Related Videos

---

[https://www.notion.so](https://www.notion.so)