# Strings

### Introduction:

- **Strings in Python** are arrays of bytes representing Unicode characters.
- They are created by enclosing characters in quotes. Python allows for either pairs of single or double quotes.

### Creating Strings:

```python
# String with single quotes
str1 = 'Hello'

# String with double quotes
str2 = "World"

```

### Accessing String Characters:

- Strings are arrays, so you can access elements using square brackets `[]`.
- Slice notation `[start:end]` can be used to get a sub string.

```python
# Accessing characters
char = str1[0]             # Output: 'H'
substring = str2[1:4]      # Output: 'orl'

```

### Modifying Strings:

- Strings are immutable. This means that elements of a string cannot be changed once they have been assigned.
- You can, however, concatenate strings using `+` operator to create a new string.

```python
# Concatenation
new_str = str1 + " " + str2   # Output: 'Hello World'

```

### Escaping Characters:

- Backslash `\` is used to escape characters that otherwise have a special meaning, like quotes.

```python
# Escaping single quote
escaped_str = 'It\'s Python!'
```

### String Methods:

- Python has a set of built-in methods that can be used on strings.

### Raw Strings:

- Prefixing a string with 'r' or 'R' creates a raw string, which passes through backslashes without change.

```python
# Raw string
raw_str = r"Raw \n String"

```

### String Formatting:

- Python provides multiple ways to format strings, including old-style `%` formatting, `str.format()`, and f-strings (formatted string literals).

### Common String Operations:

- Finding length of a string using `len()`.
- String methods like `lower()`, `upper()`, `join()`, `split()`, etc.

### f-Strings in Python

In Python 3.6 and later, a new string formatting mechanism known as f-Strings (or formatted string literals) was introduced. These provide a more readable, concise, and convenient way to format strings.

### Creating f-Strings

- f-Strings are created by prefixing a string with the letter `f` or `F` before the opening quotation mark.
- Inside an f-String, you can directly embed expressions inside curly braces `{}` which will be evaluated at runtime and formatted using the standard `str.format()` syntax.

### Basic Usage of f-Strings

```python
name = "Alice"
age = 25

# Using f-String for formatting
greeting = f"Hello, my name is {name} and I am {age} years old."
print(greeting)  # Output: Hello, my name is Alice and I am 25 years old.

```

### Expressions Inside f-Strings

- You can include any valid Python expression inside the curly braces of an f-String.
- This includes calling functions, arithmetic operations, accessing dictionary values, etc.

```python
# Expression inside f-String
expression_str = f"The sum of 2 and 3 is {2 + 3}."
print(expression_str)  # Output: The sum of 2 and 3 is 5.
```

### Formatting Specifiers

- f-Strings support all the formatting specifiers available to `str.format()`.
- You can format numbers, dates, and more right within the f-String.

```python
import datetime
today = datetime.datetime.now()

# Formatting dates
formatted_date = f"Today's date is {today:%B %d, %Y}."
print(formatted_date)  # Example Output: Today's date is January 18, 2024.
```

### Advantages of f-Strings

- **Readability**: f-Strings are generally more readable and concise than other string formatting methods in Python.
- **Performance**: They are faster than both `%` formatting and `str.format()`.
- **Flexibility**: Easily include Python expressions and perform inline formatting.

f-Strings can be used in conjunction with iterables such as lists, tuples, or dictionaries in Python. This allows for more dynamic and readable string formatting. Below is an example that demonstrates using f-Strings with a list:

### Example: Using f-Strings with a List

Suppose you have a list of fruits and you want to print each fruit in a formatted string:

```python
fruits = ["apple", "banana", "cherry"]

for fruit in fruits:
    print(f"I love eating {fruit}!")
```

In this example, the f-String `f"I love eating {fruit}!"` dynamically inserts each element from the `fruits` list into the string. As the loop iterates over the list, each fruit name is formatted into the string in place of `{fruit}`.

### Output:

```
I love eating apple!
I love eating banana!
I love eating cherry!
```

This example shows how f-Strings can be effectively used to incorporate elements from an iterable into a formatted string, enhancing both code readability and functionality.

## String Methods

### **Most Common For LeetCode :**

These methods are frequently used in coding interviews and competitive programming on platforms like LeetCode.

| Method | Description |
| --- | --- |
| [count()](https://www.w3schools.com/python/ref_string_count.asp) | Returns the number of times a specified value occurs in a string |
| [encode()](https://www.w3schools.com/python/ref_string_encode.asp) | Returns an encoded version of the string |
| [find()](https://www.w3schools.com/python/ref_string_find.asp) | Searches the string for a specified value and returns the position of where it was found |
| [isalnum()](https://www.w3schools.com/python/ref_string_isalnum.asp) | Returns True if all characters in the string are alphanumeric |
| [isdigit()](https://www.w3schools.com/python/ref_string_isdigit.asp) | Returns True if all characters in the string are digits |
| [islower()](https://www.w3schools.com/python/ref_string_islower.asp) | Returns True if all characters in the string are lower case |
| [isupper()](https://www.w3schools.com/python/ref_string_isupper.asp) | Returns True if all characters in the string are upper case |
| [join()](https://www.w3schools.com/python/ref_string_join.asp) | Joins the elements of an iterable to the end of the string |
| [lower()](https://www.w3schools.com/python/ref_string_lower.asp) | Converts a string into lower case |
| [lstrip()](https://www.w3schools.com/python/ref_string_lstrip.asp) | Returns a left trim version of the string |
| [replace()](https://www.w3schools.com/python/ref_string_replace.asp) | Returns a string where a specified value is replaced with a specified value |
| [split()](https://www.w3schools.com/python/ref_string_split.asp) | Splits the string at the specified separator and returns a list |
| [startswith()](https://www.w3schools.com/python/ref_string_startswith.asp) | Returns true if the string starts with the specified value |
| [strip()](https://www.w3schools.com/python/ref_string_strip.asp) | Returns a trimmed version of the string |

- **Least Common For Leetcode**
    - These methods are less frequently used in coding interviews and competitive programming on platforms like LeetCode.
    
    ### String Methods Table
    
    | Method | Description |
    | --- | --- |
    | [capitalize()](https://www.w3schools.com/python/ref_string_capitalize.asp) | Converts the first character to upper case |
    | [casefold()](https://www.w3schools.com/python/ref_string_casefold.asp) | Converts string into lower case |
    | [center()](https://www.w3schools.com/python/ref_string_center.asp) | Returns a centered string |
    | [format()](https://www.w3schools.com/python/ref_string_format.asp) | Formats specified values in a string |
    | [index()](https://www.w3schools.com/python/ref_string_index.asp) | Searches the string for a specified value and returns the position of where it was found |
    | [isalpha()](https://www.w3schools.com/python/ref_string_isalpha.asp) | Returns True if all characters in the string are in the alphabet |
    | [isdecimal()](https://www.w3schools.com/python/ref_string_isdecimal.asp) | Returns True if all characters in the string are decimals |
    | [isidentifier()](https://www.w3schools.com/python/ref_string_isidentifier.asp) | Returns True if the string is an identifier |
    | [isnumeric()](https://www.w3schools.com/python/ref_string_isnumeric.asp) | Returns True if all characters in the string are numeric |
    | [isprintable()](https://www.w3schools.com/python/ref_string_isprintable.asp) | Returns True if all characters in the string are printable |
    | [isspace()](https://www.w3schools.com/python/ref_string_isspace.asp) | Returns True if all characters in the string are whitespaces |
    | [istitle()](https://www.w3schools.com/python/ref_string_istitle.asp) | Returns True if the string follows the rules of a title |
    | [join()](https://www.w3schools.com/python/ref_string_join.asp) | Joins the elements of an iterable to the end of the string |
    | [maketrans()](https://www.w3schools.com/python/ref_string_maketrans.asp) | Returns a translation table to be used in translations |
    | [partition()](https://www.w3schools.com/python/ref_string_partition.asp) | Returns a tuple where the string is parted into three parts |
    | [rfind()](https://www.w3schools.com/python/ref_string_rfind.asp) | Searches the string for a specified value and returns the last position of where it was found |
    | [rindex()](https://www.w3schools.com/python/ref_string_rindex.asp) | Searches the string for a specified value and returns the last position of where it was found |
    | [rjust()](https://www.w3schools.com/python/ref_string_rjust.asp) | Returns a right justified version of the string |
    | [rpartition()](https://www.w3schools.com/python/ref_string_rpartition.asp) | Returns a tuple where the string is parted into three parts |
    | [rsplit()](https://www.w3schools.com/python/ref_string_rsplit.asp) | Splits the string at the specified separator and returns a list |
    | [rstrip()](https://www.w3schools.com/python/ref_string_rstrip.asp) | Returns a right trim version of the string |
    | [splitlines()](https://www.w3schools.com/python/ref_string_splitlines.asp) | Splits the string at line breaks and returns a list |
    | [swapcase()](https://www.w3schools.com/python/ref_string_swapcase.asp) | Swaps cases, lower case becomes upper case and vice versa |
    | [title()](https://www.w3schools.com/python/ref_string_title.asp) | Converts the first character of each word to upper case |
    | [translate()](https://www.w3schools.com/python/ref_string_translate.asp) | Returns a translated string |
    | [upper()](https://www.w3schools.com/python/ref_string_upper.asp) | Converts a string into upper case |
    | [zfill()](https://www.w3schools.com/python/ref_string_zfill.asp) | Fills the string with a specified number of 0 values at the beginning |
