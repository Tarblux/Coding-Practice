# Longest Increasing Subsequence

Problem: 300
Official Difficulty: medium
Feels Like : medium
My Understanding: Mostly Understand
Topic: array, binary search, dynamic programming
Link: https://leetcode.com/problems/longest-increasing-subsequence/description/
Completed On : February 1, 2025
Last Review: February 1, 2025
Days Since Review: 29
Neetcode: Yes

## Problem

---

Given an integer array `nums`, return *the length of the longest **strictly increasing***

***subsequence***.

**Example 1:**

```
Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
```

**Example 2:**

```
Input: nums = [0,1,0,3,2,3]
Output: 4
```

**Example 3:**

```
Input: nums = [7,7,7,7,7,7,7]
Output: 1
```

**Constraints:**

- `1 <= nums.length <= 2500`
- `104 <= nums[i] <= 104`

**Follow up:** Can you come up with an algorithm that runs in `O(n log(n))` time complexity?

## My Solutions

---

```python
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:

        if not nums:
            return 0

        n = len(nums)
        dp = [1] * n
        longest = 1

        for i in range(1,n):
            for j in range(i):
    
                if nums[i] > nums[j]:
                    dp[i] = max(dp[i],dp[j]+1)
                    longest = max(longest,dp[i])

        return longest
```

```python

```

## Optimal Solutions

---

**Intuition**

- We want the length of the longest strictly increasing subsequence in an array.
- A subsequence does not need to be contiguous, but the order of elements must be maintained.
- There are **three well-known approaches**:
    1. **Top-Down DP (O(n²))**
    2. **Bottom-Up DP (O(n²))**
    3. **Optimized Approach with Binary Search (O(n log n))** (this is typically considered the “most optimal” in practice).

Below, you’ll find both **Top-Down** and **Bottom-Up** solutions for the classic DP approach (O(n2)O(n^2)) along with the **O(n \log n)** optimization.

---

## Approach

### 1) Top-Down (Memoized) – O(n2)O(n^2)

1. Define a function `LIS(i, prev_index)` that returns the length of the longest increasing subsequence starting at index `i` when the previous element used in the subsequence is at `prev_index`.
2. If `nums[i] > nums[prev_index]`, we have two choices:
    - **Take** `nums[i]`, and move to `LIS(i+1, i)`.
    - **Skip** `nums[i]`, and move to `LIS(i+1, prev_index)`.
    The result is the maximum of these two.
3. If `nums[i] <= nums[prev_index]`, we can only skip `nums[i]` and do `LIS(i+1, prev_index)`.
4. Use a memo dictionary to store `(i, prev_index) -> result`.
5. For convenience, we can start `prev_index` as `1` indicating no element has been chosen yet.

**Code**:

```python
def lengthOfLIS_top_down(nums):
    from functools import lru_cache

    n = len(nums)

    @lru_cache(None)
    def LIS(i, prev_index):
        if i == n:
            return 0

        # Option 1: Skip current i
        best = LIS(i + 1, prev_index)

        # Option 2: Take nums[i] if valid
        if prev_index == -1 or nums[i] > nums[prev_index]:
            best = max(best, 1 + LIS(i + 1, i))

        return best

    return LIS(0, -1)

```

---

### 2) Bottom-Up (Tabulated) – O(n2)O(n^2)

1. Let `dp[i]` represent the length of the longest increasing subsequence **ending at index `i`**.
2. Initialize `dp[i] = 1` for all `i` (the smallest LIS ending anywhere is at least the element itself).
3. For each `i` from `0` to `n-1`:
    - Look at each `j < i`.
    - If `nums[j] < nums[i]`, then `dp[i] = max(dp[i], dp[j] + 1)`.
4. The final answer is `max(dp)` among all indices.

**Code**:

```python
def lengthOfLIS_bottom_up(nums):
    n = len(nums)
    if n == 0:
        return 0

    dp = [1] * n
    for i in range(n):
        for j in range(i):
            if nums[j] < nums[i]:
                dp[i] = max(dp[i], dp[j] + 1)

    return max(dp)

```

---

### 3) Optimized with Binary Search – O(nlog⁡n)O(n \log n)

1. Maintain a list `tails`, where `tails[k]` is the **smallest possible tail value** of any increasing subsequence of length `k+1`.
2. Iterate through each `num` in `nums`:
    - Use **binary search** to find the position `pos` in `tails` where `num` should be placed:
        - If `num` is bigger than all elements in `tails`, append it (increasing the length of our subsequence).
        - Otherwise, replace the element at `pos` with `num` (lowering the tail value for subsequences of length `pos+1`).
3. The length of `tails` at the end is the length of the longest increasing subsequence.

**Code**:

```python
def lengthOfLIS_optimized(nums):
    import bisect

    tails = []
    for num in nums:
        # Find the index to replace in tails
        pos = bisect.bisect_left(tails, num)
        # If pos is equal to len(tails), we extend tails
        if pos == len(tails):
            tails.append(num)
        else:
            tails[pos] = num
    return len(tails)

```

---

## Testcases

```python
# 1) Example 1
nums1 = [10, 9, 2, 5, 3, 7, 101, 18]
# Top-Down
print(lengthOfLIS_top_down(nums1))       # Output: 4
# Bottom-Up
print(lengthOfLIS_bottom_up(nums1))      # Output: 4
# Optimized
print(lengthOfLIS_optimized(nums1))      # Output: 4

# 2) Example 2
nums2 = [0, 1, 0, 3, 2, 3]
# Top-Down
print(lengthOfLIS_top_down(nums2))       # Output: 4
# Bottom-Up
print(lengthOfLIS_bottom_up(nums2))      # Output: 4
# Optimized
print(lengthOfLIS_optimized(nums2))      # Output: 4

# 3) Example 3
nums3 = [7, 7, 7, 7, 7, 7]
# Top-Down
print(lengthOfLIS_top_down(nums3))       # Output: 1
# Bottom-Up
print(lengthOfLIS_bottom_up(nums3))      # Output: 1
# Optimized
print(lengthOfLIS_optimized(nums3))      # Output: 1

```

---

**Summary**

- **Top-Down DP** and **Bottom-Up DP** both have  complexity.
    
    O(n2)O(n^2)
    
- The **Optimized** approach with binary search yields  time complexity, which is generally considered the best known solution for Longest Increasing Subsequence.
    
    O(nlog⁡n)O(n \log n)
    

## Notes

---

 

## Related Videos

---

[https://www.notion.so](https://www.notion.so)