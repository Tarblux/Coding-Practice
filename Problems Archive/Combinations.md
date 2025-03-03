# Combinations

Problem: 77
Official Difficulty: medium
Feels Like : medium
My Understanding: Mostly Understand
Topic: backtracking
Link: https://leetcode.com/problems/combinations/description/
Completed On : November 11, 2024
Last Review: November 11, 2024
Days Since Review: 111
Neetcode: No

## Problem

---

Given two integers `n` and `k`, return *all possible combinations of* `k` *numbers chosen from the range* `[1, n]`.

You may return the answer in **any order**.

**Example 1:**

```
Input: n = 4, k = 2
Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
Explanation: There are 4 choose 2 = 6 total combinations.
Note that combinations are unordered, i.e., [1,2] and [2,1] are considered to be the same combination.
```

**Example 2:**

```
Input: n = 1, k = 1
Output: [[1]]
Explanation: There is 1 choose 1 = 1 total combination.
```

**Constraints:**

- `1 <= n <= 20`
- `1 <= k <= n`

## My Solutions

---

```python
class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:

        combinations = []

        def backtrack(state,start):

            if len(state) == k:
                combinations.append(state)
                return

            for i in range(start,n+1):
                backtrack(state + [i],i + 1)

        backtrack([],1)

        return combinations
```

```python
class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:

        combinations = []
        

        def backtrack(state,start):

            if len(state) == k:
                combinations.append(state.copy())
                return

            for i in range(start,n+1):
                state.append(i)
                backtrack(state,i + 1)
                state.pop()

        backtrack([],1)

        return combinations
```

## Optimal Solutions

---

To solve **LeetCode Problem 77: Combinations**, which requires generating all possible combinations of `k` numbers out of the range `[1, n]`, several efficient algorithms can be employed. Below are the optimal methods along with their time and space complexities.

---

### **1. Backtracking (Depth-First Search)**

**Algorithm Overview:**

- **Objective:** Generate all combinations by building them incrementally and exploring all possibilities using recursion.
- **Approach:** Use backtracking to explore all potential combinations by adding numbers one by one and backtracking when the combination is invalid or complete.

**Algorithm Steps:**

1. **Define a Backtracking Function:**
    - The function `backtrack(start, path)` builds combinations starting from `start` with the current combination `path`.
    - **Base Case:**
        - If `len(path) == k`, add a copy of `path` to the result list.
    - **Recursive Case:**
        - Loop from `start` to `n`:
            - Append the current number `i` to `path`.
            - Recursively call `backtrack(i + 1, path)`.
            - Backtrack by removing the last number from `path`.
2. **Initialize the Process:**
    - Call `backtrack(1, [])` to start building combinations from `1`.

**Code Example:**

```python
def combine(n, k):
    result = []

    def backtrack(start, path):
        if len(path) == k:
            result.append(path[:])
            return
        for i in range(start, n + 1):
            path.append(i)
            backtrack(i + 1, path)
            path.pop()

    backtrack(1, [])
    return result

```

**Time Complexity:** O(C(n, k) * k)

- **Explanation:**
    - Total combinations are `C(n, k)` (n choose k).
    - Each combination takes O(k) time to build and add to the result.

**Space Complexity:** O(k)

- **Explanation:**
    - The recursion stack and `path` list can go up to depth `k`.

---

### **2. Optimized Backtracking with Pruning**

**Algorithm Overview:**

- **Objective:** Improve the basic backtracking by pruning unnecessary branches.
- **Approach:** Avoid unnecessary iterations by stopping the loop early when it's impossible to reach `k` elements.

**Algorithm Steps:**

1. **Modify the Loop Range:**
    - In the for-loop, iterate from `start` to `n - (k - len(path)) + 1`.
    - This ensures there are enough remaining numbers to fill the combination.
2. **Backtracking Function Remains Similar:**
    - Proceed as in the basic backtracking, but with the optimized loop range.

**Code Example:**

```python
def combine(n, k):
    result = []

    def backtrack(start, path):
        if len(path) == k:
            result.append(path[:])
            return
        for i in range(start, n - (k - len(path)) + 2):
            path.append(i)
            backtrack(i + 1, path)
            path.pop()

    backtrack(1, [])
    return result

```

**Time Complexity:** O(C(n, k) * k)

- **Explanation:**
    - Pruning reduces the number of iterations, but the total combinations remain `C(n, k)`.

**Space Complexity:** O(k)

---

### **3. Iterative Approach Using Stack**

**Algorithm Overview:**

- **Objective:** Generate combinations iteratively to avoid recursion.
- **Approach:** Use a stack to simulate the recursive calls.

**Algorithm Steps:**

1. **Initialize the Stack:**
    - Start with an initial combination `[1]`.
2. **Iteratively Build Combinations:**
    - While the stack is not empty:
        - If the current combination has length `k`, add it to the result.
        - Else, increment the last element and add it to the combination if valid.
        - If the last element exceeds `n`, backtrack.

**Code Example:**

```python
def combine(n, k):
    result = []
    stack = []
    x = 1
    while True:
        if len(stack) == k:
            result.append(stack[:])
        if len(stack) == k or x > n:
            if not stack:
                break
            x = stack.pop() + 1
        else:
            stack.append(x)
            x += 1
    return result

```

**Time Complexity:** O(C(n, k) * k)

- **Explanation:**
    - Similar to recursive backtracking.

**Space Complexity:** O(k)

---

### **4. Lexicographic (Binary Sorted) Combinations**

**Algorithm Overview:**

- **Objective:** Generate combinations in lexicographic order.
- **Approach:** Use integers to represent combinations and manipulate them to get the next combination.

**Algorithm Steps:**

1. **Initialize the First Combination:**
    - Start with the combination `[1, 2, ..., k]`.
2. **Generate Next Combinations:**
    - While the first element has not exceeded `n - k + 1`:
        - Add the current combination to the result.
        - Find the first element from the end that can be incremented.
        - Increment it and reset subsequent elements.

**Code Example:**

```python
def combine(n, k):
    result = []
    nums = list(range(1, k + 1)) + [n + 1]
    j = 0
    while j < k:
        result.append(nums[:k])
        j = 0
        while j < k and nums[j + 1] == nums[j] + 1:
            nums[j] = j + 1
            j += 1
        nums[j] += 1
    return result

```

**Time Complexity:** O(C(n, k) * k)

- **Explanation:**
    - Each combination is generated in O(k) time.

**Space Complexity:** O(k)

---

### **5. Using itertools.combinations (Python Specific)**

**Algorithm Overview:**

- **Objective:** Utilize Python's built-in library to generate combinations.
- **Approach:** Use `itertools.combinations` to generate all combinations.

**Code Example:**

```python
from itertools import combinations

def combine(n, k):
    return [list(c) for c in combinations(range(1, n + 1), k)]

```

**Time Complexity:** O(C(n, k) * k)

- **Explanation:**
    - The library function is optimized but still generates all combinations.

**Space Complexity:** O(C(n, k) * k)

- **Explanation:**
    - All combinations are stored in the result list.

---

### **Comparison and Recommendation**

- **Backtracking (Method 1 and 2):**
    - **Pros:**
        - Straightforward and easy to understand.
        - Efficient for generating combinations.
    - **Cons:**
        - Recursive calls can lead to stack overflow for very large `n`.
- **Iterative Approach (Method 3):**
    - **Pros:**
        - Avoids recursion.
    - **Cons:**
        - Can be less intuitive.
- **Lexicographic Combinations (Method 4):**
    - **Pros:**
        - Generates combinations in order.
        - Efficient without recursion.
    - **Cons:**
        - More complex to implement.
- **Using itertools (Method 5):**
    - **Pros:**
        - Simplest code.
        - Highly optimized.
    - **Cons:**
        - Not suitable if custom logic is needed within the generation process.
        - Depends on the language/library.

**Recommendation:**

- The **backtracking approach (Method 1)** is generally preferred for its simplicity and clarity. It is easy to implement and understand, making it suitable for most cases.
- If avoiding recursion is desired, the **lexicographic method (Method 4)** is a good alternative.

---

### **Final Code Solution (Backtracking Approach):**

```python
class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        result = []

        def backtrack(start, path):
            if len(path) == k:
                result.append(path[:])
                return
            # Optimization: Enough elements remaining to fill the combination
            for i in range(start, n - (k - len(path)) + 2):
                path.append(i)
                backtrack(i + 1, path)
                path.pop()

        backtrack(1, [])
        return result

```

**Time Complexity:** O(C(n, k) * k)

- **Explanation:**
    - Generates all possible combinations.
    - Each combination takes O(k) time to build.

**Space Complexity:** O(k)

- **Explanation:**
    - The recursion stack and path list have a maximum depth of `k`.

---

By using backtracking with pruning, we efficiently generate all possible combinations while minimizing unnecessary iterations. This approach balances performance and code simplicity, making it an optimal solution for the problem.

## Notes

---

 

## Related Videos

---

[https://www.notion.so](https://www.notion.so)