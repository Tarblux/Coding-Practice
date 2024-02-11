# Robot Bounded In a Circle

Problem: 1041
Official Difficulty: medium
Feels Like : easy
Topic: Math, simulation, string
Link: https://leetcode.com/problems/robot-bounded-in-circle/description/
Completed On : January 22, 2024
My Understanding: Mostly Understand
Last Review: January 22, 2024
Days Since Review: 19

## Problem

---

On an infinite plane, a robot initially stands at `(0, 0)` and faces north. Note that:

- The **north direction** is the positive direction of the y-axis.
- The **south direction** is the negative direction of the y-axis.
- The **east direction** is the positive direction of the x-axis.
- The **west direction** is the negative direction of the x-axis.

The robot can receive one of three instructions:

- `"G"`: go straight 1 unit.
- `"L"`: turn 90 degrees to the left (i.e., anti-clockwise direction).
- `"R"`: turn 90 degrees to the right (i.e., clockwise direction).

The robot performs the `instructions` given in order, and repeats them forever.

Return `true` if and only if there exists a circle in the plane such that the robot never leaves the circle.

**Example 1:**

```
Input: instructions = "GGLLGG"
Output: true
Explanation: The robot is initially at (0, 0) facing the north direction.
"G": move one step. Position: (0, 1). Direction: North.
"G": move one step. Position: (0, 2). Direction: North.
"L": turn 90 degrees anti-clockwise. Position: (0, 2). Direction: West.
"L": turn 90 degrees anti-clockwise. Position: (0, 2). Direction: South.
"G": move one step. Position: (0, 1). Direction: South.
"G": move one step. Position: (0, 0). Direction: South.
Repeating the instructions, the robot goes into the cycle: (0, 0) --> (0, 1) --> (0, 2) --> (0, 1) --> (0, 0).
Based on that, we return true.

```

**Example 2:**

```
Input: instructions = "GG"
Output: false
Explanation: The robot is initially at (0, 0) facing the north direction.
"G": move one step. Position: (0, 1). Direction: North.
"G": move one step. Position: (0, 2). Direction: North.
Repeating the instructions, keeps advancing in the north direction and does not go into cycles.
Based on that, we return false.

```

**Example 3:**

```
Input: instructions = "GL"
Output: true
Explanation: The robot is initially at (0, 0) facing the north direction.
"G": move one step. Position: (0, 1). Direction: North.
"L": turn 90 degrees anti-clockwise. Position: (0, 1). Direction: West.
"G": move one step. Position: (-1, 1). Direction: West.
"L": turn 90 degrees anti-clockwise. Position: (-1, 1). Direction: South.
"G": move one step. Position: (-1, 0). Direction: South.
"L": turn 90 degrees anti-clockwise. Position: (-1, 0). Direction: East.
"G": move one step. Position: (0, 0). Direction: East.
"L": turn 90 degrees anti-clockwise. Position: (0, 0). Direction: North.
Repeating the instructions, the robot goes into the cycle: (0, 0) --> (0, 1) --> (-1, 1) --> (-1, 0) --> (0, 0).
Based on that, we return true.

```

**Constraints:**

- `1 <= instructions.length <= 100`
- `instructions[i]` is `'G'`, `'L'` or, `'R'`.

## My Solutions

---

```python
class Solution:
    def isRobotBounded(self, instructions: str) -> bool:

        direction = 0

        # North = 0, East = 1, South = 2, West = 3

        x = 0 

        y = 0

        for letter in instructions : 

            if letter == 'L' : 

                direction = (direction - 1) % 4
            
            if letter == 'R' :

                direction = (direction + 1 ) % 4

            if letter == 'G' and direction == 0 : 

                y += 1

            if letter == 'G' and direction == 1 : 

                x += 1

            if letter == 'G' and direction == 2 : 

                y -= 1

            if letter == 'G' and direction == 3 : 

                x -= 1

        return (x == 0 and  y == 0 ) or direction != 0
```

```python

```

## Optimal Solutions

---

The optimal solution for the "Robot Bounded In Circle" problem can be achieved by analyzing the robot's position and direction after completing one cycle of instructions. If the robot returns to the starting point or does not face north (the original direction) after one cycle, it is guaranteed to be bounded in a circle.

### Problem Understanding

The robot starts at the origin `(0, 0)` facing north and follows a set of instructions that may include 'G' (go straight 1 unit), 'L' (turn left 90 degrees), and 'R' (turn right 90 degrees). The question is whether the robot ends up in a circle (i.e., it's bounded) after following these instructions indefinitely.

### Solution Approach

1. **Track Position and Direction**: Use variables to track the robot's position `(x, y)` and direction.
2. **Process Instructions**: Iterate through each instruction and update the robot's position and direction accordingly.
3. **Check Final State**:
    - If the robot returns to the origin `(0, 0)` or
    - If the robot does not face north after completing one cycle of instructions, then it is bounded in a circle.

### Python Implementation

```python
class Solution:
    def isRobotBounded(self, instructions: str) -> bool:
        # North = 0, East = 1, South = 2, West = 3
        x, y, direction = 0, 0, 0
        # Movement changes for North, East, South, West
        moves = [(0, 1), (1, 0), (0, -1), (-1, 0)]

        for i in instructions:
            if i == 'L':
                direction = (direction - 1) % 4
            elif i == 'R':
                direction = (direction + 1) % 4
            else:  # 'G'
                dx, dy = moves[direction]
                x, y = x + dx, y + dy

        # The robot is bounded if it returns to the origin or changes direction
        return (x == 0 and y == 0) or direction != 0

```

### Explanation

- The `direction` variable keeps track of the robot's current facing direction.
- The `moves` array represents the change in `x` and `y` for each direction.
- On encountering 'L' or 'R', the direction is updated.
- On encountering 'G', the robot moves in the direction it is currently facing.
- After processing the instructions, if the robot is back at the origin or facing a different direction, it is bounded in a circle.

### Complexity Analysis

- **Time Complexity**: O(n), where n is the length of the instructions string. Each instruction is processed once.
- **Space Complexity**: O(1), as the solution uses a fixed amount of space.

This approach effectively determines whether the robot's movement is bounded within a circle, considering its position and orientation after one cycle of the instructions.

## Notes

---

 

## Related Videos

---

[https://youtu.be/nKv2LnC_g6E](https://youtu.be/nKv2LnC_g6E)