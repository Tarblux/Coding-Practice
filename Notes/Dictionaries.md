# Dictionaries / Hash Map

### Introduction:

- **Python dictionaries** are built-in data types that store collections of key-value pairs.
- Each key-value pair in a dictionary maps a unique key to its associated value.
- Dictionaries are defined using curly braces `{}` with key-value pairs separated by commas.

### Creating a Dictionary

```python
# Creating an empty dictionary
my_dict = {}

# Dictionary with integer keys
my_dict = {1: 'apple', 2: 'ball'}

# Dictionary with mixed keys
my_dict = {'name': 'John', 1: [2, 4, 3]}

```

### Accessing Dictionary Elements:

In Python, dictionaries are collections of key-value pairs where each key is unique. Accessing elements in a dictionary can be done in multiple ways, ensuring flexibility and safety in retrieving values.

### Using Square Brackets `[]`:

- Directly access values using their keys inside square brackets `[]`.
- If the key is not present, this method raises a `KeyError`.

```python
my_dict = {'name': 'John', 1: [2, 4, 3]}

# Accessing elements using square brackets
print(my_dict['name'])  # Output: John
```

### Using the `get()` Method:

- The `get()` method provides a safer way to access values.
- It returns `None` (or a specified default value) if the key is not found, instead of raising an error.

```python
# Using get() to access elements
print(my_dict.get(1))           # Output: [2, 4, 3]
print(my_dict.get('age', 30))   # Output: 30 (default value as 'age' is not a key)
```

### Using `get()` with Iterables to Create Dictionaries:

- When creating a dictionary from an iterable, such as a list, you can use the `get()` method to initialize and update the dictionary values effectively.

```python
A = [1, 2, 3, 1, 5, 6]
dict_counter = {}

for num in A:
    dict_counter[num] = dict_counter.get(num, 0) + 1

# Outputting the resulting dictionary
print(dict_counter)  # Output: {1: 2, 2: 1, 3: 1, 5: 1, 6: 1}
```

- In the above code, `dict_counter.get(num, 0)` returns the current count of `num` in the dictionary, or 0 if `num` is not yet a key. This value is then incremented by 1 and stored back in the dictionary.

### Modifying Dictionaries:

- Dictionaries are mutable, meaning their elements can be changed after creation.

```python
# Update value
my_dict['name'] = 'Doe'

# Add new key-value pair
my_dict['age'] = 25

```

### Removing Elements:

- Use `pop()` to remove an item by key and return its value.
- `popitem()` method removes and returns the last inserted pair (as of Python 3.7).
- `del` keyword removes an individual item or the entire dictionary.
- `clear()` empties the dictionary.

```python
# Remove a specific item
removed_value = my_dict.pop('name')

# Remove the last inserted item
last_item = my_dict.popitem()

# Delete a specific item
del my_dict['age']

# Clear the dictionary
my_dict.clear()

```

### Dictionary Methods:

- `keys()`: returns a view of the dictionary's keys.
- `values()`: returns a view of the dictionary's values.
- `items()`: returns a view of the dictionary's key-value pairs.
- `update()`: updates the dictionary with elements from another dictionary or an iterable of key-value pairs.

```python
# Iterating through keys
for key in my_dict.keys():
    print(key)

# Iterating through values
for value in my_dict.values():
    print(value)

# Iterating through key-value pairs
for key, value in my_dict.items():
    print(key, value)

```

### Comprehensions:

- Similar to lists, dictionaries also support comprehensions to create dictionaries from arbitrary key and value expressions.

```python
# Dictionary comprehensions
squared_numbers = {x: x*x for x in range(6)}

```

### Nested Dictionaries:

- You can nest dictionaries inside other dictionaries to create complex data structures.

```python
# Nested dictionary
my_family = {
    'child1': {'name': 'Emil', 'year': 2004},
    'child2': {'name': 'Tobias', 'year': 2007},
    'child3': {'name': 'Linus', 'year': 2011}
}

```

---

### Specialized Dictionaries in Python

In addition to the standard dictionary, Python offers specialized dictionary types that extend its capabilities and provide additional functionality for specific use cases.

### Counter

- **Purpose**: `Counter` is part of the `collections` module and is used to count hashable objects. It is a subclass of `dict` that helps count hashable objects.
- **Features**:
    - Elements are stored as dictionary keys and their counts are stored as dictionary values.
    - Provides methods for easy counting of items.
- **Example**:
    
    ```python
    from collections import Counter
    
    colors = ['blue', 'red', 'blue', 'yellow', 'blue', 'red']
    color_count = Counter(colors)
    
    print(color_count)  # Output: Counter({'blue': 3, 'red': 2, 'yellow': 1})
    
    ```
    

### Ordered Dict

- **Purpose**: `OrderedDict`, also from the `collections` module, is a dictionary subclass that remembers the order in which its contents are added.
- **Features**:
    - Before Python 3.7, regular dicts did not maintain insertion order. `OrderedDict` was particularly useful to ensure the order of key/value pairs.
    - As of Python 3.7, the built-in `dict` class maintains insertion order by default, but `OrderedDict` still has useful features such as reversing the order.
- **Example**:
    
    ```python
    from collections import OrderedDict
    
    ordered_dict = OrderedDict()
    ordered_dict['banana'] = 3
    ordered_dict['apple'] = 4
    ordered_dict['pear'] = 1
    
    print(ordered_dict)  # Output: OrderedDict([('banana', 3), ('apple', 4), ('pear', 1)])
    
    ```
    

## Dictionary Methods

| Method | Description |
| --- | --- |
| [clear()](https://www.w3schools.com/python/ref_dictionary_clear.asp) | Removes all elements from the dictionary |
| [copy()](https://www.w3schools.com/python/ref_dictionary_copy.asp) | Returns a copy of the dictionary |
| [fromkeys()](https://www.w3schools.com/python/ref_dictionary_fromkeys.asp) | Returns a dictionary with the specified keys and value |
| [get()](https://www.w3schools.com/python/ref_dictionary_get.asp) | Returns the value of the specified key |
| [items()](https://www.w3schools.com/python/ref_dictionary_items.asp) | Returns a list containing a tuple for each key-value pair |
| [keys()](https://www.w3schools.com/python/ref_dictionary_keys.asp) | Returns a list containing the dictionary's keys |
| [pop()](https://www.w3schools.com/python/ref_dictionary_pop.asp) | Removes the element with the specified key |
| [popitem()](https://www.w3schools.com/python/ref_dictionary_popitem.asp) | Removes the last inserted key-value pair |
| [setdefault()](https://www.w3schools.com/python/ref_dictionary_setdefault.asp) | Returns the value of the specified key. If the key does not exist: insert the key, with the specified value |
| [update()](https://www.w3schools.com/python/ref_dictionary_update.asp) | Updates the dictionary with the specified key-value pairs |
| [values()](https://www.w3schools.com/python/ref_dictionary_values.asp) | Returns a list of all the values in the dictionary |
