# Remove Duplicates From Sorted Array

Problem: 26
Official Difficulty: easy
Topic: array, two pointers
Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
Completed On : November 29, 2023
My Understanding: I Have No Idea
Last Review: November 29, 2023
Days Since Review: 73

## Problem

---

Given an integer array `nums` sorted in **non-decreasing order**, remove the duplicates **[in-place](https://en.wikipedia.org/wiki/In-place_algorithm)** such that each unique element appears only **once**. The **relative order** of the elements should be kept the **same**. Then return *the number of unique elements in* `nums`.

Consider the number of unique elements of `nums` to be `k`, to get accepted, you need to do the following things:

- Change the array `nums` such that the first `k` elements of `nums` contain the unique elements in the order they were present in `nums` initially. The remaining elements of `nums` are not important as well as the size of `nums`.
- Return `k`.

## My Solutions

---

```python
class Solution(object):
    def removeDuplicates(self, nums):
        
        
        if len(nums) == 0 :
            
            return 0 
        
        k = 1
        
        for i in range ( 1 , len (nums) ) :
            
            if nums[i] != nums[i-1] : 
                        
                nums[k] = nums[i]
                
                k += 1
        
        return k

```

```python

```

## Optimal Solution

---

The "Remove Duplicates from Sorted Array" problem can be efficiently solved using a two-pointer approach. The goal here is to modify the array in-place to remove the duplicates and return the new length of the array after duplicates are removed.

Since the array is already sorted, duplicates will be adjacent. We can use two pointers to solve this problem:

1. **Slow Pointer (`i`)**: This pointer moves only when a unique element is found.
2. **Fast Pointer (`j`)**: This pointer iterates through the array.

Here's the step-by-step approach:

1. If the array is empty or has only one element, its length is the answer.
2. Initialize two pointers, `i` and `j`, where `i` is 0 and `j` is 1.
3. Iterate over the array with `j`. For each iteration:
    - If `nums[i]` is not equal to `nums[j]`, it means we have found a new unique element.
    - Increment `i` and replace `nums[i]` with `nums[j]`. This step effectively shifts the unique elements to the start of the array.
4. Continue this process until `j` has traversed the whole array.
5. The length of the array without duplicates will be `i + 1` (as array indexing starts at 0).

Here's the implementation in Python:

```python
def removeDuplicates(nums):
    if len(nums) <= 1:
        return len(nums)

    i = 0
    for j in range(1, len(nums)):
        if nums[i] != nums[j]:
            i += 1
            nums[i] = nums[j]

    return i + 1

# Example usage
nums = [1, 1, 2]
print(removeDuplicates(nums))  # Output will be 2, and nums will be modified to [1, 2, ...]

```

In this code:

- The function `removeDuplicates` takes an array `nums` as input.
- If the length of `nums` is 0 or 1, we return the length directly.
- We initialize `i` at 0 and use a `for` loop to iterate with `j`.
- Inside the loop, if `nums[i]` and `nums[j]` are different, we increment `i` and copy `nums[j]` to `nums[i]`. This effectively moves all unique elements to the front of the array.
- After the loop completes, we return `i + 1` as the new length of the array.

This approach ensures that the space complexity is O(1) since no extra space is used, and the time complexity is O(n), where n is the number of elements in the array, as we traverse the list only once.

## Notes

---

Lorem Ipsum 

## Related Videos

---

[https://www.youtube.com/watch?v=DEJAZBq0FDA&t=21s](https://www.youtube.com/watch?v=DEJAZBq0FDA&t=21s)