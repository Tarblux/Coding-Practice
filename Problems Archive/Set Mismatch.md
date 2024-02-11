# Set Mismatch

Problem: 645
Official Difficulty: easy
Feels Like : medium
Topic: Bit Manipulation, array, hash table, sorting
Link: https://leetcode.com/problems/set-mismatch/description/
Completed On : January 22, 2024
My Understanding: Mostly Understand
Last Review: January 22, 2024
Days Since Review: 19

## Problem

---

You have a set of integers `s`, which originally contains all the numbers from `1` to `n`. Unfortunately, due to some error, one of the numbers in `s` got duplicated to another number in the set, which results in **repetition of one** number and **loss of another** number.

You are given an integer array `nums` representing the data status of this set after the error.

Find the number that occurs twice and the number that is missing and return *them in the form of an array*.

**Example 1:**

```
Input: nums = [1,2,2,4]
Output: [2,3]
```

**Example 2:**

```
Input: nums = [1,1]
Output: [1,2]
```

**Constraints:**

- `2 <= nums.length <= 104`
- `1 <= nums[i] <= 104`

## My Solutions

---

```python
class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:

        nums.sort()

        actual_sum = 0

        extra_num = 0

        n = len(nums)

        Xsum = int(n * ((n+1) / 2))

        for i in range (0,len(nums)-1):

            actual_sum += nums[i] 

            if nums[i] == nums[i+1] : 

                extra_num = nums[i]

        actual_sum += nums[-1]

        missing_num = Xsum - (actual_sum - extra_num )
                

        return [extra_num , missing_num ]
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