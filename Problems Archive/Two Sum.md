# Two Sum

Problem: 1
Official Difficulty: easy
Topic: array, hash table
Link: https://leetcode.com/problems/two-sum/
Completed On : September 12, 2023
My Understanding: Fully Understand
Last Review: September 12, 2023
Days Since Review: 151

## Problem

---

Given an array of integers `nums` and an integer `target`, return *indices of the two numbers such that they add up to `target`*.

You may assume that each input would have ***exactly* one solution**, and you may not use the *same* element twice.

You can return the answer in any order.

**Example 1:**

```
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
```

**Example 2:**

```
Input: nums = [3,2,4], target = 6
Output: [1,2]
```

**Example 3:**

```
Input: nums = [3,3], target = 6
Output: [0,1]
```

## My Solutions

---

```python
class Solution(object):
    def twoSum(self, nums, target):

        result = []
        
        for i in range (0,len(nums)) :
            
            for index in range (1 , len(nums)) : 
                
                if i != index : 
                    
                    if nums [i] + nums [index] == target :
                        
                        result.append(i)
                        
                        result.append(index)
                    
                        return result
```

```python

```

## Optimal Solutions

---

The most optimal solution to the "Two Sum" problem you're describing is to use a hash table to store the indices of the elements as you iterate through the array. A hash table allows for constant time lookups on average, which makes the overall time complexity of the algorithm O(n), where n is the number of elements in the array.

Here's a step-by-step explanation:

1. **Initialize an empty dictionary (hash table)** to store the numbers from the array as keys and their indices as values.
2. **Iterate through the array once**. For each element:
    - Calculate the complement by subtracting the current element value from the target value.
    - Check if the complement is in the dictionary. If it is, return the current index along with the index stored for the complement in the dictionary, since together they add up to the target.
    - If the complement is not in the dictionary, add the current element's value and index to the dictionary.

Here's how you would implement it in Python:

```python
def two_sum(nums, target):
    prev_map = {}  # To store value:index pairs

    for i, num in enumerate(nums):
        # The complement is the number we need to find
        complement = target - num
        if complement in prev_map:
            # If complement is found, return the indices
            return [prev_map[complement], i]
        # Store the index of the current element
        prev_map[num] = i

    # Since the problem statement says there is exactly one solution,
    # the return statement will always be reached before the loop ends,
    # and the following return is for the sake of completeness.
    return []

```

This function will return the indices of the two numbers that add up to the target, and it will do so efficiently. The use of a hash table (`prev_map`) ensures that we can find the complement quickly without needing a nested loop to check for every possible pair.

## Notes

---

 

## Related Videos

---

[https://youtu.be/isGKzmwDREg?si=QylyqEkXrnZtEnqV](https://youtu.be/isGKzmwDREg?si=QylyqEkXrnZtEnqV)

[https://www.youtube.com/watch?v=KLlXCFG5TnA&t=3s](https://www.youtube.com/watch?v=KLlXCFG5TnA&t=3s)