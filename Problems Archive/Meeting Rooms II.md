<<<<<<< Updated upstream
Problem: 253
Official Difficulty: medium
Link: https://leetcode.com/problems/meeting-rooms-ii/description/
Completed On : 2024-12-20
Feels Like : medium
Topic: array, two pointers, greedy, sorting, Heap(Priority Queue), prefix sum
My Understanding: Fully Understand
Last Review: 2024-12-20
Days Since Review: 2
Name: Meeting Rooms II

# Meeting Rooms II
### Problem
___
Given an array of meeting time intervals `intervals` where `intervals[i] = [starti, endi]`, return *the minimum number of conference rooms required*.
**Example 1:**
```plain text
Input: intervals = [[0,30],[5,10],[15,20]]
Output: 2
```
**Example 2:**
```plain text
Input: intervals = [[7,10],[2,4]]
Output: 1
```
**Constraints:**
- `1 <= intervals.length <= 104`
- `0 <= starti < endi <= 106`
### My Solutions
___
=======
# Meeting Rooms II

Problem: 253
Official Difficulty: medium
Feels Like : medium
My Understanding: Fully Understand
Topic: Heap(Priority Queue), array, greedy, prefix sum, sorting, two pointers
Link: https://leetcode.com/problems/meeting-rooms-ii/description/
Completed On : December 20, 2024
Last Review: December 20, 2024
Days Since Review: 72
Neetcode: Yes

## Problem

---

Given an array of meeting time intervals `intervals` where `intervals[i] = [starti, endi]`, return *the minimum number of conference rooms required*.

**Example 1:**

```
Input: intervals = [[0,30],[5,10],[15,20]]
Output: 2
```

**Example 2:**

```
Input: intervals = [[7,10],[2,4]]
Output: 1
```

**Constraints:**

- `1 <= intervals.length <= 104`
- `0 <= starti < endi <= 106`

## My Solutions

---

>>>>>>> Stashed changes
```python
class Solution:
    def minMeetingRooms(self, intervals: List[List[int]]) -> int:

        if not intervals:
            return 0

        intervals.sort()
        rooms = 0
        occupied = [] 

        for interval in intervals :
            
            while occupied and occupied[0] <= interval[0]:
                heapq.heappop(occupied)

            heapq.heappush(occupied,interval[1])

            rooms = max(rooms,len(occupied))

        return rooms
```

<<<<<<< Updated upstream
Time Complexity :
=======
>>>>>>> Stashed changes
```python

```

<<<<<<< Updated upstream
Time Complexity : 
### Optimal Solutions
___
To solve **LeetCode 253: Meeting Rooms II**, we need to determine the minimum number of meeting rooms required to hold all meetings given their start and end times.
#### **Approach**
The problem can be viewed as finding the maximum number of overlapping intervals. The most efficient solution involves **sorting and using a priority queue (min-heap)** to manage the end times of meetings currently occupying rooms.
___
#### **Steps**
1. **Sort Meetings by Start Time**:
	- Sort the intervals by their start times so that we process them in chronological order.
2. **Use a Min-Heap to Track End Times**:
	- The min-heap will store the end times of meetings currently occupying rooms.
	- The smallest end time in the heap represents the meeting that will finish the earliest.
3. **Iterate Through the Intervals**:
	- For each meeting:
		- If the start time of the current meeting is greater than or equal to the smallest end time in the heap, it means a room has been freed up, so we remove the top of the heap.
		- Push the current meeting's end time into the heap (allocate a room).
4. **Result**:
	- The size of the heap at the end of the iteration represents the minimum number of rooms required.
___
#### **Code Implementation**
=======
## Optimal Solutions

---

To solve **LeetCode 253: Meeting Rooms II**, we need to determine the minimum number of meeting rooms required to hold all meetings given their start and end times.

### **Approach**

The problem can be viewed as finding the maximum number of overlapping intervals. The most efficient solution involves **sorting and using a priority queue (min-heap)** to manage the end times of meetings currently occupying rooms.

---

### **Steps**

1. **Sort Meetings by Start Time**:
    - Sort the intervals by their start times so that we process them in chronological order.
2. **Use a Min-Heap to Track End Times**:
    - The min-heap will store the end times of meetings currently occupying rooms.
    - The smallest end time in the heap represents the meeting that will finish the earliest.
3. **Iterate Through the Intervals**:
    - For each meeting:
        - If the start time of the current meeting is greater than or equal to the smallest end time in the heap, it means a room has been freed up, so we remove the top of the heap.
        - Push the current meeting's end time into the heap (allocate a room).
4. **Result**:
    - The size of the heap at the end of the iteration represents the minimum number of rooms required.

---

### **Code Implementation**

>>>>>>> Stashed changes
```python
import heapq

class Solution:
    def minMeetingRooms(self, intervals: List[List[int]]) -> int:
        if not intervals:
            return 0

        # Step 1: Sort the intervals by start time
        intervals.sort(key=lambda x: x[0])

        # Step 2: Use a min-heap to track end times
        heap = []

        # Step 3: Iterate through the intervals
        for interval in intervals:
            # If the room is free, remove the earliest ending meeting
            if heap and interval[0] >= heap[0]:
                heapq.heappop(heap)

            # Add the current meeting's end time to the heap
            heapq.heappush(heap, interval[1])

        # Step 4: The size of the heap is the number of meeting rooms needed
        return len(heap)

```
<<<<<<< Updated upstream
___
#### **Complexity Analysis**
- **Time Complexity:**
	- Sorting the intervals: **O(n log n)**.
	- Each `heappush` and `heappop` operation: **O(log n)**.
	- Total: **O(n log n)**.
- **Space Complexity:**
	- The heap stores the end times of meetings: **O(n)** in the worst case.
___
#### **Example Walkthrough**
**Input:**
`intervals = [[0, 30], [5, 10], [15, 20]]`
**Execution:**
5. **Sort by Start Time:**
`[[0, 30], [5, 10], [15, 20]]`.
6. **Iterate with Min-Heap:**
	- For `[0, 30]`: Add `30` to the heap → `heap = [30]`.
	- For `[5, 10]`: Add `10` to the heap → `heap = [10, 30]`.
	- For `[15, 20]`: `15 >= 10`, so remove `10` from the heap, then add `20` → `heap = [20, 30]`.
7. **Result:**
The heap size is `2`, so `2` meeting rooms are needed.
**Output:**
`2`
___
#### **Key Insights**
- The heap helps efficiently track the smallest end time, ensuring that we only use the required number of meeting rooms.
- Sorting the intervals by start time simplifies managing overlapping intervals.
This approach ensures optimal performance and clarity in implementation.
### Notes
___
 
### Related Videos 
___
[FdzJmTCVyJU](https://youtu.be/FdzJmTCVyJU)
=======

---

### **Complexity Analysis**

- **Time Complexity:**
    - Sorting the intervals: **O(n log n)**.
    - Each `heappush` and `heappop` operation: **O(log n)**.
    - Total: **O(n log n)**.
- **Space Complexity:**
    - The heap stores the end times of meetings: **O(n)** in the worst case.

---

### **Example Walkthrough**

**Input:**

`intervals = [[0, 30], [5, 10], [15, 20]]`

**Execution:**

1. **Sort by Start Time:**
    
    `[[0, 30], [5, 10], [15, 20]]`.
    
2. **Iterate with Min-Heap:**
    - For `[0, 30]`: Add `30` to the heap → `heap = [30]`.
    - For `[5, 10]`: Add `10` to the heap → `heap = [10, 30]`.
    - For `[15, 20]`: `15 >= 10`, so remove `10` from the heap, then add `20` → `heap = [20, 30]`.
3. **Result:**
    
    The heap size is `2`, so `2` meeting rooms are needed.
    

**Output:**

`2`

---

### **Key Insights**

- The heap helps efficiently track the smallest end time, ensuring that we only use the required number of meeting rooms.
- Sorting the intervals by start time simplifies managing overlapping intervals.

This approach ensures optimal performance and clarity in implementation.

## Notes

---

 

## Related Videos

---

[https://youtu.be/FdzJmTCVyJU](https://youtu.be/FdzJmTCVyJU)
>>>>>>> Stashed changes
