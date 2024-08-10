# Minimum Increment to Make Array Unique

Problem: 945
Official Difficulty: medium
Feels Like : medium
My Understanding: Mostly Understand
Topic: Counting, array, greedy, sorting
Link: https://leetcode.com/problems/minimum-increment-to-make-array-unique/description/
Completed On : June 14, 2024
Last Review: June 14, 2024
Days Since Review: 56

## Problem

---

You are given an integer array `nums`. In one move, you can pick an index `i` where `0 <= i < nums.length` and increment `nums[i]` by `1`.

Return *the minimum number of moves to make every value in* `nums` ***unique***.

The test cases are generated so that the answer fits in a 32-bit integer.

**Example 1:**

```
Input: nums = [1,2,2]
Output: 1
Explanation: After 1 move, the array could be [1, 2, 3].
```

**Example 2:**

```
Input: nums = [3,2,1,2,1,7]
Output: 6
Explanation: After 6 moves, the array could be [3, 4, 1, 2, 5, 7].
It can be shown with 5 or less moves that it is impossible for the array to have all unique values.
```

**Constraints:**

- `1 <= nums.length <= 105`
- `0 <= nums[i] <= 105`

## My Solutions

---

```python
class Solution:
    def minIncrementForUnique(self, nums: List[int]) -> int:

        """
        - Sort input array
        - Iterate from index 1 and find difference in adjacent numbers  
        - add difference plus one to moves 
        """ 

        if len(nums) < 2:
            return 0

        nums.sort()
        moves = 0

        for i in range(1,len(nums)):
            
            if nums[i] <= nums[i-1]:

                cur_moves = nums[i-1] - nums[i] + 1

                nums[i] += cur_moves
                moves += cur_moves
                
                

        return moves
```

```python

```

## Optimal Solutions

---

### Problem Description

Given an array of integers `arr`, return the minimum number of increments required to make all the elements of the array unique. An increment operation involves increasing any element of the array by 1.

### Example

```python
Input: arr = [1,2,2]
Output: 1
Explanation: After 1 increment, the array could be [1, 2, 3].

Input: arr = [3,2,1,2,1,7]
Output: 6
Explanation: After 6 increments, the array could be [3, 4, 1, 2, 5, 7] or any other unique combination.

```

### Optimal Solution and Explanation

To solve this problem efficiently, we can use the following approach:

1. **Sort the Array**: Sorting the array helps us easily identify duplicates and manage increments.
2. **Increment Duplicates**: Traverse the sorted array and for each duplicate element, increment it to ensure it becomes unique. Track the number of increments required.

### Steps:

1. **Sort the Array**: Sort the input array to bring duplicates next to each other.
2. **Traverse and Increment**: Traverse the sorted array and increment duplicates as needed to make all elements unique, while counting the total number of increments.

### Python Code

Here's the Python code to achieve this:

```python
def minIncrementForUnique(arr):
    arr.sort()
    moves = 0
    for i in range(1, len(arr)):
        if arr[i] <= arr[i - 1]:
            increment = arr[i - 1] - arr[i] + 1
            arr[i] += increment
            moves += increment
    return moves

# Example usage
print(minIncrementForUnique([1, 2, 2]))  # Output: 1
print(minIncrementForUnique([3, 2, 1, 2, 1, 7]))  # Output: 6

```

### Explanation

1. **Sorting**:
    - Sort the array to group duplicates together.
    - For example, `arr = [3, 2, 1, 2, 1, 7]` becomes `[1, 1, 2, 2, 3, 7]`.
2. **Increment Duplicates**:
    - Traverse the sorted array starting from the second element.
    - If the current element `arr[i]` is less than or equal to the previous element `arr[i-1]`, increment `arr[i]` to `arr[i-1] + 1` and add the difference to the moves counter.
    - For example, with `[1, 1, 2, 2, 3, 7]`:
        - First duplicate `1` becomes `2` with 1 increment (`[1, 2, 2, 2, 3, 7]`).
        - First duplicate `2` becomes `3` with 1 increment (`[1, 2, 3, 2, 3, 7]`).
        - Second duplicate `2` becomes `4` with 2 increments (`[1, 2, 3, 4, 3, 7]`).
        - First duplicate `3` becomes `5` with 2 increments (`[1, 2, 3, 4, 5, 7]`).
        - Total moves = 1 + 1 + 2 + 2 = 6.

### Time Complexity Analysis

- **Time Complexity**: `O(n log n)`
    - Sorting the array takes `O(n log n)`.
    - Traversing the array to count the increments takes `O(n)`.
- **Overall Time Complexity**: `O(n log n)`

### Space Complexity Analysis

- **Space Complexity**: `O(1)`
    - The algorithm uses a constant amount of extra space, excluding the input and output.

This approach ensures that all elements in the array become unique with the minimum number of increments.

## Notes

---

 

## Related Videos

---

[https://www.youtube.com/watch?v=XPPs2Wj2YSk](https://www.youtube.com/watch?v=XPPs2Wj2YSk)