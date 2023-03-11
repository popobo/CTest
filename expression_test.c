#include <stdio.h>
#include <sys/types.h>

int main() {
	double result = (  (   215339.0    +( (162.0   )   /   9033.0+  ( 8.0   ) +335999.0   )    *  78018.0  )   ) -  ((   3988.0 ) );
	unsigned int temp = (unsigned int)result;
	long temp2 = (long)result;
	printf("int size=%ld result:%lf\n", sizeof(int), result);
	
	int temp3 = 1 + 0 && 1;
	printf("temp3:%d\n", temp3);

	return 0;
}
