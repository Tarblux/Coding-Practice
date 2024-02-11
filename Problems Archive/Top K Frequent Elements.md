# Top K Frequent Elements

Problem: 347
Official Difficulty: medium
Feels Like : easy
Topic: Heap, hash table, sorting
Link: https://leetcode.com/problems/top-k-frequent-elements/
Completed On : December 13, 2023
My Understanding: Mostly Understand
Last Review: December 13, 2023
Days Since Review: 59

## Problem

---

Given an integer array `nums` and an integer `k`, return *the* `k` *most frequent elements*. You may return the answer in **any order**.

**Example 1:**

```
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

```

**Example 2:**

```
Input: nums = [1], k = 1
Output: [1]

```

**Constraints:**

- `1 <= nums.length <= 105`
- `104 <= nums[i] <= 104`
- `k` is in the range `[1, the number of unique elements in the array]`.
- It is **guaranteed** that the answer is **unique**.

**Follow up:** Your algorithm's time complexity must be better than `O(n log n)`, where n is the array's size.

## My Solutions

---

```python
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:

        freq_dict = {}

        for num in nums:
            if num not in freq_dict:
                freq_dict[num] = 1
            else:
                freq_dict[num] += 1

        sorted_nums = sorted(freq_dict, key=freq_dict.get , reverse=True)

        return sorted_nums[:k]
```

### Sanya

```python
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        
        if len(nums) == 1:
            return [nums[0]]

        dict = {}

        for num in nums:
            dict[num] = dict.get(num, 0) + 1
    
        freq = []
        for i in range(len(nums) + 1):
            freq.append([])
        #[ [], [3], [2], [1], [], [] ]

        for key_num, value_count in dict.items():
            freq[value_count].append(key_num)
        
        results = [] 

        for i in range(len(freq) - 1, -1, -1):
            for j in freq[i]:
                results.append(j)
                k -= 1
                if k == 0:
                    #print(dict) # {1: 3, 2: 2, 3: 1}
                    #print(freq) # [[], [3], [2], [1], [], []]
                    #print(results) # [1, 2]
                    return results

        return results
```

## Optimal Solutions

---

The "Top K Frequent Elements" problem involves finding the `k` most frequent elements in a given list. A common and efficient approach to solve this problem is to use a hash map (or dictionary in Python) to count the frequency of each element and then use a heap or sorting to find the `k` most frequent elements.

### Solution Approach

1. **Count Frequencies**: Use a hash map to count the frequency of each element in the list.
2. **Use a Heap**: Build a min-heap of size `k` to keep track of the `k` most frequent elements. Alternatively, you can sort the elements by frequency and then take the top `k`.

### Python Implementation Using a Heap

```python
import heapq
from collections import Counter

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        # Count the frequency of each element
        freq = Counter(nums)

        # Build a heap of the k most frequent elements
        return heapq.nlargest(k, freq.keys(), key=freq.get)

```

### Explanation

- `Counter(nums)` creates a frequency map of the elements in `nums`.
- `heapq.nlargest(k, freq.keys(), key=freq.get)` finds the `k` keys with the highest values in `freq`. It uses a min-heap under the hood, making it more efficient than sorting for large lists.

### Complexity Analysis

- **Time Complexity**:
    - Counting the frequencies is O(n), where `n` is the number of elements in the list.
    - The `heapq.nlargest` function runs in O(n log k) time.
    - Overall, the time complexity is O(n log k).
- **Space Complexity**: O(n) for storing the frequency map.

This approach efficiently finds the top `k` frequent elements in the given list using a combination of a hash map and a heap.

## Notes

---

 

## Related Videos

---

[https://youtu.be/YPTqKIgVk-k?si=xZcRR7Lnd5ZDlDNW](https://youtu.be/YPTqKIgVk-k?si=xZcRR7Lnd5ZDlDNW)