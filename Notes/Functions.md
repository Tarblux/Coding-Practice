# Functions

In Python, a function is a reusable block of code that performs a specific task. It's like a mini-program within your program that you can call whenever you need to perform that task. Functions help organize your code into manageable and reusable pieces, making your code base more modular and easier to understand.

The line print('Hello, world!') means “Print out the text in the string 'Hello, world!'.” When Python executes this line, you say that Python is calling the print() function and the string value is being passed to the function. A value that is passed to a function call is an argument. Notice that the quotes are not printed to the screen. They just mark where the string begins and ends; they are not part of the string value.

Here's a simple breakdown of the key components of a function:

1. **Function Definition:** This is where you define the function, giving it a name and specifying its parameters (inputs) and an optional return type.
2. **Parameters:** Parameters are variables that you define in the function's parentheses. They act as placeholders for values that you pass into the function when you call it. Functions can have zero or more parameters.
3. **Function Body:** The body of the function consists of the code that gets executed when the function is called. It contains the instructions for performing the specific task the function is designed for.
4. **Return Statement:** If a function is supposed to produce a result, you can use the `return` statement to send a value back to the code that called the function. This value can then be used or stored as needed.

<aside>
💡 After a function returns a value it stops right there - Aleksandr

</aside>

Here's a simple example of a function that adds two numbers together and returns the result:

```python
def add_numbers(a, b):
    result = a + b
    return result

# Call the function
sum_result = add_numbers(5, 3)
print("Sum:", sum_result)  # Output: Sum: 8
```

In this example:

- `def add_numbers(a, b):` defines the function named `add_numbers` with two parameters `a` and `b`.
- `result = a + b` calculates the sum of the two input numbers.
- `return result` sends the calculated sum back to the code that called the function.
- `add_numbers(5, 3)` is the function call, passing `5` and `3` as arguments to the function.
- `sum_result` stores the returned value from the function call.

By using functions, you can write code more efficiently, avoid duplicating code, and make your code base more organized and maintainable.

## Python Built-in Functions

### Most Useful For LeetCode
| Function                                                | Description                                                                     |
| ------------------------------------------------------- | ------------------------------------------------------------------------------- |
| [abs()](https://www.w3schools.com/python/ref_func_abs.asp)      | Returns the absolute value of a number                                          |
| [all()](https://www.w3schools.com/python/ref_func_all.asp)       | Returns True if all items in an iterable object are true                        |
| [any()](https://www.w3schools.com/python/ref_func_any.asp)       | Returns True if any item in an iterable object is true                          |
| [dict()](https://www.w3schools.com/python/ref_func_dict.asp)      | Returns a dictionary (Array)                                                    |
| [enumerate()](https://www.w3schools.com/python/ref_func_enumerate.asp) | Converts a collection (e.g., a tuple) and returns it as an enumerate object     |
| [filter()](https://www.w3schools.com/python/ref_func_filter.asp)    | Use a filter function to exclude items in an iterable object                    |
| [int()](https://www.w3schools.com/python/ref_func_int.asp)       | Returns an integer number                                                       |
| [len()](https://www.w3schools.com/python/ref_func_len.asp)       | Returns the length of an object                                                 |
| [list()](https://www.w3schools.com/python/ref_func_list.asp)      | Returns a list                                                                  |
| [map()](https://www.w3schools.com/python/ref_func_map.asp)       | Returns the specified iterator with the specified function applied to each item |
| [max()](https://www.w3schools.com/python/ref_func_max.asp)       | Returns the largest item in an iterable                                         |
| [min()](https://www.w3schools.com/python/ref_func_min.asp)       | Returns the smallest item in an iterable                                        |
| [next()](https://www.w3schools.com/python/ref_func_next.asp)      | Returns the next item in an iterable                                            |
| [range()](https://www.w3schools.com/python/ref_func_range.asp)     | Returns a sequence of numbers                                                   |
| [set()](https://www.w3schools.com/python/ref_func_set.asp)       | Returns a new set object                                                        |
| [sorted()](https://www.w3schools.com/python/ref_func_sorted.asp)    | Returns a sorted list                                                           |
| [sum()](https://www.w3schools.com/python/ref_func_sum.asp)       | Returns sum of iterable                                                         |

### Least Useful for LeetCode
| Function                                                | Description                                                                        |
| ------------------------------------------------------- | ---------------------------------------------------------------------------------- |
| [ascii()](https://www.w3schools.com/python/ref_func_ascii.asp)     | Returns a readable version of an object, replacing non-ASCII characters            |
| [bin()](https://www.w3schools.com/python/ref_func_bin.asp)       | Returns the binary version of a number                                             |
| [bytes()](https://www.w3schools.com/python/ref_func_bytes.asp)     | Returns a bytes object                                                             |
| [callable()](https://www.w3schools.com/python/ref_func_callable.asp)  | Returns True if the specified object is callable                                   |
| [chr()](https://www.w3schools.com/python/ref_func_chr.asp)       | Returns a character from the specified Unicode code                                |
| [compile()](https://www.w3schools.com/python/ref_func_compile.asp)   | Returns the specified source as an object, ready to be executed                    |
| [complex()](https://www.w3schools.com/python/ref_func_complex.asp)   | Returns a complex number                                                           |
| [delattr()](https://www.w3schools.com/python/ref_func_delattr.asp)   | Deletes the specified attribute (property or method) from the specified object     |
| [eval()](https://www.w3schools.com/python/ref_func_eval.asp)      | Evaluates and executes an expression                                               |
| [exec()](https://www.w3schools.com/python/ref_func_exec.asp)      | Executes the specified code (or object)                                            |
| [float()](https://www.w3schools.com/python/ref_func_float.asp)     | Returns a floating-point number                                                    |
| [format()](https://www.w3schools.com/python/ref_func_format.asp)    | Formats a specified value                                                          |
| [frozenset()](https://www.w3schools.com/python/ref_func_frozenset.asp) | Returns a frozenset object                                                         |
| [getattr()](https://www.w3schools.com/python/ref_func_getattr.asp)   | Returns the value of the specified attribute (property or method)                  |
| [globals()](https://www.w3schools.com/python/ref_func_globals.asp)   | Returns the current global symbol table as a dictionary                            |
| [hasattr()](https://www.w3schools.com/python/ref_func_hasattr.asp)   | Returns True if the specified object has the specified attribute (property/method) |
| [hash()](https://docs.python.org/3/library/functions.html#hash)   | Returns the hash value of a specified object                                       |
| [help()](https://docs.python.org/3/library/functions.html#help)   | Executes the built-in help system                                                  |


# Recursion

Recursion is a powerful and fundamental concept in computer science and programming. It involves solving a problem by breaking it down into smaller, more manageable instances of the same problem. In this comprehensive guide, we will explore the principles of recursion, its applications, and provide graphical illustrations where possible.

## 1. Introduction to Recursion

Recursion is a problem-solving technique where a function calls itself to solve a smaller instance of the same problem. It is based on the idea of dividing a problem into sub problems, solving each sub problem independently, and then combining their solutions to obtain the final result.

### Quick Video

[https://www.youtube.com/watch?v=ivl5-snqul8](https://www.youtube.com/watch?v=ivl5-snqul8)

### Comprehensive Video

[https://www.youtube.com/watch?v=GOs07Kn2W1E](https://www.youtube.com/watch?v=GOs07Kn2W1E)

## 2. Basic Concepts

### Base Case

Every recursive function should have a base case, which defines the simplest scenario where the function returns a result without making any further recursive calls. The base case is essential to prevent infinite recursion.

### Recursive Case

The recursive case defines how the problem is divided into smaller subproblems. It includes the recursive call(s) to the same function with modified arguments. Each recursive call should progress toward the base case.

## 3. How Recursion Works

Recursion works by breaking a complex problem into simpler instances of the same problem. Each recursive call operates on a smaller subset of the data, and when the base case is reached, the results are combined to solve the original problem.

## 4. Recursion vs. Iteration

Recursion and iteration (looping) are two ways to solve problems iteratively. Recursion offers a more elegant and concise solution for problems that can be naturally divided into subproblems. Iteration is often preferred for efficiency and when dealing with problems that don't naturally exhibit recursive behavior.

## 5. Applications of Recursion

Recursion is used in various algorithms and applications. Here are some common examples:

### 1. Factorial

The factorial of a non-negative integer **n** , denoted as **n!** , is the product of all positive integers from 1 to **n** . It is defined recursively as:

$n! = \begin{cases}
  1 & \text{if } n = 0 \\
  n \cdot (n-1)! & \text{if } n > 0
\end{cases}$

**Python Code Example:**

```python
def factorial(n):
    if n == 0:
        return 1
    else:
        return n * factorial(n-1)
```

### 2. Fibonacci Sequence

The Fibonacci sequence is a series of numbers where each number is the sum of the two preceding ones. It is defined recursively as:

$$
F(n) = \begin{cases}
  0 & \text{if } n = 0 \\
  1 & \text{if } n = 1 \\
  F(n-1) + F(n-2) & \text{if } n > 1
\end{cases}
$$

**Python Code Example:**

```python
def fibonacci(n):
    if n <= 1:
        return n
    else:
        return fibonacci(n-1) + fibonacci(n-2)
```

[https://www.youtube.com/watch?v=dDokMfPpfu4](https://www.youtube.com/watch?v=dDokMfPpfu4)

### 3. Binary Search

Binary search is an efficient algorithm for finding a target value in a sorted array. It uses recursion to divide the search interval in half and eliminate half of the remaining elements in each step.

**Python Code Example:**

```python
def binary_search(arr, target, left, right):
    if left > right:
        return -1  # Base case: target not found
    mid = (left + right) // 2
    if arr[mid] == target:
        return mid  # Base case: target found
    elif arr[mid] < target:
        return binary_search(arr, target, mid + 1, right)  # Search right half
    else:
        return binary_search(arr, target, left, mid - 1)  # Search left half
```

### 4. Tower of Hanoi

The Tower of Hanoi is a classic puzzle that involves moving a stack of disks from one peg to another while obeying specific rules. It can be solved recursively.

**Python Code Example:**

```python
def tower_of_hanoi(n, source, auxiliary, target):
    if n == 1:
        print(f"Move disk 1 from {source} to {target}")
        return
    tower_of_hanoi(n-1, source, target, auxiliary)
    print(f"Move disk {n} from {source} to {target}")
    tower_of_hanoi(n-1, auxiliary, source, target)
```

## 6. Graphical Illustration

Graphical illustrations can help visualize recursion. Below are diagrams for the Fibonacci sequence and the Tower of Hanoi:

*Fibonacci Sequence Visualization*

![https://upload.wikimedia.org/wikipedia/commons/thumb/0/07/Tower_of_Hanoi.jpeg/400px-Tower_of_Hanoi.jpeg](https://upload.wikimedia.org/wikipedia/commons/thumb/0/07/Tower_of_Hanoi.jpeg/400px-Tower_of_Hanoi.jpeg)

*Tower of Hanoi Visualization*

## 7. Best Practices

- Ensure there is a base case to terminate recursion.
- Verify that recursive calls make progress toward the base case.
- Avoid excessive recursion to prevent stack overflow errors.
- Optimize recursive algorithms when possible.

## 8. Common Pitfalls

- Forgetting the base case.
- Not ensuring progress toward the base case.
- Using recursion when iteration is more efficient.
- Exceeding the maximum recursion depth.

## 9. Conclusion

Recursion is a powerful technique for solving problems by breaking them down into smaller instances. It is widely used in algorithms,data structures, and programming tasks. Understanding the principles of recursion and practicing with different examples is essential for becoming a proficient programmer. [https://realpython.com/python-recursion/](https://realpython.com/python-recursion/)
