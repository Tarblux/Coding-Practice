Problem: 739
Official Difficulty: medium
Link: https://leetcode.com/problems/daily-temperatures/description/
Completed On : 2024-11-18
Feels Like : medium
Topic: array, monotonic stack, Stack
My Understanding: Mostly Understand
Last Review: 2024-11-18
Days Since Review: 6
Name: Daily Temperatures

# Daily Temperatures
### Problem
___
Given an array of integers `temperatures` represents the daily temperatures, return *an array* `answer` *such that* `answer[i]` *is the number of days you have to wait after the* `ith` *day to get a warmer temperature*. If there is no future day for which this is possible, keep `answer[i] == 0` instead.
**Example 1:**
```plain text
Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]
```
**Example 2:**
```plain text
Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]
```
**Example 3:**
```plain text
Input: temperatures = [30,60,90]
Output: [1,1,0]
```
**Constraints:**
- `1 <= temperatures.length <= 105`
- `30 <= temperatures[i] <= 100`
### My Solutions
___
```python
class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:

        output = [0] * len(temperatures)
        stack = [] #[temp,day]

        for i in range(len(temperatures)):

            current_temp = temperatures[i]

            while stack and current_temp > stack[-1][0]:

                colder_temp , colder_day = stack.pop()
                output[colder_day] = i - colder_day

            stack.append([current_temp,i])

        return output
```

Time Complexity :
```python

```

Time Complexity : 
### Optimal Solutions
___
### **Optimal Algorithm: Monotonic Decreasing Stack**
#### **Algorithm Overview**
- **Objective:** For each day, find the next day with a higher temperature.
- **Approach:** Use a stack to keep track of indices of days with unresolved temperatures.
- **Monotonic Stack:** The stack will maintain indices of temperatures in a **monotonically decreasing** order (from top to bottom).
#### **Algorithm Steps**
1. **Initialize:**
	- Create an array `answer` of the same length as `temperatures`, initialized with zeros.
	- Initialize an empty stack `stack` to store indices.
2. **Iterate Over Temperatures:**
	- Loop through each temperature with index `i` from `0` to `n - 1`, where `n` is the length of `temperatures`.
3. **Process Current Temperature:**
	- While the stack is not empty and the current temperature `temperatures[i]` is greater than the temperature at the index on top of the stack (`temperatures[stack[-1]]`):
		- **Pop** the index `prev_index` from the stack.
		- Calculate the difference `i - prev_index` and set `answer[prev_index] = i - prev_index`.
		- This means the warmer temperature for day `prev_index` is `i - prev_index` days ahead.
	- **Push** the current index `i` onto the stack.
4. **Finalize Answer:**
	- After processing all temperatures, any indices left in the stack do not have a warmer temperature in the future, so their values in `answer` remain `0`.
#### **Example Walkthrough**
Let's walk through the example `temperatures = [73,74,75,71,69,72,76,73]`.
- **Initialization:**
	- `answer = [0,0,0,0,0,0,0,0]`
	- `stack = []`
- **Iteration 0 (**`**i = 0**`**):**
	- Current temperature: `73`
	- Stack is empty, so push `0` onto the stack.
	- `stack = [0]`
- **Iteration 1 (**`**i = 1**`**):**
	- Current temperature: `74`
	- `74 > 73` (`temperatures[1] > temperatures[stack[-1]]`)
	- Pop `0` from stack; set `answer[0] = 1 - 0 = 1`
	- `answer = [1,0,0,0,0,0,0,0]`
	- Stack is empty, push `1` onto stack.
	- `stack = [1]`
- **Iteration 2 (**`**i = 2**`**):**
	- Current temperature: `75`
	- `75 > 74`
	- Pop `1` from stack; set `answer[1] = 2 - 1 = 1`
	- `answer = [1,1,0,0,0,0,0,0]`
	- Stack is empty, push `2` onto stack.
	- `stack = [2]`
- **Iteration 3 (**`**i = 3**`**):**
	- Current temperature: `71`
	- `71 <= 75`
	- Push `3` onto stack.
	- `stack = [2,3]`
- **Iteration 4 (**`**i = 4**`**):**
	- Current temperature: `69`
	- `69 <= 71`
	- Push `4` onto stack.
	- `stack = [2,3,4]`
- **Iteration 5 (**`**i = 5**`**):**
	- Current temperature: `72`
	- `72 > 69`
	- Pop `4`; set `answer[4] = 5 - 4 = 1`
	- `answer = [1,1,0,0,1,0,0,0]`
	- `72 > 71`
	- Pop `3`; set `answer[3] = 5 - 3 = 2`
	- `answer = [1,1,0,2,1,0,0,0]`
	- `72 <= 75`
	- Push `5` onto stack.
	- `stack = [2,5]`
- **Iteration 6 (**`**i = 6**`**):**
	- Current temperature: `76`
	- `76 > 72`
	- Pop `5`; set `answer[5] = 6 - 5 = 1`
	- `answer = [1,1,0,2,1,1,0,0]`
	- `76 > 75`
	- Pop `2`; set `answer[2] = 6 - 2 = 4`
	- `answer = [1,1,4,2,1,1,0,0]`
	- Stack is empty, push `6` onto stack.
	- `stack = [6]`
- **Iteration 7 (**`**i = 7**`**):**
	- Current temperature: `73`
	- `73 <= 76`
	- Push `7` onto stack.
	- `stack = [6,7]`
- **Finalization:**
	- Indices `6` and `7` remain in the stack; set `answer[6] = 0`, `answer[7] = 0`.
	- Final `answer = [1,1,4,2,1,1,0,0]`
#### **Code Implementation**
```python
class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        n = len(temperatures)
        answer = [0] * n  # Initialize the answer array with zeros
        stack = []  # This will store indices of the temperatures array

        for i in range(n):
            # While current temperature is greater than the temperature at the index on top of the stack
            while stack and temperatures[i] > temperatures[stack[-1]]:
                prev_index = stack.pop()
                answer[prev_index] = i - prev_index
            stack.append(i)

        return answer

```
___
### **Time and Space Complexity Analysis**
#### **Time Complexity:** O(n)
- **Explanation:**
	- Each temperature is pushed onto the stack exactly once.
	- Each temperature is popped from the stack at most once.
	- Therefore, the total number of stack operations is O(n).
	- The loop runs `n` times, and each operation inside the loop is O(1).
	- Overall time complexity is linear.
#### **Space Complexity:** O(n)
- **Explanation:**
	- In the worst case (monotonically decreasing temperatures), all temperatures are pushed onto the stack.
	- The `answer` array uses O(n) space.
	- Therefore, the total space complexity is O(n).
___
### **Alternative Algorithms**
#### **1. Brute-Force Approach (Not Optimal)**
- **Description:**
	- For each day `i`, scan forward to find the first day with a warmer temperature.
	- Time complexity is O(n²), which is not efficient for large inputs.
- **Code Example:**
```python
def dailyTemperatures(temperatures):
    n = len(temperatures)
    answer = [0] * n
    for i in range(n):
        for j in range(i + 1, n):
            if temperatures[j] > temperatures[i]:
                answer[i] = j - i
                break
    return answer

```
- **Time Complexity:** O(n²)
- **Space Complexity:** O(1) (excluding the output array)
#### **2. Using Array for Next Warmer Temperature**
- **Description:**
	- For temperatures ranging from 30 to 100, use an array `next` of size 71 to store the next occurrence of each temperature.
	- Traverse the temperatures array from the end to the beginning.
	- For each temperature, find the earliest day when a warmer temperature occurs by checking the `next` array.
- **Code Example:**
```python
class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        n = len(temperatures)
        answer = [0] * n
        next_temp = [float('inf')] * 71  # Temperatures from 30 to 100

        for i in range(n - 1, -1, -1):
            warmer_index = float('inf')
            for t in range(temperatures[i] - 29, 71):
                if next_temp[t] < warmer_index:
                    warmer_index = next_temp[t]
            if warmer_index < float('inf'):
                answer[i] = warmer_index - i
            next_temp[temperatures[i] - 30] = i

        return answer

```
- **Time Complexity:** O(n * m), where `m` is the number of possible temperatures (71 in this case)
- **Space Complexity:** O(m)
- **Note:** This method is not as efficient as the monotonic stack approach due to the extra loop over possible temperatures.
___
### **Conclusion**
- The **monotonic decreasing stack** approach is the most efficient and optimal solution for the Daily Temperatures problem.
- It efficiently finds the next warmer day for each day by maintaining a stack of indices whose temperatures are waiting for a warmer day.
- The time complexity is **O(n)**, and space complexity is **O(n)**, both of which are optimal given the problem constraints.
___
### **Test Cases**
```python
# Test Case 1
temperatures = [73,74,75,71,69,72,76,73]
assert Solution().dailyTemperatures(temperatures) == [1,1,4,2,1,1,0,0]

# Test Case 2
temperatures = [30,40,50,60]
assert Solution().dailyTemperatures(temperatures) == [1,1,1,0]

# Test Case 3
temperatures = [30,60,90]
assert Solution().dailyTemperatures(temperatures) == [1,1,0]

# Test Case 4
temperatures = [90,80,70,60,50]
assert Solution().dailyTemperatures(temperatures) == [0,0,0,0,0]

# Test Case 5
temperatures = [70]
assert Solution().dailyTemperatures(temperatures) == [0]

```
___
### **Summary**
- **Problem:** For each day, find out how many days you need to wait until a warmer temperature.
- **Optimal Solution:** Use a **monotonic decreasing stack** to keep track of temperatures.
- **Time Complexity:** O(n)
- **Space Complexity:** O(n)
- **Key Idea:** By using a stack to store indices of days with unresolved temperatures, we can efficiently find the next day with a warmer temperature for each day in a single pass through the input.
___
By understanding and applying the monotonic stack approach, we can solve the Daily Temperatures problem efficiently and optimally.
### Notes
___
 
### Related Videos 
___
[cTBiBSnjO3c](https://youtu.be/cTBiBSnjO3c)