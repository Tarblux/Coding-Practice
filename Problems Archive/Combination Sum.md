# Combination Sum

Problem: 39
Official Difficulty: medium
Feels Like : medium
My Understanding: Mostly Understand
Topic: backtracking
Link: https://leetcode.com/problems/combination-sum/description/?envType=problem-list-v2&envId=a2nl34vi
Completed On : October 17, 2024
Last Review: October 17, 2024
Days Since Review: 136
Neetcode: Yes

## Problem

---

Given an array of **distinct** integers `candidates` and a target integer `target`, return *a list of all **unique combinations** of* `candidates` *where the chosen numbers sum to* `target`*.* You may return the combinations in **any order**.

The **same** number may be chosen from `candidates` an **unlimited number of times**. Two combinations are unique if the

frequency

of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to `target` is less than `150` combinations for the given input.

**Example 1:**

```
Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
```

**Example 2:**

```
Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]
```

**Example 3:**

```
Input: candidates = [2], target = 1
Output: []
```

**Constraints:**

- `1 <= candidates.length <= 30`
- `2 <= candidates[i] <= 40`
- All elements of `candidates` are **distinct**.
- `1 <= target <= 40`

## My Solutions

---

```python
**class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:

        combinations = []
        seen = set()

        def backtrack(state,cur_sum,start):

            if cur_sum == target:
                combinations.append(state)
                return
            elif cur_sum > target:
                return

            for i in range(start,len(candidates)):
                backtrack(state + [candidates[i]], cur_sum + candidates[i], i)

        backtrack([],0,0)

        return combinations**
```

```python

```

## Optimal Solutions

---

To solve **LeetCode Problem 39: Combination Sum**, the most efficient algorithms involve exploring all possible combinations of the given candidates that sum up to the target. Below are the optimal methods to achieve this, along with their time and space complexities.

---

### **1. Backtracking (Depth-First Search)**

**Algorithm Overview:**

- **Objective:** Find all unique combinations where the candidate numbers sum to the target.
- **Approach:** Use backtracking to explore all potential combinations by recursively adding candidates to a path if their cumulative sum does not exceed the target.

**Algorithm Steps:**

1. **Sort the Candidates:**
    - Sorting helps to optimize the process by allowing early termination of paths that exceed the target.
        
        ```python
        candidates.sort()
        
        ```
        
2. **Define the Backtracking Function:**
    - The function `backtrack(remaining, start, path, result)` recursively builds combinations.
        - `remaining`: The remaining value to reach the target.
        - `start`: The index to start the loop from, allowing reuse of the same element.
        - `path`: The current combination being built.
        - `result`: The list of valid combinations found.
3. **Base Cases:**
    - **If `remaining == 0`:**
        - A valid combination is found; add a copy of `path` to `result`.
    - **If `remaining < 0`:**
        - The current path exceeds the target; terminate this path.
4. **Recursive Exploration:**
    - Loop through the candidates starting from `start` to allow unlimited usage of the same element.
        - **Include the Candidate:**
            - Add the candidate to `path`.
            - Recursively call `backtrack` with updated `remaining` and `start`.
        - **Backtrack:**
            - Remove the last candidate from `path` to explore other possibilities.

**Code Example:**

```python
def combinationSum(candidates, target):
    def backtrack(remaining, start, path, result):
        if remaining == 0:
            result.append(list(path))
            return
        elif remaining < 0:
            return  # Exceeds target, backtrack
        for i in range(start, len(candidates)):
            # Include the candidate
            path.append(candidates[i])
            # Recurse with updated remaining and same start index (unlimited use)
            backtrack(remaining - candidates[i], i, path, result)
            # Backtrack
            path.pop()

    candidates.sort()
    result = []
    backtrack(target, 0, [], result)
    return result

```

**Time Complexity:** O(2<sup>t/m</sup>)

- **Explanation:**
    - `t` is the target value, and `m` is the minimal value among the candidates.
    - The number of potential combinations is exponential due to the possibility of using each candidate unlimited times.

**Space Complexity:** O(t/m)

- **Explanation:**
    - The maximum depth of the recursion tree is `t/m`, representing the longest possible combination where only the smallest candidate is used.
    - Additional space is used for the `path` and `result` lists.

---

### **2. Backtracking with Memoization (Optimization Attempt)**

**Note:** While memoization is a common optimization technique, in this problem, it is generally not effective due to the need to store all unique combinations rather than just counts or boolean values. However, for completeness, here's how it could be attempted.

**Algorithm Overview:**

- Use a cache to store results for a given `remaining` sum to avoid redundant calculations.

**Algorithm Steps:**

1. **Initialize a Memoization Cache:**
    - Use a dictionary `memo` to map `remaining` sums to their corresponding combinations.
2. **Modify the Backtracking Function:**
    - Before computing combinations for a `remaining` sum, check if it's already in `memo`.
    - If so, return the cached result to avoid recomputation.

**Code Example:**

```python
def combinationSum(candidates, target):
    from collections import defaultdict

    def backtrack(remaining, start):
        if remaining in memo:
            return memo[remaining]
        if remaining == 0:
            return [[]]
        elif remaining < 0:
            return []
        combinations = []
        for i in range(start, len(candidates)):
            num = candidates[i]
            for combo in backtrack(remaining - num, i):
                combinations.append([num] + combo)
        memo[remaining] = combinations
        return combinations

    candidates.sort()
    memo = {}
    return backtrack(target, 0)

```

**Time Complexity:** Potentially worse than simple backtracking due to overhead and storage.

**Space Complexity:** High, due to storing combinations for each `remaining` sum.

**Recommendation:** **Not advised** for this problem, as memoization doesn't offer significant benefits and can increase space complexity unnecessarily.

---

### **3. Iterative Approach Using Dynamic Programming (Less Practical)**

**Algorithm Overview:**

- **Objective:** Build up combinations using dynamic programming.
- **Approach:** Use a list to store combinations for each possible sum up to the target.

**Algorithm Steps:**

1. **Initialize DP Array:**
    - `dp = [ [] for _ in range(target + 1) ]`
    - `dp[0] = [[]]` represents the base case.
2. **Iterate Through Candidates and Sums:**
    - For each candidate, iterate from the candidate value up to the target.
    - For each sum `i`, append the candidate to the combinations in `dp[i - candidate]`.

**Code Example:**

```python
def combinationSum(candidates, target):
    dp = [[] for _ in range(target + 1)]
    dp[0] = [[]]
    for candidate in candidates:
        for i in range(candidate, target + 1):
            for combo in dp[i - candidate]:
                dp[i].append(combo + [candidate])
    return dp[target]

```

**Time Complexity:** O(n * t * k)

- **Explanation:**
    - `n` is the number of candidates.
    - `t` is the target value.
    - `k` is the average number of combinations for each sum.
- **Note:** This approach can be inefficient due to the high number of possible combinations to store and process.

**Space Complexity:** O(t * k)

- **Explanation:**
    - Storing combinations for each sum up to the target.

**Recommendation:** **Not practical** for this problem when you need to generate all combinations due to high time and space complexities.

---

### **4. Backtracking with Candidate Frequency Count**

**Algorithm Overview:**

- **Objective:** Similar to the basic backtracking but keeps track of candidate frequencies.
- **Approach:** Limit the number of times each candidate is used based on the target divided by the candidate value.

**Algorithm Steps:**

1. **Sort Candidates:**
    - As before, sort to optimize and handle duplicates if any.
2. **Define Backtracking Function:**
    - Pass a frequency map or count to track how many times a candidate has been used.
3. **Recursive Exploration:**
    - For each candidate, decide how many times to include it in the current combination.

**Code Example:**

```python
def combinationSum(candidates, target):
    def backtrack(start, path, total):
        if total == target:
            result.append(list(path))
            return
        if total > target:
            return
        for i in range(start, len(candidates)):
            num = candidates[i]
            path.append(num)
            backtrack(i, path, total + num)
            path.pop()

    candidates.sort()
    result = []
    backtrack(0, [], 0)
    return result

```

**Time Complexity:** O(n<sup>t/m</sup>)

- **Explanation:**
    - Similar to the basic backtracking, but potentially more calls due to trying multiple counts of each candidate.

**Space Complexity:** O(t/m)

- **Explanation:**
    - Maximum depth of recursion depends on how many times the smallest candidate can fit into the target.

**Recommendation:** This method doesn't offer significant advantages over the standard backtracking approach and may add unnecessary complexity.

---

### **5. Using Combinations with Replacement from itertools (Python Specific)**

**Algorithm Overview:**

- Use Python's `itertools` module to generate combinations with replacement.

**Algorithm Steps:**

1. **Generate All Possible Lengths:**
    - Since candidates can be used unlimited times, generate combinations of lengths from 1 to `target // min(candidates)`.
2. **Filter Valid Combinations:**
    - For each combination, check if the sum equals the target.

**Code Example:**

```python
import itertools

def combinationSum(candidates, target):
    result = []
    min_length = 1
    max_length = target // min(candidates) + 1
    for r in range(min_length, max_length):
        for combo in itertools.combinations_with_replacement(candidates, r):
            if sum(combo) == target:
                result.append(list(combo))
    return result

```

**Time Complexity:** High and inefficient.

- **Explanation:**
    - Generates all combinations regardless of their sum, leading to a combinatorial explosion.

**Space Complexity:** High.

**Recommendation:** **Not efficient** for large inputs; not recommended compared to backtracking.

---

### **Comparison and Recommendation**

- **Backtracking with Depth-First Search (Method 1):**
    - **Pros:**
        - Efficiently explores only valid combinations.
        - Prunes paths that exceed the target early.
        - Simple and intuitive implementation.
    - **Cons:**
        - Time complexity is still exponential but acceptable due to pruning.
- **Iterative and Alternative Methods:**
    - **Cons:**
        - Generally less efficient due to generating unnecessary combinations.
        - Higher time and space complexities.
        - More complex to implement without significant benefits.

**Recommendation:**

- The **backtracking approach (Method 1)** is the most optimal and widely used solution for this problem. It effectively explores all valid combinations while pruning invalid paths, offering a balance between efficiency and simplicity.

---

**Note:** In problems where all possible combinations need to be generated, exponential time complexity is often unavoidable. The goal is to optimize the search space and avoid unnecessary computations, which the backtracking method achieves effectively.

## Notes

---

 

## Related Videos

---

[https://youtu.be/GBKI9VSKdGg](https://youtu.be/GBKI9VSKdGg)