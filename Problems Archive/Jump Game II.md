# Jump Game II

Problem: 45
Official Difficulty: medium
Feels Like : medium
My Understanding: Mostly Understand
Topic: array, dynamic programming, greedy
Link: https://leetcode.com/problems/jump-game-ii/description/
Completed On : March 2, 2024
Last Review: March 7, 2024
Days Since Review: 54

## Problem

---

You are given a **0-indexed** array of integers `nums` of length `n`. You are initially positioned at `nums[0]`.

Each element `nums[i]` represents the maximum length of a forward jump from index `i`. In other words, if you are at `nums[i]`, you can jump to any `nums[i + j]` where:

- `0 <= j <= nums[i]` and
- `i + j < n`

Return *the minimum number of jumps to reach* `nums[n - 1]`. The test cases are generated such that you can reach `nums[n - 1]`.

**Example 1:**

```
Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
```

**Example 2:**

```
Input: nums = [2,3,0,1,4]
Output: 2
```

**Constraints:**

- `1 <= nums.length <= 104`
- `0 <= nums[i] <= 1000`
- It's guaranteed that you can reach `nums[n - 1]`.

## My Solutions

---

```python
class Solution:
    def jump(self, nums: List[int]) -> int:

        min_jump = 0 
        max_index = 0
        destination = len(nums)-1
        local_max = 0

        for i in range(destination):

            landing_position = i + nums[i]
            max_index = max(max_index, landing_position)

            if i >= local_max :
            
                min_jump += 1
                local_max = max_index

        return min_jump
```

**Neetcode Solution**

```python
class Solution: 

	def jump(self,nums:list[int]) -> int:

			res = 0
			l = r = 0
			while r > len(nums) - 1 : 

				farthest = 0

				for i in range(1,r+1):
						farthest = max(farthest , i + nums[i])
				l = r + 1
				r = farthest
				res += 1
			return res
```

## Optimal Solutions

---

The optimal solution to the "Jump Game II" problem, where you need to find the minimum number of jumps required to reach the last index of an array (where each element represents the maximum jump length at that position), involves using a greedy approach. The idea is to dynamically update the farthest reach possible while iterating through the array and to count the jumps needed to reach the end.

### Key Idea

The key insight is to maintain two pointers: one to track the farthest reach within the current jump (`farthest`) and another to track the edge of the current jump (`end`). Instead of calculating all possible jumps at each step, you only update the jump count when you reach the `end` of the current jump range, indicating that you need another jump to go further.

### Python Implementation

```python
class Solution:
    def jump(self, nums: List[int]) -> int:
        jumps = 0
        end = 0
        farthest = 0
        for i in range(len(nums) - 1):  # Exclude the last index since you don't need to jump from the last position
            farthest = max(farthest, i + nums[i])  # Update the farthest reach from the current position
            if i == end:  # Need to make a jump to continue
                jumps += 1
                end = farthest  # Update the end to the farthest reach
        return jumps
```

### Explanation

- **Initialization**: Start with `jumps = 0`, `end = 0`, and `farthest = 0`. These variables track the number of jumps made, the current jump's reach, and the farthest reach observed while processing the current jump, respectively.
- **Iterate Through the Array**: Loop through the array up to the second-to-last element. The last element doesn't require a jump, so it's excluded from the loop.
- **Update Farthest Reach**: For each position, calculate how far you can reach from that position (`i + nums[i]`) and update `farthest` if this is beyond the current `farthest`.
- **Jump and Update End**: If the current position `i` reaches the `end` of the current jump, it means you must jump to proceed further. Increment `jumps` and set `end` to `farthest` to extend the reachable range.
- **Return Jumps**: After the loop, `jumps` will contain the minimum number of jumps needed to reach the last index.

### Complexity Analysis

- **Time Complexity**: O(N), where N is the number of elements in the input array. The array is traversed once.
- **Space Complexity**: O(1), as the solution uses a constant amount of space regardless of the input size.

This greedy approach efficiently finds the minimum number of jumps by always choosing the farthest reachable position within the current jump, minimizing the total number of jumps needed to reach the end of the array.

## Notes

---

 

## Related Videos

---

[https://youtu.be/dJ7sWiOoK7g](https://youtu.be/dJ7sWiOoK7g)