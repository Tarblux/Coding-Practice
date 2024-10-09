# Lexicographical Numbers

Problem: 386
Official Difficulty: medium
Feels Like : medium
My Understanding: Fully Understand
Topic: Depth-First Search (DFS), Trie
Link: https://leetcode.com/problems/lexicographical-numbers/description/
Completed On : September 20, 2024
Last Review: September 20, 2024
Days Since Review: 3

## Problem

---

Given an integer `n`, return all the numbers in the range `[1, n]` sorted in lexicographical order.

You must write an algorithm that runs in `O(n)` time and uses `O(1)` extra space.

**Example 1:**

```
Input: n = 13
Output: [1,10,11,12,13,2,3,4,5,6,7,8,9]
```

**Example 2:**

```
Input: n = 2
Output: [1,2]
```

**Constraints:**

- `1 <= n <= 5 * 104`

## My Solutions

---

```python
class Solution:

    def converter(self,number):

        output = []
        while number:

            digit = number % 10
            number //= 10
            output.append(chr(digit + 96))
        return ''.join(output[::-1])

    def lexicalOrder(self, n: int) -> List[int]:

        nums = [i for i in range(1,n+1)]

        nums.sort(key=lambda x : self.converter(x))

        return nums
```

```python

```

## Optimal Solutions

---

**Problem 386: Lexicographical Numbers**

**Description:**
Given an integer `n`, return all the numbers in the range `[1, n]` sorted in lexicographical order.

### Approach:

To generate numbers in lexicographical order, you can think of it as performing a Depth-First Search (DFS) on numbers starting from 1 up to `n`. This means you try to "expand" each number by adding digits to it in the form of a tree traversal.

1. **Recursive DFS Method**:
    - Start with the smallest digit (1 to 9).
    - For each number, keep adding digits from 0 to 9 to form the next set of numbers.
    - If the number formed is greater than `n`, stop expanding that path.
2. **Iterative Method**:
    - You can also simulate DFS using an iterative approach, starting from the smallest possible lexicographical number.

### Example:

For `n = 13`, the lexicographical order would be:

```
1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9

```

### Solution using DFS:

```python
class Solution:
    def lexicalOrder(self, n: int) -> List[int]:
        def dfs(current):
            if current > n:
                return
            result.append(current)
            for i in range(10):
                next_num = current * 10 + i
                if next_num > n:
                    return
                dfs(next_num)

        result = []
        # Start DFS with numbers 1 through 9 (valid starting digits)
        for i in range(1, 10):
            dfs(i)
        return result

```

### Explanation:

1. **dfs(current)**:
    - Adds `current` to the `result` list.
    - Tries to form new numbers by appending digits `0` through `9` to `current` (multiplying `current` by 10 and adding the digit).
    - Stops expanding when the new number exceeds `n`.
2. **Loop from 1 to 9**:
    - Starts the DFS for numbers starting from `1` to `9` because `0` is not a valid starting number in the range `[1, n]`.
3. **Time Complexity**:
    - The DFS will visit each number once up to `n`, making it an `O(n)` solution.

### Iterative Approach:

If you prefer an iterative approach instead of using recursion, you can use this method:

```python
class Solution:
    def lexicalOrder(self, n: int) -> List[int]:
        result = []
        current = 1
        for _ in range(n):
            result.append(current)
            # Try to move to the next lexicographical number
            if current * 10 <= n:
                current *= 10
            else:
                # Move to the next number in lexicographical order
                while current % 10 == 9 or current + 1 > n:
                    current //= 10
                current += 1
        return result

```

### Explanation:

1. **Current number multiplication**:
    - If `current * 10` is within bounds (`<= n`), it means we can go to the next digit level (e.g., `1` to `10`).
2. **Handling the next lexicographical number**:
    - If we cannot go to the next digit level (because it exceeds `n`), we backtrack by dividing by 10 until we can increment to the next number that doesn’t end in `9` (to avoid numbers like `19` to `20`).

This approach is also `O(n)` and is straightforward to implement without recursion, using a loop to simulate the DFS traversal.

## Notes

---

 

## Related Videos

---

[https://www.youtube.com/watch?v=E3RGdrPGO5Q&pp=ygUMbGVldGNvZGUgMzg2](https://www.youtube.com/watch?v=E3RGdrPGO5Q&pp=ygUMbGVldGNvZGUgMzg2)