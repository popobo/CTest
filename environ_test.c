#include <stdio.h>

extern char **environ;

int main() {
    int index = 0;
    while(environ[index] != NULL) {
        printf("environ[index]:%s\n", environ[index]);
        index++;
    }

    return 0;
}