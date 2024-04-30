# Sort Colors

Problem: 75
Official Difficulty: medium
Feels Like : easy
My Understanding: Fully Understand
Topic: array, sorting, two pointers
Link: https://leetcode.com/problems/sort-colors/description/
Completed On : March 27, 2024
Last Review: March 27, 2024
Days Since Review: 34

## Problem

---

Given an array `nums` with `n` objects colored red, white, or blue, sort them **[in-place](https://en.wikipedia.org/wiki/In-place_algorithm)** so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers `0`, `1`, and `2` to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

**Example 1:**

```
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
```

**Example 2:**

```
Input: nums = [2,0,1]
Output: [0,1,2]
```

**Constraints:**

- `n == nums.length`
- `1 <= n <= 300`
- `nums[i]` is either `0`, `1`, or `2`.

**Follow up:** Could you come up with a one-pass algorithm using only constant extra space?

## My Solutions

---

```python
class Solution:
    def sortColors(self, nums: List[int]) -> None:

        counts = Counter(nums)

        for i in range(counts[0]):
            nums[i] = 0
            
        for i in range(counts[0],counts[1]+counts[0]):
            nums[i] = 1

        for i in range(counts[1]+counts[0],len(nums)):
            nums[i] = 2

```

```python

```

## Optimal Solutions

---

The "Sort Colors" problem, also known as the Dutch National Flag problem, asks you to sort an array containing only 0s, 1s, and 2s in-place, with the constraint of doing it in a single pass and without using the library's sort function. The goal is to arrange the colors represented by these numbers in the order of 0s first, then 1s, and finally 2s.

A common and efficient way to solve this problem is to use three pointers to partition the array into three sections: one for each color. The three pointers can be thought of as follows:

- `left` for the next position to place a 0 (starts at the beginning of the array),
- `right` for the next position to place a 2 (starts at the end of the array),
- `current` to scan through the array.

### Python Solution:

```python
def sortColors(nums):
    left, current = 0, 0
    right = len(nums) - 1

    while current <= right:
        if nums[current] == 0:
            nums[left], nums[current] = nums[current], nums[left]
            left += 1
            current += 1
        elif nums[current] == 2:
            nums[right], nums[current] = nums[current], nums[right]
            right -= 1
        else:  # nums[current] == 1
            current += 1

# Example
nums = [2, 0, 2, 1, 1, 0]
sortColors(nums)
print(nums)

```

### How It Works:

- Initialize three pointers: `left` at 0, `current` at 0, and `right` at the end of the array.
- While `current` is not beyond `right`:
    - If `nums[current] == 0`, swap `nums[current]` with `nums[left]` and move both `left` and `current` one step forward. This ensures that all 0s are at the beginning.
    - If `nums[current] == 2`, swap `nums[current]` with `nums[right]` and move `right` one step backward. Note that we don't move `current` in this case because the swapped element from `right` has not been examined yet.
    - If `nums[current] == 1`, just move `current` one step forward because 1s are correctly placed in the middle.

### Complexity Analysis:

- **Time Complexity:** O(n), where n is the number of elements in the array. The algorithm makes a single pass through the array.
- **Space Complexity:** O(1), as it sorts the array in place and does not use any additional storage proportional to the input size.

## Notes

---

 

[Sort an array of 0s, 1s and 2s | Dutch National Flag problem - GeeksforGeeks](https://www.geeksforgeeks.org/sort-an-array-of-0s-1s-and-2s/)

## Related Videos

---

[https://www.youtube.com/watch?v=4xbWSRZHqac](https://www.youtube.com/watch?v=4xbWSRZHqac)