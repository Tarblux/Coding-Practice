# Peeking Iterator

Problem: 284
Official Difficulty: medium
Feels Like : medium
My Understanding: Needs Review
Topic: Iterator, array, design
Link: https://leetcode.com/problems/peeking-iterator/description/
Completed On : March 11, 2024
Last Review: March 11, 2024
Days Since Review: 50

## Problem

---

Design an iterator that supports the `peek` operation on an existing iterator in addition to the `hasNext` and the `next` operations.

Implement the `PeekingIterator` class:

- `PeekingIterator(Iterator<int> nums)` Initializes the object with the given integer iterator `iterator`.
- `int next()` Returns the next element in the array and moves the pointer to the next element.
- `boolean hasNext()` Returns `true` if there are still elements in the array.
- `int peek()` Returns the next element in the array **without** moving the pointer.

**Note:** Each language may have a different implementation of the constructor and `Iterator`, but they all support the `int next()` and `boolean hasNext()` functions.

**Example 1:**

```
Input
["PeekingIterator", "next", "peek", "next", "next", "hasNext"]
[[[1, 2, 3]], [], [], [], [], []]
Output
[null, 1, 2, 2, 3, false]

Explanation
PeekingIterator peekingIterator = new PeekingIterator([1, 2, 3]); // [1,2,3]
peekingIterator.next();    // return 1, the pointer moves to the next element [1,2,3].
peekingIterator.peek();    // return 2, the pointer does not move [1,2,3].
peekingIterator.next();    // return 2, the pointer moves to the next element [1,2,3]
peekingIterator.next();    // return 3, the pointer moves to the next element [1,2,3]
peekingIterator.hasNext(); // return False
```

**Constraints:**

- `1 <= nums.length <= 1000`
- `1 <= nums[i] <= 1000`
- All the calls to `next` and `peek` are valid.
- At most `1000` calls will be made to `next`, `hasNext`, and `peek`.

**Follow up:**

How would you extend your design to be generic and work with all types, not just integer?

## My Solutions

---

```python
# Below is the interface for Iterator, which is already defined for you.
#
# class Iterator:
#     def __init__(self, nums):
#         """
#         Initializes an iterator object to the beginning of a list.
#         :type nums: List[int]
#         """
#
#     def hasNext(self):
#         """
#         Returns true if the iteration has more elements.
#         :rtype: bool
#         """
#
#     def next(self):
#         """
#         Returns the next element in the iteration.
#         :rtype: int
#         """

class PeekingIterator:

    def __init__(self, iterator):

        self.peeking_iterator = []

        while iterator.hasNext():
            self.peeking_iterator.append(iterator.next())

        self.index = 0
        self.size = len(self.peeking_iterator) 

        """
        Initialize your data structure here.
        :type iterator: Iterator
        """
        
    def peek(self):

        if self.index < self.size:
            return self.peeking_iterator[self.index] 
        
        """
        Returns the next element in the iteration without advancing the iterator.
        :rtype: int
        """
        
    def next(self):
        
        if self.index < self.size:
            current = self.peeking_iterator[self.index]  
            self.index += 1 
            return current
        """
        :rtype: int
        """

    def hasNext(self):

        return self.index < self.size
        """
        :rtype: bool
        """
        

# Your PeekingIterator object will be instantiated and called as such:
# iter = PeekingIterator(Iterator(nums))
# while iter.hasNext():
#     val = iter.peek()   # Get the next element but not advance the iterator.
#     iter.next()         # Should return the same value as [val].
```

Alex’s Solution

```python
# Below is the interface for Iterator, which is already defined for you.
#
# class Iterator:
#     def __init__(self, nums):
#         """
#         Initializes an iterator object to the beginning of a list.
#         :type nums: List[int]
#         """
#
#     def hasNext(self):
#         """
#         Returns true if the iteration has more elements.
#         :rtype: bool
#         """
#
#     def next(self):
#         """
#         Returns the next element in the iteration.
#         :rtype: int
#         """

class PeekingIterator:
    def __init__(self, iterator):
        """
        Initialize your data structure here.
        :type iterator: Iterator
        """
        self.iterator = iterator
        self.next_num = -100000 if not self.iterator.hasNext() else self.iterator.next()
        

    def peek(self):
        """
        Returns the next element in the iteration without advancing the iterator.
        :rtype: int
        """
        if self.next_num == -100000:
            return -1
        return self.next_num

        

    def next(self):
        """
        :rtype: int
        """
        if self.next_num == -100000:
            return -1
        toReturn = self.next_num
        self.next_num = self.iterator.next()
        return toReturn
        

    def hasNext(self):
        """
        :rtype: bool
        """
        return self.next_num != -100000

        

# Your PeekingIterator object will be instantiated and called as such:
# iter = PeekingIterator(Iterator(nums))
# while iter.hasNext():
#     val = iter.peek()   # Get the next element but not advance the iterator.
#     iter.next()         # Should return the same value as [val].
```

## Optimal Solutions

---

The Peeking Iterator problem involves designing a wrapper class around an existing iterator that supports a `peek()` operation in addition to the standard iterator operations. This `peek()` method allows you to look at the next element in the iterator without advancing the iterator itself.

The challenge typically lies in implementing this additional functionality without modifying the original iterator and ensuring that the `next()`, `peek()`, and `hasNext()` methods all work correctly in conjunction.

Here's a basic implementation of the Peeking Iterator that leverages the provided Iterator interface. The implementation caches the next element of the iterator so that the `peek()` method can return it without advancing the iterator:

```python
# Below is the interface for Iterator, which is already defined for you.
#
# class Iterator:
#     def __init__(self, nums):
#         """
#         Initializes an iterator object to the beginning of a list.
#         """
#
#     def hasNext(self):
#         """
#         Returns true if the iteration has more elements.
#         """
#
#     def next(self):
#         """
#         Returns the next element in the iteration.
#         """

class PeekingIterator:
    def __init__(self, iterator):
        self.iterator = iterator
        self._next = iterator.next() if iterator.hasNext() else None
        self._hasNext = iterator.hasNext()

    def peek(self):
        """
        Returns the next element in the iteration without advancing the iterator.
        """
        return self._next

    def next(self):
        """
        Returns the next element in the iteration and advances the iterator.
        """
        tmp = self._next
        self._hasNext = self.iterator.hasNext()
        self._next = self.iterator.next() if self._hasNext else None
        return tmp

    def hasNext(self):
        """
        Returns true if the iteration has more elements.
        """
        return self._hasNext

```

### Explanation:

- **Initialization**: In the `__init__` method, the iterator is stored, and the next element is pre-fetched using `iterator.next()` if there are more elements (`iterator.hasNext()`). The `_hasNext` flag is used to keep track of whether there are further elements in the iterator beyond the cached `_next` element.
- **Peek**: The `peek()` method simply returns the pre-fetched `_next` element, allowing the client to see the next element without moving the iterator.
- **Next**: The `next()` method returns the current `_next` element and advances the iterator by fetching the next element and updating the `_next` and `_hasNext` accordingly.
- **HasNext**: The `hasNext()` method returns the `_hasNext` flag, indicating whether there are more elements to iterate over.

This implementation effectively "peeks" into the iterator without altering its state, except when explicitly moving forward with the `next()` method, and correctly handles the iteration state with `hasNext()`.

## Notes

---

 

## Related Videos

---

[https://www.youtube.com/watch?v=UyGxiD5GtI4](https://www.youtube.com/watch?v=UyGxiD5GtI4)