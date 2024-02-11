# House Robber

Problem: 198
Official Difficulty: medium
Feels Like : medium
Topic: dynamic programming
Link: https://leetcode.com/problems/house-robber/
Completed On : December 5, 2023
My Understanding: I Have No Idea
Last Review: December 5, 2023
Days Since Review: 67

## Problem

---

You are a professional robber planning to rob houses along a street. Each 
house has a certain amount of money stashed, the only constraint 
stopping you from robbing each of them is that adjacent houses have 
security systems connected and **it will automatically contact the police if two adjacent houses were broken into on the same night**.

Given an integer array `nums` representing the amount of money of each house, return *the maximum amount of money you can rob tonight **without alerting the police***.

**Example 1:**

```
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
```

**Example 2:**

```
Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.
```

**Constraints:**

- `1 <= nums.length <= 100`
- `0 <= nums[i] <= 400`

## My Solutions

---

### Sanya

```python
class Solution:
    def rob(self, nums: List[int]) -> int:
        
        #   0,   0 [2, 7, 9, 3, 1]
        #   ↑    ↑
        # 1st  2nd
        
        #            new = max(1st + num, old 2nd) = max(0 + 2, 0)
        #            ↓
        #   0,   0 [*2*, 7, 9, 3, 1]
        #        ↑   
        #     1st = 2nd
        #     2nd = new
        
        
        #               new = max(1st + num, old 2nd) = max(0 + 7, 2)
        #               ↓
        #   0,   0 [2, *7*, 9, 3, 1]
        #           ↑   
        #     1st = 2nd (not just 2, but max)  
        #     2nd = new

        
        #                  new = max(1st + num, old 2nd) = max(2 + 9, 7)
        #                  ↓
        #   0,   0 [2, 7, *9*, 3, 1]
        #              ↑   
        #              1st = 2nd (not just 2, but max)  
        #              2nd = new

        
        #                     new = max(1st + num, old 2nd) = max(10, 11)
        #                     ↓
        #   0,   0 [2, 7, 9, *3*, 1]
        #                 ↑   
        #                 1st = 2nd (not just 2, but max)  
        #                 2nd = new 

        
        firstMax = 0
        secondMax = 0
        
        for i in range(len(nums)):
            num = nums[i]
            newMax = max(firstMax + num, secondMax)
            firstMax = secondMax
            secondMax = newMax
            
        return secondMax
```

```python

```

## Optimal Solutions

### Dynamic Programming Approach

The optimal solution involves using dynamic programming to find the maximum sum of non-adjacent elements in the array. This approach ensures that no two adjacent houses are robbed, adhering to the problem's constraint.

### Algorithm

1. Edge Cases: If the array is empty, return 0. If it contains only one element, return that element since there's only one house to rob.
2. Initialize two variables, `rob1` and `rob2`. Think of them as the maximum loot at the previous and the second previous step, respectively. Initially, set both `rob1` and `rob2` to 0.
3. Iterate through the array:
    - For each house (`nums[i]`), calculate the maximum of two scenarios:
        - Robbing the current house (`nums[i] + rob2`), which means we add the current house's value to the maximum loot from the house before the previous one (since we can't rob two adjacent houses).
        - Not robbing the current house (`rob1`), which means we just carry forward the maximum loot until the previous house.
    - Update `rob2` to `rob1`, and `rob1` to the newly calculated maximum.
4. After iterating through all houses, `rob1` will contain the maximum amount of money that can be robbed.

### Complexity Analysis

- **Time Complexity**: O(n), where n is the number of houses. We only need one pass through the array.
- **Space Complexity**: O(1), as we are using a constant amount of space regardless of the input size.

### Python Implementation

```python
def rob(nums):
    if not nums:
        return 0
    if len(nums) == 1:
        return nums[0]

    rob1, rob2 = 0, 0

    for n in nums:
        newRob = max(n + rob2, rob1)
        rob2 = rob1
        rob1 = newRob

    return rob1

```

### Explanation

This implementation iteratively determines the maximum amount of money that can be robbed up to each house, taking into consideration the constraint that adjacent houses cannot be robbed. The variables `rob1` and `rob2` keep track of the loot calculations as we move through the array. After processing all houses, `rob1` gives us the maximum amount of money that can be robbed.

## Notes

---

 Similar to the other DP stuff with the greedy approach 

## Related Videos

---

[https://www.youtube.com/watch?v=73r3KWiEvyk](https://www.youtube.com/watch?v=73r3KWiEvyk)