
# Object Oriented Programming - OOP

- Procedural programming is about writing procedures or functions that perform operations on the data, while object-oriented programming is about creating objects that contain both data and functions.

- Object-oriented programming has several advantages over procedural programming:

    - OOP is faster and easier to execute
    - OOP provides a clear structure for the programs
    - OOP helps to keep the C++ code DRY "Don't Repeat Yourself", and makes the code easier to maintain, modify and debug
    - OOP makes it possible to create full reusable applications with less code and shorter development time

## Class & Object

- Classes and objects are the two main aspects of object-oriented programming.
- A class is a template for objects, and an object is an instance of a class. When the individual objects are created, they inherit all the variables and functions from the class.

## C++ Classes & Objects

- C++ is an object-oriented programming language.
- Everything in C++ is associated with classes and objects, along with its attributes and methods.
- Attributes and methods are basically variables and functions that belongs to the class.
- A class is a user-defined data type that we can use in our program, and it works as an object constructor, or a "blueprint" for creating objects.

### Create a class in C++

```cpp
class Student {
public:
    string name;
    int englishGrade;
};
```

### Create a object in C++

```cpp
class Student {
public:
    string name;
    int englishGrade;
};

int main() {
    Student a;
    a.name = "Minh";
    a.englishGrade = 9;

    cout << a.name << endl;
    cout << a.englishGrade << endl;

    return 0;
}
```





