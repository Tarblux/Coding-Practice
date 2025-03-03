# Rotate String

Problem: 796
Official Difficulty: easy
Feels Like : medium
My Understanding: Fully Understand
Topic: string, string matching
Link: https://leetcode.com/problems/rotate-string/description/
Completed On : November 2, 2024
Last Review: November 2, 2024
Days Since Review: 120
Neetcode: No

## Problem

---

Given two strings `s` and `goal`, return `true` *if and only if* `s` *can become* `goal` *after some number of **shifts** on* `s`.

A **shift** on `s` consists of moving the leftmost character of `s` to the rightmost position.

- For example, if `s = "abcde"`, then it will be `"bcdea"` after one shift.

**Example 1:**

```
Input: s = "abcde", goal = "cdeab"
Output: true
```

**Example 2:**

```
Input: s = "abcde", goal = "abced"
Output: false
```

**Constraints:**

- `1 <= s.length, goal.length <= 100`
- `s` and `goal` consist of lowercase English letters.

## My Solutions

---

```python
from collections import deque

class Solution:
    def rotateString(self, s: str, goal: str) -> bool:
        if len(s) != len(goal):
            return False

        queue_s = deque(s)
        queue_goal = deque(goal)

        for _ in range(len(s)):

            if queue_s == queue_goal:
                return True
                
            queue_s.rotate(-1) 

        return False
```

```python

```

## Optimal Solutions

---

To solve **LeetCode Problem 796: Rotate String**, the most efficient algorithm involves string manipulation and checking for substring inclusion.

---

### **Optimal Algorithm: Concatenate and Check Substring**

**Algorithm Overview:**

- **Objective:** Determine if string `s` can be rotated to become string `goal`.
- **Approach:** Concatenate `s` with itself, resulting in `s + s`. If `goal` is a substring of `s + s`, then `s` can be obtained by rotating `s`.

**Algorithm Steps:**

1. **Check Lengths:**
    - If the lengths of `s` and `goal` are not equal, return `False`.
2. **Concatenate `s` with Itself:**
    - Create a new string `concatenated = s + s`.
3. **Check for Substring:**
    - Use the `in` operator to check if `goal` is a substring of `concatenated`.
4. **Return the Result:**
    - Return `True` if `goal` is a substring; otherwise, return `False`.

**Code Example:**

```python
def rotateString(s: str, goal: str) -> bool:
    if len(s) != len(goal):
        return False
    concatenated = s + s
    return goal in concatenated

```

**Time Complexity:** O(n)

- **Explanation:**
    - Concatenation of `s` with itself takes O(n) time.
    - Checking if `goal` is a substring of `concatenated` is O(n).
    - Overall, the algorithm runs in linear time relative to the length of `s`.

**Space Complexity:** O(n)

- **Explanation:**
    - The concatenated string `s + s` uses O(n) additional space.
    - Other variables use negligible space.

---

### **Alternative Algorithm: Check All Rotations (Less Efficient)**

**Algorithm Overview:**

- **Approach:** Generate all possible rotations of `s` and check if any rotation equals `goal`.

**Algorithm Steps:**

1. **Check Lengths:**
    - If the lengths of `s` and `goal` are not equal, return `False`.
2. **Iterate Over Possible Rotations:**
    - For `i` from `0` to `len(s) - 1`:
        - Generate the rotation by slicing: `rotated = s[i:] + s[:i]`.
        - If `rotated` equals `goal`, return `True`.
3. **Return the Result:**
    - If no rotation matches `goal`, return `False`.

**Code Example:**

```python
def rotateString(s: str, goal: str) -> bool:
    if len(s) != len(goal):
        return False
    for i in range(len(s)):
        rotated = s[i:] + s[:i]
        if rotated == goal:
            return True
    return False

```

**Time Complexity:** O(n²)

- **Explanation:**
    - There are `n` rotations, each taking O(n) time to compute and compare.
    - Overall time complexity is quadratic.

**Space Complexity:** O(n)

- **Explanation:**
    - Each rotated string uses O(n) space.

---

### **Recommendation**

- The **concatenation method** is the optimal solution due to its linear time complexity and simplicity.
- The **rotation method** is less efficient and not recommended for longer strings.

---

### **Final Code Solution**

```python
class Solution:
    def rotateString(self, s: str, goal: str) -> bool:
        if len(s) != len(goal):
            return False
        concatenated = s + s
        return goal in concatenated
```

**Time Complexity:** O(n)

**Space Complexity:** O(n)

---

By concatenating `s` with itself and checking if `goal` is a substring, we efficiently determine whether `s` can be rotated to form `goal`.

## Notes

---

 

## Related Videos

---

[https://www.notion.so](https://www.notion.so)