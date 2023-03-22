# 42seoul-cpp00

## Orthodox Canonical Class Form(OCCF)
In C++98 and C++03 the OCCF had four different methods that the C++ compiler is willing to generate:
- Default constructor
- Copy constructor
- Destructor
- Copy assignment operator
```cpp
class A final {
public:
  A ();
  A (const A &a);
  ~A ();
  A & operator = (const A &a);
};
```

## Namespaces
### Namespaces
A mechanism for expressing that some declarations belong together and that their names shouldn't clash with other names.
### using-declaration
A using-declaration makes a name from a namespace usalbe as if it was declared in the scope in which it appears.
```cpp
using std::cout;
```
### using-directive
A using-directive makes unqualified names from the named namespace accessible from the scope in which we placed the directive.
```cpp
using namespace std;
```

## Classes
### struct
A data structure is a group of data elements grouped together under one name.\
These data elements, known as members, can have different types and different lengths.
### class
Classes are an expanded concept of data structures: like data structures, they can contain data members, but they can also contain functions as members.\
There is no fundamental difference between a struct and a class; a struct is simply a class with members public by default.\
There are two concepts, one is "interface", other is "implementation".\
Interface is to be used by all, implementation is what has access to the otherwise inaccessible data.\
Interface is defined by the public members of class, implementation is defined by the private members of class.

## Stdio streams
### iostream
The I/O stream library provides formatted and unformatted buffered I/O of text and numeric values.\
An ostream converts typed objects to a stream of characters(bytes):\
An istream converts a stream of characters(bytes) to typed objects:

## Initialization lists
### Constructors and member initializer lists
Constructor is a special non-static member function of a class that is used to initialize objects of its class type.\
In the definition of a constructor of a class, member initializer list specifies the initializers for direct and virtual bases and non-static data members.

## Static members
### static members
Inside a class definition, the keyword static declares members that are not bound to class instances.\
Outside a class definition, it has a different meaning: see storage duration.
