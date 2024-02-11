# Sign of the Product of an Array

Problem: 1822
Official Difficulty: easy
Feels Like : easy
Topic: Math, array
Link: https://leetcode.com/problems/sign-of-the-product-of-an-array/description
Completed On : January 10, 2024
My Understanding: Fully Understand
Last Review: January 10, 2024
Days Since Review: 31

## Problem

---

There is a function `signFunc(x)` that returns:

- `1` if `x` is positive.
- `1` if `x` is negative.
- `0` if `x` is equal to `0`.

You are given an integer array `nums`. Let `product` be the product of all values in the array `nums`.

Return `signFunc(product)`.

**Example 1:**

```
Input: nums = [-1,-2,-3,-4,3,2,1]
Output: 1
Explanation: The product of all values in the array is 144, and signFunc(144) = 1

```

**Example 2:**

```
Input: nums = [1,5,0,2,-3]
Output: 0
Explanation: The product of all values in the array is 0, and signFunc(0) = 0

```

**Example 3:**

```
Input: nums = [-1,1,-1,1,-1]
Output: -1
Explanation: The product of all values in the array is -1, and signFunc(-1) = -1

```

**Constraints:**

- `1 <= nums.length <= 1000`
- `100 <= nums[i] <= 100`

## My Solutions

---

```python
class Solution:
    def arraySign(self, nums: List[int]) -> int:

        def signFunc(num):

            if num < 0 : 

                return -1

            elif num > 0 :

                return 1

            else : 

                return 0

        x = 1

        for num in nums :

            x *= num

        return signFunc(x)
```

```python

```

## Optimal Solutions

---

The optimal solution to this problem involves determining the sign of the product of all elements in the array `nums`. You don't actually need to compute the product due to potential overflow issues or unnecessary computational overhead. Instead, you can determine the sign by simply counting the number of negative numbers and checking for any zeroes in the array.

### Solution Approach

1. **Count Negative Numbers**: Iterate through the array and count the number of negative numbers.
2. **Check for Zero**: Also, check if there is any zero in the array.
3. **Determine the Sign of the Product**:
    - If there's a zero in the array, the product is zero, so return `0`.
    - If the count of negative numbers is odd, the product is negative, so return `1`.
    - Otherwise, the product is positive, so return `1`.

### Python Implementation

```python
class Solution:
    def arraySign(self, nums: List[int]) -> int:
        negative_count = 0
        for num in nums:
            if num == 0:
                return 0
            if num < 0:
                negative_count += 1

        return -1 if negative_count % 2 else 1

```

### Explanation

- The for loop iterates through each element in `nums`.
- If a zero is found, it immediately returns `0`.
- If a negative number is found, the `negative_count` is incremented.
- After the loop, if `negative_count` is odd, the product is negative, so it returns `1`.
- If `negative_count` is even, the product is positive, so it returns `1`.

### Complexity Analysis

- **Time Complexity**: O(n), where n is the number of elements in `nums`. The solution requires a single pass through the array.
- **Space Complexity**: O(1), as it uses a constant amount of space.

This solution efficiently determines the sign of the product of the array elements without calculating the actual product, thus avoiding potential overflow and reducing computational work.

### Leetcode 99.9% Solution

```jsx
class Solution:
    def arraySign(self, nums: List[int]) -> int:
        mul = 1
        for num in nums:
            mul *= num
        return mul // abs(mul) if mul != 0 else 0
```

## Notes

---

 

## Related Videos

---

[https://www.notion.so](https://www.notion.so)