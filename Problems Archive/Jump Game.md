# Jump Game

Problem: 55
Official Difficulty: medium
Feels Like : medium
Topic: array, greedy
Link: https://leetcode.com/problems/jump-game/
Completed On : January 8, 2024
My Understanding: Needs Review
Last Review: January 8, 2024
Days Since Review: 33

## Problem

---

You are given an integer array `nums`. You are initially positioned at the array's **first index**, and each element in the array represents your maximum jump length at that position.

Return `true` *if you can reach the last index, or* `false` *otherwise*.

**Example 1:**

```
Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

```

**Example 2:**

```
Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.

```

**Constraints:**

- `1 <= nums.length <= 104`
- `0 <= nums[i] <= 105`

## My Solutions

---

```python
class Solution:
    def canJump(self, nums: List[int]) -> bool:

        if len(nums) <= 1 : 

            return True

        max_index = 0

        for i in range(0,len(nums)-1) : 

            possible_index = i + nums[i]

            max_index = max(max_index , possible_index)

            if i >= max_index : 

                return False
       
        return True
```

### Sanya

```python
class Solution:
    def canJump(self, nums: List[int]) -> bool:
    
        if len(nums) == 1: return True
        
        destination = len(nums) - 1
        lastToReach = nums[0]
        i = 0
        while i < len(nums):
            num = nums[i]
            lastToReach = max(lastToReach, i + num)
            if lastToReach >= destination:
                return True
            if num == 0:
                if lastToReach <= 0 or i == lastToReach:
                    return False
                while num != 0 and lastToReach != 0:
                    lastToReach -= 1
                    i += 1
            i += 1
        
        return False
```

## Optimal Solutions

---

The optimal solution for the "Jump Game" problem (LeetCode 55) uses a greedy approach. The problem asks whether you can reach the last index of the array, where each element in the array represents your maximum jump length at that position.

### Solution Approach: Greedy

In a greedy approach, the idea is to iterate through the array and keep track of the furthest index that can be reached at each step. If at any point, the furthest reachable index is less than the current index, it means you can't proceed further, and therefore can't reach the end. If you can reach or surpass the last index, then you can reach the end of the array.

### Python Implementation

```python
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        furthest_reachable = 0
        n = len(nums)

        for i in range(n):
            # If current index is greater than the furthest reachable index,
            # it means we can't reach this point, hence can't jump to the end
            if i > furthest_reachable:
                return False

            # Update the furthest reachable index
            furthest_reachable = max(furthest_reachable, i + nums[i])

            # If the furthest reachable index is beyond or at the last index
            if furthest_reachable >= n - 1:
                return True

        return False  # This line is for safety, theoretically, it should never be reached

```

### Explanation

- You iterate through the array with index `i`.
- If `i` is greater than `furthest_reachable`, it's impossible to reach `i` (and therefore impossible to reach the end), so return `False`.
- Update `furthest_reachable` to be the maximum of its current value and `i + nums[i]` (the furthest you can reach from the current position).
- If at any point `furthest_reachable` reaches or exceeds the last index (`n - 1`), return `True` as it's possible to reach the end.

### Complexity Analysis

- **Time Complexity**: O(n), where n is the number of elements in `nums`. Each element is processed once.
- **Space Complexity**: O(1), as no additional space is used beyond variables for tracking indices.

This greedy approach efficiently solves the problem with a single pass through the array, continually updating the furthest reachable index and checking if the end of the array is reachable.

## Notes

---

 It’s important to read the question thoroughly and make sure I understand exactly what is being asked of me , For this question I failed to realize that cases where you have a zero you can’t move from there. For e.g [0,2,3] you can never reach the final index because you can never past the first one.

## Related Videos

---

[https://youtu.be/Yan0cv2cLy8](https://youtu.be/Yan0cv2cLy8)