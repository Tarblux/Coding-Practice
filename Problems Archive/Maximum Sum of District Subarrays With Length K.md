# Maximum Sum of District Subarrays With Length K

Problem: 2461
Official Difficulty: medium
Feels Like : medium
My Understanding: Fully Understand
Topic: array, hash table, sliding window
Link: https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/description/
Completed On : December 11, 2024
Last Review: December 11, 2024
Days Since Review: 81
Neetcode: No

## Problem

---

You are given an integer array `nums` and an integer `k`. Find the maximum subarray sum of all the subarrays of `nums` that meet the following conditions:

- The length of the subarray is `k`, and
- All the elements of the subarray are **distinct**.

Return *the maximum subarray sum of all the subarrays that meet the conditions.* If no subarray meets the conditions, return `0`.

*A **subarray** is a contiguous non-empty sequence of elements within an array.*

**Example 1:**

```
Input: nums = [1,5,4,2,9,9,9], k = 3
Output: 15
Explanation: The subarrays of nums with length 3 are:
- [1,5,4] which meets the requirements and has a sum of 10.
- [5,4,2] which meets the requirements and has a sum of 11.
- [4,2,9] which meets the requirements and has a sum of 15.
- [2,9,9] which does not meet the requirements because the element 9 is repeated.
- [9,9,9] which does not meet the requirements because the element 9 is repeated.
We return 15 because it is the maximum subarray sum of all the subarrays that meet the conditions
```

**Example 2:**

```
Input: nums = [4,4,4], k = 3
Output: 0
Explanation: The subarrays of nums with length 3 are:
- [4,4,4] which does not meet the requirements because the element 4 is repeated.
We return 0 because no subarrays meet the conditions.
```

**Constraints:**

- `1 <= k <= nums.length <= 105`
- `1 <= nums[i] <= 105`

## My Solutions

---

Doesn’t quite work but see if you see why 

```python
class Solution:
    def maximumSubarraySum(self, nums: List[int], k: int) -> int:
        
        max_sum = 0
        cur_sum = 0
        unique = set()
        start = 0

        for i in range(len(nums)):

            cur_sum += nums[i]
            unique.add(nums[i])

            if i - start + 1 == k:

                if len(unique) == k:
                    max_sum = max(max_sum,cur_sum)

                cur_sum -= nums[start]
                unique.discard(nums[start])

                start += 1

        return max_sum
```

```python
class Solution:
    def maximumSubarraySum(self, nums: List[int], k: int) -> int:
        
        max_sum = 0
        cur_sum = 0
        unique = defaultdict(int)
        start = 0

        for i in range(len(nums)):

            cur_sum += nums[i]
            unique[nums[i]] += 1

            if i - start + 1 == k:

                if len(unique) == k:
                    max_sum = max(max_sum,cur_sum)

                cur_sum -= nums[start]
                unique[nums[start]] -= 1

                if unique[nums[start]] == 0:
                    unique.pop(nums[start])

                start += 1

        return max_sum
```

Alex 

```python
class Solution:
    def maximumSubarraySum(self, nums: List[int], k: int) -> int:

        start = 0
        cur_sum = 0
        cur = set()
        res = 0
        
        for end in range(len(nums)):
            while nums[end] in cur:
                cur.discard(nums[start])
                cur_sum -= nums[start]
                start += 1
            cur.add(nums[end])
            cur_sum += nums[end]
            if len(cur) == k:
                res = max(cur_sum, res)
                cur.discard(nums[start])
                cur_sum -= nums[start]
                start += 1

        return res

```

## Optimal Solutions

---

This approach uses a sliding window with a frequency map to track whether the current window of length `k` contains distinct elements. We keep track of:

- `freq`: a dictionary mapping each element in the current window to its frequency.
- `window_sum`: the sum of elements in the current window.
- `duplicates`: how many elements occur more than once in the current window.

**Steps:**

1. Initialize the first window of size `k`:
    - Add each element’s frequency to `freq`.
    - If any element’s frequency hits 2, increment `duplicates`.
    - Compute `window_sum`.
2. If no duplicates are in the initial window (`duplicates == 0`), update `max_sum` with `window_sum`.
3. Slide the window across `nums`:
    - Remove the element leaving the window (decrement its frequency, update `duplicates` if needed, subtract from `window_sum`).
    - Add the new element entering the window (increment its frequency, update `duplicates` if needed, add to `window_sum`).
4. After adjusting the window, if there are no duplicates (`duplicates == 0`), update `max_sum` if `window_sum` is larger.

By maintaining this information in O(1) time each step, the algorithm runs in O(n) time. The key insight is that we only consider windows of length `k` and check if they have distinct elements by tracking frequencies and duplicates count. If a window is distinct, we attempt to maximize `window_sum`.

**Code:**

```python
class Solution:
    def maximumSubarraySum(self, nums: List[int], k: int) -> int:
        freq = {}
        window_sum = 0
        max_sum = 0
        duplicates = 0  # counts how many elements appear more than once

        # Initialize the first window
        for i in range(k):
            val = nums[i]
            freq[val] = freq.get(val, 0) + 1
            if freq[val] == 2:
                duplicates += 1
            window_sum += val

        if duplicates == 0:
            max_sum = window_sum

        # Slide the window
        for i in range(k, len(nums)):
            # remove the element going out of the window
            left_val = nums[i - k]
            freq[left_val] -= 1
            if freq[left_val] == 1:
                duplicates -= 1
            window_sum -= left_val

            # add the new element coming into the window
            right_val = nums[i]
            freq[right_val] = freq.get(right_val, 0) + 1
            if freq[right_val] == 2:
                duplicates += 1
            window_sum += right_val

            # check if this window is distinct
            if duplicates == 0:
                max_sum = max(max_sum, window_sum)

        return max_sum

```

## Notes

---

 

[DSA Visualizations | Hello Interview](https://www.hellointerview.com/learn/code/sliding-window/maximum-sum-of-distinct-subarrays-with-length-k)

## Related Videos

---

[https://www.notion.so](https://www.notion.so)