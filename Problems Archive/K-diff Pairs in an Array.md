# K-diff Pairs in an Array

Problem: 532
Official Difficulty: medium
Feels Like : medium
My Understanding: Mostly Understand
Topic: array, binary search, hash table, sorting, two pointers
Link: https://leetcode.com/problems/k-diff-pairs-in-an-array/description/
Completed On : June 1, 2024
Last Review: June 1, 2024
Days Since Review: 2

## Problem

---

Given an array of integers `nums` and an integer `k`, return *the number of **unique** k-diff pairs in the array*.

A **k-diff** pair is an integer pair `(nums[i], nums[j])`, where the following are true:

- `0 <= i, j < nums.length`
- `i != j`
- `|nums[i] - nums[j]| == k`

**Notice** that `|val|` denotes the absolute value of `val`.

**Example 1:**

```
Input: nums = [3,1,4,1,5], k = 2
Output: 2
Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
Although we have two 1s in the input, we should only return the number ofunique pairs.

```

**Example 2:**

```
Input: nums = [1,2,3,4,5], k = 1
Output: 4
Explanation: There are four 1-diff pairs in the array, (1, 2), (2, 3), (3, 4) and (4, 5).

```

**Example 3:**

```
Input: nums = [1,3,1,5,4], k = 0
Output: 1
Explanation: There is one 0-diff pair in the array, (1, 1).

```

**Constraints:**

- `1 <= nums.length <= 104`
- `107 <= nums[i] <= 107`
- `0 <= k <= 107`

## My Solutions

---

```python
class Solution:
    def findPairs(self, nums: List[int], k: int) -> int:
        if k < 0:
            return 0
  
        seen = set()
        output = set()

        for num in nums:
            if num + k in seen:
                output.add((num, num + k))
            if num - k in seen:
                output.add((num - k, num))
            seen.add(num)
            
        return len(output)
```

```python

```

## Optimal Solutions

---

### Problem Description

Given an array of integers `nums` and an integer `k`, return the number of unique k-diff pairs in the array. A k-diff pair is an integer pair `(nums[i], nums[j])`, where:

- `0 <= i < j < nums.length`
- `|nums[i] - nums[j]| == k`

### Example

```python
Input: nums = [3, 1, 4, 1, 5], k = 2
Output: 2
Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).

Input: nums = [1, 2, 3, 4, 5], k = 1
Output: 4
Explanation: There are four 1-diff pairs in the array, (1, 2), (2, 3), (3, 4), and (4, 5).

Input: nums = [1, 3, 1, 5, 4], k = 0
Output: 1
Explanation: There is one 0-diff pair in the array, (1, 1).
```

### Optimal Solution and Explanation

To solve this problem efficiently, we can use a hash map to keep track of the frequency of each number in the array. This allows us to find pairs with the desired difference in linear time.

### Steps:

1. **Count Frequencies**: Use a hash map to count the frequency of each number in the array.
2. **Find k-diff Pairs**:
    - For `k > 0`: For each unique number in the array, check if the number plus `k` exists in the hash map.
    - For `k == 0`: Find all numbers with a frequency greater than 1, as they form pairs with themselves.

### Python Code

Here's the Python code to achieve this:

```python
def findPairs(nums, k):
    if k < 0:
        return 0

    count = 0
    num_map = {}

    # Count the frequency of each number
    for num in nums:
        num_map[num] = num_map.get(num, 0) + 1

    # Find k-diff pairs
    if k > 0:
        for num in num_map:
            if num + k in num_map:
                count += 1
    elif k == 0:
        for num in num_map:
            if num_map[num] > 1:
                count += 1

    return count

# Example usage
print(findPairs([3, 1, 4, 1, 5], 2))  # Output: 2
print(findPairs([1, 2, 3, 4, 5], 1))  # Output: 4
print(findPairs([1, 3, 1, 5, 4], 0))  # Output: 1

```

### Explanation

1. **Count Frequencies**:
    - Iterate through the array and use a hash map to count the occurrences of each number.
    - This takes `O(n)` time, where `n` is the length of the array.
2. **Find k-diff Pairs**:
    - If `k > 0`: For each number in the hash map, check if the number plus `k` exists in the hash map. Each valid pair is counted once.
    - If `k == 0`: Count how many numbers have a frequency greater than 1, as these can form pairs with themselves.
3. **Return the Count**:
    - The total count of valid pairs is returned.

### Time Complexity Analysis

- **Counting Frequencies**: `O(n)` time for creating the frequency map.
- **Finding k-diff Pairs**: `O(n)` time for iterating through the hash map and checking conditions.
- **Overall Time Complexity**: `O(n)`

### Space Complexity Analysis

- **Space Complexity**: `O(n)` for storing the frequency map.

### Explain Like I'm Five (ELI5)

Imagine you have a box of toy cars, each with a number on it. You want to find pairs of cars where the difference in their numbers is exactly `k`:

1. **Count Cars**: First, count how many cars you have for each number.
2. **Find Pairs**: Look at each number and check if you have another car with a number that's exactly `k` more or less.
    - If `k` is zero, just check if you have more than one car with the same number.

By counting and then checking, you can quickly find all the pairs of cars with the desired difference!

## Notes

---

 

## Related Videos

---

[https://www.youtube.com/watch?v=VTPasSPZVCY](https://www.youtube.com/watch?v=VTPasSPZVCY)