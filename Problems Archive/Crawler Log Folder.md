# Crawler Log Folder

Problem: 1598
Official Difficulty: easy
Feels Like : easy breazy
My Understanding: Fully Understand
Topic: Stack, array, string
Link: https://leetcode.com/problems/crawler-log-folder/description/
Completed On : July 10, 2024
Last Review: July 10, 2024
Days Since Review: 30

## Problem

---

The Leetcode file system keeps a log each time some user performs a *change folder* operation.

The operations are described below:

- `"../"` : Move to the parent folder of the current folder. (If you are already in the main folder, **remain in the same folder**).
- `"./"` : Remain in the same folder.
- `"x/"` : Move to the child folder named `x` (This folder is **guaranteed to always exist**).

You are given a list of strings `logs` where `logs[i]` is the operation performed by the user at the `ith` step.

The file system starts in the main folder, then the operations in `logs` are performed.

Return *the minimum number of operations needed to go back to the main folder after the change folder operations.*

**Example 1:**

![https://assets.leetcode.com/uploads/2020/09/09/sample_11_1957.png](https://assets.leetcode.com/uploads/2020/09/09/sample_11_1957.png)

```
Input: logs = ["d1/","d2/","../","d21/","./"]
Output: 2
Explanation:Use this change folder operation "../" 2 times and go back to the main folder.
```

**Example 2:**

![https://assets.leetcode.com/uploads/2020/09/09/sample_22_1957.png](https://assets.leetcode.com/uploads/2020/09/09/sample_22_1957.png)

```
Input: logs = ["d1/","d2/","./","d3/","../","d31/"]
Output: 3
```

**Example 3:**

```
Input: logs = ["d1/","../","../","../"]
Output: 0
```

**Constraints:**

- `1 <= logs.length <= 103`
- `2 <= logs[i].length <= 10`
- `logs[i]` contains lowercase English letters, digits, `'.'`, and `'/'`.
- `logs[i]` follows the format described in the statement.
- Folder names consist of lowercase English letters and digits.

## My Solutions

---

```python
class Solution:
    def minOperations(self, logs: List[str]) -> int:

        operations = defaultdict(lambda: 1)
        operations["../"] = -1
        operations["./"] = 0

        min_ops = 0

        for op in logs:

            if min_ops == 0 and op == "../":
                continue

            min_ops += operations[op]

        return min_ops
```

### Aleksandr

```python
class LinkedNodePath:
    def __init__(self, val, next=None, prev=None):
        self.val = val
        self.next = next
        self.prev = prev

    def fullPath(self):
        return self.val

    def goBack(self):
        if self.prev == None:
            return self
        before = self.prev
        before.next = None
        return before 

    def goTo(self, dir):
        self.next = LinkedNodePath(self.val + dir, prev=self)
        return self.next

class Solution:
    def minOperations(self, logs: List[str]) -> int:

        root = LinkedNodePath('')
        cur = root
        for log in logs:
            if log == '../':
                cur = cur.goBack()
            elif log == './':
                continue
            else:
                cur = cur.goTo(log)
        
        return cur.fullPath().count('/')
```

## Optimal Solutions

---

## Notes

---

 

## Related Videos

---

[https://youtu.be/Ur3saIXP7ro](https://youtu.be/Ur3saIXP7ro)