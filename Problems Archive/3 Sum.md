# 3 Sum

Problem: 15
Official Difficulty: medium
Feels Like : medium
Topic: array, sorting, two pointers
Link: https://leetcode.com/problems/3sum/
Completed On : December 20, 2023
My Understanding: I Have No Idea
Last Review: December 20, 2023
Days Since Review: 52

## Problem

---

Given an integer array nums, return all the triplets `[nums[i], nums[j], nums[k]]` such that `i != j`, `i != k`, and `j != k`, and `nums[i] + nums[j] + nums[k] == 0`.

Notice that the solution set must not contain duplicate triplets.

**Example 1:**

```
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation:
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.

```

**Example 2:**

```
Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.

```

**Example 3:**

```
Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.

```

**Constraints:**

- `3 <= nums.length <= 3000`
- `105 <= nums[i] <= 105`

## My Solutions

---

```python

```

```python

```

## Optimal Solutions

---

```python
class Solution:
    def threeSum(self, nums):
            
        result = []

        nums.sort()

        for i in range (0,len(nums)) : 

            if i > 0 and nums[i] == nums[i-1] : 

                continue

            right = len(nums) - 1

            left = i + 1

            while left < right : 

                # if i == left:
                #     left += 1
                #     continue
                # if i == right:
                #     right -= 1
                #     continue

                cur_sum = nums[i] + nums[left] + nums[right]

                if cur_sum == 0 :

                    result.append([nums[i],nums[left],nums[right]])

                    while left < right and nums[left] == nums[left + 1]:
                        left += 1
                    
                    while left < right and nums[right] == nums[right - 1]:
                        right -= 1

                    left += 1
                    right -= 1

                if cur_sum < 0 :

                    left += 1

                if cur_sum > 0 :

                    right -= 1
                    
        return result
```

## Notes

---

 

## Related Videos

---

[https://youtu.be/jzZsG8n2R9A](https://youtu.be/jzZsG8n2R9A)