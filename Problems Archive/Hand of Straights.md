<<<<<<< Updated upstream
Problem: 846
Official Difficulty: medium
Link: https://leetcode.com/problems/hand-of-straights/description/
Completed On : 2024-12-15
Feels Like : medium
Topic: array, hash table, greedy, sorting
My Understanding: Fully Understand
Last Review: 2024-12-15
Days Since Review: 7
Name: Hand of Straights

# Hand of Straights
### Problem
___
Alice has some number of cards and she wants to rearrange the cards into groups so that each group is of size `groupSize`, and consists of `groupSize` consecutive cards.
Given an integer array `hand` where `hand[i]` is the value written on the `ith` card and an integer `groupSize`, return `true` if she can rearrange the cards, or `false` otherwise.
**Example 1:**
```plain text
=======
# Hand of Straights

Problem: 846
Official Difficulty: medium
Feels Like : medium
My Understanding: Fully Understand
Topic: array, greedy, hash table, sorting
Link: https://leetcode.com/problems/hand-of-straights/description/
Completed On : December 15, 2024
Last Review: December 15, 2024
Days Since Review: 77
Neetcode: Yes

## Problem

---

Alice has some number of cards and she wants to rearrange the cards into groups so that each group is of size `groupSize`, and consists of `groupSize` consecutive cards.

Given an integer array `hand` where `hand[i]` is the value written on the `ith` card and an integer `groupSize`, return `true` if she can rearrange the cards, or `false` otherwise.

**Example 1:**

```
>>>>>>> Stashed changes
Input: hand = [1,2,3,6,2,3,4,7,8], groupSize = 3
Output: true
Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8]
```
<<<<<<< Updated upstream
**Example 2:**
```plain text
=======

**Example 2:**

```
>>>>>>> Stashed changes
Input: hand = [1,2,3,4,5], groupSize = 4
Output: false
Explanation: Alice's hand can not be rearranged into groups of 4.
```
<<<<<<< Updated upstream
**Constraints:**
- `1 <= hand.length <= 104`
- `0 <= hand[i] <= 109`
- `1 <= groupSize <= hand.length`
**Note:** This question is the same as 1296: [https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/](https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/)
### My Solutions
___
=======

**Constraints:**

- `1 <= hand.length <= 104`
- `0 <= hand[i] <= 109`
- `1 <= groupSize <= hand.length`

**Note:** This question is the same as 1296: [https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/](https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/)

## My Solutions

---

>>>>>>> Stashed changes
```python
class Solution:
    def isNStraightHand(self, hand: List[int], groupSize: int) -> bool:

        if len(hand) % groupSize != 0:
            return False

        heapq.heapify(hand)
        available = Counter(hand)

        while hand:
            
            start = heapq.heappop(hand)

            if available[start] == 0:
                continue

            for i in range(groupSize):
                
                need = start + i
                
                if available[need] <= 0:
                    return False

                available[need] -= 1
                if available[need] == 0:
                    available.pop(need)

        return True
```

<<<<<<< Updated upstream
Time Complexity :
=======
>>>>>>> Stashed changes
```python

```

<<<<<<< Updated upstream
Time Complexity : 
### Optimal Solutions
___
Use a greedy approach combined with a frequency map of card values:
1. Count the frequency of each card.
2. Sort the distinct card values.
3. For each smallest card value currently available, try to form a consecutive sequence of length `W`.
	- For each of the next `W` card values (starting from this smallest card), decrement their frequency.
	- If any required card is not present or its frequency is insufficient, return `False`.
4. If all sequences are successfully formed, return `True`.
This works because starting from the smallest available card and greedily forming a consecutive sequence ensures we handle the lowest cards first without leaving gaps.
**Code:**
=======
## Optimal Solutions

---

Use a greedy approach combined with a frequency map of card values:

1. Count the frequency of each card.
2. Sort the distinct card values.
3. For each smallest card value currently available, try to form a consecutive sequence of length `W`.
    - For each of the next `W` card values (starting from this smallest card), decrement their frequency.
    - If any required card is not present or its frequency is insufficient, return `False`.
4. If all sequences are successfully formed, return `True`.

This works because starting from the smallest available card and greedily forming a consecutive sequence ensures we handle the lowest cards first without leaving gaps.

**Code:**

>>>>>>> Stashed changes
```python
class Solution:
    def isNStraightHand(self, hand: List[int], W: int) -> bool:
        if len(hand) % W != 0:
            return False

        freq = {}
        for card in hand:
            freq[card] = freq.get(card, 0) + 1

        # Sort distinct card values
        unique_cards = sorted(freq.keys())

        for card in unique_cards:
            while freq[card] > 0:
                # Need to form a group starting from 'card'
                for val in range(card, card + W):
                    if freq.get(val, 0) == 0:
                        return False
                    freq[val] -= 1

        return True

```
<<<<<<< Updated upstream
### Notes
___
 
### Related Videos 
___
[amnrMCVd2YI](https://youtu.be/amnrMCVd2YI)
=======

## Notes

---

 

## Related Videos

---

[https://youtu.be/amnrMCVd2YI](https://youtu.be/amnrMCVd2YI)
>>>>>>> Stashed changes
