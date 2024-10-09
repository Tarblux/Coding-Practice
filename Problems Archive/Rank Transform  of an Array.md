Problem: 1331
Official Difficulty: easy
Link: https://leetcode.com/problems/rank-transform-of-an-array/description/
Completed On : 2024-10-02
Feels Like : medium
Topic: array, hash table, sorting
My Understanding: Fully Understand
Last Review: 2024-10-02
Days Since Review: 7
Name: Rank Transform  of an Array

# Rank Transform  of an Array
### Problem
___
Given an array of integers `arr`, replace each element with its rank.
The rank represents how large the element is. The rank has the following rules:
- Rank is an integer starting from 1.
- The larger the element, the larger the rank. If two elements are equal, their rank must be the same.
- Rank should be as small as possible.
**Example 1:**
```plain text
Input: arr = [40,10,20,30]
Output: [4,1,2,3]
Explanation: 40 is the largest element. 10 is the smallest. 20 is the second smallest. 30 is the third smallest.
```
**Example 2:**
```plain text
Input: arr = [100,100,100]
Output: [1,1,1]
Explanation: Same elements share the same rank.

```
**Example 3:**
```plain text
Input: arr = [37,12,28,9,100,56,80,5,12]
Output: [5,3,4,2,8,6,7,1,3]

```
**Constraints:**
- `0 <= arr.length <= 105`
- `109 <= arr[i] <= 109`
### My Solutions
___
```python
class Solution:
    def arrayRankTransform(self, arr: List[int]) -> List[int]:

        if not arr:
            return []
        elif len(arr) == 1:
            return [1]

        output = arr.copy()
        arr.sort()
        ranks = defaultdict(int)
        ranks[arr[0]] = 1
        rank = 1

        for i in range(1,len(arr)):

            if arr[i] == arr[i-1]:
                ranks[arr[i]] = rank
                continue
            rank += 1
            ranks[arr[i]] = rank

        for i in range(len(output)):
            output[i] = ranks[output[i]]

        return output
            



        
```

Time Complexity :
Certainly! Your current solution effectively solves the problem by assigning ranks to the elements of the array. However, there are a few ways to **optimize and simplify** your code:
1. **Avoid Modifying the Input Array:**
	- **Issue:** Your code sorts the input array `arr` in-place, which modifies the original array.
	- **Improvement:** Use a sorted copy of the array to avoid side effects.
2. **Use **`**set**`** to Remove Duplicates Before Sorting:**
	- **Benefit:** This reduces the number of elements to sort, improving efficiency when there are duplicate elements.
3. **Utilize Dictionary and List Comprehensions:**
	- **Benefit:** This makes the code more concise and potentially faster.
4. **Eliminate Unnecessary Checks:**
	- **Issue:** The initial checks for empty array and single-element array are unnecessary since the general logic handles these cases.
Here's the **improved code** incorporating these suggestions:
```python
class Solution:
    def arrayRankTransform(self, arr: List[int]) -> List[int]:
        # Create a sorted list of unique elements
        sorted_unique = sorted(set(arr))

        # Map each number to its rank
        rank_dict = {num: rank for rank, num in enumerate(sorted_unique, start=1)}

        # Replace each element in the original array with its rank
        return [rank_dict[num] for num in arr]

```
**Explanation:**
- **Line 3:** We create a sorted list of unique elements using `sorted(set(arr))`. This step has a time complexity of O(n log n), where n is the number of unique elements.
- **Line 6:** We use a dictionary comprehension to map each unique number to its rank. The `enumerate` function assigns ranks starting from 1.
- **Line 9:** We construct the output array by replacing each element with its corresponding rank from `rank_dict`. This operation is O(n).
**Benefits of the Improved Code:**
- **Efficiency:** By removing duplicates before sorting, we potentially reduce the sorting time, especially when the array contains many duplicates.
- **Conciseness:** Using comprehensions makes the code shorter and more readable.
- **Avoids Side Effects:** We avoid modifying the input array `arr`, which is a good practice to prevent unintended consequences.
**Time and Space Complexity:**
- **Time Complexity:** O(n log n)
	- Creating the set is O(n).
	- Sorting the unique elements is O(k log k), where k ≤ n.
	- Mapping ranks and building the output array are both O(n).
- **Space Complexity:** O(n)
	- Storing the `rank_dict` and the output array requires O(n) space.
___
**Additional Notes:**
- **Edge Cases:** The improved code naturally handles empty arrays and single-element arrays without explicit checks.
- **Default Dictionaries:** Since we're mapping known keys, a regular dictionary suffices; using `defaultdict` is unnecessary.
___
**Example:**
Let's see how the improved code works with an example.
```python
arr = [40, 10, 20, 30, 20]

# Step 1: sorted_unique = [10, 20, 30, 40]
# Step 2: rank_dict = {10: 1, 20: 2, 30: 3, 40: 4}
# Step 3: output = [4, 1, 2, 3, 2]

```
**Result:**
```python
[4, 1, 2, 3, 2]

```
___
**Conclusion:**
By implementing these improvements, your solution becomes more efficient and clean while maintaining the same functionality. This approach is commonly used in problems that involve ranking or ordering elements based on their values.
### Optimal Solutions
___

### Notes
___
 
### Related Videos 
___
[]()