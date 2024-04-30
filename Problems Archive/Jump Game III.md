# Jump Game III

Problem: 1306
Official Difficulty: medium
Feels Like : medium
My Understanding: Mostly Understand
Topic: Breadth-First Search(BFS), Depth-First Search (DFS), array
Link: https://leetcode.com/problems/jump-game-iii/description/
Completed On : April 15, 2024
Last Review: April 15, 2024
Days Since Review: 15

## Problem

---

Given an array of non-negative integers `arr`, you are initially positioned at `start` index of the array. When you are at index `i`, you can jump to `i + arr[i]` or `i - arr[i]`, check if you can reach **any** index with value 0.

Notice that you can not jump outside of the array at any time.

**Example 1:**

```
Input: arr = [4,2,3,0,3,1,2], start = 5
Output: true
Explanation:
All possible ways to reach at index 3 with value 0 are:
index 5 -> index 4 -> index 1 -> index 3
index 5 -> index 6 -> index 4 -> index 1 -> index 3
```

**Example 2:**

```
Input: arr = [4,2,3,0,3,1,2], start = 0
Output: true
Explanation:
One possible way to reach at index 3 with value 0 is:
index 0 -> index 4 -> index 1 -> index 3
```

**Example 3:**

```
Input: arr = [3,0,2,1,2], start = 2
Output: false
Explanation:There is no way to reach at index 1 with value 0.
```

**Constraints:**

- `1 <= arr.length <= 5 * 104`
- `0 <= arr[i] < arr.length`
- `0 <= start < arr.length`

## My Solutions

---

```python
class Solution:

    def jumper(self,index:int,array:List[int],cache:dict) -> bool:

        if index < 0 or index > len(array) - 1:
            return False

        if array[index] == 0 :
            return True

        if index in cache: 
            return False
        else:
            cache[index] = True

        return self.jumper(index - array[index],array,cache) or self.jumper(index + array[index],array,cache)

    def canReach(self, arr: List[int], start: int) -> bool:

        cache = {}

        return self.jumper(start,arr,cache)     
```

```python

```

## Optimal Solutions

---

The "Jump Game III" problem is a variation of the classic "Jump Game" where you start at a specific index in an array of non-negative integers. Each element in the array represents your maximum jump length at that position. Your goal is to determine if you can reach any index with value 0 by jumping left or right.

Here's a brief on how to solve the "Jump Game III" problem using depth-first search (DFS), which can efficiently explore the jump paths:

### Problem Statement:

Given an array `arr` of non-negative integers and a starting index `start`, determine if you can reach any index with the value `0`.

### Approach: Depth-First Search (DFS)

1. **Recursive DFS**: Use a recursive function to try jumping from the current index to any index within the jump range in both directions (left and right).
2. **Visited Set**: Keep track of visited indices to prevent infinite loops.
3. **Base Cases**:
    - If you land on an index with value `0`, return `True`.
    - If you land on an index that is out of bounds or has been visited before, return `False`.

### Python Implementation:

```python
from typing import List

class Solution:
    def canReach(self, arr: List[int], start: int) -> bool:
        n = len(arr)
        visited = set()

        def dfs(index: int) -> bool:
            # Base cases: check if out of bounds or already visited
            if index < 0 or index >= n or index in visited:
                return False
            # Check if we've reached a zero value
            if arr[index] == 0:
                return True

            # Mark this index as visited
            visited.add(index)

            # Recurse to the right and left
            jump_distance = arr[index]
            return dfs(index + jump_distance) or dfs(index - jump_distance)

        return dfs(start)

```

### Explanation:

- **DFS Function**: The `dfs` function checks if the current index is within bounds and if the index has not been visited. It then checks if the current value is `0`. If true, it means we've reached a valid end. If not, it adds the index to the visited set and recursively calls itself for both right and left jumps.
- **Initial Call**: The solution starts the DFS from the `start` index.

### Complexity:

- **Time Complexity**: O(n), where `n` is the number of elements in `arr`. In the worst case, each element is visited once.
- **Space Complexity**: O(n) for the recursion stack and the visited set in the worst case.

This DFS approach efficiently explores all possible paths and checks if a path can lead to an index with value `0`. The use of the visited set is crucial for ensuring the algorithm does not re-visit indices, thus preventing infinite loops and reducing the time complexity.

## Notes

---

 

## Related Videos

---

[https://www.youtube.com/watch?v=FVkYM-GjiQQ](https://www.youtube.com/watch?v=FVkYM-GjiQQ)