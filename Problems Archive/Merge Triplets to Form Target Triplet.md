<<<<<<< Updated upstream
Problem: 1899
Official Difficulty: medium
Link: https://leetcode.com/problems/merge-triplets-to-form-target-triplet/description/
Completed On : 2024-12-16
Feels Like : medium
Topic: array, greedy
My Understanding: Mostly Understand
Last Review: 2024-12-16
Days Since Review: 6
Name: Merge Triplets to Form Target Triplet

# Merge Triplets to Form Target Triplet
### Problem
___
A **triplet** is an array of three integers. You are given a 2D integer array `triplets`, where `triplets[i] = [ai, bi, ci]` describes the `ith` **triplet**. You are also given an integer array `target = [x, y, z]` that describes the **triplet** you want to obtain.
To obtain `target`, you may apply the following operation on `triplets` **any number** of times (possibly **zero**):
- Choose two indices (**0-indexed**) `i` and `j` (`i != j`) and **update** `triplets[j]` to become `[max(ai, aj), max(bi, bj), max(ci, cj)]`.
	- For example, if `triplets[i] = [2, 5, 3]` and `triplets[j] = [1, 7, 5]`, `triplets[j]` will be updated to `[max(2, 1), max(5, 7), max(3, 5)] = [2, 7, 5]`.
Return `true` *if it is possible to obtain the *`target`* ****triplet**** *`[x, y, z]`* as an**** element**** of *`triplets`*, or *`false`* otherwise*.
**Example 1:**
```plain text
=======
# Merge Triplets to Form Target Triplet

Problem: 1899
Official Difficulty: medium
Feels Like : medium
My Understanding: Mostly Understand
Topic: array, greedy
Link: https://leetcode.com/problems/merge-triplets-to-form-target-triplet/description/
Completed On : December 16, 2024
Last Review: December 16, 2024
Days Since Review: 76
Neetcode: Yes

## Problem

---

A **triplet** is an array of three integers. You are given a 2D integer array `triplets`, where `triplets[i] = [ai, bi, ci]` describes the `ith` **triplet**. You are also given an integer array `target = [x, y, z]` that describes the **triplet** you want to obtain.

To obtain `target`, you may apply the following operation on `triplets` **any number** of times (possibly **zero**):

- Choose two indices (**0-indexed**) `i` and `j` (`i != j`) and **update** `triplets[j]` to become `[max(ai, aj), max(bi, bj), max(ci, cj)]`.
    - For example, if `triplets[i] = [2, 5, 3]` and `triplets[j] = [1, 7, 5]`, `triplets[j]` will be updated to `[max(2, 1), max(5, 7), max(3, 5)] = [2, 7, 5]`.

Return `true` *if it is possible to obtain the* `target` ***triplet*** `[x, y, z]` *as an **element** of* `triplets`*, or* `false` *otherwise*.

**Example 1:**

```
>>>>>>> Stashed changes
Input: triplets = [[2,5,3],[1,8,4],[1,7,5]], target = [2,7,5]
Output: true
Explanation: Perform the following operations:
- Choose the first and last triplets [[2,5,3],[1,8,4],[1,7,5]]. Update the last triplet to be [max(2,1), max(5,7), max(3,5)] = [2,7,5]. triplets = [[2,5,3],[1,8,4],[2,7,5]]
The target triplet [2,7,5] is now an element of triplets.

```
<<<<<<< Updated upstream
**Example 2:**
```plain text
=======

**Example 2:**

```
>>>>>>> Stashed changes
Input: triplets = [[3,4,5],[4,5,6]], target = [3,2,5]
Output: false
Explanation: It is impossible to have [3,2,5] as an element because there is no 2 in any of the triplets.

```
<<<<<<< Updated upstream
**Example 3:**
```plain text
=======

**Example 3:**

```
>>>>>>> Stashed changes
Input: triplets = [[2,5,3],[2,3,4],[1,2,5],[5,2,3]], target = [5,5,5]
Output: true
Explanation:Perform the following operations:
- Choose the first and third triplets [[2,5,3],[2,3,4],[1,2,5],[5,2,3]]. Update the third triplet to be [max(2,1), max(5,2), max(3,5)] = [2,5,5]. triplets = [[2,5,3],[2,3,4],[2,5,5],[5,2,3]].
- Choose the third and fourth triplets [[2,5,3],[2,3,4],[2,5,5],[5,2,3]]. Update the fourth triplet to be [max(2,5), max(5,2), max(5,3)] = [5,5,5]. triplets = [[2,5,3],[2,3,4],[2,5,5],[5,5,5]].
The target triplet [5,5,5] is now an element of triplets.

```
<<<<<<< Updated upstream
**Constraints:**
- `1 <= triplets.length <= 105`
- `triplets[i].length == target.length == 3`
- `1 <= ai, bi, ci, x, y, z <= 1000`
### My Solutions
___
=======

**Constraints:**

- `1 <= triplets.length <= 105`
- `triplets[i].length == target.length == 3`
- `1 <= ai, bi, ci, x, y, z <= 1000`

## My Solutions

---

>>>>>>> Stashed changes
```python
class Solution:
    def mergeTriplets(self, triplets: List[List[int]], target: List[int]) -> bool:
        
        def validTriplet(triplet):

            for i in range(3):
                if triplet[i] > target[i]:
                    return False

            return True

        output = [0]*3

        for triplet in triplets:

            if validTriplet(triplet):
                for i in range(3):
                    if triplet[i] == target[i]:
                        output[i] = 1

            if all(output):
                return True

        return False
```

<<<<<<< Updated upstream
Time Complexity :
Aleks
=======
Aleks

>>>>>>> Stashed changes
```python
class Solution:
    def mergeTriplets(self, triplets: List[List[int]], target: List[int]) -> bool:

        def merge(t1, t2):
            return [max(t1[0], t2[0]), max(t1[1], t2[1]), max(t1[2], t2[2])]
        
        res = [1, 1, 1]
        for triplet in triplets:
            if triplet[0] <= target[0] and triplet[1] <= target[1] and triplet[2] <= target[2]:
                res = merge(res, triplet)
            if res == target:
                return True
        
        return False

```

<<<<<<< Updated upstream
Time Complexity : 
### Optimal Solutions
___

### Notes
___
 Kinda just first making sure none of their values will break anything elsewhere and then just checking each of them to see if they can contribute to the answer 
### Related Videos 
___
[]()
=======
## Optimal Solutions

---

## Notes

---

 Kinda just first making sure none of their values will break anything elsewhere and then just checking each of them to see if they can contribute to the answer 

## Related Videos

---

[https://www.notion.so](https://www.notion.so)
>>>>>>> Stashed changes
