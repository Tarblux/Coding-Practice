# Sort the People

Problem: 2418
Official Difficulty: easy
Feels Like : easy breazy
My Understanding: Fully Understand
Topic: array, hash table, sorting, string
Link: https://leetcode.com/problems/sort-the-people/description/
Completed On : August 9, 2024
Last Review: August 9, 2024
Days Since Review: 0

## Problem

---

You are given an array of strings `names`, and an array `heights` that consists of **distinct** positive integers. Both arrays are of length `n`.

For each index `i`, `names[i]` and `heights[i]` denote the name and height of the `ith` person.

Return `names` *sorted in **descending** order by the people's heights*.

**Example 1:**

```
Input: names = ["Mary","John","Emma"], heights = [180,165,170]
Output: ["Mary","Emma","John"]
Explanation: Mary is the tallest, followed by Emma and John.
```

**Example 2:**

```
Input: names = ["Alice","Bob","Bob"], heights = [155,185,150]
Output: ["Bob","Alice","Bob"]
Explanation: The first Bob is the tallest, followed by Alice and the second Bob.
```

**Constraints:**

- `n == names.length == heights.length`
- `1 <= n <= 103`
- `1 <= names[i].length <= 20`
- `1 <= heights[i] <= 105`
- `names[i]` consists of lower and upper case English letters.
- All the values of `heights` are distinct.

## My Solutions

---

```python
class Solution:
    def sortPeople(self, names: List[str], heights: List[int]) -> List[str]:

        zipped = list(zip(heights,names))
        zipped.sort(reverse = True)
        names = [name for _ , name in zipped]
        return names
        
```

```python
class Solution:
    def sortPeople(self, names: List[str], heights: List[int]) -> List[str]:

        zipped = list(zip(names,heights))
        zipped.sort(key= lambda x : x[1] , reverse = True)

        return [name[0] for name in zipped]
        
```

```python
class Solution:
    def sortPeople(self, names: List[str], heights: List[int]) -> List[str]:

        zipped = list(zip(names,heights))
        zipped.sort(key= lambda x : x[1])

        return [name[0] for name in zipped[::-1]]
        
```

## Optimal Solutions

---

### Problem Description

Given an array `names` and an array `heights` where `names[i]` corresponds to the height `heights[i]`, sort the people in descending order by their heights.

### Example

```python
Input: names = ["Mary", "John", "Emma"], heights = [180, 165, 170]
Output: ["Mary", "Emma", "John"]

Input: names = ["Alice", "Bob", "Bob"], heights = [155, 185, 150]
Output: ["Bob", "Alice", "Bob"]

```

### Solution Approach

To solve this problem, follow these steps:

1. **Combine the Names and Heights**: Create pairs of each name with its corresponding height.
2. **Sort by Heights**: Sort these pairs based on the height in descending order.
3. **Extract the Names**: After sorting, extract and return the names from the sorted list.

### Python Code

Here's the Python code to achieve this:

```python
from typing import List

class Solution:
    def sortPeople(self, names: List[str], heights: List[int]) -> List[str]:
        # Combine names and heights into a list of tuples
        people = list(zip(heights, names))

        # Sort the list by heights in descending order
        people.sort(reverse=True, key=lambda x: x[0])

        # Extract and return the sorted names
        return [name for _, name in people]

# Example usage
sol = Solution()
print(sol.sortPeople(["Mary", "John", "Emma"], [180, 165, 170]))  # Output: ["Mary", "Emma", "John"]
print(sol.sortPeople(["Alice", "Bob", "Bob"], [155, 185, 150]))   # Output: ["Bob", "Alice", "Bob"]

```

### Explanation

1. **Combine the Names and Heights**:
    - `people = list(zip(heights, names))` combines the `heights` and `names` into a list of tuples where each tuple consists of a height and the corresponding name. For example, `[(180, "Mary"), (165, "John"), (170, "Emma")]`.
2. **Sort by Heights**:
    - `people.sort(reverse=True, key=lambda x: x[0])` sorts the list of tuples by the first element (height) in descending order. The `reverse=True` parameter ensures that the sorting is done in descending order.
3. **Extract the Names**:
    - `return [name for _, name in people]` extracts just the names from the sorted list of tuples and returns them.

### Time Complexity Analysis

- **Time Complexity**: `O(n log n)`
    - Sorting the list of tuples takes `O(n log n)` time, where `n` is the number of people.
- **Space Complexity**: `O(n)`
    - The space complexity is `O(n)` due to the storage required for the list of tuples and the final list of names.

This approach efficiently sorts the people based on their heights and returns their names in the required order.

## Notes

---

 

## Related Videos

---

[https://www.youtube.com/watch?v=Zv_gXqqslbw&t=272s](https://www.youtube.com/watch?v=Zv_gXqqslbw&t=272s)