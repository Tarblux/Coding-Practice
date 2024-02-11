# Plus One

Problem: 66
Official Difficulty: easy
Topic: Math, array
Link: https://leetcode.com/problems/plus-one/editorial/
Completed On : November 12, 2023
My Understanding: Mostly Understand
Last Review: November 12, 2023
Days Since Review: 90

## Problem

---

You are given a **large integer** represented as an integer array `digits`, where each `digits[i]` is the `ith`
 digit of the integer. The digits are ordered from most significant to 
least significant in left-to-right order. The large integer does not 
contain any leading `0`'s.

Increment the large integer by one and return *the resulting array of digits*.

**Example 1:**

```
Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].
```

**Example 2:**

```
Input: digits = [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
Incrementing by one gives 4321 + 1 = 4322.
Thus, the result should be [4,3,2,2].
```

**Example 3:**

```
Input: digits = [9]
Output: [1,0]
Explanation: The array represents the integer 9.
Incrementing by one gives 9 + 1 = 10.
Thus, the result should be [1,0].
```

## My Solutions

### Tariq

---

```python
class Solution(object):
    def plusOne(self, digits):
           
        
        for i in range (len(digits)-1 , -1 , -1 ) : 
            
            if digits [i] == 9 and i != 0 : 
                
                digits [i] = 0
                
                
            elif digits [i] == 9 and i == 0 : 
                
                digits [i] = 0
                
                digits.insert(0,1)
                
            else :
            
                digits [i] += 1
                
                break
                
        
        return digits
```

### Aleksandr

```java
class Solution {
    public int[] plusOne(int[] digits) {
        
        int[] result = new int[digits.length + 1];
        int stoppedAt = -1;
        
        for (int i = digits.length - 1; i >= 0; i--){
            int cur = digits[i];
            if (cur + 1 < 10) {
                result[i + 1] = cur + 1; 
                stoppedAt = i;
                break;
            } else {
                result[i] = 0;
                if (i == 0) {
                    result[0] = 1; 
                    return result;
                }
            }
        }
        
        for (int i = stoppedAt; i >= 0; i--){
            result[i+1] = digits[i];
        }
            
        return Arrays.copyOfRange(result, 1, result.length);
    }
}
```

## Optimal Solutions

---

To solve the problem as described, you will need to consider how incrementing a number works when you're dealing with individual digits. The main complication arises when there's a carry-over, i.e., when the digit is `9`. Here's a step-by-step approach to increment the integer represented by the array `digits`:

1. Start from the least significant digit (the last element of the array).
2. If the least significant digit is less than 9, increment it and return the array.
3. If the least significant digit is 9, set it to 0 and move to the next more significant digit.
4. If you reach the most significant digit and it's a 9, set it to 0 and add a new digit at the beginning of the array.
5. Return the updated array.

Here's how you could implement this logic:

```python
def plusOne(digits):
    # Start from the end of the digits array
    for i in range(len(digits) - 1, -1, -1):
        # If the current digit is less than 9, just increment it and return the array
        if digits[i] < 9:
            digits[i] += 1
            return digits
        # If the digit is 9, it becomes 0
        digits[i] = 0

    # If all the digits were 9, then after the loop, we have an array of all 0s
    # We need to add a new most significant digit which is 1 at the beginning
    # This is because 99...99 + 1 = 100...000 (with one more digit)
    return [1] + digits

# Example usage:
print(plusOne([1, 2, 3]))  # Output: [1, 2, 4]
print(plusOne([4, 3, 2, 1]))  # Output: [4, 3, 2, 2]
print(plusOne([9]))  # Output: [1, 0]

```

This function will handle all the cases correctly, including when a carry is propagated through the entire list.

### LeetCode Premium Solution

```python
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        n = len(digits)

        # move along the input array starting from the end
        for i in range(n):
            idx = n - 1 - i
            # set all the nines at the end of array to zeros
            if digits[idx] == 9:
                digits[idx] = 0
            # here we have the rightmost not-nine
            else:
                # increase this rightmost not-nine by 1
                digits[idx] += 1
                # and the job is done
                return digits

        # we're here because all the digits are nines
        return [1] + digits
```

## Notes

---

## Related Videos

---

[https://www.youtube.com/watch?v=jIaA8boiG1s](https://www.youtube.com/watch?v=jIaA8boiG1s)