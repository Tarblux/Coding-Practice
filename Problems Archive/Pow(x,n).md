# Pow(x,n)

Problem: 50
Official Difficulty: medium
Feels Like : hard
My Understanding: Needs Review
Topic: Math, recursion
Link: https://leetcode.com/problems/powx-n/description/
Completed On : May 17, 2024
Last Review: May 17, 2024
Days Since Review: 2

## Problem

---

Implement [pow(x, n)](http://www.cplusplus.com/reference/valarray/pow/), which calculates `x` raised to the power `n` (i.e., `xn`).

**Example 1:**

```
Input: x = 2.00000, n = 10
Output: 1024.00000
```

**Example 2:**

```
Input: x = 2.10000, n = 3
Output: 9.26100
```

**Example 3:**

```
Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
```

**Constraints:**

- `100.0 < x < 100.0`
- `231 <= n <= 2311`
- `n` is an integer.
- Either `x` is not zero or `n > 0`.
- `104 <= xn <= 104`

## My Solutions

---

```python
class Solution:
    def myPow(self, x: float, n: int) -> float:

        if n == 0:
            return 1

        result = 1

        if n < 0: 
            x = 1/x
        
        n = abs(n)
            
        while n:

            if n%2 == 1:
                result *= x
                n-=1
            
            x *= x
            n//=2

        return result
```

```python

```

## Optimal Solutions

---

### Optimal Solutions and Explanation

To solve the problem of calculating \( x \) raised to the power of \( n \), we can use both iterative and recursive approaches. Both methods utilize the principle of exponentiation by squaring to achieve an \( O(\log n) \) time complexity.

### Recursive Solution

The recursive solution leverages the properties of powers to break down the problem into smaller subproblems:

1. If \( n \) is even, \( x^n = (x^2)^{n/2} \)
2. If \( n \) is odd, \( x^n = x \times x^{n-1} \)

Here's the Python code for the recursive solution:

```python
def myPowRecursive(x, n):
    def fastPow(x, n):
        if n == 0:
            return 1.0
        half = fastPow(x, n // 2)
        if n % 2 == 0:
            return half * half
        else:
            return half * half * x

    if n < 0:
        x = 1 / x
        n = -n
    return fastPow(x, n)

# Example usage
print(myPowRecursive(2.0, 10))  # Output: 1024.0
print(myPowRecursive(2.1, 3))   # Output: 9.261
print(myPowRecursive(2.0, -2))  # Output: 0.25

```

### Iterative Solution

The iterative solution uses a loop to perform the same operations without the need for recursive function calls:

1. Initialize the result as 1.0.
2. Adjust \( x \) and \( n \) for negative exponents.
3. Loop through \( n \), updating \( x \) and the result based on whether the current power is even or odd.

Here's the Python code for the iterative solution:

```python
def myPowIterative(x, n):
    if n < 0:
        x = 1 / x
        n = -n

    result = 1.0
    current_product = x

    while n > 0:
        if n % 2 == 1:  # If n is odd
            result *= current_product
        current_product *= current_product  # Square the base
        n //= 2  # Reduce n by half

    return result

# Example usage
print(myPowIterative(2.0, 10))  # Output: 1024.0
print(myPowIterative(2.1, 3))   # Output: 9.261
print(myPowIterative(2.0, -2))  # Output: 0.25

```

### Explain Like I'm Five (ELI5)

Imagine you have a super strong robot that can multiply numbers really fast. You want to find out what happens if you multiply a number \( x \) by itself \( n \) times. But instead of making the robot do all the multiplications one by one, you use a clever trick to save time:

1. **Recursive Approach**:
    - Break it down: If you need to multiply a number a lot of times, you can break the problem into smaller, easier pieces.
    - If you want \( x \) to the power of 4, you can do:
        - \( x^4 = (x^2) \times (x^2) \)
        - And \( x^2 = x \times x \)
    - Use smaller pieces: By breaking the problem down like this, the robot can solve it faster because it reuses the results of smaller multiplications.
    - Handle negatives: If you need to multiply by a negative number of times, you flip the number (like turning it upside down) and then multiply.
2. **Iterative Approach**:
    - Start with 1: Begin with a result of 1.
    - Loop through the steps: Multiply the result by the base number \( x \) whenever \( n \) is odd, and then square \( x \) and halve \( n \) until \( n \) is zero.
    - Handle negatives: If \( n \) is negative, flip \( x \) upside down (i.e., take the reciprocal) and then treat \( n \) as positive.

Both methods allow you to calculate the power in fewer steps by cleverly reusing calculations, making the process much faster!

## Notes

---

 

## Related Videos

---

[https://www.youtube.com/watch?v=g9YQyYi4IQQ&pp=ygUIcG93KHggbik%3D](https://www.youtube.com/watch?v=g9YQyYi4IQQ&pp=ygUIcG93KHggbik%3D)