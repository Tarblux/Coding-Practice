# Merge Sorted Array

Problem: 88
Official Difficulty: easy
Feels Like : medium
Topic: array, two pointers
Link: https://leetcode.com/problems/merge-sorted-array/
Completed On : December 1, 2023
My Understanding: Mostly Understand
Last Review: December 1, 2023
Days Since Review: 71

## Problem

---

You are given two integer arrays `nums1` and `nums2`, sorted in non-decreasing order, and two integers `m` and `n`, representing the number of elements in `nums1` and `nums2` respectively.

Merge `nums1` and `nums2` into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function but instead be stored inside the array `nums1`. To accommodate this, `nums1` has a length of `m + n`, where the first `m` elements denote the elements that should be merged and the rest should be set to 0.

You may assume that `nums1` has a size equal to `m + n`, and `nums1` and `nums2` are sorted in non-decreasing order.

Example 1:

```python
Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
```

Example 2:

```python
Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
```

Constraints:

- `nums1.length == m + n`
- `nums2.length == n`
- `0 <= m, n <= 200`
- `1 <= m + n <= 200`
- `10^9 <= nums1[i], nums2[i] <= 10^9`

**Follow-up:**
You must do it in place and with O(1) extra memory.

## My Solutions

---

```python
class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """

        if not nums1 :
        
            nums1 = nums2
            
            return
            
        if not nums2: 
            
            return
          
        j = 0
        
        nums2_index = (m + n) - n 
        
        for i in range ((m + n) - n , len(nums1)) : 
            
            nums1[i] =  nums2[j]
            
            j += 1 
            
        # This is an easy way to just sort but it would be poor form in an interview 
        
        nums1.sort()
        
        # This is the medium difficulty way to sort it using a bubble sort 

            
#         for i in range(m + n - 1):
            
#             for j in range(0, m + n - i - 1):
                
#                 if nums1[j] > nums1[j + 1]:
                    
#                     nums1[j], nums1[j + 1] = nums1[j + 1], nums1[j]
```

```python

```

## Optimal Solutions

---

```python
class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        
        # Set p1 and p2 to point to the end of their respective arrays.
        p1 = m - 1
        p2 = n - 1
    
        # And move p backward through the array, each time writing
        # the smallest value pointed at by p1 or p2.
        for p in range(n + m - 1, -1, -1):
            if p2 < 0:
                break
            if p1 >= 0 and nums1[p1] > nums2[p2]:
                nums1[p] = nums1[p1]
                p1 -= 1
            else:
                nums1[p] = nums2[p2]
                p2 -= 1
```

![Untitled](Merge%20Sorted%20Array%20bfb95f823b654b29883000f4b2dad062/Untitled.png)

## Notes

---

 Important intuition is to start from the largest in the list because otherwise you a play di fyah cuz you go affi take extra cases into consideration if yuh start a front 

## Related Videos

---

[https://www.youtube.com/watch?v=P1Ic85RarKY](https://www.youtube.com/watch?v=P1Ic85RarKY)