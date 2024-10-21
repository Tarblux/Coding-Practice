Problem: 90
Official Difficulty: medium
Link: https://leetcode.com/problems/subsets-ii/description/?envType=problem-list-v2&envId=a2nl34vi
Completed On : 2024-10-17
Feels Like : medium
Topic: array, backtracking, Bit Manipulation
My Understanding: Mostly Understand
Last Review: 2024-10-17
Days Since Review: 3
Name: Subset II

# Subset II
### Problem
___
Given an integer array `nums` that may contain duplicates, return *all possible*
*subsets*
*(the power set)*
.
The solution set **must not** contain duplicate subsets. Return the solution in **any order**.
**Example 1:**
```plain text
Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
```
**Example 2:**
```plain text
Input: nums = [0]
Output: [[],[0]]
```
**Constraints:**
- `1 <= nums.length <= 10`
- `10 <= nums[i] <= 10`
### My Solutions
___
```python
class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:

        nums.sort()
        subsets = set()

        def backtrack(state, idx):

            subsets.add(tuple(state))

            for i in range(idx, len(nums)):
                backtrack(state + [nums[i]], i + 1)

        backtrack([], 0)

        return [list(subset) for subset in subsets]
```

Time Complexity :
```python

```

Time Complexity : 
### Optimal Solutions
___
To solve **LeetCode Problem 90: Subsets II**, which requires generating all possible subsets of a list of integers that may contain duplicates (ensuring no duplicate subsets are included), several efficient algorithms can be employed. Below are the optimal methods with their time and space complexities.
___
#### **1. Backtracking with Sorting to Handle Duplicates**
**Algorithm Steps:**
1. **Sort the Input List:**
	- Sorting `nums` brings duplicates together, making it easier to skip them during recursion.
2. **Define a Backtracking Function:**
	- The function `backtrack(start, path)` builds subsets starting from index `start` with the current subset `path`.
3. **Avoid Duplicates:**
	- Before recursing, check if the current element is the same as the previous one.
	- If it is a duplicate and not at the starting index, skip it to avoid duplicate subsets.
4. **Recursive Exploration:**
	- Include the current element and recurse.
	- Backtrack by removing the last element and move to the next index.
**Code Example:**
```python
def subsetsWithDup(nums):
    nums.sort()  # Sort to handle duplicates
    result = []

    def backtrack(start, path):
        result.append(path[:])
        for i in range(start, len(nums)):
            # Skip duplicates
            if i > start and nums[i] == nums[i - 1]:
                continue
            # Include nums[i]
            path.append(nums[i])
            backtrack(i + 1, path)
            # Backtrack
            path.pop()

    backtrack(0, [])
    return result

```
**Time Complexity:** O(2<sup>n</sup>)
- The total number of subsets is O(2<sup>n</sup>).
- Pruning duplicates doesn't change the exponential nature.
**Space Complexity:** O(n)
- The recursion stack can go up to depth `n`.
___
#### **2. Iterative Approach with Start and End Indices**
**Algorithm Steps:**
5. **Sort the Input List:**
	- Sorting helps in identifying duplicates.
6. **Initialize Result List:**
	- Start with an empty subset: `result = [[]]`.
7. **Iterate Over the Numbers:**
	- Use variables `start` and `end` to track the range of subsets to which the current number should be added.
	- If the current number is a duplicate, only add it to the subsets formed in the previous step.
**Code Example:**
```python
def subsetsWithDup(nums):
    nums.sort()
    result = [[]]
    start = 0
    for i in range(len(nums)):
        # If current is same as previous, start from end of previous additions
        if i > 0 and nums[i] == nums[i - 1]:
            l = len(result)
            new_subsets = [result[j] + [nums[i]] for j in range(prev_len, l)]
        else:
            new_subsets = [subset + [nums[i]] for subset in result]
        prev_len = len(result)
        result.extend(new_subsets)
    return result

```
**Time Complexity:** O(2<sup>n</sup>)
- Each element can potentially double the number of subsets.
**Space Complexity:** O(2<sup>n</sup> \* n)
- Storing all subsets, each can have up to `n` elements.
___
#### **3. Using Counter to Handle Duplicates**
**Algorithm Steps:**
8. **Count Occurrences of Each Number:**
	- Use `collections.Counter` to get counts of unique numbers.
9. **Iteratively Build Subsets:**
	- For each unique number, decide how many times (from 0 to its count) to include it in subsets.
10. **Combine with Existing Subsets:**
	- Multiply existing subsets by the new options created for each number.
**Code Example:**
```python
from collections import Counter

def subsetsWithDup(nums):
    counts = Counter(nums)
    result = [[]]
    for num in counts:
        temp = []
        for subset in result:
            for freq in range(1, counts[num] + 1):
                temp.append(subset + [num] * freq)
        result.extend(temp)
    return result

```
**Time Complexity:** O(∏ (counts[num] + 1))
- The total subsets are the product of (count + 1) for each unique number.
**Space Complexity:** O(total subsets)
- Storing all subsets generated.
___
#### **4. Bit Manipulation with Hash Set to Avoid Duplicates**
**Algorithm Steps:**
11. **Sort the Input List:**
	- Sorting helps in consistent subset generation.
12. **Generate All Bitmasks:**
	- For a list of size `n`, generate all `2^n` bitmasks.
13. **Build Subsets Based on Bitmasks:**
	- Use the bits in each bitmask to decide whether to include each element.
14. **Use a Set to Avoid Duplicates:**
	- Convert subsets to tuples and add to a set to eliminate duplicates.
**Code Example:**
```python
def subsetsWithDup(nums):
    nums.sort()
    n = len(nums)
    seen = set()
    result = []
    for bitmask in range(1 << n):
        subset = []
        for j in range(n):
            if bitmask & (1 << j):
                subset.append(nums[j])
        t_subset = tuple(subset)
        if t_subset not in seen:
            seen.add(t_subset)
            result.append(subset)
    return result

```
**Time Complexity:** O(n * 2<sup>n</sup>)
- Generating all subsets and checking against the set.
**Space Complexity:** O(n * 2<sup>n</sup>)
- Storing all subsets and the set for duplicates.
___
#### **5. Backtracking with Index Skipping**
**Algorithm Steps:**
15. **Sort the Input List:**
	- Sorting brings duplicates together.
16. **Define Backtracking Function with Index Skipping:**
	- If a duplicate element is at the same recursive depth, skip it.
17. **Recursive Exploration:**
	- Include the current element and move forward.
	- Exclude the current element and move forward, skipping duplicates.
**Code Example:**
```python
def subsetsWithDup(nums):
    nums.sort()
    result = []
    n = len(nums)

    def backtrack(index, path):
        result.append(path)
        for i in range(index, n):
            if i > index and nums[i] == nums[i - 1]:
                continue
            backtrack(i + 1, path + [nums[i]])

    backtrack(0, [])
    return result

```
**Time Complexity:** O(2<sup>n</sup>)
**Space Complexity:** O(n)
- Recursion stack depth.
___
#### **6. Using Dynamic Programming**
**Algorithm Steps:**
18. **Sort the Input List:**
	- Ensures duplicates are adjacent.
19. **Initialize DP Array:**
	- Start with subsets containing only the empty set.
20. **Iterate and Build Subsets:**
	- For each number, create new subsets by adding it to existing subsets.
	- If the number is a duplicate, only add it to subsets generated in the previous step.
**Code Example:**
```python
def subsetsWithDup(nums):
    nums.sort()
    result = [[]]
    last_size = 0
    for i in range(len(nums)):
        size = len(result)
        start = last_size if i > 0 and nums[i] == nums[i - 1] else 0
        last_size = size
        for j in range(start, size):
            result.append(result[j] + [nums[i]])
    return result

```
**Time Complexity:** O(2<sup>n</sup>)
**Space Complexity:** O(2<sup>n</sup>)
___
#### **Comparison and Recommendations**
- **Backtracking with Sorting (Method 1)** is preferred for its balance of simplicity and efficiency. It avoids duplicates during recursion without extra space for duplicate tracking structures.
- **Iterative Approach with Start and End Indices (Method 2 and 6)** effectively handles duplicates by controlling the subset range for additions, offering a clean and efficient solution.
- **Using Counter (Method 3)** can be advantageous when there are many duplicates, reducing redundant computations.
- **Bit Manipulation with Hash Set (Method 4)** is less efficient due to the overhead of managing the set and is generally not preferred.
___
**Recommendation:** The **backtracking approach with sorting and skipping duplicates (Method 1)** is typically the most optimal and widely used solution for this problem due to its efficiency and clarity.
### Notes
___
 
### Related Videos 
___
[Vn2v6ajA7U0](https://youtu.be/Vn2v6ajA7U0)
