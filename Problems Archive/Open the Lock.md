# Open the Lock

Problem: 752
Official Difficulty: medium
Feels Like : hard
My Understanding: Mostly Understand
Topic: Breadth-First Search(BFS), array, hash table, string
Link: https://leetcode.com/problems/open-the-lock/description/?envType=daily-question&envId=2024-04-22
Completed On : April 22, 2024
Last Review: June 26, 2024
Days Since Review: 5

## Problem

---

You have a lock in front of you with 4 circular wheels. Each wheel has 10 slots: `'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'`. The wheels can rotate freely and wrap around: for example we can turn `'9'` to be `'0'`, or `'0'` to be `'9'`. Each move consists of turning one wheel one slot.

The lock initially starts at `'0000'`, a string representing the state of the 4 wheels.

You are given a list of `deadends` dead ends, meaning if 
the lock displays any of these codes, the wheels of the lock will stop 
turning and you will be unable to open it.

Given a `target` representing the value of the wheels that
 will unlock the lock, return the minimum total number of turns required
 to open the lock, or -1 if it is impossible.

**Example 1:**

```
Input: deadends = ["0201","0101","0102","1212","2002"], target = "0202"
Output: 6
Explanation:
A sequence of valid moves would be "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202".
Note that a sequence like "0000" -> "0001" -> "0002" -> "0102" -> "0202" would be invalid,
because the wheels of the lock become stuck after the display becomes the dead end "0102".
```

**Example 2:**

```
Input: deadends = ["8888"], target = "0009"
Output: 1
Explanation: We can turn the last wheel in reverse to move from "0000" -> "0009".

```

**Example 3:**

```
Input: deadends = ["8887","8889","8878","8898","8788","8988","7888","9888"], target = "8888"
Output: -1
Explanation: We cannot reach the target without getting stuck.

```

**Constraints:**

- `1 <= deadends.length <= 500`
- `deadends[i].length == 4`
- `target.length == 4`
- target **will not be** in the list `deadends`.
- `target` and `deadends[i]` consist of digits only.

## My Solutions

---

```python
class Solution:
    
    def neighbors(self,code:str) -> List[str]:
        
        output = []
        
        for i in range(len(code)):
            
            up = (int(code[i]) + 1) % 10
            down = (int(code[i]) - 1) % 10
            
            up_string = code[:i] + str(up) + code[i+1:]
            down_string = code[:i]+str(down)+code[i+1:]
            
            output.append(up_string)
            output.append(down_string)
            
        return output
    
    def openLock(self, deadends: List[str], target: str) -> int:
        
        visited = set()
        queue = deque([('0000',0)])
        
        for de in deadends:
            visited.add(de)
            
        while queue:
            
            state , moves = queue.popleft()
            
            if state in visited:
                continue
            
            visited.add(state)
            
            if state == target:
                return moves
            
            neighbors = self.neighbors(state)
            neighbors_moves = [(n,moves+1) for n in neighbors]
            
            queue.extend(neighbors_moves)

        return -1
        
```

## Chau

```python
class Solution:
    def openLock(self, deadends: List[str], target: str) -> int:
        wheel = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']
        queue = deque()
        queue.append(("0000", 0))
        visited = set()
        visited.add("0000")
        res = -1

        deadends_dict = dict()
        for deadend in deadends:
            deadends_dict[deadend] = True

        while queue:
            cur_display, step = queue.popleft()
            if cur_display == target:
                return step
            
            if cur_display in deadends_dict:
                continue

            for i in range(4):
                idx = int(cur_display[i])
                new_display1 = cur_display[:i] + wheel[(idx + 1)%10]
                new_display2 = cur_display[:i] + wheel[(idx - 1)%10]
                if i + 1 < 4:
                    new_display1 += cur_display[i+1:]
                    new_display2 += cur_display[i+1:]
                if new_display1 not in visited:
                    queue.append((new_display1, step + 1))
                    visited.add(new_display1)
                if new_display2 not in visited:
                    queue.append((new_display2, step + 1))
                    visited.add(new_display2)
            
        return res
```

## Optimal Solutions

---

The "Open The Lock" problem is a classic breadth-first search (BFS) problem often seen in coding interviews. The problem is typically framed as follows:

You have a lock in front of you with 4 circular wheels. Each wheel has 10 slots: '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'. The wheels can rotate freely and wrap around: for example, we can turn '9' to be '0', or '0' to be '9'. Each move consists of turning one wheel one slot.

The lock initially starts at '0000', a string representing the state of the four wheels.

You are given a list of "deadends" dead numbers, meaning if the lock displays any of these codes, the wheels of the lock will stop turning and you will be unable to open it.

Given a target representing the desired combination of the wheels, write a function to open the lock by turning the wheels, with the minimum number of turns, and return the minimum number of turns required to open the lock, or -1 if it is impossible.

Here is a Python solution using BFS:

```python
from typing import List
from collections import deque

class Solution:
    def openLock(self, deadends: List[str], target: str) -> int:
        def neighbors(node):
            for i in range(4):
                x = int(node[i])
                for d in (-1, 1):  # This represents the wheel turning to previous or next number
                    y = (x + d) % 10
                    yield node[:i] + str(y) + node[i+1:]

        dead = set(deadends)
        queue = deque([('0000', 0)])
        visited = set('0000')

        while queue:
            node, depth = queue.popleft()
            if node == target:
                return depth
            if node in dead:
                continue
            for nei in neighbors(node):
                if nei not in visited:
                    visited.add(nei)
                    queue.append((nei, depth + 1))

        return -1  # If no solution is found

# Example usage:
sol = Solution()
print(sol.openLock(["0201","0101","0102","1212","2002"], "0202"))  # Output: 6

```

### Explanation:

- **BFS Strategy**: BFS is used because it explores all positions at the present "depth" before moving on to positions that are further away, guaranteeing that the first time we reach the target combination, it is the minimum number of moves possible.
- **Neighbors Function**: This helper function generates all possible states of the lock that can be reached from a given state by turning any of the four wheels one position forward or backward.
- **Deadends**: These are stored in a set for O(1) complexity checks. If we reach a deadend, we skip processing that node.
- **Queue**: BFS uses a queue to keep track of each state and its depth (number of turns from the start).
- **Visited**: A set to keep track of visited combinations to prevent processing the same combination multiple times.

The time complexity of this approach is O(N^2 * A^N + D), where A is the number of digits in our locks (10, for the digits 0-9), N is the number of wheels (4, one for each digit of the lock), and D is the number of deadends. The space complexity is O(A^N + D), used by the queue and the set of dead ends.

## Notes

---

 

## Related Videos

---

[https://youtu.be/Pzg3bCDY87w](https://youtu.be/Pzg3bCDY87w)