# Number Complement

Problem: 476
Official Difficulty: easy
Feels Like : medium
My Understanding: I Have No Idea
Topic: Bit Manipulation
Link: https://leetcode.com/problems/number-complement/description/
Completed On : June 6, 2024
Last Review: June 6, 2024
Days Since Review: 3

## Problem

---

The **complement** of an integer is the integer you get when you flip all the `0`'s to `1`'s and all the `1`'s to `0`'s in its binary representation.

- For example, The integer `5` is `"101"` in binary and its **complement** is `"010"` which is the integer `2`.

Given an integer `num`, return *its complement*.

**Example 1:**

```
Input: num = 5
Output: 2
Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.
```

**Example 2:**

```
Input: num = 1
Output: 0
Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.
```

**Constraints:**

- `1 <= num < 231`

## My Solutions

---

```python

```

```python

```

## Optimal Solutions

---

https://leetcode.com/problems/number-complement/editorial/

### Problem Description

Given a positive integer `num`, output its complement number. The complement strategy is to flip the bits of its binary representation.

### Example

```python
Input: num = 5
Output: 2
Explanation: The binary representation of 5 is 101, and its complement is 010, which is 2.

Input: num = 1
Output: 0
Explanation: The binary representation of 1 is 1, and its complement is 0.
```

### Optimal Solution and Explanation

To find the complement of a number, you need to flip all the bits in its binary representation. Here's the step-by-step approach to achieve this:

1. **Find the Binary Length**: Determine the number of bits required to represent the number.
2. **Create a Bitmask**: Create a bitmask that has the same number of bits all set to `1`.
3. **XOR Operation**: XOR the number with the bitmask to flip all the bits.

### Steps:

1. **Calculate the Bitmask**: For a given number `num`, if it has `n` bits, the bitmask can be calculated as `(1 << n) - 1`, where `1 << n` shifts `1` left by `n` positions to create a number with `n` bits all set to `1`.
2. **Compute the Complement**: XOR the number with the bitmask to get the complement.

### Python Code

Here's the Python code to achieve this:

```python
def findComplement(num):
    # Calculate the bit length of num
    bit_length = num.bit_length()

    # Create a bitmask with the same number of bits as num, all set to 1
    bitmask = (1 << bit_length) - 1

    # XOR num with the bitmask to get the complement
    return num ^ bitmask

# Example usage
print(findComplement(5))  # Output: 2
print(findComplement(1))  # Output: 0
```

### Explanation

1. **Bit Length Calculation**:
    - `num.bit_length()` returns the number of bits required to represent `num` in binary. For example, `5` has a binary representation of `101`, which requires 3 bits.
2. **Bitmask Creation**:
    - `(1 << bit_length) - 1` creates a bitmask with all bits set to `1` for the length of the number. For example, for a 3-bit number, this results in `111` (binary), which is `7` in decimal.
3. **XOR Operation**:
    - XORing the number with the bitmask flips all the bits. For example, `5` (binary `101`) XOR `7` (binary `111`) results in `2` (binary `010`).

### Time Complexity Analysis

- **Time Complexity**: `O(1)`
    - Bit operations are performed in constant time.

### Space Complexity Analysis

- **Space Complexity**: `O(1)`
    - A constant amount of space is used for the bitmask and the result.

### Explain Like I'm Five (ELI5)

Imagine you have a series of light switches. Each switch can be either on (1) or off (0). You want to flip all the switches:

1. **Count the Switches**: First, count how many switches you have.
2. **Create a Mask**: Create a mask where all switches are turned on.
3. **Flip the Switches**: Use this mask to flip all the switches at once.

By using the mask and flipping the switches, you can quickly change all the on switches to off and all the off switches to on.

## Notes

---

 

## Related Videos

---

[https://www.notion.so](https://www.notion.so)