#include <stdio.h>
#include <limits.h>

int main() {
	short temp = SHRT_MIN;
	printf("SHRT_MAX:%d, SHRT_MIN:%d\n", SHRT_MAX, SHRT_MIN);
	
	char temp1 = -127;
	char temp2 = -127;
	char sum = temp1 + temp2;
	
	return 0;
}
