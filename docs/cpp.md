
# C++ Guide 

This guide documents all the libraries, functions, and C++ features used in the exercises from modules 00 and 01.

---

## Table of Contents

1. [Used Libraries](#used-libraries)
2. [Namespace std::](#namespace-std)
3. [Input/Output (I/O)](#inputoutput-io)
4. [String Manipulation](#string-manipulation)
5. [File Management](#file-management)
6. [Memory Management](#memory-management)
7. [Classes and OOP](#classes-and-oop)
8. [References and Pointers](#references-and-pointers)

---

## Used Libraries

### `#include <iostream>`
**Purpose:** Standard C++ input/output.

**Main components:**
- `std::cout` - Standard output
- `std::cin` - Standard input
- `std::cerr` - Error output
- `std::endl` - Newline and buffer flush

**Used in:** All exercises

---

### `#include <string>`
**Purpose:** Text string handling in C++.

**Main class:** `std::string`

**Used in:** ex01, ex02, ex04

---

### `#include <cctype>`
**Purpose:** Character classification and conversion functions.

**Functions used:**
- `toupper(char c)` - Converts a character to uppercase
- `isdigit(char c)` - Checks if a character is a digit

**Used in:** ex00, ex01

---

### `#include <cstring>`
**Purpose:** C-style string manipulation functions.

**Functions used:**
- `strncmp(const char *s1, const char *s2, size_t n)` - Compares n characters of two strings

**Used in:** ex00

---

### `#include <iomanip>`
**Purpose:** Format manipulators for streams.

**Functions used:**
- `std::setw(int n)` - Sets the output field width
- `std::put_time()` - Formats and displays time

**Used in:** ex01, ex02

---

### `#include <fstream>`
**Purpose:** File operations (reading and writing).

**Main classes:**
- `std::ifstream` - Input file stream (reading)
- `std::ofstream` - Output file stream (writing)

**Used in:** ex04

---

### `#include <unistd.h>`
**Purpose:** POSIX API for system calls.

**Functions used:**
- `sleep(unsigned int seconds)` - Pauses execution for n seconds

**Used in:** ex01

---

### `#include <cstdlib>`
**Purpose:** General C utilities.

**Functions used:**
- `system(const char *command)` - Executes system commands
- `atoi(const char *str)` - Converts string to int
- `exit(int status)` - Terminates the program

**Used in:** ex01

---

### `#include <cstdio>`
**Purpose:** C-style input/output functions.

**Used in:** ex01

---

## Namespace std::

The `std::` namespace contains all the functionalities of the C++ standard library.

### Usage:
```cpp
// Option 1: std:: prefix
std::cout << "Hello" << std::endl;

// Option 2: Using declaration (used in your exercises)
typedef std::string string;

// Option 3: Using directive (NOT RECOMMENDED in headers)
using namespace std;
```

---

## Input/Output (I/O)

### `std::cout`
**Description:** Standard output stream.

**Usage:**
```cpp
std::cout << "Text" << variable << std::endl;
```

**Operator:** `<<` (insertion)

**Examples from your exercises:**
- `module_00/ex00/megaphone.cpp:24` - Text output
- `module_00/ex01/phonebook.cpp:27` - User messages
- `module_01/ex02/main.cpp:30` - Display memory addresses

---

### `std::cin`
**Description:** Standard input stream.

**Usage:**
```cpp
std::cin >> variable;
```

**Operator:** `>>` (extraction)

**Examples from your exercises:**
- `module_00/ex01/phonebook.cpp:31` - Reading with `std::getline()`

---

### `std::cerr`
**Description:** Error output stream (unbuffered).

**Usage:**
```cpp
std::cerr << "Error: " << message << std::endl;
```

**Difference with cout:**
- `std::cerr` - Unbuffered, for urgent errors
- `std::cout` - Buffered, for normal output

**Examples from your exercises:**
- `module_00/ex01/phonebook.cpp:23` - Argument error message
- `module_01/ex00/main.cpp:22` - Argument validation
- `module_01/ex04/main.cpp:35` - File opening error

---

### `std::endl`
**Description:** Inserts a newline and flushes the buffer.

**Alternatives:**
```cpp
std::cout << "Text" << std::endl;  // Newline + flush
std::cout << "Text\n";             // Only newline (faster)
```

**Used in:** All exercises

---

### `std::getline()`
**Description:** Reads a complete line of input (including spaces).

**Syntax:**
```cpp
std::getline(std::cin, string_variable);
```

**EOF detection:**
```cpp
if (!std::getline(std::cin, input) || std::cin.eof())
{
    // Ctrl+D detected
}
```

**Examples from your exercises:**
- `module_00/ex01/phonebook.cpp:31` - Command reading
- `module_00/ex01/phonebook_options.cpp:28` - Input validation

---

## String Manipulation

### `std::string`
**Description:** Class for dynamic text string handling.

**Methods used:**

#### `.empty()`
Checks if the string is empty.
```cpp
if (input.empty())
    std::cout << "Empty string" << std::endl;
```
**Example:** `module_00/ex01/phonebook_options.cpp:33`

---

#### `.compare()`
Compares two strings.
```cpp
if (!input.compare("ADD"))  // Returns 0 if equal
    // do something
```
**Example:** `module_00/ex01/phonebook.cpp:36`

---

#### `.length()` / `.size()`
Returns the size of the string.
```cpp
if (name.length() > 10)
    name = name.substr(0, 9) + ".";
```
**Example:** `module_00/ex01/phonebook_options.cpp:114`

---

#### `.substr()`
Extracts a substring.
```cpp
string sub = str.substr(start, length);
```
**Example:** `module_00/ex01/phonebook_options.cpp:115`

---

#### `.find()`
Searches for a substring within the string.
```cpp
size_t pos = content.find(s1, start);
if (pos != string::npos)  // npos = not found
    // found
```
**Example:** `module_01/ex04/main.cpp:23`

---

#### `.erase()`
Removes characters from the string.
```cpp
content.erase(position, length);
```
**Example:** `module_01/ex04/main.cpp:25`

---

#### `.insert()`
Inserts characters at a position.
```cpp
content.insert(position, string_to_insert);
```
**Example:** `module_01/ex04/main.cpp:26`

---

#### `.c_str()`
Converts `std::string` to `const char*` (C string).
```cpp
std::ifstream file(filename.c_str());
```
**Example:** `module_01/ex04/main.cpp:43`

---

## File Management

### `std::ifstream` (Input File Stream)
**Description:** Class for file reading.

**Basic usage:**
```cpp
std::ifstream inputFile("file.txt");
if (!inputFile)
{
    std::cerr << "Error opening file" << std::endl;
    return 1;
}

// Read all content
std::string content((std::istreambuf_iterator<char>(inputFile)),
                    std::istreambuf_iterator<char>());

inputFile.close();
```

**Example from your exercises:** `module_01/ex04/main.cpp:43-51`

---

### `std::ofstream` (Output File Stream)
**Description:** Class for file writing.

**Basic usage:**
```cpp
std::ofstream outputFile("file.txt");
if (!outputFile)
{
    std::cerr << "Error creating file" << std::endl;
    return 1;
}

outputFile << "Content to write";
outputFile.close();
```

**Example from your exercises:** `module_01/ex04/main.cpp:55-64`

---

### `std::istreambuf_iterator`
**Description:** Iterator for reading characters from a stream.

**Usage:**
```cpp
// Read entire file into a single string
std::string content((std::istreambuf_iterator<char>(inputFile)),
                    std::istreambuf_iterator<char>());
```

**Example:** `module_01/ex04/main.cpp:50`

---

## Memory Management

### Operator `new`
**Description:** Allocates dynamic memory on the heap.

**Usage:**
```cpp
// Single object
Zombie* zombie = new Zombie();

// Array of objects
Zombie* zombies = new Zombie[N];
```

**Example from your exercises:** `module_01/ex01/zombieHorde.cpp` (implicit in array allocation)

---

### Operator `delete`
**Description:** Frees memory allocated with `new`.

**Usage:**
```cpp
// Single object
delete zombie;

// Array of objects
delete[] zombies;
```

**Example from your exercises:** `module_01/ex01/main.cpp:36`

⚠️ **Important:** Always use `delete[]` for arrays and `delete` for single objects.

---

### Operator `NULL`
**Description:** Null pointer (value 0).

**Usage:**
```cpp
if (zombies == NULL)
    return 1;
```

**Example:** `module_01/ex01/main.cpp:28`

**Note:** In modern C++ `nullptr` is preferred over `NULL`.

---

## Classes and OOP

### Class Definition

**Basic syntax:**
```cpp
class ClassName
{
    public:
        // Public members
        ClassName();           // Constructor
        ~ClassName();          // Destructor
        void method();

    private:
        // Private members
        int variable;
};
```

**Examples from your exercises:**
- `module_00/ex01/phonebook.hpp:25-49` - `contact` class
- `module_00/ex01/phonebook.hpp:51-67` - `phoneBook` class
- `module_01/ex00/Zombie.hpp:18-36` - `Zombie` class

---

### Constructor
**Description:** Special method that initializes an object.

**Syntax:**
```cpp
contact::contact()
{
    // Initialization
}

// Constructor with initialization list
phoneBook::phoneBook() : max_contacts(8), number(0), contacts(0)
{
}
```

**Examples from your exercises:**
- `module_00/ex01/phonebook_contact.cpp:15-17` - Simple constructor
- `module_00/ex01/phonebook_options.cpp:15-17` - Constructor with initialization

---

### Destructor
**Description:** Special method that cleans up an object.

**Syntax:**
```cpp
contact::~contact()
{
    // Cleanup
}
```

**Examples from your exercises:**
- `module_00/ex01/phonebook_contact.cpp:19-21`
- `module_00/ex01/phonebook_options.cpp:19-21`

---

### Getter and Setter Methods

**Setters** (modifiers):
```cpp
void contact::setName(string name)
{
    this->name = name;
}
```

**Getters** (accessors):
```cpp
string contact::getName() const
{
    return this->name;
}
```

**Note:** `const` at the end indicates the method doesn't modify the object.

**Examples from your exercises:**
- `module_00/ex01/phonebook_contact.cpp:23-71`

---

### Keyword `this`
**Description:** Pointer to the current object.

**Usage:**
```cpp
void setName(string name)
{
    this->name = name;  // this->name is the class attribute
                        // name is the parameter
}
```

**Example:** `module_00/ex01/phonebook_contact.cpp:25`

---

### Static Members (`static`)

**Static variables:**
```cpp
class Account
{
    static int _nbAccounts;  // Shared by all instances
};

int Account::_nbAccounts = 0;  // Initialization outside the class
```

**Static methods:**
```cpp
static int getNbAccounts(void)
{
    return Account::_nbAccounts;
}
```

**Example from your exercises:** `module_00/ex02/Account.hpp:43-46`

---

### Access Modifiers

- **`public:`** - Accessible from anywhere
- **`private:`** - Only accessible within the class
- **`protected:`** - Accessible in the class and derived classes

**Example:**
```cpp
class contact
{
    public:
        void setName(string name);  // Accessible from outside

    private:
        string name;  // Only accessible within contact
};
```

---

## References and Pointers

### Pointers (`*`)
**Description:** Variable that stores the memory address of another variable.

**Syntax:**
```cpp
std::string str = "HI THIS IS BRAIN";
std::string* stringPTR = &str;  // Gets the address of str

std::cout << stringPTR;         // Shows the address
std::cout << *stringPTR;        // Dereference: shows the value
```

**Operators:**
- `&` - Address-of operator (gets the address of a variable)
- `*` - Dereference operator (accesses the pointed value)

**Example from your exercises:** `module_01/ex02/main.cpp:27-36`

---

### References (`&`)
**Description:** Alias of an existing variable.

**Syntax:**
```cpp
std::string str = "HI THIS IS BRAIN";
std::string& stringREF = str;  // Reference to str

stringREF = "NEW VALUE";       // Modifies str directly
```

**Differences with pointers:**
- Cannot be NULL
- Cannot change what it refers to
- Doesn't need dereferencing

**Example from your exercises:** `module_01/ex02/main.cpp:28`

---

### Pass by Reference
**Description:** Passes the original variable (not a copy) to a function.

**Syntax:**
```cpp
bool get_input(string &input, const string &prompt)
{
    std::getline(std::cin, input);  // Modifies input directly
    return true;
}
```

**Advantages:**
- Avoids costly copies
- Allows modifying the original variable
- Use `const &` for read-only parameters

**Example from your exercises:** `module_00/ex01/phonebook.hpp:66`

---

## Other Functionalities

### `typedef`
**Description:** Creates an alias for a type.

**Syntax:**
```cpp
typedef std::string string;

// Now you can use 'string' instead of 'std::string'
string name = "John";
```

**Examples from your exercises:**
- `module_00/ex01/phonebook.hpp:23`
- `module_01/ex04/main.cpp:17`

---

### `#pragma once`
**Description:** Include guard (prevents multiple header inclusions).

**Alternative:**
```cpp
// Traditional method
#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
// ... code ...
#endif

// Modern method (used in your exercises)
#pragma once
```

**Example from your exercises:** `module_00/ex01/phonebook.hpp:13`

---

### `(void)variable`
**Description:** Marks a variable as intentionally unused.

**Purpose:** Avoid compiler warnings.

**Syntax:**
```cpp
int main(int argc, char *argv[])
{
    (void)argv;  // argv is not used in this program

    if (argc != 1)
        return 1;
}
```

**Examples from your exercises:**
- `module_00/ex01/phonebook.cpp:19`
- `module_01/ex00/main.cpp:18`

---

### `size_t`
**Description:** Unsigned integer type for sizes and positions.

**Usage:**
```cpp
size_t pos = content.find(s1, start);

for (size_t j = 0; j < ret.length(); j++)
    // iteration
```

**Examples from your exercises:**
- `module_01/ex04/main.cpp:21`
- `module_00/ex01/phonebook_options.cpp:145`

---

### `const`
**Description:** Indicates that a variable or method is not modified.

**Uses:**
```cpp
// Constant variable
const int max_contacts = 8;

// Constant parameter by reference
bool get_input(string &input, const string &prompt);

// Constant method (doesn't modify the object)
string getName() const;
```

**Examples from your exercises:**
- `module_00/ex01/phonebook.hpp:61` - Constant variable
- `module_00/ex01/phonebook.hpp:37` - Constant method
- `module_00/ex01/phonebook.hpp:66` - Constant parameter

---

## System Functions

### `system()`
**Description:** Executes an operating system command.

**Syntax:**
```cpp
system("clear");  // Clears the terminal on Linux/Mac
system("cls");    // Clears the terminal on Windows
```

⚠️ **Warning:** Not portable or secure. Only use in exercises/tests.

**Example from your exercises:** `module_00/ex01/phonebook.cpp:26`

---

### `sleep()`
**Description:** Pauses program execution.

**Syntax:**
```cpp
#include <unistd.h>

sleep(1);  // Pause for 1 second
```

**Example from your exercises:** `module_00/ex01/phonebook_options.cpp:140`

---

### `exit()`
**Description:** Terminates the program immediately.

**Syntax:**
```cpp
exit(0);   // Successful exit
exit(1);   // Exit with error
```

**Example from your exercises:** `module_00/ex01/phonebook_options.cpp:54`

---

## Type Conversion

### `atoi()`
**Description:** Converts C string (`const char*`) to integer.

**Syntax:**
```cpp
const char* str = "123";
int num = atoi(str);

// With std::string
std::string ret = "123";
int index = atoi(ret.c_str());
```

**Example from your exercises:** `module_00/ex01/phonebook_options.cpp:160`

---

### `toupper()`
**Description:** Converts a character to uppercase.

**Syntax:**
```cpp
#include <cctype>

char upper = toupper('a');  // Returns 'A'
std::cout << (char)toupper(argv[i][j]);
```

**Example from your exercises:** `module_00/ex00/megaphone.cpp:38`

---

### `isdigit()`
**Description:** Checks if a character is a digit (0-9).

**Syntax:**
```cpp
#include <cctype>

if (isdigit('5'))  // Returns true
    std::cout << "It's a digit" << std::endl;
```

**Example from your exercises:** `module_00/ex01/phonebook_options.cpp:147`

---

## Output Formatting

### `std::setw()`
**Description:** Sets the output field width.

**Syntax:**
```cpp
#include <iomanip>

std::cout << std::setw(10) << "Text";  // Pads with spaces up to 10 characters
```

**Example from your exercises:** `module_00/ex01/phonebook_options.cpp:98-101`

**Table usage:**
```cpp
std::cout << "|" << std::setw(11) << "Index" << " |";
std::cout << std::setw(11) << "Firstname" << " |";
std::cout << std::setw(11) << "Lastname" << " |";
```

---

## Exercise Summary

### Module 00

#### ex00 - Megaphone
**Concepts:** Basic I/O, string manipulation, character conversion
- `std::cout`, `std::endl`
- `toupper()`, `strncmp()`
- Argument handling (`argc`, `argv`)

#### ex01 - Phonebook
**Concepts:** Classes, OOP, arrays, input validation
- `contact` class with getters/setters
- `phoneBook` class with object array
- `std::getline()`, `std::cin.eof()`
- `std::setw()` for table formatting
- `const` methods

#### ex02 - Account (commented)
**Concepts:** Static members, timestamps
- `static` variables and methods
- `std::put_time()` for time formatting

---

### Module 01

#### ex00 - Zombie
**Concepts:** Basic memory management, classes
- `Zombie` class with `announce()` method
- Methods to create zombies

#### ex01 - Zombie Horde
**Concepts:** Dynamic arrays, new/delete operators
- `new[]` and `delete[]`
- Dynamic array allocation

#### ex02 - HI THIS IS BRAIN
**Concepts:** Pointers and references
- Operators `&` (address) and `*` (dereference)
- References as aliases
- Differences between pointers and references

#### ex04 - Sed is for losers
**Concepts:** File management, string manipulation
- `std::ifstream` and `std::ofstream`
- `std::istreambuf_iterator`
- `.find()`, `.erase()`, `.insert()`
- `.c_str()` for conversion

---

## Observed Best Practices

1. **Input validation:** Always check `argc` and validate user input
2. **EOF detection:** Use `std::cin.eof()` to detect Ctrl+D
3. **Constants:** Use `const` for values that don't change
4. **Const methods:** Mark methods that don't modify the object
5. **References:** Use `const &` for read-only parameters
6. **Memory management:** Free memory allocated with `new` using `delete`
7. **Dynamic arrays:** Use `delete[]` for arrays

---

## C vs C++ Differences

| C | C++ |
|---|-----|
| `printf()` | `std::cout <<` |
| `scanf()` | `std::cin >>` |
| `char*` strings | `std::string` |
| `malloc()/free()` | `new/delete` |
| `struct` | `class` |
| No namespaces | `std::` namespace |

---

## C++ Keywords

- `class` - Defines a class
- `public`/`private` - Access modifiers
- `this` - Pointer to current object
- `new`/`delete` - Dynamic memory management
- `const` - Constants
- `static` - Shared members
- `typedef` - Type aliases
- `#pragma once` - Include guard

---

**Note:** This guide covers the functionalities used so far in modules 00 and 01. It will be updated with new concepts in future modules.
