# Exam Room

Problem: 855
Official Difficulty: medium
Feels Like : medium
My Understanding: I Have No Idea
Topic: Heap, design, order set
Link: https://leetcode.com/problems/exam-room/description/
Completed On : March 20, 2024
Last Review: March 20, 2024
Days Since Review: 41

## Problem

---

There is an exam room with `n` seats in a single row labeled from `0` to `n - 1`.

When a student enters the room, they must sit in the seat that 
maximizes the distance to the closest person. If there are multiple such
 seats, they sit in the seat with the lowest number. If no one is in the
 room, then the student sits at seat number `0`.

Design a class that simulates the mentioned exam room.

Implement the `ExamRoom` class:

- `ExamRoom(int n)` Initializes the object of the exam room with the number of the seats `n`.
- `int seat()` Returns the label of the seat at which the next student will set.
- `void leave(int p)` Indicates that the student sitting at seat `p` will leave the room. It is guaranteed that there will be a student sitting at seat `p`.

**Example 1:**

```
Input
["ExamRoom", "seat", "seat", "seat", "seat", "leave", "seat"]
[[10], [], [], [], [], [4], []]
Output
[null, 0, 9, 4, 2, null, 5]

Explanation
ExamRoom examRoom = new ExamRoom(10);
examRoom.seat(); // return 0, no one is in the room, then the student sits at seat number 0.
examRoom.seat(); // return 9, the student sits at the last seat number 9.
examRoom.seat(); // return 4, the student sits at the last seat number 4.
examRoom.seat(); // return 2, the student sits at the last seat number 2.
examRoom.leave(4);
examRoom.seat(); // return 5, the student sits at the last seat number 5.
```

**Constraints:**

- `1 <= n <= 109`
- It is guaranteed that there is a student sitting at seat `p`.
- At most `104` calls will be made to `seat` and `leave`.

## My Solutions

---

```python
class ExamRoom:

    def __init__(self, n: int):
        self.n = n
        self.taken = []

    def seat(self) -> int:
        if not self.taken:
            self.taken.append(0)
            return 0

        # To find the max gap, we need to consider the beginning and end of the row
        max_gap = self.taken[0]  # Initial gap considering the first taken seat
        seat_to_take = 0  # Default seat to take is 0

        # Find the max gap between taken seats
        for i in range(1, len(self.taken)):
            gap = (self.taken[i] - self.taken[i-1]) // 2
            if gap > max_gap:
                max_gap = gap
                seat_to_take = self.taken[i-1] + gap

        # Check the gap from the last seat to the end
        if self.n - 1 - self.taken[-1] > max_gap:
            seat_to_take = self.n - 1

        # Insert the seat_to_take in sorted order
        bisect.insort(self.taken, seat_to_take)
        
        #or do this : 
        
        self.taken.append(seat_to_take)
        self.taken.sort
        
        return seat_to_take

    def leave(self, p: int) -> None:
        self.taken.remove(p)

```

```python

```

## Optimal Solutions

---

## Notes

---

 

## Related Videos

---

[https://www.youtube.com/watch?v=vkQfBjk46jI](https://www.youtube.com/watch?v=vkQfBjk46jI)