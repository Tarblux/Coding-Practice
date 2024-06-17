# Confusing Number

Problem: 1056
Official Difficulty: easy
Feels Like : medium
My Understanding: Needs Review
Topic: Math
Link: https://leetcode.com/problems/confusing-number/description/
Completed On : June 12, 2024
Last Review: June 12, 2024
Days Since Review: 4

## Problem

---

A **confusing number** is a number that when rotated `180` degrees becomes a different number with **each digit valid**.

We can rotate digits of a number by `180` degrees to form new digits.

- When `0`, `1`, `6`, `8`, and `9` are rotated `180` degrees, they become `0`, `1`, `9`, `8`, and `6` respectively.
- When `2`, `3`, `4`, `5`, and `7` are rotated `180` degrees, they become **invalid**.

Note that after rotating a number, we can ignore leading zeros.

- For example, after rotating `8000`, we have `0008` which is considered as just `8`.

Given an integer `n`, return `true` *if it is a **confusing number**, or* `false` *otherwise*.

**Example 1:**

![https://assets.leetcode.com/uploads/2019/03/23/1268_1.png](https://assets.leetcode.com/uploads/2019/03/23/1268_1.png)

```
Input: n = 6
Output: true
Explanation: We get 9 after rotating 6, 9 is a valid number, and 9 != 6.

```

**Example 2:**

![https://assets.leetcode.com/uploads/2019/03/23/1268_2.png](https://assets.leetcode.com/uploads/2019/03/23/1268_2.png)

```
Input: n = 89
Output: true
Explanation: We get 68 after rotating 89, 68 is a valid number and 68 != 89.

```

**Example 3:**

![https://assets.leetcode.com/uploads/2019/03/26/1268_3.png](https://assets.leetcode.com/uploads/2019/03/26/1268_3.png)

```
Input: n = 11
Output: false
Explanation: We get 11 after rotating 11, 11 is a valid number but the value remains the same, thus 11 is not a confusing number

```

**Constraints:**

- `0 <= n <= 109`

## My Solutions

---

```python
class Solution:
    def confusingNumber(self, n: int) -> bool:

        invert_map = {"0":"0", "1":"1", "8":"8", "6":"9", "9":"6"}
        rotated_number = []
        
        for ch in str(n):
            if ch not in invert_map:
                return False

            rotated_number.append(invert_map[ch])
        
        rotated_number = "".join(rotated_number)

        return int(rotated_number[::-1]) != n
```

```python

```

## Optimal Solutions

---

### Problem Description

Given a number `n`, return `true` if `n` is a confusing number, or `false` otherwise.

A confusing number is a number that when rotated 180 degrees becomes a different number with each digit valid. Valid digits are `0, 1, 6, 8, 9` and rotate as follows:

- `0` becomes `0`
- `1` becomes `1`
- `6` becomes `9`
- `8` becomes `8`
- `9` becomes `6`

Other digits become invalid when rotated 180 degrees.

### Example

```python
Input: n = 6
Output: true
Explanation: The number 6 becomes 9 when rotated 180 degrees.

Input: n = 89
Output: true
Explanation: The number 89 becomes 68 when rotated 180 degrees.

Input: n = 11
Output: false
Explanation: The number 11 becomes 11 when rotated 180 degrees.

Input: n = 25
Output: false
Explanation: The number 25 becomes invalid when rotated.

```

### Optimal Solution and Explanation

To determine if a number is a confusing number, we can follow these steps:

1. **Check Validity**: Ensure that all digits of the number are in the set of valid digits `0, 1, 6, 8, 9`.
2. **Rotation and Comparison**: Rotate each digit and form the new number, then compare it with the original number to ensure they are different.

### Steps:

1. **Create a Dictionary for Rotations**: Define a dictionary to map each valid digit to its rotated equivalent.
2. **Extract and Rotate Digits**: Convert the number to a string, and for each digit, map it to its rotated equivalent.
3. **Form the Rotated Number**: Reverse the order of the rotated digits to simulate the 180-degree rotation.
4. **Comparison**: Compare the rotated number with the original number.

### Python Code

Here's the Python code to achieve this:

```python
def confusingNumber(n):
    # Mapping of valid digits to their rotated equivalents
    rotation_map = {'0': '0', '1': '1', '6': '9', '8': '8', '9': '6'}

    # Convert the number to a string
    s = str(n)

    # Initialize the rotated number
    rotated = []

    # Rotate each digit
    for char in s:
        if char not in rotation_map:
            return False
        rotated.append(rotation_map[char])

    # Form the rotated number by reversing the rotated list and joining
    rotated_number = ''.join(rotated[::-1])

    # Compare the rotated number with the original number
    return rotated_number != s

# Example usage
print(confusingNumber(6))    # Output: true
print(confusingNumber(89))   # Output: true
print(confusingNumber(11))   # Output: false
print(confusingNumber(25))   # Output: false

```

### Explanation

1. **Mapping of Valid Digits**:
    - Create a dictionary `rotation_map` to map valid digits to their rotated equivalents.
2. **Conversion and Rotation**:
    - Convert the number to a string for easy manipulation.
    - Iterate through each character of the string and use the `rotation_map` to get the rotated digit.
    - If a character is not in the `rotation_map`, return `false` as it cannot be a valid confusing number.
3. **Forming the Rotated Number**:
    - Reverse the list of rotated digits to simulate the 180-degree rotation.
    - Join the reversed list to form the rotated number.
4. **Comparison**:
    - Compare the rotated number with the original number. If they are different, return `true`; otherwise, return `false`.

### Time Complexity Analysis

- **Time Complexity**: `O(d)`, where `d` is the number of digits in the number `n`.
    - We iterate through each digit of the number once.

### Space Complexity Analysis

- **Space Complexity**: `O(d)`
    - We use a list to store the rotated digits, which requires space proportional to the number of digits in the number `n`.

## Notes

---

 Same as leetcode 246 :

https://leetcode.com/problems/strobogrammatic-number/description/

![Screenshot 2024-06-12 at 17-25-30 Confusing Number - LeetCode.png](Confusing%20Number%20abc2f18b793f42ac8ebb8ed5c84f74a5/Screenshot_2024-06-12_at_17-25-30_Confusing_Number_-_LeetCode.png)

## Related Videos

---

[https://www.youtube.com/watch?v=o74xgGWxSvE](https://www.youtube.com/watch?v=o74xgGWxSvE)