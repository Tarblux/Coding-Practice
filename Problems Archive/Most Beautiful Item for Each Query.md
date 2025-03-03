# Most Beautiful Item for Each Query

Problem: 2070
Official Difficulty: medium
Feels Like : hard
My Understanding: Mostly Understand
Topic: array, binary search, sorting
Link: https://leetcode.com/problems/most-beautiful-item-for-each-query/description/?envType=daily-question&envId=2024-11-12
Completed On : November 11, 2024
Last Review: November 11, 2024
Days Since Review: 111
Neetcode: No

## Problem

---

You are given a 2D integer array `items` where `items[i] = [pricei, beautyi]` denotes the **price** and **beauty** of an item respectively.

You are also given a **0-indexed** integer array `queries`. For each `queries[j]`, you want to determine the **maximum beauty** of an item whose **price** is **less than or equal** to `queries[j]`. If no such item exists, then the answer to this query is `0`.

Return *an array* `answer` *of the same length as* `queries` *where* `answer[j]` *is the answer to the* `jth` *query*.

**Example 1:**

```
Input: items = [[1,2],[3,2],[2,4],[5,6],[3,5]], queries = [1,2,3,4,5,6]
Output: [2,4,5,5,6,6]
Explanation:
- For queries[0]=1, [1,2] is the only item which has price <= 1. Hence, the answer for this query is 2.
- For queries[1]=2, the items which can be considered are [1,2] and [2,4].
  The maximum beauty among them is 4.
- For queries[2]=3 and queries[3]=4, the items which can be considered are [1,2], [3,2], [2,4], and [3,5].
  The maximum beauty among them is 5.
- For queries[4]=5 and queries[5]=6, all items can be considered.
  Hence, the answer for them is the maximum beauty of all items, i.e., 6.
```

**Example 2:**

```
Input: items = [[1,2],[1,2],[1,3],[1,4]], queries = [1]
Output: [4]
Explanation:
The price of every item is equal to 1, so we choose the item with the maximum beauty 4.
Note that multiple items can have the same price and/or beauty.
```

**Example 3:**

```
Input: items = [[10,1000]], queries = [5]
Output: [0]
Explanation:
No item has a price less than or equal to 5, so no item can be chosen.
Hence, the answer to the query is 0.
```

**Constraints:**

- `1 <= items.length, queries.length <= 105`
- `items[i].length == 2`
- `1 <= pricei, beautyi, queries[j] <= 109`

## My Solutions

---

```python
class Solution:

    def searchMax(self,items,target):

        left = 0
        right = len(items)

        while left < right:

            mid = left + (right-left)//2

            if items[mid][0] == target:
                left = mid + 1
            elif items[mid][0] < target:
                left = mid + 1
            elif items[mid][0] > target:
                right = mid

        return items[left - 1][1] if left > 0 else 0

    def maximumBeauty(self, items: List[List[int]], queries: List[int]) -> List[int]:

        items.sort()
        beauty = []

        max_beauty = 0
        for i in range(len(items)):
            max_beauty = max(max_beauty, items[i][1])
            items[i][1] = max_beauty

        for query in queries:
            beauty.append(self.searchMax(items,query))

        return beauty

        
        
```

```python

```

## Optimal Solutions

---

To solve **LeetCode Problem 2070: Most Beautiful Item for Each Query**, the most efficient approach involves preprocessing the items and queries to answer each query in optimal time.

---

### **Problem Overview**

- **Items:** An array where each item is represented as `[price_i, beauty_i]`.
- **Queries:** An array of integers where each query represents a maximum price.
- **Goal:** For each query, find the maximum beauty of an item whose price is less than or equal to the query price.

---

### **Optimal Algorithm: Sorting and Two-Pointer Technique**

### **Algorithm Intuition**

- **Sort Items:** By price in ascending order.
- **Precompute Maximum Beauties:** For each item, keep track of the maximum beauty up to that price.
- **Sort Queries:** Along with their original indices.
- **Process Queries:** Using a two-pointer approach to efficiently find the maximum beauty for each query.

### **Algorithm Steps**

1. **Sort Items by Price:**
    
    ```python
    items.sort()
    
    ```
    
2. **Precompute Maximum Beauties:**
    - Initialize `max_beauty = 0`.
    - Iterate over the sorted items:
        - Update `max_beauty = max(max_beauty, beauty_i)`.
        - Replace `beauty_i` with `max_beauty` in the items array.
    
    ```python
    max_beauty = 0
    for i in range(len(items)):
        max_beauty = max(max_beauty, items[i][1])
        items[i][1] = max_beauty
    
    ```
    
3. **Prepare Queries with Original Indices:**
    - Create a list of tuples `(query_price, original_index)`.
    - Sort the queries by `query_price`.
    
    ```python
    queries_with_indices = [(query, idx) for idx, query in enumerate(queries)]
    queries_with_indices.sort()
    
    ```
    
4. **Process Queries:**
    - Initialize an empty array `answers` of the same length as `queries`.
    - Initialize an index `i = 0` to traverse `items`.
    - For each query `(query_price, original_index)`:
        - While `i < len(items)` and `items[i][0] <= query_price`:
            - Increment `i`.
        - If `i == 0`, no items are affordable; set `answers[original_index] = 0`.
        - Else, set `answers[original_index] = items[i - 1][1]`.
    
    ```python
    answers = [0] * len(queries)
    i = 0
    n = len(items)
    for query_price, idx in queries_with_indices:
        while i < n and items[i][0] <= query_price:
            i += 1
        if i == 0:
            answers[idx] = 0
        else:
            answers[idx] = items[i - 1][1]
    
    ```
    

### **Complete Code Implementation**

```python
class Solution:
    def maximumBeauty(self, items: List[List[int]], queries: List[int]) -> List[int]:
        # Step 1: Sort items by price
        items.sort()

        # Step 2: Precompute maximum beauties
        max_beauty = 0
        for i in range(len(items)):
            max_beauty = max(max_beauty, items[i][1])
            items[i][1] = max_beauty  # Update beauty to be the max up to this price

        # Step 3: Prepare queries with original indices and sort
        queries_with_indices = sorted([(q, idx) for idx, q in enumerate(queries)])

        # Step 4: Process queries
        answers = [0] * len(queries)
        i = 0  # Pointer for items
        n = len(items)

        for query_price, idx in queries_with_indices:
            # Move the pointer i as long as the item price is less than or equal to the query price
            while i < n and items[i][0] <= query_price:
                i += 1
            # If no items are affordable, beauty is 0
            if i == 0:
                answers[idx] = 0
            else:
                # The maximum beauty up to the last affordable item
                answers[idx] = items[i - 1][1]

        return answers

```

---

### **Time and Space Complexity Analysis**

### **Time Complexity**

- **Sorting Items:** O(n log n), where `n` is the number of items.
- **Precomputing Max Beauties:** O(n), single pass through the items.
- **Sorting Queries:** O(q log q), where `q` is the number of queries.
- **Processing Queries:**
    - The pointer `i` traverses the items array at most once, O(n).
    - The loop over queries runs O(q) times.
- **Total Time Complexity:** O(n log n + q log q + n + q) ⇒ **O((n + q) log n)** (assuming n ≥ q).

### **Space Complexity**

- **Storage for Precomputed Beauties:** O(1), done in place.
- **Queries with Indices:** O(q), to store the sorted queries.
- **Answers Array:** O(q).
- **Total Space Complexity:** **O(n + q)** (for the sorted items and queries).

---

### **Explanation of the Algorithm**

- **Why Precompute Maximum Beauties?**
    - By updating each item's beauty to be the maximum beauty up to that price, we can quickly determine the maximum beauty for any given price.
- **How Does the Two-Pointer Technique Work?**
    - Since both items and queries are sorted by price, we can efficiently process them in a single pass.
    - The pointer `i` advances through the items only when the item price is less than or equal to the current query price.
- **Handling Queries That Cannot Afford Any Item:**
    - If `i == 0`, it means no items have a price less than or equal to the query price, so the answer is 0.

---

### **Example**

Let's walk through an example to solidify understanding.

**Items:** `[[1, 2], [3, 2], [2, 4], [5, 6]]`

**Queries:** `[2, 3, 5]`

**Step 1: Sort Items**

```
Items sorted by price:
[(1, 2), (2, 4), (3, 2), (5, 6)]

```

**Step 2: Precompute Maximum Beauties**

```
Index 0: max_beauty = max(0, 2) = 2 → Items[0] = (1, 2)
Index 1: max_beauty = max(2, 4) = 4 → Items[1] = (2, 4)
Index 2: max_beauty = max(4, 2) = 4 → Items[2] = (3, 4)
Index 3: max_beauty = max(4, 6) = 6 → Items[3] = (5, 6)

Updated Items:
[(1, 2), (2, 4), (3, 4), (5, 6)]

```

**Step 3: Prepare and Sort Queries**

```
Queries with indices:
[(2, 0), (3, 1), (5, 2)]

```

**Step 4: Process Queries**

- **Query 2 (Index 0):**
    - While `items[i][0] <= 2`:
        - `i = 0 → items[0][0] = 1 ≤ 2 → i = 1`
        - `i = 1 → items[1][0] = 2 ≤ 2 → i = 2`
    - `i = 2 → items[2][0] = 3 > 2`
    - `answers[0] = items[i - 1][1] = items[1][1] = 4`
- **Query 3 (Index 1):**
    - `i = 2 → items[2][0] = 3 ≤ 3 → i = 3`
    - `i = 3 → items[3][0] = 5 > 3`
    - `answers[1] = items[i - 1][1] = items[2][1] = 4`
- **Query 5 (Index 2):**
    - `i = 3 → items[3][0] = 5 ≤ 5 → i = 4`
    - `i = 4 → end of items`
    - `answers[2] = items[i - 1][1] = items[3][1] = 6`

**Final Answers:** `[4, 4, 6]`

---

### **Edge Cases to Consider**

- **No Affordable Items:** If a query price is less than the smallest item price.
- **Multiple Items with the Same Price:** Ensure that the maximum beauty is correctly updated.
- **Large Inputs:** The algorithm handles large inputs efficiently due to its optimal time complexity.

---

### **Conclusion**

By preprocessing the items to keep track of the maximum beauty up to each price and sorting both items and queries, we can efficiently answer each query in optimal time. This approach leverages the sorted nature of the data and the two-pointer technique to achieve **O((n + q) log n)** time complexity.

---

**Note:** The code provided is a complete solution that can be directly used to solve the problem on LeetCode or similar platforms.

## Notes

---

 

## Related Videos

---

[https://www.youtube.com/watch?v=r1WymhQxLZA](https://www.youtube.com/watch?v=r1WymhQxLZA)