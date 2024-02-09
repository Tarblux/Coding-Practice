# Object Oriented Programming

Object-Oriented Programming (OOP) in Python is a method of structuring a program by bundling related properties and behaviors into individual objects. In this guide, we'll explore the fundamental concepts of OOP in Python, including classes, objects, the four pillars of OOP, and other key concepts like instance variables and abstract methods.

### Quick Video

[https://www.youtube.com/watch?v=q2SGW2VgwAM](https://www.youtube.com/watch?v=q2SGW2VgwAM)

### Comprehensive Video

[https://www.youtube.com/watch?v=Ej_02ICOIgs](https://www.youtube.com/watch?v=Ej_02ICOIgs)

### Basic Concepts

1. **Classes and Objects**
    - **Classes**: Blueprints for creating objects (a particular data structure), providing initial values for state (attributes) and implementations of behavior (methods).
    - **Objects**: Instances of classes; a combination of data and functionality.
    - **Example**:
        
        ```python
        class Dog:
            def __init__(self, name, age):
                self.name = name
                self.age = age
        
            def bark(self):
                print("Woof!")
        
        my_dog = Dog("Fido", 3)
        my_dog.bark()
        
        ```
        
2. **Instance Variables**
    - Variables that are unique to each instance.
    - Defined within methods and prefixed with `self`.
    - **Example**:
        
        ```python
        class Dog:
            def __init__(self, name, age):
                self.name = name  # Instance variable
                self.age = age    # Instance variable
        
        ```
        
3. **Class Variables**
    - Variables that are shared among all instances of a class.
    - Defined within the class but outside any methods.
    - **Example**:
        
        ```python
        class Dog:
            species = "Canis familiaris"  # Class variable
        
            def __init__(self, name, age):
                self.name = name
                self.age = age
        
        ```
        

### The Four Pillars of OOP

1. **Encapsulation**
    - Combining data and the code that manipulates it into a single unit, a class.
    - Protects the data from outside interference and misuse.
2. **Abstraction**
    - Hiding complex implementation details and showing only the necessary features.
    - Can be achieved using abstract classes and methods.
    - **Abstract Method Example**:
        
        ```python
        from abc import ABC, abstractmethod
        
        class Animal(ABC):
            @abstractmethod
            def sound(self):
                pass
        
        class Dog(Animal):
            def sound(self):
                return "Woof!"
        
        ```
        
3. **Inheritance**
    - Allows new classes to inherit properties and methods from existing classes.
    - Helps to reduce code redundancy.
    - **Example**:
        
        ```python
        class Animal:
            def __init__(self, name):
                self.name = name
        
            def speak(self):
                pass
        
        class Dog(Animal):
            def speak(self):
                return f"{self.name} says Woof!"
        
        ```
        
4. **Polymorphism**
    - Allows objects of different classes to be treated as objects of a common superclass.
    - It's about using a unified interface to operate on objects of different classes.
    - **Example**:
        
        ```python
        for animal in [Dog("Fido"), Cat("Whiskers")]:
            print(animal.speak())
        
        ```
        

### Additional Key Concepts

1. **`self` Keyword**
    - Represents the instance of the class and is used to access the attributes and methods of the class.
    - Automatically passed as the first parameter to class methods.
2. **Method Overloading and Overriding**
    - **Overloading**: Python does not support method overloading by default. However, we can achieve it by default arguments or variable-length arguments.
    - **Overriding**: Redefining methods in a subclass that have been defined in a superclass.
3. **Special Methods**
    - Also known as magic methods, like `__init__`, `__str__`, `__repr__`.
    - Allows us to emulate the behavior of built-in types.
4. **Property Decorators**
    - Getters, setters, and deleters for handling attributes more effectively.
    - **Example**:
        
        ```python
        class Person:
            def __init__(self, name):
                self._name = name
        
            @property
            def name(self):
                return self._name
        
            @name.setter
            def name(self, value):
                self._name = value
        
            @name.deleter
            def name(self):
                del self._name
        
        ```
        

### Conclusion

OOP in Python is a robust and flexible way to write clean, modular, and reusable code. By mastering classes and objects, the four pillars of OOP, and other essential concepts like instance variables, method overriding, and property decorators, you can effectively solve complex problems in a structured and efficient manner.