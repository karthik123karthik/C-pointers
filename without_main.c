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
