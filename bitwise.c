#include <stdio.h>

void printUnsignedBinary(unsigned int n) {
    for (int i = sizeof(n) * 8 - 1; i >= 0; i--) {
        putchar((n & (1U << i)) ? '1' : '0');
        if (i % 8 == 0) putchar(' '); // Add space every byte for readability
    }
    putchar('\n');
}

void printSignedBinary(int n) {
    for (int i = sizeof(n) * 8 - 1; i >= 0; i--) {
        putchar((n & (1U << i)) ? '1' : '0');
        if (i % 8 == 0) putchar(' '); // Add space every byte for readability
    }
    putchar('\n');
}


int main(){
    unsigned int a = 10;
    int b = -20;
    printf("a = %u, b = %d\n", a, b);

    unsigned int x = a >> 3;
    printf("a >> 3 = %u\n", x);
    printUnsignedBinary(x);
    // When performing arithmetic between signed and unsigned types, the signed type is converted to unsigned.
    int y = b >> 3;
    printf("b >> 3 = %d\n", y);
    printSignedBinary(y);
    //for negative numbers right shift fills most significant bits with 1s when left shift is done

    int z = b << 31;
    printf("b << 32 = %d\n", z);
    printSignedBinary(b);       
    printSignedBinary(z);

    return 0;
}
