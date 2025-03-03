# Reorganize String

Problem: 767
Official Difficulty: medium
Feels Like : medium
My Understanding: Mostly Understand
Topic: Counting, Heap(Priority Queue), greedy, hash table, sorting, string
Link: https://leetcode.com/problems/reorganize-string/description/
Completed On : January 31, 2025
Last Review: January 31, 2025
Days Since Review: 30
Neetcode: No

## Problem

---

Given a string `s`, rearrange the characters of `s` so that any two adjacent characters are not the same.

Return *any possible rearrangement of* `s` *or return* `""` *if not possible*.

**Example 1:**

```
Input: s = "aab"
Output: "aba"
```

**Example 2:**

```
Input: s = "aaab"
Output: ""
```

**Constraints:**

- `1 <= s.length <= 500`
- `s` consists of lowercase English letters.

## My Solutions

---

```python
class Solution:
    def reorganizeString(self, s: str) -> str:

        counts = Counter(s)
        max_count = max(counts.values(), default=0)
        n = len(s)
        
        if max_count > (n + 1) // 2:
            return ""
        
        heap = [(-count, char) for char, count in counts.items()]
        heapq.heapify(heap)
        
        output = []
        
        while heap:

            if len(heap) >= 2:

                count1, char1 = heapq.heappop(heap)
                count2, char2 = heapq.heappop(heap)
                
                output.append(char1)
                output.append(char2)
                
                if count1 + 1 < 0:
                    heapq.heappush(heap, (count1 + 1, char1))
                if count2 + 1 < 0:
                    heapq.heappush(heap, (count2 + 1, char2))
            else:

                count, char = heapq.heappop(heap)
                if output and output[-1] == char:
                    return ""
                output.append(char)
        
        return ''.join(output)   
```

```python

```

## Optimal Solutions

---

## Notes

---

 

## Related Videos

---

[https://www.notion.so](https://www.notion.so)