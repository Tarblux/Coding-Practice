# Height Checker

Problem: 1051
Official Difficulty: easy
Feels Like : easy breazy
My Understanding: Fully Understand
Topic: array, counting sort, sorting
Link: https://leetcode.com/problems/height-checker/description/
Completed On : June 10, 2024
Last Review: June 10, 2024
Days Since Review: 6

## Problem

---

A school is trying to take an annual photo of all the students. The students are asked to stand in a single file line in **non-decreasing order** by height. Let this ordering be represented by the integer array `expected` where `expected[i]` is the expected height of the `ith` student in line.

You are given an integer array `heights` representing the **current order** that the students are standing in. Each `heights[i]` is the height of the `ith` student in line (**0-indexed**).

Return *the **number of indices** where* `heights[i] != expected[i]`.

**Example 1:**

```
Input: heights = [1,1,4,2,1,3]
Output: 3
Explanation:
heights:  [1,1,4,2,1,3]
expected: [1,1,1,2,3,4]
Indices 2, 4, and 5 do not match.
```

**Example 2:**

```
Input: heights = [5,1,2,3,4]
Output: 5
Explanation:
heights:  [5,1,2,3,4]
expected: [1,2,3,4,5]
All indices do not match.
```

**Example 3:**

```
Input: heights = [1,2,3,4,5]
Output: 0
Explanation:
heights:  [1,2,3,4,5]
expected: [1,2,3,4,5]
All indices match.
```

**Constraints:**

- `1 <= heights.length <= 100`
- `1 <= heights[i] <= 100`

## My Solutions

---

```python
class Solution:
    def heightChecker(self, heights: List[int]) -> int:

        mismatch = 0

        expected = sorted(heights)

        for h , e in zip(heights,expected):

            if h!=e:
                mismatch +=1

        return mismatch
```

```python

```

## Optimal Solutions

---

### Problem Description

Students are asked to stand in non-decreasing order of heights for an annual photo. Return the number of students not standing in the right positions. This is defined as the number of indices where the heights do not match when the list is sorted.

### Example

```python
Input: heights = [1,1,4,2,1,3]
Output: 3

Input: heights = [5,1,2,3,4]
Output: 5

Input: heights = [1,2,3,4,5]
Output: 0
```

### Optimal Solution and Explanation

To solve this problem, we need to compare the original list of heights with its sorted version. The number of students not standing in the right positions is the number of indices where the original list and the sorted list differ.

### Steps:

1. **Sort the List**: Create a sorted version of the list `heights`.
2. **Compare with Original List**: Iterate through both lists and count the number of indices where the elements differ.

### Python Code

Here's the Python code to achieve this:

```python
def heightChecker(heights):
    # Create a sorted version of the list heights
    expected = sorted(heights)

    # Count the number of positions where the original list and sorted list differ
    count = 0
    for i in range(len(heights)):
        if heights[i] != expected[i]:
            count += 1

    return count

# Example usage
print(heightChecker([1, 1, 4, 2, 1, 3]))  # Output: 3
print(heightChecker([5, 1, 2, 3, 4]))     # Output: 5
print(heightChecker([1, 2, 3, 4, 5]))     # Output: 0

```

### Explanation

1. **Sorting**:
    - Create a sorted version of the `heights` list named `expected`.
2. **Comparison**:
    - Initialize a counter `count` to 0.
    - Iterate through the indices of the `heights` list.
    - For each index `i`, compare `heights[i]` with `expected[i]`.
    - If they differ, increment the counter `count`.
3. **Return the Result**:
    - Return the counter `count`, which represents the number of indices where the heights do not match.

### Time Complexity Analysis

- **Time Complexity**: `O(n log n)`
    - Sorting the list `heights` takes `O(n log n)` time, where `n` is the length of the list.
    - Comparing the elements of the two lists takes `O(n)` time.
- **Overall Time Complexity**: `O(n log n)`

### Space Complexity Analysis

- **Space Complexity**: `O(n)`
    - We use additional space to store the sorted version of the list `heights`.

### Explain Like I'm Five (ELI5)

Imagine you have a line of students and you know the correct order they should be standing in based on their height. To check how many students are out of order:

1. **Make a Correct Order List**: First, write down the correct order of heights.
2. **Compare Each Position**: Compare each student's position in the current line to the correct order.
3. **Count Differences**: Count how many students are standing in the wrong spot.

By comparing the actual line with the correct order, you can quickly find out how many students need to move to be in the right position.

## Notes

---

 

## Related Videos

---

[https://www.youtube.com/watch?v=mQAoeYaE3Xk&pp=ygULbmVldGNvZGUgaW8%3D](https://www.youtube.com/watch?v=mQAoeYaE3Xk&pp=ygULbmVldGNvZGUgaW8%3D)