Problem: 204
Official Difficulty: medium
Link: https://leetcode.com/problems/count-primes/description/
Completed On : 2024-12-10
Feels Like : medium
Topic: array, Math, enumeration, number theory
My Understanding: I Have No Idea
Last Review: 2024-12-10
Days Since Review: 5
Name: Count Primes

# Count Primes
### Problem
___
Given an integer `n`, return *the number of prime numbers that are strictly less than* `n`.
**Example 1:**
```plain text
Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
```
**Example 2:**
```plain text
Input: n = 0
Output: 0
```
**Example 3:**
```plain text
Input: n = 1
Output: 0
```
**Constraints:**
- `0 <= n <= 5 * 106`
### My Solutions
___
```python

```

Time Complexity :
```python
class Solution:
    def countPrimes(self, n: int) -> int:
        if n < 2:
            return 0

        is_prime = [True] * n  # Initialize all numbers as prime
        is_prime[0] = is_prime[1] = False  # 0 and 1 are not prime

        # Use the Sieve of Eratosthenes algorithm
        for i in range(2, int(n**0.5) + 1):
            if is_prime[i]:
                for j in range(i*i, n, i):
                    is_prime[j] = False

        return sum(is_prime)

            
        
```

Time Complexity : 
### Optimal Solutions
___

### Notes
___
 
### Related Videos 
___
[]()