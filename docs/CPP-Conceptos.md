
# C++ - [ Modulo00 a Modulo04 ]

## Índice
1. [Introducción a C++](#introducción-a-c)
2. [Namespaces](#namespaces)
3. [Clases y Objetos](#clases-y-objetos)
4. [Modificadores de Acceso](#modificadores-de-acceso)
5. [Constructores y Destructores](#constructores-y-destructores)
6. [Miembros Static y Const](#miembros-static-y-const)
7. [Member Functions](#member-functions)
8. [Stdio Streams](#stdio-streams)
9. [Listas de Inicialización](#listas-de-inicialización)
10. [Gestión de Memoria](#gestión-de-memoria)
11. [Punteros vs Referencias](#punteros-vs-referencias)
12. [Punteros a Miembros](#punteros-a-miembros)
13. [Forma Canónica Ortodoxa](#forma-canónica-ortodoxa)
14. [Sobrecarga de Operadores](#sobrecarga-de-operadores)
15. [Herencia](#herencia)
16. [Polimorfismo](#polimorfismo)
17. [Clases Abstractas](#clases-abstractas)
18. [Interfaces](#interfaces)
19. [Copia Profunda vs Copia Superficial](#copia-profunda-vs-copia-superficial)

---

## Clases y Objetos

Una clase es un tipo de dato definido por el usuario que agrupa datos y funciones relacionadas.

### Estructura Básica de una Clase

```cpp
class NombreClase
{
    public:
        // Miembros públicos
        void funcionPublica();

    private:
        // Miembros privados
        int atributoPrivado;

    protected:
        // Miembros protegidos
        float atributoProtegido;
};
```

### Convenciones de Nombres
- **Clases**: UpperCamelCase (ej: `PhoneBook`, `ClapTrap`)
- **Archivos**:
  - Header: `ClassName.hpp` o `ClassName.h`
  - Implementation: `ClassName.cpp`

### Ejemplo Completo

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
    std::cout << "Constructor llamado" << std::endl;
}

Contact::~Contact()
{
    std::cout << "Destructor llamado" << std::endl;
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

## Modificadores de Acceso

Los modificadores de acceso controlan la visibilidad de los miembros de una clase.

### Public
Los miembros públicos son accesibles desde cualquier parte del programa.

```cpp
class Ejemplo
{
    public:
        int valorPublico;
        void funcionPublica();
};
```

### Private
Los miembros privados solo son accesibles desde dentro de la propia clase.

```cpp
class Ejemplo
{
    private:
        int valorPrivado;
        void funcionPrivada();
};
```

### Protected
Los miembros protegidos son accesibles desde la propia clase y sus clases derivadas.

```cpp
class Ejemplo
{
    protected:
        int valorProtegido;
        void funcionProtegida();
};
```

### Regla General
- **Private**: Todo lo que es interno a la clase
- **Public**: La interfaz de la clase (métodos que pueden usar otros objetos)
- **Protected**: Miembros que queremos compartir con clases derivadas

---

## Constructores y Destructores

### Constructores

Un constructor es una función especial que se llama automáticamente cuando se crea un objeto.

#### Constructor por Defecto

```cpp
class MiClase
{
    public:
        MiClase(); // Constructor por defecto
};

MiClase::MiClase()
{
    std::cout << "Constructor por defecto" << std::endl;
}
```

#### Constructor Parametrizado

```cpp
class MiClase
{
    public:
        MiClase(int valor);

    private:
        int _valor;
};

MiClase::MiClase(int valor) : _valor(valor)
{
    std::cout << "Constructor parametrizado" << std::endl;
}
```

#### Constructor de Copia

```cpp
class MiClase
{
    public:
        MiClase(const MiClase &copy);

    private:
        int _valor;
};

MiClase::MiClase(const MiClase &copy)
{
    std::cout << "Constructor de copia" << std::endl;
    *this = copy;
}
```

### Destructores

Un destructor se llama automáticamente cuando un objeto es destruido.

```cpp
class MiClase
{
    public:
        ~MiClase(); // Destructor
};

MiClase::~MiClase()
{
    std::cout << "Destructor llamado" << std::endl;
}
```

**Importante**:
- Los destructores deben imprimir mensajes para debugging
- El orden de destrucción es inverso al de construcción

---

## Miembros Static y Const

### Static Members

Los miembros estáticos pertenecen a la clase, no a las instancias.

```cpp
class Contador
{
    public:
        Contador();
        static int getContador();

    private:
        static int _contador;
};

int Contador::_contador = 0; // Inicialización fuera de la clase

Contador::Contador()
{
    _contador++;
}

int Contador::getContador()
{
    return _contador;
}
```

### Const Members

#### Miembros Const

```cpp
class MiClase
{
    private:
        const int _valorConstante;

    public:
        MiClase(int valor);
};

MiClase::MiClase(int valor) : _valorConstante(valor)
{
    // _valorConstante debe inicializarse en la lista de inicialización
}
```

#### Funciones Const

Las funciones const no pueden modificar el estado del objeto.

```cpp
class MiClase
{
    public:
        int getValor() const; // Función const

    private:
        int _valor;
};

int MiClase::getValor() const
{
    // No puede modificar _valor
    return this->_valor;
}
```

---

## Member Functions

Las funciones miembro son funciones declaradas dentro de una clase.

### Declaración y Definición

```cpp
// En el header (.hpp)
class MiClase
{
    public:
        void funcion1();
        int funcion2(int param);
};

// En el archivo .cpp
void MiClase::funcion1()
{
    std::cout << "Función 1" << std::endl;
}

int MiClase::funcion2(int param)
{
    return param * 2;
}
```

### This Pointer

El puntero `this` apunta al objeto actual.

```cpp
class MiClase
{
    public:
        void setValor(int valor);

    private:
        int _valor;
};

void MiClase::setValor(int valor)
{
    this->_valor = valor; // Uso de this
}
```

---

## Stdio Streams

C++ usa streams para entrada/salida.

### Operadores de Stream

```cpp
#include <iostream>

// Salida
std::cout << "Hola mundo" << std::endl;
std::cout << "Valor: " << 42 << std::endl;

// Entrada
int numero;
std::cin >> numero;

// Error stream
std::cerr << "Error!" << std::endl;
```

### Manipuladores (iomanip)

```cpp
#include <iomanip>

// Ancho de campo
std::cout << std::setw(10) << "Texto" << std::endl;

// Alineación
std::cout << std::right << std::setw(10) << "Derecha" << std::endl;
std::cout << std::left << std::setw(10) << "Izquierda" << std::endl;

// Precisión de flotantes
std::cout << std::setprecision(2) << std::fixed << 3.14159 << std::endl;
```

### Sobrecarga del Operador <<

```cpp
class MiClase
{
    public:
        int getValor() const;
    private:
        int _valor;
};

std::ostream &operator<<(std::ostream &out, const MiClase &obj)
{
    out << obj.getValor();
    return out;
}
```

---

## Listas de Inicialización

Las listas de inicialización permiten inicializar miembros de una clase de forma eficiente.

### Sintaxis

```cpp
class MiClase
{
    public:
        MiClase(int a, int b);

    private:
        int _a;
        int _b;
        const int _c;
};

// Lista de inicialización
MiClase::MiClase(int a, int b) : _a(a), _b(b), _c(42)
{
    // Cuerpo del constructor
}
```

### Cuándo Usar Listas de Inicialización

**Obligatorio para:**
- Miembros const
- Referencias
- Clases sin constructor por defecto
- Clases base

**Ventajas:**
- Más eficiente (evita construcción + asignación)
- Permite inicializar miembros const y referencias

```cpp
class Ejemplo
{
    public:
        Ejemplo(const std::string &nombre);

    private:
        const std::string _nombre;
        int &_referencia;
        OtraClase _objeto;
};

Ejemplo::Ejemplo(const std::string &nombre)
    : _nombre(nombre),           // Const member
      _referencia(variable),     // Referencia
      _objeto(parametro)         // Clase sin constructor por defecto
{
}
```

---

## Gestión de Memoria

### Stack vs Heap

#### Stack (Pila)
- Memoria automática
- Destrucción automática al salir del scope
- Rápida pero limitada

```cpp
void funcion()
{
    MiClase objeto; // En el stack
    // Se destruye automáticamente al salir de la función
}
```

#### Heap (Montón)
- Memoria dinámica
- Requiere new/delete
- Más lenta pero flexible

```cpp
void funcion()
{
    MiClase *objeto = new MiClase(); // En el heap
    // ...
    delete objeto; // ¡Necesario para evitar memory leaks!
}
```

### New y Delete

```cpp
// Crear un objeto
MiClase *obj = new MiClase();

// Crear un array
int *array = new int[10];

// Liberar un objeto
delete obj;

// Liberar un array
delete[] array;
```

### Memory Leaks

**Evitar siempre:**

```cpp
// MAL - Memory leak
void funcion()
{
    int *array = new int[100];
    // ¡No se libera la memoria!
}

// BIEN
void funcion()
{
    int *array = new int[100];
    // ... usar array ...
    delete[] array;
}
```

---

## Punteros vs Referencias

### Punteros

```cpp
int valor = 42;
int *ptr = &valor;

std::cout << *ptr << std::endl; // Desreferencia: 42
std::cout << ptr << std::endl;  // Dirección de memoria

*ptr = 100; // Modifica valor
```

### Referencias

```cpp
int valor = 42;
int &ref = valor; // Referencia debe inicializarse

std::cout << ref << std::endl; // 42

ref = 100; // Modifica valor
```

### Diferencias Clave

| Característica | Puntero | Referencia |
|----------------|---------|------------|
| Puede ser NULL | Sí | No |
| Reasignable | Sí | No |
| Sintaxis | Requiere `*` y `&` | Transparente |
| Inicialización | Opcional | Obligatoria |

### Cuándo Usar Cada Uno

**Punteros:**
- Cuando puede no apuntar a nada (NULL)
- Arrays dinámicos
- Cuando necesitas reasignar

**Referencias:**
- Parámetros de función
- Valores de retorno
- Cuando siempre debe referenciar algo válido

### Ejemplo con Armas (Module 01)

```cpp
class HumanA
{
    public:
        HumanA(std::string name, Weapon &weapon);

    private:
        std::string _name;
        Weapon &_weapon; // Referencia - siempre tiene arma
};

class HumanB
{
    public:
        HumanB(std::string name);
        void setWeapon(Weapon &weapon);

    private:
        std::string _name;
        Weapon *_weapon; // Puntero - puede no tener arma
};
```

---

## Punteros a Miembros

Los punteros a miembros permiten referenciar funciones miembro de una clase.

### Sintaxis

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

### Uso Práctico

```cpp
void Harl::complain(std::string level)
{
    // Array de punteros a funciones miembro
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
            (this->*functions[i])(); // Llamada a función miembro
            return;
        }
    }
}
```

---

## Forma Canónica Ortodoxa

**Desde el Módulo 02, todas las clases deben seguir la Forma Canónica Ortodoxa (Orthodox Canonical Form).**

### Los Cuatro Elementos Obligatorios

1. **Constructor por defecto**
2. **Constructor de copia**
3. **Operador de asignación**
4. **Destructor**

### Plantilla Completa

```cpp
// Header
class MiClase
{
    public:
        MiClase();                          // Constructor por defecto
        MiClase(const MiClase &copy);       // Constructor de copia
        ~MiClase();                         // Destructor

        MiClase &operator=(const MiClase &src); // Operador de asignación

    private:
        int _valor;
};

// Implementation
MiClase::MiClase() : _valor(0)
{
    std::cout << "Constructor por defecto" << std::endl;
}

MiClase::MiClase(const MiClase &copy)
{
    std::cout << "Constructor de copia" << std::endl;
    *this = copy;
}

MiClase::~MiClase()
{
    std::cout << "Destructor" << std::endl;
}

MiClase &MiClase::operator=(const MiClase &src)
{
    std::cout << "Operador de asignación" << std::endl;
    if (this != &src)
    {
        this->_valor = src._valor;
    }
    return *this;
}
```

### Ejemplo del Módulo 02: Clase Fixed

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

## Sobrecarga de Operadores

La sobrecarga de operadores permite definir el comportamiento de operadores para clases personalizadas.

### Operadores de Comparación

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

### Operadores Aritméticos

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

### Operadores de Incremento/Decremento

```cpp
class Fixed
{
    public:
        Fixed &operator++();    // Pre-incremento
        Fixed operator++(int);   // Post-incremento
        Fixed &operator--();    // Pre-decremento
        Fixed operator--(int);   // Post-decremento
};

// Pre-incremento (++x)
Fixed &Fixed::operator++()
{
    this->_fpValue++;
    return *this;
}

// Post-incremento (x++)
Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    ++(*this);
    return temp;
}
```

### Operador de Inserción (<<)

```cpp
std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}
```

---

## Herencia

La herencia permite crear nuevas clases basadas en clases existentes.

### Sintaxis Básica

```cpp
class ClaseBase
{
    public:
        ClaseBase();
        ~ClaseBase();

        void funcionBase();

    protected:
        int _valorProtegido;

    private:
        int _valorPrivado;
};

class ClaseDerivada : public ClaseBase
{
    public:
        ClaseDerivada();
        ~ClaseDerivada();

        void funcionDerivada();

    private:
        int _valorDerivado;
};
```

### Tipos de Herencia

#### Herencia Pública (public)

```cpp
class Derivada : public Base
{
    // Miembros public de Base siguen siendo public
    // Miembros protected de Base siguen siendo protected
};
```

#### Herencia Protegida (protected)

```cpp
class Derivada : protected Base
{
    // Miembros public de Base se convierten en protected
    // Miembros protected de Base siguen siendo protected
};
```

#### Herencia Privada (private)

```cpp
class Derivada : private Base
{
    // Miembros public de Base se convierten en private
    // Miembros protected de Base se convierten en private
};
```

### Cadena de Construcción/Destrucción

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

// Orden de construcción:
// 1. Constructor de ClapTrap
// 2. Constructor de ScavTrap

// Orden de destrucción (inverso):
// 1. Destructor de ScavTrap
// 2. Destructor de ClapTrap
```

### Ejemplo del Módulo 03

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

### Inicialización de Clase Base

```cpp
ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    std::cout << "ScavTrap " << this->_name << " construido" << std::endl;
}
```

---

## Polimorfismo

El polimorfismo permite que objetos de diferentes clases sean tratados de manera uniforme.

### Funciones Virtuales

```cpp
class Base
{
    public:
        virtual void funcion(); // Virtual
        virtual ~Base();        // Destructor virtual
};

class Derivada : public Base
{
    public:
        void funcion(); // Override implícito
        ~Derivada();
};
```

### Herencia Múltiple (Diamond Problem)

El Módulo 03, ejercicio 03 introduce el problema del diamante.

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
        std::string _name; // Propio nombre
    public:
        DiamondTrap(std::string name);
        void whoAmI();
};
```

**Virtual Inheritance** asegura que solo haya una instancia de ClapTrap en DiamondTrap.

### Override de Funciones

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

## Clases Abstractas

Una clase abstracta es una clase que no puede ser instanciada. Contiene al menos una función virtual pura.

### Funciones Virtuales Puras

Una función virtual pura se declara asignando `= 0` a la declaración de la función.

```cpp
class Animal
{
    protected:
        std::string _type;

    public:
        Animal();
        virtual ~Animal();

        virtual void makeSound() const = 0; // Función virtual pura
        std::string getType() const;
};
```

**Puntos Clave:**
- No se pueden crear instancias de clases abstractas
- Las clases derivadas deben implementar todas las funciones virtuales puras para poder ser instanciadas
- Se usan para definir interfaces y clases base

### Ejemplo: Hacer Animal Abstracta

```cpp
class Animal
{
    protected:
        std::string _type;

    public:
        Animal();
        virtual ~Animal();

        virtual void makeSound() const = 0; // Virtual pura - hace la clase abstracta

        std::string getType() const;
};

class Dog : public Animal
{
    public:
        Dog();
        ~Dog();

        void makeSound() const; // Debe implementar
};

class Cat : public Animal
{
    public:
        Cat();
        ~Cat();

        void makeSound() const; // Debe implementar
};

// Esto NO compilará:
// Animal animal; // Error: no se puede instanciar clase abstracta

// Esto SÍ compilará:
Animal *dog = new Dog(); // OK - Dog implementa makeSound()
Animal *cat = new Cat(); // OK - Cat implementa makeSound()
```

### Cuándo Usar Clases Abstractas

- Cuando quieres definir una interfaz común para clases derivadas
- Cuando la clase base no tiene una implementación significativa
- Para prevenir la instanciación de clases base

---

## Interfaces

En C++98, las interfaces se implementan como clases puramente abstractas (clases con solo funciones virtuales puras).

### Definición de Interface

Una interfaz es una clase que:
- Contiene solo funciones virtuales puras
- Tiene un destructor virtual
- No tiene variables miembro (generalmente)

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

### Implementando una Interface

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

        // Implementar todos los métodos de la interfaz
        std::string const &getName() const;
        void equip(AMateria *m);
        void unequip(int idx);
        void use(int idx, ICharacter &target);
};
```

### Ejemplo del Módulo 04: AMateria

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

        virtual AMateria *clone() const = 0; // Virtual pura
        virtual void use(ICharacter &target);
};

class Ice : public AMateria
{
    public:
        Ice();
        Ice(const Ice &copy);
        ~Ice();

        Ice &operator=(const Ice &src);

        AMateria *clone() const; // Debe implementar
        void use(ICharacter &target);
};

class Cure : public AMateria
{
    public:
        Cure();
        Cure(const Cure &copy);
        ~Cure();

        Cure &operator=(const Cure &src);

        AMateria *clone() const; // Debe implementar
        void use(ICharacter &target);
};
```

### Convención de Nombres

Por convención, los nombres de interfaces suelen comenzar con "I":
- `ICharacter`
- `IMateriaSource`
- `IObserver`

---

## Copia Profunda vs Copia Superficial

Entender la diferencia entre copias profundas y superficiales es crucial cuando trabajas con clases que gestionan memoria dinámica.

### Copia Superficial

Una copia superficial copia todos los valores de los miembros directamente. Para punteros, solo se copia la dirección, no los datos apuntados.

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

// El constructor de copia por defecto hace copia SUPERFICIAL
Dog::Dog(const Dog &copy)
{
    this->_brain = copy._brain; // ¡MAL! Ambos apuntan al mismo Brain
}
```

**Problema con la Copia Superficial:**
- Ambos objetos comparten el mismo puntero `Brain`
- Cuando uno es destruido, elimina el `Brain`
- El otro objeto ahora tiene un puntero colgante (dangling pointer)
- La doble eliminación causa crashes

### Copia Profunda

Una copia profunda crea copias independientes de toda la memoria asignada dinámicamente.

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

// Constructor de copia profunda correcto
Dog::Dog(const Dog &copy) : _type(copy._type)
{
    this->_brain = new Brain(*copy._brain); // Crear NUEVO Brain
    std::cout << "Constructor de copia de Dog" << std::endl;
}

// Operador de asignación con copia profunda correcto
Dog &Dog::operator=(const Dog &src)
{
    std::cout << "Operador de asignación de Dog" << std::endl;
    if (this != &src)
    {
        this->_type = src._type;
        delete this->_brain; // Eliminar Brain antiguo
        this->_brain = new Brain(*src._brain); // Crear NUEVO Brain
    }
    return *this;
}

Dog::~Dog()
{
    delete this->_brain;
    std::cout << "Destructor de Dog" << std::endl;
}
```

### Probando la Copia Profunda

```cpp
int main()
{
    Dog basic;
    {
        Dog tmp = basic; // Constructor de copia
        // tmp sale del scope y es destruido
    }
    // ¡basic debería seguir siendo válido!

    Dog dog1;
    Dog dog2;
    dog2 = dog1; // Operador de asignación

    return 0;
}
```

### Diferencias Clave

| Aspecto | Copia Superficial | Copia Profunda |
|---------|------------------|----------------|
| Copia de punteros | Solo copia la dirección | Crea nuevo objeto |
| Independencia | Los objetos comparten datos | Los objetos son independientes |
| Seguridad de memoria | Peligroso (doble delete) | Seguro |
| Rendimiento | Rápido | Más lento (asignación) |

### Cuándo se Requiere Copia Profunda

- Clases con miembros puntero
- Clases que gestionan memoria dinámica
- Clases con recursos (archivos, sockets, etc.)
- Módulo 04: Dog y Cat con atributo Brain

### Mejores Prácticas

1. **Siempre implementar copia profunda** para clases con punteros
2. **Probar tus copias** para asegurar que son independientes
3. **Verificar auto-asignación** en el operador de asignación
4. **Eliminar recursos antiguos** antes de asignar nuevos en el operador de asignación
5. **Usar listas de inicialización** cuando sea posible

---
