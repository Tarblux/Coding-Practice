# Number of 1 Bits

Problem: 191
Official Difficulty: easy
Feels Like : easy
Topic: Bit Manipulation
Link: https://leetcode.com/problems/number-of-1-bits/
Completed On : December 8, 2023
My Understanding: Fully Understand
Last Review: December 8, 2023
Days Since Review: 64

---

Write a function that takes the binary representation of an unsigned 
integer and returns the number of '1' bits it has (also known as the [Hamming weight](http://en.wikipedia.org/wiki/Hamming_weight)).

**Note:**

- Note that in some languages, such as Java, there is no unsigned
integer type. In this case, the input will be given as a signed integer
type. It should not affect your implementation, as the integer's
internal binary representation is the same, whether it is signed or
unsigned.
- In Java, the compiler represents the signed integers using [2's complement notation](https://en.wikipedia.org/wiki/Two%27s_complement). Therefore, in **Example 3**, the input represents the signed integer. `3`.

**Example 1:**

```
Input: n = 00000000000000000000000000001011
Output: 3
Explanation: The input binary string00000000000000000000000000001011 has a total of three '1' bits.

```

**Example 2:**

```
Input: n = 00000000000000000000000010000000
Output: 1
Explanation: The input binary string00000000000000000000000010000000 has a total of one '1' bit.

```

**Example 3:**

```
Input: n = 11111111111111111111111111111101
Output: 31
Explanation: The input binary string11111111111111111111111111111101 has a total of thirty one '1' bits.

```

**Constraints:**

- The input must be a **binary string** of length `32`.

**Follow up:**

If this function is called many times, how would you optimize it?

## My Solutions

---

```python
class Solution:
    def hammingWeight(self, n: int) -> int:
        
        string = bin(n)
        
        ones = 0
        
        for char in string : 
            
            if char == "1" :
            
                ones += 1
            
        return ones
```

```python

```

## Optimal Solutions

---

The "Number of 1 Bits" problem, also known as the "Hamming Weight" problem, involves counting the number of '1' bits (set bits) in an integer's binary representation.

### Solution Approach

There are several ways to solve this problem, but one common approach is to use bit manipulation. The key idea is to repeatedly check the least significant bit of the number and then shift the bits to the right.

### Python Implementation

Here's a Python implementation of this approach:

```python
class Solution:
    def hammingWeight(self, n: int) -> int:
        count = 0
        while n:
            count += n & 1
            n >>= 1
        return count
```

### Explanation

- `count` is initialized to 0 to keep track of the number of '1' bits.
- In each iteration of the while loop:
    - `n & 1` performs a bit wise AND operation between `n` and 1. If the least significant bit of `n` is 1, `n & 1` will be 1, otherwise, it will be 0. This result is added to `count`.
    - `n >>= 1` right-shifts `n` by one bit. This operation effectively divides `n` by 2 and discards the least significant bit.
- The loop continues until `n` becomes 0.
- Finally, `count` is returned, which is the number of '1' bits in the binary representation of the original number.

### Complexity Analysis

- **Time Complexity**: O(k), where k is the number of bits in the integer. In Python, this is typically 32 or 64 bits depending on the machine. The while loop runs once for each bit.
- **Space Complexity**: O(1), as the space used is constant and does not depend on the size of the input.

## Notes

---

 

## Related Videos

---

[https://youtu.be/5Km3utixwZs?si=FZ69euX6I5CE3VVn](https://youtu.be/5Km3utixwZs?si=FZ69euX6I5CE3VVn)