Problem: 12
Official Difficulty: medium
Link: https://leetcode.com/problems/integer-to-roman/description/
Completed On : 2024-12-03
Feels Like : medium
Topic: hash table, array, string
My Understanding: Needs Review
Last Review: 2024-12-03
Days Since Review: 5
Name: Integer to Roman

# Integer to Roman
### Problem
___
Seven different symbols represent Roman numerals with the following values:

|**Symbol**|**Value**|
|---|---|
|I|1|
|V|5|
|X|10|
|L|50|
|C|100|
|D|500|
|M|1000|
Roman numerals are formed by appending the conversions of decimal place values from highest to lowest. Converting a decimal place value into a Roman numeral has the following rules:
- If the value does not start with 4 or 9, select the symbol of the maximal value that can be subtracted from the input, append that symbol to the result, subtract its value, and convert the remainder to a Roman numeral.
- If the value starts with 4 or 9 use the **subtractive form** representing one symbol subtracted from the following symbol, for example, 4 is 1 (`I`) less than 5 (`V`): `IV` and 9 is 1 (`I`) less than 10 (`X`): `IX`. Only the following subtractive forms are used: 4 (`IV`), 9 (`IX`), 40 (`XL`), 90 (`XC`), 400 (`CD`) and 900 (`CM`).
- Only powers of 10 (`I`, `X`, `C`, `M`) can be appended consecutively at most 3 times to represent multiples of 10. You cannot append 5 (`V`), 50 (`L`), or 500 (`D`) multiple times. If you need to append a symbol 4 times use the **subtractive form**.
Given an integer, convert it to a Roman numeral.
**Example 1:**
**Input:** num = 3749
**Output:** "MMMDCCXLIX"
**Explanation:**
```plain text
3000 = MMM as 1000 (M) + 1000 (M) + 1000 (M)
 700 = DCC as 500 (D) + 100 (C) + 100 (C)
  40 = XL as 10 (X) less of 50 (L)
   9 = IX as 1 (I) less of 10 (X)
Note: 49 is not 1 (I) less of 50 (L) because the conversion is based on decimal places

```
**Example 2:**
**Input:** num = 58
**Output:** "LVIII"
**Explanation:**
```plain text
50 = L
 8 = VIII

```
**Example 3:**
**Input:** num = 1994
**Output:** "MCMXCIV"
**Explanation:**
```plain text
1000 = M
 900 = CM
  90 = XC
   4 = IV

```
**Constraints:**
- `1 <= num <= 3999`
### My Solutions
___
My semi try , not right tho
```python
class Solution:
    def intToRoman(self, num: int) -> str:

        romans = {
        1:'I',
        4:'IV',
        5:'V',
        9:'IX',
        10:'X',
        40:'XL',
        50:'L',
        90:'XC',
        100:'C',
        400:'CD',
        500:'D',
        900:'CM',
        1000:'M'
        }

        output = []
        place = 1

        while num:

            digit = num % 10
            number = digit * place

            if digit in [4,9]:
                output.append(romans[number])
            elif number in romans:
                output.append(romans[number])

            elif number > 500 and:
                output.append(romans[500])
                number -= 500
                digiti = number // place
                duplicate = romans[place] * digiti
                output.append(duplicate)
            else:
                duplicate = romans[place] * digit
                output.append(duplicate)
            
            num //= 10
            place *= 10

        return ''.join(output[::-1])


        
```

Time Complexity :
### Improvement of Above : 
Certainly! Let's adjust your original approach to make it work correctly for converting integers to Roman numerals.
#### **Issues in Your Original Code**
1. **Incorrect Handling of Digits Greater Than 5:**
	- For digits like 6, 7, 8, the code doesn't correctly build numerals like 'VI', 'VII', 'VIII'.
	- The code multiplies the symbol for '1' (e.g., 'I') by the digit, which leads to incorrect representations like 'IIIIIIII' for 8.
2. **Processing Digits in Reverse Order:**
	- While reversing the output can work, it's more reliable to process the number from the highest place value to the lowest to maintain the correct order, especially because Roman numerals are not purely positional.
3. **Inconsistent Handling of Place Values:**
	- The code doesn't correctly handle different symbols for tens, hundreds, and thousands places.
#### **Adjustments to Make the Approach Work**
We'll modify your code to:
- **Process the number from the lowest to the highest place value**, but correctly map each digit to its Roman numeral considering its place.
- **Use symbol mappings for each place value** (ones, tens, hundreds, thousands).
- **Handle special cases for 4 and 9** correctly in each place value.
- **Construct the Roman numeral for each digit based on its place value**.
Here's the corrected code:
```python
class Solution:
    def intToRoman(self, num: int) -> str:
        # Mappings for symbols in ones, tens, hundreds, and thousands places
        symbol_map = {
            1: ('I', 'V', 'X'),      # Ones place
            10: ('X', 'L', 'C'),     # Tens place
            100: ('C', 'D', 'M'),    # Hundreds place
            1000: ('M', '', ''),     # Thousands place (no symbols for 5000 and 10000)
        }

        output = []
        place = 1

        while num > 0:
            digit = num % 10
            num //= 10

            if digit == 0:
                place *= 10
                continue

            one, five, ten = symbol_map[place]

            # Build the Roman numeral for the current digit
            if digit == 9:
                output.append(one + ten)
            elif digit >= 5:
                output.append(five + one * (digit - 5))
            elif digit == 4:
                output.append(one + five)
            else:
                output.append(one * digit)

            place *= 10

        # Since we processed from lowest to highest place value, reverse the output
        return ''.join(output[::-1])

```
#### **Explanation of the Adjustments**
4. **Symbol Mappings per Place Value:**
	- We define `symbol_map` to provide the correct symbols for each place value.
		- **Ones Place (1):** 'I', 'V', 'X'
		- **Tens Place (10):** 'X', 'L', 'C'
		- **Hundreds Place (100):** 'C', 'D', 'M'
		- **Thousands Place (1000):** 'M', '', ''
	- Each tuple contains symbols for:
		- `one`: The symbol representing one unit of the current place.
		- `five`: The symbol representing five units of the current place.
		- `ten`: The symbol representing ten units of the current place.
5. **Processing Each Digit:**
	- We extract each digit and its corresponding place value.
	- We skip processing if the digit is zero.
	- For each digit, we use the appropriate symbols from `symbol_map` to build the Roman numeral.
6. **Building the Roman Numeral for Each Digit:**
	- **Digit == 9:**
		- Represented as `one + ten` (e.g., 'IX' for 9 in ones place).
	- **Digit >= 5:**
		- Represented as `five + one * (digit - 5)` (e.g., 'VI' for 6).
	- **Digit == 4:**
		- Represented as `one + five` (e.g., 'IV' for 4).
	- **Digit < 4:**
		- Represented as `one * digit` (e.g., 'III' for 3).
7. **Reversing the Output:**
	- Since we process the digits from least significant to most significant, we need to reverse the output to get the correct Roman numeral order.
#### **Example Walkthrough**
Let's convert **num = 58** step by step:
- **Initialize:**
	- `output = []`
	- `place = 1`
- **First Iteration (Ones Place):**
	- `digit = 58 % 10 = 8`
	- `num = 58 // 10 = 5`
	- Symbols: `one = 'I'`, `five = 'V'`, `ten = 'X'`
	- Since `digit >= 5`, we build:
		- `'V' + 'I' * (8 - 5) = 'V' + 'III' = 'VIII'`
	- `output = ['VIII']`
	- `place *= 10` → `place = 10`
- **Second Iteration (Tens Place):**
	- `digit = 5 % 10 = 5`
	- `num = 5 // 10 = 0`
	- Symbols: `one = 'X'`, `five = 'L'`, `ten = 'C'`
	- Since `digit >= 5`, we build:
		- `'L' + 'X' * (5 - 5) = 'L' + '' = 'L'`
	- `output = ['VIII', 'L']`
	- `place *= 10` → `place = 100`
- **Final Step:**
	- Since `num = 0`, we exit the loop.
	- Reverse `output`: `['L', 'VIII']`
	- Join to get `'LVIII'`
#### **Testing the Corrected Code**
Let's test the corrected code with some examples:
#### **Example 1:**
- **Input:** `num = 3`
- **Output:** `'III'`
#### **Example 2:**
- **Input:** `num = 4`
- **Output:** `'IV'`
#### **Example 3:**
- **Input:** `num = 9`
- **Output:** `'IX'`
#### **Example 4:**
- **Input:** `num = 58`
- **Output:** `'LVIII'`
#### **Example 5:**
- **Input:** `num = 1994`
- **Output:** `'MCMXCIV'`
#### **Full Corrected Code**
```python
class Solution:
    def intToRoman(self, num: int) -> str:
        # Mappings for symbols in ones, tens, hundreds, and thousands places
        symbol_map = {
            1: ('I', 'V', 'X'),      # Ones place
            10: ('X', 'L', 'C'),     # Tens place
            100: ('C', 'D', 'M'),    # Hundreds place
            1000: ('M', '', ''),     # Thousands place (no symbols for 5000 and 10000)
        }

        output = []
        place = 1

        while num > 0:
            digit = num % 10
            num //= 10

            if digit == 0:
                place *= 10
                continue

            one, five, ten = symbol_map[place]

            # Build the Roman numeral for the current digit
            if digit == 9:
                output.append(one + ten)
            elif digit >= 5:
                output.append(five + one * (digit - 5))
            elif digit == 4:
                output.append(one + five)
            else:
                output.append(one * digit)

            place *= 10

        # Since we processed from lowest to highest place value, reverse the output
        return ''.join(output[::-1])

```
#### **Explanation of How the Code Works**
- **Processing Order:**
	- The code processes each digit starting from the ones place up to the thousands place.
	- It correctly handles the special cases for Roman numerals where subtraction is used (e.g., 'IV' for 4, 'IX' for 9).
- **Building the Output:**
	- For each digit, we build the corresponding Roman numeral string and append it to the `output` list.
	- We reverse the `output` list at the end to assemble the final Roman numeral.
- **Reversing the Output:**
	- Since we're processing from the least significant digit upwards, we need to reverse the `output` list to get the correct order.
#### **Why This Approach Works**
- **Alignment with Roman Numeral Rules:**
	- The approach adheres to the standard rules for Roman numerals, handling the subtractive notation correctly.
- **Place Value Consideration:**
	- By using the `symbol_map`, we correctly represent each digit according to its place value.
- **Efficiency:**
	- The code avoids unnecessary complexity and remains efficient by directly mapping digits to their Roman numeral equivalents.
#### **Conclusion**
By adjusting your original approach with these modifications, we've made it work correctly. The key was to:
- Use symbol mappings for each place value.
- Correctly handle digits, especially for special cases like 4 and 9.
- Reverse the output at the end to maintain the correct order.
___
**Feel free to run this code with different inputs to verify that it works correctly. Let me know if you have any questions or need further clarification!**
```python
class Solution:
    def intToRoman(self, num: int) -> str:

        romans = {
        1000:'M',
        900:'CM',
        500:'D',
        400:'CD',
        100:'C',
        90:'XC',
        50:'L',
        40:'XL',
        10:'X',
        9:'IX',
        5:'V',
        4:'IV',
        1:'I',
        }

        output = ''

        for value in romans:

            freq = num // value

            if freq:

                output += freq * romans[value]
                num -= freq * value

        return output
```

Time Complexity : 
### Optimal Solutions
___
## LeetCode Problem 12: Integer to Roman
### Problem Description
Roman numerals are represented by seven different symbols: `I`, `V`, `X`, `L`, `C`, `D`, and `M`.

|Symbol|Value|
|---|---|
|I|1|
|V|5|
|X|10|
|L|50|
|C|100|
|D|500|
|M|1000|
For example, **2** is written as `II` in Roman numeral, just two one's added together. **12** is written as `XII`, which is simply `X` + `II`. The number **27** is written as `XXVII`, which is `XX` + `V` + `II`.
Roman numerals are usually written largest to smallest from left to right. However, the numeral for **4** is not `IIII`. Instead, the number **4** is written as `IV`. Because the one is before the five, we subtract it making four. The same principle applies to the number **9**, which is written as `IX`.
There are six instances where subtraction is used:
- `I` can be placed before `V` (5) and `X` (10) to make **4** and **9**.
- `X` can be placed before `L` (50) and `C` (100) to make **40** and **90**.
- `C` can be placed before `D` (500) and `M` (1000) to make **400** and **900**.
Given an integer, convert it to a Roman numeral.
**Example 1:**
```plain text
Input: num = 3
Output: "III"

```
**Example 2:**
```plain text
Input: num = 4
Output: "IV"

```
**Example 3:**
```plain text
Input: num = 9
Output: "IX"

```
**Example 4:**
```plain text
Input: num = 58
Output: "LVIII"
Explanation: L = 50, V = 5, III = 3.

```
**Example 5:**
```plain text
Input: num = 1994
Output: "MCMXCIV"
Explanation: M = 1000, CM = 900, XC = 90, IV = 4.

```
**Constraints:**
- `1 <= num <= 3999`
___
### Solution Overview
To convert an integer to a Roman numeral, we can use a greedy approach:
- We have a list of Roman numerals and their corresponding integer values, ordered from largest to smallest.
- We iterate over this list, subtracting the largest possible Roman numeral values from the number until we reach zero.
- We append the corresponding Roman numerals to the result string.
#### Algorithm Steps
8. **Create a List of Roman Numerals:**
	- We need a list of tuples where each tuple contains the integer value and its corresponding Roman numeral symbol.
	- The list should be ordered from largest to smallest, including the subtractive combinations.
```python
val_syms = [
    (1000, 'M'),
    (900, 'CM'),
    (500, 'D'),
    (400, 'CD'),
    (100, 'C'),
    (90, 'XC'),
    (50, 'L'),
    (40, 'XL'),
    (10, 'X'),
    (9, 'IX'),
    (5, 'V'),
    (4, 'IV'),
    (1, 'I'),
]

```
9. **Initialize Result String:**
	- Start with an empty string `result = ''`.
10. **Iterate Over the List:**
	- For each `(value, symbol)` in `val_syms`:
		- While `num >= value`:
			- Subtract `value` from `num`.
			- Append `symbol` to `result`.
11. **Return the Result:**
	- After processing all symbols, return the `result` string.
___
### Code Implementation
```python
class Solution:
    def intToRoman(self, num: int) -> str:
        val_syms = [
            (1000, 'M'),
            (900, 'CM'),
            (500, 'D'),
            (400, 'CD'),
            (100, 'C'),
            (90, 'XC'),
            (50, 'L'),
            (40, 'XL'),
            (10, 'X'),
            (9, 'IX'),
            (5, 'V'),
            (4, 'IV'),
            (1, 'I'),
        ]

        result = ''
        for value, symbol in val_syms:
            while num >= value:
                num -= value
                result += symbol
        return result

```
___
### Time and Space Complexity Analysis
#### Time Complexity
- **O(1)**: Since the input number `num` is constrained to be between 1 and 3999, the maximum number of iterations in the worst case is limited (e.g., for `num = 3999`, the maximum number of symbols is around 15).
- Therefore, we can consider the time complexity as constant time O(1).
#### Space Complexity
- **O(1)**: The space used for the `result` string is proportional to the number of symbols appended, which is limited by the constraints.
- The list `val_syms` is of fixed size.
- Therefore, the space complexity is constant O(1).
___
### Detailed Explanation
- The Roman numerals are constructed by repeatedly matching the largest possible symbol that does not exceed the remaining value of `num`.
- By arranging the `val_syms` list from largest to smallest, including subtractive notations (e.g., `CM` for 900), we ensure that we always choose the appropriate symbol.
- The algorithm subtracts the value of the symbol from `num` and appends the symbol to the result string until `num` is reduced to zero.
___
### Alternative Approach: Using Hard-Coded Mappings
An alternative method is to handle thousands, hundreds, tens, and ones separately using arrays for each digit's possible Roman numeral representations.
#### Algorithm Steps
12. **Create Arrays for Each Place Value:**
```python
thousands = ["", "M", "MM", "MMM"]
hundreds  = ["", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"]
tens      = ["", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"]
ones      = ["", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"]
```
13. **Split the Number into Digits:**
	- Get the thousands, hundreds, tens, and ones digits.
```python
th = num // 1000
h = (num % 1000) // 100
t = (num % 100) // 10
o = num % 10
```
14. **Construct the Roman Numeral:**
	- Concatenate the Roman numerals for each digit.
```python
result = thousands[th] + hundreds[h] + tens[t] + ones[o]
```
15. **Return the Result:**
	- Return the constructed `result` string.
#### Code Implementation
```python
class Solution:
    def intToRoman(self, num: int) -> str:
        thousands = ["", "M", "MM", "MMM"]
        hundreds  = ["", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"]
        tens      = ["", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"]
        ones      = ["", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"]

        th = num // 1000
        h = (num % 1000) // 100
        t = (num % 100) // 10
        o = num % 10

        result = thousands[th] + hundreds[h] + tens[t] + ones[o]
        return result

```
#### Time and Space Complexity
- **Time Complexity:** O(1) — All operations are constant time due to fixed-size arrays and the constraints on `num`.
- **Space Complexity:** O(1) — The arrays are of fixed size.
___
### Analysis of the User's Code
The code you provided attempts to convert an integer to a Roman numeral by processing each digit starting from the ones place. Here's a brief analysis:
#### Explanation of Your Code
- **Dictionary **`**romans**`**:** Stores the Roman numeral representations for specific numbers, including special cases like `4` (`IV`), `9` (`IX`), etc.
- **Variables:**
	- `output`: A list to accumulate the Roman numerals.
	- `place`: Keeps track of the current place value (ones, tens, hundreds, etc.).
- **While Loop:**
	- Processes the number digit by digit.
	- **Calculates:**
		- `digit`: The current digit at the place value.
		- `number`: The value of the digit at its place value.
- **Conditional Statements:**
	- Handles special cases where the digit is `4` or `9`.
	- Checks if `number` is directly in the `romans` dictionary.
	- For numbers between `500` and `1000`, it subtracts `500` and processes the remaining amount.
	- For other cases, it replicates the Roman numeral for the current place value `digit` times.
- **Update Statements:**
	- Moves to the next higher place value.
	- Divides `num` by `10` to process the next digit.
- **Final Output:**
	- Joins the `output` list in reverse order to form the final Roman numeral string.
#### Issues and Suggestions
- **Edge Cases for Large Numbers:**
	- Your code may not handle numbers greater than or equal to `1000` correctly. For example, it might not correctly convert numbers like `2000` or `3000`.
- **Complexity and Readability:**
	- The logic is complex due to handling many specific cases.
	- It can be simplified by using the greedy approach or the alternative method provided above.
#### Recommendation
Consider adopting the standard greedy approach outlined earlier, which simplifies the conversion process and ensures correctness across all valid input values.
___
### Conclusion
To solve the Integer to Roman numeral conversion, the greedy approach using a list of value-symbol pairs is efficient and straightforward. The alternative method using arrays for thousands, hundreds, tens, and ones digits is also effective.
Both methods have constant time and space complexities due to the constraints on the input number.
___
### Final Code Solution
```python
class Solution:
    def intToRoman(self, num: int) -> str:
        val_syms = [
            (1000, 'M'),
            (900, 'CM'),
            (500, 'D'),
            (400, 'CD'),
            (100, 'C'),
            (90, 'XC'),
            (50, 'L'),
            (40, 'XL'),
            (10, 'X'),
            (9, 'IX'),
            (5, 'V'),
            (4, 'IV'),
            (1, 'I'),
        ]

        result = ''
        for value, symbol in val_syms:
            while num >= value:
                num -= value
                result += symbol
        return result
```
___
### Test Cases
```python
assert Solution().intToRoman(3) == "III"
assert Solution().intToRoman(4) == "IV"
assert Solution().intToRoman(9) == "IX"
assert Solution().intToRoman(58) == "LVIII"
assert Solution().intToRoman(1994) == "MCMXCIV"
assert Solution().intToRoman(1) == "I"
assert Solution().intToRoman(3999) == "MMMCMXCIX"
assert Solution().intToRoman(44) == "XLIV"
assert Solution().intToRoman(294) == "CCXCIV"

```
These test cases cover a range of inputs, including the minimum and maximum values, and ensure that the algorithm handles subtractive notation correctly.
___
**Key Takeaways:**
- Using a greedy approach with a list of value-symbol pairs simplifies the conversion process.
- Ensure that all special cases, including subtractive notations, are included in the value-symbol list.
- The alternative method using arrays for each digit place is also efficient and may be preferred for its clarity.
- Always test the code with various inputs to ensure correctness, especially edge cases.
### Notes
___
 
### Related Videos 
___
[ohBNdSJyLh8](https://youtu.be/ohBNdSJyLh8?si=wtsQd-nyFcWaVmSX)