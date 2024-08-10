# Trapping Rain Water

Problem: 42
Official Difficulty: hard
Feels Like : medium
My Understanding: Needs Review
Topic: Stack, array, dynamic programming, monotonic stack, two pointers
Link: https://leetcode.com/problems/trapping-rain-water/description/
Completed On : June 15, 2024
Last Review: June 15, 2024
Days Since Review: 55

## Problem

---

Given `n` non-negative integers representing an elevation map where the width of each bar is `1`, compute how much water it can trap after raining.

**Example 1:**

![https://assets.leetcode.com/uploads/2018/10/22/rainwatertrap.png](https://assets.leetcode.com/uploads/2018/10/22/rainwatertrap.png)

```
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

```

**Example 2:**

```
Input: height = [4,2,0,3,2,5]
Output: 9

```

**Constraints:**

- `n == height.length`
- `1 <= n <= 2 * 104`
- `0 <= height[i] <= 105`

## My Solutions

---

```python
class Solution:
    def trap(self, height: List[int]) -> int:

        """
        - Handle Edge Cases
        - Memoize all Left and right maxes
        - Iterate through all heights and calculate volume of water above :
            area = min(l_max[i],r_max[i]) - height[i]
        - Greedily store total rain water

        TC: O(3N) -> O(N)
        SC: O(N)
        """

        if len(height) < 3:
            return 0

        # Left Memo
        l_max = [0] * len(height)
        l_max[0] = height[0]
        for i in range(1, len(height)):
            l_max[i] = max(height[i], l_max[i - 1])

        # Right Memo
        r_max = [0] * len(height)
        r_max[-1] = height[-1]
        for i in range(len(height) - 2, -1, -1):
            r_max[i] = max(height[i], r_max[i + 1])

        trapped = 0

        for i in range(len(height)):
            cur_water = min(l_max[i], r_max[i]) - height[i]
            trapped += cur_water

        return trapped

```

```python

```

## Optimal Solutions

---

### Problem Description

Given `n` non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

### Example

```python
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6

Input: height = [4,2,0,3,2,5]
Output: 9

```

### Optimal Solution and Explanation

To solve this problem, we need to calculate the trapped water at each index by finding the minimum of the maximum heights to the left and right of that index, and subtracting the height at that index. This can be efficiently achieved using two pointers.

### Steps:

1. **Two Pointers Approach**:
    - Use two pointers, `left` and `right`, starting at the beginning and end of the array, respectively.
    - Use two variables, `left_max` and `right_max`, to keep track of the maximum heights encountered from the left and right.
    - Move the pointers towards each other and update the trapped water at each step based on the `left_max` and `right_max` values.

### Python Code

Here's the Python code to achieve this:

```python
def trap(height):
    if not height:
        return 0

    left, right = 0, len(height) - 1
    left_max, right_max = height[left], height[right]
    water_trapped = 0

    while left < right:
        if left_max < right_max:
            left += 1
            left_max = max(left_max, height[left])
            water_trapped += left_max - height[left]
        else:
            right -= 1
            right_max = max(right_max, height[right])
            water_trapped += right_max - height[right]

    return water_trapped

# Example usage
print(trap([0,1,0,2,1,0,1,3,2,1,2,1]))  # Output: 6
print(trap([4,2,0,3,2,5]))              # Output: 9

```

### Explanation

1. **Initialization**:
    - Initialize `left` to 0 and `right` to `len(height) - 1`.
    - Initialize `left_max` to `height[left]` and `right_max` to `height[right]`.
    - Initialize `water_trapped` to 0.
2. **Two Pointers Traversal**:
    - While `left` is less than `right`:
        - Compare `left_max` and `right_max`:
            - If `left_max` is less than `right_max`, move the `left` pointer one step to the right:
                - Update `left_max` to the maximum of the current `left_max` and `height[left]`.
                - Add `left_max - height[left]` to `water_trapped`.
            - Otherwise, move the `right` pointer one step to the left:
                - Update `right_max` to the maximum of the current `right_max` and `height[right]`.
                - Add `right_max - height[right]` to `water_trapped`.
3. **Return the Result**:
    - Return the total `water_trapped`.

### Time Complexity Analysis

- **Time Complexity**: `O(n)`
    - The algorithm uses a single pass through the array with two pointers, resulting in a linear time complexity.

### Space Complexity Analysis

- **Space Complexity**: `O(1)`
    - The algorithm uses a constant amount of extra space for the pointers and variables.

This approach ensures that the trapped water is calculated efficiently using two pointers, with linear time complexity and constant space complexity.

## Notes

---

 Good Notes in the fucking algorithm repo

[https://labuladong.gitbook.io/algo-en/iv.-high-frequency-interview-problem/trapping_rain_water](https://labuladong.gitbook.io/algo-en/iv.-high-frequency-interview-problem/trapping_rain_water)

## Related Videos

---

[https://youtu.be/ZI2z5pq0TqA](https://youtu.be/ZI2z5pq0TqA)