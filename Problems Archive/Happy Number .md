# Happy Number

Problem: 202
Official Difficulty: easy
Feels Like : medium
My Understanding: Mostly Understand
Topic: Math, string
Link: https://leetcode.com/problems/happy-number/description/
Completed On : June 18, 2024
Last Review: June 18, 2024
Days Since Review: 6

## Problem

---

Write an algorithm to determine if a number `n` is happy.

A **happy number** is a number defined by the following process:

- Starting with any positive integer, replace the number by the sum of the squares of its digits.
- Repeat the process until the number equals 1 (where it will stay), or it **loops endlessly in a cycle** which does not include 1.
- Those numbers for which this process **ends in 1** are happy.

Return `true` *if* `n` *is a happy number, and* `false` *if not*.

**Example 1:**

```
Input: n = 19
Output: true
Explanation:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
```

**Example 2:**

```
Input: n = 2
Output: false
```

**Constraints:**

- `1 <= n <= 231 - 1`

## My Solutions

---

- Wrong

```python
class Solution:
    def isHappy(self, n: int) -> bool:

        """
        - Hash the seen states 
        - Simulate Splitting into digits and squaring
        - Continue until 1 or if a sate is revisited we return true

        TC: O(1)
        SC: O(1)
        """

        if n == 1:
            return True

        if len(str(n)) < 2:
            return False

        visited = set([n])

        while n != 1:

            d1 = int(str(n)[0])
            d2 = int(str(n)[1])

            n = d1**2 + d2**2

            if n in visited:
                return False

            visited.add(n)

        return True

            

         
```

### Steps:

1. **Hash the Seen States**: Use a set to keep track of numbers we've already seen to detect cycles.
2. **Simulate the Process**: Continuously split the number into its digits, square each digit, and sum the squares until we reach 1 or detect a cycle.

### Python Code

Here's the corrected and improved Python code to achieve this:

```python
class Solution:
    def isHappy(self, n: int) -> bool:
        """
        Determine if a number is a happy number.

        A happy number is a number that eventually reaches 1 when replaced by the sum of the square of each digit.
        """

        def get_next(number):
            total_sum = 0
            while number > 0:
                digit = number % 10
                total_sum += digit * digit
                number //= 10
            return total_sum

        visited = set()

        while n != 1 and n not in visited:
            visited.add(n)
            n = get_next(n)

        return n == 1

# Example usage
solution = Solution()
print(solution.isHappy(19))  # Output: True
print(solution.isHappy(2))   # Output: False

```

### Explanation

1. **Helper Function**:
    - `get_next(number)`: This function computes the sum of the squares of the digits of `number`. It extracts each digit by taking `number % 10` and updates the total sum by squaring the digit. It then removes the last digit by integer division `number //= 10`.
2. **Main Logic**:
    - Use a set `visited` to keep track of numbers that have been seen.
    - Loop until `n` becomes 1 or a cycle is detected (i.e., `n` is found in `visited`).
    - Inside the loop, add `n` to the `visited` set and update `n` to the result of `get_next(n)`.
3. **Termination**:
    - The loop terminates when `n` equals 1 (indicating the number is happy) or a cycle is detected (indicating the number is not happy).
    - Return `True` if `n` is 1, otherwise `False`.

### Time Complexity Analysis

- **Time Complexity**: `O(log n)`
    - The number of iterations is proportional to the number of digits in the number, which is `O(log n)`. Each iteration involves calculating the sum of squares of the digits, which takes `O(log n)` time.
    - Thus, the overall time complexity is `O(log n)`.

### Space Complexity Analysis

- **Space Complexity**: `O(log n)`
    - The space complexity is determined by the number of unique numbers encountered during the process, which is proportional to the number of digits in the number.
    - Thus, the overall space complexity is `O(log n)`.

```python

```

---

---

 

## Related Videos

---

[https://www.notion.so](https://www.notion.so)