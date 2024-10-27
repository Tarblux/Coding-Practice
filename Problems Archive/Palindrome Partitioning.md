Problem: 131
Official Difficulty: medium
Link: https://leetcode.com/problems/palindrome-partitioning/description/
Completed On : 2024-10-19
Feels Like : medium
Topic: backtracking, string, dynamic programming
My Understanding: Needs Review
Last Review: 2024-10-19
Days Since Review: 8
Name: Palindrome Partitioning 

# Palindrome Partitioning 
### Problem
___
Given a string `s`, partition `s` such that every
substring
of the partition is a
**palindrome**
. Return
*all possible palindrome partitioning of *`s`

**Example 1:**
```plain text
Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
```
**Example 2:**
```plain text
Input: s = "a"
Output: [["a"]]
```
**Constraints:**
- `1 <= s.length <= 16`
- `s` contains only lowercase English letters
### My Solutions
___
```python
class Solution:
    def partition(self, s: str) -> List[List[str]]:

        palindromes = []

        def backtrack(path, start):
            if start == len(s):
                palindromes.append(path)
                return
            for end in range(start, len(s)):
                substring = s[start:end + 1]
                if substring == substring[::-1]:
                    backtrack(path + [substring], end + 1)

        backtrack([],0)

        return palindromes
```

Time Complexity :
```python

```

Time Complexity : 
### Optimal Solutions
___
To solve **LeetCode Problem 131: Palindrome Partitioning**, the most efficient algorithms involve backtracking combined with optimized palindrome checking. Below are the optimal methods along with their time and space complexities.
___
#### **1. Backtracking with Precomputed Palindromic Substrings**
**Algorithm Overview:**
- **Objective:** Find all possible palindrome partitionings of the string `s`.
- **Approach:** Use backtracking to explore all possible partitions, and precompute palindromic substrings to optimize palindrome checks.
**Algorithm Steps:**
1. **Precompute Palindromic Substrings:**
	- Use dynamic programming to precompute whether `s[i:j+1]` is a palindrome for all `0 ≤ i ≤ j < n`.
	- Create a 2D boolean array `is_palindrome` of size `n × n`.
```python
n = len(s)
is_palindrome = [[False] * n for _ in range(n)]
for end in range(n):
    for start in range(end + 1):
        if s[start] == s[end] and (end - start <= 2 or is_palindrome[start + 1][end - 1]):
            is_palindrome[start][end] = True

```
2. **Define the Backtracking Function:**
	- The function `backtrack(start, path)` recursively builds partitions starting from index `start` with the current partition `path`.
3. **Recursive Exploration:**
	- For each possible end index `end` from `start` to `n - 1`:
		- If `is_palindrome[start][end]` is `True`:
			- Append `s[start:end+1]` to `path`.
			- Recursively call `backtrack(end + 1, path)`.
			- Backtrack by removing the last substring from `path`.
**Code Example:**
```python
class Solution:
    def partition(self, s: str) -> List[List[str]]:
        def backtrack(start, path):
            if start == n:
                result.append(list(path))
                return
            for end in range(start, n):
                if is_palindrome[start][end]:
                    path.append(s[start:end + 1])
                    backtrack(end + 1, path)
                    path.pop()

        n = len(s)
        # Precompute palindrome substrings
        is_palindrome = [[False] * n for _ in range(n)]
        for end in range(n):
            for start in range(end + 1):
                if s[start] == s[end] and (end - start <= 2 or is_palindrome[start + 1][end - 1]):
                    is_palindrome[start][end] = True

        result = []
        backtrack(0, [])
        return result

```
**Time Complexity:** O(n × 2<sup>n</sup>)
- **Explanation:**
	- There are up to 2<sup>n</sup> possible partitions.
	- Each partition requires O(n) time to build and validate.
**Space Complexity:** O(n<sup>2</sup>)
- **Explanation:**
	- The `is_palindrome` array uses O(n<sup>2</sup>) space.
	- The recursion stack and the result list use additional space proportional to the number of partitions.
___
#### **2. Backtracking with On-the-fly Palindrome Checking**
**Algorithm Overview:**
- **Approach:** Use backtracking and check for palindromes during recursion without precomputing.
**Algorithm Steps:**
4. **Define the Backtracking Function:**
	- The function `backtrack(start, path)` recursively builds partitions.
5. **Recursive Exploration:**
	- For each possible end index `end` from `start` to `n - 1`:
		- If `s[start:end+1]` is a palindrome (checked on the fly):
			- Append `s[start:end+1]` to `path`.
			- Recursively call `backtrack(end + 1, path)`.
			- Backtrack by removing the last substring from `path`.
6. **Palindrome Checking Function:**
	- Implement a helper function `is_palindrome(substring)` that checks if a substring is a palindrome.
**Code Example:**
```python
class Solution:
    def partition(self, s: str) -> List[List[str]]:
        def is_palindrome(sub):
            return sub == sub[::-1]

        def backtrack(start, path):
            if start == n:
                result.append(list(path))
                return
            for end in range(start, n):
                substring = s[start:end + 1]
                if is_palindrome(substring):
                    path.append(substring)
                    backtrack(end + 1, path)
                    path.pop()

        n = len(s)
        result = []
        backtrack(0, [])
        return result

```
**Time Complexity:** O(n<sup>2</sup> × 2<sup>n</sup>)
- **Explanation:**
	- Palindrome checking takes O(n) time for each substring.
	- There are O(2<sup>n</sup>) possible partitions.
**Space Complexity:** O(n × 2<sup>n</sup>)
- **Explanation:**
	- The recursion stack and result list.
___
#### **3. Backtracking with Memoization**
**Algorithm Overview:**
- **Approach:** Use memoization to store and reuse the results of subproblems, avoiding redundant computations.
**Algorithm Steps:**
7. **Define the Backtracking Function with Memoization:**
	- The function `backtrack(start)` returns all palindrome partitionings starting from index `start`.
	- Use a dictionary `memo` to store results.
8. **Recursive Exploration:**
	- If `start` is in `memo`, return `memo[start]`.
	- For each possible end index `end` from `start` to `n - 1`:
		- If `s[start:end+1]` is a palindrome:
			- For each partition in `backtrack(end + 1)`:
				- Prepend `s[start:end+1]` to the partition and add to the result.
	- Store the result in `memo[start]`.
**Code Example:**
```python
class Solution:
    def partition(self, s: str) -> List[List[str]]:
        memo = {}
        n = len(s)

        def is_palindrome(sub):
            return sub == sub[::-1]

        def backtrack(start):
            if start == n:
                return [[]]
            if start in memo:
                return memo[start]
            result = []
            for end in range(start, n):
                substring = s[start:end + 1]
                if is_palindrome(substring):
                    for sub_partition in backtrack(end + 1):
                        result.append([substring] + sub_partition)
            memo[start] = result
            return result

        return backtrack(0)

```
**Time Complexity:** O(n × 2<sup>n</sup>)
- **Explanation:**
	- Similar to previous methods but may save time by avoiding redundant computations.
**Space Complexity:** O(n × 2<sup>n</sup>)
- **Explanation:**
	- The memoization dictionary stores results for each starting index.
___
#### **4. Dynamic Programming Approach**
**Algorithm Overview:**
- **Approach:** Build up all possible partitions using dynamic programming.
**Algorithm Steps:**
9. **Initialize DP Array:**
	- `dp[i]` stores all possible palindrome partitionings of `s[i:]`.
	- Set `dp[n] = [[]]` as the base case.
10. **Iterate Backwards:**
	- For `i` from `n - 1` down to `0`:
		- For each `end` from `i` to `n - 1`:
			- If `s[i:end+1]` is a palindrome:
				- For each partition in `dp[end + 1]`:
					- Prepend `s[i:end+1]` to the partition and add to `dp[i]`.
11. **Palindrome Checking:**
	- Use the precomputed `is_palindrome` array as in Method 1.
**Code Example:**
```python
class Solution:
    def partition(self, s: str) -> List[List[str]]:
        n = len(s)
        # Precompute palindrome substrings
        is_palindrome = [[False] * n for _ in range(n)]
        for end in range(n):
            for start in range(end + 1):
                if s[start] == s[end] and (end - start <= 2 or is_palindrome[start + 1][end - 1]):
                    is_palindrome[start][end] = True

        dp = [[] for _ in range(n + 1)]
        dp[n] = [[]]

        for i in range(n - 1, -1, -1):
            for end in range(i, n):
                if is_palindrome[i][end]:
                    substring = s[i:end + 1]
                    for partition in dp[end + 1]:
                        dp[i].append([substring] + partition)

        return dp[0]

```
**Time Complexity:** O(n × 2<sup>n</sup>)
**Space Complexity:** O(n × 2<sup>n</sup>)
___
#### **Comparison and Recommendation**
- **Method 1 (Backtracking with Precomputed Palindromes):**
	- **Pros:**
		- Efficient palindrome checks.
		- Optimal time and space for the problem constraints.
	- **Cons:**
		- Requires additional space for `is_palindrome`.
- **Method 2 (Backtracking with On-the-fly Checking):**
	- **Pros:**
		- Simpler code.
	- **Cons:**
		- Less efficient due to repeated palindrome checks.
- **Method 3 (Backtracking with Memoization):**
	- **Pros:**
		- Avoids redundant computations.
	- **Cons:**
		- Additional overhead of memoization.
- **Method 4 (Dynamic Programming):**
	- **Pros:**
		- Alternative approach.
	- **Cons:**
		- Similar complexity; code may be less intuitive.
**Recommendation:**
- The **backtracking approach with precomputed palindromic substrings (Method 1)** is the most efficient and commonly used solution. It balances performance and code clarity, making it suitable for this problem.
___
**Final Code Solution (Method 1):**
```python
class Solution:
    def partition(self, s: str) -> List[List[str]]:
        def backtrack(start, path):
            if start == n:
                result.append(list(path))
                return
            for end in range(start, n):
                if is_palindrome[start][end]:
                    path.append(s[start:end + 1])
                    backtrack(end + 1, path)
                    path.pop()

        n = len(s)
        # Precompute palindromic substrings
        is_palindrome = [[False] * n for _ in range(n)]
        for end in range(n):
            for start in range(end + 1):
                if s[start] == s[end] and (end - start <= 2 or is_palindrome[start + 1][end - 1]):
                    is_palindrome[start][end] = True

        result = []
        backtrack(0, [])
        return result

```
**Time Complexity:** O(n × 2<sup>n</sup>)
**Space Complexity:** O(n<sup>2</sup>)
- Due to the `is_palindrome` array and the recursion stack.
___
This solution efficiently finds all palindrome partitionings by precomputing palindromic substrings and using backtracking to explore all valid partitions.
### Notes
___
 
### Related Videos 
___
[3jvWodd7ht0](https://youtu.be/3jvWodd7ht0)