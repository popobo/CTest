#include <stdint.h>

int main() {
    uint32_t temp1 = 0x00000020;
    if (temp1 == 0b0000000) {
        temp1 = 1;
    } else if (temp1 == 0b0100000) {
        temp1 = 1;
    }
}