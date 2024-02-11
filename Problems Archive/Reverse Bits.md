# Reverse Bits

Problem: 190
Official Difficulty: easy
Feels Like : easy
Topic: Bit Manipulation
Link: https://leetcode.com/problems/reverse-bits/
Completed On : December 9, 2023
My Understanding: Mostly Understand
Last Review: December 9, 2023
Days Since Review: 63

## Problem

---

Reverse bits of a given 32 bits unsigned integer.

**Note:**

- Note that in some languages, such as Java, there is no unsigned
integer type. In this case, both input and output will be given as a
signed integer type. They should not affect your implementation, as the
integer's internal binary representation is the same, whether it is
signed or unsigned.
- In Java, the compiler represents the signed integers using [2's complement notation](https://en.wikipedia.org/wiki/Two%27s_complement). Therefore, in **Example 2** above, the input represents the signed integer `3` and the output represents the signed integer `1073741825`.

**Example 1:**

```
Input: n = 00000010100101000001111010011100
Output:    964176192 (00111001011110000010100101000000)
Explanation:The input binary string00000010100101000001111010011100 represents the unsigned integer 43261596, so return 964176192 which its binary representation is00111001011110000010100101000000.
```

**Example 2:**

```
Input: n = 11111111111111111111111111111101
Output:   3221225471 (10111111111111111111111111111111)
Explanation:The input binary string11111111111111111111111111111101 represents the unsigned integer 4294967293, so return 3221225471 which its binary representation is10111111111111111111111111111111.
```

**Constraints:**

- The input must be a **binary string** of length `32`

**Follow up:** If this function is called many times, how would you optimize it?

## My Solutions

---

```python
class Solution:
    def reverseBits(self, n: int) -> int:
                        
        fint = 0
        
        power = 31
        
        while power >= 0 : 
            
            if (n&1) : 
                
                fint += 2 ** power
                
                
            power -= 1    
            
            n = n >> 1
                
        return fint
```

```python

```

## Optimal Solutions

---

The "Reverse Bits" problem involves reversing the bits of a given 32-bit unsigned integer. This means the bit at position 0 should be swapped with the bit at position 31, the bit at position 1 with the bit at position 30, and so on.

### Solution Approach

One common approach to solve this problem is to iterate through each bit of the number, extract the bit at each position, and then set it at the correct position in the reversed number.

### Python Implementation

Here's a Python implementation of this approach:

```python
class Solution:
    def reverseBits(self, n: int) -> int:
        reversed_num = 0
        for i in range(32):
            # Extract the rightmost bit of n
            bit = (n >> i) & 1
            # Set this bit at the reversed position in reversed_num
            reversed_num |= bit << (31 - i)
        return reversed_num
```

### Explanation

- Initialize `reversed_num` to 0. This variable will hold the reversed bits.
- Iterate over a range of 32, since we're dealing with 32-bit integers.
- For each `i` from 0 to 31:
    - Right shift `n` by `i` and bit wise-AND with 1 to extract the `i`th bit (this is the bit at position `i` from the right).
    - Left shift this bit by `(31 - i)` and bit wise-OR with `reversed_num` to set the bit at its reversed position.
- After the loop, `reversed_num` contains the integer representation of the reversed bits of `n`.

### Complexity Analysis

- **Time Complexity**: O(1), as the number of iterations is fixed at 32, independent of the input size.
- **Space Complexity**: O(1), as the space used is constant and does not depend on the input.

## Notes

---

 

## Related Videos

---

[https://www.notion.so](https://www.notion.so)