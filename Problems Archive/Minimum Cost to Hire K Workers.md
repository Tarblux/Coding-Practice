# Minimum Cost to Hire K Workers

Problem: 857
Official Difficulty: hard
Feels Like : hard
My Understanding: Needs Review
Topic: Heap(Priority Queue), array, greedy, sorting
Link: https://leetcode.com/problems/minimum-cost-to-hire-k-workers/description/
Completed On : May 13, 2024
Last Review: May 13, 2024
Days Since Review: 6

## Problem

---

There are `n` workers. You are given two integer arrays `quality` and `wage` where `quality[i]` is the quality of the `ith` worker and `wage[i]` is the minimum wage expectation for the `ith` worker.

We want to hire exactly `k` workers to form a **paid group**. To hire a group of `k` workers, we must pay them according to the following rules:

1. Every worker in the paid group must be paid at least their minimum wage expectation.
2. In the group, each worker's pay must be directly proportional to
their quality. This means if a worker’s quality is double that of
another worker in the group, then they must be paid twice as much as the other worker.

Given the integer `k`, return *the least amount of money needed to form a paid group satisfying the above conditions*. Answers within `10-5` of the actual answer will be accepted.

**Example 1:**

```
Input: quality = [10,20,5], wage = [70,50,30], k = 2
Output: 105.00000
Explanation: We pay 70 to 0th worker and 35 to 2nd worker.
```

**Example 2:**

```
Input: quality = [3,1,10,10,1], wage = [4,8,2,2,7], k = 3
Output: 30.66667
Explanation: We pay 4 to 0th worker, 13.33333 to 2nd and 3rd workers separately.
```

**Constraints:**

- `n == quality.length == wage.length`
- `1 <= k <= n <= 104`
- `1 <= quality[i], wage[i] <= 104`

## My Solutions

---

```python
class Solution:
    def mincostToHireWorkers(self, quality: List[int], wage: List[int], k: int) ->float:

        result = float("inf")

        pairs = [(wage[i] / quality[i], quality[i]) for i in range(0, len(wage))]

        pairs.sort(key=lambda pair: pair[0])

        maxHeap = []
        total_quality = 0
        for rate, q in pairs:
            heapq.heappush(maxHeap, -q)
            total_quality += q
            if len(maxHeap) > k:
                max_quality = heapq.heappop(maxHeap)
                total_quality += max_quality
            if len(maxHeap) == k:
                result = min(result, total_quality * rate)

        return result
```

```python

```

## Optimal Solutions

---

The LeetCode problem "Minimum Cost to Hire K Workers" involves hiring exactly K workers from a pool of candidates, where each worker has a quality and an expected wage. The goal is to minimize the total cost of hiring exactly K workers while ensuring each worker gets at least their expected wage.

Here's a thorough explanation and solution:

## Problem Statement

Given two arrays `quality` and `wage`, where `quality[i]` represents the quality of the `i-th` worker and `wage[i]` represents the minimum wage expectation of the `i-th` worker, you need to find the minimum cost to hire exactly `K` workers.

## Optimal Solution Approach

To solve this problem, we can use a greedy algorithm combined with a min-heap (priority queue) to maintain the smallest possible cost while ensuring each worker gets at least their expected wage. The key insight is to hire workers based on their wage-to-quality ratio.

### Detailed Steps

1. **Calculate the Wage-to-Quality Ratio**:
    - For each worker, calculate the wage-to-quality ratio, which is `wage[i] / quality[i]`.
    - This ratio represents how much the worker charges per unit of quality.
2. **Sort Workers by Ratio**:
    - Sort the workers based on their wage-to-quality ratio in ascending order.
    - This ensures that we are considering the workers who give the best "deal" (lowest ratio) first.
3. **Use a Max-Heap to Maintain K Workers with Minimum Cost**:
    - Use a max-heap to keep track of the quality of the hired workers.
    - Iterate through the sorted list of workers. For each worker, add their quality to a running total and push it into the max-heap.
    - If the size of the heap exceeds K, remove the worker with the highest quality (since this maximizes the total cost).
4. **Calculate the Minimum Cost**:
    - After adding each worker, if the heap size is exactly K, calculate the total cost using the current worker's ratio and the sum of the qualities in the heap.
    - Update the minimum cost if the current total cost is lower.

### Code Implementation

```python
import heapq

def mincostToHireWorkers(quality, wage, K):
    workers = sorted((w / q, q, w) for q, w in zip(quality, wage))
    heap = []
    total_quality = 0
    min_cost = float('inf')

    for ratio, q, w in workers:
        heapq.heappush(heap, -q)
        total_quality += q

        if len(heap) > K:
            total_quality += heapq.heappop(heap)

        if len(heap) == K:
            min_cost = min(min_cost, ratio * total_quality)

    return min_cost

```

### Explanation

1. **Sorting**:
    - The workers are sorted by their wage-to-quality ratio. This ensures that we always consider the cheapest ratio first.
2. **Heap Management**:
    - We use a max-heap to keep track of the top K qualities. If adding a new worker causes the heap to exceed K, we remove the worker with the highest quality (and hence the highest cost).
3. **Cost Calculation**:
    - For each valid set of K workers, the total cost is calculated using the current ratio and the sum of qualities. We continuously update the minimum cost as we iterate through the workers.

### Explain Like I'm Five

Imagine you have a bunch of friends, and each friend wants to help you with a project. Each friend has a skill level (quality) and a minimum amount of candy they want to be paid (wage). You need to choose exactly K friends to help you, but you want to spend the least amount of candy possible.

First, you figure out how many candies each friend wants for each skill point they have (wage-to-quality ratio). You sort your friends by this ratio, so the friends who give you the most skill for the least candy are at the front of the line.

Then, you start picking friends from the front of the line and keep track of their total skill levels using a pile (heap). If you ever have more than K friends in your pile, you remove the one with the highest skill level (since they're the most expensive).

Every time you have exactly K friends, you calculate the total amount of candy you need to pay them based on the current friend's ratio and the total skill in your pile. You keep track of the smallest amount of candy you need as you go through the line of friends.

This way, you ensure that you get the most help (skill) for the least amount of candy while hiring exactly K friends.

## Notes

---

 

## Related Videos

---

[https://www.youtube.com/watch?v=f879mUH6vJk&pp=ygUfbWluaW11bSBjb3N0IHRvIGhpcmUgayB3b3JrZXJzIA%3D%3D](https://www.youtube.com/watch?v=f879mUH6vJk&pp=ygUfbWluaW11bSBjb3N0IHRvIGhpcmUgayB3b3JrZXJzIA%3D%3D)