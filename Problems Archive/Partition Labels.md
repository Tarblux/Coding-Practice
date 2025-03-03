<<<<<<< Updated upstream
Problem: 763
Official Difficulty: medium
Link: https://leetcode.com/problems/partition-labels/description/
Completed On : 2024-12-16
Feels Like : medium
Topic: hash table, two pointers, string, greedy
My Understanding: Mostly Understand, Needs Review
Last Review: 2024-12-16
Days Since Review: 6
Name: Partition Labels

# Partition Labels
### Problem
___
You are given a string `s`. We want to partition the string into as many parts as possible so that each letter appears in at most one part.
Note that the partition is done so that after concatenating all the parts in order, the resultant string should be `s`.
Return *a list of integers representing the size of these parts*.
**Example 1:**
```plain text
=======
# Partition Labels

Problem: 763
Official Difficulty: medium
Feels Like : medium
My Understanding: Mostly Understand, Needs Review
Topic: greedy, hash table, string, two pointers
Link: https://leetcode.com/problems/partition-labels/description/
Completed On : December 16, 2024
Last Review: December 16, 2024
Days Since Review: 76
Neetcode: Yes

## Problem

---

You are given a string `s`. We want to partition the string into as many parts as possible so that each letter appears in at most one part.

Note that the partition is done so that after concatenating all the parts in order, the resultant string should be `s`.

Return *a list of integers representing the size of these parts*.

**Example 1:**

```
>>>>>>> Stashed changes
Input: s = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits s into less parts.
```
<<<<<<< Updated upstream
**Example 2:**
```plain text
Input: s = "eccbbbbdec"
Output: [10]
```
**Constraints:**
- `1 <= s.length <= 500`
- `s` consists of lowercase English letters.
### My Solutions
___
=======

**Example 2:**

```
Input: s = "eccbbbbdec"
Output: [10]
```

**Constraints:**

- `1 <= s.length <= 500`
- `s` consists of lowercase English letters.

## My Solutions

---

>>>>>>> Stashed changes
```python
class Solution:
    def partitionLabels(self, s: str) -> List[int]:

        last = {c:i for i,c in enumerate(s)}
        partition_end = float('-inf')
        start = 0
        output = []

        for i in range(len(s)):
            
            char = s[i] 
            partition_end = max(partition_end,last[char])

            if i == partition_end:
                output.append(i - start + 1)
                start = i + 1

            
        return output     
```

<<<<<<< Updated upstream
Time Complexity :
=======
>>>>>>> Stashed changes
```python

```

<<<<<<< Updated upstream
Time Complexity : 
### Optimal Solutions
___
Here is the solution to **LeetCode 763: Partition Labels** using the greedy approach:
___
#### **Approach**
1. **Track Last Occurrences:**
	- First, compute the last occurrence of each character in the string `s`. This tells us how far we need to go to include all instances of a character in a single partition.
2. **Iterate Through the String:**
	- As you iterate through the string, keep track of the farthest position (`end`) of any character seen so far in the current partition.
	- If the current index equals the `end`, it means all characters in the current partition have been fully included. At this point, you can "cut" the partition.
3. **Store Partition Sizes:**
	- Record the size of each partition as the difference between the current index (`end`) and the start of the partition.
4. **Repeat for the Entire String.**
This approach ensures that each partition is as small as possible while maximizing the number of partitions, as cuts are made at the earliest point where the current partition is complete.
___
#### **Code Implementation**
=======
## Optimal Solutions

---

Here is the solution to **LeetCode 763: Partition Labels** using the greedy approach:

---

### **Approach**

1. **Track Last Occurrences:**
    - First, compute the last occurrence of each character in the string `s`. This tells us how far we need to go to include all instances of a character in a single partition.
2. **Iterate Through the String:**
    - As you iterate through the string, keep track of the farthest position (`end`) of any character seen so far in the current partition.
    - If the current index equals the `end`, it means all characters in the current partition have been fully included. At this point, you can "cut" the partition.
3. **Store Partition Sizes:**
    - Record the size of each partition as the difference between the current index (`end`) and the start of the partition.
4. **Repeat for the Entire String.**

This approach ensures that each partition is as small as possible while maximizing the number of partitions, as cuts are made at the earliest point where the current partition is complete.

---

### **Code Implementation**

>>>>>>> Stashed changes
```python
class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        # Step 1: Record the last occurrence of each character
        last_occurrence = {char: idx for idx, char in enumerate(s)}

        # Step 2: Iterate through the string to create partitions
        partitions = []
        start = 0
        end = 0

        for i, char in enumerate(s):
            # Update the end of the current partition
            end = max(end, last_occurrence[char])

            # If we've reached the end of the current partition
            if i == end:
                # Add the size of the partition to the result
                partitions.append(end - start + 1)
                # Update the start for the next partition
                start = i + 1

        return partitions

```
<<<<<<< Updated upstream
___
#### **Example Walkthrough**
**Input:**
`s = "ababcbacadefegdehijhklij"`
5. **Step 1: Last Occurrence Table**
	- `last_occurrence = {'a': 8, 'b': 5, 'c': 7, 'd': 14, 'e': 15, 'f': 11, 'g': 13, 'h': 19, 'i': 22, 'j': 23, 'k': 20, 'l': 21}`
6. **Step 2: Partition the String**
	- Start iterating through `s`:
		- At `i = 0` to `i = 8`: `end = 8` (all characters `a`, `b`, and `c` are included). Cut partition `[0, 8]` of size `9`.
		- At `i = 9` to `i = 15`: `end = 15` (all characters `d`, `e`, `f`, and `g` are included). Cut partition `[9, 15]` of size `7`.
		- At `i = 16` to `i = 23`: `end = 23` (all characters `h`, `i`, `j`, `k`, `l` are included). Cut partition `[16, 23]` of size `8`.
**Output:**
`[9, 7, 8]`
___
#### **Complexity Analysis**
7. **Time Complexity:** O(n)
	- First pass to compute `last_occurrence` takes O(n).
	- Second pass to form partitions also takes O(n).
	- Total time complexity is O(n).
8. **Space Complexity:** O(1) (or O(26))
	- The `last_occurrence` dictionary uses space proportional to the number of unique characters, which is at most 26 for lowercase English letters.
___
#### **Explanation of Results**
The string is divided into partitions such that no character from one partition appears in another. Each partition is as small as possible while including all instances of its characters. This ensures the maximum number of partitions.
**Example Results:**
- `s = "ababcbacadefegdehijhklij"` → `[9, 7, 8]`
- `s = "eccbbbbdec"` → `[10]`
- `s = "a"` → `[1]`
This approach is efficient and adheres to the constraints of the problem.
### Notes
___
 
### Related Videos 
___
[B7m8UmZE-vw](https://youtu.be/B7m8UmZE-vw)
=======

---

### **Example Walkthrough**

**Input:**

`s = "ababcbacadefegdehijhklij"`

1. **Step 1: Last Occurrence Table**
    - `last_occurrence = {'a': 8, 'b': 5, 'c': 7, 'd': 14, 'e': 15, 'f': 11, 'g': 13, 'h': 19, 'i': 22, 'j': 23, 'k': 20, 'l': 21}`
2. **Step 2: Partition the String**
    - Start iterating through `s`:
        - At `i = 0` to `i = 8`: `end = 8` (all characters `a`, `b`, and `c` are included). Cut partition `[0, 8]` of size `9`.
        - At `i = 9` to `i = 15`: `end = 15` (all characters `d`, `e`, `f`, and `g` are included). Cut partition `[9, 15]` of size `7`.
        - At `i = 16` to `i = 23`: `end = 23` (all characters `h`, `i`, `j`, `k`, `l` are included). Cut partition `[16, 23]` of size `8`.

**Output:**

`[9, 7, 8]`

---

### **Complexity Analysis**

1. **Time Complexity:** O(n)
    - First pass to compute `last_occurrence` takes O(n).
    - Second pass to form partitions also takes O(n).
    - Total time complexity is O(n).
2. **Space Complexity:** O(1) (or O(26))
    - The `last_occurrence` dictionary uses space proportional to the number of unique characters, which is at most 26 for lowercase English letters.

---

### **Explanation of Results**

The string is divided into partitions such that no character from one partition appears in another. Each partition is as small as possible while including all instances of its characters. This ensures the maximum number of partitions.

**Example Results:**

- `s = "ababcbacadefegdehijhklij"` → `[9, 7, 8]`
- `s = "eccbbbbdec"` → `[10]`
- `s = "a"` → `[1]`

This approach is efficient and adheres to the constraints of the problem.

## Notes

---

 

## Related Videos

---

[https://youtu.be/B7m8UmZE-vw](https://youtu.be/B7m8UmZE-vw)
>>>>>>> Stashed changes
