# Robot Collisions

Problem: 2751
Official Difficulty: hard
Feels Like : hard
My Understanding: I Have No Idea
Topic: Stack, array, simulation, sorting
Link: https://leetcode.com/problems/robot-collisions/description/
Completed On : August 9, 2024
Last Review: August 9, 2024
Days Since Review: 0

## Problem

---

There are `n` **1-indexed** robots, each having a position on a line, health, and movement direction.

You are given **0-indexed** integer arrays `positions`, `healths`, and a string `directions` (`directions[i]` is either **'L'** for **left** or **'R'** for **right**). All integers in `positions` are **unique**.

All robots start moving on the line **simultaneously** at the **same speed** in their given directions. If two robots ever share the same position while moving, they will **collide**.

If two robots collide, the robot with **lower health** is **removed** from the line, and the health of the other robot **decreases** **by one**. The surviving robot continues in the **same** direction it was going. If both robots have the **same** health, they are both ****removed from the line.

Your task is to determine the **health** of the robots that survive the collisions, in the same **order** that the robots were given, ****i.e.
 final heath of robot 1 (if survived), final health of robot 2 (if 
survived), and so on. If there are no survivors, return an empty array.

Return *an array containing the health of the remaining robots (in
 the order they were given in the input), after no further collisions 
can occur.*

**Note:** The positions may be unsorted.

**Example 1:**

![https://assets.leetcode.com/uploads/2023/05/15/image-20230516011718-12.png](https://assets.leetcode.com/uploads/2023/05/15/image-20230516011718-12.png)

```
Input: positions = [5,4,3,2,1], healths = [2,17,9,15,10], directions = "RRRRR"
Output: [2,17,9,15,10]
Explanation: No collision occurs in this example, since all robots are moving in the same direction. So, the health of the robots in order from the first robot is returned, [2, 17, 9, 15, 10].

```

**Example 2:**

![https://assets.leetcode.com/uploads/2023/05/15/image-20230516004433-7.png](https://assets.leetcode.com/uploads/2023/05/15/image-20230516004433-7.png)

```
Input: positions = [3,5,2,6], healths = [10,10,15,12], directions = "RLRL"
Output: [14]
Explanation: There are 2 collisions in this example. Firstly, robot 1 and robot 2 will collide, and since both have the same health, they will be removed from the line. Next, robot 3 and robot 4 will collide and since robot 4's health is smaller, it gets removed, and robot 3's health becomes 15 - 1 = 14. Only robot 3 remains, so we return [14].

```

**Example 3:**

![https://assets.leetcode.com/uploads/2023/05/15/image-20230516005114-9.png](https://assets.leetcode.com/uploads/2023/05/15/image-20230516005114-9.png)

```
Input: positions = [1,2,5,6], healths = [10,10,11,11], directions = "RLRL"
Output: []
Explanation: Robot 1 and robot 2 will collide and since both have the same health, they are both removed. Robot 3 and 4 will collide and since both have the same health, they are both removed. So, we return an empty array, [].
```

**Constraints:**

- `1 <= positions.length == healths.length == directions.length == n <= 105`
- `1 <= positions[i], healths[i] <= 109`
- `directions[i] == 'L'` or `directions[i] == 'R'`
- All values in `positions` are distinct

## My Solutions

---

For some reason this doesn’t work

```python
class Solution:
    def survivedRobotsHealths(self, positions: List[int], healths: List[int], directions: str) -> List[int]:

        robots = defaultdict(list)
        
        for robot , hp , dr in zip(positions,healths,directions):
            robots[robot] = [hp,dr]

        positions.sort()
        stack = [positions[0]]

        for i in range(1,len(positions)):
            
            if not stack:
                stack.append(positions[i])
                continue
            
            cur_robot = positions[i]
            hp1 , dr1 = robots[cur_robot]

            prev_robot = stack[-1]
            hp2 , dr2 = robots[prev_robot]

            if dr1 == dr2:
                stack.append(cur_robot)
                continue
            elif dr1 == 'R' and dr2 == 'L':
                stack.append(cur_robot)
                continue

            if hp2 > hp1:

                robots[prev_robot][0] -= 1
                robots[cur_robot][0] = 0

            elif hp1 > hp2:
                
                robots[cur_robot][0] -= 1
                robots[prev_robot][0] = 0
                stack.pop()
                stack.append(cur_robot)
            else:
                robots[cur_robot][0] = 0
                robots[prev_robot][0] = 0
                stack.pop()

        result = []

        for hp , _ in robots.values():

            if hp > 0 :
                result.append(hp)

        return result
  
```

^ Above fails this case

![Screenshot 2024-08-09 at 17-18-09 Robot Collisions - LeetCode.png](Robot%20Collisions%20e7a7df1c9a6b4b2f8b0e3e097743fa5c/Screenshot_2024-08-09_at_17-18-09_Robot_Collisions_-_LeetCode.png)

```python

```

## Optimal Solutions

---

### Approach: Sorting & Stack

### Intuition

To solve the problem of simulating robot collisions, we need to process the robots in the order of their positions and handle collisions as they occur. The key challenge lies in managing these collisions correctly and in the proper sequence.

Because all robots move at the same speed, collisions will only happen when a robot with a lower position is moving to the right (`R`), and another robot with a higher position is moving to the left (`L`). Robots moving in the same direction or moving away from each other will never collide.

The first step is to sort the robots by their positions. Sorting allows us to simulate the collisions in the correct order, starting from the leftmost robot to the rightmost robot.

After sorting, the next step is to handle the collisions. To manage this, we can use a stack, which is an ideal data structure for handling the sequence of robot collisions.

When we encounter a robot moving to the left (`L`), it may collide with one or more robots moving to the right (`R`) that are closer to it. We need to compare the health of the left-moving robot with the health of each right-moving robot it collides with. This process continues until one of the following scenarios occurs:

- The left-moving robot is destroyed.
- The right-moving robot(s) are destroyed.
- Both robots are destroyed if their healths are equal.

A stack is effective for managing this sequence because it operates on a last-in-first-out (LIFO) principle. This principle aligns perfectly with how we need to handle collisions, where the most recently encountered right-moving robot (`R`) is the first to potentially collide with a left-moving robot (`L`).

In summary:

- **Sorting**: Allows us to process the robots in the correct order.
- **Stack**: Helps manage and resolve collisions in the correct sequence.

### Algorithm

1. **Initialization**:
    - Determine the number of robots (`n`).
    - Create an array `indices` to keep track of the original indices of the robots.
    - Create a list `result` to store the health of the surviving robots.
    - Initialize an empty stack to manage right-moving robots.
2. **Sort Robots by Position**:
    - Sort the `indices` array based on the positions of the robots to ensure they are processed from left to right.
3. **Process Each Robot**:
    - Iterate through each `current_index` in the sorted `indices` array:
        - If the robot is moving to the right (`R`), push `current_index` onto the stack.
        - If the robot is moving to the left (`L`):
            - While the stack is not empty and the current robot's health is greater than 0:
                - Pop the top robot from the stack (this represents the most recent right-moving robot).
                - Compare the health of the current left-moving robot and the top right-moving robot:
                    - If the top right-moving robot has more health:
                        - Decrease its health by 1 and push it back onto the stack.
                        - Set the current left-moving robot's health to 0.
                    - If the current left-moving robot has more health:
                        - Decrease its health by 1.
                        - Set the top right-moving robot's health to 0.
                    - If both robots have the same health:
                        - Set both robots' health to 0.
4. **Collect Surviving Robots**:
    - Iterate through each robot index from `0` to `n - 1`:
        - If the robot's health is greater than 0, append it to the `result` list.
5. **Return the Result**:
    - The `result` list now contains the health of the surviving robots.

### Implementation

```python
from typing import List
from collections import deque

class Solution:
    def survivedRobotsHealths(
        self, positions: List[int], healths: List[int], directions: str
    ) -> List[int]:
        n = len(positions)
        indices = list(range(n))
        result = []
        stack = deque()

        # Sort indices based on their positions
        indices.sort(key=lambda x: positions[x])

        for current_index in indices:
            # Add right-moving robots to the stack
            if directions[current_index] == "R":
                stack.append(current_index)
            else:
                while stack and healths[current_index] > 0:
                    # Pop the top robot from the stack for collision check
                    top_index = stack.pop()

                    if healths[top_index] > healths[current_index]:
                        # Top robot survives, current robot is destroyed
                        healths[top_index] -= 1
                        healths[current_index] = 0
                        stack.append(top_index)
                    elif healths[top_index] < healths[current_index]:
                        # Current robot survives, top robot is destroyed
                        healths[current_index] -= 1
                        healths[top_index] = 0
                    else:
                        # Both robots are destroyed
                        healths[current_index] = 0
                        healths[top_index] = 0

        # Collect surviving robots
        for index in range(n):
            if healths[index] > 0:
                result.append(healths[index])

        return result

```

### Complexity Analysis

- **Time Complexity**: `O(n log n)`
    - Sorting the robots based on their positions takes `O(n log n)` time.
    - Processing each robot in the for loop runs in `O(n)` time since each robot is processed once.
    - Thus, the overall time complexity is dominated by the sorting step, making it `O(n log n)`.
- **Space Complexity**: `O(n)`
    - The additional space used includes the `indices` array and the stack, each taking `O(n)` space.
    - The total space complexity is `O(n)`.

This approach efficiently handles robot collisions using a stack and returns the health of the surviving robots after all collisions have been processed.

## Notes

---

 

## Related Videos

---

[https://www.notion.so](https://www.notion.so)