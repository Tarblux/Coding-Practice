# First Bad Version

Problem: 278
Official Difficulty: easy
Feels Like : medium
Topic: binary search
Link: https://leetcode.com/problems/first-bad-version/
Completed On : December 2, 2023
My Understanding: I Have No Idea
Last Review: December 2, 2023
Days Since Review: 70

## Problem

---

Suppose you have `n` versions `[1, 2, ..., n]` and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API `bool isBadVersion(version)` which returns whether `version` is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.

**Example 1:**

```python
Input: n = 5, bad = 4
Output: 4
Explanation:
call isBadVersion(3) -> false
call isBadVersion(5) -> true
call isBadVersion(4) -> true
Then 4 is the first bad version.
```

**Example 2:**

```python
Input: n = 1, bad = 1
Output: 1
```

**Constraints:**

- `1 <= bad <= n <= 231 - 1`

## My Solutions

---

Fully Dunce , this nuh make nuh sense so nuh too medz it 

```python
class Solution:
    def firstBadVersion(self, n: int) -> int:
        
        if n == 1: 
            
            return 1
        
        p1 = 0 
        p2 = 1
        p3 = 2
        p4 = 3 
        p5 = 4
        p6 = 5
        p7 = 6
        p8 = 7
        p9 = 8 
        p10 = 9
        
        tries = [1,2,3,4,5,6,7,8,9,10]
        
        step = 10 
        
        bad_vs = []
        
        for i in range (n//5) : 
            
            if isBadVersion(p1) or isBadVersion(p2) or isBadVersion(p3) or isBadVersion(p4) or isBadVersion(p5) :
            
                bad_vs = [p1,p2,p3,p4,p5]
            
                break
            
            else : 
                
                p1+= 5
                p2+= 5
                p3+= 5
                p4+= 5 
                p5+= 5
        
        for num in bad_vs : 
            
            if isBadVersion(num)  : 
                
                return num 
```

### Sanya

```python
# The isBadVersion API is already defined for you.
# def isBadVersion(version: int) -> bool:

class Solution:
    def firstBadVersion(self, n: int) -> int:
        
        def customFirstBadVersion(start, end) -> int:

            #middle element
            #cur = n // 2 + n % 2
            cur = start + (end - start) // 2

            if start >= end:
                return end
            
            elif isBadVersion(cur):
                return customFirstBadVersion(start, cur) 
            
            else:
                return customFirstBadVersion(cur + 1, end)    
        
        
        return customFirstBadVersion(1, n)
```

## Optimal Solutions

---

## Notes

---

 Need to have a solid Understanding of Binary Search 

## Related Videos

---

[https://www.youtube.com/watch?v=KiZwKNpayZw](https://www.youtube.com/watch?v=KiZwKNpayZw)