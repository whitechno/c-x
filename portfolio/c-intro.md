# C Programming Tutorial

## Table of Contents

- [Getting Started](#getting-started)
- [Basic Syntax](#basic-syntax)
- [Data Types](#data-types)
- [Control Structures](#control-structures)

## Getting Started

### Setting Up Your Environment

To compile and run C programs, you'll need:

- A text editor (like VS Code)
- A C compiler (like gcc)
- Terminal access

### Your First C Program

```c
#include <stdio.h>

int main() {
    printf("Hello, World!\n");
    return 0;
}
```

## Basic Syntax

### Variables

```c
int number = 42;
float pi = 3.14159;
char letter = 'A';
```

### Functions

```c
int add(int a, int b) {
    return a + b;
}
```

## Data Types

Common data types in C:

| Data Type | Size (bytes)| Description                       | Example Values                              |
|:----------|------------:|:----------------------------------|:--------------------------------------------|
| char      |           1 | Single character/small integer    | 'A', '\n', -128 to 127                      |
| int       |           4 | Integer number                    | -2147483648 to 2147483647                   |
| float     |           4 | Single-precision floating point   | 3.14f, -0.001f                              |
| double    |           8 | Double-precision floating point   | 3.14159265359                               |
| void      |           - | No type/empty type                | Used in functions/pointers                  |
| short     |           2 | Short integer                     | -32768 to 32767                             |
| long      |           8 | Long integer                      | -9223372036854775808 to 9223372036854775807 |
| unsigned  |           4 | Non-negative integer              | 0 to 4294967295                             |

## Control Structures

### If Statement

```c
if (condition) {
    // code block
} else {
    // else block
}
```

### For Loop

```c
for (int i = 0; i < 10; i++) {
    // loop body
}
```

### While Loop

```c
while (condition) {
    // loop body
}
```
