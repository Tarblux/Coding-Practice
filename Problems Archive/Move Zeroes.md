# Move Zeroes

Problem: 283
Official Difficulty: easy
Feels Like : easy
Topic: array
Link: https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/567/
Completed On : November 13, 2023
My Understanding: Needs Review
Last Review: November 13, 2023
Days Since Review: 89

## Problem

---

Given an integer array `nums`, move all `0`'s to the end of it while maintaining the relative order of the non-zero elements.

**Note** that you must do this in-place without making a copy of the array.

**Example 1:**

```
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]

```

**Example 2:**

```
Input: nums = [0]
Output: [0]

```

## My Solutions

---

### Tariq

```python
class Solution(object):
    def moveZeroes(self, nums):
       
        index = 0
        
        for i in range (0,len(nums)) : 
            
            if nums[i] != 0 :
                
                nums[index] = nums[i]
                
                index += 1
            
        for i in range(index , len(nums)) : 
            
            nums[i] = 0
```

### Aleksandr (Java)

```python
public void moveZeroes(int[] nums) {
        
        for (int i = nums.length - 1; i >= 1; i--){
            if (nums[i-1] == 0){
                int j = i;
                while(j != nums.length){
                    nums[j-1] = nums[j];
                    nums[j] = 0;
                    j++;
                }
            }
        }
    }
```

## Optimal Solutions

---

## Notes

---

 

## Related Videos

---

[https://www.youtube.com/watch?v=aayNRwUN3Do](https://www.youtube.com/watch?v=aayNRwUN3Do)