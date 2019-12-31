# Hexagon Engine coding style

## Rules

- Allman braces style are must!

```
while (x == y)
{
    something();
    somethingelse();
}
```

- Indent using spaces

- Regular variable using `snake_case`

```
int foo(bool foo_bar)
{
    int baz_bag = (foo_bar)?1:0;
    ...
}
```

- A defined data type should use PascalCase

```
enum Boolean
{
    True,
    False,
};

class Klass
{
    // Props and method
};

struct Strukt
{
    // Data field
};
```

- Enums type should be defined by using it's namespace

```
enum Boolean{
    True,
    False,
};

...
Boolean::True;
```

- Interfaces/Abstract classes must begin with 'I' prefix and followed by a name with PascalCasing (ex: `IMyInterface`)
- Use `this->` when using a class method/property (ex: `this->MyVariable`, `this->MyFunction()`)

## Basic type aliases for C++ type

| Type alias | original           |
| ---------- | ------------------ |
| int8       | char               |
| int16      | short              |
| int32      | int                |
| int64      | long long          |
| uint8      | unsigned char      |
| uint16     | unsigned short     |
| uint32     | unsigned int       |
| uint64     | unsigned long long |

## Comments

## Modern C++ Syntax

## Code documentation
