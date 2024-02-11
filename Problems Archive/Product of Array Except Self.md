# Product of Array Except Self

Problem: 238
Official Difficulty: medium
Feels Like : medium
Topic: Prefix Product, Suffix Product, array
Link: https://leetcode.com/problems/product-of-array-except-self/
Completed On : December 14, 2023
My Understanding: Needs Review
Last Review: December 14, 2023
Days Since Review: 58

## Problem

---

Given an integer array `nums`, return *an array* `answer` *such that* `answer[i]` *is equal to the product of all the elements of* `nums` *except* `nums[i]`.

The product of any prefix or suffix of `nums` is **guaranteed** to fit in a **32-bit** integer.

You must write an algorithm that runs in `O(n)` time and without using the division operation.

## My Solutions

---

```python
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:

        output = [1] * len(nums)

        left = [1] * len(nums)

        left[0] = nums[0]

        right = [1] * len(nums)

        right[-1] = nums[-1]

        l = 1

        r = len(nums) - 2

        for i in range(1,len(nums)) : 

            left[i] = nums[l] * left[i-1] 

            l += 1

        for i in range(len(nums)-2 , -1 , -1) : 

            right[i] = nums[r] * right[i+1]

            r -= 1

        output[0] = right[1]

        output[-1] = left[-2]

        for i in range(1,len(nums)-1) : 

            output[i] =  left[i-1] * right[i+1]

        return output
```

### Sanya

```python
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:

        left = [1] * len(nums)
        right = [1] * len(nums)

        left[0] = nums[0]
        for i, num in enumerate(nums): 
           left[i] = left[i - 1] * num

        right[len(nums)-1] = nums[len(nums)-1]
        for i in range(len(nums) - 2, -1, -1):       
            right[i] = right[i + 1] * nums[i]

        result = [1] * len(nums)

        result[0] = right[1]
        result[len(result) - 1] = left[len(result) - 2]
        for i in range(1, len(result) - 1):
            result[i] = left[i - 1] * right[i + 1]

        return result
```

## Optimal Solutions

---

The "Product of Array Except Self" problem requires you to find an array output such that `output[i]` is equal to the product of all the elements of the input array except `nums[i]`. You must solve it without using division and in O(n) time complexity.

### Solution Approach

A common approach is to use two arrays to hold the products of all the numbers to the left and to the right of each index. Then, for each position in the output array, you multiply the left and right products.

1. **Left Products**: Iterate from the beginning of the input array and calculate the running product of all elements to the left of each index.
2. **Right Products**: Similarly, iterate from the end of the input array and calculate the running product of all elements to the right of each index.
3. **Final Output**: For each index in the output array, multiply the left and right products.

### Python Implementation

```python
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        length = len(nums)
        left_products, right_products = [1] * length, [1] * length
        output = [1] * length

        # Calculate left products
        for i in range(1, length):
            left_products[i] = nums[i - 1] * left_products[i - 1]

        # Calculate right products
        for i in range(length - 2, -1, -1):
            right_products[i] = nums[i + 1] * right_products[i + 1]

        # Calculate output
        for i in range(length):
            output[i] = left_products[i] * right_products[i]

        return output

```

### Explanation

- `left_products` and `right_products` arrays store the cumulative product of all elements to the left and right of each index, respectively.
- The final `output` array is calculated by multiplying the corresponding elements of `left_products` and `right_products`.

### Complexity Analysis

- **Time Complexity**: O(n), where n is the number of elements in the input array. We traverse the array three times.
- **Space Complexity**: O(n) for the two additional arrays used (left_products and right_products). If the problem statement allows modifying the input array, you can reduce the space complexity to O(1) by using the input array for one of the products and a single additional variable for the other.

This approach is efficient and follows the constraints of not using division and having a linear time complexity.

## Notes

---

 

## Related Videos

---

[https://youtu.be/bNvIQI2wAjk](https://youtu.be/bNvIQI2wAjk)