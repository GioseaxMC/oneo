# Oneo.c – Single-File C Learning Library

**Oneo** is a lightweight, single-file C library aimed at making learning C easier. It provides utilities, macros, and patterns to help understand core C concepts quickly.

## Features

- Helpers for type-aware printing
- Safe dynamic array
- Simple memory management

## Usage

Include and use directly:

```c
#include <stdio.h>
#include "oneo.c"

int main() {
    prompt("insert name: ");
    string name;
    scan(string, &name);
    
    prompt("insert age: ");
    int age;
    scan(int, &age);

    print("Person is called ", name, " and is ", age, " years old");
}
