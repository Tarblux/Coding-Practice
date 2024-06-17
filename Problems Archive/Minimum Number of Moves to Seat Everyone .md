# Minimum Number of Moves to Seat Everyone

Problem: 2037
Official Difficulty: easy
Feels Like : easy breazy
My Understanding: Fully Understand
Topic: array, greedy, sorting
Link: https://leetcode.com/problems/minimum-number-of-moves-to-seat-everyone/
Completed On : June 13, 2024
Last Review: June 13, 2024
Days Since Review: 3

## Problem

---

`ith` seat. You are also given the array `students` of length `n`, where `students[j]` is the position of the `jth` student.

You may perform the following move any number of times:

- Increase or decrease the position of the `ith` student by `1` (i.e., moving the `ith` student from position `x` to `x + 1` or `x - 1`)

Return *the **minimum number of moves** required to move each student to a seat such that no two students are in the same seat.*

Note that there may be **multiple** seats or students in the **same** position at the beginning.

**Example 1:**

```
Input: seats = [3,1,5], students = [2,7,4]
Output: 4
Explanation: The students are moved as follows:
- The first student is moved from from position 2 to position 1 using 1 move.
- The second student is moved from from position 7 to position 5 using 2 moves.
- The third student is moved from from position 4 to position 3 using 1 move.
In total, 1 + 2 + 1 = 4 moves were used.
```

**Example 2:**

```
Input: seats = [4,1,5,9], students = [1,3,2,6]
Output: 7
Explanation: The students are moved as follows:
- The first student is not moved.
- The second student is moved from from position 3 to position 4 using 1 move.
- The third student is moved from from position 2 to position 5 using 3 moves.
- The fourth student is moved from from position 6 to position 9 using 3 moves.
In total, 0 + 1 + 3 + 3 = 7 moves were used.
```

**Example 3:**

```
Input: seats = [2,2,6,6], students = [1,3,2,6]
Output: 4
Explanation: Note that there are two seats at position 2 and two seats at position 6.
The students are moved as follows:
- The first student is moved from from position 1 to position 2 using 1 move.
- The second student is moved from from position 3 to position 6 using 3 moves.
- The third student is not moved.
- The fourth student is not moved.
In total, 1 + 3 + 0 + 0 = 4 moves were used.
```

**Constraints:**

- `n == seats.length == students.length`
- `1 <= n <= 100`
- `1 <= seats[i], students[j] <= 100`

## My Solutions

---

```python
class Solution:
    def minMovesToSeat(self, seats: List[int], students: List[int]) -> int:

        """
        - Sort List to place students close to the closest seat
        - Create Zip iterator of students and closest seat
        - Compare current student position and seat and sum differences

        TC: O(nlogn)
        SC: O(1)
        """

        seats.sort()
        students.sort()

        moves = 0

        for stu , pos in zip(students,seats):

            moves += abs(stu-pos)

        return moves
```

```python

```

## Optimal Solutions

---

### Problem Description

Given two arrays `seats` and `students`, return the minimum number of moves required to move each student to a seat such that the absolute difference between the student's position and the seat's position is minimized. Each student should be seated in exactly one seat.

### Example

```python
Input: seats = [3,1,5], students = [2,7,4]
Output: 4

Input: seats = [4,1,5,9], students = [1,3,2,6]
Output: 7

Input: seats = [2,2,6,6], students = [1,3,2,6]
Output: 4

```

### Optimal Solution and Explanation

To minimize the total number of moves, we can follow these steps:

1. **Sort Both Arrays**: By sorting both `seats` and `students` arrays, we can pair each student with the closest available seat.
2. **Calculate the Moves**: After sorting, for each pair of seat and student, calculate the absolute difference in their positions and sum these differences.

### Steps:

1. **Sort the Arrays**: Sort the `seats` and `students` arrays.
2. **Pair and Calculate Moves**: Iterate through the sorted arrays and sum the absolute differences between corresponding elements.

### Python Code

Here's the Python code to achieve this:

```python
def minMovesToSeat(seats, students):
    # Sort the seats and students arrays
    seats.sort()
    students.sort()

    # Calculate the total number of moves
    total_moves = 0
    for seat, student in zip(seats, students):
        total_moves += abs(seat - student)

    return total_moves

# Example usage
print(minMovesToSeat([3, 1, 5], [2, 7, 4]))  # Output: 4
print(minMovesToSeat([4, 1, 5, 9], [1, 3, 2, 6]))  # Output: 7
print(minMovesToSeat([2, 2, 6, 6], [1, 3, 2, 6]))  # Output: 4

```

### Explanation

1. **Sorting**:
    - Sorting both `seats` and `students` ensures that each student is paired with the closest available seat.
    - For example, if `seats = [3, 1, 5]` and `students = [2, 7, 4]`, sorting them results in `seats = [1, 3, 5]` and `students = [2, 4, 7]`.
2. **Pairing and Calculating Moves**:
    - After sorting, pair each student with the corresponding seat and calculate the absolute difference.
    - Sum these differences to get the total number of moves.
    - For the sorted arrays above, the pairs are `(1, 2)`, `(3, 4)`, and `(5, 7)`. The absolute differences are `1`, `1`, and `2`, respectively, giving a total of `4` moves.

### Time Complexity Analysis

- **Time Complexity**: `O(n log n)`
    - Sorting the arrays takes `O(n log n)`, where `n` is the number of elements in the arrays.
    - Calculating the moves takes `O(n)`.
- **Overall Time Complexity**: `O(n log n)`

### Space Complexity Analysis

- **Space Complexity**: `O(1)`
    - The algorithm uses a constant amount of extra space, excluding the input and output.

This approach ensures that each student is seated in the closest available seat, minimizing the total number of moves required.

## Notes

---

 

## Related Videos

---

[https://www.notion.so](https://www.notion.so)