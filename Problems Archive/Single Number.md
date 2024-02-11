# Single Number

Problem: 136
Official Difficulty: easy
Topic: Bit Manipulation, array
Link: https://leetcode.com/problems/single-number/description/
Completed On : November 10, 2023
My Understanding: Mostly Understand
Last Review: November 10, 2023
Days Since Review: 92

## Problem

---

Given a **non-empty** array of integers `nums`, every element appears *twice* except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.

## Aleksandr’s Solution

---

```java
public int singleNumber(int[] nums) {
        
        Arrays.sort(nums);
        for (int i = 1; i < nums.length - 1; i = i + 2){
            int prev = nums[i - 1];
            int cur = nums[i];         
            if (prev != cur){
                return prev;
            }
        }    
        
        return nums[nums.length - 1];
    }
```

## Tariq’s Solution

```python
class Solution(object):
    def singleNumber(self, nums):
        
        nums = sorted(nums)

        for i in range (1,len(nums),2):
            
            if nums[i] != nums [i-1] : 
                
                return nums [i-1] 
        
        return nums [-1]
```

## Optimal Solutions

---

```python
def singleNumber(self, nums: List[int]) -> int:
        
        a = 0
        for i in nums:
            a ^= i
            
        return a
```

## Notes

---

The optimal solution is using an XOR thingy , makes no sense rn but would be good to look into

## Related Videos

---

[https://www.youtube.com/watch?v=qMPX1AOa83k&pp=ygUWbmVldGNvZGUgc2luZ2xlIG51bWJlcg%3D%3D](https://www.youtube.com/watch?v=qMPX1AOa83k&pp=ygUWbmVldGNvZGUgc2luZ2xlIG51bWJlcg%3D%3D)