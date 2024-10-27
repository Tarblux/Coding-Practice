Problem: 1046
Official Difficulty: easy
Link: https://leetcode.com/problems/last-stone-weight/description/
Completed On : 2024-10-24
Feels Like : easy breazy
Topic: array, Heap(Priority Queue)
My Understanding: Fully Understand
Last Review: 2024-10-24
Days Since Review: 3
Name: Last Stone Weight

# Last Stone Weight
### Problem
___
You are given an array of integers `stones` where `stones[i]` is the weight of the `ith` stone.
We are playing a game with the stones. On each turn, we choose the **heaviest two stones** and smash them together. Suppose the heaviest two stones have weights `x` and `y` with `x <= y`. The result of this smash is:
- If `x == y`, both stones are destroyed, and
- If `x != y`, the stone of weight `x` is destroyed, and the stone of weight `y` has new weight `y - x`.
At the end of the game, there is **at most one** stone left.
Return *the weight of the last remaining stone*. If there are no stones left, return `0`.
**Example 1:**
```plain text
Input: stones = [2,7,4,1,8,1]
Output: 1
Explanation:
We combine 7 and 8 to get 1 so the array converts to [2,4,1,1,1] then,
we combine 2 and 4 to get 2 so the array converts to [2,1,1,1] then,
we combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
we combine 1 and 1 to get 0 so the array converts to [1] then that's the value of the last stone.
```
**Example 2:**
```plain text
Input: stones = [1]
Output: 1
```
**Constraints:**
- `1 <= stones.length <= 30`
- `1 <= stones[i] <= 1000`
### My Solutions
___
```python
class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:

        stones = [-weight for weight in stones]
        heapq.heapify(stones)

        while len(stones) > 1:

            h = heapq.heappop(stones) * -1
            nh = heapq.heappop(stones) * -1

            if h == nh:
                continue
            
            heapq.heappush(stones,-(h - nh))

        return -stones[0] if stones else 0
```

Time Complexity :
```python

```

Time Complexity : 
### Optimal Solutions
___
To solve **LeetCode Problem 1046: Last Stone Weight**, the most optimal approach is to use a **max-heap** (priority queue). Below are the efficient algorithms along with their time and space complexities.
___
#### **Algorithm 1: Max-Heap Approach**
**Algorithm Steps:**
1. **Initialize a Max-Heap:**
	- Convert the list of stone weights into a max-heap.
	- Since Python's `heapq` module implements a min-heap, insert negative values to simulate a max-heap.
```python
import heapq
stones = [-stone for stone in stones]
heapq.heapify(stones)

```
2. **Simulate the Stone-Smashing Process:**
	- While there is more than one stone in the heap:
		- **Pop** the two heaviest stones (by popping the two smallest negatives).
```python
stone1 = -heapq.heappop(stones)
stone2 = -heapq.heappop(stones)

```
		- **If** `stone1` is not equal to `stone2`:
			- **Push** the difference back into the heap.
```python
heapq.heappush(stones, -(stone1 - stone2))

```
		- **Else:**
			- Both stones are destroyed; do nothing.
3. **Return the Result:**
	- If the heap is not empty, return the weight of the last remaining stone.
```python
return -stones[0] if stones else 0

```
**Time Complexity:** O(n log n)
- **Explanation:**
	- Building the heap takes O(n) time.
	- Each `heappop` and `heappush` operation takes O(log n) time.
	- In the worst case, we perform up to O(n) such operations.
	- Therefore, the overall time complexity is O(n log n).
**Space Complexity:** O(n)
- **Explanation:**
	- The heap stores up to `n` elements.
**Example Code:**
```python
import heapq

class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        # Convert to max-heap by negating the stone weights
        stones = [-stone for stone in stones]
        heapq.heapify(stones)

        # Simulate the process
        while len(stones) > 1:
            # Pop the two heaviest stones
            stone1 = -heapq.heappop(stones)
            stone2 = -heapq.heappop(stones)
            if stone1 != stone2:
                # If they are not equal, push the difference back
                heapq.heappush(stones, -(stone1 - stone2))
            # If equal, both stones are destroyed; do nothing

        # Return the weight of the last stone or 0
        return -stones[0] if stones else 0

```
___
#### **Algorithm 2: Sorting Approach**
**Algorithm Steps:**
4. **Sort the Stones in Descending Order:**
	- Sort the `stones` list in reverse order.
```python
stones.sort(reverse=True)

```
5. **Simulate the Stone-Smashing Process:**
	- While there are more than one stones left:
		- **Remove** the two heaviest stones from the list.
```python
stone1 = stones.pop(0)
stone2 = stones.pop(0)

```
		- **If** `stone1` is not equal to `stone2`:
			- **Insert** the difference back into the list.
```python
stones.append(abs(stone1 - stone2))

```
```plain text
- **Re-sort** the list in descending order.
  ```python
  stones.sort(reverse=True)

```
		- **Else:**
			- Both stones are destroyed; do nothing.
6. **Return the Result:**
	- If the list is not empty, return the weight of the last remaining stone.
```python
return stones[0] if stones else 0

```
**Time Complexity:** O(n² log n)
- **Explanation:**
	- Sorting takes O(n log n) time.
	- Each iteration involves popping elements and re-sorting, which can take up to O(n log n) time.
	- Since this can happen up to `n` times, the overall time complexity is O(n² log n).
**Space Complexity:** O(n)
- **Explanation:**
	- The list stores up to `n` elements.
**Example Code:**
```python
class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        stones.sort(reverse=True)
        while len(stones) > 1:
            # Remove the two heaviest stones
            stone1 = stones.pop(0)
            stone2 = stones.pop(0)
            if stone1 != stone2:
                # Insert the difference and re-sort
                stones.append(abs(stone1 - stone2))
                stones.sort(reverse=True)
            # If equal, both stones are destroyed; do nothing
        return stones[0] if stones else 0

```
___
#### **Comparison and Recommendation**
- **Max-Heap Approach:**
	- **Pros:**
		- Efficient time complexity of O(n log n).
		- Optimal for large inputs.
	- **Cons:**
		- Slightly more complex to implement due to heap manipulation.
- **Sorting Approach:**
	- **Pros:**
		- Simple to understand and implement.
	- **Cons:**
		- Inefficient time complexity of O(n² log n).
		- Not suitable for larger inputs.
**Recommendation:**
- The **max-heap approach** is the most efficient and optimal solution for this problem. It handles the operations in logarithmic time and is suitable for larger datasets.
___
**Final Code Solution (Max-Heap Approach):**
```python
import heapq

class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        # Convert stones list into a max-heap
        stones = [-stone for stone in stones]
        heapq.heapify(stones)

        # Process the stones
        while len(stones) > 1:
            # Get the two heaviest stones
            stone1 = -heapq.heappop(stones)
            stone2 = -heapq.heappop(stones)
            # If they are not equal, push the difference back
            if stone1 != stone2:
                heapq.heappush(stones, -(stone1 - stone2))
            # If equal, both stones are destroyed

        # Return the last stone weight or 0 if none remain
        return -stones[0] if stones else 0

```
___
This solution efficiently simulates the stone-smashing process by always accessing the two largest stones using a max-heap. The time and space complexities are optimal for this problem.
### Notes
___
 
### Related Videos 
___
[B-QCq79-Vfw](https://youtu.be/B-QCq79-Vfw)