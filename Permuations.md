
```python
def permutations(nums):
    result = []
    
    def backtrack(path, remaining):
        if not remaining:
            result.append(path)
            return
        for i in range(len(remaining)):
            backtrack(path + [remaining[i]], remaining[:i] + remaining[i+1:])
            
    backtrack([], nums)
    return result

# Example usage:
nums = [1, 2, 3]
print(permutations(nums))
```

1. **Function `permutations(nums)`**:
   - This function takes a list of numbers `nums` as input and returns a list of all possible permutations of the elements in `nums`.
   - It initializes an empty list called `result`, which will store all the permutations.

2. **Nested function `backtrack(path, remaining)`**:
   - This is a recursive function responsible for generating permutations.
   - It takes two parameters:
     - `path`: A list representing the current permutation being constructed.
     - `remaining`: A list containing the elements that are yet to be permuted.
   - Inside the function, there's a base case:
     - If `remaining` is empty, it means all elements have been used to form a permutation. In this case, the `path` is a complete permutation, so it is appended to the `result` list.
   - If the base case is not met (i.e., there are remaining elements), it iterates through each element of `remaining`:
     - For each element, it recursively calls `backtrack` with the updated `path` (adding the current element) and `remaining` (excluding the current element). This way, it explores all possible permutations.

3. **Function call `backtrack([], nums)`**:
   - Initiates the permutation generation process with an empty `path` and the entire list of numbers `nums`.
   - This is the starting point for the recursion.

4. **Return `result`**:
   - After all permutations are generated, the function returns the `result` list containing all permutations.

5. **Example usage**:
   - An example list `nums = [1, 2, 3]` is provided, and the `permutations` function is called with this list.
   - The permutations of `[1, 2, 3]` are printed.

Let's understand the process of generating permutations with an example:

For `nums = [1, 2, 3]`:

- Initially, `backtrack([], [1, 2, 3])` is called.
- Inside `backtrack`:
  - `remaining` is `[1, 2, 3]`.
  - It iterates through each element in `[1, 2, 3]`.
  - For `i = 0` (element `1`):
    - It calls `backtrack([1], [2, 3])`.
      - For `i = 0` (element `2`):
        - It calls `backtrack([1, 2], [3])`.
          - For `i = 0` (element `3`):
            - It calls `backtrack([1, 2, 3], [])`.
              - Since `remaining` is empty, `[1, 2, 3]` is appended to `result`.
      - For `i = 1` (element `3`):
        - It calls `backtrack([1, 3], [2])`.
          - For `i = 0` (element `2`):
            - It calls `backtrack([1, 3, 2], [])`.
              - Since `remaining` is empty, `[1, 3, 2]` is appended to `result`.
  - For `i = 1` (element `2`):
    - It calls `backtrack([2], [1, 3])`.
      - For `i = 0` (element `1`):
        - It calls `backtrack([2, 1], [3])`.
          - For `i = 0` (element `3`):
            - It calls `backtrack([2, 1, 3], [])`.
              - Since `remaining` is empty, `[2, 1, 3]` is appended to `result`.
      - For `i = 1` (element `3`):
        - It calls `backtrack([2, 3], [1])`.
          - For `i = 0` (element `1`):
            - It calls `backtrack([2, 3, 1], [])`.
              - Since `remaining` is empty, `[2, 3, 1]` is appended to `result`.
  - For `i = 2` (element `3`):
    - It calls `backtrack([3], [1, 2])`.
      - For `i = 0` (element `1`):
        - It calls `backtrack([3, 1], [2])`.
          - For `i = 0` (element `2`):
            - It calls `backtrack([3, 1, 2], [])`.
              - Since `remaining` is empty, `[3, 1, 2]` is appended to `result`.
      - For `i = 1` (element `2`):
        - It calls `backtrack([3, 2], [1])`.
          - For `i = 0` (element `1`):
            - It calls `backtrack([3, 2, 1], [])`.
              - Since `remaining` is empty, `[3, 2, 1]` is appended to `result`.

Finally, `result` contains all permutations: `[[1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 1, 2], [3, 2, 1]]`, which is printed.