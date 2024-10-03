# Walking Robot Simulation

Problem: 874
Official Difficulty: medium
Feels Like : medium
My Understanding: Fully Understand
Topic: array, hash table, simulation
Link: https://leetcode.com/problems/walking-robot-simulation/description/
Completed On : October 3, 2024
Last Review: October 3, 2024
Days Since Review: 0

## Problem

---

A robot on an infinite XY-plane starts at point `(0, 0)` facing north. The robot receives an array of integers `commands`,
 which represents a sequence of moves that it needs to execute. There 
are only three possible types of instructions the robot can receive:

- `2`: Turn left `90` degrees.
- `1`: Turn right `90` degrees.
- `1 <= k <= 9`: Move forward `k` units, one unit at a time.

Some of the grid squares are `obstacles`. The `ith` obstacle is at grid point `obstacles[i] = (xi, yi)`.
 If the robot runs into an obstacle, it will stay in its current 
location (on the block adjacent to the obstacle) and move onto the next 
command.

Return the **maximum squared Euclidean distance** that the robot reaches at any point in its path (i.e. if the distance is `5`, return `25`).

**Note:**

- There can be an obstacle at `(0, 0)`. If this happens,
the robot will ignore the obstacle until it has moved off the origin.
However, it will be unable to return to `(0, 0)` due to the obstacle.
- North means +Y direction.
- East means +X direction.
- South means -Y direction.
- West means -X direction.

**Example 1:**

**Input:** commands = [4,-1,3], obstacles = []

**Output:** 25

**Explanation:**

The robot starts at `(0, 0)`:

1. Move north 4 units to `(0, 4)`.
2. Turn right.
3. Move east 3 units to `(3, 4)`.

The furthest point the robot ever gets from the origin is `(3, 4)`, which squared is `32 + 42 = 25` units away.

**Example 2:**

**Input:** commands = [4,-1,4,-2,4], obstacles = [[2,4]]

**Output:** 65

**Explanation:**

The robot starts at `(0, 0)`:

1. Move north 4 units to `(0, 4)`.
2. Turn right.
3. Move east 1 unit and get blocked by the obstacle at `(2, 4)`, robot is at `(1, 4)`.
4. Turn left.
5. Move north 4 units to `(1, 8)`.

The furthest point the robot ever gets from the origin is `(1, 8)`, which squared is `12 + 82 = 65` units away.

**Example 3:**

**Input:** commands = [6,-1,-1,6], obstacles = [[0,0]]

**Output:** 36

**Explanation:**

The robot starts at `(0, 0)`:

1. Move north 6 units to `(0, 6)`.
2. Turn right.
3. Turn right.
4. Move south 5 units and get blocked by the obstacle at `(0,0)`, robot is at `(0, 1)`.

The furthest point the robot ever gets from the origin is `(0, 6)`, which squared is `62 = 36` units away.

**Constraints:**

- `1 <= commands.length <= 104`
- `commands[i]` is either `2`, `1`, or an integer in the range `[1, 9]`.
- `0 <= obstacles.length <= 104`
- `3 * 104 <= xi, yi <= 3 * 104`
- The answer is guaranteed to be less than `231`.

## My Solutions

---

```python
class Solution:
    def robotSim(self, commands: List[int], obstacles: List[List[int]]) -> int:

        obs = set()
        max_dist = 0
        direction = 0

        # Up , Right, Down , Left
        directions = [(0,1),(1,0),(0,-1),(-1,0)]

        x = 0
        y = 0

        for obstacle in obstacles:
            obs.add(tuple(obstacle))

        for command in commands:
            
            if command == -1:
                direction += 1
                continue
            elif command == -2:
                direction -= 1
                continue

            for i in range(command):

                dx,dy = directions[direction % 4]

                if (x+dx,y+dy) in obs:
                    break

                x,y = x + dx , y + dy
                max_dist = max(max_dist,x**2 + y**2)

        return max_dist 
```

```python

```

## Optimal Solutions

---

### **Optimal Algorithm: Simulation with Efficient Obstacle Lookup**

### **Algorithm Overview**

The most efficient approach is to simulate the robot's movement while efficiently checking for obstacles using a hash set.

### **Key Steps**

1. **Initialize Direction Vectors:**
    - Use a list to represent the four cardinal directions (north, east, south, west).
        
        ```python
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        ```
        
    - Start with a `direction_index` pointing to **north**.
2. **Convert Obstacles to a Set:**
    - Convert the list of obstacle coordinates to a set for **O(1)** lookup times.
        
        ```python
        obstacle_set = set(map(tuple, obstacles))
        ```
        
3. **Process Commands:**
    - Iterate over each command in the `commands` list.
        - **Turn Commands (`2` and `1`):**
            - Update the `direction_index` accordingly using modular arithmetic.
        - **Move Commands (Positive Integers):**
            - Move one step at a time in the current direction.
            - After each step:
                - Check if the next position is an obstacle.
                - If not, update the robot's position and calculate the distance squared.
                - If it is an obstacle, stop moving in the current command.
4. **Track Maximum Distance:**
    - After each valid move, update the `max_distance` if the new position is farther from the origin.

### **Algorithm Implementation**

```python
def robotSim(commands, obstacles):
    # Direction vectors: North, East, South, West
    directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
    direction_index = 0  # Facing North
    x, y = 0, 0  # Starting position
    max_distance = 0

    # Convert obstacles list to a set for O(1) access
    obstacle_set = set(map(tuple, obstacles))

    for cmd in commands:
        if cmd == -2:
            # Turn left 90 degrees
            direction_index = (direction_index - 1) % 4
        elif cmd == -1:
            # Turn right 90 degrees
            direction_index = (direction_index + 1) % 4
        else:
            # Move forward cmd steps
            dx, dy = directions[direction_index]
            for _ in range(cmd):
                next_x, next_y = x + dx, y + dy
                if (next_x, next_y) not in obstacle_set:
                    x, y = next_x, next_y
                    max_distance = max(max_distance, x * x + y * y)
                else:
                    # Obstacle encountered; stop moving forward
                    break
    return max_distance

```

### **Explanation**

- **Direction Management:**
    - `direction_index` cycles through `[0, 1, 2, 3]` representing north, east, south, and west.
    - Turning left decrements the index, while turning right increments it, modulo 4 to wrap around.
- **Obstacle Checking:**
    - Before each step, check if the next position is in `obstacle_set`.
    - If it is, break out of the loop for the current command.
- **Distance Calculation:**
    - After each valid move, calculate `x * x + y * y` to find the distance squared and update `max_distance` if it's larger than the previous value.

### **Time Complexity**

- **O(N + K)** where:
    - `N` is the number of commands.
    - `K` is the total number of steps moved (sum of movement commands).
- **Explanation:**
    - Each command is processed in O(1) time for turns.
    - For movement commands, we may perform up to 9 steps per command (since movement commands are between 1 and 9).
    - Obstacle checking is O(1) due to the use of a set.

### **Space Complexity**

- **O(M)** where:
    - `M` is the number of obstacles.
- **Explanation:**
    - Storing the obstacles in a set requires O(M) space.
    - Other variables use constant or negligible space.

---

### **Alternative Approaches**

Given the constraints and the need for obstacle checking, the simulation approach with an obstacle set is the most optimal. However, here's a brief discussion on potential alternatives:

### **1. Preprocessing Obstacle Coordinates**

- **Idea:**
    - Organize obstacles in a more complex data structure, such as a hash map with positions grouped by x or y coordinates.
- **Pros:**
    - Might improve obstacle lookup in certain scenarios.
- **Cons:**
    - Additional complexity without significant performance gains due to the arbitrary distribution of obstacles.

### **2. Movement Optimization**

- **Idea:**
    - Instead of moving one step at a time, calculate the maximum possible steps in the current direction until an obstacle is hit.
- **Pros:**
    - Reduces the number of iterations in the movement loop.
- **Cons:**
    - Requires additional computation to find the nearest obstacle in the path, which can be complex and may not improve overall performance.

---

### **Why the Optimal Algorithm is Preferred**

- **Efficiency:**
    - The simulation approach efficiently handles up to 10,000 commands and obstacles.
- **Simplicity:**
    - The algorithm is straightforward to implement and understand.
- **Flexibility:**
    - Easily handles various scenarios, including obstacles placed anywhere on the grid.

---

### **Final Thoughts**

- **Edge Cases Handling:**
    - The algorithm correctly handles cases where the robot encounters obstacles immediately or turns multiple times.
- **Practical Performance:**
    - Despite the theoretical time complexity, the actual runtime is acceptable for the problem's constraints.

---

**In summary**, the most optimal approach for **LeetCode 874: Walking Robot Simulation** is to simulate the robot's movement step by step while using a set to efficiently check for obstacles. This method balances efficiency and simplicity, ensuring that the solution runs effectively within the given constraints.

## Notes

---

 

## Related Videos

---

[https://www.notion.so](https://www.notion.so)