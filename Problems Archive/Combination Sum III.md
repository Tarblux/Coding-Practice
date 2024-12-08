Problem: 216
Official Difficulty: medium
Link: https://leetcode.com/problems/combination-sum-iii/description/
Completed On : 2024-12-03
Feels Like : easy
Topic: array, backtracking
My Understanding: Fully Understand
Last Review: 2024-12-03
Days Since Review: 5
Name: Combination Sum III

# Combination Sum III
### Problem
___
Find all valid combinations of `k` numbers that sum up to `n` such that the following conditions are true:
- Only numbers `1` through `9` are used.
- Each number is used **at most once**.
Return *a list of all possible valid combinations*. The list must not contain the same combination twice, and the combinations may be returned in any order.
**Example 1:**
```plain text
Input: k = 3, n = 7
Output: [[1,2,4]]
Explanation:
1 + 2 + 4 = 7
There are no other valid combinations.
```
**Example 2:**
```plain text
Input: k = 3, n = 9
Output: [[1,2,6],[1,3,5],[2,3,4]]
Explanation:
1 + 2 + 6 = 9
1 + 3 + 5 = 9
2 + 3 + 4 = 9
There are no other valid combinations.

```
**Example 3:**
```plain text
Input: k = 4, n = 1
Output: []
Explanation: There are no valid combinations.
Using 4 different numbers in the range [1,9], the smallest sum we can get is 1+2+3+4 = 10 and since 10 > 1, there are no valid combination.

```
**Constraints:**
- `2 <= k <= 9`
- `1 <= n <= 60`
### My Solutions
___
```python
class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        
        combinations = []

        def backtrack(state,start,cur_sum):

            if cur_sum == n and len(state) == k:
                combinations.append(state.copy())
                return 
            elif len(state) == k:
                return

            for i in range(start,10):
                state.append(i)
                backtrack(state,i + 1, cur_sum + i)
                state.pop()

        backtrack([],1,0)

        return combinations
```

Time Complexity :
```python

```

Time Complexity : 
### Optimal Solutions
___
To solve **Combination Sum III**, we aim to find all unique combinations of `k` distinct numbers from `1` to `9` that sum up to `n`. Given the constraints, the most efficient and straightforward approach is to use **backtracking** with **pruning** to explore potential combinations.
#### **Key Concepts:**
1. **Backtracking:**
	- A recursive approach to explore all possible combinations.
	- Builds combinations incrementally and abandons a path (backtracks) as soon as it determines that the path cannot possibly lead to a valid solution.
2. **Pruning:**
	- An optimization technique to reduce the search space by eliminating paths that cannot yield valid combinations.
	- In this problem, we can prune the search when:
		- The current sum exceeds `n`.
		- The number of elements in the current combination exceeds `k`.
		- The remaining numbers are insufficient to reach `k` elements.
#### **Algorithm Steps:**
3. **Initialize Variables:**
	- Create an empty list `result` to store all valid combinations.
	- Define a helper function `backtrack(start, path, current_sum)` where:
		- `start`: The starting number for the current recursion to avoid duplicates.
		- `path`: The current combination being built.
		- `current_sum`: The sum of numbers in the current `path`.
4. **Backtracking Function (**`**backtrack**`**):**
	- **Base Cases:**
		- If the length of `path` is `k` and `current_sum` is equal to `n`, append a copy of `path` to `result`.
		- If the length of `path` exceeds `k` or `current_sum` exceeds `n`, terminate the current path (prune).
	- **Recursive Exploration:**
		- Iterate through numbers from `start` to `9`:
			- Append the current number to `path`.
			- Recursively call `backtrack` with updated `start`, `path`, and `current_sum`.
			- Remove the last number from `path` to backtrack.
5. **Invoke Backtracking:**
	- Start the backtracking process with `start = 1`, an empty `path`, and `current_sum = 0`.
6. **Return the Result:**
	- After exploring all paths, return the `result` list containing all valid combinations.
___
### Code Implementation
#### **Backtracking Approach (Optimal Solution)**
```python
class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        result = []

        def backtrack(start, path, current_sum):
            # Base Case 1: If the combination is complete
            if len(path) == k:
                if current_sum == n:
                    result.append(path.copy())
                return  # Backtrack

            # Iterate through possible candidates
            for num in range(start, 10):  # Numbers 1 to 9
                # Prune the search space
                if current_sum + num > n:
                    break  # Further numbers will be larger, no need to continue
                # Append the number to the current path
                path.append(num)
                # Recurse with updated parameters
                backtrack(num + 1, path, current_sum + num)
                # Backtrack: remove the last number added
                path.pop()

        # Start backtracking with the first number
        backtrack(1, [], 0)
        return result

```
___
### Detailed Explanation
#### **Step-by-Step Process:**
7. **Initialization:**
	- `result = []`: To store all valid combinations.
	- The `backtrack` function is defined to explore combinations recursively.
8. **Backtracking Function (**`**backtrack**`**):**
	- **Parameters:**
		- `start`: The next number to consider (to ensure numbers are used only once and combinations are unique).
		- `path`: The current combination being built.
		- `current_sum`: The sum of the numbers in `path`.
	- **Base Cases:**
		- **Combination Complete:**
			- If `len(path) == k` and `current_sum == n`, a valid combination is found.
			- Append a copy of `path` to `result`.
			- Return to explore other possibilities.
		- **Invalid Combination:**
			- If `len(path) > k` or `current_sum > n`, terminate this path as it cannot lead to a valid combination.
	- **Recursive Exploration:**
		- Iterate through numbers from `start` to `9`:
			- **Pruning:**
				- If adding the current number `num` to `current_sum` exceeds `n`, break the loop. Since numbers are in ascending order, further numbers will only increase the sum.
			- **Choose the Current Number:**
				- Append `num` to `path`.
				- Recursively call `backtrack` with updated parameters:
					- `start = num + 1`: To ensure the next number is greater than the current `num`.
					- `path`: Updated with `num`.
					- `current_sum + num`: Updated sum.
			- **Backtrack:**
				- Remove the last number from `path` to explore other combinations.
9. **Starting the Backtracking Process:**
	- Call `backtrack(1, [], 0)` to begin with the first number (`1`), an empty path, and a sum of `0`.
10. **Completion:**
	- After all recursive calls complete, `result` contains all valid combinations.
	- Return `result`.
#### **Why This Works:**
- **Uniqueness:** By always choosing the next number greater than the current (`num + 1`), we ensure that combinations are unique and numbers are not reused.
- **Pruning:** Early termination of paths that exceed the target sum (`n`) or the required number of elements (`k`) optimizes the algorithm, preventing unnecessary computations.
- **Efficiency:** The approach explores all potential combinations without redundancy, ensuring optimal performance within the given constraints.
___
### Time and Space Complexity Analysis
#### **Time Complexity:** O(2^9) = O(512) → Considered **Constant Time** for this problem
- **Explanation:**
	- The problem involves choosing up to `k` numbers from `9` possible candidates (`1` to `9`).
	- The number of possible combinations is limited (e.g., C(9,3) = 84, C(9,4) = 126).
	- Therefore, the algorithm runs efficiently within the problem's constraints.
#### **Space Complexity:** O(k)
- **Explanation:**
	- The space used by the recursion stack is proportional to `k` (the depth of the recursion).
	- The `result` list stores all valid combinations, but since the number of combinations is limited, this does not significantly affect space complexity.
	- Overall, the space complexity is linear with respect to `k`.
___
### Example Walkthrough
#### **Example 1:**
- **Input:**
```plain text
k = 3, n = 7

```
- **Process:**
	- **Possible Combinations:**
		- `[1, 2, 4]` → 1 + 2 + 4 = 7
		- `[1, 3, 3]` → Invalid (duplicate number)
		- `[2, 2, 3]` → Invalid (duplicate number)
	- **Valid Combination:** `[1, 2, 4]`
- **Output:**
```plain text
[[1, 2, 4]]

```
#### **Example 2:**
- **Input:**
```plain text
k = 3, n = 9

```
- **Process:**
	- **Possible Combinations:**
		- `[1, 2, 6]` → 1 + 2 + 6 = 9
		- `[1, 3, 5]` → 1 + 3 + 5 = 9
		- `[2, 3, 4]` → 2 + 3 + 4 = 9
	- **Valid Combinations:** `[1, 2, 6]`, `[1, 3, 5]`, `[2, 3, 4]`
- **Output:**
```plain text
[[1, 2, 6], [1, 3, 5], [2, 3, 4]]

```
#### **Example 3:**
- **Input:**
```plain text
k = 4, n = 1

```
- **Process:**
	- **Possible Combinations:**
		- No combination of `4` distinct numbers from `1` to `9` can sum up to `1`.
	- **Valid Combinations:** None
- **Output:**
```plain text
[]

```
___
### Edge Cases to Consider
11. **Minimum Values:**
	- `k = 2`, `n = 3`: The smallest valid combination is `[1, 2]`.
12. **No Valid Combination:**
	- `k = 4`, `n = 1`: Impossible to form a combination.
13. **Maximum Values:**
	- `k = 9`, `n = 45`: The only valid combination is `[1, 2, 3, 4, 5, 6, 7, 8, 9]`.
14. **Multiple Combinations:**
	- Ensure that all valid unique combinations are captured without duplicates.
15. **Single Combination:**
	- When only one combination satisfies the conditions, e.g., `k = 1`, `n = 5` → `[5]`.
___
### Test Cases
```python
# Test Case 1: Single Valid Combination
k = 3
n = 7
assert Solution().combinationSum3(k, n) == [[1, 2, 4]]

# Test Case 2: Multiple Valid Combinations
k = 3
n = 9
assert Solution().combinationSum3(k, n) == [[1, 2, 6], [1, 3, 5], [2, 3, 4]]

# Test Case 3: No Valid Combination
k = 4
n = 1
assert Solution().combinationSum3(k, n) == []

# Test Case 4: Maximum Combination
k = 9
n = 45
assert Solution().combinationSum3(k, n) == [[1,2,3,4,5,6,7,8,9]]

# Test Case 5: Single Number Combination
k = 1
n = 5
assert Solution().combinationSum3(k, n) == [[5]]

# Test Case 6: All Possible Combinations
k = 2
n = 5
assert Solution().combinationSum3(k, n) == [[1,4], [2,3]]

# Test Case 7: Larger n with No Combination
k = 5
n = 50
assert Solution().combinationSum3(k, n) == []

# Test Case 8: Edge Case with k equals 2 and n equals 3
k = 2
n = 3
assert Solution().combinationSum3(k, n) == [[1,2]]

# Test Case 9: Edge Case with k equals 2 and n equals 18 (maximum sum with k=2)
k = 2
n = 17
assert Solution().combinationSum3(k, n) == [[8,9]]

```
___
### Conclusion
The **backtracking approach** is the most efficient and intuitive method to solve the **Combination Sum III** problem. By systematically exploring potential combinations and utilizing pruning to eliminate invalid paths, we can generate all unique combinations of `k` numbers from `1` to `9` that sum up to `n` with optimal performance.
#### **Key Takeaways:**
- **Backtracking:** A powerful technique for exploring all possible combinations or permutations, especially when constraints are present.
- **Pruning:** Essential for optimizing backtracking by eliminating paths that cannot lead to valid solutions, thereby reducing computational overhead.
- **Constraints Awareness:** Understanding the problem's constraints (e.g., numbers from `1` to `9`, `k <= 9`) allows for more targeted and efficient algorithm design.
This solution effectively balances simplicity and efficiency, making it suitable for both small and large inputs within the given problem constraints.
### Notes
___
 
### Related Videos 
___
[qnLeadJaM_Q](https://youtu.be/qnLeadJaM_Q?si=N9OuB8At34Vww7cT)