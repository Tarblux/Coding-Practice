# Longest Consecutive Sequence

Problem: 128
Official Difficulty: medium
Feels Like : medium
Topic: array, hash table, union find
Link: https://leetcode.com/problems/longest-consecutive-sequence/description/
Completed On : January 2, 2024
My Understanding: Mostly Understand
Last Review: January 2, 2024
Days Since Review: 39

## Problem

---

Given an unsorted array of integers `nums`, return *the length of the longest consecutive elements sequence.*

You must write an algorithm that runs in `O(n)` time.

**Example 1:**

```
Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is[1, 2, 3, 4]. Therefore its length is 4.

```

**Example 2:**

```
Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9

```

**Constraints:**

- `0 <= nums.length <= 105`
- `109 <= nums[i] <= 109`

## My Solutions

---

This works but because of the while loop it ends up being O(n^2) in the worst case because of the while loop

```python
class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:

        if not nums : 

            return 0

        dict = {}

        for i in range(0,len(nums)) : 

            if nums[i] not in dict :

                dict[nums[i]] = ''

        count = 0

        output = 0

        for key in dict : 

            cur_key = key - 1
            count = 0

            while cur_key in dict :

                cur_key -= 1
                count += 1

            output = max(count,output)

        return output + 1
```

```python
class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        
        if not nums:
            return 0

        num_set = set(nums)
        longest_streak = 0

        for num in num_set:
            
            if num - 1 not in num_set:
                current_num = num
                current_streak = 1

                
                while current_num + 1 in num_set:
                    current_num += 1
                    current_streak += 1

                longest_streak = max(longest_streak, current_streak)

        return longest_streak
```

## Optimal Solutions

---

The optimal solution for finding the longest consecutive sequence in an array is to use a set for fast lookups, ensuring the time complexity remains O(n). The key idea is to use the set to efficiently check the existence of consecutive numbers for each unique number in the array.

### Solution Approach

1. **Store Elements in a Set**: First, add all elements of the array to a set. This allows for O(1) lookup time to check if an element exists in the array.
2. **Iterate and Find Sequences**: Iterate through each element in the array. For each element, check if it is the start of a consecutive sequence. An element `num` is the start of a sequence if `(num - 1)` is not in the set.
3. **Count Consecutive Elements**: If the current element is the start of a sequence, iterate to find the length of this sequence by continuously checking if `(num + 1)`, `(num + 2)`, etc., are in the set.
4. **Track the Longest Sequence**: Keep track of the length of the longest sequence found during this process.

### Python Implementation

```python
class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if not nums:
            return 0

        num_set = set(nums)
        longest_streak = 0

        for num in num_set:
            if num - 1 not in num_set:  # Check if it's the start of a sequence
                current_streak = 1
                current_num = num

                while current_num + 1 in num_set:
                    current_num += 1
                    current_streak += 1

                longest_streak = max(longest_streak, current_streak)

        return longest_streak

```

### Explanation

- We use a set to achieve constant-time lookup.
- By ensuring we only start counting when we find the beginning of a sequence, we avoid redundant checks and repeated counting of the same sequence.
- This approach guarantees that each number in the set is part of a sequence that is counted only once, ensuring the time complexity stays linear.

### Complexity Analysis

- **Time Complexity**: O(n). Each element in the array is processed once. While there are nested loops, they collectively process each consecutive sequence only once.
- **Space Complexity**: O(n) for storing the elements in the set.

This approach is efficient and works well even with large datasets, as it maintains linear time complexity while effectively identifying and counting consecutive sequences.

## Notes

---

 Efficiency is the name of the game with this one 

## Related Videos

---

[https://youtu.be/P6RZZMu_maU](https://youtu.be/P6RZZMu_maU)