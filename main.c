#include <stdio.h>
#include <unistd.h>

#include "oneo.c"

#ifndef COMPDIR
#define COMPDIR "."
#endif

int main(int argc, string* argv) {
    char cwd[256];
    char ret[2048];

    getcwd(cwd, sizeof(cwd));

    string libdir = COMPDIR;
    chdir(libdir);

    system("git pull");
    
    sprintf(ret, "cp '%s/oneo.c' %s", libdir, cwd);
    system(ret);
}
