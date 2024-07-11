# Minimum Difference Between Largest and Smallest Value in Three Moves

Problem: 1509
Official Difficulty: medium
Feels Like : medium
My Understanding: Mostly Understand
Topic: array, greedy, sorting
Link: https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/
Completed On : July 3, 2024
Last Review: July 3, 2024
Days Since Review: 8

## Problem

---

You are given an integer array `nums`.

In one move, you can choose one element of `nums` and change it to **any value**.

Return *the minimum difference between the largest and smallest value of `nums` **after performing at most three moves***.

**Example 1:**

```
Input: nums = [5,3,2,4]
Output: 0
Explanation: We can make at most 3 moves.
In the first move, change 2 to 3. nums becomes [5,3,3,4].
In the second move, change 4 to 3. nums becomes [5,3,3,3].
In the third move, change 5 to 3. nums becomes [3,3,3,3].
After performing 3 moves, the difference between the minimum and maximum is 3 - 3 = 0.
```

**Example 2:**

```
Input: nums = [1,5,0,10,14]
Output: 1
Explanation: We can make at most 3 moves.
In the first move, change 5 to 0. nums becomes [1,0,0,10,14].
In the second move, change 10 to 0. nums becomes [1,0,0,0,14].
In the third move, change 14 to 1. nums becomes [1,0,0,0,1].
After performing 3 moves, the difference between the minimum and maximum is 1 - 0 = 1.
It can be shown that there is no way to make the difference 0 in 3 moves.
```

**Example 3:**

```
Input: nums = [3,100,20]
Output: 0
Explanation: We can make at most 3 moves.
In the first move, change 100 to 7. nums becomes [3,7,20].
In the second move, change 20 to 7. nums becomes [3,7,7].
In the third move, change 3 to 7. nums becomes [7,7,7].
After performing 3 moves, the difference between the minimum and maximum is 7 - 7 = 0.
```

**Constraints:**

- `1 <= nums.length <= 105`
- `109 <= nums[i] <= 109`

## My Solutions

---

```python
**class Solution:
    def minDifference(self, nums: List[int]) -> int:

        """
        - Handle Edge Cases
        - Sort Array
        - Compare the different possibilities from removing from each end 
        - Greedily store soulutions to different removals

        TC: O(nlogn)
        SC: O(1)
        """

        if len(nums) <= 4:
            return 0

        nums.sort()

        # Moving the 3 largest
        largest = nums[len(nums)-4] - nums[0]

        # Move the smallest 
        smallest = nums[len(nums)-1] - nums[3]

        # Move the smallest + two largest 
        onesmall_twolargest = nums[len(nums)-3] - nums[1] 

        # Move the two smallest + largest 
        twosmall_onelargest = nums[len(nums)-2] - nums[2] 

        return min(twosmall_onelargest,onesmall_twolargest,smallest,largest)**
```

```python
class Solution:
    def minDifference(self, nums: List[int]) -> int:
        nums_size = len(nums)

        # If the array has 4 or fewer elements, return 0
        if nums_size <= 4:
            return 0

        nums.sort()

        min_diff = float("inf")

        # Four scenarios to compute the minimum difference
        for left in range(4):
            right = nums_size - 4 + left
            min_diff = min(min_diff, nums[right] - nums[left])

        return min_diff
```

## Optimal Solutions

---

### Problem Description

Given an integer array `nums`, you are allowed to make at most three moves. In each move, you can choose any element of the array and change it to any value. After doing so, return the minimum difference between the largest and smallest values in the array.

### Example

```python
Input: nums = [5,3,2,4]
Output: 0
Explanation: Change the array to [2,2,2,2]. The difference between the maximum and minimum is 2-2 = 0.

Input: nums = [1,5,0,10,14]
Output: 1
Explanation: Change the array to [1,1,0,1,1]. The difference between the maximum and minimum is 1-0 = 1.

```

### Optimal Solution and Explanation

To solve this problem, the key insight is to understand that after up to three changes, the minimum difference will be determined by how we can manipulate the smallest and largest elements. Specifically, after at most three moves, we can either change up to three of the smallest values or up to three of the largest values or some combination of both.

To achieve the minimum difference:

1. **Sort the Array**: First, sort the array.
2. **Check All Possible Changes**: Consider the minimum difference possible when changing 0, 1, 2, or 3 of the smallest/largest elements.
3. **Return the Minimum Possible Difference**: Among all the changes considered, return the smallest difference.

### Steps:

1. Sort the array.
2. Consider the difference between the 4th smallest and the largest, the 3rd smallest and the 2nd largest, etc., after changing 0, 1, 2, or 3 elements respectively.

### Python Code

```python
def minDifference(nums):
    if len(nums) <= 4:
        return 0  # If there are 4 or fewer elements, we can make them all equal

    nums.sort()
    # Compare the minimum difference after changing 0, 1, 2, or 3 elements
    return min(
        nums[-1] - nums[3],    # Change the smallest three elements
        nums[-2] - nums[2],    # Change the smallest two and the largest one
        nums[-3] - nums[1],    # Change the smallest one and the largest two
        nums[-4] - nums[0]     # Change the largest three elements
    )

# Example usage
print(minDifference([5,3,2,4]))  # Output: 0
print(minDifference([1,5,0,10,14]))  # Output: 1

```

### Explanation

1. **Sorting the Array**:
    - By sorting the array, we can easily identify and manipulate the smallest and largest elements.
2. **Calculating Differences**:
    - `nums[-1] - nums[3]`: Change the smallest three elements to something greater or equal to the 4th smallest.
    - `nums[-2] - nums[2]`: Change the smallest two and the largest one.
    - `nums[-3] - nums[1]`: Change the smallest one and the largest two.
    - `nums[-4] - nums[0]`: Change the largest three elements.

### Time Complexity Analysis

- **Time Complexity**: `O(n log n)`
    - The most time-consuming step is sorting the array.

### Space Complexity Analysis

- **Space Complexity**: `O(1)`
    - This approach only requires a constant amount of additional space beyond the input array itself.

This solution efficiently calculates the minimum difference by leveraging sorting and careful consideration of how changes affect the array’s minimum and maximum elements.

# Better Solution

```python
from typing import List
import heapq

class Solution:
    def minDifference(self, nums: List[int]) -> int:
        if len(nums) <= 4:
            return 0  # If there are 4 or fewer elements, all can be made equal, so the difference is 0.

        # Extract the four largest and four smallest elements using heaps
        largest = heapq.nlargest(4, nums)
        smallest = heapq.nsmallest(4, nums)

        # Initialize minimum difference as infinity
        min_diff = float('inf')

        # Compare differences after potentially changing up to three elements
        for i in range(4):
            min_diff = min(min_diff, largest[i] - smallest[3 - i])

        return min_diff

# Example usage:
sol = Solution()
print(sol.minDifference([5,3,2,4]))  # Output: 0
print(sol.minDifference([1,5,0,10,14]))  # Output: 1

```

### Time Complexity Analysis

- **Heap Operations**:
    - `heapq.nlargest(4, nums)` and `heapq.nsmallest(4, nums)` both operate in `O(n log k)` time, where `n` is the number of elements in the array and `k` is the number of elements we are extracting, which in this case is `4`. Since `k` is constant, these operations can be considered `O(n)`.
- **Loop Over Fixed Range**:
    - The loop iterates a fixed number of times (4 times), and each iteration involves a constant time comparison and assignment operation. Thus, the loop itself contributes only `O(1)` to the overall time complexity.
- **Overall Time Complexity**:
    - Given that the heap operations dominate the time complexity, the overall time complexity of the method is `O(n)`, where `n` is the size of the input array `nums`.

### Space Complexity Analysis

- **Heap Storage**:
    - The space used to store the `largest` and `smallest` arrays is constant, i.e., `O(1)`, since we are only storing four elements each regardless of the size of the input array.
- **Overall Space Complexity**:
    - Thus, the overall space complexity of the method is also `O(1)`.

This solution is efficient, utilizing heap operations to extract only the necessary elements rather than sorting the entire array. It’s optimal for large arrays where the difference between the few largest and smallest values determines the potential minimum difference after the allowed modifications.

## Notes

---

 

## Related Videos

---

[https://youtu.be/S6cUjbQuTnE](https://youtu.be/S6cUjbQuTnE)