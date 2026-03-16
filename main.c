#include <stdio.h>
#include "oneo.c"

int main() {
    prompt("insert name: ");
    string name=NULL;
    scan(string, &name);
    
    prompt("insert age: ");
    int age=0;
    scan(int, &age);

    print("Person is called ", name, " and is ", age, " years old");
}
