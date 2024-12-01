Problem: 1762
Official Difficulty: medium
Link: https://leetcode.com/problems/buildings-with-an-ocean-view/description/?envType=company&envId=facebook&favoriteSlug=facebook-thirty-days
Completed On : 2024-11-23
Feels Like : easy
Topic: array, Stack, monotonic stack
My Understanding: Needs Review
Last Review: 2024-11-23
Days Since Review: 8
Name: Buildings with an Ocean View

# Buildings with an Ocean View
### Problem
___
There are `n` buildings in a line. You are given an integer array `heights` of size `n` that represents the heights of the buildings in the line.
The ocean is to the right of the buildings. A building has an ocean view if the building can see the ocean without obstructions. Formally, a building has an ocean view if all the buildings to its right have a **smaller** height.
Return a list of indices **(0-indexed)** of buildings that have an ocean view, sorted in increasing order.
**Example 1:**
```plain text
Input: heights = [4,2,3,1]
Output: [0,2,3]
Explanation: Building 1 (0-indexed) does not have an ocean view because building 2 is taller.

```
**Example 2:**
```plain text
Input: heights = [4,3,2,1]
Output: [0,1,2,3]
Explanation: All the buildings have an ocean view.

```
**Example 3:**
```plain text
Input: heights = [1,3,2,4]
Output: [3]
Explanation: Only building 3 has an ocean view.

```
**Constraints:**
- `1 <= heights.length <= 105`
- `1 <= heights[i] <= 109`
### My Solutions
___
```python
class Solution:
    def findBuildings(self, heights: List[int]) -> List[int]:

        stack = []

        for i in range(len(heights)):

            while stack and heights[stack[-1]] <= heights[i]:
                stack.pop()

            stack.append(i)

        return stack
```

Time Complexity :
```python

```

Time Complexity : 
### Optimal Solutions
___

### Notes
___
 A lot of comments mentioned that it becomes harder if the data is a stream so think about that a bit : 
[https://leetcode.com/problems/buildings-with-an-ocean-view/editorial/comments/2289039](https://leetcode.com/problems/buildings-with-an-ocean-view/editorial/comments/2289039)
### Related Videos 
___
[]()