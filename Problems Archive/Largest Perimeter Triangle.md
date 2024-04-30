# Largest Perimeter Triangle

Problem: 976
Official Difficulty: easy
Feels Like : medium
My Understanding: Mostly Understand, Needs Review
Topic: Math, array, greedy, sorting
Link: https://leetcode.com/problems/largest-perimeter-triangle/description/
Completed On : April 27, 2024
Last Review: April 27, 2024
Days Since Review: 3

## Problem

---

Given an integer array `nums`, return *the largest perimeter of a triangle with a non-zero area, formed from three of these lengths*. If it is impossible to form any triangle of a non-zero area, return `0`.

**Example 1:**

```
Input: nums = [2,1,2]
Output: 5
Explanation: You can form a triangle with three side lengths: 1, 2, and 2.
```

**Example 2:**

```
Input: nums = [1,2,1,10]
Output: 0
Explanation:
You cannot use the side lengths 1, 1, and 2 to form a triangle.
You cannot use the side lengths 1, 1, and 10 to form a triangle.
You cannot use the side lengths 1, 2, and 10 to form a triangle.
As we cannot use any three side lengths to form a triangle of non-zero area, we return 0.
```

**Constraints:**

- `3 <= nums.length <= 104`
- `1 <= nums[i] <= 106`

## My Solutions

---

### Time Limit Exceeded 😢

```python
import itertools

class Solution:

    def isValidTriangle(self,lengths:List[int]) -> bool:

        a,b,c = lengths
        return (a + b > c) and (b + c > a) and (a + c > b)

    def largestPerimeter(self, nums: List[int]) -> int:

        largest_perimeter = 0

        for triplet in itertools.combinations(nums,3):

            if self.isValidTriangle(triplet):

                largest_perimeter = max(largest_perimeter,sum(list(triplet)))

        return largest_perimeter
```

```python
class Solution:

    def largestPerimeter(self, nums: List[int]) -> int:
        
        nums.sort(reverse=True)
        largest_perimeter = 0

        for i in range(len(nums)-2):

            if nums[i] < nums[i+1] + nums[i+2]:

                largest_perimeter = nums[i] + nums[i+1] + nums[i+2]

                return largest_perimeter

        return largest_perimeter
```

## Optimal Solutions

---

To make the computation of the largest perimeter triangle from a list of side lengths faster, you can optimize the approach by reducing the number of combinations you need to check and improving the condition checking for valid triangles. Here’s how you can achieve this:

### Key Optimizations:

1. **Sort the Numbers**: Once the list is sorted, only combinations where the three sides are adjacent need to be checked because the sum of the two smaller sides (which are adjacent in a sorted list) must be greater than the third side for the largest possible perimeter.
2. **Reverse Order Iteration**: Start checking triplets from the largest possible sides down to the smallest. This way, you can break out early once you find a valid triangle, which will have the largest possible perimeter due to the sorted order.
3. **Early Termination**: If a valid triangle is found in a sorted list, it's guaranteed to have the largest possible perimeter among all valid triangles because of the order of the sides.

### Revised Python Code:

Here is the revised version of the code implementing these optimizations:

```python
class Solution:
    def largestPerimeter(self, nums: List[int]) -> int:
        # Sort the array in non-decreasing order
        nums.sort(reverse=True)

        # Check only adjacent triplets starting from the largest elements
        for i in range(len(nums) - 2):
            # Check if the three sides form a valid triangle
            if nums[i] < nums[i+1] + nums[i+2]:
                # Return the perimeter of the first valid triangle found
                return nums[i] + nums[i+1] + nums[i+2]

        # If no valid triangle is found
        return 0

# Example usage
sol = Solution()
nums = [2, 1, 2, 4, 3, 5]
print(sol.largestPerimeter(nums))  # Output should be 12, from sides [5, 4, 3]

```

### Explanation:

- **Sorting**: The list `nums` is sorted in descending order, which means the largest numbers come first.
- **Loop Through Triplets**: Starting from the largest elements, check each triplet to see if it can form a triangle. The condition `nums[i] < nums[i+1] + nums[i+2]` is derived from the triangle inequality theorem and ensures that the largest side is less than the sum of the other two sides.
- **Early Return**: As soon as a valid triangle is found, its perimeter is returned because it’s guaranteed to be the largest due to the descending order of side lengths.

### Complexity:

- **Time Complexity**: The sorting operation is \(O(n \log n)\), and the checking of triplets is \(O(n)\) because only a single pass through the list is needed post-sorting. Thus, the overall complexity is dominated by the sorting step, \(O(n \log n)\).
- **Space Complexity**: The space complexity is \(O(1)\) or \(O(n)\) depending on whether in-place sorting is considered.

This approach is significantly more efficient than checking all combinations since it strategically uses sorting and the properties of triangle sides to minimize checks and maximize early termination.

## Notes

---

 This just feels like this is one of them where you just have to know the solution or otherwise you are just cooked

## Related Videos

---

[https://www.youtube.com/watch?v=b6qE5k_-eGk](https://www.youtube.com/watch?v=b6qE5k_-eGk)