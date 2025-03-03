# The Number of the Smallest Unoccupied Chair

Problem: 1942
Official Difficulty: medium
Feels Like : medium
My Understanding: Mostly Understand, Needs Review
Topic: Heap(Priority Queue), array, hash table
Link: https://leetcode.com/problems/the-number-of-the-smallest-unoccupied-chair/description/?envType=daily-question&envId=2024-10-11
Completed On : October 10, 2024
Last Review: October 10, 2024
Days Since Review: 143
Neetcode: No

## Problem

---

There is a party where `n` friends numbered from `0` to `n - 1` are attending. There is an **infinite** number of chairs in this party that are numbered from `0` to `infinity`. When a friend arrives at the party, they sit on the unoccupied chair with the **smallest number**.

- For example, if chairs `0`, `1`, and `5` are occupied when a friend comes, they will sit on chair number `2`.

When a friend leaves the party, their chair becomes unoccupied at the moment they leave. If another friend arrives at that same moment, they can sit in that chair.

You are given a **0-indexed** 2D integer array `times` where `times[i] = [arrivali, leavingi]`, indicating the arrival and leaving times of the `ith` friend respectively, and an integer `targetFriend`. All arrival times are **distinct**.

Return *the **chair number** that the friend numbered* `targetFriend` *will sit on*.

**Example 1:**

```
Input: times = [[1,4],[2,3],[4,6]], targetFriend = 1
Output: 1
Explanation:
- Friend 0 arrives at time 1 and sits on chair 0.
- Friend 1 arrives at time 2 and sits on chair 1.
- Friend 1 leaves at time 3 and chair 1 becomes empty.
- Friend 0 leaves at time 4 and chair 0 becomes empty.
- Friend 2 arrives at time 4 and sits on chair 0.
Since friend 1 sat on chair 1, we return 1.

```

**Example 2:**

```
Input: times = [[3,10],[1,5],[2,6]], targetFriend = 0
Output: 2
Explanation:
- Friend 1 arrives at time 1 and sits on chair 0.
- Friend 2 arrives at time 2 and sits on chair 1.
- Friend 0 arrives at time 3 and sits on chair 2.
- Friend 1 leaves at time 5 and chair 0 becomes empty.
- Friend 2 leaves at time 6 and chair 1 becomes empty.
- Friend 0 leaves at time 10 and chair 2 becomes empty.
Since friend 0 sat on chair 2, we return 2.

```

**Constraints:**

- `n == times.length`
- `2 <= n <= 104`
- `times[i].length == 2`
- `1 <= arrivali < leavingi <= 105`
- `0 <= targetFriend <= n - 1`
- Each `arrivali` time is **distinct**.

## My Solutions

---

```python
import heapq

class Solution:
    def smallestChair(self, times: List[List[int]], targetFriend: int) -> int:
        
        times = [[arr, leave, idx] for idx, [arr, leave] in enumerate(times)]
        times.sort()
        
        available_chairs = [i for i in range(len(times))]  
        occupied_chairs = []   
        

        for arr, dep, idx in times:
						
						# Clear out occupied chairs and add them back to availkab
            while occupied_chairs and occupied_chairs[0][0] <= arr:
                leave_time, chair = heapq.heappop(occupied_chairs)
                heapq.heappush(available_chairs, chair)
            
            chair = heapq.heappop(available_chairs)

            if idx == targetFriend:
                return chair
            
            heapq.heappush(occupied_chairs, (dep, chair_num))
```

```python

```

## Optimal Solutions

---

To solve **LeetCode Problem 1942: The Number of the Smallest Unoccupied Chair**, the most efficient approach is to use two min-heaps (priority queues) to manage chair allocation and freeing.

---

### **Optimal Algorithm: Priority Queues with Min-Heaps**

**Algorithm Steps:**

1. **Prepare Data:**
    - Create a list that includes arrival time, leaving time, and the friend's index.
    - Sort this list based on arrival times.
    
    ```python
    times_with_indices = [(times[i][0], times[i][1], i) for i in range(len(times))]
    times_with_indices.sort()
    
    ```
    
2. **Initialize Heaps:**
    - `available_chairs`: A min-heap to store available chair numbers.
    - `occupied_chairs`: A min-heap to store tuples of `(leaving_time, chair_number)`.
    - `next_available_chair`: An integer to assign new chair numbers when none are available.
3. **Iterate Over Friends:**
    - For each friend, process all chairs that have become available before their arrival.
        - Free up chairs by moving them from `occupied_chairs` to `available_chairs`.
    - Assign the smallest available chair to the current friend.
        - If no chairs are available, assign `next_available_chair` and increment it.
    - Add the assigned chair to `occupied_chairs` with the friend's leaving time.
    - If the current friend is the target friend `k`, return the assigned chair number.

**Code Implementation:**

```python
import heapq

def smallestChair(times, targetFriend):
    n = len(times)
    # Step 1: Prepare data
    times_with_indices = [(times[i][0], times[i][1], i) for i in range(n)]
    times_with_indices.sort()

    # Step 2: Initialize heaps
    available_chairs = []
    occupied_chairs = []
    next_available_chair = 0

    # Step 3: Iterate over friends
    for arrival_time, leaving_time, friend_index in times_with_indices:
        # Free up chairs that have become available
        while occupied_chairs and occupied_chairs[0][0] <= arrival_time:
            _, freed_chair = heapq.heappop(occupied_chairs)
            heapq.heappush(available_chairs, freed_chair)

        # Assign chair to the current friend
        if available_chairs:
            chair_number = heapq.heappop(available_chairs)
        else:
            chair_number = next_available_chair
            next_available_chair += 1

        # Add the chair to the occupied chairs heap with leaving time
        heapq.heappush(occupied_chairs, (leaving_time, chair_number))

        # If this is the target friend, return the chair number
        if friend_index == targetFriend:
            return chair_number

```

**Time Complexity:** O(n log n)

- **Sorting:** The list of times is sorted once, taking O(n log n) time.
- **Heap Operations:** Each friend's arrival and departure involve O(log n) time operations.
- **Overall:** The algorithm processes each friend once with heap operations, resulting in O(n log n) time.

**Space Complexity:** O(n)

- **Heaps:** Both `available_chairs` and `occupied_chairs` can hold up to `n` elements combined.
- **Data Structures:** The list `times_with_indices` stores `n` elements.

---

This algorithm efficiently assigns the smallest unoccupied chair to each friend by always keeping track of available chairs and processing departures before arrivals when necessary. It ensures that the target friend's chair number is found in optimal time.

## Notes

---

 

## Related Videos

---

[https://www.notion.so](https://www.notion.so)