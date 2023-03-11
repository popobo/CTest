#include <stdint.h>

int getbit(void *buf, int offset){
	int byte = offset >> 3;
	offset &= 7;
	uint8_t mask = 1 << offset;
	return (((uint8_t *)buf)[byte] & mask) != 0;
}

__attribute__((noinline))
void setbit(void *buf, int offset, unsigned char bit){
	int byte = offset >> 3;
	offset &= 7;
	uint8_t mask = 1 << offset;

	uint8_t * volatile p = buf + byte;
	*p = (bit == 0 ? (*p & ~mask) : (*p | mask));
}

int main() {
	uint8_t buf[2];

	buf[0] = 0xaa;
	buf[1] = 0x0;
	int ret = getbit(buf, 0);
	// check(getbit(buf, 1) == 1);
	// check(getbit(buf, 2) == 0);
	// check(getbit(buf, 3) == 1);
	// check(getbit(buf, 4) == 0);
	// check(getbit(buf, 5) == 1);
	// check(getbit(buf, 6) == 0);
	// check(getbit(buf, 7) == 1);

	setbit(buf, 8, 1);
	setbit(buf, 9, 0);
	setbit(buf, 10, 1);
	setbit(buf, 11, 0);
	setbit(buf, 12, 1);
	setbit(buf, 13, 0);
	setbit(buf, 14, 1);
	setbit(buf, 15, 0);
	// check(buf[1] == 0x55);

    uint8_t mask = 0b10101010;
    mask = ~mask;

	return 0;
}