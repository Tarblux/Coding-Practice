Problem: 2109
Official Difficulty: medium
Link: https://leetcode.com/problems/adding-spaces-to-a-string/description/
Completed On : 2024-12-02
Feels Like : easy
Topic: array, two pointers, string, simulation
My Understanding: Fully Understand
Last Review: 2024-12-02
Days Since Review: 6
Name: Adding Spaces to a String

# Adding Spaces to a String
### Problem
___
You are given a **0-indexed** string `s` and a **0-indexed** integer array `spaces` that describes the indices in the original string where spaces will be added. Each space should be inserted **before** the character at the given index.
- For example, given `s = "EnjoyYourCoffee"` and `spaces = [5, 9]`, we place spaces before `'Y'` and `'C'`, which are at indices `5` and `9` respectively. Thus, we obtain `"Enjoy ``<u>**Y**</u>``our ``<u>**C**</u>``offee"`.
Return** ***the modified string ****after**** the spaces have been added.*
**Example 1:**
```plain text
Input: s = "LeetcodeHelpsMeLearn", spaces = [8,13,15]
Output: "Leetcode Helps Me Learn"
Explanation:
The indices 8, 13, and 15 correspond to the underlined characters in "LeetcodeHelpsMeLearn".
We then place spaces before those characters.
```
**Example 2:**
```plain text
Input: s = "icodeinpython", spaces = [1,5,7,9]
Output: "i code in py thon"
Explanation:
The indices 1, 5, 7, and 9 correspond to the underlined characters in "icodeinpython".
We then place spaces before those characters.
```
**Example 3:**
```plain text
Input: s = "spacing", spaces = [0,1,2,3,4,5,6]
Output: " s p a c i n g"
Explanation:
We are also able to place spaces before the first character of the string.
```
**Constraints:**
- `1 <= s.length <= 3 * 105`
- `s` consists only of lowercase and uppercase English letters.
- `1 <= spaces.length <= 3 * 105`
- `0 <= spaces[i] <= s.length - 1`
- All the values of `spaces` are **strictly increasing**.
### My Solutions
___
```python
class Solution:
    def addSpaces(self, s: str, spaces: List[int]) -> str:

        output = []
        idx = 0
        spaces = set(spaces)

        while idx < len(s):

            if idx in spaces:
                output.append(' ')
                output.append(s[idx])
            else:
                output.append(s[idx])
            idx += 1

        return ''.join(output)
```

Time Complexity :
```python

```

Time Complexity : 
### Optimal Solutions
___
To solve **LeetCode Problem 2109: Adding Spaces to a String**, we need to insert spaces into a given string `s` at specified indices provided in the array `spaces`. The challenge is to perform this efficiently, considering the large constraints (up to `3 * 10^5` characters).
___
#### **Optimal Algorithm: Two-Pointer Technique**
#### **Algorithm Overview**
- **Objective:** Insert spaces into the string `s` at the indices specified in the array `spaces`.
- **Constraints:**
	- `s` can be up to `3 * 10^5` characters long.
	- `spaces` can contain up to `3 * 10^5` indices.
	- All indices in `spaces` are strictly increasing.
- **Approach:**
	- Use a two-pointer technique to iterate over the string `s` and the `spaces` array simultaneously.
	- Build the result using a list to efficiently append characters and spaces.
	- This method ensures we achieve linear time complexity O(N), where N is the length of the string `s`.
#### **Algorithm Steps**
1. **Initialize Pointers and Result List:**
	- Set `i = 0` to iterate over the characters in `s`.
	- Set `j = 0` to iterate over the indices in `spaces`.
	- Initialize an empty list `result` to build the final string.
2. **Iterate Over the String:**
	- While `i < len(s)`:
		- **Check for Space Insertion:**
			- If `j < len(spaces)` and `i == spaces[j]`:
				- Append a space `' '` to `result`.
				- Increment `j` by 1 (move to the next index in `spaces`).
		- **Append Current Character:**
			- Append `s[i]` to `result`.
		- Increment `i` by 1 (move to the next character in `s`).
3. **Construct the Final String:**
	- Join the list `result` into a string using `''.join(result)`.
4. **Return the Final String:**
	- Return the constructed string as the result.
#### **Code Implementation**
```python
class Solution:
    def addSpaces(self, s: str, spaces: List[int]) -> str:
        result = []
        i = 0  # Pointer for string s
        j = 0  # Pointer for spaces array
        n = len(s)
        m = len(spaces)

        while i < n:
            # Check if we need to insert a space at the current index
            if j < m and i == spaces[j]:
                result.append(' ')
                j += 1  # Move to the next space index
            result.append(s[i])
            i += 1  # Move to the next character in s

        return ''.join(result)

```
#### **Example Walkthrough**
**Example 1:**
- **Input:**
```plain text
s = "LeetcodeHelpsMeLearn"
spaces = [8, 13, 15]

```
- **Process:**
	- Initialize `result = []`, `i = 0`, `j = 0`.
	- Iterate over `s`, inserting spaces at indices 8, 13, and 15.
	- Build `result` step by step:
		- At `i = 8` (spaces[0]), insert a space before `s[8]` ('H').
		- At `i = 13` (spaces[1]), insert a space before `s[13]` ('M').
		- At `i = 15` (spaces[2]), insert a space before `s[15]` ('L').
	- Final `result` list contains characters and spaces in the correct order.
- **Output:**
```plain text
"Leetcode Helps Me Learn"

```
#### **Time Complexity Analysis**
- **Time Complexity:** O(N)
	- **Explanation:** We iterate over each character in the string `s` exactly once.
	- Insertion of spaces is done in constant time per space.
	- Overall time complexity is linear with respect to the length of `s`.
- **Space Complexity:** O(N)
	- **Explanation:** We use an additional list `result` to store the characters and spaces, which can be up to size `N + M`, where `M` is the number of spaces.
	- Since `M` is at most `N`, the space complexity is O(N).
#### **Alternative Approach: Using StringBuilder (Language Dependent)**
In some programming languages, such as Java, strings are immutable, and concatenation can be inefficient. Using a `StringBuilder` or similar data structure can improve performance by avoiding the creation of many intermediate string objects.
In Python, using a list to collect characters and then joining them at the end is the most efficient way for string building.
___
#### **Summary**
By using the two-pointer technique and building the result in a list, we efficiently insert spaces into the string without incurring a performance penalty from string concatenation in a loop. This approach ensures that the algorithm runs in linear time and is suitable for large inputs within the given constraints.
___
**Note:** The code provided above is a complete solution that can be directly used to solve the problem on LeetCode or similar platforms.
### Notes
___
 
### Related Videos 
___
[]()