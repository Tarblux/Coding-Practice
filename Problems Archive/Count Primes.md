# Count Primes

Problem: 204
Official Difficulty: easy
Feels Like : medium
Topic: Math, Sieve of Eratosthenes
Link: https://leetcode.com/problems/count-primes/
Completed On : December 7, 2023
My Understanding: I Have No Idea
Last Review: December 7, 2023
Days Since Review: 65

## Problem

---

Given an integer `n`, return *the number of prime numbers that are strictly less than* `n`.

**Example 1:**

```
Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.

```

**Example 2:**

```
Input: n = 0
Output: 0

```

**Example 3:**

```
Input: n = 1
Output: 0

```

**Constraints:**

- `0 <= n <= 5 * 106`

## My Solutions

---

```python
class Solution:
    def countPrimes(self, n: int) -> int:
        
#         arr = []
        
#         for i in range (0,n) : 
            
#             arr.append(i)
            
#         for i in arr[:] : 
            
#             if i % 2 == 0 and i != 2 : 
                
#                 arr.remove(i)
                        
        if n < 2 : 
            
            return 0
        
        count = 0
        
        
        def primetime (num) : 
            
            if num < 2 : 
                
                return False
            
            for i in range (2 , int(num**0.5) + 1) : 
                
                if num % i == 0 : 
                    
                    return False 
                  
            return True
                
        for i in range (2,n): 
            
            if primetime(i): 
                
                count+=1
                
        return count
```

```python

```

## Optimal Solutions

---

The "Count Primes" problem involves counting the number of prime numbers less than a non-negative number `n`. The most efficient way to solve this problem is by using the Sieve of Eratosthenes algorithm, an ancient algorithm used to find all prime numbers up to any given limit.

### Sieve of Eratosthenes Algorithm

The main idea of the algorithm is to iterate through each number starting from 2 (the first prime number) and eliminate its multiples, as they cannot be primes. We repeat this process up to the square root of `n`, since any non-prime number less than `n` must have a factor less than the square root of `n`.

### Python Implementation

Here's a Python implementation of the algorithm:

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

### Explanation

- We start by initializing a boolean array `is_prime` of length `n` with all `True` values, except for indices 0 and 1 (which are not prime).
- We then iterate from 2 up to the square root of `n`. For each number `i` in this range, if `i` is marked as prime (`is_prime[i]` is `True`), we mark all multiples of `i` from `i*i` up to `n` as non-prime (`False`), since they have `i` as a factor.
- Finally, we return the count of prime numbers, which is the sum of `True` values in the `is_prime` array.

### Complexity Analysis

- **Time Complexity**: O(n log log n). The inner loop runs approximately `n/i` times for each `i`, and the sum of this series approximates to `n log log n`.
- **Space Complexity**: O(n) for storing the `is_prime` array.

## Notes

---

 [https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes](https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes)

## Related Videos

---

[https://www.youtube.com/watch?v=5LMkddl2NCk](https://www.youtube.com/watch?v=5LMkddl2NCk)