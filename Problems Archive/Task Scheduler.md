Problem: 621
Official Difficulty: medium
Link: https://leetcode.com/problems/task-scheduler/description/
Completed On : 2024-11-17
Feels Like : hard
Topic: array, hash table, greedy, sorting, Heap(Priority Queue), Counting
My Understanding: Needs Review
Last Review: 2024-11-17
Days Since Review: 7
Name: Task Scheduler

# Task Scheduler
### Problem
___
You are given an array of CPU `tasks`, each labeled with a letter from A to Z, and a number `n`. Each CPU interval can be idle or allow the completion of one task. Tasks can be completed in any order, but there's a constraint: there has to be a gap of **at least** `n` intervals between two tasks with the same label.
Return the **minimum** number of CPU intervals required to complete all tasks.
**Example 1:**
**Input:** tasks = ["A","A","A","B","B","B"], n = 2
**Output:** 8
**Explanation:** A possible sequence is: A -> B -> idle -> A -> B -> idle -> A -> B.
After completing task A, you must wait two intervals before doing A again. The same applies to task B. In the 3rd interval, neither A nor B can be done, so you idle. By the 4th interval, you can do A again as 2 intervals have passed.
**Example 2:**
**Input:** tasks = ["A","C","A","B","D","B"], n = 1
**Output:** 6
**Explanation:** A possible sequence is: A -> B -> C -> D -> A -> B.
With a cooling interval of 1, you can repeat a task after just one other task.
**Example 3:**
**Input:** tasks = ["A","A","A", "B","B","B"], n = 3
**Output:** 10
**Explanation:** A possible sequence is: A -> B -> idle -> idle -> A -> B -> idle -> idle -> A -> B.
There are only two types of tasks, A and B, which need to be separated by 3 intervals. This leads to idling twice between repetitions of these tasks.
**Constraints:**
- `1 <= tasks.length <= 104`
- `tasks[i]` is an uppercase English letter.
- `0 <= n <= 100`
### My Solutions
___
My orginal idea , doesn’t work becuase it fails to try others in the heap if it can’t do the most frequent
```python
from collections import Counter
import heapq

class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> List[str]:

        counts = Counter(tasks)
        heap = [(-counts[task], float('-inf'), task) for task in counts]
        heapq.heapify(heap)

        elapsed_time = 0
        schedule = []

        while heap:
            freq, last_exec_time, task = heapq.heappop(heap)
            gap = elapsed_time - last_exec_time - 1  

            if gap >= n:

                freq += 1  # freq is negative,increment to decrease cuz max heap/pq
                last_exec_time = elapsed_time
                if freq != 0:
                    heapq.heappush(heap, (freq, last_exec_time, task))
                schedule.append(task)
            else:
                heapq.heappush(heap, (freq, last_exec_time, task))
                schedule.append('idle')

            elapsed_time += 1

        return len(schedule)

```

Time Complexity :
```python
class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:

        counts = Counter(tasks)
        # [freq,ready_time,task]
        heap = [(-counts[task],float('-inf'),task) for task in counts]
        heapq.heapify(heap)

        elapsed_time = 0
        waiting = deque()

        while heap or waiting:

            if waiting and waiting[0][1] <= elapsed_time:
                freq , ready_time, task = waiting.popleft()
                heapq.heappush(heap,(freq,ready_time,task))

            if heap:
                freq , ready_time , task = heapq.heappop(heap)

                freq += 1
                if freq != 0:

                    ready_time = elapsed_time + n + 1
                    waiting.append((freq,ready_time,task))
            else:
                # Idle
                pass

            elapsed_time +=1

        return elapsed_time
    

```

Time Complexity : 
### Optimal Solutions
___

### Notes
___
 
### Related Videos 
___
[s8p8ukTyA2I](https://youtu.be/s8p8ukTyA2I)