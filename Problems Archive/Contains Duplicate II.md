# Contains Duplicate II

Problem: 219
Official Difficulty: easy
Feels Like : easy
My Understanding: Fully Understand
Topic: array, hash table, sliding window
Link: https://leetcode.com/problems/contains-duplicate-ii/description/?envType=study-plan-v2&envId=top-interview-150
Completed On : October 8, 2024
Last Review: October 8, 2024
Days Since Review: 145
Neetcode: No

## Problem

---

Given an integer array `nums` and an integer `k`, return `true` *if there are two **distinct indices*** `i` *and* `j` *in the array such that* `nums[i] == nums[j]` *and* `abs(i - j) <= k`.

**Example 1:**

```
Input: nums = [1,2,3,1], k = 3
Output: true

```

**Example 2:**

```
Input: nums = [1,0,1,1], k = 1
Output: true

```

**Example 3:**

```
Input: nums = [1,2,3,1,2,3], k = 2
Output: false

```

**Constraints:**

- `1 <= nums.length <= 105`
- `109 <= nums[i] <= 109`
- `0 <= k <= 105`

## My Solutions

---

```python
class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:

        memo = {}

        for i in range(len(nums)):
            if nums[i] not in memo:
                memo[nums[i]] = i
            else:
                if abs(memo[nums[i]] - i) <= k:
                    return True 
                memo[nums[i]] = i

        return False
```

```python

```

## Optimal Solutions

---

To solve **LeetCode Problem: Contains Duplicate II**, the most efficient algorithms utilize hash-based data structures to track elements and their indices within a given range.

---

### **Algorithm 1: Sliding Window using a HashSet**

**Algorithm Steps:**

1. **Initialize** an empty `HashSet` to store elements within the current window of size `k`.
2. **Iterate** over the array `nums` with index `i`:
    - **Check** if `nums[i]` is in the `HashSet`:
        - If **yes**, return `True` (a duplicate within distance `k` is found).
    - **Add** `nums[i]` to the `HashSet`.
    - **Maintain** the window size:
        - If `i >= k`, **remove** `nums[i - k]` from the `HashSet` to keep the window size at most `k`.
3. **Return** `False` if no duplicates are found within distance `k`.

**Time Complexity:** O(n)

- Each element is added to and possibly removed from the `HashSet` exactly once.

**Space Complexity:** O(min(n, k))

- The `HashSet` contains at most `k` elements at any time.

**Code Example:**

```python
def containsNearbyDuplicate(nums, k):
    seen = set()
    for i, num in enumerate(nums):
        if num in seen:
            return True
        seen.add(num)
        if i >= k:
            seen.remove(nums[i - k])
    return False
```

---

### **Algorithm 2: HashMap to Track Indices**

**Algorithm Steps:**

1. **Initialize** an empty `HashMap` to store the last seen index of each element.
2. **Iterate** over the array `nums` with index `i`:
    - **If** `nums[i]` is in the `HashMap` and `i - hashmap[nums[i]] <= k`:
        - **Return** `True` (a duplicate within distance `k` is found).
    - **Update** `hashmap[nums[i]] = i`.
3. **Return** `False` if no duplicates are found within distance `k`.

**Time Complexity:** O(n)

- Single pass through the array.

**Space Complexity:** O(n)

- In the worst case, the `HashMap` stores all elements.

**Code Example:**

```python
def containsNearbyDuplicate(nums, k):
    index_map = {}
    for i, num in enumerate(nums):
        if num in index_map and i - index_map[num] <= k:
            return True
        index_map[num] = i
    return False
```

---

### **Algorithm Comparison**

- **Algorithm 1 (HashSet with Sliding Window):**
    - **Space Efficient** when `k` is small compared to `n`.
    - **Maintains** a window of the last `k` elements.
- **Algorithm 2 (HashMap with Indices):**
    - **Simple Implementation** that directly checks the distance between duplicate indices.
    - **Potentially Higher Space Usage** since it can store up to `n` elements.

Both algorithms have a time complexity of **O(n)** and are efficient for this problem. The choice between them can depend on the specific constraints of `k` and personal preference.

## Notes

---

 

## Related Videos

---

[https://www.notion.so](https://www.notion.so)