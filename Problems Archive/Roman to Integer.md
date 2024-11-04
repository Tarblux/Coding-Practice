Problem: 13
Official Difficulty: easy
Link: https://leetcode.com/problems/roman-to-integer/
Completed On : 2023-12-30
Feels Like : easy
Topic: Math, string
My Understanding: Needs Review
Last Review: 2024-10-29
Days Since Review: 6
Name: Roman to Integer 

# Roman to Integer 
### Problem
___
Roman numerals are represented by seven different symbols: `I`, `V`, `X`, `L`, `C`, `D` and `M`.
```plain text
SymbolValue
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
```
For example, `2` is written as `II` in Roman numeral, just two ones added together. `12` is written as `XII`, which is simply `X + II`. The number `27` is written as `XXVII`, which is `XX + V + II`.
Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not `IIII`. Instead, the number four is written as `IV`.
 Because the one is before the five we subtract it making four. The same
 principle applies to the number nine, which is written as `IX`. There are six instances where subtraction is used:
- `I` can be placed before `V` (5) and `X` (10) to make 4 and 9.
- `X` can be placed before `L` (50) and `C` (100) to make 40 and 90.
- `C` can be placed before `D` (500) and `M` (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer.
**Example 1:**
```plain text
Input: s = "III"
Output: 3
Explanation: III = 3.

```
**Example 2:**
```plain text
Input: s = "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.

```
**Example 3:**
```plain text
Input: s = "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.

```
**Constraints:**
- `1 <= s.length <= 15`
- `s` contains only the characters `('I', 'V', 'X', 'L', 'C', 'D', 'M')`.
- It is **guaranteed** that `s` is a valid roman numeral in the range `[1, 3999]`.
### My Solutions
___
Fully Dunce 
```python
class Solution:
    def romanToInt(self, s: str) -> int:
        
        if not s:
            return 0

        integer = 0
        
        i = len(s) - 1

        while i >= 0:
            
            if s[i] == "M" and (i == 0 or s[i-1] != "C"):
                
                integer += 1000
                i -= 1
                
            elif s[i] == "M" and s[i-1] == "C":
                
                integer += 900
                i -= 2
                
            elif s[i] == "D" and (i == 0 or s[i-1] != "C"):
                
                integer += 500
                i -= 1
                
            elif s[i] == "D" and s[i-1] == "C":
                
                integer += 400
                i -= 2
                
            elif s[i] == "C" and (i == 0 or s[i-1] != "X"):
                
                integer += 100
                i -= 1
                
            elif s[i] == "C" and s[i-1] == "X":
                
                integer += 90
                i -= 2
                
            elif s[i] == "L" and (i == 0 or s[i-1] != "X"):
                
                integer += 50
                i -= 1
                
            elif s[i] == "L" and s[i-1] == "X":
                
                integer += 40
                i -= 2
                
            elif s[i] == "X" and (i == 0 or s[i-1] != "I"):
                
                integer += 10
                i -= 1
                
            elif s[i] == "X" and s[i-1] == "I":
                
                integer += 9
                i -= 2
                
            elif s[i] == "V" and (i == 0 or s[i-1] != "I"):
                
                integer += 5
                i -= 1
                
            elif s[i] == "V" and s[i-1] == "I":
                
                integer += 4
                i -= 2
                
            elif s[i] == "I":
                integer += 1
                i -= 1

        return integer
```

Time Complexity :
```python
class Solution:
    def romanToInt(self, s: str) -> int:

        romans = {
            'I':1,
            'V':5,
            'X':10,
            'L':50,
            'C':100,
            'D':500,
            'M':1000,
        }
        
        subtractions = {
            'IV':4,
            'IX':9,
            'XL':40,
            'XC':90,
            'CD':400,
            'CM':900,
        }

        i = 0
        conversion = 0


        while i < len(s):

            cur_romans = s[i:i+2]

            if cur_romans in subtractions:
                conversion += subtractions[cur_romans]
                i += 2
            else:
                conversion += romans[s[i]]
                i += 1

        return conversion
```

Time Complexity : 
### Optimal Solutions
___
The "Roman to Integer" problem involves converting a Roman numeral to an integer. Roman numerals are represented by seven different symbols: I, V, X, L, C, D, and M.
#### Roman Numerals Rules:
- I can be placed before V (5) and X (10) to make 4 and 9.
- X can be placed before L (50) and C (100) to make 40 and 90.
- C can be placed before D (500) and M (1000) to make 400 and 900.
#### Solution Approach
To convert a Roman numeral to an integer, you can iterate over each character and add its value to a total sum. When a smaller numeral appears before a larger numeral, you subtract the smaller numeral's value instead of adding it.
#### Python Implementation
```python
class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        numerals = {
            "I": 1,
            "V": 5,
            "X": 10,
            "L": 50,
            "C": 100,
            "D": 500,
            "M": 1000
        }
        
        result = 0
        prevChar = 'I' # set it to the smallest roman character
        for char in s[::-1]:
            if numerals[char] < numerals[prevChar]:
                result -= numerals[char]
            else:
                result += numerals[char]
                
            prevChar = char
            
        return result

```
#### Explanation
- A dictionary `roman_values` is used to map Roman numeral characters to their integer values.
- We iterate over the Roman numeral string in reverse order.
- For each character, we get its value. If this value is less than the value of the previous character, it means we need to subtract this value (e.g., IV, where I comes before V, and we need to do 5 - 1). Otherwise, we add the value.
- The `total` variable keeps track of the cumulative sum, which is the integer representation of the Roman numeral.
#### Complexity Analysis
- **Time Complexity**: O(n), where n is the length of the Roman numeral string. Each character in the string is visited once.
- **Space Complexity**: O(1), as the space used does not depend on the size of the input string. The `roman_values` dictionary is a fixed size.
### Notes
___
 
### Related Videos 
___
[watch](https://www.youtube.com/watch?v=3jdxYj3DD98)