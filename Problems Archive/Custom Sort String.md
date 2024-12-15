Problem: 791
Official Difficulty: medium
Link: https://leetcode.com/problems/custom-sort-string/description/?envType=company&envId=facebook&favoriteSlug=facebook-thirty-days
Completed On : 2024-12-07
Feels Like : medium
Topic: hash table, string, sorting
My Understanding: Fully Understand
Last Review: 2024-12-07
Days Since Review: 8
Name: Custom Sort String

# Custom Sort String
### Problem
___
You are given two strings `order` and `s`. All the characters of `order` are **unique** and were sorted in some custom order previously.
Permute the characters of `s` so that they match the order that `order` was sorted. More specifically, if a character `x` occurs before a character `y` in `order`, then `x` should occur before `y` in the permuted string.
Return *any permutation of *`s`* that satisfies this property*.
**Example 1:**
**Input: **order = "cba", s = "abcd"
**Output: **"cbad"
**Explanation: **`"a"`, `"b"`, `"c"` appear in order, so the order of `"a"`, `"b"`, `"c"` should be `"c"`, `"b"`, and `"a"`.
Since `"d"` does not appear in `order`, it can be at any position in the returned string. `"dcba"`, `"cdba"`, `"cbda"` are also valid outputs.
**Example 2:**
**Input: **order = "bcafg", s = "abcd"
**Output: **"bcad"
**Explanation: **The characters `"b"`, `"c"`, and `"a"` from `order` dictate the order for the characters in `s`. The character `"d"` in `s` does not appear in `order`, so its position is flexible.
Following the order of appearance in `order`, `"b"`, `"c"`, and `"a"` from `s` should be arranged as `"b"`, `"c"`, `"a"`. `"d"` can be placed at any position since it's not in order. The output `"bcad"` correctly follows this rule. Other arrangements like `"dbca"` or `"bcda"` would also be valid, as long as `"b"`, `"c"`, `"a"` maintain their order.
**Constraints:**
- `1 <= order.length <= 26`
- `1 <= s.length <= 200`
- `order` and `s` consist of lowercase English letters.
- All the characters of `order` are **unique**.
### My Solutions
___
```python
class Solution:
    def customSortString(self, order: str, s: str) -> str:
        sort_order = {char: i for i, char in enumerate(order)}

        def sortKey(ch):

            if ch in sort_order:
                return sort_order[ch]
            else:
                return len(order) + ord(ch)

        output = sorted(s, key=sortKey)
        return ''.join(output)
```

Time Complexity :
```python

```

Time Complexity : 
### Optimal Solutions
___
Below is a detailed explanation and solution for **LeetCode Problem 791: Custom Sort String**.
___
### Understanding the Problem
You are given two strings:
1. **order**: A string that defines a custom ordering of all characters (lowercase English letters). Each character in `order` is unique and forms a complete or partial permutation of the lowercase alphabet.
2. **s**: A string whose characters need to be rearranged such that they follow the ordering rules defined by `order`.
The goal is to rearrange the characters of `s` so that:
- Characters that appear in `order` should appear in the resulting string `s'` in the exact order given by `order`.
- Characters in `s` that are **not** present in `order` can appear in any order, but only after all characters from `s` that appear in `order` have been placed.
**Key Points:**
- Every character in `order` defines a relative ordering: if `order = "cba"`, then `c` should appear before any `b`, and `b` should appear before any `a` in the rearranged string.
- Characters not in `order` have no specific positioning constraints relative to each other; they just need to appear after all the characters defined by `order` are placed.
- All characters in `s` must be included in the output string, just rearranged.
**Example:**
- Suppose `order = "cba"` and `s = "abcccba"`.
	- Characters of `s` are: `a, b, c, c, c, b, a`.
	- According to `order = "cba"`, we must list all `c`s first, then `b`s, then `a`s for those that appear in both `order` and `s`.
	- `s` contains:
		- `c`: 3 times
		- `b`: 2 times
		- `a`: 2 times
	- Rearranged according to "cba" ordering would be: `"cccbb aa"`.
		- First place `c`s (because 'c' is first in `order`), then `b`s, then `a`s.
		- If there were letters not in `order`, we would append them at the end.
___
### Outline of a Solution
3. **Count the Frequency of Characters in **`**s**`**:**
	- Create a frequency map (e.g., a dictionary) to count how many times each character appears in `s`.
4. **Build the Result in the Order Defined by **`**order**`**:**
	- Initialize an empty list (or use string builder techniques) to form the result.
	- Iterate over each character `ch` in `order`:
		- Check if `ch` is in the frequency map.
		- If yes, append `ch` to the result as many times as its frequency, then set its frequency to zero (or remove it from the map).
5. **Append Remaining Characters:**
	- After processing all characters in `order`, some characters in `s` may remain that are not in `order`.
	- Append these leftover characters in any order. Since there's no constraint on their order, we can simply iterate over the remaining keys in the frequency map and append them as many times as their count.
6. **Convert the Result List to a String and Return It:**
	- Join the list into a string and return it.
**Time Complexity:** O(n + m) where `n` is the length of `s` and `m` is the length of `order`.
- Counting frequencies takes O(n).
- Building the result using `order` takes O(m).
- Appending leftover characters takes up to O(n).
- Since `order` and `s` lengths are reasonably bounded (generally `|order| ≤ 26` for letters), this is efficient.
**Space Complexity:** O(n) due to the frequency map and the output construction.
___
### Step-by-Step Example
**Example:**
- `order = "cba"`
- `s = "abcccba"`
**Step 1: Frequency Map of **`**s**`**:**
- `a`: 2
- `b`: 2
- `c`: 3
**Step 2: Build According to **`**order**`**:**
- `order[0] = 'c'`: In `s`, `c` appears 3 times. Append `"ccc"` to the result. Now `result = "ccc"`.
- `order[1] = 'b'`: In `s`, `b` appears 2 times. Append `"bb"`. Now `result = "cccbb"`.
- `order[2] = 'a'`: In `s`, `a` appears 2 times. Append `"aa"`. Now `result = "cccbbaa"`.
No leftover characters remain since all were part of `order`.
**Final result:** `"cccbbaa"`
___
### Code Implementation
```python
class Solution:
    def customSortString(self, order: str, s: str) -> str:
        # Step 1: Count frequencies of chars in s
        freq = {}
        for ch in s:
            freq[ch] = freq.get(ch, 0) + 1

        # Step 2: Build result according to 'order'
        result = []
        for ch in order:
            if ch in freq:
                # Append this char freq[ch] times
                result.append(ch * freq[ch])
                # Set its frequency to zero
                del freq[ch]

        # Step 3: Append leftover characters
        for ch, count in freq.items():
            result.append(ch * count)

        # Step 4: Join and return
        return ''.join(result)

```
___
### Additional Notes
- If `order` does not contain some letters that appear in `s`, those letters simply go to the end.
- The problem does not impose any sorting constraints on leftover characters. You can append them in the order of their frequency map keys or the order they appear in `s`. The solution above uses the frequency dictionary iteration order, which is acceptable since any permutation of leftover characters is valid.
___
### Testing the Solution
**Test Case 1:**
- `order = "cba"`, `s = "abcccba"`
- Expected output: `"ccc b b a a"` or `"ccc b b a a"` (spaces added for clarity)
- Actual output: `"cccbbaa"`
**Test Case 2:**
- `order = "kqep"`, `s = "pekeq"`
- Characters in `s`: p(2), e(2), k(1), q(1)
- `order = "kqep"` means order priority: k → q → e → p
- From `s`, place `k` first (1 time), then `q` (1 time), then `e` (2 times), then `p` (2 times)
- Result: `"kqeepp"`
**Test Case 3:**
- `order = "xyz"`, `s = "abc"`
- None of `a, b, c` are in `xyz`.
- Just append `abc` as is (or any order) at the end since no chars in s appear in order.
- Output: `"abc"`
___
### Conclusion
The provided solution efficiently solves the **Custom Sort String** problem by leveraging a frequency map and a greedy iteration over `order`. The approach ensures all characters defined in `order` appear first in the desired order, and any remaining characters appear subsequently. This leads to a clean, optimal solution meeting all problem requirements.
### Notes
___
 
### Related Videos 
___
[lVfcS2Hn6M4](https://youtu.be/lVfcS2Hn6M4)