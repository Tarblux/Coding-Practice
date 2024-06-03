# Special Array With X Elements greater than or equal X

Problem: 1608
Official Difficulty: easy
Feels Like : medium
My Understanding: Mostly Understand
Topic: array, binary search, sorting
Link: https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/description/?envType=daily-question&envId=2024-05-27
Completed On : May 27, 2024
Last Review: May 27, 2024
Days Since Review: 7

## Problem

---

You are given an array `nums` of non-negative integers. `nums` is considered **special** if there exists a number `x` such that there are **exactly** `x` numbers in `nums` that are **greater than or equal to** `x`.

Notice that `x` **does not** have to be an element in `nums`.

Return `x` *if the array is **special**, otherwise, return* `-1`. It can be proven that if `nums` is special, the value for `x` is **unique**.

**Example 1:**

```
Input: nums = [3,5]
Output: 2
Explanation: There are 2 values (3 and 5) that are greater than or equal to 2.

```

**Example 2:**

```
Input: nums = [0,0]
Output: -1
Explanation: No numbers fit the criteria for x.
If x = 0, there should be 0 numbers >= x, but there are 2.
If x = 1, there should be 1 number >= x, but there are 0.
If x = 2, there should be 2 numbers >= x, but there are 0.
x cannot be greater since there are only 2 numbers in nums.

```

**Example 3:**

```
Input: nums = [0,4,3,0,4]
Output: 3
Explanation: There are 3 values that are greater than or equal to 3.

```

**Constraints:**

- `1 <= nums.length <= 100`
- `0 <= nums[i] <= 1000`

## My Solutions

---

```python
class Solution:
    def specialArray(self, nums: List[int]) -> int:

        broom = [[num,0] for num in range(len(nums)+1)]

        for num in nums:

            for i in range(len(broom)):

                if broom[i][0] <= num:

                    broom[i][1] += 1

        for pair in broom:

            if pair[0] == pair[1]:
                return pair[0]

        return -1
```

Chau

```python
def specialArray(self, nums: List[int]) -> int:
        nums.sort()
        nums = [0] + nums

        for i in range(1, len(nums)):
            x = len(nums) - i
            if nums[i-1] < x <= nums[i]:
                return x

        return -1
```

### Thorough Explanation of the Approach

The given function `specialArray` checks if an array `nums` is a special array. The approach leverages sorting and careful index manipulation to efficiently find the special value `x`.

### Steps and Detailed Explanation

1. **Sort the Array**:
    
    ```python
    nums.sort()
    ```
    
    - Sorting the array simplifies the process of counting elements that are greater than or equal to any given value `x`. After sorting, elements are in ascending order.
2. **Adjust Array to Include Zero**:
    
    ```python
    nums = [0] + nums
    ```
    
    - Prepend a zero to the sorted array. This step helps to handle edge cases smoothly where `x` can be 1, 2, ..., up to the length of the original array. By adding a zero at the beginning, we ensure that indices and lengths align correctly during the iteration.
3. **Iterate Through the Array**:
    
    ```python
    for i in range(1, len(nums)):
        x = len(nums) - i
        if nums[i-1] < x <= nums[i]:
            return x
    
    ```
    
    - Start iterating from index 1 to the end of the adjusted array.
    - For each index `i`, calculate `x` as `len(nums) - i`.
        - `x` represents the number of elements that should be greater than or equal to `x` to satisfy the special array condition.
    - Check the condition `nums[i-1] < x <= nums[i]`:
        - `nums[i-1] < x`: Ensures that `x` is greater than the number just before the current position. This checks if `x` is a valid candidate to count the numbers in the array.
        - `x <= nums[i]`: Ensures that `x` is less than or equal to the current number, meaning there are at least `x` elements greater than or equal to `x`.
    - If the condition is met, return `x`.
4. **Return -1 if No Special Value Found**:
    
    ```python
    return -1
    ```
    
    - If no valid `x` is found during the iteration, return `1` indicating that the array is not special.

### Why This Approach Works

1. **Sorted Array**:
    - Sorting helps us leverage the order of elements to count how many elements are greater than or equal to any potential `x`.
2. **Iterating with Adjusted Index**:
    - By prepending a zero, we ensure that all possible values of `x` from 1 up to the length of the original array are considered.
3. **Condition Check**:
    - The condition `nums[i-1] < x <= nums[i]` is crucial:
        - `nums[i-1] < x`: This ensures that `x` can be a valid count of numbers greater than or equal to it, without overcounting.
        - `x <= nums[i]`: This ensures that there are at least `x` elements greater than or equal to `x`.

### Example Walkthrough

Let's consider the example `nums = [3, 5]`.

1. **Sorting**:
    - Sorted array: `[3, 5]`
    - Adjusted array: `[0, 3, 5]`
2. **Iteration**:
    - For `i = 1`:
        - `x = 2` (since `len(nums) - i = 3 - 1 = 2`)
        - Check if `nums[i-1] < x <= nums[i]`: `0 < 2 <= 3`
        - Condition is true, so return `x = 2`.
3. **Output**:
    - The function returns `2`, which is the special value for the array `[3, 5]`.

### Complexity Analysis

- **Time Complexity**: `O(n log n)` due to the sorting step, where `n` is the length of the array.
- **Space Complexity**: `O(1)` additional space (ignoring the space required for sorting), as we only use a few extra variables.

### Summary

This approach efficiently finds the special value `x` by:

- Sorting the array.
- Using a systematic iteration to check for the condition.
- Leveraging the properties of sorted arrays to count elements greater than or equal to `x`.
- Returning `x` if the condition is met, otherwise `1`.

## Optimal Solutions

---

### Problem Description

You are given an array `nums` of non-negative integers. `nums` is considered a special array if there exists a number `x` such that there are exactly `x` numbers in `nums` that are greater than or equal to `x`.

Return `x` if the array is special, otherwise return `-1`. It is guaranteed that `x` is a non-negative integer.

### Example

```python
Input: nums = [3,5]
Output: 2

Input: nums = [0,0]
Output: -1

Input: nums = [0,4,3,0,4]
Output: 3
```

### Optimal Solution and Explanation

To determine if an array is special, we need to find an integer `x` such that exactly `x` elements in the array are greater than or equal to `x`.

### Steps:

1. **Sort the Array**: Sorting the array simplifies the problem by allowing us to efficiently count the number of elements greater than or equal to any given `x`.
2. **Iterate through Possible Values of `x`**: After sorting, iterate through possible values of `x` from 0 to the length of the array.
3. **Count Elements**: For each possible `x`, count how many elements in the array are greater than or equal to `x`. If this count equals `x`, we have found our special value.
4. **Return the Result**: If no such `x` is found, return `1`.

### Python Code

Here’s the Python code to achieve this:

```python
def specialArray(nums):
    nums.sort()
    n = len(nums)

    for x in range(n + 1):
        count = sum(1 for num in nums if num >= x)
        if count == x:
            return x

    return -1

# Example usage
print(specialArray([3, 5]))           # Output: 2
print(specialArray([0, 0]))           # Output: -1
print(specialArray([0, 4, 3, 0, 4]))  # Output: 3

```

### Explanation

1. **Sort the Array**: Sorting helps in easily counting the number of elements greater than or equal to any given `x`.
2. **Iterate through `x`**: Loop through all possible values of `x` from 0 to `n` (inclusive), where `n` is the length of the array.
3. **Count Elements**: Use a generator expression to count how many elements in the array are greater than or equal to `x`.
4. **Check Condition**: If the count equals `x`, return `x`. If no such `x` is found, return `1`.

### Explain Like I'm Five (ELI5)

Imagine you have a list of toys, and you want to find a number `x` such that exactly `x` toys are either as big as `x` or bigger.

1. **Sort the Toys**: First, arrange your toys in order from smallest to largest.
2. **Count the Big Toys**: For each possible number `x`, count how many toys are at least as big as `x`.
3. **Check the Count**: If the count of big toys matches `x`, you’ve found your special number.
4. **Result**: If you find such a number, that's your answer. If not, then there is no special number.

By sorting the toys and counting for each possible `x`, you can find out if there is a special number that fits the condition.

## Notes

---

 

## Related Videos

---

[https://www.notion.so](https://www.notion.so)