Problem: 2530
Official Difficulty: medium
Link: https://leetcode.com/problems/maximal-score-after-applying-k-operations/description/?envType=daily-question&envId=2024-10-14
Completed On : 2024-10-13
Feels Like : easy
Topic: array, greedy, Heap(Priority Queue)
My Understanding: Fully Understand
Last Review: 2024-10-13
Days Since Review: 7
Name: Maximal Score After Applying K Operations

# Maximal Score After Applying K Operations
### Problem
___
You are given a **0-indexed** integer array `nums` and an integer `k`. You have a **starting score** of `0`.
In one **operation**:
1. choose an index `i` such that `0 <= i < nums.length`,
2. increase your **score** by `nums[i]`, and
3. replace `nums[i]` with `ceil(nums[i] / 3)`.
Return *the maximum possible ****score**** you can attain after applying ****exactly*** `k` *operations*.
The ceiling function `ceil(val)` is the least integer greater than or equal to `val`.
**Example 1:**
```plain text
Input: nums = [10,10,10,10,10], k = 5
Output: 50
Explanation: Apply the operation to each array element exactly once. The final score is 10 + 10 + 10 + 10 + 10 = 50.

```
**Example 2:**
```plain text
Input: nums = [1,10,3,3,3], k = 3
Output: 17
Explanation:You can do the following operations:
Operation 1: Select i = 1, so nums becomes [1,4,3,3,3]. Your score increases by 10.
Operation 2: Select i = 1, so nums becomes [1,2,3,3,3]. Your score increases by 4.
Operation 3: Select i = 2, so nums becomes [1,1,1,3,3]. Your score increases by 3.
The final score is 10 + 4 + 3 = 17.

```
**Constraints:**
- `1 <= nums.length, k <= 105`
- `1 <= nums[i] <= 109`
### My Solutions
___
```python
class Solution:
    def maxKelements(self, nums: List[int], k: int) -> int:

        score = 0
        nums = [-n for n in nums]
        heapq.heapify(nums)

        for i in range(k):

            best = heapq.heappop(nums) * -1
            score += best
            heapq.heappush(nums,-1*(math.ceil(best/3)))

        return score
        
```

Time Complexity :
```python

```

Time Complexity : 
### Optimal Solutions
___


___

To solve **LeetCode Problem: Maximal Score After Applying K Operations**, the most optimal approach is to use a **min-heap** (priority queue) to efficiently increment the smallest elements in the array. Below is the detailed explanation of the algorithm along with its time and space complexities.
#### **Optimal Algorithm: Min-Heap Approach**
**Algorithm Overview:**
- **Objective:** Increment the smallest elements in the array `nums` to maximize the final product after `k` operations.
- **Strategy:** Use a min-heap to always access and increment the smallest element efficiently.
**Algorithm Steps:**
4. **Initialize a Min-Heap:**
	- Convert the array `nums` into a min-heap to efficiently retrieve the smallest element.
```python
import heapq
heapq.heapify(nums)

```
5. **Perform K Increments:**
	- For each of the `k` operations:
		- **Pop** the smallest element from the heap.
		- **Increment** it by 1.
		- **Push** the incremented value back into the heap.
	- This ensures that the smallest elements are incremented first, maximizing the final product.
6. **Calculate the Final Product:**
	- Initialize `product = 1` and `mod = 10**9 + 7`.
	- **Iterate** over the elements in the heap:
		- Multiply `product` by each element modulo `mod`.
		- This step computes the final product after all increments.
**Time Complexity Analysis:**
- **Heap Initialization:** O(n)
	- The `heapify` function transforms the list into a heap in linear time.
- **K Operations:** O(k log n)
	- Each `heappop` and `heappush` operation takes O(log n) time.
	- For `k` increments, total time is O(k log n).
- **Product Calculation:** O(n)
	- Iterating over all elements in the heap to compute the product.
- **Total Time Complexity:** **O(k log n + n)**
	- Since `k` can be up to `10^5`, and `n` can be up to `10^5`, this is acceptable for the problem constraints.
**Space Complexity Analysis:**
- **O(n)**
	- The heap stores all `n` elements of the array.
	- Additional space used is negligible.
**Code Implementation:**
```python
import heapq

def maximumProduct(nums, k):
    mod = 10**9 + 7
    heapq.heapify(nums)

    for _ in range(k):
        smallest = heapq.heappop(nums)
        heapq.heappush(nums, smallest + 1)

    product = 1
    for num in nums:
        product = (product * num) % mod

    return product

```
___
#### **Alternative Algorithm: Counting Sort Optimization**
**Algorithm Overview:**
- **Objective:** Efficiently distribute the `k` increments among the smallest elements.
- **Strategy:** Use a frequency array to count occurrences of each number and simulate the increment process without using a heap.
**Algorithm Steps:**
7. **Initialize Frequency Array:**
	- Since `nums[i]` can be up to `10^6`, create a frequency array `freq` of size `max_num + k + 2`.
```python
from collections import Counter
freq = Counter(nums)
max_num = max(nums)

```
8. **Distribute K Increments:**
	- Iterate over the possible numbers starting from the smallest.
	- For each number `num`:
		- Determine the number of increments needed to make all occurrences of `num` equal to `num + 1`.
		- Calculate `increments = freq[num]`.
		- If `k >= increments`:
			- Update `freq[num + 1] += freq[num]`.
			- Set `freq[num] = 0`.
			- Decrease `k` by `increments`.
		- Else:
			- Update `freq[num + 1] += k`.
			- Update `freq[num] -= k`.
			- Set `k = 0` and break the loop.
9. **Calculate the Final Product:**
	- Iterate over the frequency array and compute the product.
	- Use modulo operation to prevent integer overflow.
**Time Complexity Analysis:**
- **Frequency Array Initialization:** O(n)
- **Distributing K Increments:** O(max_num + k)
	- Since `max_num` can be up to `10^6`, this step can be acceptable if optimized.
- **Product Calculation:** O(n)
- **Total Time Complexity:** **O(n + max_num + k)**
	- May not be optimal due to the potential size of `max_num`.
**Space Complexity Analysis:**
- **O(max_num + k)**
	- Storing frequencies up to `max_num + k`.
**Note:**
- This approach may not be practical due to the potential size of `max_num`.
- The min-heap approach is preferred for its better time complexity and practicality.
___
#### **Comparison and Recommendation**
- **Min-Heap Approach:**
	- **Pros:**
		- Efficiently increments the smallest elements.
		- Acceptable time complexity for the given constraints.
		- Easy to implement and understand.
	- **Cons:**
		- Requires O(n) space for the heap.
- **Counting Sort Optimization:**
	- **Pros:**
		- Can be efficient if `max_num` is small.
	- **Cons:**
		- Not practical if `max_num` is large (up to `10^6`), leading to higher time and space complexities.
**Recommendation:**
- The **min-heap approach** is the most optimal and practical solution for this problem, given the constraints on `nums[i]` and `k`.
___
#### **Final Code Solution**
```python
class Solution:
    def maximumProduct(self, nums: List[int], k: int) -> int:
        import heapq
        mod = 10**9 + 7
        heapq.heapify(nums)

        for _ in range(k):
            smallest = heapq.heappop(nums)
            heapq.heappush(nums, smallest + 1)

        product = 1
        for num in nums:
            product = (product * num) % mod

        return product

```
**Time Complexity:** O(k log n + n)
**Space Complexity:** O(n)
___
By incrementing the smallest elements first, we ensure that the product is maximized. The use of a min-heap allows us to perform these increments efficiently, making this the optimal solution for maximizing the score after applying `k` operations.
### Notes
___
 
### Related Videos 
___
[]()