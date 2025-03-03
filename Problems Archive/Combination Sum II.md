# Combination Sum II

Problem: 40
Official Difficulty: medium
Feels Like : medium
My Understanding: Mostly Understand
Topic: array, backtracking
Link: https://leetcode.com/problems/combination-sum-ii/description/?envType=problem-list-v2&envId=a2nl34vi
Completed On : October 18, 2024
Last Review: October 18, 2024
Days Since Review: 135
Neetcode: Yes

## Problem

---

Given a collection of candidate numbers (`candidates`) and a target number (`target`), find all unique combinations in `candidates` where the candidate numbers sum to `target`.

Each number in `candidates` may only be used **once** in the combination.

**Note:** The solution set must not contain duplicate combinations.

**Example 1:**

```
Input: candidates = [10,1,2,7,6,1,5], target = 8
Output:
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]

```

**Example 2:**

```
Input: candidates = [2,5,2,1,2], target = 5
Output:
[
[1,2,2],
[5]
]

```

**Constraints:**

- `1 <= candidates.length <= 100`
- `1 <= candidates[i] <= 50`
- `1 <= target <= 30`

## My Solutions

---

```python
class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:

        combinations = []
        candidates.sort()

        def backtrack(state,combo_sum,start):

            if combo_sum == target:
                combinations.append(state)
            elif combo_sum > target:
                return

            for i in range(start,len(candidates)):
                if i > start and candidates[i] == candidates[i - 1]:
                    continue
                backtrack(state + [candidates[i]], combo_sum + candidates[i], i + 1)

        backtrack([],0,0)

        return combinations
```

```python

```

## Optimal Solutions

---

To solve **LeetCode Problem 40: Combination Sum II**, which requires finding all unique combinations of numbers that sum up to a target value without reusing elements and avoiding duplicate combinations, several efficient algorithms can be applied. Below are the optimal methods along with their time and space complexities.

---

### **1. Backtracking with Sorting and Skipping Duplicates**

**Algorithm Overview:**

- **Objective:** Find all unique combinations where candidates sum to the target, each number used at most once.
- **Approach:** Use backtracking with depth-first search (DFS), sort the candidates to handle duplicates, and skip over duplicate elements.

**Algorithm Steps:**

1. **Sort the Input List:**
    - Sorting the `candidates` array brings duplicates together, helping to skip them and avoid duplicate combinations.
        
        ```python
        candidates.sort()
        
        ```
        
2. **Define the Backtracking Function:**
    - The function `backtrack(remaining, start, path, result)` recursively builds combinations.
        - `remaining`: Remaining sum to reach the target.
        - `start`: Index to start from, ensuring elements are only used once.
        - `path`: Current combination being built.
        - `result`: List of valid combinations found.
3. **Base Cases:**
    - If `remaining == 0`:
        - A valid combination is found; add a copy of `path` to `result`.
    - If `remaining < 0`:
        - The current path exceeds the target; backtrack.
4. **Recursive Exploration:**
    - Loop through the candidates starting from `start`.
    - **Skip Duplicates:**
        - If `i > start` and `candidates[i] == candidates[i - 1]`, skip the current candidate.
    - **Include the Candidate:**
        - Add `candidates[i]` to `path`.
        - Recursively call `backtrack` with updated `remaining` (`remaining - candidates[i]`) and `i + 1` (move to the next index).
    - **Backtrack:**
        - Remove the last candidate from `path` to explore other possibilities.

**Code Example:**

```python
def combinationSum2(candidates, target):
    def backtrack(remaining, start, path, result):
        if remaining == 0:
            result.append(list(path))
            return
        elif remaining < 0:
            return
        for i in range(start, len(candidates)):
            # Skip duplicates
            if i > start and candidates[i] == candidates[i - 1]:
                continue
            # Include the candidate
            path.append(candidates[i])
            backtrack(remaining - candidates[i], i + 1, path, result)
            # Backtrack
            path.pop()

    candidates.sort()
    result = []
    backtrack(target, 0, [], result)
    return result

```

**Time Complexity:** O(2<sup>n</sup>)

- **Explanation:**
    - The number of combinations is exponential in the worst case.
    - Pruning duplicates reduces recursive calls but doesn't change the exponential nature.

**Space Complexity:** O(n)

- **Explanation:**
    - The maximum depth of the recursion tree is `n`.
    - Additional space is used for the `path` and `result` lists.

---

### **2. Backtracking with Frequency Map (Counter)**

**Algorithm Overview:**

- **Objective:** Use a frequency map to track the count of each unique candidate.
- **Approach:** Build combinations by selecting from unique candidates, considering their counts.

**Algorithm Steps:**

1. **Build a Frequency Map:**
    - Use `collections.Counter` to count occurrences of each candidate.
        
        ```python
        from collections import Counter
        counter = Counter(candidates)
        unique_candidates = sorted(counter)
        
        ```
        
2. **Define the Backtracking Function:**
    - The function `backtrack(index, path, remaining)` recursively builds combinations.
        - `index`: Current index in `unique_candidates`.
        - `path`: Current combination.
        - `remaining`: Remaining sum to reach the target.
3. **Base Cases:**
    - If `remaining == 0`:
        - Add a copy of `path` to `result`.
    - If `remaining < 0` or `index == len(unique_candidates)`:
        - Exceeded target or no more candidates; backtrack.
4. **Recursive Exploration:**
    - For the current candidate, decide how many times to include it (from 0 up to its count), without exceeding the target.
    - For each count:
        - Extend `path` with the candidate repeated `count` times.
        - Recursively call `backtrack` with updated `remaining` and `index + 1`.
        - Backtrack by removing the candidate from `path`.

**Code Example:**

```python
from collections import Counter

def combinationSum2(candidates, target):
    def backtrack(index, path, remaining):
        if remaining == 0:
            result.append(list(path))
            return
        if remaining < 0 or index == len(unique_candidates):
            return
        candidate = unique_candidates[index]
        max_count = min(counter[candidate], remaining // candidate)
        # Skip the current candidate
        backtrack(index + 1, path, remaining)
        # Include the current candidate from 1 up to max_count times
        for count in range(1, max_count + 1):
            path.extend([candidate] * count)
            backtrack(index + 1, path, remaining - candidate * count)
            # Backtrack
            for _ in range(count):
                path.pop()

    counter = Counter(candidates)
    unique_candidates = sorted(counter)
    result = []
    backtrack(0, [], target)
    return result

```

**Time Complexity:** O(2<sup>k</sup> * t / m)

- **Explanation:**
    - `k` is the number of unique candidates.
    - The recursive tree branches exponentially with respect to `k`.
    - Pruning reduces unnecessary branches.

**Space Complexity:** O(k)

- **Explanation:**
    - The recursion stack can go up to depth `k`.

---

### **3. Using Iterative Approach with Sets (Less Efficient)**

**Algorithm Overview:**

- **Objective:** Iteratively build combinations using sets to avoid duplicates.
- **Approach:** Generate all possible combinations and filter out those that sum to the target.

**Algorithm Steps:**

1. **Sort the Candidates:**
    - Sort the array to handle duplicates.
2. **Initialize a Set of Combinations:**
    - Start with an empty combination: `combinations = {()}`.
3. **Iterate Over Candidates:**
    - For each candidate:
        - Create new combinations by adding the candidate to existing combinations.
        - Use a set to avoid duplicates.
4. **Filter Combinations:**
    - After all iterations, filter combinations that sum to the target.

**Code Example:**

```python
def combinationSum2(candidates, target):
    candidates.sort()
    combinations = {()}
    for num in candidates:
        new_combinations = set()
        for comb in combinations:
            new_comb = comb + (num,)
            if sum(new_comb) <= target:
                new_combinations.add(new_comb)
        combinations.update(new_combinations)
    # Filter and remove duplicates
    result = [list(comb) for comb in combinations if sum(comb) == target]
    return result

```

**Time Complexity:** High and inefficient.

- **Explanation:**
    - Generates many unnecessary combinations, leading to poor performance.

**Space Complexity:** High.

- **Explanation:**
    - Storing all combinations uses significant space.

**Recommendation:** Not practical compared to backtracking methods.

---

### **Comparison and Recommendation**

- **Backtracking with Sorting and Skipping Duplicates (Method 1):**
    - **Pros:**
        - Efficiently avoids duplicate combinations.
        - Ensures each candidate is used at most once.
        - Simple and intuitive implementation.
    - **Cons:**
        - Time complexity is exponential but acceptable for problem constraints.
- **Backtracking with Frequency Map (Method 2):**
    - **Pros:**
        - Useful when there are many duplicates.
    - **Cons:**
        - Slightly more complex due to managing counts.
- **Iterative Approach with Sets (Method 3):**
    - **Cons:**
        - Inefficient due to generating excessive combinations.
        - Not recommended.

**Recommendation:**

- The **backtracking approach with sorting and skipping duplicates (Method 1)** is the most optimal and commonly used solution.
- It effectively handles duplicates and ensures each candidate is used only once per combination.

---

**Final Code Solution (Method 1):**

```python
class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        def backtrack(remaining, start, path, result):
            if remaining == 0:
                result.append(list(path))
                return
            elif remaining < 0:
                return
            for i in range(start, len(candidates)):
                # Skip duplicates
                if i > start and candidates[i] == candidates[i - 1]:
                    continue
                # Include the candidate
                path.append(candidates[i])
                backtrack(remaining - candidates[i], i + 1, path, result)
                # Backtrack
                path.pop()

        candidates.sort()
        result = []
        backtrack(target, 0, [], result)
        return result

```

---

**Time Complexity:** O(2<sup>n</sup>)

- Exponential due to the nature of the problem.

**Space Complexity:** O(n)

- Proportional to the depth of the recursion stack.

By using backtracking with careful handling of duplicates, we can efficiently find all unique combinations that sum to the target, ensuring elements are not reused and duplicate combinations are avoided.

## Notes

---

 

## Related Videos

---

[https://youtu.be/FOyRpNUSFeA](https://youtu.be/FOyRpNUSFeA)