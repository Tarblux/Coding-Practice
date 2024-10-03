# Subsets

Problem: 78
Official Difficulty: medium
Feels Like : easy
My Understanding: Mostly Understand
Topic: Bit Manipulation, array, backtracking
Link: https://leetcode.com/problems/subsets/description/
Completed On : September 26, 2024
Last Review: September 26, 2024
Days Since Review: 7

## Problem

---

Given an integer array `nums` of **unique** elements, return *all possible*

*subsets.(the power set)*

The solution set **must not** contain duplicate subsets. Return the solution in **any order**.

**Example 1:**

```
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
```

**Example 2:**

```
Input: nums = [0]
Output: [[],[0]]
```

**Constraints:**

- `1 <= nums.length <= 10`
- `10 <= nums[i] <= 10`
- All the numbers of `nums` are **unique**.

## My Solutions

---

```python
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        def backtrack(state,start,output):

            output.append(state)

            for i in range(start,len(nums)):
                backtrack(state + [nums[i]],i+1,output)

        output = []
        backtrack([],0,output)
        return output
```

```python

```

## Optimal Solutions

---

To solve **LeetCode Problem 78: Subsets**, you can employ several efficient algorithms. Below are the most optimal methods, each with its time and space complexities:

---

### **1. Backtracking (Recursive Depth-First Search)**

**Algorithm Overview:**

This method uses recursion to explore all possible subsets by making a choice at each step: include the current element or not.

**Steps:**

1. **Initialize** an empty list to hold all subsets.
2. **Define** a recursive function that takes three parameters:
    - The current subset being built.
    - The index of the next element to consider.
    - The original array `nums`.
3. **Base Case:** If the index equals the length of `nums`, add the current subset to the list of subsets.
4. **Recursive Case:**
    - **Include** the current element and recurse.
    - **Exclude** the current element and recurse.

**Code Snippet:**

```python
def subsets(nums):
    result = []
    def backtrack(current, index):
        if index == len(nums):
            result.append(current[:])
            return
        # Include nums[index]
        current.append(nums[index])
        backtrack(current, index + 1)
        # Exclude nums[index]
        current.pop()
        backtrack(current, index + 1)
    backtrack([], 0)
    return result

```

**Time Complexity:** O(2<sup>n</sup>)

- Each element has two choices: include or exclude.
- Total subsets = 2<sup>n</sup>.

**Space Complexity:** O(n)

- Maximum recursion depth is n.
- Space used by the recursion stack.

---

### **2. Iterative Approach (Cascading)**

**Algorithm Overview:**

This method builds subsets iteratively by adding each element to existing subsets.

**Steps:**

1. **Start** with an empty subset: `[[]]`.
2. **Iterate** over each element `num` in `nums`:
    - For each existing subset, create a new subset by adding `num`.
    - **Extend** the list of subsets with these new subsets.

**Code Snippet:**

```python
def subsets(nums):
    subsets = [[]]
    for num in nums:
        subsets += [curr + [num] for curr in subsets]
    return subsets

```

**Time Complexity:** O(2<sup>n</sup>)

- At each step, the number of subsets doubles.

**Space Complexity:** O(2<sup>n</sup>)

- Storing all subsets.

---

### **3. Bit Manipulation**

**Algorithm Overview:**

Utilize binary representations to generate all possible combinations.

**Steps:**

1. **Calculate** the total number of subsets: `2 ** n`.
2. **Iterate** from `0` to `2 ** n - 1`:
    - For each number `i`, generate a subset by including elements where the bit is set.
    - Use bitwise operations to check if a bit is set.

**Code Snippet:**

```python
def subsets(nums):
    n = len(nums)
    total_subsets = 1 << n  # 2^n
    result = []
    for i in range(total_subsets):
        subset = []
        for j in range(n):
            if (i >> j) & 1:
                subset.append(nums[j])
        result.append(subset)
    return result

```

**Time Complexity:** O(n * 2<sup>n</sup>)

- Iterating over 2<sup>n</sup> numbers.
- For each number, checking n bits.

**Space Complexity:** O(2<sup>n</sup> * n)

- Storing all subsets, each can have up to n elements.

---

### **Comparison and Recommendations**

- **All methods have a time complexity of O(2<sup>n</sup>)**, which is optimal for generating all subsets.
- **Backtracking** is intuitive and easy to implement recursively.
- **Iterative (Cascading)** is efficient and avoids recursion, which can be helpful to prevent stack overflow.
- **Bit Manipulation** is elegant and can be faster in practice due to bitwise operations but may be less intuitive.

---

**Note:** Since the problem requires generating all possible subsets, the exponential time complexity is unavoidable. The choice of algorithm can depend on personal preference or specific constraints such as stack size or execution speed.

## Notes

---

 

## Related Videos

---

[https://youtu.be/REOH22Xwdkk](https://youtu.be/REOH22Xwdkk)