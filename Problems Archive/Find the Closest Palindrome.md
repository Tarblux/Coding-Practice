# Find the Closest Palindrome

Problem: 564
Official Difficulty: hard
Feels Like : Brain Damage
My Understanding: Needs Review
Topic: Math, string
Link: https://leetcode.com/problems/find-the-closest-palindrome/description/
Completed On : August 25, 2024
Last Review: August 25, 2024
Days Since Review: 1

## Problem

---

Given a string `n` representing an integer, return *the closest integer (not including itself), which is a palindrome*. If there is a tie, return ***the smaller one***.

The closest is defined as the absolute difference minimized between two integers.

**Example 1:**

```
Input: n = "123"
Output: "121"
```

**Example 2:**

```
Input: n = "1"
Output: "0"
Explanation: 0 and 2 are the closest palindromes but we return the smallest which is 0.
```

**Constraints:**

- `1 <= n.length <= 18`
- `n` consists of only digits.
- `n` does not have leading zeros.
- `n` is representing an integer in the range `[1, 1018 - 1]`.

## My Solutions

---

```python
class Solution:
    def nearestPalindromic(self, n: str) -> str:
        
        if len(n) == 1:
            return str(int(n) - 1)

        if len(n) == 2 and 9 < int(n) < 12 :
            return "9"

        if n == '99':
            return '101'

        if len(n) == 2:
            return str(int(n[0] * 2) if int(n[1]) > int(n[0]) else int(n[0] * 2) - 11)

        mid = len(n) // 2
        if len(n) % 2 == 0:
            left = n[:mid]
        else:
            left = n[:mid + 1]

        candidates = set()

        # 1. Mirror the left side directly
        if len(n) % 2 == 0:
            candidates.add(left + left[::-1])
        else:
            candidates.add(left[:-1] + left[::-1])

        # 2. Increment the left part and mirror
        incremented_left = str(int(left) + 1)
        if len(incremented_left) > len(left):
            candidates.add(incremented_left + incremented_left[:-1][::-1])
        else:
            if len(n) % 2 == 0:
                candidates.add(incremented_left + incremented_left[::-1])
            else:
                candidates.add(incremented_left[:-1] + incremented_left[::-1])

        # 3. Decrement the left part and mirror
        decremented_left = str(int(left) - 1)
        if len(decremented_left) < len(left):
            if len(n) % 2 == 0:
                candidates.add(decremented_left + decremented_left[::-1])
            else:
                candidates.add(decremented_left + decremented_left[::-1][1:])
        else:
            if len(n) % 2 == 0:
                candidates.add(decremented_left + decremented_left[::-1])
            else:
                candidates.add(decremented_left[:-1] + decremented_left[::-1])

        # Edge cases
        candidates.add("9" * (len(n) - 1))
        candidates.add("1" + "0" * (len(n) - 1) + "1")

        candidates.discard(n)

        closest_palindrome = min(candidates, key=lambda x: (abs(int(x) - int(n)), int(x)))

        return closest_palindrome

```

```python

```

## Optimal Solutions

---

### Problem Description

Given a positive integer `n`, find the closest integer (not including itself) which is a palindrome. If there is a tie, return the smaller one.

### Example

```python
Input: n = "123"
Output: "121"

Input: n = "1"
Output: "0"

Input: n = "11"
Output: "9"

Input: n = "1283"
Output: "1331"

```

### Approach

To find the closest palindrome to a given number `n`, consider the following steps:

1. **Generate Possible Palindromes**:
    - Identify potential palindrome candidates by modifying the middle of the number.
    - Consider palindromes by:
        - Keeping the first half of the number as is and mirroring it.
        - Incrementing or decrementing the first half before mirroring.
        - Handling edge cases like `999...999` (which turns into `1000...0001`) and `100...001` (which turns into `99...999`).
2. **Evaluate the Candidates**:
    - Compare the distance between `n` and each candidate.
    - Return the smallest palindrome if multiple candidates have the same distance from `n`.

### Steps

1. **Mirror the First Half**: Create a palindrome by mirroring the first half of `n`.
2. **Handle Edge Cases**: Consider edge cases by generating candidates from numbers like `100...001` and `999...999`.
3. **Compare Distances**: Calculate the difference between `n` and each palindrome candidate, selecting the closest one.

### Python Implementation

Here's a Python solution that implements this approach:

```python
class Solution:
    def nearestPalindromic(self, n: str) -> str:
        length = len(n)
        candidates = set()

        # Edge cases: single-digit and power of 10 cases
        candidates.add(str(10**(length - 1) - 1))  # 999...999
        candidates.add(str(10**length + 1))  # 100...001

        # Generate palindromes by mirroring the first half
        prefix = int(n[:(length + 1) // 2])

        for i in range(-1, 2):
            # Generate a candidate palindrome
            new_prefix = str(prefix + i)
            if length % 2 == 0:
                candidate = new_prefix + new_prefix[::-1]
            else:
                candidate = new_prefix + new_prefix[:-1][::-1]

            candidates.add(candidate)

        # Remove the original number itself if it exists
        candidates.discard(n)

        # Find the closest palindrome
        closest_palindrome = None
        min_diff = float('inf')

        for candidate in candidates:
            diff = abs(int(candidate) - int(n))
            if diff < min_diff or (diff == min_diff and int(candidate) < int(closest_palindrome)):
                min_diff = diff
                closest_palindrome = candidate

        return closest_palindrome

# Example usage
sol = Solution()
print(sol.nearestPalindromic("123"))  # Output: "121"
print(sol.nearestPalindromic("1"))    # Output: "0"
print(sol.nearestPalindromic("11"))   # Output: "9"
print(sol.nearestPalindromic("1283")) # Output: "1331"

```

### Explanation

1. **Edge Cases**:
    - We handle small numbers and powers of 10 explicitly by adding `999...999` and `100...001` to the set of candidates.
2. **Mirroring the Prefix**:
    - By considering the first half of `n`, we generate three possible palindromes:
        - One where the first half is kept as is.
        - One where the first half is incremented by 1.
        - One where the first half is decremented by 1.
3. **Finding the Closest Palindrome**:
    - We compare all the generated palindrome candidates by calculating their absolute difference from `n`.
    - We return the smallest palindrome if there is a tie in the difference.

### Complexity Analysis

- **Time Complexity**: `O(1)` for small fixed-length numbers. The solution is optimal for typical input sizes since the number of candidates is small (at most 5).
- **Space Complexity**: `O(1)` for storing a few candidates and the results.

This solution efficiently identifies the closest palindrome by considering all possible candidates that could be close to the given number `n`. It ensures that even edge cases are handled correctly.

## Notes

---

 

## Related Videos

---

[https://www.youtube.com/watch?v=AJOPHKJJE9A&pp=ygUbZmluZCB0aGUgY2xvc2VzdCBwYWxpbmRyb21l](https://www.youtube.com/watch?v=AJOPHKJJE9A&pp=ygUbZmluZCB0aGUgY2xvc2VzdCBwYWxpbmRyb21l)