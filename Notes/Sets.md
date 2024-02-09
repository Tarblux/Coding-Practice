# Sets / Hash Sets

### Introduction to Sets/Hash Sets in Python

Sets in Python are collections of unique elements and are commonly used for operations like set theory tasks, membership testing, and eliminating duplicate entries. Python implements sets as hash sets, meaning they are unordered collections of distinct hashable objects.

[https://www.youtube.com/watch?v=t9j8lCUGZXo&pp=ygUOc2V0cyBpbiBweXRob24=](https://www.youtube.com/watch?v=t9j8lCUGZXo&pp=ygUOc2V0cyBpbiBweXRob24=)

### Basic Properties of Sets

- **Unordered**: The elements in a set do not have a defined order.
- **Mutable**: Sets can be modified after their creation.
- **Unique Elements**: Each element in a set is distinct; duplicate elements are not allowed.
- **Hashable**: Elements of the set must be immutable and hashable.

### Creating a Set

- Sets are created using curly braces `{}` or the `set()` function.
- **Example**:
    
    ```python
    my_set = {1, 2, 3}
    another_set = set([4, 5, 6])
    ```
    

### Accessing Elements in a Set

- Sets in Python are unordered, so you cannot access elements using an index or key.
- However, you can iterate through the set using a `for` loop.

**Example**:

```python
my_set = {1, 2, 3, 4, 5}
for element in my_set:
    print(element)  # Prints each element in the set
```

### Modifying Sets

1. **Add Elements**
    - Use the `add()` method to add a single element to a set.
    - **Example**:
        
        ```python
        my_set.add(6)
        print(my_set)  # Output: {1, 2, 3, 4, 5, 6}
        ```
        
2. **Remove Elements**
    - `remove()`: Removes a specified element from the set. Raises a KeyError if the element is not found.
    - `discard()`: Removes a specified element from the set. Does not raise an error if the element is not found.
    - `pop()`: Removes an arbitrary element from the set and returns it. Raises a KeyError if the set is empty.
    
    **Examples**:
    
    ```python
    my_set.remove(2)
    print(my_set)  # Output: {1, 3, 4, 5, 6}
    
    my_set.discard(7)  # No error if the element is not found
    print(my_set)  # Output: {1, 3, 4, 5, 6}
    
    popped_element = my_set.pop()
    print(popped_element)  # Output: Random element from the set
    ```
    

### Set Operations

1. **Union**
    - Combines the elements of two sets without duplicates.
    - **Example**:
        
        ```python
        set_a = {1, 2, 3}
        set_b = {3, 4, 5}
        union_set = set_a.union(set_b)  # or set_a | set_b
        print(union_set)  # Output: {1, 2, 3, 4, 5}
        ```
        
2. **Intersection**
    - Returns the common elements between two sets.
    - **Example**:
        
        ```python
        intersection_set = set_a.intersection(set_b)  # or set_a & set_b
        print(intersection_set)  # Output: {3}
        ```
        
3. **Difference**
    - Returns elements that are in one set but not in the other.
    - **Example**:
        
        ```python
        difference_set = set_a.difference(set_b)  # or set_a - set_b
        print(difference_set)  # Output: {1, 2}
        ```
        
4. **Symmetric Difference**
    - Returns elements that are in either of the sets, but not in both.
    - **Example**:
        
        ```python
        symmetric_diff_set = set_a.symmetric_difference(set_b)  # or set_a ^ set_b
        print(symmetric_diff_set)  # Output: {1, 2, 4, 5}
        ```
        

### Converting Between Sets and Other Data Types

- Convert a list or tuple to a set to remove duplicates or perform set operations.
- Convert a set back to a list or tuple if you need an ordered collection.

**Examples**:

```python
# Converting list to set
my_list = [1, 2, 2, 3, 3, 3]
my_set = set(my_list)
print(my_set)  # Output: {1, 2, 3}

# Converting set to list
my_new_list = list(my_set)
print(my_new_list)  # Output: [1, 2, 3]
```

These examples highlight the utility and functionality of sets in Python, showcasing how they can be used for managing unique items and performing fundamental set operations.

### Set Comprehensions

- Similar to list comprehensions but with curly braces.
- **Example**:
    
    ```python
    squared_set = {x**2 for x in range(10)}
    ```

## Set Methods

Certainly, here's the table with the set methods and their descriptions, with links to W3Schools for each method:

| Method | Description |
| --- | --- |
| [add()](https://www.w3schools.com/python/ref_set_add.asp) | Adds an element to the set |
| [clear()](https://www.w3schools.com/python/ref_set_clear.asp) | Removes all elements from the set |
| [copy()](https://www.w3schools.com/python/ref_set_copy.asp) | Returns a copy of the set |
| [difference()](https://www.w3schools.com/python/ref_set_difference.asp) | Returns a set containing the difference between two or more sets |
| [difference_update()](https://www.w3schools.com/python/ref_set_difference_update.asp) | Removes the items in this set that are also included in another specified set |
| [discard()](https://www.w3schools.com/python/ref_set_discard.asp) | Remove the specified item |
| [intersection()](https://www.w3schools.com/python/ref_set_intersection.asp) | Returns a set, that is the intersection of two other sets |
| [intersection_update()](https://www.w3schools.com/python/ref_set_intersection_update.asp) | Removes the items in this set that are not present in other specified set(s) |
| [isdisjoint()](https://www.w3schools.com/python/ref_set_isdisjoint.asp) | Returns whether two sets have an intersection or not |
| [issubset()](https://www.w3schools.com/python/ref_set_issubset.asp) | Returns whether another set contains this set or not |
| [issuperset()](https://www.w3schools.com/python/ref_set_issuperset.asp) | Returns whether this set contains another set or not |
| [pop()](https://www.w3schools.com/python/ref_set_pop.asp) | Removes an element from the set |
| [remove()](https://www.w3schools.com/python/ref_set_remove.asp) | Removes the specified element |
| [symmetric_difference()](https://www.w3schools.com/python/ref_set_symmetric_difference.asp) | Returns a set with the symmetric differences of two sets |
| [symmetric_difference_update()](https://www.w3schools.com/python/ref_set_symmetric_difference_update.asp) | Inserts the symmetric differences from this set and another |
| [union()](https://www.w3schools.com/python/ref_set_union.asp) | Return a set containing the union of sets |
| [update()](https://www.w3schools.com/python/ref_set_update.asp) | Update the set with the union of this set and others |



These methods provide a comprehensive toolkit for manipulating sets in Python, enabling efficient handling of Sets