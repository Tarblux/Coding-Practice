Problem: 2013
Official Difficulty: medium
Link: https://leetcode.com/problems/detect-squares/description/
Completed On : 2024-12-19
Feels Like : Brain Damage
Topic: array, hash table, design, Counting
My Understanding: Needs Review
Last Review: 2024-12-19
Days Since Review: 3
Name: Detect Squares

# Detect Squares
### Problem
___
You are given a stream of points on the X-Y plane. Design an algorithm that:
- **Adds** new points from the stream into a data structure. **Duplicate** points are allowed and should be treated as different points.
- Given a query point, **counts** the number of ways to choose three points from the data structure such that the three points and the query point form an **axis-aligned square** with **positive area**.
An **axis-aligned square** is a square whose edges are all the same length and are either parallel or perpendicular to the x-axis and y-axis.
Implement the `DetectSquares` class:
- `DetectSquares()` Initializes the object with an empty data structure.
- `void add(int[] point)` Adds a new point `point = [x, y]` to the data structure.
- `int count(int[] point)` Counts the number of ways to form **axis-aligned squares** with point `point = [x, y]` as described above.
**Example 1:**
![image.png](https://assets.leetcode.com/uploads/2021/09/01/image.png)
```plain text
Input
["DetectSquares", "add", "add", "add", "count", "count", "add", "count"]
[[], [[3, 10]], [[11, 2]], [[3, 2]], [[11, 10]], [[14, 8]], [[11, 2]], [[11, 10]]]
Output
[null, null, null, null, 1, 0, null, 2]

Explanation
DetectSquares detectSquares = new DetectSquares();
detectSquares.add([3, 10]);
detectSquares.add([11, 2]);
detectSquares.add([3, 2]);
detectSquares.count([11, 10]); // return 1. You can choose:
                               //   - The first, second, and third points
detectSquares.count([14, 8]);  // return 0. The query point cannot form a square with any points in the data structure.
detectSquares.add([11, 2]);    // Adding duplicate points is allowed.
detectSquares.count([11, 10]); // return 2. You can choose:
                               //   - The first, second, and third points
                               //   - The first, third, and fourth points

```
**Constraints:**
- `point.length == 2`
- `0 <= x, y <= 1000`
- At most `3000` calls **in total** will be made to `add` and `count`.
### My Solutions
___
```python
class DetectSquares:

    def __init__(self):

        self.points = defaultdict(int)
        
    def add(self, point: List[int]) -> None:

        self.points[tuple(point)] += 1

    def count(self, point: List[int]) -> int:

        output = 0
        x1, y1 = point # Corner 1

        for (x2,y2), count in self.points.items():

            corner2 = abs(x1-x2) == abs(y1-y2)
              
            if x1 != x2 and corner2:

                corner3 = (x1, y2)
                corner4 = (x2,y1)
                if corner3 in self.points and corner4 in self.points:
                    output += self.points[corner3] * self.points[corner4] * count
                    print(f'corners: 1:{(x1,y1)} 2:{(x2,y2)} 3:{(x1,y2)} 4:{(x2,y1)}')

        return output

# Your DetectSquares object will be instantiated and called as such:
# obj = DetectSquares()
# obj.add(point)
# param_2 = obj.count(point)
```

Time Complexity :
```python

```

Time Complexity : 
### Optimal Solutions
___
Here’s the solution for **LeetCode 2013: Detect Squares**, where we efficiently track and detect squares using a dictionary-based approach.
___
#### **Approach**
The problem involves detecting squares in a 2D plane when points are added. A square requires:
- Two points with the same x-coordinate and two points with the same y-coordinate, forming perpendicular sides.
We use a dictionary to efficiently store and query the points.
___
#### **Steps**
#### **1. Data Structure**
- Use a dictionary `point_count` to store the frequency of each point:
	- Key: `(x, y)` coordinate.
	- Value: Frequency of that point.
- This allows efficient updates and queries.
___
#### **2. Adding Points**
- Increment the count for the given point `(x, y)` in the `point_count` dictionary.
___
#### **3. Detecting Squares**
For a query point `(qx, qy)`:
1. **Find Potential Diagonal Points:**
	- Iterate over all points `(px, py)` in `point_count`.
	- A valid diagonal exists if `px != qx` and `abs(px - qx) == abs(py - qy)` (side length of a square).
2. **Count Valid Squares:**
	- For each valid diagonal `(px, py)`, find the other two points of the square:
		- `(qx, py)` (shares y-coordinate with `(px, py)`).
		- `(px, qy)` (shares x-coordinate with `(px, py)`).
	- Multiply their frequencies from `point_count` to calculate the total number of squares.
___
#### **Code Implementation**
```python
from collections import defaultdict

class DetectSquares:

    def __init__(self):
        self.point_count = defaultdict(int)

    def add(self, point: List[int]) -> None:
        x, y = point
        self.point_count[(x, y)] += 1

    def count(self, point: List[int]) -> int:
        qx, qy = point
        square_count = 0

        for (px, py), freq in self.point_count.items():
            # Ensure it forms a valid diagonal
            if px != qx and abs(px - qx) == abs(py - qy):
                # Calculate the count of squares
                square_count += (
                    freq *
                    self.point_count.get((qx, py), 0) *
                    self.point_count.get((px, qy), 0)
                )

        return square_count

```
___
#### **Explanation**
3. **Initialization:**
	- `point_count` tracks the frequency of each point added.
4. **Add Operation:**
	- Increment the count of the given point `(x, y)` in `point_count`.
5. **Count Operation:**
	- For each potential diagonal `(px, py)`:
		- Check if it forms a valid diagonal with `(qx, qy)`.
		- If valid, multiply the frequencies of the two remaining points `(qx, py)` and `(px, qy)` to calculate the number of squares.
	- Sum these values for all potential diagonals.
___
#### **Complexity Analysis**
- **Add Operation:**
	- Time complexity: O(1), since it’s a simple dictionary update.
- **Count Operation:**
	- Time complexity: O(n), where `n` is the number of unique points in `point_count`. We iterate through all points to check for diagonals.
- **Space Complexity:**
	- O(n), where `n` is the number of unique points stored in `point_count`.
___
#### **Example Walkthrough**
**Operations:**
```python
ds = DetectSquares()
ds.add([3, 10])
ds.add([11, 2])
ds.add([3, 2])
print(ds.count([11, 10]))  # Output: 1

```
**Explanation:**
6. Add points `[3, 10]`, `[11, 2]`, `[3, 2]`:
	- `point_count = {(3, 10): 1, (11, 2): 1, (3, 2): 1}`.
7. Count squares for `[11, 10]`:
	- Diagonal with `[3, 10]`:
		- Check `(11, 2)` and `(3, 2)`: both exist in `point_count`.
		- Result: `1 * 1 * 1 = 1`.
	- Total count = 1.
___
#### **Advantages of the Approach**
- Efficient for both `add` and `count` operations.
- Uses space proportional to the number of unique points, which is manageable for most practical cases.
This method ensures correctness and efficiency, leveraging dictionaries for quick lookups and updates.
### Notes
___
 
### Related Videos 
___
[bahebearrDc](https://youtu.be/bahebearrDc)