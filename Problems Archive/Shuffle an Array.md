# Shuffle an Array

Problem: 384
Official Difficulty: medium
Feels Like : easy
Topic: array, randomization
Link: https://leetcode.com/problems/shuffle-an-array/
Completed On : December 5, 2023
My Understanding: Mostly Understand
Last Review: December 5, 2023
Days Since Review: 67

---

## My Solutions

---

```python
class Solution:

    def __init__(self, nums: List[int]):
        
        self.og_nums  = nums.copy() 
        
        self.new_nums = nums.copy()
        
    
    def reset(self) -> List[int]:
        
        return self.og_nums
        

    def shuffle(self) -> List[int]:
        
        random.shuffle(self.new_nums)
        
        return self.new_nums
        
list = [1,2,34]   

A = Solution1.Solution(list)

B = Solution(list) 

A.shuffle()

print(A.new_nums)

# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.reset()
# param_2 = obj.shuffle()
```

## Optimal Solutions

---

The "Shuffle an Array" problem involves randomly shuffling the elements of an array. This can be efficiently solved using the Fisher-Yates (or Knuth) Shuffle algorithm. The idea is to iterate over the array and for each index, swap the element at that index with an element at a random index that is either equal to or comes after the current index.

### Algorithm: Fisher-Yates Shuffle

1. Iterate over the array from the first element to the second-to-last element.
2. For each index `i`, generate a random index `j` such that `i <= j < n`, where `n` is the length of the array.
3. Swap the elements at indices `i` and `j`.
4. Repeat this process until you reach the end of the array.

### Python Implementation

Here's how you might implement this in Python:

```python
import random

class Solution:

    def __init__(self, nums):
        self.array = nums
        self.original = list(nums)

    def reset(self):
        self.array = self.original
        self.original = list(self.original)
        return self.array

    def shuffle(self):
        for i in range(len(self.array)):
            swap_idx = random.randrange(i, len(self.array))
            self.array[i], self.array[swap_idx] = self.array[swap_idx], self.array[i]
        return self.array

```

### Explanation

- The constructor `__init__` stores the original array.
- The `reset` method returns the array to its original configuration.
- The `shuffle` method implements the Fisher-Yates algorithm. For each index `i`, it selects a random index `j` (`i <= j < n`) and swaps the elements at these indices.

### Complexity Analysis

- **Time Complexity**: O(n) for the shuffle method, where n is the length of the array. Each element is considered once.
- **Space Complexity**: O(n) due to the storage of the original array for the reset functionality. Without the need for a reset, the space complexity would be O(1).

The Fisher-Yates Shuffle is an unbiased algorithm, ensuring that every permutation of the array is equally likely.

## Notes

---

 Easy way out is to use the random library but the medium level answer is to implement the randomization yourself.

In this implementation of the shuffle problem, the use of the `.copy()` method is essential for maintaining the original state of the array while allowing for its shuffled versions to be generated. Here's why the `.copy()` method is important:

1. **Separation of Original and Current Arrays**:
    - `self.og_nums = nums.copy()`: This creates a separate copy of the input array `nums` and stores it in `self.og_nums`. The `.copy()` method ensures that `self.og_nums` is a new list object, not just a reference to the original `nums` list. This way, any modifications to `self.cur_nums` won't affect `self.og_nums`.
    - `self.cur_nums = nums.copy()`: Similarly, this creates another independent copy of `nums` for current operations like shuffling.
2. **Maintaining Original Array in `reset` Method**:
    - `self.cur_nums = self.og_nums.copy()`: When the `reset` method is called, it's important to return the array to its original state. Here, `self.og_nums.copy()` creates a fresh copy of the original array. This is crucial because if we used `self.cur_nums = self.og_nums` without `.copy()`, then `self.cur_nums` and `self.og_nums` would point to the same list object. Any subsequent shuffling on `self.cur_nums` would then also affect `self.og_nums`, which defeats the purpose of having a resettable array.
3. **Ensuring Immutability of the Original Array**:
    - The use of `.copy()` in both the initialization and the `reset` method ensures that the original array (`self.og_nums`) remains unchanged and intact regardless of how many times the `shuffle` method is called. This immutability is essential to repeatedly return to the original configuration of the array when `reset` is called.

In summary, the use of `.copy()` is crucial for maintaining the integrity of the original array and ensuring that the operations of shuffling and resetting are independent of each other. This approach is a common and necessary practice in problems where the original state needs to be preserved while allowing modifications in derived states.

## Related Videos

---

[https://www.youtube.com/watch?v=4zx5bM2OcvA](https://www.youtube.com/watch?v=4zx5bM2OcvA)