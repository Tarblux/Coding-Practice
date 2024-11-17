Problem: 1213
Official Difficulty: easy
Link: https://leetcode.com/problems/intersection-of-three-sorted-arrays/description/?envType=weekly-question&envId=2024-11-08
Completed On : 2024-11-09
Feels Like : easy
Topic: array, hash table, binary search, Counting
My Understanding: Mostly Understand
Last Review: 2024-11-09
Days Since Review: 8
Name: Intersection of Three Sorted Arrays

# Intersection of Three Sorted Arrays
### Problem
___
Given three integer arrays `arr1`, `arr2` and `arr3` **sorted** in **strictly increasing** order, return a sorted array of **only** the integers that appeared in **all** three arrays.
**Example 1:**
```plain text
Input: arr1 = [1,2,3,4,5], arr2 = [1,2,5,7,9], arr3 = [1,3,4,5,8]
Output: [1,5]
Explanation:Only 1 and 5 appeared in the three arrays.
```
**Example 2:**
```plain text
Input: arr1 = [197,418,523,876,1356], arr2 = [501,880,1593,1710,1870], arr3 = [521,682,1337,1395,1764]
Output: []
```
**Constraints:**
- `1 <= arr1.length, arr2.length, arr3.length <= 1000`
- `1 <= arr1[i], arr2[i], arr3[i] <= 2000`
### My Solutions
___
```python
class Solution:
    def arraysIntersection(self, arr1: List[int], arr2: List[int], arr3: List[int]) -> List[int]:

        arr1 = set(arr1)
        arr2 = set(arr2)
        arr3 = set(arr3)

        output = list(arr1 & arr2 & arr3)

        return sorted(output)
```

Time Complexity :
```python

```

Time Complexity : 
### Optimal Solutions
___
To solve **LeetCode Problem 1213: Intersection of Three Sorted Arrays**, the most optimal algorithms leverage the fact that the arrays are sorted. Below are the efficient methods along with their time and space complexities.
___
#### **Algorithm 1: Three Pointers Approach**
**Algorithm Steps:**
1. **Initialize Pointers:**
	- Set pointers `i`, `j`, and `k` to `0`, representing the current indices in `arr1`, `arr2`, and `arr3`, respectively.
2. **Traverse the Arrays:**
	- While `i < len(arr1)` and `j < len(arr2)` and `k < len(arr3)`:
		- **If** `arr1[i] == arr2[j] == arr3[k]`:
			- **Append** `arr1[i]` to the result list.
			- **Increment** `i`, `j`, and `k` by `1`.
		- **Else:**
			- **Find** the smallest among `arr1[i]`, `arr2[j]`, and `arr3[k]`.
			- **Increment** the pointer(s) that point to the smallest value(s).
			- This ensures we skip over smaller elements to catch up with the larger ones.
3. **Return the Result:**
	- After the traversal, return the result list containing the common elements.
**Code Example:**
```python
def arraysIntersection(arr1, arr2, arr3):
    result = []
    i = j = k = 0
    while i < len(arr1) and j < len(arr2) and k < len(arr3):
        # If all elements are equal, add to result and move all pointers
        if arr1[i] == arr2[j] == arr3[k]:
            result.append(arr1[i])
            i += 1
            j += 1
            k += 1
        else:
            # Find the smallest value among the three arrays
            min_val = min(arr1[i], arr2[j], arr3[k])
            # Increment pointers for arrays with the smallest value
            if arr1[i] == min_val:
                i += 1
            if arr2[j] == min_val:
                j += 1
            if arr3[k] == min_val:
                k += 1
    return result

```
**Time Complexity:** O(n)
- **Explanation:**
	- Each array is traversed at most once.
	- The total number of iterations is proportional to the length of the longest array.
**Space Complexity:** O(n)
- **Explanation:**
	- The result list stores up to `n` elements, where `n` is the number of common elements.
	- Additional space used by variables is negligible.
___
#### **Alternative Algorithm: Set Intersection Approach**
**Algorithm Steps:**
4. **Convert Arrays to Sets:**
	- Convert `arr1`, `arr2`, and `arr3` to sets `set1`, `set2`, and `set3`.
5. **Find Intersection:**
	- Compute the intersection of the three sets:
```python
intersection = set1 & set2 & set3

```
6. **Return Sorted Result:**
	- Since the arrays are sorted, return the sorted list of the intersection:
```python
result = sorted(list(intersection))

```
**Code Example:**
```python
def arraysIntersection(arr1, arr2, arr3):
    set1 = set(arr1)
    set2 = set(arr2)
    set3 = set(arr3)
    intersection = set1 & set2 & set3
    return sorted(list(intersection))

```
**Time Complexity:** O(n log n)
- **Explanation:**
	- Converting lists to sets is O(n) for each array.
	- Computing the intersection is O(min(n1, n2, n3)) on average.
	- Sorting the result takes O(k log k), where `k` is the number of common elements.
	- Overall, due to the sorting step, the time complexity is O(n log n).
**Space Complexity:** O(n)
- **Explanation:**
	- Sets store up to `n` elements.
	- The result list stores up to `n` elements.
___
#### **Comparison and Recommendation**
- **Three Pointers Approach (Algorithm 1):**
	- **Pros:**
		- Optimal time complexity O(n).
		- Leverages the fact that arrays are sorted.
		- No need to sort the result.
	- **Cons:**
		- Slightly more complex to implement compared to set operations.
- **Set Intersection Approach (Algorithm 2):**
	- **Pros:**
		- Simple to implement.
		- Useful when arrays are not sorted.
	- **Cons:**
		- Time complexity is higher due to the sorting step.
		- Not leveraging the sorted nature of the arrays.
**Recommendation:**
- The **Three Pointers Approach** is the most optimal solution for this problem. It takes advantage of the sorted arrays to achieve linear time complexity without additional sorting.
___
**Final Code Solution (Algorithm 1):**
```python
class Solution:
    def arraysIntersection(self, arr1: List[int], arr2: List[int], arr3: List[int]) -> List[int]:
        result = []
        i = j = k = 0
        while i < len(arr1) and j < len(arr2) and k < len(arr3):
            # If all elements are equal, add to result and move all pointers
            if arr1[i] == arr2[j] == arr3[k]:
                result.append(arr1[i])
                i += 1
                j += 1
                k += 1
            else:
                # Find the smallest value among the three arrays
                min_val = min(arr1[i], arr2[j], arr3[k])
                # Increment pointers for arrays with the smallest value
                if arr1[i] == min_val:
                    i += 1
                if arr2[j] == min_val:
                    j += 1
                if arr3[k] == min_val:
                    k += 1
        return result

```
**Time Complexity:** O(n)
**Space Complexity:** O(n)
___
By using the Three Pointers Approach, we efficiently find the intersection of three sorted arrays in linear time, which is optimal for this problem.
### Notes
___
 
### Related Videos 
___
[]()