Problem: 17
Official Difficulty: medium
Link: https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
Completed On : 2024-03-26
Feels Like : medium
Topic: hash table, string, backtracking
My Understanding: Mostly Understand
Last Review: 2024-10-15
Days Since Review: 5
Name: Letter Combinations of a Phone Number

# Letter Combinations of a Phone Number
### Problem
___
Given a string containing digits from `2-9` inclusive, return all possible letter combinations that the number could represent. Return the answer in **any order**.
A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
![1200px-telephone-keypad2svg.png](https://assets.leetcode.com/uploads/2022/03/15/1200px-telephone-keypad2svg.png)
**Example 1:**
```plain text
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
```
**Example 2:**
```plain text
Input: digits = ""
Output: []
```
**Example 3:**
```plain text
Input: digits = "2"
Output: ["a","b","c"]
```
**Constraints:**
- `0 <= digits.length <= 4`
- `digits[i]` is a digit in the range `['2', '9']`.
### My Solutions
___
```python
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:

        if not digits:
            return []

        phone = {
            "2": ["a", "b", "c"],
            "3": ["d", "e", "f"],
            "4": ["g", "h", "i"],
            "5": ["j", "k", "l"],
            "6": ["m", "n", "o"],
            "7": ["p", "q", "r", "s"],
            "8": ["t", "u", "v"],
            "9": ["w", "x", "y", "z"],
        }

        combinations = []

        def backtrack(idx, path):

            if idx == len(digits):
                combinations.append(path)
                return

            for letter in phone[digits[idx]]:
                backtrack(idx + 1, path + letter)

        backtrack(0, "")

        return combinations

```

Time Complexity :
```python

```

Time Complexity : 
### Optimal Solutions
___
To complete the function `letterCombinations` which finds all possible letter combinations that the number could represent, based on a mapping similar to the number buttons on a traditional phone keypad, we need to iterate over each group of letters associated with the input digits and combine them in all possible ways. This can be efficiently done using a queue to maintain the current combinations and updating it as we process each digit. Since you asked for a solution using nested loops, I'll adapt the logic to fit that request, but it's worth mentioning that a more efficient solution might not strictly use nested loops in the traditional sense.
Here's a completion of your function using nested for loops:
```python
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if not digits:
            return []

        letters = {
            '2': ['a', 'b', 'c'],
            '3': ['d', 'e', 'f'],
            '4': ['g', 'h', 'i'],
            '5': ['j', 'k', 'l'],
            '6': ['m', 'n', 'o'],
            '7': ['p', 'q', 'r', 's'],
            '8': ['t', 'u', 'v'],
            '9': ['w', 'x', 'y', 'z']
        }

        letter_groups = [letters[num] for num in digits]
        letter_combinations = [""]  # Start with an empty combination to build upon

        for group in letter_groups:
            new_combinations = []
            for prefix in letter_combinations:
                for letter in group:
                    new_combinations.append(prefix + letter)
            letter_combinations = new_combinations  # Update with new combinations

        return letter_combinations
```
This code works by first translating each digit into its corresponding group of letters. Then, it initializes the result list with an empty string to handle concatenation in the first iteration properly. For each group of letters corresponding to a digit, it combines every letter in the group with all the combinations generated in the previous step, updating the combinations list in the process. This way, it constructs all possible letter combinations that can be derived from the input digit string.
For the problem "17. Letter Combinations of a Phone Number", you're given a string containing digits from 2-9 and need to return all possible letter combinations that the number could represent, based on the classic telephone keypad layout. Here's an efficient way to solve this problem using a backtracking approach, which is well-suited for generating combinations or permutations.
#### Python Solution:
```python
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if not digits:
            return []

        # Mapping of digits to letters
        phoneMap = {
            "2": "abc", "3": "def", "4": "ghi", "5": "jkl",
            "6": "mno", "7": "pqrs", "8": "tuv", "9": "wxyz"
        }

        def backtrack(index: int, path: str):
            # If the path is the same length as digits, we have a complete combination
            if len(path) == len(digits):
                combinations.append(path)
                return

            # Get the letters that the current digit maps to, and loop through them
            possible_letters = phoneMap[digits[index]]
            for letter in possible_letters:
                backtrack(index + 1, path + letter)

        combinations = []
        backtrack(0, "")
        return combinations

```
#### How It Works:
1. **Base Case**: If the input `digits` string is empty, immediately return an empty list, as there are no combinations possible.
2. **Backtracking Function**: The core of this solution is a backtracking function (`backtrack`) that builds combinations one letter at a time. For each digit in the input, it appends all possible letters that the digit could represent to a partially formed combination (`path`), and recursively proceeds to add letters for the next digit.
	- The `index` parameter tracks the current position in the `digits` string being processed.
	- The `path` parameter is a string that accumulates letters chosen so far.
3. **Termination Condition**: When the length of the `path` string equals the length of the `digits` string, it means a complete combination has been formed, so it's added to the list of `combinations`.
4. **Exploring Possibilities**: For each digit, the function iterates through all letters that the digit maps to (using the `phoneMap` dictionary), appending each letter to the current path and recursing to add letters for the next digit.
5. **Combination Accumulation**: A list named `combinations` is used to accumulate all valid combinations generated by the backtracking process.
#### Complexity Analysis:
- **Time Complexity**: O(4^N * N), where N is the length of the input `digits` string. In the worst case, each digit maps to 4 letters (e.g., digits 7 or 9), leading to at most 4^N combinations, and constructing each combination takes O(N) time.
- **Space Complexity**: O(N), due to the recursion call stack and the space used to store `path`. The maximum depth of the recursive call stack is N, where N is the length of the input digits.
### Notes
___
 
### Related Videos 
___
[watch](https://www.youtube.com/watch?v=0snEunUacZY&pp=ygUlbGV0dGVyIGNvbWJpbmF0aW9ucyBvZiBhIHBob25lIG51bWJlcg%3D%3D)