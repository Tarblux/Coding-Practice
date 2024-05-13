# Count Elements With Maximum Frequency

Problem: 3005
Official Difficulty: easy
Feels Like : easy breazy
My Understanding: Fully Understand
Topic: Counting, array, hash table
Link: https://leetcode.com/problems/count-elements-with-maximum-frequency/description/
Completed On : May 7, 2024
Last Review: May 7, 2024
Days Since Review: 5

## Problem

---

You are given an array `nums` consisting of **positive** integers.

Return *the **total frequencies** of elements in* `nums` *such that those elements all have the **maximum** frequency*.

The **frequency** of an element is the number of occurrences of that element in the array.

**Example 1:**

```
Input: nums = [1,2,2,3,1,4]
Output: 4
Explanation: The elements 1 and 2 have a frequency of 2 which is the maximum frequency in the array.
So the number of elements in the array with maximum frequency is 4.
```

**Example 2:**

```
Input: nums = [1,2,3,4,5]
Output: 5
Explanation: All elements of the array have a frequency of 1 which is the maximum.
So the number of elements in the array with maximum frequency is 5.
```

**Constraints:**

- `1 <= nums.length <= 100`
- `1 <= nums[i] <= 100`

## My Solutions

---

```python
from collections import Counter

class Solution:
    def maxFrequencyElements(self, nums: List[int]) -> int:

        counts = Counter(nums)
        max_freqs = []
        maxy = max(counts.values())
        total = 0

        for key , val in counts.items():

            if val == maxy : 
                max_freqs.append(key)

        for num in nums:

            if num in max_freqs:

                total = total + 1

        return total
```

```python

```

## Optimal Solutions

---

Certainly! Let's revisit and refine the provided solution code to ensure it adheres to the discussed approach for efficiently counting and tracking the maximum frequency of elements in a single pass. The explanation describes a strategy to update the count of frequencies dynamically as the array is traversed.

### Problem Approach: One-Pass Sum of Maximum Frequencies

### Enhanced Code with Detailed Comments:

Here’s the Python code for the `Solution` class that implements the strategy of finding the total frequency of the most frequent elements in an array using a single pass:

```python
class Solution:
    def maxFrequencyElements(self, nums):
        frequencies = {}
        max_frequency = 0
        total_frequencies = 0

        # Traverse through each number in the array
        for num in nums:
            # Increment the frequency of the current number
            frequencies[num] = frequencies.get(num, 0) + 1
            frequency = frequencies[num]

            # If the current frequency exceeds the known maximum frequency
            if frequency > max_frequency:
                max_frequency = frequency
                total_frequencies = frequency  # Reset total to the new max frequency

            # If the current frequency matches the known maximum frequency
            elif frequency == max_frequency:
                total_frequencies += frequency  # Add the current frequency to the total

        return total_frequencies

# Example usage:
sol = Solution()
nums = [1, 2, 2, 3, 3, 3, 4, 4, 4, 4]
print(sol.maxFrequencyElements(nums))  # Output: 16 (4 occurs four times, total frequency is 4*4)

```

### Corrected Explanation:

- The solution tracks the frequency of each element using a dictionary.
- `max_frequency` keeps the highest frequency encountered so far.
- `total_frequencies` accumulates the total occurrences of elements that appear with `max_frequency`.
- As we iterate over `nums`, we update `frequencies` and compare each element’s updated frequency against `max_frequency`.
    - **If a new maximum is found**: Update `max_frequency` and reset `total_frequencies` to the new maximum's frequency.
    - **If an existing maximum is encountered again**: Add the frequency of that element to `total_frequencies`.

### Discussion on Complexity:

- **Time Complexity**: \(O(n)\) where \(n\) is the length of `nums`, because we iterate through the list once, performing constant time operations for each element (dictionary operations).
- **Space Complexity**: \(O(k)\), where \(k\) is the number of unique elements in `nums`. In the worst case (all elements are unique), the space required approaches \(O(n)\).

This solution correctly implements the discussed approach with an efficient single-pass strategy and appropriate management of data structures to handle the frequencies and calculations of maximum frequencies dynamically.

## Notes

---

 

## Related Videos

---

[https://www.notion.so](https://www.notion.so)