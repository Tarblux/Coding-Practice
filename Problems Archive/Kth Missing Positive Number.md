# Kth Missing Positive Number

Problem: 1539
Official Difficulty: easy
Feels Like : easy
My Understanding: Fully Understand
Topic: array, binary search
Link: https://leetcode.com/problems/kth-missing-positive-number/
Completed On : June 2, 2024
Last Review: June 2, 2024
Days Since Review: 7

## Problem

---

Given an array `arr` of positive integers sorted in a **strictly increasing order**, and an integer `k`.

Return *the* `kth` ***positive** integer that is **missing** from this array.*

**Example 1:**

```
Input: arr = [2,3,4,7,11], k = 5
Output: 9
Explanation:The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.
```

**Example 2:**

```
Input: arr = [1,2,3,4], k = 2
Output: 6
Explanation:The missing positive integers are [5,6,7,...]. The 2nd missing positive integer is 6.
```

**Constraints:**

- `1 <= arr.length <= 1000`
- `1 <= arr[i] <= 1000`
- `1 <= k <= 1000`
- `arr[i] < arr[j]` for `1 <= i < j <= arr.length`

**Follow up:**

Could you solve this problem in less than O(n) complexity?

## My Solutions

---

```python
class Solution:
    def findKthPositive(self, arr: List[int], k: int) -> int:

        arr = [0] + arr
        
        output = []

        for i in range(1,len(arr)):

            if arr[i-1] != arr[i] - 1 :

                missing = arr[i-1] + 1

                while missing != arr[i]:

                    output.append(missing)
                    missing += 1
                    

        if len(output) < k:

            last = arr[-1]
            return last + (k-len(output))

        return output[k - 1]
```

```python

```

## Optimal Solutions

---

### Problem Description

Given an array `arr` of positive integers sorted in a strictly increasing order, and an integer `k`, return the `k`-th positive integer that is missing from this array.

### Example

```python
Input: arr = [2, 3, 4, 7, 11], k = 5
Output: 9

Input: arr = [1, 2, 3, 4], k = 2
Output: 6
```

### Optimal Solution and Explanation

To solve this problem, we need to find the `k`-th missing positive integer from the array. One efficient way to do this is by using binary search.

### Steps:

1. **Calculate the number of missing numbers**: For each index `i` in the array, the number of missing numbers before `arr[i]` can be determined by `arr[i] - (i + 1)`.
2. **Binary Search**:
    - Use binary search to find the smallest index `i` such that the number of missing numbers up to `arr[i]` is at least `k`.
    - The missing number is then determined by calculating how many more numbers need to be added to reach `k`.

### Python Code

Here's the Python code to achieve this:

```python
def findKthPositive(arr, k):
    left, right = 0, len(arr) - 1

    # Perform binary search
    while left <= right:
        mid = (left + right) // 2
        # Missing numbers until arr[mid]
        missing = arr[mid] - (mid + 1)

        if missing < k:
            left = mid + 1
        else:
            right = mid - 1

    # The left pointer will point to the first element where the number of missing elements is >= k
    return left + k

# Example usage
print(findKthPositive([2, 3, 4, 7, 11], 5))  # Output: 9
print(findKthPositive([1, 2, 3, 4], 2))      # Output: 6
```

### Explanation

1. **Binary Search Setup**:
    - Initialize `left` to 0 and `right` to `len(arr) - 1`.
2. **Binary Search Execution**:
    - Calculate `mid` as the middle index.
    - Calculate the number of missing numbers up to `arr[mid]` using the formula `arr[mid] - (mid + 1)`.
    - If the number of missing numbers is less than `k`, move the `left` pointer to `mid + 1`.
    - Otherwise, move the `right` pointer to `mid - 1`.
3. **Calculate the k-th Missing Positive**:
    - After the binary search, `left` will point to the first element where the number of missing elements is at least `k`.
    - The k-th missing number is then `left + k`.

### Time Complexity Analysis

- **Binary Search**: The binary search runs in `O(log n)` time, where `n` is the length of the array.
- **Overall Time Complexity**: `O(log n)`

### Space Complexity Analysis

- **Space Complexity**: `O(1)`
    - We use a constant amount of additional space for the pointers and temporary variables.

### Explain Like I'm Five (ELI5)

Imagine you have a row of numbered slots, and some of the slots are missing:

1. **Count Missing Slots**: For each slot, count how many slots are missing up to that point.
2. **Find the Right Spot**: Use a clever way (binary search) to quickly find the spot where the count of missing slots is just right.
3. **Calculate the Missing Number**: Once you find the spot, you can easily calculate which number is the `k`th missing number.

By counting and searching efficiently, you can find the missing number without checking every single slot one by one.

## Notes

---

 

## Related Videos

---

[https://www.notion.so](https://www.notion.so)