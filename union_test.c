#include <stdint.h>
#include <stdio.h>

struct PTE {
    union {
        struct {
            uint32_t V: 1;
            uint32_t R: 1;
            uint32_t W: 1;
            uint32_t X: 1;
            uint32_t U: 1;
            uint32_t G: 1;
            uint32_t A: 1;
            uint32_t D: 1;
            uint32_t RSW: 2;
            uint32_t PPN_01: 22; 
        } union_01;
        struct {
            uint32_t V: 1;
            uint32_t R: 1;
            uint32_t W: 1;
            uint32_t X: 1;
            uint32_t U: 1;
            uint32_t G: 1;
            uint32_t A: 1;
            uint32_t D: 1;
            uint32_t RSW: 2;
            uint32_t PPN_0: 10;
            uint32_t PPN_1: 12;
        } union_0_1;
        uint32_t val;
    } PTE_uo;
};

struct VA {
    union 
    {
        struct {
            uint32_t page_offset: 12;
            uint32_t VPN_0: 10;
            uint32_t VPN_1: 10;            
        } fields;
        uint32_t val;
    } va_no;
};

int main() {
    struct PTE pte;
    pte.PTE_uo.val = 0xffff0001;
    
    struct VA va;
    uint32_t ppn  = 0b1000000011001011001100;

    uint32_t ppn1 = 0b0010000000110010110011;
    uint32_t ppn2 = ppn1 << 12;

    uint32_t temp = 128 * 1024 * 1024;
}