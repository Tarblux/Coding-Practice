Problem: 904
Official Difficulty: medium
Link: https://leetcode.com/problems/fruit-into-baskets/description/
Completed On : 2024-12-12
Feels Like : medium
Topic: sliding window, two pointers, greedy
My Understanding: Fully Understand
Last Review: 2024-12-12
Days Since Review: 3
Name: Fruits Into Baskets

# Fruits Into Baskets
### Problem
___
You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array `fruits` where `fruits[i]` is the **type** of fruit the `ith` tree produces.
You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:
- You only have **two** baskets, and each basket can only hold a **single type** of fruit. There is no limit on the amount of fruit each basket can hold.
- Starting from any tree of your choice, you must pick **exactly one fruit** from **every** tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.
- Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
Given the integer array `fruits`, return *the ****maximum**** number of fruits you can pick*.
**Example 1:**
```plain text
Input: fruits = [1,2,1]
Output: 3
Explanation: We can pick from all 3 trees.
```
**Example 2:**
```plain text
Input: fruits = [0,1,2,2]
Output: 3
Explanation: We can pick from trees [1,2,2].
If we had started at the first tree, we would only pick from trees [0,1].
```
**Example 3:**
```plain text
Input: fruits = [1,2,3,2,2]
Output: 4
Explanation: We can pick from trees [2,3,2,2].
If we had started at the first tree, we would only pick from trees [1,2].
```
**Constraints:**
- `1 <= fruits.length <= 105`
- `0 <= fruits[i] < fruits.length`
### My Solutions
___
```python
class Solution:
    def totalFruit(self, fruits: List[int]) -> int:

        max_basket = float('-inf')
        total_fruits = start = 0
        baskets = {}

        for end in range(len(fruits)):

            if fruits[end] not in baskets:
                baskets[fruits[end]] = 0

            baskets[fruits[end]] += 1
            

            while len(baskets) > 2:

                baskets[fruits[start]] -= 1

                if baskets[fruits[start]] == 0:
                    baskets.pop(fruits[start])

                start += 1

            max_basket = max(end - start + 1, max_basket)
            

        return max_basket

 
        
```

Time Complexity :
```python

```

Time Complexity : 
### Optimal Solutions
___
```python
def fruit_into_baskets(fruits):
  start = 0
  state = {}
  max_fruit = 0

  for end in range(len(fruits)):
    state[fruits[end]] = state.get(fruits[end], 0) + 1

    while len(state) > 2:
      state[fruits[start]] -= 1
      if state[fruits[start]] == 0:
        del state[fruits[start]]
      start += 1

    max_fruit = max(max_fruit, end - start + 1)

  return max_fruit
```
### Notes
___
 
### Related Videos 
___
[]()