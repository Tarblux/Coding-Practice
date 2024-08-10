# Intersection Of Two Arrays II

Problem: 350
Official Difficulty: easy
Feels Like : easy
My Understanding: Fully Understand
Topic: binary search, hash table, sorting, two pointers
Link: https://leetcode.com/problems/intersection-of-two-arrays-ii/description/
Completed On : November 11, 2023
Last Review: July 1, 2024
Days Since Review: 39

## Problem

---

Given two integer arrays `nums1` and `nums2`, return *an array of their intersection*. Each element in the result must appear as many times as it shows in both arrays and you may return the result in **any order**.

**Example 1:**

```
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
```

**Example 2:**

```
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Explanation: [9,4] is also accepted.
```

## My Solutions

---

```python
class Solution(object):
    def intersect(self, nums1, nums2):
        
            
        nums1_dict = {}
        
        nums2_dict = {}
        
        result = []
        
        for num in nums1 : 
            
            if num not in nums1_dict :
                
                nums1_dict[num] = 1
                
            else : 
                
                nums1_dict[num] += 1
        
        
        for num in nums2 : 
            
            if num not in nums2_dict :
                
                nums2_dict[num] = 1
                
            else : 
                
                nums2_dict[num] += 1
                
                
        common_keys = set(nums1_dict.keys()).intersection(nums2_dict.keys()) 
        
        for key in common_keys : 

            val_1 = nums1_dict[key]
            val_2 = nums2_dict[key]

            i = min(val_1, val_2)

            for val in range (0,i) :

                result.append(key)

        return result
```

```python
class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:

        n1 = defaultdict(int)
        n2 = defaultdict(int)

        for num in nums1:
            n1[num] += 1

        for num in nums2:
            n2[num] += 1

        output = []

        for num in n1:
            if num in n2:
                cur = [num]*min(n1[num],n2[num])
                output.extend(cur)

        return output

 
```

## Optimal Solutions

---

### Solution W/ Native Python

1. **Count Occurrences in the First Array**: We'll use a dictionary to count occurrences of each element in the first array (`nums1`).
2. **Iterate Through the Second Array**: As we iterate through the second array (`nums2`), we check if the element is in our dictionary and if its count is greater than 0. If so, we add it to the intersection and decrease its count in the dictionary.

Here's the implementation:

```python
def intersect(nums1, nums2):
    nums1_dict = {}
    intersection = []

    # Count occurrences in nums1
    for num in nums1:
        if num in nums1_dict:
            nums1_dict[num] += 1
        else:
            nums1_dict[num] = 1

    # Find intersection
    for num in nums2:
        if num in nums1_dict and nums1_dict[num] > 0:
            intersection.append(num)
            nums1_dict[num] -= 1

    return intersection

# Test the function with the given examples
print(intersect([1, 2, 2, 1], [2, 2]))  # Output: [2, 2]
print(intersect([4, 9, 5], [9, 4, 9, 8, 4]))  # Output: [4, 9] or [9, 4]

```

In this solution:

- We manually create and update a dictionary (`nums1_dict`) to count occurrences of each element in `nums1`.
- We then iterate over `nums2`, adding each number to the intersection list if it's found in `nums1_dict` and its count is greater than 0.
- The order of elements in the output list is based on their order in `nums2`, and it will include duplicates if they appear in both arrays.

---

### Solution W/ Library Import

Only use this as a basis of “seeming more knowledgable” , this kinda skips the heart of the question so typically steer away.

To solve this problem, we can use a dictionary (or a `collections.Counter` object in Python) to count the occurrences of each number in one of the arrays. Then, we iterate through the second array and check if the number exists in our dictionary. If it does, we add it to the result and decrease its count in the dictionary. This approach ensures that each element in the result appears as many times as it shows in both arrays.

Here's the implementation in Python:

```python
from collections import Counter

def intersect(nums1, nums2):
    counts = Counter(nums1)
    intersection = []

    for num in nums2:
        if counts[num] > 0:
            intersection.append(num)
            counts[num] -= 1

    return intersection

# Test the function with the given examples
print(intersect([1, 2, 2, 1], [2, 2]))  # Output: [2, 2]
print(intersect([4, 9, 5], [9, 4, 9, 8, 4]))  # Output: [4, 9] or [9, 4]

```

In this code:

- We use `Counter(nums1)` to create a dictionary that maps each number in `nums1` to its count.
- We then iterate over `nums2`. For each number in `nums2`, if it is found in the counts dictionary and its count is greater than 0, we add it to the `intersection` list and decrease its count by 1.
- This process ensures that each element is added to the intersection list only as many times as it appears in both arrays.
- The order of elements in the intersection list doesn't matter as per the problem statement.

## Notes

---

 

## Related Videos

---

[https://www.youtube.com/watch?v=ctOkl71esQg](https://www.youtube.com/watch?v=ctOkl71esQg)