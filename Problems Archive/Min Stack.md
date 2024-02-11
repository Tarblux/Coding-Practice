# Min Stack

Problem: 155
Official Difficulty: medium
Feels Like : easy
Topic: Stack, design
Link: https://leetcode.com/problems/min-stack/
Completed On : December 6, 2023
My Understanding: Fully Understand
Last Review: December 6, 2023
Days Since Review: 66

## Problem

---

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the `MinStack` class:

- `MinStack()` initializes the stack object.
- `void push(int val)` pushes the element `val` onto the stack.
- `void pop()` removes the element on the top of the stack.
- `int top()` gets the top element of the stack.
- `int getMin()` retrieves the minimum element in the stack.

You must implement a solution with `O(1)` time complexity for each function.

**Example 1:**

```
Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2

```

**Constraints:**

- `231 <= val <= 231 - 1`
- Methods `pop`, `top` and `getMin` operations will always be called on **non-empty** stacks.
- At most `3 * 104` calls will be made to `push`, `pop`, `top`, and `getMin`.

**Follow-up:**

How would you solve this problem if you can't use extra space for the minimum values?

## My Solutions

---

```python
class MinStack:

    def __init__(self):
        
        self.array = []
        

    def push(self, val: int) -> None:
        
        self.array.append(val)
        

    def pop(self) -> None:
        
        self.array.reverse()
        
        self.array.pop(0)
        
        self.array.reverse()
        

    def top(self) -> int:
        
        self.array.reverse()
        
        top_val = self.array[0]
        
        self.array.reverse()
        
        return top_val
        

    def getMin(self) -> int:
        
        return min(self.array)
        

# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
```

```python
class MinStack:

    def __init__(self):
        
        self.array = []
        

    def push(self, val: int) -> None:
        
        self.array.append(val)
        

    def pop(self) -> None:
        
        self.array.pop()
        

    def top(self) -> int:
        
        top_val = self.array[-1]

        return top_val
        

    def getMin(self) -> int:
        
        return min(self.array)
```

## Optimal Solutions

---

The "Min Stack" problem is a design problem that requires creating a stack that supports push, pop, top, and retrieving the minimum element in constant time. To achieve this, you need to maintain an auxiliary stack that keeps track of the minimum elements.

### Design Approach

1. **Two Stacks**: Use two stacks - one to store all the elements (`stack`) and another to store the minimum elements (`minStack`).
2. **Push Operation**:
    - Always push the new element onto the main stack.
    - If the `minStack` is empty or the new element is less than or equal to the current minimum (top element of `minStack`), also push it onto the `minStack`.
3. **Pop Operation**:
    - Pop the element from the main stack.
    - If the popped element is the same as the top element of the `minStack`, pop from `minStack` as well.
4. **Top Operation**: Return the top element of the main stack.
5. **Get Minimum**: Return the top element of the `minStack`.

### Python Implementation

Here is a Python implementation of the Min Stack:

```python
class MinStack:

    def __init__(self):
        self.stack = []
        self.minStack = []

    def push(self, val: int) -> None:
        self.stack.append(val)
        if not self.minStack or val <= self.minStack[-1]:
            self.minStack.append(val)

    def pop(self) -> None:
        val = self.stack.pop()
        if val == self.minStack[-1]:
            self.minStack.pop()

    def top(self) -> int:
        return self.stack[-1]

    def getMin(self) -> int:
        return self.minStack[-1]

```

### Complexity Analysis

- **Time Complexity**: O(1) for each operation (`push`, `pop`, `top`, `getMin`). Each operation performs a constant amount of work.
- **Space Complexity**: O(n), where `n` is the number of elements in the stack. In the worst case, the auxiliary stack (`minStack`) might be as large as the main stack.

### Explanation

- **Push**: By keeping the elements in `minStack` in sorted order (the smallest element on top), we can achieve O(1) time complexity for the `getMin` operation.
- **Pop**: We check if the element being popped is the current minimum. If it is, we also pop it from the `minStack` to update our current minimum.
- **Top**: Simply returns the top element of the main stack.
- **GetMin**: Returns the top element of the `minStack`, which is the current minimum.

## Notes

---

 The noob way to do it is to use the min function at the end but that is super slow so you should be going for an approach where you keep track of the minimum value while making the stack and then return that.

## Related Videos

---

[https://www.youtube.com/watch?v=qkLl7nAwDPo](https://www.youtube.com/watch?v=qkLl7nAwDPo)