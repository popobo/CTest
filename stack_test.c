#include <stdio.h>

typedef struct {
  char stack[100];
  int a, b, c;
} PCB;

int main() {
    PCB pcb;

    printf("stack top &pcb.stack[0]:%x, stack bottom &pcb.stack[99]:%x\n", &pcb.stack[0], &pcb.stack[99]);

    return 0;
}