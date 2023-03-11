#include "stdint.h"

union {
    uint32_t shamt4_0: 5;
    uint32_t imm11_5 : 7;
    int32_t simm11_0 :12;
} test;

union Instr {
    struct {
      uint32_t opcode1_0 : 2;
      uint32_t opcode6_2 : 5;
      uint32_t rd        : 5;
      uint32_t funct3    : 3;
      uint32_t rs1       : 5;
      int32_t simm11_0   :12;
    //   union {
    //     uint32_t shamt4_0: 5;
    //     uint32_t imm11_5 : 7;
    //     int32_t simm11_0 :12;
    //   };
    } i;
    struct {
      uint32_t opcode1_0 : 2;
      uint32_t opcode6_2 : 5;
      uint32_t imm4_0    : 5;
      uint32_t funct3    : 3;
      uint32_t rs1       : 5;
      uint32_t rs2       : 5;
      int32_t  simm11_5  : 7;
    } s;
    struct {
      uint32_t opcode1_0 : 2;
      uint32_t opcode6_2 : 5;
      uint32_t rd        : 5;
      uint32_t imm31_12  :20;
    } u;
    struct {
        uint32_t opcode1_0 : 2;
        uint32_t opcode6_2 : 5;
        uint32_t rd        : 5;
        uint32_t func3     : 3;
        uint32_t rs1       : 5;
        uint32_t rs2       : 5;
        uint32_t func7     : 7;
    } r;
    struct {
        uint32_t opcode1_0 : 2;
        uint32_t opcode6_2 : 5;
        uint32_t rd        : 5;
        uint32_t imm19_12  : 8;
        uint32_t imm11     : 1;
        uint32_t imm10_1   :10;
        uint32_t simm20    : 1;
    } j;
    uint32_t val;
};

int main() {
    union Instr instr1;
    instr1.val = 0x99999999;
    uint32_t temp1 = instr1.j.simm20 << 20;
    uint32_t temp2 = instr1.j.imm19_12 << 12;
    uint32_t temp3 = instr1.j.imm11 << 11;
    uint32_t temp4 = instr1.j.imm10_1 << 1;
    uint32_t temp5 = temp1 | temp2 | temp3 | temp4;
    
    //*t0 = (s->isa.instr.j.simm20 << 20) | (s->isa.instr.j.imm19_12 << 12) | (s->isa.instr.j.imm11 << 11) | (s->isa.instr.j.imm10_1 << 1);
    
}