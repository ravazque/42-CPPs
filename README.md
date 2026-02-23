# 42 C++ MODULES

## 📖 About

"42 C++ Modules" is a series of projects at 42 Madrid that introduces C++ programming from the ground up. Spanning from Module 00 to Module 09, each module focuses on a specific set of C++ concepts, progressively building knowledge from basic syntax and class design to advanced template programming and STL usage.

The goal is to gain deep familiarity with C++ by implementing increasingly complex programs that cover object-oriented design, memory management, polymorphism, casts, templates, and the Standard Template Library.

## 🎯 Objectives

- Understanding C++ class design, constructors, destructors, and member functions
- Learning memory management with stack and heap allocations, pointers, and references
- Implementing operator overloading and the Orthodox Canonical Form
- Mastering inheritance, virtual functions, abstract classes, and interfaces
- Handling exceptions with try/catch blocks and custom exception classes
- Applying the four C++ casts: `static_cast`, `dynamic_cast`, `reinterpret_cast`, `const_cast`
- Writing generic code with function and class templates
- Using STL containers, iterators, and algorithms effectively
- Implementing classic algorithms such as the Ford-Johnson merge-insert sort

## 📋 Module Overview

<details>
<summary><strong>CPP-Module_00 — Introduction to C++</strong></summary>

### Concepts

**Topics:** Namespaces, classes, member functions, stdio streams, initialization lists, static, const

| Exercise | Name | Description |
|----------|------|-------------|
| ex00 | Megaphone | String manipulation and basic I/O |
| ex01 | PhoneBook | Simple class with static attributes and array of objects |
| ex02 | The Job of Your Dreams | Reconstructing a class from a header file |

</details>

<details>
<summary><strong>CPP-Module_01 — Memory & References</strong></summary>

### Concepts

**Topics:** Memory allocation, pointers to members, references, switch statements

| Exercise | Name | Description |
|----------|------|-------------|
| ex00 | BraiiiiiiinnnzzzZ | Stack vs heap object instantiation |
| ex01 | Moar brainz! | Array of objects on the heap |
| ex02 | HI THIS IS BRAIN | Pointers and references to same variable |
| ex03 | Unnecessary violence | References vs pointers in class members |
| ex04 | Sed is for losers | File I/O and string replacement |
| ex05 | Harl 2.0 | Pointers to member functions |
| ex06 | Harl filter | Switch statement with fall-through |

</details>

<details>
<summary><strong>CPP-Module_02 — Orthodox Canonical Form</strong></summary>

### Concepts

**Topics:** Ad-hoc polymorphism, operator overloading, Orthodox Canonical Form

| Exercise | Name | Description |
|----------|------|-------------|
| ex00 | My First Class in Orthodox Canonical Form | Fixed-point number class with OCF |
| ex01 | Towards a more useful fixed-point number class | Constructors and conversion methods |
| ex02 | Now we're talking | Operator overloading for fixed-point arithmetic |

</details>

<details>
<summary><strong>CPP-Module_03 — Inheritance</strong></summary>

### Concepts

**Topics:** Inheritance, virtual inheritance, diamond problem

| Exercise | Name | Description |
|----------|------|-------------|
| ex00 | Aaaaand... OPEN! | Base class with derived ClapTrap |
| ex01 | Serena, my love! | ScavTrap inheriting from ClapTrap |
| ex02 | Repetitive work | FragTrap inheriting from ClapTrap |
| ex03 | Now it's weird! | DiamondTrap with multiple inheritance |

</details>

<details>
<summary><strong>CPP-Module_04 — Subtype Polymorphism, Abstract Classes & Interfaces</strong></summary>

### Concepts

**Topics:** Subtype polymorphism, abstract classes, interfaces, pure virtual functions, deep copy

| Exercise | Name | Description |
|----------|------|-------------|
| ex00 | Polymorphism | Animal hierarchy with virtual `makeSound()` |
| ex01 | I don't want to set the world on fire | Deep copy with Brain class |
| ex02 | Abstract class | Pure virtual functions to prevent instantiation |
| ex03 | Interface & recap | Pure abstract interfaces with AMateria and ICharacter |

</details>

<details>
<summary><strong>CPP-Module_05 — Repetition and Exceptions</strong></summary>

### Concepts

**Topics:** Exceptions, try/catch blocks, exception classes, nested classes

| Exercise | Name | Description |
|----------|------|-------------|
| ex00 | Mommy, when I grow up, I want to be a bureaucrat! | Bureaucrat class with grade exceptions |
| ex01 | Form up, maggots! | Form class with signing/executing logic |
| ex02 | No, you need form 28B, not 28C... | Concrete form types with actions |
| ex03 | At least this beats coffee-making | Intern class that creates forms |

</details>

<details>
<summary><strong>CPP-Module_06 — C++ Casts</strong></summary>

### Concepts

**Topics:** `static_cast`, `dynamic_cast`, `reinterpret_cast`, `const_cast`

| Exercise | Name | Description |
|----------|------|-------------|
| ex00 | Conversion of scalar types | ScalarConverter: string to int/float/double/char |
| ex01 | Serialization | Serialize/deserialize pointers with `reinterpret_cast` |
| ex02 | Identify real type | Identify derived type from base pointer with `dynamic_cast` |

</details>

<details>
<summary><strong>CPP-Module_07 — C++ Templates</strong></summary>

### Concepts

**Topics:** Function templates, class templates, template specialization

| Exercise | Name | Description |
|----------|------|-------------|
| ex00 | Start with a few functions | `swap`, `min`, `max` as function templates |
| ex01 | Iter | `iter` function template to apply a function to an array |
| ex02 | Array | Generic `Array<T>` class with bounds checking |

</details>

<details>
<summary><strong>CPP-Module_08 — Templated Containers, Iterators, Algorithms</strong></summary>

### Concepts

**Topics:** Templated containers, iterators, STL algorithms

| Exercise | Name | Description |
|----------|------|-------------|
| ex00 | Easy find | `easyfind` template function with STL iterators |
| ex01 | Span | `Span` class storing numbers and finding shortest/longest span |
| ex02 | Mutated abomination | `MutantStack` with iterator support via STL stack |

</details>

<details>
<summary><strong>CPP-Module_09 — STL</strong></summary>

### Concepts

**Topics:** STL containers (`map`, `stack`, `deque`), algorithms, Ford-Johnson sort

| Exercise | Name | Description |
|----------|------|-------------|
| ex00 | Bitcoin Exchange | Parse CSV database and evaluate BTC prices with `std::map` |
| ex01 | Reverse Polish Notation | RPN calculator using `std::stack` |
| ex02 | PmergeMe | Ford-Johnson merge-insert sort with two different containers |

</details>

## 🚀 Installation & Structure

<details>
<summary><strong>📥 Download & Compilation</strong></summary>

<br>

```bash
# Clone the repository
git clone https://github.com/ravazque/42-CPPs.git
cd 42-CPPs

# Compile a specific exercise
cd CPP-Module_XX/exYY
make

# Clean object files
make clean

# Clean everything including executable
make fclean

# Recompile everything
make re
```

<br>

</details>

<details>
<summary><strong>📁 Project Structure</strong></summary>

<br>

```
42-CPPs/
├── CPP-Module_00/
│   ├── ex00/                   # Megaphone
│   ├── ex01/                   # PhoneBook
│   └── ex02/                   # The Job of Your Dreams
├── CPP-Module_01/
│   ├── ex00/ ... ex06/         # Memory & References exercises
├── CPP-Module_02/
│   ├── ex00/ ... ex02/         # Orthodox Canonical Form exercises
├── CPP-Module_03/
│   ├── ex00/ ... ex03/         # Inheritance exercises
├── CPP-Module_04/
│   ├── ex00/ ... ex03/         # Polymorphism exercises
├── CPP-Module_05/
│   ├── ex00/ ... ex03/         # Exceptions exercises
├── CPP-Module_06/
│   ├── ex00/ ... ex02/         # Casts exercises
├── CPP-Module_07/
│   ├── ex00/ ... ex02/         # Templates exercises
├── CPP-Module_08/
│   ├── ex00/ ... ex02/         # STL containers exercises
└── CPP-Module_09/
    ├── ex00/ ... ex02/         # STL algorithms exercises
```

Each exercise follows the structure:
```
exYY/
├── include/        # Header files (.hpp)
├── src/            # Source files (.cpp)
└── Makefile        # Compilation rules
```

<br>

</details>

## 💡 Key Learning Outcomes

The C++ Modules project builds a solid foundation in modern C++ programming:

- **Object-Oriented Design**: Mastery of classes, encapsulation, and the Orthodox Canonical Form
- **Memory Management**: Understanding stack vs heap, deep vs shallow copy, and RAII
- **Polymorphism**: Virtual functions, abstract classes, and interface-based design
- **Exception Safety**: Writing robust programs with proper try/catch and custom exceptions
- **Generic Programming**: Writing reusable code with function and class templates
- **STL Proficiency**: Using containers, iterators, and algorithms from the Standard Library
- **Algorithm Implementation**: Understanding and implementing the Ford-Johnson sort
- **Type System**: Deep knowledge of C++ casts and type safety

## ⚙️ Technical Specifications

- **Language**: C++ (C++98 standard)
- **Compiler**: `c++` with flags `-Wall -Wextra -Werror -std=c++98`
- **Naming Convention**: UpperCamelCase for classes, `.hpp` / `.cpp` file extensions
- **Class Design**: Orthodox Canonical Form required (copy constructor, assignment operator, destructor)
- **Platform**: UNIX-like systems (Linux, macOS)
- **Memory Management**: No memory leaks, proper use of `new` / `delete`
- **STL**: Allowed from Module 08 onward (containers, iterators, algorithms)
- **Forbidden**: `printf`, `alloc`, `free`; C-style casts discouraged from Module 06

---

> [!NOTE]
> This project series serves as a comprehensive introduction to C++ programming, covering the core language features required for professional software development and competitive programming.
