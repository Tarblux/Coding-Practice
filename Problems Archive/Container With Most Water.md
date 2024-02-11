# Container With Most Water

Problem: 11
Official Difficulty: medium
Feels Like : easy
Topic: array, greedy, two pointers
Link: https://leetcode.com/problems/container-with-most-water/
Completed On : December 22, 2023
My Understanding: Mostly Understand
Last Review: December 22, 2023
Days Since Review: 50

## Problem

---

You are given an integer array `height` of length `n`. There are `n` vertical lines drawn such that the two endpoints of the `ith` line are `(i, 0)` and `(i, height[i])`.

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return *the maximum amount of water a container can store*.

**Notice** that you may not slant the container.

**Example 1:**

![https://s3-lc-upload.s3.amazonaws.com/uploads/2018/07/17/question_11.jpg](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/07/17/question_11.jpg)

```
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

```

**Example 2:**

```
Input: height = [1,1]
Output: 1

```

**Constraints:**

- `n == height.length`
- `2 <= n <= 105`
- `0 <= height[i] <= 104`

## My Solutions

---

```python
class Solution:
    def maxArea(self, height: List[int]) -> int:

        areas = []

        for i in range (0,len(height)) : 
            
             for ii in range (i,len(height)) : 

                 area = min(height[i],height[ii]) * abs( ii - i) 

                 areas.append(area)

        return max(areas)
```

```python
class Solution:
    def maxArea(self, height: List[int]) -> int:

				right = len(height) - 1
				
				        left = 0 
				
				        max_area = 0 
				
				        while left < right : 
				
				            area = min(height[left],height[right]) * (right - left)
				
				            max_area = max(area,max_area)
				
				            if height[left] > height[right] : 
				
				                right -= 1
				
				                continue 
				
				            
				            if height[left] < height[right] : 
				
				                left += 1 
				
				                continue 
				
				            if height[left] == height[right] : 
				
				                right -= 1
				
				                continue 
				        
				        return max_area
```

## Optimal Solutions

---

### Solution Approach: Two-Pointer Technique

1. **Initialize Two Pointers**: Place one pointer at the start (`left`) and the other at the end (`right`) of the array.
2. **Calculate Area**: For each pair of pointers, calculate the area formed by the lines at the two pointers and the x-axis. The area is calculated as `min(height[left], height[right]) * (right - left)`.
3. **Move Pointers**: Move the pointer pointing to the shorter line towards the other pointer because moving the longer line won't increase the area.
4. **Maximize Area**: Continuously update the maximum area as you move the pointers.
5. **Stop When Pointers Meet**: The process is repeated until the two pointers meet.

### Python Implementation

```python
class Solution:
    def maxArea(self, height: List[int]) -> int:
        left, right = 0, len(height) - 1
        max_water = 0

        while left < right:
            # Calculate the area and update max_water
            width = right - left
            current_water = min(height[left], height[right]) * width
            max_water = max(max_water, current_water)

            # Move the pointer of the shorter line
            if height[left] < height[right]:
                left += 1
            else:
                right -= 1

        return max_water

```

### Explanation

- The area between the lines at `left` and `right` is determined by the shorter of the two lines and the distance between them.
- To find the largest area, the algorithm tries different pairs of lines by moving the pointers. Since the width between lines decreases as the pointers move towards each other, it makes sense to move the pointer at the shorter line in the hope of finding a longer line that increases the area.
- The maximum area found during this process is the answer.

### Complexity Analysis

- **Time Complexity**: O(n), as the algorithm only requires one pass through the array, moving the two pointers from the ends towards the middle.
- **Space Complexity**: O(1), since no additional space is used beyond variables for tracking indices and the maximum area.

## Notes

---

 

## Related Videos

---

[https://youtu.be/UuiTKBwPgAo](https://youtu.be/UuiTKBwPgAo)