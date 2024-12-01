Problem: 1346
Official Difficulty: easy
Link: https://leetcode.com/problems/check-if-n-and-its-double-exist/description/?envType=daily-question&envId=2024-12-01
Completed On : 2024-11-30
Feels Like : medium
Topic: array, hash table, two pointers, binary search, sorting
My Understanding: Mostly Understand
Last Review: 2024-11-30
Days Since Review: 1
Name: Check If N and Its Double Exist

# Check If N and Its Double Exist
### Problem
___
Given an array `arr` of integers, check if there exist two indices `i` and `j` such that :
- `i != j`
- `0 <= i, j < arr.length`
- `arr[i] == 2 * arr[j]`
**Example 1:**
```plain text
Input: arr = [10,2,5,3]
Output: true
Explanation: For i = 0 and j = 2, arr[i] == 10 == 2 * 5 == 2 * arr[j]

```
**Example 2:**
```plain text
Input: arr = [3,1,7,11]
Output: false
Explanation: There is no i and j that satisfy the conditions.

```
**Constraints:**
- `2 <= arr.length <= 500`
- `103 <= arr[i] <= 103`
### My Solutions
___
```python
class Solution:
    def checkIfExist(self, arr: List[int]) -> bool:

        memo = {}

        for i in range(len(arr)):
            need = arr[i] * 2
            if need in memo or (arr[i] % 2 == 0 and arr[i]//2 in memo):
                return True
            memo[arr[i]] = 'Pani'

        return False
        
```

Time Complexity :
```python

```

Time Complexity : 
### Optimal Solutions
___
## LeetCode Problem 1346: Check If N and Its Double Exist
### Problem Description
Given an array `arr` of integers, check if there exist two integers **N** and **M** such that **N** is the double of **M** (i.e., `N = 2 * M`).
More formally, check whether there exist two indices `i` and `j` such that:
- `i != j`
- `0 <= i, j < arr.length`
- `arr[i] == 2 * arr[j]`
___
### Solution Overview
To solve this problem efficiently, we can use a hash set to keep track of the numbers we've seen so far. For each number in the array, we check if either its double or half (if it's even) exists in the set.
#### **Algorithm Steps**
1. **Initialize a Hash Set:**
	- Create a set `seen` to store the elements we've encountered.
	- Initialize a variable `zero_count` to count the number of zeros in the array.
2. **Iterate Over the Array:**
	- For each element `num` in `arr`:
		- **If **`**num**`** is zero:**
			- Increment `zero_count`.
			- If `zero_count` is at least 2, return `True` (since `0 == 2 * 0`).
		- **Else:**
			- Check if `2 * num` is in `seen` or if `num` is even and `num // 2` is in `seen`.
			- If either condition is `True`, return `True`.
		- Add `num` to `seen`.
3. **Return the Result:**
	- If no such pair is found after iterating through the array, return `False`.
___
### Code Implementation
```python
class Solution:
    def checkIfExist(self, arr: List[int]) -> bool:
        seen = set()
        zero_count = 0

        for num in arr:
            if num == 0:
                zero_count += 1
                if zero_count >= 2:
                    return True
            else:
                if (2 * num in seen) or (num % 2 == 0 and num // 2 in seen):
                    return True
            seen.add(num)
        return False

```
___
### Example Walkthrough
**Example 1:**
- **Input:** `arr = [10, 2, 5, 3]`
- **Process:**
	- Initialize `seen = {}`.
	- Iteration 1: `num = 10`
		- `2 * 10 = 20` not in `seen`.
		- `10` is even, `10 // 2 = 5` not in `seen`.
		- Add `10` to `seen` → `seen = {10}`.
	- Iteration 2: `num = 2`
		- `2 * 2 = 4` not in `seen`.
		- `2` is even, `2 // 2 = 1` not in `seen`.
		- Add `2` to `seen` → `seen = {2, 10}`.
	- Iteration 3: `num = 5`
		- `2 * 5 = 10` in `seen`.
		- Return `True`.
- **Output:** `True`
**Example 2:**
- **Input:** `arr = [7, 1, 14, 11]`
- **Process:**
	- Initialize `seen = {}`.
	- Iteration 1: `num = 7`
		- `2 * 7 = 14` not in `seen`.
		- `7` is odd.
		- Add `7` to `seen` → `seen = {7}`.
	- Iteration 2: `num = 1`
		- `2 * 1 = 2` not in `seen`.
		- `1` is odd.
		- Add `1` to `seen` → `seen = {1, 7}`.
	- Iteration 3: `num = 14`
		- `2 * 14 = 28` not in `seen`.
		- `14` is even, `14 // 2 = 7` in `seen`.
		- Return `True`.
- **Output:** `True`
___
### Complexity Analysis
#### **Time Complexity:** O(n)
- We iterate through the array once.
- All operations inside the loop are O(1).
- Total time complexity is linear with respect to the length of `arr`.
#### **Space Complexity:** O(n)
- In the worst case, we store all elements of `arr` in the `seen` set.
- Space complexity is linear with respect to the length of `arr`.
___
### Explanation
- **Handling Zeroes:**
	- Since `0 == 2 * 0`, we need to check if there are at least two zeros in the array.
	- We use `zero_count` to keep track of the number of zeros.
	- If `zero_count` reaches 2, we return `True`.
- **Non-Zero Elements:**
	- For each non-zero `num`, we check:
		- If `2 * num` is in `seen` (someone else's double equals `num`).
		- If `num` is even and `num // 2` is in `seen` (someone else's half equals `num`).
	- If either condition is met, we return `True`.
- **Set **`**seen**`**:**
	- We add `num` to `seen` after the checks to ensure we don't compare `num` with itself unless it's zero.
___
### Edge Cases
- **Multiple Zeros:**
	- If the array contains at least two zeros, the condition `arr[i] == 2 * arr[j]` is satisfied for zeros.
- **Negative Numbers:**
	- The algorithm works correctly with negative numbers due to the properties of multiplication and division.
___
### Conclusion
By using a hash set for constant-time lookups, we can efficiently solve the problem in linear time. The key is to carefully handle zeros and check for both double and half of each number in the array.
### Notes
___
 
### Related Videos 
___
[]()