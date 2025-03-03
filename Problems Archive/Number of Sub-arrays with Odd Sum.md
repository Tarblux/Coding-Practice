# Number of Sub-arrays with  Odd Sum

Problem: 1524
Official Difficulty: medium
Feels Like : medium
My Understanding: Needs Review
Topic: Math, array, dynamic programming, prefix sum
Link: https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/description/?envType=daily-question&envId=2025-02-25
Completed On : February 24, 2025
Last Review: February 24, 2025
Days Since Review: 6
Neetcode: No

## Problem

---

Given an array of integers `arr`, return *the number of subarrays with an **odd** sum*.

Since the answer can be very large, return it modulo `109 + 7`.

**Example 1:**

```
Input: arr = [1,3,5]
Output: 4
Explanation: All subarrays are [[1],[1,3],[1,3,5],[3],[3,5],[5]]
All sub-arrays sum are [1,4,9,3,8,5].
Odd sums are [1,9,3,5] so the answer is 4.

```

**Example 2:**

```
Input: arr = [2,4,6]
Output: 0
Explanation: All subarrays are [[2],[2,4],[2,4,6],[4],[4,6],[6]]
All sub-arrays sum are [2,6,12,4,10,6].
All sub-arrays have even sum and the answer is 0.

```

**Example 3:**

```
Input: arr = [1,2,3,4,5,6,7]
Output: 16

```

**Constraints:**

- `1 <= arr.length <= 105`
- `1 <= arr[i] <= 100`

## My Solutions

---

```python
class Solution:
    def numOfSubarrays(self, arr: List[int]) -> int:
        
        n = len(arr)
        prefix = [0] * (n+1)
        odd = 0
        even = 1
        total = 0

        for i in range(1,n+1):
            prefix[i] = prefix[i-1] + arr[i-1]

        print(prefix)

        for i in range(1,n+1):

            if prefix[i] % 2 == 0:
                total += odd
                even += 1
            else :
                total += even
                odd += 1

        return total % (10**9 + 7)

        
```

```python

```

## Optimal Solutions

---

## Notes

---

 

## Related Videos

---

[https://www.notion.so](https://www.notion.so)