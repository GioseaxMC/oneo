#include <stdio.h>
#include "oneo.c"

int main() {
    prompt("insert age: ");
    int age=0;
    scan(int, &age);

    prompt("insert name: ");
    string name=NULL;
    scan(string, &name);
    

    print("Person is called ", name, " and is ", age, " years old");
}
