#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define BLOCK 4096

typedef void (*func)(char*);

// TODO remove dead code
void unsafe_run(char* cmd) {
    system(cmd);
}

void say_hi(char* name) {
    printf("Hello, %s", name);
}

int main() {
    func a = say_hi;
    char buf[128];

    read(0, buf, BLOCK); // oops!
    a(buf);
}
