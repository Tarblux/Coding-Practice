# Car Fleet

Problem: 853
Official Difficulty: medium
Feels Like : medium
My Understanding: Needs Review
Topic: Stack, array, monotonic stack, sorting
Link: https://leetcode.com/problems/car-fleet/description/
Completed On : November 19, 2024
Last Review: November 19, 2024
Days Since Review: 103
Neetcode: Yes

## Problem

---

There are `n` cars at given miles away from the starting mile 0, traveling to reach the mile `target`.

You are given two integer array `position` and `speed`, both of length `n`, where `position[i]` is the starting mile of the `ith` car and `speed[i]` is the speed of the `ith` car in miles per hour.

A car cannot pass another car, but it can catch up and then travel next to it at the speed of the slower car.

A **car fleet** is a car or cars driving next to each other. The speed of the car fleet is the **minimum** speed of any car in the fleet.

If a car catches up to a car fleet at the mile `target`, it will still be considered as part of the car fleet.

Return the number of car fleets that will arrive at the destination.

**Example 1:**

**Input:** target = 12, position = [10,8,0,5,3], speed = [2,4,1,1,3]

**Output:** 3

**Explanation:**

- The cars starting at 10 (speed 2) and 8 (speed 4) become a fleet, meeting each other at 12. The fleet forms at `target`.
- The car starting at 0 (speed 1) does not catch up to any other car, so it is a fleet by itself.
- The cars starting at 5 (speed 1) and 3 (speed 3) become a fleet, meeting each other at 6. The fleet moves at speed 1 until it reaches `target`.

**Example 2:**

**Input:** target = 10, position = [3], speed = [3]

**Output:** 1

**Explanation:**

There is only one car, hence there is only one fleet.

**Example 3:**

**Input:** target = 100, position = [0,2,4], speed = [4,2,1]

**Output:** 1

**Explanation:**

- The cars starting at 0 (speed 4) and 2 (speed 2) become a fleet, meeting each other at 4. The car starting at 4 (speed 1) travels to 5.
- Then, the fleet at 4 (speed 2) and the car at position 5 (speed 1) become one fleet, meeting each other at 6. The fleet moves at speed 1 until it reaches `target`.

**Constraints:**

- `n == position.length == speed.length`
- `1 <= n <= 105`
- `0 < target <= 106`
- `0 <= position[i] < target`
- All the values of `position` are **unique**.
- `0 < speed[i] <= 106`

## My Solutions

---

```python
class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:

        
        combo = list(zip(position,speed))
        combo.sort(reverse = True)
        print(combo)
        
        stack = [] # Monotonically increasing -> time to destination
        fleets = 0
        
        for i in range(len(combo)):
            
            pos , spd = combo[i]
            current_ttd = (target-pos) / spd
            
            # The first fleet ago be at least the time is take the closest to reach
            if not stack:
                stack.append(current_ttd)
                fleets += 1
                continue

            #will nvr catch up to next one to be in that fleet so formns a new fleet
            if current_ttd > stack[-1]:
                # No need to pop before since this car cannot catch up to the fleet ahead
                # So the mono increasing property is fine
                stack.append(current_ttd)
                fleets += 1
            else:
            
            # Else, the car joins the fleet represented by stack[-1]
            # Do nothing since it's absorbed into the fleet ahead
                pass

  
        return fleets
        
```

```python

```

## Optimal Solutions

---

To solve **LeetCode Problem 853: Car Fleet**, we need to determine how many car fleets will arrive at the target location when cars with different positions and speeds are moving towards it. The optimal approach involves sorting the cars based on their starting positions and simulating the process of fleet formation.

---

## **Problem Description**

- **Given:**
    - An integer `target` representing the destination position.
    - Two integer arrays `position` and `speed`, both of the same length.
        - `position[i]` represents the starting position of the `i`th car.
        - `speed[i]` represents the speed of the `i`th car.
- **Goal:**
    - Return the **number of car fleets** that will arrive at the destination `target`.
- **Definition of a Car Fleet:**
    - If a car catches up to another car that is moving at the same or slower speed, they form a fleet and move together at the slower car's speed.

---

## **Optimal Algorithm: Sorting and Stack Simulation**

### **Algorithm Overview**

1. **Sort Cars by Starting Position:**
    - Sort the cars in descending order based on their starting positions. This ensures that we process cars from the closest to the target to the farthest.
2. **Calculate Time to Reach the Target:**
    - For each car, calculate the time it will take to reach the target.
3. **Simulate Fleet Formation Using a Stack:**
    - Initialize a stack to keep track of the times it takes for fleets to reach the target.
    - Iterate over the cars:
        - If the time for the current car is greater than the time at the top of the stack, it means the current car cannot catch up to the fleet ahead and forms a new fleet.
        - If the time is less than or equal to the time at the top of the stack, the current car will join the fleet ahead.
4. **Return the Number of Fleets:**
    - The number of elements in the stack represents the number of car fleets that will reach the target.

### **Algorithm Steps**

1. **Pair Positions with Speeds and Sort:**
    
    ```python
    cars = sorted(zip(position, speed), key=lambda x: -x[0])
    
    ```
    
    - `cars` is a list of tuples `(position, speed)`, sorted in descending order by position.
2. **Calculate Time to Target and Use Stack:**
    
    ```python
    stack = []
    for pos, spd in cars:
        time = (target - pos) / spd
        if not stack or time > stack[-1]:
            stack.append(time)
        # If time <= stack[-1], current car joins the fleet ahead
    
    ```
    
    - We calculate the time `time` for each car to reach the target.
    - If the `stack` is empty or `time` is greater than the top of the stack, we append `time` to the stack, indicating a new fleet.
    - If `time` is less than or equal to the top of the stack, the current car joins the fleet represented by the top of the stack.
3. **Return the Result:**
    
    ```python
    return len(stack)
    
    ```
    

### **Code Implementation**

```python
class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        # Step 1: Pair positions with speeds and sort in descending order of position
        cars = sorted(zip(position, speed), key=lambda x: -x[0])

        # Step 2: Initialize a stack to simulate fleet formation
        stack = []
        for pos, spd in cars:
            time = (target - pos) / spd  # Time to reach the target
            # If the current car cannot catch up to the fleet ahead, it forms a new fleet
            if not stack or time > stack[-1]:
                stack.append(time)
            # Else, it joins the fleet ahead (do nothing)

        # Step 3: The number of fleets is the number of elements in the stack
        return len(stack)

```

---

## **Explanation**

- **Sorting in Descending Order:**
    - By sorting the cars from the closest to the target to the farthest, we ensure that we process cars in the order they would potentially interact (i.e., a car can only catch up to cars ahead of it).
- **Fleet Formation Logic:**
    - If a car takes longer to reach the target than the car ahead, it cannot catch up and forms a new fleet.
    - If a car takes less or equal time to reach the target compared to the car ahead, it will catch up and join the fleet ahead.
- **Using a Stack:**
    - The stack maintains the times for fleets to reach the target.
    - Each time a new fleet is formed, its time is pushed onto the stack.
    - Cars that join existing fleets do not alter the fleet's time to reach the target.

---

## **Time and Space Complexity Analysis**

### **Time Complexity:** O(N log N)

- **Explanation:**
    - Sorting the `cars` list takes O(N log N), where N is the number of cars.
    - The iteration over the cars is O(N).
    - Therefore, the overall time complexity is dominated by the sorting step.

### **Space Complexity:** O(N)

- **Explanation:**
    - The `cars` list holds N elements after zipping and sorting.
    - The `stack` may hold up to N elements in the worst case.
    - Therefore, the space complexity is O(N).

---

## **Example Walkthrough**

Let's walk through an example to understand how the algorithm works.

**Example:**

- **Input:**
    
    ```
    target = 12
    position = [10, 8, 0, 5, 3]
    speed = [2, 4, 1, 1, 3]
    
    ```
    
- **Step 1: Pair and Sort Cars**
    
    ```
    cars = [(10, 2), (8, 4), (5, 1), (3, 3), (0, 1)]
    
    ```
    
- **Step 2: Calculate Times and Simulate Fleets**
    - Initialize `stack = []`.
    - **Car at position 10 with speed 2:**
        - Time = (12 - 10) / 2 = 1.0
        - `stack` is empty, so append 1.0.
        - `stack = [1.0]`
    - **Car at position 8 with speed 4:**
        - Time = (12 - 8) / 4 = 1.0
        - Time <= stack[-1] (1.0 <= 1.0), so car joins the fleet ahead.
        - `stack` remains `[1.0]`
    - **Car at position 5 with speed 1:**
        - Time = (12 - 5) / 1 = 7.0
        - Time > stack[-1] (7.0 > 1.0), so forms a new fleet.
        - `stack = [1.0, 7.0]`
    - **Car at position 3 with speed 3:**
        - Time = (12 - 3) / 3 = 3.0
        - Time <= stack[-1] (3.0 <= 7.0), so car joins the fleet at time 7.0.
        - `stack` remains `[1.0, 7.0]`
    - **Car at position 0 with speed 1:**
        - Time = (12 - 0) / 1 = 12.0
        - Time > stack[-1] (12.0 > 7.0), so forms a new fleet.
        - `stack = [1.0, 7.0, 12.0]`
- **Step 3: Return the Number of Fleets**
    - The number of fleets is `len(stack) = 3`.

**Output:**

```
3

```

---

## **Edge Cases to Consider**

- **All Cars Have the Same Speed:**
    - If all cars have the same speed, they will not catch up to each other, and the number of fleets equals the number of cars.
- **Cars Starting at the Same Position:**
    - Cars starting at the same position are considered separate unless they have the same speed.
- **No Cars:**
    - If there are no cars, the number of fleets is 0.

---

## **Alternative Approaches**

While the above method is the most efficient, another approach is to:

- **Use a Dictionary or Map:**
    - Map each position to its time to reach the target.
    - Sort the positions and process similarly.

However, this approach does not offer significant advantages over the stack method and may be less efficient due to additional data structures.

---

## **Summary**

- **Algorithm:**
    - Sort cars based on starting positions in descending order.
    - Use a stack to simulate fleet formations based on time to reach the target.
    - Cars catching up to fleets ahead join them; otherwise, they form new fleets.
- **Time Complexity:** O(N log N)
- **Space Complexity:** O(N)

This algorithm efficiently calculates the number of car fleets that will arrive at the destination by simulating the process using a stack after sorting the cars. It handles various edge cases and scales well with larger inputs.

---

## **Test Cases**

```python
# Test Case 1
target = 12
position = [10, 8, 0, 5, 3]
speed = [2, 4, 1, 1, 3]
assert Solution().carFleet(target, position, speed) == 3

# Test Case 2
target = 10
position = [3]
speed = [3]
assert Solution().carFleet(target, position, speed) == 1

# Test Case 3
target = 100
position = []
speed = []
assert Solution().carFleet(target, position, speed) == 0

# Test Case 4
target = 10
position = [6, 8]
speed = [3, 2]
assert Solution().carFleet(target, position, speed) == 2

# Test Case 5
target = 100
position = [0, 2, 4]
speed = [4, 2, 1]
assert Solution().carFleet(target, position, speed) == 1

```

---

## **Conclusion**

By leveraging sorting and a stack to simulate fleet formations based on the time it takes for each car to reach the target, we can efficiently solve the Car Fleet problem. This approach ensures an optimal time complexity of O(N log N) and handles all necessary edge cases, making it suitable for large inputs and practical applications.

## Notes

---

 

## Related Videos

---

[https://youtu.be/zx5Sw9130L0](https://youtu.be/zx5Sw9130L0)