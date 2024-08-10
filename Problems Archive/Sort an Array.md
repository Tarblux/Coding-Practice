# Sort an Array

Problem: 912
Official Difficulty: medium
Feels Like : hard
My Understanding: Mostly Understand
Topic: Divide and Conquer, Heap(Priority Queue), array, bucket sort, counting sort, merge sort, radix sort, sorting
Link: https://leetcode.com/problems/sort-an-array/description/
Completed On : August 9, 2024
Last Review: August 9, 2024
Days Since Review: 0

## Problem

---

Given an array of integers `nums`, sort the array in ascending order and return it.

You must solve the problem **without using any built-in** functions in `O(nlog(n))` time complexity and with the smallest space complexity possible.

**Example 1:**

```
Input: nums = [5,2,3,1]
Output: [1,2,3,5]
Explanation: After sorting the array, the positions of some numbers are not changed (for example, 2 and 3), while the positions of other numbers are changed (for example, 1 and 5).
```

**Example 2:**

```
Input: nums = [5,1,1,2,0,0]
Output: [0,0,1,1,2,5]
Explanation: Note that the values of nums are not necessairly unique.

```

**Constraints:**

- `1 <= nums.length <= 5 * 104`
- `5 * 104 <= nums[i] <= 5 * 104`

## My Solutions

---

Sometimes time complexity degrades to O(n^2) but it works otherwise when the pivot isn’t the largest

```python

class Solution:
    
    def partition(self,array:List[int],start:int,end:int) -> int:
        
        pivot = array[end]
        split = start - 1
        
        for i in range(start,end):
            
            if array[i] <= pivot:
                split += 1
                array[split] , array[i] = array[i] , array[split]
                
        array[split+1] , array[end]  = array[end] , array[split+1]
        
        return split + 1
    
    def quickSort(self,array:List[int],start:int,end:int) -> None:
        
        if start >= end:
            return

        pivot = self.partition(array,start,end)
        
        self.quickSort(array,pivot+1,end)
        self.quickSort(array,start,pivot-1) 
        
    
    def sortArray(self,nums:List[int]) -> List[int]:
        
        self.quickSort(nums,0,len(nums)-1)
        return nums
        
```

bubble Sort : Super Naive Approach → always O(n^2) so never works really

```python
class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:

        for i in range(0, len(nums)):
            for j in range(0, len(nums) - i - 1):
                if nums[j] > nums[j + 1]:
                    
                    nums[j + 1], nums[j] = nums[j], nums[j + 1]
            
        return nums       
        
```

## Optimal Solutions

---

### Problem Description

Given an array of integers, sort the array in ascending order. Implement the sorting using the following algorithms: Merge Sort, Quick Sort, Radix Sort, and Heap Sort.

### Python Implementations

Here are the implementations of each sorting algorithm:

---

### Merge Sort

Merge Sort is a divide-and-conquer algorithm that divides the array into two halves, recursively sorts each half, and then merges the two sorted halves.

```python
def mergeSort(nums):
    if len(nums) <= 1:
        return nums

    mid = len(nums) // 2
    left_half = mergeSort(nums[:mid])
    right_half = mergeSort(nums[mid:])

    return merge(left_half, right_half)

def merge(left, right):
    sorted_array = []
    i = j = 0

    while i < len(left) and j < len(right):
        if left[i] < right[j]:
            sorted_array.append(left[i])
            i += 1
        else:
            sorted_array.append(right[j])
            j += 1

    sorted_array.extend(left[i:])
    sorted_array.extend(right[j:])

    return sorted_array

# Example usage
nums = [5, 2, 3, 1]
print(mergeSort(nums))  # Output: [1, 2, 3, 5]

```

### Quick Sort

Quick Sort is another divide-and-conquer algorithm. It selects a pivot element and partitions the array such that elements less than the pivot are on the left, and elements greater than the pivot are on the right, then recursively applies the same logic to the subarrays.

```python
def quickSort(nums):
    if len(nums) <= 1:
        return nums

    pivot = nums[len(nums) // 2]
    left = [x for x in nums if x < pivot]
    middle = [x for x in nums if x == pivot]
    right = [x for x in nums if x > pivot]

    return quickSort(left) + middle + quickSort(right)

# Example usage
nums = [5, 2, 3, 1]
print(quickSort(nums))  # Output: [1, 2, 3, 5]

```

### Radix Sort

Radix Sort is a non-comparative sorting algorithm that sorts numbers by processing individual digits. It works by sorting numbers on each digit, starting from the least significant digit to the most significant digit.

```python
def radixSort(nums):
    max_num = max(nums)
    exp = 1

    while max_num // exp > 0:
        countingSort(nums, exp)
        exp *= 10

    return nums

def countingSort(nums, exp):
    n = len(nums)
    output = [0] * n
    count = [0] * 10

    for i in range(n):
        index = (nums[i] // exp) % 10
        count[index] += 1

    for i in range(1, 10):
        count[i] += count[i - 1]

    for i in range(n - 1, -1, -1):
        index = (nums[i] // exp) % 10
        output[count[index] - 1] = nums[i]
        count[index] -= 1

    for i in range(n):
        nums[i] = output[i]

# Example usage
nums = [170, 45, 75, 90, 802, 24, 2, 66]
print(radixSort(nums))  # Output: [2, 24, 45, 66, 75, 90, 170, 802]

```

### Heap Sort

Heap Sort is a comparison-based sorting algorithm that uses a binary heap data structure. It works by building a max heap from the input data and then repeatedly extracting the maximum element from the heap and placing it at the end of the array.

```python
def heapSort(nums):
    n = len(nums)

    # Build max heap
    for i in range(n // 2 - 1, -1, -1):
        heapify(nums, n, i)

    # Extract elements from heap one by one
    for i in range(n - 1, 0, -1):
        nums[i], nums[0] = nums[0], nums[i]  # Swap
        heapify(nums, i, 0)

    return nums

def heapify(nums, n, i):
    largest = i
    left = 2 * i + 1
    right = 2 * i + 2

    if left < n and nums[left] > nums[largest]:
        largest = left

    if right < n and nums[right] > nums[largest]:
        largest = right

    if largest != i:
        nums[i], nums[largest] = nums[largest], nums[i]
        heapify(nums, n, largest)

# Example usage
nums = [5, 2, 3, 1]
print(heapSort(nums))  # Output: [1, 2, 3, 5]

```

### Summary of the Algorithms

1. **Merge Sort**:
    - **Time Complexity**: `O(n log n)`
    - **Space Complexity**: `O(n)` (due to the extra space required for merging)
2. **Quick Sort**:
    - **Time Complexity**: `O(n log n)` on average, `O(n^2)` in the worst case
    - **Space Complexity**: `O(log n)` (due to recursion)
3. **Radix Sort**:
    - **Time Complexity**: `O(nk)` where `k` is the number of digits in the largest number
    - **Space Complexity**: `O(n + k)`
4. **Heap Sort**:
    - **Time Complexity**: `O(n log n)`
    - **Space Complexity**: `O(1)`

These algorithms each have their strengths and are suitable for different kinds of data and constraints.

## Notes

---

 

## Related Videos

---

[https://www.youtube.com/watch?v=MsYZSinhuFo&pp=ygUNc29ydCBhbiBhcnJheQ%3D%3D](https://www.youtube.com/watch?v=MsYZSinhuFo&pp=ygUNc29ydCBhbiBhcnJheQ%3D%3D)