#include "stdlib.h"
#include "stdio.h"

int main() {
	char * test = "100000    ";
	long temp = strtol(test, NULL, 10);
	printf("temp:%ld", temp);
}
