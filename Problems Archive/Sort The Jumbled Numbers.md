# Sort The Jumbled Numbers

Problem: 2191
Official Difficulty: medium
Feels Like : easy
My Understanding: Fully Understand
Topic: array, sorting
Link: https://leetcode.com/problems/sort-the-jumbled-numbers/description/
Completed On : July 26, 2024
Last Review: July 26, 2024
Days Since Review: 14

## Problem

---

You are given a **0-indexed** integer array `mapping` which represents the mapping rule of a shuffled decimal system. `mapping[i] = j` means digit `i` should be mapped to digit `j` in this system.

The **mapped value** of an integer is the new integer obtained by replacing each occurrence of digit `i` in the integer with `mapping[i]` for all `0 <= i <= 9`.

You are also given another integer array `nums`. Return *the array* `nums` *sorted in **non-decreasing** order based on the **mapped values** of its elements.*

**Notes:**

- Elements with the same mapped values should appear in the **same relative order** as in the input.
- The elements of `nums` should only be sorted based on their mapped values and **not be replaced** by them.

**Example 1:**

```
Input: mapping = [8,9,4,0,2,1,3,5,7,6], nums = [991,338,38]
Output: [338,38,991]
Explanation:
Map the number 991 as follows:
1. mapping[9] = 6, so all occurrences of the digit 9 will become 6.
2. mapping[1] = 9, so all occurrences of the digit 1 will become 9.
Therefore, the mapped value of 991 is 669.
338 maps to 007, or 7 after removing the leading zeros.
38 maps to 07, which is also 7 after removing leading zeros.
Since 338 and 38 share the same mapped value, they should remain in the same relative order, so 338 comes before 38.
Thus, the sorted array is [338,38,991].
```

**Example 2:**

```
Input: mapping = [0,1,2,3,4,5,6,7,8,9], nums = [789,456,123]
Output: [123,456,789]
Explanation: 789 maps to 789, 456 maps to 456, and 123 maps to 123. Thus, the sorted array is [123,456,789].
```

**Constraints:**

- `mapping.length == 10`
- `0 <= mapping[i] <= 9`
- All the values of `mapping[i]` are **unique**.
- `1 <= nums.length <= 3 * 104`
- `0 <= nums[i] < 109`

## My Solutions

---

```python
class Solution:

    def converter(self,mapping,num):

        if num == 0:
            return mapping[0]
        
        multiplier = 1
        value = 0
        while num :

            digit  = num % 10
            cur_val = mapping[digit]
            value += cur_val * multiplier
            num //= 10
            multiplier *= 10

        return value

    def sortJumbled(self, mapping: List[int], nums: List[int]) -> List[int]:

        nums.sort(key= lambda x : self.converter(mapping,x))

        return nums
```

```python

```

## Optimal Solutions

---

### Problem Description

Given two arrays `mapping` and `nums` where:

- `mapping` is a permutation of the digits 0-9.
- `nums` is a list of non-negative integers.

Sort the array `nums` such that the relative order is determined by the value of each integer when mapped according to `mapping`.

### Example

```python
Input: mapping = [8,9,4,0,2,1,3,5,7,6], nums = [990, 332, 981]
Output: [981, 990, 332]
```

### Solution Approach

1. **Map Each Number**: Convert each number in `nums` to its mapped value using `mapping`.
2. **Sort Based on Mapped Values**: Sort the numbers based on their mapped values.
3. **Return the Sorted Numbers**: Return the sorted array based on the mapped values.

### Python Code

Here's the Python code to achieve this:

```python
from typing import List

class Solution:
    def sortJumbled(self, mapping: List[int], nums: List[int]) -> List[int]:
        def map_value(num: int) -> int:
            mapped_digits = [str(mapping[int(digit)]) for digit in str(num)]
            return int(''.join(mapped_digits))

        # Pair each number with its mapped value
        mapped_nums = [(map_value(num), num) for num in nums]

        # Sort based on the mapped values
        mapped_nums.sort()

        # Extract the sorted original numbers
        return [num for _, num in mapped_nums]

# Example usage
sol = Solution()
print(sol.sortJumbled([8,9,4,0,2,1,3,5,7,6], [990, 332, 981]))  # Output: [981, 990, 332]
print(sol.sortJumbled([0,1,2,3,4,5,6,7,8,9], [990, 332, 981]))  # Output: [332, 981, 990]
```

### Explanation

1. **Mapping Function**:
    - The `map_value` function takes an integer `num`, converts it to a string to iterate over its digits, maps each digit according to `mapping`, and joins the mapped digits back into a string before converting it back to an integer.
2. **Pairing Numbers with Mapped Values**:
    - `mapped_nums = [(map_value(num), num) for num in nums]` creates a list of tuples where each tuple contains the mapped value and the original number.
3. **Sorting**:
    - `mapped_nums.sort()` sorts the tuples primarily by the mapped value.
4. **Extracting Sorted Numbers**:
    - `[num for _, num in mapped_nums]` extracts the original numbers from the sorted list of tuples, giving the final sorted list.

### Time Complexity Analysis

- **Time Complexity**: `O(n log n)`
    - The mapping operation for each number takes `O(d)` where `d` is the number of digits in the number. This is typically considered constant compared to `n`, the number of numbers.
    - Sorting the list of tuples takes `O(n log n)`.
- **Space Complexity**: `O(n)`
    - Space is required to store the list of tuples and the final sorted list.

This solution efficiently sorts the jumbled numbers based on the provided digit mapping.

## Notes

---

 

## Related Videos

---

[https://www.notion.so](https://www.notion.so)