# Compare Version Numbers

Problem: 165
Official Difficulty: medium
Feels Like : medium
My Understanding: Mostly Understand
Topic: string, two pointers
Link: https://leetcode.com/problems/compare-version-numbers/description/
Completed On : May 9, 2024
Last Review: May 9, 2024
Days Since Review: 3

## Problem

---

Given two **version strings**, `version1` and `version2`, compare them. A version string consists of **revisions** separated by dots `'.'`. The **value of the revision** is its **integer conversion** ignoring leading zeros.

To compare version strings, compare their revision values in **left-to-right order**. If one of the version strings has fewer revisions, treat the missing revision values as `0`.

*Return the following:*

- If `version1 < version2`, return `1`.
- If `version1 > version2`, return `1`.
- Otherwise, return `0`.

**Example 1:**

**Input:** version1 = "1.2", version2 = "1.10"

**Output:** -1

**Explanation:**

version1's second revision is "2" and version2's second revision is "10": 2 < 10, so version1 < version2.

**Example 2:**

**Input:** version1 = "1.01", version2 = "1.001"

**Output:** 0

**Explanation:**

Ignoring leading zeroes, both "01" and "001" represent the same integer "1".

**Example 3:**

**Input:** version1 = "1.0", version2 = "1.0.0.0"

**Output:** 0

**Explanation:**

version1 has less revisions, which means every missing revision are treated as "0".

**Constraints:**

- `1 <= version1.length, version2.length <= 500`
- `version1` and `version2` only contain digits and `'.'`.
- `version1` and `version2` **are valid version numbers**.
- All the given revisions in `version1` and `version2` can be stored in a **32-bit integer**.

## My Solutions

---

```python
class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:

        v1  = version1.split('.')
        v2  = version2.split('.')

        for v1, v2 in zip_longest(v1, v2 , fillvalue = 0):

            if int(v1) > int(v2):
                return 1
            elif int(v1) < int(v2):
                return -1

        return 0
```

`zip_longest` is a function provided by the `itertools` module in Python. It's similar to the built-in `zip` function, but it allows you to iterate over multiple iterables of potentially different lengths. This is particularly useful when you need to pair elements from iterables of unequal lengths and want to handle the extra elements gracefully.

Here's a brief overview of `zip_longest` and its key features:

1. **Handling Unequal Lengths**: While the `zip` function stops iteration as soon as the shortest input iterable is exhausted, `zip_longest` continues until the longest iterable is exhausted. This ensures that all elements from all iterables are processed.
2. **Fill Value**: `zip_longest` takes an optional `fillvalue` parameter, which specifies the value to use for missing elements from shorter iterables. When an iterable is exhausted and there are still elements in the other iterables, `fillvalue` is used as a placeholder for the missing elements. This allows you to control how missing values are handled.
3. **Usage Example**:
    
    ```python
    from itertools import zip_longest
    
    iter1 = [1, 2, 3]
    iter2 = ['a', 'b']
    
    for item1, item2 in zip_longest(iter1, iter2, fillvalue=0):
        print(item1, item2)
    
    ```
    
    Output:
    
    ```
    1 a
    2 b
    3 0
    
    ```
    
    In this example, when `iter2` is exhausted, `fillvalue=0` ensures that the missing elements are replaced with zeros, allowing iteration to continue until all elements in `iter1` are processed.
    

Overall, `zip_longest` is a versatile tool for iterating over multiple iterables simultaneously, especially when dealing with iterables of different lengths and the need to handle missing values elegantly.

```python

```

## Optimal Solutions

---

## Notes

---

 

## Related Videos

---

[https://www.youtube.com/watch?v=zNgwO4wD2gE](https://www.youtube.com/watch?v=zNgwO4wD2gE)