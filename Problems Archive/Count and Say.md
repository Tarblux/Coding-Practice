# Count and Say

Problem: 38
Official Difficulty: medium
Feels Like : medium
Topic: design, string
Link: https://leetcode.com/problems/count-and-say/description/
Completed On : January 11, 2024
My Understanding: Needs Review
Last Review: January 11, 2024
Days Since Review: 30

## Problem

---

The **count-and-say** sequence is a sequence of digit strings defined by the recursive formula:

- `countAndSay(1) = "1"`
- `countAndSay(n)` is the way you would "say" the digit string from `countAndSay(n-1)`, which is then converted into a different digit string.

To determine how you "say" a digit string, split it into the **minimal** number of sub strings such that each sub string contains exactly **one** unique digit. Then for each sub-string, say the number of digits, then say the digit. Finally, concatenate every said digit.

For example, the saying and conversion for digit string `"3322251"`:

![https://assets.leetcode.com/uploads/2020/10/23/countandsay.jpg](https://assets.leetcode.com/uploads/2020/10/23/countandsay.jpg)

Given a positive integer `n`, return *the* `nth` *term of the **count-and-say** sequence*.

**Example 1:**

```
Input: n = 1
Output: "1"
Explanation: This is the base case.

```

**Example 2:**

```
Input: n = 4
Output: "1211"
Explanation:
countAndSay(1) = "1"
countAndSay(2) = say "1" = one 1 = "11"
countAndSay(3) = say "11" = two 1's = "21"
countAndSay(4) = say "21" = one 2 + one 1 = "12" + "11" = "1211"

```

**Constraints:**

- `1 <= n <= 30`

## My Solutions

---

```python
class Solution:
    def countAndSay(self, n: int) -> str:
        
        def coder(s) : 
            
            if not s:
                
                return []
            
            p1 = 0
            
            output = []
            
            s = str(s)
            
            i = 0
            
            while i < len(s) :
                
                num = s[i]
                
                freq = 1
                
                p1 = i + 1
                
                while p1< len(s) and s[p1] == num :
                    
                    freq += 1
                    
                    p1 += 1
                    
                output.append([int(num),freq])
                
                # while i < len(s) and s[i] == num :
                    
                #     i += 1

                # Can just do this instead 

                i += freq
                
            return output
        
        # print(coder(223314444411))
        
        def decoder(arr) : 
            
            if not arr : 
                
                return ''
            
            string = ''
            
            for array in arr : 
                
                string += str(array[1])
                
                string += str(array[0])
                
            return string
        
        # print(decoder([[2,2], [3,2], [1,1], [4,5], [1, 2]]))
        
        answer = 1
        
        for i in range(0,n-1) :
            
            answer = coder(answer)
            
            answer = decoder(answer)
        
            
        return str(answer)
```

### Sanya

```python
class Solution:
    def countAndSay(self, n: int) -> str:

        if n == 1:
            return "1"
    
        prev = self.countAndSay(n - 1)
        result = ""
    
        count = 1
        for i in range(len(prev)):
            if i + 1 < len(prev) and prev[i] == prev[i + 1]:
                count += 1
            else:
                result += str(count) + prev[i]
                count = 1
            
        return result
```

## Optimal Solutions

---

The "Count and Say" problem is an interesting sequence-based problem. The sequence starts with "1" and each term is derived by describing the previous term.

### Problem Statement

Given an integer `n`, generate the `n`th term of the "count-and-say" sequence.

The "count-and-say" sequence is defined as follows:

1. The first term is "1".
2. The second term is "11", derived from the first term by describing one "1" ("1" is read as "one 1").
3. The third term is "21", derived from the second term by describing two "1"s.
4. The fourth term is "1211", derived from the third term by describing one "2", followed by one "1".

... and so on.

### Solution Approach

The approach to solving this problem is iterative. For each term after the first, look at the previous term, count the number of occurrences of each digit, and say what you see.

### Python Implementation

```python
class Solution:
    def countAndSay(self, n: int) -> str:
        if n == 1:
            return "1"

        prev = "1"
        for k in range(n - 1):
            current = ""
            i = 0
            while i < len(prev):
                count = 1
                while i + 1 < len(prev) and prev[i] == prev[i + 1]:
                    i += 1
                    count += 1
                current += str(count) + prev[i]
                i += 1
            prev = current

        return prev

```

### Explanation

- Start with the first term "1".
- For each term from the second to the `n`th:
    - Initialize an empty string `current` for the new term.
    - Iterate over the previous term (`prev`).
    - Count the consecutive identical digits and append their count and value to `current`.
    - Update `prev` to `current` for the next iteration.
- Return `prev`, which now contains the `n`th term.

### Complexity Analysis

- **Time Complexity**: O(m * n), where `m` is the average length of the term and `n` is the input number. Each term's generation depends on the length of the previous term.
- **Space Complexity**: O(m), where `m` is the length of the largest term. The space used is for storing the current and previous terms.

This algorithm iteratively builds each term of the sequence based on the description of the previous term, adhering to the "count and say" pattern.

## Notes

---

 

## Related Videos

---

[https://www.notion.so](https://www.notion.so)