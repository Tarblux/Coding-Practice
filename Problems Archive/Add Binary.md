# Add Binary

Problem: 67
Official Difficulty: easy
Feels Like : easy
My Understanding: Mostly Understand
Topic: Bit Manipulation, Math, simulation, string
Link: https://leetcode.com/problems/add-binary/description/
Completed On : March 3, 2024
Last Review: March 3, 2024
Days Since Review: 0

## Problem

---

Given two binary strings `a` and `b`, return *their sum as a binary string*.

**Example 1:**

```
Input: a = "11", b = "1"
Output: "100"
```

**Example 2:**

```
Input: a = "1010", b = "1011"
Output: "10101"
```

**Constraints:**

- `1 <= a.length, b.length <= 104`
- `a` and `b` consist only of `'0'` or `'1'` characters.
- Each string does not contain leading zeros except for the zero itself.

## My Solutions

---

This fails this test case a = 1111 and b = 1111 , unsure why for now

```python
class Solution:

    def addBinary(self, a: str, b: str) -> str:

        ans = []

        a_len = len(a) - 1

        b_len = len(b) - 1

        carry = 0

        while a_len >= 0 or b_len >= 0 or carry: 

            a_bin = int(a[a_len]) if a_len >= 0 else 0
            b_bin = int(b[b_len]) if b_len >= 0 else 0
            sums = int(a_bin) + int(b_bin) + carry 

            if a_len == 0 and b_len == 0 and carry : 

                ans.insert(0,'1')

                carry = 0

                break

            if sums == 0 : 

                ans.insert(0,'0')
                carry = 0

            elif sums == 1 : 

                ans.insert(0,'1')
                carry = 0

            elif sums == 2 :

                ans.insert(0,'0')
                carry = 1 
            else :

                ans.insert(0,'1')
                carry = 1 

            a_len -= 1

            b_len -= 1

        return ''.join(ans)
```

```python
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        ans = []
        a_len, b_len = len(a) - 1, len(b) - 1
        carry = 0

        while a_len >= 0 or b_len >= 0 or carry:
            a_bin = int(a[a_len]) if a_len >= 0 else 0
            b_bin = int(b[b_len]) if b_len >= 0 else 0
            sums = a_bin + b_bin + carry

            carry = sums // 2 
            ans.append(str(sums % 2))  

            a_len -= 1
            b_len -= 1

        return ''.join(reversed(ans)) 
```

## Optimal Solutions

---

The "Add Binary" problem asks you to add two binary strings and return their sum, also as a binary string. The input is two binary strings `a` and `b`.

### Approach

To solve this problem, you can simulate the binary addition process starting from the least significant bit (rightmost bit) of both input strings, moving towards the most significant bit (leftmost bit). Keep track of the carry that results from each bit addition, as it will be added to the next bit calculation.

### Python Implementation

Here's a Python function to perform binary string addition:

```python
def addBinary(a: str, b: str) -> str:
    # Initialize the result string and the carry
    result = ""
    carry = 0

    # Initialize pointers for both strings at their last characters
    i, j = len(a) - 1, len(b) - 1

    # Loop until all digits are processed or there is no carry left
    while i >= 0 or j >= 0 or carry:
        # Sum the carry with the current digits of a and b
        total = carry
        if i >= 0:
            total += int(a[i])
            i -= 1
        if j >= 0:
            total += int(b[j])
            j -= 1

        # Compute carry and the current digit of the result
        carry, digit = divmod(total, 2)

        # Prepend the digit to the result string
        result = str(digit) + result

    return result
```

### Explanation

- The function loops until all digits from both binary strings are processed. It also checks for any remaining carry that needs to be added to the result.
- For each iteration, it calculates the total of the current digit by adding the carry with the current digits from `a` and `b`. If the pointer for `a` or `b` is out of range (negative), it means that string has no more digits to process, and only the carry (if any) is added.
- The `divmod(total, 2)` function is used to compute the carry and the current result digit. The quotient is the new carry (either `0` or `1`), and the remainder is the current digit of the result.
- The current digit is prepended to the result string. This is important because binary addition is performed from right to left, but the result is constructed from left to right.
- After processing all digits and carry, the final result string is returned.

### Complexity Analysis

- **Time Complexity**: O(max(N, M)), where N and M are the lengths of the binary strings `a` and `b`, respectively. This is because the algorithm iterates through each digit of the longer string once.
- **Space Complexity**: O(max(N, M)), the space used by the `result` string to store the sum of the two binary strings.

# Bitwise Optimal

Solving the "Add Binary" problem using bit manipulation involves treating the binary strings as integers and performing the addition operation in binary without converting the entire strings to integers upfront. The goal is to iterate through the strings and apply bitwise operations to simulate binary addition, handling the carry as we move along.

### Approach

1. **Convert Binary Strings to Integers**: We start by converting each character in the binary strings to an integer, but rather than converting the entire string to an integer at once, we process one character at a time from right to left.
2. **Bitwise Addition and Carry**: Use bitwise operations to simulate the addition of each bit and carry the overflow to the next significant bit.

### Python Implementation

This approach requires a different way of thinking about the problem since Python doesn't directly support bitwise operations on strings. However, we can simulate the process by converting bits to integers and manipulating those:

```python
def addBinary(a: str, b: str) -> str:
    result = []
    carry = 0
    a, b = list(a), list(b)

    while a or b or carry:
        if a:
            carry += int(a.pop())
        if b:
            carry += int(b.pop())

        # Bitwise AND with 1 will give us the result of adding the two bits plus carry
        result.append(str(carry & 1))
        # Right-shift carry by 1 will give us the new carry
        carry >>= 1

    # Reverse the result and join to form the final binary string
    return ''.join(reversed(result))
```

### Explanation

- We convert the input strings `a` and `b` into lists to easily pop elements from the end (simulate processing from the least significant bit to the most significant bit).
- In each iteration, we add the value of the current bit from each string (if present) to the `carry`. Since we're adding binary numbers, the sum can be 0, 1, 2, or 3.
- We append the result of `carry & 1` to the result list, which gives the current bit value of the sum in binary (0 or 1).
- We update the `carry` by right-shifting one position (`carry >>= 1`). This effectively divides the carry by 2, preparing it for the next iteration (since, in binary addition, a carry happens when the sum is 2 or 3).
- Since we're appending the least significant bit of the result first, we need to reverse the result list before returning it as a string.

### Complexity Analysis

- **Time Complexity**: O(max(N, M)), where N and M are the lengths of the binary strings `a` and `b`. This is due to the iteration over each bit in the input strings.
- **Space Complexity**: O(max(N, M)) for storing the result. The space needed for the result is proportional to the length of the longer input string.

This solution effectively uses bit manipulation concepts to simulate binary addition, providing an optimal and elegant way to solve the problem without relying on converting the entire binary strings to integers at the beginning.

## Notes

---

 

## Related Videos

---

[https://www.notion.so](https://www.notion.so)