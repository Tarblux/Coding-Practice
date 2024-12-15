Problem: 84
Official Difficulty: hard
Link: https://leetcode.com/problems/largest-rectangle-in-histogram/description/
Completed On : 2024-12-10
Feels Like : Brain Damage
Topic: array, Stack, monotonic stack
My Understanding: Needs Review
Last Review: 2024-12-10
Days Since Review: 5
Name: Largest Rectangle in Histogram

# Largest Rectangle in Histogram
### Problem
___
Given an array of integers `heights` representing the histogram's bar height where the width of each bar is `1`, return *the area of the largest rectangle in the histogram*.
**Example 1:**
![histogram.jpg](https://assets.leetcode.com/uploads/2021/01/04/histogram.jpg)
```plain text
Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.

```
**Example 2:**
![histogram-1.jpg](https://assets.leetcode.com/uploads/2021/01/04/histogram-1.jpg)
```plain text
Input: heights = [2,4]
Output: 4

```
**Constraints:**
- `1 <= heights.length <= 105`
- `0 <= heights[i] <= 104`
### My Solutions
___
```python
class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:

        stack = []
        max_area = 0

        for i in range(len(heights)):

            while stack and heights[stack[-1]] > heights[i]:

                height = heights[stack.pop()]
                width = i if not stack else i - stack[-1] - 1
                max_area = max(max_area,height * width)

            stack.append(i)

        while stack:

            height = heights[stack.pop()]
            width = len(heights) if not stack else len(heights) - stack[-1] - 1
            max_area = max(max_area , height * width)

        return max_area
```

Time Complexity :
```python

```

Time Complexity : 
Great question! Let's break down why the width is calculated as `n` in the second `while stack` loop for the remaining bars.
___
#### **Understanding the Second **`**while stack**`** Loop**
The purpose of this loop is to process any remaining heights in the stack after we've finished iterating through the histogram. These heights correspond to bars that extend to the **end of the histogram** because no smaller bar was encountered after them.
In the second `while stack` loop, the stack is processed until it's empty. For each height popped from the stack:
- `**height**`**:** The height of the bar being popped.
- `**width**`**:** The horizontal extent of the rectangle that this bar can form.
#### **Why **`**width = n**`**?**
When a bar is popped, the **width** of the rectangle depends on whether the stack is empty or not:
1. **Case 1: The Stack is Empty**
	- If the stack is empty after popping, it means the popped bar extends **all the way to the start and end of the histogram**.
	- In this case:
		- `width = n`, where `n` is the total number of bars in the histogram.
	- This happens because there are no smaller bars to the left of the current bar.
2. **Case 2: The Stack is Not Empty**
	- If the stack is not empty after popping, the rectangle extends **from the bar at the top of the stack to the end of the histogram**.
	- In this case:
		- `width = n - stack[-1] - 1`.
	- The term `n - stack[-1] - 1` ensures that the width is calculated between the index of the last smaller bar (at `stack[-1]`) and the end of the histogram.
___
#### **Why Does This Work?**
The stack ensures that for any bar being processed:
- All bars to its left (still in the stack) are **smaller** than it.
- Any bar to its right (already processed) is **smaller** than it.
Thus, when the stack is empty, the bar can safely extend across the entire histogram.
___
#### **Example Walkthrough**
#### Histogram:
```python
heights = [2, 1, 5, 6, 2, 3]
n = 6

```
#### After the First Loop:
The stack contains indices of bars that extend to the end of the histogram:
```python
stack = [1, 4, 5]

```
#### Processing the Remaining Bars:
3. **Pop **`**5**`**:**
	- `height = heights[5] = 3`
	- Stack after pop: `[1, 4]`
	- `width = n - stack[-1] - 1 = 6 - 4 - 1 = 1`
	- Area: `height * width = 3 * 1 = 3`
4. **Pop **`**4**`**:**
	- `height = heights[4] = 2`
	- Stack after pop: `[1]`
	- `width = n - stack[-1] - 1 = 6 - 1 - 1 = 4`
	- Area: `height * width = 2 * 4 = 8`
5. **Pop **`**1**`**:**
	- `height = heights[1] = 1`
	- Stack after pop: `[]` (empty)
	- `width = n = 6` (extends across the entire histogram)
	- Area: `height * width = 1 * 6 = 6`
___
#### **Key Takeaways**
- The width calculation in the second `while stack` loop depends on whether the stack is empty or not:
	- **Empty stack:** `width = n` because the rectangle extends across the entire histogram.
	- **Non-empty stack:** `width = n - stack[-1] - 1` because the rectangle extends between the top of the stack and the end of the histogram.
- This ensures that every rectangle is considered correctly, even for bars that extend to the end of the histogram.
Let me know if you need further clarification!
### Optimal Solutions
___
#### 1. Brute Force (O(n²))
- For each bar `i`, expand left and right to find how far you can extend the rectangle with the height of the bar `i`.
- Compute area at each step.
- Time complexity is O(n²), which is too slow for large inputs.
#### 2. Stack-Based Optimal Solution (O(n))
**Idea:**
- Use a stack to keep track of indices of bars.
- The stack ensures that heights are in ascending order.
- When we encounter a bar that is lower than the top of the stack, it means we've found a boundary for the rectangle of the bar at the top of the stack.
- We pop from the stack and calculate the area:
	- The height of the popped bar is the limiting height.
	- The width is determined by the current index and the index of the bar on the top of the stack after popping.
**Steps:**
6. Initialize an empty stack.
7. Append a sentinel height 0 at the end of the heights array. This ensures that all bars will be popped by the end.
8. Iterate through each bar (including the sentinel):
	- While the stack is not empty and the current bar's height is less than the height of the bar at the top of the stack:
		- Pop the top of the stack. Let this index be `top`.
		- The height for the rectangle is `heights[top]`.
		- If the stack is empty after popping, the width is the current index `i`.
		- Otherwise, the width is `i - stack[-1] - 1`.
		- Compute the area and update the maximum area if necessary.
	- Push the current index onto the stack.
9. Return the maximum area found.
**Why this works:**
- By maintaining an ascending stack of heights, when we encounter a bar that breaks the ascending order, it means we've reached the end of a potential rectangle region.
- Popping from the stack effectively calculates the largest rectangle possible with the popped bar as the smallest height.
**Time Complexity:** O(n)
- Each bar is pushed and popped at most once.
**Space Complexity:** O(n) for the stack.
___
### Code Implementation
```python
class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        # Append a sentinel value (0) to ensure all bars are popped
        heights.append(0)
        stack = []  # will store indices of bars
        max_area = 0

        for i, h in enumerate(heights):
            # While current bar is smaller than the top of stack
            # it means we can finalize the rectangle for the bar at top of stack
            while stack and heights[stack[-1]] > h:
                top = stack.pop()
                height = heights[top]

                # If stack is empty, width = i
                # else width = i - stack[-1] - 1
                if not stack:
                    width = i
                else:
                    width = i - stack[-1] - 1

                # Update max_area
                max_area = max(max_area, height * width)

            # Push current index onto stack
            stack.append(i)

        return max_area

```
___
### Example Walkthrough
**Example:** heights = [2, 1, 5, 6, 2, 3]
- Add a sentinel: [2, 1, 5, 6, 2, 3, 0]
- Start with `stack = []`, `max_area = 0`.
i=0 (h=2): stack = [0]
i=1 (h=1): since heights[stack[-1]] = 2 > 1, pop 0
- height = 2
- stack empty => width = i = 1
- area = 2*1=2, max_area=2
stack = [], then push i=1 => stack=[1]
i=2 (h=5): stack = [1, 2]
i=3 (h=6): stack = [1, 2, 3]
i=4 (h=2): now heights[3]=6 > 2, pop 3
- height=6
- stack=[1,2], width=i - 2 -1 =4-2-1=1
- area=6*1=6, max_area=6
heights[2]=5 >2, pop 2
- height=5
- stack=[1], width=4-1-1=2
- area=5*2=10, max_area=10
heights[1]=1<2 stop popping
stack=[1,4]
i=5 (h=3): heights[4]=2<3 no pop, stack=[1,4,5]
i=6 (h=0, sentinel): pop while stack:
pop 5:
height=3
stack=[1,4], width=6-4-1=1
area=3*1=3, max_area=10
pop 4:
height=2
stack=[1], width=6-1-1=4
area=2*4=8, max_area=10
pop 1:
height=1
stack=[], width=6
area=1*6=6, max_area=10
All popped, final max_area=10.
___
### Testing the Solution
- [2,1,5,6,2,3] => 10 (as shown above)
- [2,4] => max area = 4
- [2,2,2] => max area = 2*3=6
- [1,1,1,1] => max area = 1*4=4
- [1] => max area = 1
All correct.
___
### Conclusion
The stack-based O(n) approach is the optimal solution to finding the largest rectangle in a histogram. It efficiently calculates areas of potential largest rectangles by managing an ascending stack and popping only when necessary, leading to a linear time complexity and meeting the problem constraints effectively.
### Notes
___
#### Medz how he adds zero at the end and start to avoid doing the second while loop
Gonna try to explain the intuition behind this problem, as I too found the "linear" explanation confusing.
First thing to note is that there are N rectangles that need to be considered. This isn't immediately obvious, it helps to draw them out on a piece of paper. But once you see that there are N rectangles, the problem simply boils down to iterating through each one, which of course is linear.
How do we iterate through N rectangles? The obvious approach would be to scan left-to-right and have the index represent the right side of the rectangle. To derive the left side / height, we need a data structure to keep track of columns we've already seen. A stack is usually the choice for these increasing / decreasing columns type of problems.
So we know we're gonna scan left-to-right and keep putting something or other on the stack. Now to work out the specifics.
The column heights in the example are [6, 7, 5, ...]. What happens when we get to 5? The thing to note is that from perspective of any columns to the right of it, 6 and 7 don't matter. The height will be 5 or smaller. So come 5, that's the only thing that should be on the stack.
What about 6 and 7? It looks like we'll need both on the stack, cause we'll need to consider rectangles of heights 6 and 7. We don't know how far to the right those rectangles will extend, so we'll just put (column, height) onto the stack. Once we see 5, that's the right-hand border for these rectangles and that's when we can consider them.
So the algorithm boils down to:
10. Maintain a stack such that heights are always in increasing order.
11. When we see a column that's lower than what's on the stack
	- Use it as the right side and compute all the possible rectangles using what's on the stack to derive left side and height.
	- Remove each considered rectangle / column from the stack
Hope this helps convey the intuition. Code below just for reference:
```python
def largestRectangleArea(self, heights: List[int]) -> int:
    maxArea = 0
    stack = [] # list[(column, height)]
    
    for i, height in enumerate(chain([0], heights, [0])): # append zero heights at both ends
        while stack and stack[-1][1] > height:
            rect_right = i
            rect_height = stack.pop()[1]
            rect_left = stack[-1][0]
            area = (rect_right - rect_left - 1) * rect_height
            maxArea = max(area, maxArea)
        
        stack.append((i, height))
        
    return maxArea
```
Great explanation, just wanted to clarify the point where he adding 0 to the end of heights array. The idea is to store in stack increasing bars so, when the heights itself is increasing we will never pop from stack and calculate the areas, so we needed another loop after this for loop to calculate bars in stack. Adding 0 in end of the heights will make sure we pop all bars from stack because all values should be greater than 0.
### Related Videos 
___
[lktr76SxB2w](https://youtu.be/lktr76SxB2w)
[watch](https://www.youtube.com/watch?v=zx5Sw9130L0&t=282s&pp=ygUebGFyZ2VzdCByZWN0YW5nbGUgaW4gaGlzdG9ncmFt)