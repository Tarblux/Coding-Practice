# Two Sum II Input Array Is Sorted

Problem: 167
Official Difficulty: medium
Feels Like : medium
Topic: array, binary search, two pointers
Link: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
Completed On : December 19, 2023
My Understanding: Fully Understand
Last Review: December 19, 2023
Days Since Review: 53

## Problem

---

Given a **1-indexed** array of integers `numbers` that is already ***sorted in non-decreasing order***, find two numbers such that they add up to a specific `target` number. Let these two numbers be `numbers[index1]` and `numbers[index2]` where `1 <= index1 < index2 <= numbers.length`.

Return *the indices of the two numbers,* `index1` *and* `index2`*, **added by one** as an integer array* `[index1, index2]` *of length 2.*

The tests are generated such that there is **exactly one solution**. You **may not** use the same element twice.

Your solution must use only constant extra space.

**Example 1:**

```
Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].

```

**Example 2:**

```
Input: numbers = [2,3,4], target = 6
Output: [1,3]
Explanation: The sum of 2 and 4 is 6. Therefore index1 = 1, index2 = 3. We return [1, 3].

```

**Example 3:**

```
Input: numbers = [-1,0], target = -1
Output: [1,2]
Explanation: The sum of -1 and 0 is -1. Therefore index1 = 1, index2 = 2. We return [1, 2].

```

**Constraints:**

- `2 <= numbers.length <= 3 * 104`
- `1000 <= numbers[i] <= 1000`
- `numbers` is sorted in **non-decreasing order**.
- `1000 <= target <= 1000`
- The tests are generated such that there is **exactly one solution**.

## My Solutions

---

```python
class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:

        
        left  = 0 
        right = -1

        while left != right : 

            if numbers[left] + numbers[right] == target : 
                
                return [left + 1 , (right + 1 ) + len(numbers)]

            elif numbers[left] + numbers[right] > target : 

                right -= 1
            
            else : 

                left += 1
```

```python

```

## Optimal Solutions

---

The "Two Sum II - Input Array Is Sorted" problem requires finding two numbers such that they add up to a specific target number. The input array is sorted in ascending order, and the solution must return indices of the two numbers, where they are 1-indexed (not zero-indexed). A key point is that each input would have exactly one solution, and you should not use the same element twice.

### Solution Approach: Two Pointers

Since the array is sorted, a two-pointer approach is a very efficient solution. Here's how it works:

1. **Initialize Two Pointers**: Place one pointer at the beginning of the array (`left`) and the other at the end (`right`).
2. **Iterate Until Solution is Found**:
    - Calculate the sum of the elements at the `left` and `right` pointers.
    - If the sum is equal to the target, return the indices.
    - If the sum is less than the target, move the `left` pointer to the right (to increase the sum).
    - If the sum is greater than the target, move the `right` pointer to the left (to decrease the sum).
3. **Return Indices**: Once the two numbers that add up to the target are found, return their indices.

### Python Implementation

```python
class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        left, right = 0, len(numbers) - 1

        while left < right:
            current_sum = numbers[left] + numbers[right]
            if current_sum == target:
                return [left + 1, right + 1]  # Convert to 1-indexed
            elif current_sum < target:
                left += 1
            else:
                right -= 1

        return []  # This line is never reached if input is guaranteed to have a solution

```

### Explanation

- The two pointers `left` and `right` start at the beginning and end of the array, respectively.
- In each iteration, you calculate the sum of the elements at these two pointers.
- If the sum matches the target, you've found your solution. Convert the indices to 1-indexed before returning.
- If the sum is less than the target, move the `left` pointer to the right. If it's more, move the `right` pointer to the left.
- Continue this process until you find the solution.

### Complexity Analysis

- **Time Complexity**: O(n), where `n` is the length of the array. In the worst case, the entire array is traversed once.
- **Space Complexity**: O(1), as no extra space is used beyond variables for the two pointers.

## Notes

---

 

## Related Videos

---

[https://youtu.be/cQ1Oz4ckceM](https://youtu.be/cQ1Oz4ckceM)