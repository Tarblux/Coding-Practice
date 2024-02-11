# Robot Return to Origin

Problem: 657
Official Difficulty: easy
Feels Like : easy
Topic: simulation, string
Link: https://leetcode.com/problems/robot-return-to-origin/description
Completed On : January 7, 2024
My Understanding: Fully Understand
Last Review: January 7, 2024
Days Since Review: 34

## Problem

---

There is a robot starting at the position `(0, 0)`, the origin, on a 2D plane. Given a sequence of its moves, judge if this robot **ends up at** `(0, 0)` after it completes its moves.

You are given a string `moves` that represents the move sequence of the robot where `moves[i]` represents its `ith` move. Valid moves are `'R'` (right), `'L'` (left), `'U'` (up), and `'D'` (down).

Return `true` *if the robot returns to the origin after it finishes all of its moves, or* `false` *otherwise*.

**Note**: The way that the robot is "facing" is irrelevant. `'R'` will always make the robot move to the right once, `'L'` will always make it move left, etc. Also, assume that the magnitude of the robot's movement is the same for each move.

**Example 1:**

```
Input: moves = "UD"
Output: true
Explanation: The robot moves up once, and then down once. All moves have the same magnitude, so it ended up at the origin where it started. Therefore, we return true.

```

**Example 2:**

```
Input: moves = "LL"
Output: false
Explanation: The robot moves left twice. It ends up two "moves" to the left of the origin. We return false because it is not at the origin at the end of its moves.

```

**Constraints:**

- `1 <= moves.length <= 2 * 104`
- `moves` only contains the characters `'U'`, `'D'`, `'L'` and `'R'`.

## My Solutions

---

```python
class Solution:
    def judgeCircle(self, moves: str) -> bool:

        dict = {
            'U' : 1 ,
            'D' : -1 ,
            'R' : 1 ,
            'L' : -1
        }

        x = 0

        y = 0

        # at_origin = True

        for move in moves : 

            if move == 'U' or move == 'D' : 

                y += dict[move]

            else : 

                x += dict[move]

        # if x == 0 and y == 0 : 

        #     at_origin = True

        # else : 

        #     at_origin = False

        return x == 0 and y == 0
```

```python

```

## Optimal Solutions

---

## Notes

---

 

## Related Videos

---

[https://www.notion.so](https://www.notion.so)