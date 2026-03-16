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