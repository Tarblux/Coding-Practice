# Consecutive Characters

Problem: 1446
Official Difficulty: easy
My Understanding: Fully Understand
Feels Like : easy
Topic: string
Link: https://leetcode.com/problems/consecutive-characters/description/
Completed On : February 21, 2024
Last Review: February 21, 2024
Days Since Review: 5

## Problem

---

The **power** of the string is the maximum length of a non-empty substring that contains only one unique character.

Given a string `s`, return *the **power** of* `s`.

**Example 1:**

```
Input: s = "leetcode"
Output: 2
Explanation: The substring "ee" is of length 2 with the character 'e' only.

```

**Example 2:**

```
Input: s = "abbcccddddeeeeedcba"
Output: 5
Explanation: The substring "eeeee" is of length 5 with the character 'e' only.

```

**Constraints:**

- `1 <= s.length <= 500`
- `s` consists of only lowercase English letters.

## My Solutions

---

```python
class Solution:
    def maxPower(self, s: str) -> int:

        max_power = 0

        for i in range(len(s)) : 

            char = s[i] 

            count = 1

            index = i

            while index < len(s) - 1 : 

                if s[index+1] == char : 

                    count += 1

                    index += 1

                else : 

                    break

            max_power = max(max_power,count)

        return max_power
```

```python

```

## Optimal Solutions

---

The problem of finding the longest substring of consecutive characters typically asks you to identify the maximum length of a substring within a given string where all the characters are the same. This is a common string manipulation question that can be solved efficiently by iterating through the string once.

### Solution Approach

A straightforward approach involves iterating through the string while keeping track of the current character count and the maximum count found so far. You compare each character with the next one:

- If they are the same, you increase the current count.
- If they are different, you update the maximum count if the current count is greater and reset the current count.

### Python Implementation

Here's how you can implement this solution:

```python
class Solution:
    def maxPower(self, s: str) -> int:
        # Edge case: empty string
        if not s:
            return 0

        max_count = 1
        current_count = 1

        for i in range(1, len(s)):
            if s[i] == s[i-1]:
                # If the current character is the same as the previous,
                # increase the current streak count.
                current_count += 1
            else:
                # If different, update max_count if necessary and reset current_count.
                max_count = max(max_count, current_count)
                current_count = 1

        # Update max_count for the last character streak
        max_count = max(max_count, current_count)

        return max_count

```

### Explanation

- **Initialization**: `max_count` and `current_count` are initialized to 1 since any non-empty string has a minimum consecutive character length of 1.
- **Iteration**: The for-loop starts from the second character of the string (`range(1, len(s))`) because the comparison is between the current character and its predecessor.
- **Count Update**: Within the loop, if the current character (`s[i]`) is the same as the previous one (`s[i-1]`), `current_count` is incremented. Otherwise, `max_count` is updated if `current_count` is greater, and then `current_count` is reset to 1 for a new character streak.
- **Final Update**: After the loop, there's a final update for `max_count` to account for the possibility that the longest streak ends at the last character of the string.
- **Return**: The function returns `max_count`, which holds the length of the longest substring of consecutive characters.

### Complexity Analysis

- **Time Complexity**: O(N), where N is the length of the string `s`. The string is traversed once.
- **Space Complexity**: O(1), as the solution uses a constant amount of extra space, regardless of the input size.

## Notes

---

 

## Related Videos

---

[https://www.notion.so](https://www.notion.so)