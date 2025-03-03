# Next Greater Element I

Problem: 496
Official Difficulty: easy
Feels Like : easy breazy
My Understanding: Fully Understand
Topic: Stack, array, hash table, monotonic stack
Link: https://leetcode.com/problems/next-greater-element-i/description/
Completed On : November 25, 2024
Last Review: November 25, 2024
Days Since Review: 97
Neetcode: No

## Problem

---

The **next greater element** of some element `x` in an array is the **first greater** element that is **to the right** of `x` in the same array.

You are given two **distinct 0-indexed** integer arrays `nums1` and `nums2`, where `nums1` is a subset of `nums2`.

For each `0 <= i < nums1.length`, find the index `j` such that `nums1[i] == nums2[j]` and determine the **next greater element** of `nums2[j]` in `nums2`. If there is no next greater element, then the answer for this query is `-1`.

Return *an array* `ans` *of length* `nums1.length` *such that* `ans[i]` *is the **next greater element** as described above.*

**Example 1:**

```
Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
Output: [-1,3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
- 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
- 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.

```

**Example 2:**

```
Input: nums1 = [2,4], nums2 = [1,2,3,4]
Output: [3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 2 is underlined in nums2 = [1,2,3,4]. The next greater element is 3.
- 4 is underlined in nums2 = [1,2,3,4]. There is no next greater element, so the answer is -1.

```

**Constraints:**

- `1 <= nums1.length <= nums2.length <= 1000`
- `0 <= nums1[i], nums2[i] <= 104`
- All integers in `nums1` and `nums2` are **unique**.
- All the integers of `nums1` also appear in `nums2`.

**Follow up:**

Could you find an

```
O(nums1.length + nums2.length)
```

solution?

## My Solutions

---

```python
class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:

        stack = [] # Mono Decreasing
        greaters = defaultdict(lambda:-1)

        for i in range(len(nums2)):
            
            while stack and stack[-1] < nums2[i]:
                less = stack.pop()
                greaters[less] = nums2[i]

            stack.append(nums2[i])

        output = [greaters[num] for num in nums1]

        return output 
```

```python

```

## Optimal Solutions

---

To solve **LeetCode Problem 496: Next Greater Element I**, the most efficient algorithm uses a **monotonic stack** to achieve linear time complexity. Below is a detailed explanation of the optimal algorithm, including code examples and time and space complexity analyses.

---

## **Problem Description**

Given two arrays:

- **`nums1`**, a subset of **`nums2`**
- **`nums2`**, a list of unique integers

For each element `nums1[i]`, find the next greater element in `nums2`. The next greater element of a number `x` in `nums2` is the first greater number to the right of `x` in `nums2`. If it doesn't exist, output `-1` for this number.

**Example 1:**

```
Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
Output: [-1,3,-1]
Explanation:
- For 4 in nums1, there is no next greater element in nums2, so output -1.
- For 1 in nums1, the next greater element in nums2 is 3.
- For 2 in nums1, there is no next greater element in nums2, so output -1.

```

**Example 2:**

```
Input: nums1 = [2,4], nums2 = [1,2,3,4]
Output: [3,-1]
Explanation:
- For 2 in nums1, the next greater element in nums2 is 3.
- For 4 in nums1, there is no next greater element in nums2, so output -1.

```

**Constraints:**

- `1 <= nums1.length <= nums2.length <= 1000`
- `0 <= nums1[i], nums2[i] <= 10^4`
- All integers in `nums1` and `nums2` are **unique**.
- All elements in `nums1` also appear in `nums2`.

---

## **Optimal Algorithm: Monotonic Stack and Hash Map**

### **Algorithm Overview**

- **Objective:** For each element in `nums1`, find its next greater element in `nums2`.
- **Approach:** Use a **monotonic decreasing stack** to find the next greater element for each number in `nums2`, then map each element to its next greater element using a hash map.
- **Process:**
    1. **Iterate over `nums2`** to find the next greater element for each number.
    2. **Store the mapping** of each number to its next greater element in a hash map.
    3. **Build the result** for `nums1` using the hash map.

### **Algorithm Steps**

1. **Initialize Data Structures:**
    - An empty **stack** to keep track of numbers.
    - An empty **hash map (`next_greater`)** to store the next greater element for each number in `nums2`.
2. **Iterate Over `nums2`:**
    - For each number `num` in `nums2`:
        - While the stack is not empty and `num` is greater than `stack[-1]`:
            - Pop the top element `last_num` from the stack.
            - Set `next_greater[last_num] = num` (since `num` is the next greater element for `last_num`).
        - Push `num` onto the stack.
3. **Handle Remaining Elements in Stack:**
    - For any elements left in the stack, set their next greater element to `1` (no greater element exists).
4. **Build the Result for `nums1`:**
    - For each number `num` in `nums1`, retrieve its next greater element from `next_greater` and add it to the result list.

### **Code Implementation**

```python
class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        # Step 1: Initialize data structures
        stack = []
        next_greater = {}

        # Step 2: Iterate over nums2 to fill next_greater map
        for num in nums2:
            while stack and num > stack[-1]:
                last_num = stack.pop()
                next_greater[last_num] = num
            stack.append(num)

        # Step 3: For remaining elements in stack, there is no next greater element
        while stack:
            last_num = stack.pop()
            next_greater[last_num] = -1

        # Step 4: Build the result for nums1
        result = [next_greater[num] for num in nums1]
        return result

```

---

## **Detailed Explanation**

- **Monotonic Stack:**
    - The stack maintains a decreasing sequence of numbers.
    - When a larger number is encountered, it is the next greater element for all smaller numbers in the stack.
- **Hash Map (`next_greater`):**
    - Stores the mapping from each number to its next greater element.
- **Step-by-Step Process:**
    - **Step 1:** Initialize an empty stack and hash map.
    - **Step 2:** Iterate through `nums2`:
        - For each `num` in `nums2`:
            - While `num` is greater than the top of the stack:
                - Pop `last_num` from the stack.
                - Set `next_greater[last_num] = num`.
            - Push `num` onto the stack.
    - **Step 3:** After processing all elements, set `next_greater` of remaining stack elements to `1`.
    - **Step 4:** For each `num` in `nums1`, retrieve its next greater element from `next_greater`.

### **Example Walkthrough**

Let's walk through the first example:

**Input:**

```
nums1 = [4,1,2]
nums2 = [1,3,4,2]

```

**Processing:**

1. **Initialize:**
    - `stack = []`
    - `next_greater = {}`
2. **Iterate over nums2:**
    - **num = 1:**
        - Stack is empty.
        - Push `1` onto stack.
        - `stack = [1]`
    - **num = 3:**
        - `3 > 1` (top of stack)
        - Pop `1` from stack.
        - Set `next_greater[1] = 3`
        - Stack is empty.
        - Push `3` onto stack.
        - `stack = [3]`
    - **num = 4:**
        - `4 > 3` (top of stack)
        - Pop `3` from stack.
        - Set `next_greater[3] = 4`
        - Stack is empty.
        - Push `4` onto stack.
        - `stack = [4]`
    - **num = 2:**
        - `2 <= 4` (top of stack)
        - Push `2` onto stack.
        - `stack = [4, 2]`
3. **Handle Remaining Stack Elements:**
    - Pop `2` from stack.
        - Set `next_greater[2] = -1`
    - Pop `4` from stack.
        - Set `next_greater[4] = -1`
    - `next_greater = {1: 3, 3: 4, 2: -1, 4: -1}`
4. **Build Result for nums1:**
    - For `4`: `next_greater[4] = -1`
    - For `1`: `next_greater[1] = 3`
    - For `2`: `next_greater[2] = -1`
    - **Result:** `[-1, 3, -1]`

---

## **Time and Space Complexity Analysis**

- **Time Complexity:** O(N + M)
    - **N:** Length of `nums2`
    - **M:** Length of `nums1`
    - **Explanation:**
        - Iterating over `nums2` takes O(N) time.
        - Building the result by iterating over `nums1` takes O(M) time.
        - Total time complexity is O(N + M).
- **Space Complexity:** O(N)
    - **Explanation:**
        - The `next_greater` map can store up to N entries.
        - The `stack` can hold up to N elements.
        - Total space used is proportional to N.

---

## **Edge Cases to Consider**

- **No Next Greater Element:**
    - If a number has no greater element in `nums2`, it maps to `1`.
- **All Elements Increasing:**
    - Each element's next greater is the element immediately after it.
- **All Elements Decreasing:**
    - All elements will have `1` as their next greater element.

---

## **Alternative Approach (Not Recommended)**

- **Brute Force Method:**
    - For each element in `nums1`, scan `nums2` to find its next greater element.
    - **Time Complexity:** O(M * N)
    - **Not efficient** for large inputs.

---

## **Test Cases**

```python
# Test Case 1
nums1 = [4,1,2]
nums2 = [1,3,4,2]
assert Solution().nextGreaterElement(nums1, nums2) == [-1,3,-1]

# Test Case 2
nums1 = [2,4]
nums2 = [1,2,3,4]
assert Solution().nextGreaterElement(nums1, nums2) == [3,-1]

# Test Case 3
nums1 = [1,3,5,2,4]
nums2 = [6,5,4,3,2,1,7]
assert Solution().nextGreaterElement(nums1, nums2) == [7,7,7,7,7]

# Test Case 4
nums1 = [4]
nums2 = [4]
assert Solution().nextGreaterElement(nums1, nums2) == [-1]

# Test Case 5
nums1 = [1,2,3]
nums2 = [3,2,1]
assert Solution().nextGreaterElement(nums1, nums2) == [-1,-1,-1]

```

---

## **Conclusion**

By utilizing a **monotonic stack** and a **hash map**, we can efficiently find the next greater element for each number in `nums2` and then build the result for `nums1`. This approach ensures linear time complexity and is optimal for the problem.

**Key Takeaways:**

- **Monotonic Stack:**
    - Helps in efficiently finding the next greater elements in a single pass.
- **Hash Map:**
    - Stores the mapping of each number to its next greater element for quick lookup.
- **Time Complexity:**
    - **O(N + M)**, where N is the length of `nums2` and M is the length of `nums1`.
- **Space Complexity:**
    - **O(N)**, due to the stack and hash map.

This method provides an efficient and scalable solution suitable for large inputs.

## Notes

---

 

## Related Videos

---

[https://www.youtube.com/watch?v=68a1Dc_qVq4&pp=ygUfbmV4dCBncmVhdGVyIGVsZW1lbnQgMSBsZWV0Y29kZQ%3D%3D](https://www.youtube.com/watch?v=68a1Dc_qVq4&pp=ygUfbmV4dCBncmVhdGVyIGVsZW1lbnQgMSBsZWV0Y29kZQ%3D%3D)