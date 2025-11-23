
# C++ - [ Module00 to Module04 ]

## Index
1. [Introduction to C++](#introduction-to-c)
2. [Namespaces](#namespaces)
3. [Classes and Objects](#classes-and-objects)
4. [Access Modifiers](#access-modifiers)
5. [Constructors and Destructors](#constructors-and-destructors)
6. [Static and Const Members](#static-and-const-members)
7. [Member Functions](#member-functions)
8. [Stdio Streams](#stdio-streams)
9. [Initialization Lists](#initialization-lists)
10. [Memory Management](#memory-management)
11. [Pointers vs References](#pointers-vs-references)
12. [Pointers to Members](#pointers-to-members)
13. [Orthodox Canonical Form](#orthodox-canonical-form)
14. [Operator Overloading](#operator-overloading)
15. [Inheritance](#inheritance)
16. [Polymorphism](#polymorphism)
17. [Abstract Classes](#abstract-classes)
18. [Interfaces](#interfaces)
19. [Deep Copy vs Shallow Copy](#deep-copy-vs-shallow-copy)

---

## Classes and Objects

A class is a user-defined data type that groups related data and functions.

### Basic Class Structure

```cpp
class ClassName
{
    public:
        // Public members
        void publicFunction();

    private:
        // Private members
        int privateAttribute;

    protected:
        // Protected members
        float protectedAttribute;
};
```

### Naming Conventions
- **Classes**: UpperCamelCase (e.g., `PhoneBook`, `ClapTrap`)
- **Files**:
  - Header: `ClassName.hpp` or `ClassName.h`
  - Implementation: `ClassName.cpp`

### Complete Example

```cpp
// Contact.hpp
#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact
{
    public:
        Contact();
        ~Contact();

        void setName(std::string name);
        std::string getName() const;

    private:
        std::string _name;
        std::string _phoneNumber;
};

#endif
```

```cpp
// Contact.cpp
#include "Contact.hpp"

Contact::Contact()
{
    std::cout << "Constructor called" << std::endl;
}

Contact::~Contact()
{
    std::cout << "Destructor called" << std::endl;
}

void Contact::setName(std::string name)
{
    this->_name = name;
}

std::string Contact::getName() const
{
    return this->_name;
}
```

---

## Access Modifiers

Access modifiers control the visibility of class members.

### Public
Public members are accessible from anywhere in the program.

```cpp
class Example
{
    public:
        int publicValue;
        void publicFunction();
};
```

### Private
Private members are only accessible from within the class itself.

```cpp
class Example
{
    private:
        int privateValue;
        void privateFunction();
};
```

### Protected
Protected members are accessible from the class itself and its derived classes.

```cpp
class Example
{
    protected:
        int protectedValue;
        void protectedFunction();
};
```

### General Rule
- **Private**: Everything internal to the class
- **Public**: The class interface (methods that other objects can use)
- **Protected**: Members we want to share with derived classes

---

## Constructors and Destructors

### Constructors

A constructor is a special function that is called automatically when an object is created.

#### Default Constructor

```cpp
class MyClass
{
    public:
        MyClass(); // Default constructor
};

MyClass::MyClass()
{
    std::cout << "Default constructor" << std::endl;
}
```

#### Parameterized Constructor

```cpp
class MyClass
{
    public:
        MyClass(int value);

    private:
        int _value;
};

MyClass::MyClass(int value) : _value(value)
{
    std::cout << "Parameterized constructor" << std::endl;
}
```

#### Copy Constructor

```cpp
class MyClass
{
    public:
        MyClass(const MyClass &copy);

    private:
        int _value;
};

MyClass::MyClass(const MyClass &copy)
{
    std::cout << "Copy constructor" << std::endl;
    *this = copy;
}
```

### Destructors

A destructor is called automatically when an object is destroyed.

```cpp
class MyClass
{
    public:
        ~MyClass(); // Destructor
};

MyClass::~MyClass()
{
    std::cout << "Destructor called" << std::endl;
}
```

**Important**:
- Destructors should print messages for debugging
- Destruction order is the reverse of construction order

---

## Static and Const Members

### Static Members

Static members belong to the class, not to individual instances.

```cpp
class Counter
{
    public:
        Counter();
        static int getCounter();

    private:
        static int _counter;
};

int Counter::_counter = 0; // Initialization outside the class

Counter::Counter()
{
    _counter++;
}

int Counter::getCounter()
{
    return _counter;
}
```

### Const Members

#### Const Members

```cpp
class MyClass
{
    private:
        const int _constantValue;

    public:
        MyClass(int value);
};

MyClass::MyClass(int value) : _constantValue(value)
{
    // _constantValue must be initialized in the initialization list
}
```

#### Const Functions

Const functions cannot modify the object's state.

```cpp
class MyClass
{
    public:
        int getValue() const; // Const function

    private:
        int _value;
};

int MyClass::getValue() const
{
    // Cannot modify _value
    return this->_value;
}
```

---

## Member Functions

Member functions are functions declared within a class.

### Declaration and Definition

```cpp
// In the header (.hpp)
class MyClass
{
    public:
        void function1();
        int function2(int param);
};

// In the .cpp file
void MyClass::function1()
{
    std::cout << "Function 1" << std::endl;
}

int MyClass::function2(int param)
{
    return param * 2;
}
```

### This Pointer

The `this` pointer points to the current object.

```cpp
class MyClass
{
    public:
        void setValue(int value);

    private:
        int _value;
};

void MyClass::setValue(int value)
{
    this->_value = value; // Using this
}
```

---

## Stdio Streams

C++ uses streams for input/output.

### Stream Operators

```cpp
#include <iostream>

// Output
std::cout << "Hello world" << std::endl;
std::cout << "Value: " << 42 << std::endl;

// Input
int number;
std::cin >> number;

// Error stream
std::cerr << "Error!" << std::endl;
```

### Manipulators (iomanip)

```cpp
#include <iomanip>

// Field width
std::cout << std::setw(10) << "Text" << std::endl;

// Alignment
std::cout << std::right << std::setw(10) << "Right" << std::endl;
std::cout << std::left << std::setw(10) << "Left" << std::endl;

// Float precision
std::cout << std::setprecision(2) << std::fixed << 3.14159 << std::endl;
```

### Overloading the << Operator

```cpp
class MyClass
{
    public:
        int getValue() const;
    private:
        int _value;
};

std::ostream &operator<<(std::ostream &out, const MyClass &obj)
{
    out << obj.getValue();
    return out;
}
```

---

## Initialization Lists

Initialization lists allow efficient initialization of class members.

### Syntax

```cpp
class MyClass
{
    public:
        MyClass(int a, int b);

    private:
        int _a;
        int _b;
        const int _c;
};

// Initialization list
MyClass::MyClass(int a, int b) : _a(a), _b(b), _c(42)
{
    // Constructor body
}
```

### When to Use Initialization Lists

**Mandatory for:**
- Const members
- References
- Classes without default constructor
- Base classes

**Advantages:**
- More efficient (avoids construction + assignment)
- Allows initialization of const members and references

```cpp
class Example
{
    public:
        Example(const std::string &name);

    private:
        const std::string _name;
        int &_reference;
        OtherClass _object;
};

Example::Example(const std::string &name)
    : _name(name),           // Const member
      _reference(variable),  // Reference
      _object(parameter)     // Class without default constructor
{
}
```

---

## Memory Management

### Stack vs Heap

#### Stack
- Automatic memory
- Automatic destruction when out of scope
- Fast but limited

```cpp
void function()
{
    MyClass object; // On the stack
    // Automatically destroyed when function exits
}
```

#### Heap
- Dynamic memory
- Requires new/delete
- Slower but flexible

```cpp
void function()
{
    MyClass *object = new MyClass(); // On the heap
    // ...
    delete object; // Necessary to avoid memory leaks!
}
```

### New and Delete

```cpp
// Create an object
MyClass *obj = new MyClass();

// Create an array
int *array = new int[10];

// Free an object
delete obj;

// Free an array
delete[] array;
```

### Memory Leaks

**Always avoid:**

```cpp
// BAD - Memory leak
void function()
{
    int *array = new int[100];
    // Memory is not freed!
}

// GOOD
void function()
{
    int *array = new int[100];
    // ... use array ...
    delete[] array;
}
```

---

## Pointers vs References

### Pointers

```cpp
int value = 42;
int *ptr = &value;

std::cout << *ptr << std::endl; // Dereference: 42
std::cout << ptr << std::endl;  // Memory address

*ptr = 100; // Modifies value
```

### References

```cpp
int value = 42;
int &ref = value; // Reference must be initialized

std::cout << ref << std::endl; // 42

ref = 100; // Modifies value
```

### Key Differences

| Feature | Pointer | Reference |
|---------|---------|-----------|
| Can be NULL | Yes | No |
| Reassignable | Yes | No |
| Syntax | Requires `*` and `&` | Transparent |
| Initialization | Optional | Mandatory |

### When to Use Each

**Pointers:**
- When it can point to nothing (NULL)
- Dynamic arrays
- When you need to reassign

**References:**
- Function parameters
- Return values
- When it must always reference something valid

### Weapon Example (Module 01)

```cpp
class HumanA
{
    public:
        HumanA(std::string name, Weapon &weapon);

    private:
        std::string _name;
        Weapon &_weapon; // Reference - always has a weapon
};

class HumanB
{
    public:
        HumanB(std::string name);
        void setWeapon(Weapon &weapon);

    private:
        std::string _name;
        Weapon *_weapon; // Pointer - may not have a weapon
};
```

---

## Pointers to Members

Pointers to members allow referencing member functions of a class.

### Syntax

```cpp
class Harl
{
    public:
        void debug(void);
        void info(void);
        void warning(void);
        void error(void);

        void complain(std::string level);

    private:
        void (Harl::*functions[4])(void);
};
```

### Practical Use

```cpp
void Harl::complain(std::string level)
{
    // Array of pointers to member functions
    void (Harl::*functions[4])(void) = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };

    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    for (int i = 0; i < 4; i++)
    {
        if (levels[i] == level)
        {
            (this->*functions[i])(); // Member function call
            return;
        }
    }
}
```

---

## Orthodox Canonical Form

**From Module 02 onwards, all classes must follow the Orthodox Canonical Form.**

### The Four Mandatory Elements

1. **Default constructor**
2. **Copy constructor**
3. **Assignment operator**
4. **Destructor**

### Complete Template

```cpp
// Header
class MyClass
{
    public:
        MyClass();                          // Default constructor
        MyClass(const MyClass &copy);       // Copy constructor
        ~MyClass();                         // Destructor

        MyClass &operator=(const MyClass &src); // Assignment operator

    private:
        int _value;
};

// Implementation
MyClass::MyClass() : _value(0)
{
    std::cout << "Default constructor" << std::endl;
}

MyClass::MyClass(const MyClass &copy)
{
    std::cout << "Copy constructor" << std::endl;
    *this = copy;
}

MyClass::~MyClass()
{
    std::cout << "Destructor" << std::endl;
}

MyClass &MyClass::operator=(const MyClass &src)
{
    std::cout << "Assignment operator" << std::endl;
    if (this != &src)
    {
        this->_value = src._value;
    }
    return (*this);
}
```

### Module 02 Example: Fixed Class

```cpp
class Fixed
{
    private:
        int _fpValue;
        static const int _fractBits;

    public:
        Fixed();
        Fixed(const Fixed &copy);
        ~Fixed();

        Fixed &operator=(const Fixed &src);

        int getRawBits(void) const;
        void setRawBits(int const raw);
};
```

---

## Operator Overloading

Operator overloading allows defining operator behavior for custom classes.

### Comparison Operators

```cpp
class Fixed
{
    public:
        bool operator>(const Fixed &other) const;
        bool operator<(const Fixed &other) const;
        bool operator>=(const Fixed &other) const;
        bool operator<=(const Fixed &other) const;
        bool operator==(const Fixed &other) const;
        bool operator!=(const Fixed &other) const;
};

bool Fixed::operator>(const Fixed &other) const
{
    return this->_fpValue > other._fpValue;
}
```

### Arithmetic Operators

```cpp
class Fixed
{
    public:
        Fixed operator+(const Fixed &other) const;
        Fixed operator-(const Fixed &other) const;
        Fixed operator*(const Fixed &other) const;
        Fixed operator/(const Fixed &other) const;
};

Fixed Fixed::operator+(const Fixed &other) const
{
    Fixed result;
    result.setRawBits(this->_fpValue + other._fpValue);
    return result;
}
```

### Increment/Decrement Operators

```cpp
class Fixed
{
    public:
        Fixed &operator++();    // Pre-increment
        Fixed operator++(int);   // Post-increment
        Fixed &operator--();    // Pre-decrement
        Fixed operator--(int);   // Post-decrement
};

// Pre-increment (++x)
Fixed &Fixed::operator++()
{
    this->_fpValue++;
    return (*this);
}

// Post-increment (x++)
Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    ++(*this);
    return temp;
}
```

### Insertion Operator (<<)

```cpp
std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}
```

---

## Inheritance

Inheritance allows creating new classes based on existing classes.

### Basic Syntax

```cpp
class BaseClass
{
    public:
        BaseClass();
        ~BaseClass();

        void baseFunction();

    protected:
        int _protectedValue;

    private:
        int _privateValue;
};

class DerivedClass : public BaseClass
{
    public:
        DerivedClass();
        ~DerivedClass();

        void derivedFunction();

    private:
        int _derivedValue;
};
```

### Types of Inheritance

#### Public Inheritance

```cpp
class Derived : public Base
{
    // Public members of Base remain public
    // Protected members of Base remain protected
};
```

#### Protected Inheritance

```cpp
class Derived : protected Base
{
    // Public members of Base become protected
    // Protected members of Base remain protected
};
```

#### Private Inheritance

```cpp
class Derived : private Base
{
    // Public members of Base become private
    // Protected members of Base become private
};
```

### Construction/Destruction Chain

```cpp
class ClapTrap
{
    public:
        ClapTrap();
        ~ClapTrap();
};

class ScavTrap : public ClapTrap
{
    public:
        ScavTrap();
        ~ScavTrap();
};

// Construction order:
// 1. ClapTrap constructor
// 2. ScavTrap constructor

// Destruction order (reverse):
// 1. ScavTrap destructor
// 2. ClapTrap destructor
```

### Module 03 Example

```cpp
class ClapTrap
{
    protected:
        std::string _name;
        int _hitPoints;
        int _energyPoints;
        int _attackDamage;

    public:
        ClapTrap();
        ClapTrap(std::string name);
        ~ClapTrap();

        void attack(const std::string &target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

class ScavTrap : public ClapTrap
{
    public:
        ScavTrap();
        ScavTrap(std::string name);
        ~ScavTrap();

        void attack(const std::string &target); // Override
        void guardGate();
};
```

### Base Class Initialization

```cpp
ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    std::cout << "ScavTrap " << this->_name << " constructed" << std::endl;
}
```

---

## Polymorphism

Polymorphism allows objects of different classes to be treated uniformly.

### Virtual Functions

```cpp
class Base
{
    public:
        virtual void function(); // Virtual
        virtual ~Base();         // Virtual destructor
};

class Derived : public Base
{
    public:
        void function(); // Implicit override
        ~Derived();
};
```

### Multiple Inheritance (Diamond Problem)

Module 03, exercise 03 introduces the diamond problem.

```cpp
class ClapTrap
{
    protected:
        std::string _name;
};

class ScavTrap : public virtual ClapTrap // Virtual inheritance
{
};

class FragTrap : public virtual ClapTrap // Virtual inheritance
{
};

class DiamondTrap : public ScavTrap, public FragTrap
{
    private:
        std::string _name; // Own name
    public:
        DiamondTrap(std::string name);
        void whoAmI();
};
```

**Virtual Inheritance** ensures there is only one instance of ClapTrap in DiamondTrap.

### Function Override

```cpp
class ScavTrap : public ClapTrap
{
    public:
        void attack(const std::string &target); // Override
};

void ScavTrap::attack(const std::string &target)
{
    std::cout << "ScavTrap " << this->_name
              << " attacks " << target << std::endl;
}
```

---

## Abstract Classes

An abstract class is a class that cannot be instantiated. It contains at least one pure virtual function.

### Pure Virtual Functions

A pure virtual function is declared by assigning `= 0` to the function declaration.

```cpp
class Animal
{
    protected:
        std::string _type;

    public:
        Animal();
        virtual ~Animal();

        virtual void makeSound() const = 0; // Pure virtual function
        std::string getType() const;
};
```

**Key Points:**
- Cannot create instances of abstract classes
- Derived classes must implement all pure virtual functions to be instantiable
- Used to define interfaces and base classes

### Example: Making Animal Abstract

```cpp
class Animal
{
    protected:
        std::string _type;

    public:
        Animal();
        virtual ~Animal();

        virtual void makeSound() const = 0; // Pure virtual - makes class abstract

        std::string getType() const;
};

class Dog : public Animal
{
    public:
        Dog();
        ~Dog();

        void makeSound() const; // Must implement
};

class Cat : public Animal
{
    public:
        Cat();
        ~Cat();

        void makeSound() const; // Must implement
};

// This will NOT compile:
// Animal animal; // Error: cannot instantiate abstract class

// This WILL compile:
Animal *dog = new Dog(); // OK - Dog implements makeSound()
Animal *cat = new Cat(); // OK - Cat implements makeSound()
```

### When to Use Abstract Classes

- When you want to define a common interface for derived classes
- When the base class doesn't have a meaningful implementation
- To prevent instantiation of base classes

---

## Interfaces

In C++98, interfaces are implemented as pure abstract classes (classes with only pure virtual functions).

### Interface Definition

An interface is a class that:
- Contains only pure virtual functions
- Has a virtual destructor
- Has no member variables (usually)

```cpp
class ICharacter
{
    public:
        virtual ~ICharacter() {}
        virtual std::string const &getName() const = 0;
        virtual void equip(AMateria *m) = 0;
        virtual void unequip(int idx) = 0;
        virtual void use(int idx, ICharacter &target) = 0;
};
```

### Implementing an Interface

```cpp
class Character : public ICharacter
{
    private:
        std::string _name;
        AMateria *_inventory[4];

    public:
        Character(std::string const &name);
        Character(const Character &copy);
        ~Character();

        Character &operator=(const Character &src);

        // Implement all interface methods
        std::string const &getName() const;
        void equip(AMateria *m);
        void unequip(int idx);
        void use(int idx, ICharacter &target);
};
```

### Module 04 Example: AMateria

```cpp
class AMateria
{
    protected:
        std::string _type;

    public:
        AMateria(std::string const &type);
        AMateria(const AMateria &copy);
        virtual ~AMateria();

        AMateria &operator=(const AMateria &src);

        std::string const &getType() const;

        virtual AMateria *clone() const = 0; // Pure virtual
        virtual void use(ICharacter &target);
};

class Ice : public AMateria
{
    public:
        Ice();
        Ice(const Ice &copy);
        ~Ice();

        Ice &operator=(const Ice &src);

        AMateria *clone() const; // Must implement
        void use(ICharacter &target);
};

class Cure : public AMateria
{
    public:
        Cure();
        Cure(const Cure &copy);
        ~Cure();

        Cure &operator=(const Cure &src);

        AMateria *clone() const; // Must implement
        void use(ICharacter &target);
};
```

### Naming Convention

By convention, interface names often start with "I":
- `ICharacter`
- `IMateriaSource`
- `IObserver`

---

## Deep Copy vs Shallow Copy

Understanding the difference between deep and shallow copies is crucial when working with classes that manage dynamic memory.

### Shallow Copy

A shallow copy copies all member values directly. For pointers, only the address is copied, not the pointed-to data.

```cpp
class Brain
{
    private:
        std::string _ideas[100];

    public:
        Brain();
        ~Brain();

        std::string getIdea(int index) const;
        void setIdea(int index, std::string idea);
};

class Dog
{
    private:
        Brain *_brain;

    public:
        Dog();
        ~Dog();
};

// Default copy constructor does SHALLOW copy
Dog::Dog(const Dog &copy)
{
    this->_brain = copy._brain; // WRONG! Both point to same Brain
}
```

**Problem with Shallow Copy:**
- Both objects share the same `Brain` pointer
- When one is destroyed, it deletes the `Brain`
- The other object now has a dangling pointer
- Double deletion causes crashes

### Deep Copy

A deep copy creates independent copies of all dynamically allocated memory.

```cpp
class Dog
{
    private:
        Brain *_brain;
        std::string _type;

    public:
        Dog();
        Dog(const Dog &copy);
        ~Dog();

        Dog &operator=(const Dog &src);
};

// Proper deep copy constructor
Dog::Dog(const Dog &copy) : _type(copy._type)
{
    this->_brain = new Brain(*copy._brain); // Create NEW Brain
    std::cout << "Dog copy constructor" << std::endl;
}

// Proper deep copy assignment operator
Dog &Dog::operator=(const Dog &src)
{
    std::cout << "Dog assignment operator" << std::endl;
    if (this != &src)
    {
        this->_type = src._type;
        delete this->_brain; // Delete old Brain
        this->_brain = new Brain(*src._brain); // Create NEW Brain
    }
    return (*this);
}

Dog::~Dog()
{
    delete this->_brain;
    std::cout << "Dog destructor" << std::endl;
}
```

### Testing Deep Copy

```cpp
int main()
{
    Dog basic;
    {
        Dog tmp = basic; // Copy constructor
        // tmp goes out of scope and is destroyed
    }
    // basic should still be valid!

    Dog dog1;
    Dog dog2;
    dog2 = dog1; // Assignment operator

    return 0;
}
```

### Key Differences

| Aspect | Shallow Copy | Deep Copy |
|--------|--------------|-----------|
| Pointer copying | Copies address only | Creates new object |
| Independence | Objects share data | Objects are independent |
| Memory safety | Dangerous (double delete) | Safe |
| Performance | Fast | Slower (allocation) |

### When Deep Copy is Required

- Classes with pointer members
- Classes managing dynamic memory
- Classes with resources (files, sockets, etc.)
- Module 04: Dog and Cat with Brain attribute

### Best Practices

1. **Always implement deep copy** for classes with pointers
2. **Test your copies** to ensure they're independent
3. **Check for self-assignment** in assignment operator
4. **Delete old resources** before allocating new ones in assignment operator
5. **Use initialization lists** when possible
