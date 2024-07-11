# Three Consecutive Odds

Problem: 1550
Official Difficulty: easy
Feels Like : easy breazy
My Understanding: Fully Understand
Topic: array
Link: https://leetcode.com/problems/three-consecutive-odds/description/
Completed On : July 1, 2024
Last Review: July 1, 2024
Days Since Review: 10

## Problem

---

Problem Description

Given an integer array arr, return true if there are three consecutive odd numbers in the array. Otherwise, return false.

Example

Input: arr = [2,6,4,1]
Output: false

Input: arr = [1,2,34,3,4,5,7,23,12]
Output: true

## My Solutions

---

```python
class Solution:
    def threeConsecutiveOdds(self, arr: List[int]) -> bool:

        odds = 0

        for i in range(len(arr)):

            if i > len(arr) - 3:
                return False

            if arr[i] % 2 != 0:

                for j in range(i+1,i+3):

                    if arr[j] % 2 != 0:
                        odds += 1
                    
                    if odds == 2:
                        return True
            
            odds = 0

        return False

```

Found in discussion. Lol

```python
class Solution:
    def threeConsecutiveOdds(self, arr: List[int]) -> bool:
        return "111" in "".join([str(i%2) for i in arr])
```

```python
class Solution:
    def threeConsecutiveOdds(self, arr: List[int]) -> bool:
        consecutive_odds = 0

        # Increment the counter if the number is odd,
        # else reset the counter
        for num in arr:
            # Check if the current number is odd
            if num % 2 == 1:
                consecutive_odds += 1
            else:
                consecutive_odds = 0

            # Check if there are three consecutive odd numbers
            if consecutive_odds == 3:
                return True

        return False
```

## Optimal Solutions

---

### Problem Description

Given an integer array `arr`, return `true` if there are three consecutive odd numbers in the array. Otherwise, return `false`.

### Example

```python
Input: arr = [2,6,4,1]
Output: false

Input: arr = [1,2,34,3,4,5,7,23,12]
Output: true

```

### Optimal Solution and Explanation

To solve this problem, we can simply iterate through the array and check for three consecutive odd numbers. If we find such a sequence, we return `true`. If we finish iterating through the array without finding such a sequence, we return `false`.

### Steps:

1. **Iterate through the array**:
    - Use a loop to iterate through the array up to the third last element.
2. **Check for three consecutive odds**:
    - For each element, check if it and the next two elements are odd.
    - If a sequence of three consecutive odd numbers is found, return `true`.
3. **Return `false` if no sequence is found**:
    - If the loop completes without finding three consecutive odd numbers, return `false`.

### Python Code

Here's the Python code to achieve this:

```python
class Solution:
    def threeConsecutiveOdds(self, arr: List[int]) -> bool:
        for i in range(len(arr) - 2):
            if arr[i] % 2 != 0 and arr[i + 1] % 2 != 0 and arr[i + 2] % 2 != 0:
                return True
        return False

# Example usage
solution = Solution()
print(solution.threeConsecutiveOdds([2,6,4,1]))  # Output: false
print(solution.threeConsecutiveOdds([1,2,34,3,4,5,7,23,12]))  # Output: true

```

### Explanation

1. **Iterate through the array**:
    - We use a loop to iterate through the array up to the index `len(arr) - 3` to ensure we have at least three elements to check in each iteration.
2. **Check for three consecutive odds**:
    - For each element, check if it, the next element, and the element after that are all odd using the modulo operator `% 2 != 0`.
    - If such a sequence is found, return `true`.
3. **Return `false` if no sequence is found**:
    - If the loop completes without finding a sequence of three consecutive odd numbers, return `false`.

### Time Complexity Analysis

- **Time Complexity**: `O(n)`
    - We iterate through the array once, where `n` is the length of the array.

### Space Complexity Analysis

- **Space Complexity**: `O(1)`
    - We use a constant amount of extra space, regardless of the input size.

This approach efficiently checks for three consecutive odd numbers in the array with linear time complexity.

## Notes

---

 

## Related Videos

---

[https://www.notion.so](https://www.notion.so)