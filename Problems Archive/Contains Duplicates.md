# Contains Duplicates

Problem: 217
Official Difficulty: easy
Topic: array, hash table, sorting
Link: https://leetcode.com/problems/contains-duplicate/description/
Completed On : January 7, 2024
My Understanding: Mostly Understand
Last Review: January 7, 2024
Days Since Review: 34

## Problem

---

Given an integer array `nums`, return `true` if any value appears **at least twice** in the array, and return `false` if every element is distinct.

## My Solutions

---

```python
class Solution(object):
    def containsDuplicate(self, nums):
        
        
        dict = {}
        
        for num in nums : 
            
            if num not in dict :
            
                dict[num] = 1
                     
            else : 
              
                dict[num] += 1
            
        
        for val in dict.values() : 
            
            if val > 1 :
            
                return True

        
        return False
```

```python

```

## Optimal Solutions

---

To solve this problem efficiently, we can use a data structure that allows for fast lookups to check if we've already encountered a particular value. The most suitable data structure for this purpose is a `set`. A `set` in many programming languages, including Python, stores unique elements and allows for constant time complexity (O(1)) for element lookup.

Here's the approach:

1. Create an empty `set`.
2. Iterate through each element in the `nums` array.
3. For each element, check if it is already in the `set`.
    - If it is, return `true` because we've found a duplicate.
    - If it isn't, add the element to the `set`.
4. If the loop completes without finding any duplicates, return `false`.

This algorithm has a time complexity of O(n), where n is the number of elements in the array, since we need to iterate through each element once. The space complexity is also O(n) in the worst case, as we might need to store each unique element in the `set`.

Now, let's implement this in Python:

```python
def containsDuplicate(nums):
    seen = set()
    for num in nums:
        if num in seen:
            return True
        seen.add(num)
    return False

# Example usage
nums = [1, 2, 3, 1]
print(containsDuplicate(nums))  # This should return True as 1 appears more than once
```

In this code:

- `seen` is a `set` that keeps track of the unique elements we've encountered.
- We iterate through `nums`, and for each `num`, we check if it's already in `seen`.
- If `num` is in `seen`, we return `True`. If not, we add `num` to `seen`.
- If the loop finishes without finding duplicates, we return `False`.

## Notes

---

Aleksandr pointed out that with flow control once you return a value within function then the execution stops 

## Related Videos

---

[https://youtu.be/0hF1lWsxPGU?si=Dfe8LGckzcfGP-FC](https://youtu.be/0hF1lWsxPGU?si=Dfe8LGckzcfGP-FC)

[https://www.youtube.com/watch?v=3OamzN90kPg](https://www.youtube.com/watch?v=3OamzN90kPg)