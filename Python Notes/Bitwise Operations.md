### Introduction to Bitwise Operations:

Bitwise operations are fundamental operations that manipulate individual bits of binary representations of numbers. These operations are performed at the binary level, meaning they operate on the binary digits (bits) of the operands.

### Purpose of Bitwise Operations:

Bitwise operations are commonly used in low-level programming, such as embedded systems programming, device driver development, and cryptography. They are also useful in optimizing certain algorithms and solving specific problems efficiently.

### Bitwise Operators in Python:

Python provides several bitwise operators:

1. **Bitwise AND (&)**: Sets each bit to 1 if both corresponding bits are 1.
2. **Bitwise OR (|)**: Sets each bit to 1 if at least one of the corresponding bits is 1.
3. **Bitwise XOR (^)**: Sets each bit to 1 if exactly one of the corresponding bits is 1.
4. **Bitwise NOT (~)**: Inverts all the bits.
5. **Left Shift (<<)**: Shifts the bits to the left by a specified number of positions. Which ends up being sort of like just multiplying by two.
6. **Right Shift (>>)**: Shifts the bits to the right by a specified number of positions. Which ends up being sort of like dividing by two.

### Notes on Bitwise Operations with Examples:

#### 1. Bitwise AND (&):

```python
a = 60    # 0011 1100
b = 13    # 0000 1101
result = a & b  # 0000 1100
```

#### 2. Bitwise OR (|):

```python
a = 60    # 0011 1100
b = 13    # 0000 1101
result = a | b  # 0011 1101
```

#### 3. Bitwise XOR (^):

```python
a = 60    # 0011 1100
b = 13    # 0000 1101
result = a ^ b  # 0011 0001
```

#### 4. Bitwise NOT (~):

```python
a = 60    # 0011 1100
result = ~a  # -61 (Two's complement)
```

#### 5. Left Shift (<<):

```python
a = 60    # 0011 1100
result = a << 2  # 1111 0000
```

#### 6. Right Shift (>>):

```python
a = 60    # 0011 1100
result = a >> 2  # 0000 1111
```

### Related Methods or Functions in Python:

Python also provides built-in functions to perform certain bitwise operations:

- **bin()**: Converts an integer to its binary representation.
- **int()**: Converts a binary string to an integer.
- **format()**: Formats integers as binary strings.

**Order of precedence :**

In Python, as with arithmetic operations, bitwise operations follow a specific order of precedence. The order of precedence for bitwise operations is as follows, from highest to lowest:

1. Bitwise NOT (~)
2. Bitwise AND (&)
3. Bitwise XOR (^)
4. Bitwise OR (|)

So, when you have multiple bitwise operations in a single expression, they are evaluated in the order specified above.

In your example, `4 & 2 | 3`:

1. First, the bitwise AND operation (`&`) is evaluated because it has a higher precedence than bitwise OR (`|`).
2. Then, the bitwise OR operation (`|`) is evaluated.

So, `4 & 2` is evaluated first, resulting in `0`, then `0 | 3` is evaluated, resulting in `3`. Therefore, the result of the expression `4 & 2 | 3` is `3`.

### Other Useful Notes:

- Bitwise operations are often used for optimizing code and solving specific problems in areas like networking, cryptography, and embedded systems.
- Understanding binary representation and the effects of bitwise operations on it is crucial for using these operations effectively.
- Bitwise operations can be used to manipulate flags or settings represented by individual bits within a binary number.
- Bitwise operations are generally faster than arithmetic operations, making them useful for performance-critical applications.

Overall, mastering bitwise operations can significantly enhance your ability to work with low-level data manipulation and optimization tasks in Python and other programming languages.
