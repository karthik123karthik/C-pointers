#include <stdio.h>

// this function will compile but fail in the linking stage
// that is .o file will get created but not .out file 

// start program will try to find main function

// there will be vector table which will have the address of main function
// it will reset stack pointer and instruct pointer to jump to main function
// it will also contains interrupt handlers address
void func(){
    printf("HELLOD WORLD\n");
}

// this attribute is a GNU extension which specify the properties or characteristics of the variable or the function
const int vector_table[] __attribute__((section(".vector_table"))) = {
    0x20001000,                  // initial stack pointer
    (int)func,                   // address of func
    (uint32_t) Reset_Handler,    // Reset handler
    (uint32_t) NMI_Handler,      // NMI handler
    (uint32_t) HardFault_Handler, // Hard fault handler
    // ... more interrupt handlers
};
