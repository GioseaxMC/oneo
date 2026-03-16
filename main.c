#include <stdio.h>
#include "oneo.c"

int main(void) {
    string name;
    scan(string, &name);
    
    print("Name is: ", name);
    return 0;
}