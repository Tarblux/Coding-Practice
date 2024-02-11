# Remove Element

Problem: 27
Official Difficulty: easy
Feels Like : easy
Topic: array, two pointers
Link: https://leetcode.com/problems/remove-element/
Completed On : December 18, 2023
My Understanding: Mostly Understand
Last Review: December 18, 2023
Days Since Review: 54

## Problem

---

Given an integer array `nums` and an integer `val`, remove all occurrences of `val` in `nums` **[in-place](https://en.wikipedia.org/wiki/In-place_algorithm)**. The order of the elements may be changed. Then return *the number of elements in* `nums` *which are not equal to* `val`.

Consider the number of elements in `nums` which are not equal to `val` be `k`, to get accepted, you need to do the following things:

- Change the array `nums` such that the first `k` elements of `nums` contain the elements which are not equal to `val`. The remaining elements of `nums` are not important as well as the size of `nums`.
- Return `k`.

**Custom Judge:**

The judge will test your solution with the following code:

```
int[] nums = [...]; // Input array
int val = ...; // Value to remove
int[] expectedNums = [...]; // The expected answer with correct length.
                            // It is sorted with no values equaling val.

int k = removeElement(nums, val); // Calls your implementation

assert k == expectedNums.length;
sort(nums, 0, k); // Sort the first k elements of nums
for (int i = 0; i < actualLength; i++) {
    assert nums[i] == expectedNums[i];
}
```

If all assertions pass, then your solution will be **accepted**.

**Example 1:**

```
Input: nums = [3,2,2,3], val = 3
Output: 2, nums = [2,2,_,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 2.
It does not matter what you leave beyond the returned k (hence they are underscores).
```

**Example 2:**

```
Input: nums = [0,1,2,2,3,0,4,2], val = 2
Output: 5, nums = [0,1,4,0,3,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums containing 0, 0, 1, 3, and 4.
Note that the five elements can be returned in any order.
It does not matter what you leave beyond the returned k (hence they are underscores).
```

**Constraints:**

- `0 <= nums.length <= 100`
- `0 <= nums[i] <= 50`
- `0 <= val <= 100`

## My Solutions

---

```python
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        next_pos = 0  # Pointer for the next position to place non-val element

        for i in range(len(nums)):
            if nums[i] != val:
                nums[next_pos] = nums[i]
                next_pos += 1

        return next_pos
```

```python

```

## Optimal Solutions

---

The most optimal solution for the "Remove Element" problem on LeetCode involves using a two-pointer technique. This approach is both efficient in terms of time complexity (O(n)) and space complexity (O(1)), as it performs the removal in-place without using any extra space.

### Solution Approach - Two-Pointer Technique

1. **Pointer for Replacement Position**: Initialize a pointer (say `next_pos`) to track the position where the next non-target element (element not equal to `val`) should be placed.
2. **Iterate Over the Array**: Iterate through the array using another pointer (say `i`). Check each element.
3. **Copy Non-Target Elements**: If the current element `nums[i]` is not equal to `val`, copy it to `nums[next_pos]`, and then increment `next_pos`.
4. **Skip Target Elements**: If `nums[i]` is equal to `val`, do nothing and move on to the next element.
5. **Return New Length**: After the loop, `next_pos` will be at the position where the next non-target element would have been placed, which is also the new length of the array after removals.

### Python Implementation

```python
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        next_pos = 0  # Pointer for the next position to place non-val element

        for i in range(len(nums)):
            if nums[i] != val:
                nums[next_pos] = nums[i]
                next_pos += 1

        return next_pos

```

### Explanation

- The `next_pos` pointer is used to keep track of where the next element that is not equal to `val` should be placed.
- We iterate over `nums` with `i`. If `nums[i]` is not equal to `val`, it's copied to `nums[next_pos]`, and `next_pos` is incremented.
- The final value of `next_pos` is the new length of the array, as all instances of `val` have been removed or overwritten.

### Complexity Analysis

- **Time Complexity**: O(n), where `n` is the number of elements in the array. The algorithm iterates through the array once.
- **Space Complexity**: O(1), as it modifies the array in place without using any extra space.

This approach is optimal as it minimizes the number of operations and works efficiently with the array in-place.

## Notes

---

 

## Related Videos

---

[https://www.notion.so](https://www.notion.so)