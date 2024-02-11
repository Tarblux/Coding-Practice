# Design Browser History

Problem: 1472
Official Difficulty: medium
Feels Like : medium
Topic: Data Stream, Stack, array, design, doubly-linked list, linked list
Link: https://leetcode.com/problems/design-browser-history/description/
Completed On : February 8, 2024
My Understanding: Fully Understand
Last Review: February 8, 2024
Days Since Review: 2

## Problem

---

You have a **browser** of one tab where you start on the `homepage` and you can visit another `url`, get back in the history number of `steps` or move forward in the history number of `steps`.

Implement the `BrowserHistory` class:

- `BrowserHistory(string homepage)` Initializes the object with the `homepage` of the browser.
- `void visit(string url)` Visits `url` from the current page. It clears up all the forward history.
- `string back(int steps)` Move `steps` back in history. If you can only return `x` steps in the history and `steps > x`, you will return only `x` steps. Return the current `url` after moving back in history **at most** `steps`.
- `string forward(int steps)` Move `steps` forward in history. If you can only forward `x` steps in the history and `steps > x`, you will forward only `x` steps. Return the current `url` after forwarding in history **at most** `steps`.

**Example:**

```
Input:
["BrowserHistory","visit","visit","visit","back","back","forward","visit","forward","back","back"]
[["leetcode.com"],["google.com"],["facebook.com"],["youtube.com"],[1],[1],[1],["linkedin.com"],[2],[2],[7]]
Output:
[null,null,null,null,"facebook.com","google.com","facebook.com",null,"linkedin.com","google.com","leetcode.com"]

Explanation:
BrowserHistory browserHistory = new BrowserHistory("leetcode.com");
browserHistory.visit("google.com");       // You are in "leetcode.com". Visit "google.com"
browserHistory.visit("facebook.com");     // You are in "google.com". Visit "facebook.com"
browserHistory.visit("youtube.com");      // You are in "facebook.com". Visit "youtube.com"
browserHistory.back(1);                   // You are in "youtube.com", move back to "facebook.com" return "facebook.com"
browserHistory.back(1);                   // You are in "facebook.com", move back to "google.com" return "google.com"
browserHistory.forward(1);                // You are in "google.com", move forward to "facebook.com" return "facebook.com"
browserHistory.visit("linkedin.com");     // You are in "facebook.com". Visit "linkedin.com"
browserHistory.forward(2);                // You are in "linkedin.com", you cannot move forward any steps.
browserHistory.back(2);                   // You are in "linkedin.com", move back two steps to "facebook.com" then to "google.com". return "google.com"
browserHistory.back(7);                   // You are in "google.com", you can move back only one step to "leetcode.com". return "leetcode.com"
```

**Constraints:**

- `1 <= homepage.length <= 20`
- `1 <= url.length <= 20`
- `1 <= steps <= 100`
- `homepage` and `url` consist of '.' or lower case English letters.
- At most `5000` calls will be made to `visit`, `back`, and `forward`.

## My Solutions

---

```python
class BrowserHistory:

    class Website : 

        def __init__(self, url = 0 , next = None , prev = None ):

            self.url = url

            self.next = None

            self.prev = None

    def __init__(self, homepage: str):

        self.history = self.Website(homepage)

    def visit(self, url: str) -> None:

        self.current = self.history

        self.history.next = self.Website(url)

        self.history = self.history.next

        self.history.prev = self.current

    def back(self, steps: int) -> str:

        while steps != 0 and self.history.prev : 

            self.history = self.history.prev

            steps -= 1

        return self.history.url

    def forward(self, steps: int) -> str:

        while steps != 0 and self.history.next :

            self.history = self.history.next

            steps -= 1

        return self.history.url
        

# Your BrowserHistory object will be instantiated and called as such:
# obj = BrowserHistory(homepage)
# obj.visit(url)
# param_2 = obj.back(steps)
# param_3 = obj.forward(steps)
```

```python

```

## Optimal Solutions

---

To design a browser history feature, you can use two stacks to simulate the operations of going back and forward in the browser history. One stack will keep track of the pages visited as the user navigates through pages (`historyStack`), and the other stack will keep track of the pages that the user has backed out of, which can be visited again using the forward operation (`forwardStack`).

### Python Implementation

Here is how you can implement the Browser History class:

```python
class BrowserHistory:

    def __init__(self, homepage: str):
        self.historyStack = [homepage]  # Initialize history stack with the homepage
        self.forwardStack = []  # Stack to keep track of forward pages

    def visit(self, url: str) -> None:
        self.historyStack.append(url)  # Add the new url to the history stack
        self.forwardStack.clear()  # Clear the forward history since we visited a new page

    def back(self, steps: int) -> str:
        # Move pages from history stack to forward stack based on the steps
        while steps > 0 and len(self.historyStack) > 1:  # Ensure at least the homepage remains in history
            self.forwardStack.append(self.historyStack.pop())
            steps -= 1
        return self.historyStack[-1]  # Return the current page

    def forward(self, steps: int) -> str:
        # Move pages back from forward stack to history stack based on the steps
        while steps > 0 and self.forwardStack:
            self.historyStack.append(self.forwardStack.pop())
            steps -= 1
        return self.historyStack[-1]  # Return the current page

```

### Explanation

- **Initialization**: The constructor initializes the browser history with the homepage.
- **visit(url)**: When visiting a new URL, push it onto the history stack. Clear the forward stack because any "forward" history is invalidated when a new page is visited.
- **back(steps)**: To go back, pop URLs from the history stack and push them onto the forward stack, effectively "moving" back in history. The number of steps to move back is limited by the size of the history stack and the requirement to always have at least one page (the homepage) in the history. Return the current URL after moving back.
- **forward(steps)**: To go forward, reverse the operation of `back` by popping URLs from the forward stack and pushing them back onto the history stack. The number of steps to move forward is limited by the size of the forward stack. Return the current URL after moving forward.

### Complexity Analysis

- **Time Complexity**:
    - O(1) for the `visit` operation, since it involves a constant number of stack operations (push and clear).
    - O(steps) for both the `back` and `forward` operations, where `steps` is the number of steps requested to move. In the worst case, the operation involves popping and pushing each step once.
- **Space Complexity**: O(n) where `n` is the total number of pages visited. This is required to store the history and forward stacks. The worst-case space usage grows linearly with the number of pages visited.

## Notes

---

 Love 

## Related Videos

---

[https://www.youtube.com/watch?v=i1G-kKnBu8k](https://www.youtube.com/watch?v=i1G-kKnBu8k)