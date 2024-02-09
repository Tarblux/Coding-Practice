# Basics

## General Stuff

- Always remember that " = " means that something is storing that value and not that it is equal. "==" means that it is equal
- When a + is used on an integer or a float it works as normal plus sign but when it is applied to two strings it works a concatenation operator and it joins the strings together. + operator CANNOT be used on a string and an integer.
- The operator (*) multiplies two integer or floating point values but when used on a string and an integer it becomes the string replication operator and repeats the string n times where n is an integer.

## Math Operators

| Operators | Operation                                                                                      |
| --------- | ---------------------------------------------------------------------------------------------- |
| **        | Exponent                                                                                       |
| %         | Modulus (Remainder after division)                                                             |
| /         | Division                                                                                       |
| //        | Floor Division (Divides and rounds to the nearest Integer, basically just toss the decimal : ) |
| *         | Multiplication                                                                                 |
| -         | Subtraction                                                                                    |
| +         | Addition                                                                                       |

### Examples

| Operation | Result    |
| --------- | --------- |
| 3**4      | 81        |
| 22%7      | 1         |
| 22/7      | 3.14285… |
| 22//7     | 3         |
| 3*5       | 15        |
| 5-2       | 3         |
| 2+2       | 4         |

The Order of precedence is ** , * , / , // , % , + , -
In general Python follows PEMDAS
P - Parentheses
E - Exponents
M - Multiplication

D - Division
A - Addition
S - Subtraction

# Augmented Operators

When assigning a value to a variable, you will frequently use the variable itself. For example, after assigning 42 to the variable spam, you would increase the value in spam by 1 with the following code:

```python
spam = 42
spam = spam + 1
spam
```

Output: 43

As a shortcut, you can use the augmented assignment operator += to do the same thing:

```python
spam = 42
spam += 1
spam
```

Output: 43

| Augmented | Equivalent      |
| --------- | --------------- |
| +=        | spam = spam + 1 |
| -=        | spam = spam - 1 |
| /=        | spam = spam / 1 |
| *=        | spam = spam * 1 |
| %=        | spam = spam % 1 |

## Methods

A method is the same thing as a function, except it is “called on” a value. For example, if a list value were stored in spam, you would call the index() list method (which I’ll explain shortly) on that list like so: spam.index('hello'). The method part comes after the value, separated by a period.

**Methods vs. Functions:**

In Python, a method is essentially a function that is associated with an object, and it is called on that object. Functions, on the other hand, are standalone blocks of code. Here's a comparison:

```python
# Function
def greet(name):
    return f"Hello, {name}!"

# Method
class Greeting:
    def greet(self, name):
        return f"Hello, {name}!"

greeting = Greeting()
print(greeting.greet("Alice"))  # Calling the method on an instance

```

**Built-in Methods:**

Python provides many built-in methods that you can use with various data types. Here are examples for strings and lists:

```python
# String methods
text = "python programming"
print(text.upper())        # Convert to uppercase
print(text.replace("python", "Java"))  # Replace text

# List methods
numbers = [1, 2, 3, 4, 5]
numbers.append(6)  # Add an element to the list
numbers.pop()       # Remove and return the last element

```

**Custom Methods:**

You can define your own methods in classes:

```python
class Calculator:
    def add(self, a, b):
        return a + b

calc = Calculator()
result = calc.add(5, 3)
print(result)

```

**Method Chaining:**

Method chaining is a technique where multiple methods are called on an object in a single line, one after the other. Each method returns the modified object, allowing you to chain more methods. Here's an example:

```python
class StringManipulator:
    def __init__(self, value):
        self.value = value

    def capitalize(self):
        self.value = self.value.capitalize()
        return self  # Return self for chaining

    def reverse(self):
        self.value = self.value[::-1]
        return self

text = "hello world"
manipulated_text = StringManipulator(text).capitalize().reverse().value
print(manipulated_text)  # Outputs "DLROW OLLEH"

```

**Method Parameters:**

Methods can take parameters (arguments) that are used within the method's logic:

```python
class Rectangle:
    def __init__(self, width, height):
        self.width = width
        self.height = height

    def area(self):
        return self.width * self.height

rect = Rectangle(4, 5)
print(rect.area())  # Calculates and prints the area

```

**Returning Values:**

Methods can return values, which can be stored in variables or used directly:

```python
class Calculator:
    def add(self, a, b):
        return a + b

    def subtract(self, a, b):
        return a - b

calc = Calculator()
sum_result = calc.add(5, 3)
difference_result = calc.subtract(7, 2)
print(sum_result, difference_result)  # Outputs 8 5

```

**Method Documentation:**

It's good practice to include documentation (doc strings) for methods to describe their purpose and usage:

```python
class MyClass:
    def my_method(self, arg1, arg2):
        """
        This is a docstring.
        It describes what the method does.

        :param arg1: The first argument
        :param arg2: The second argument
        :return: The result of the method
        """
        return arg1 + arg2

# Access documentation
help(MyClass.my_method)

```

**Method Naming Conventions:**

Python follows naming conventions for methods, typically using lowercase letters and underscores:

```python
class MyData:
    def get_data(self):
        return "Data retrieved"

    def set_data(self, new_data):
        self.data = new_data

my_instance = MyData()
my_instance.set_data("New value")
print(my_instance.get_data())  # Outputs "New value"

```
