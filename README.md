# C-pointers
- Pointer is a varible that points to the address of the other variable.
  
## Declaring a pointer and initializing it.
- int* ptr - as pointer will be storing the memory address of the variable it will be holding the hexadecimal values the only reason why we need to specify the datatype is for pointer arithmatics
- ptr will always be pointing to base address.

- eg - int i = 10;
- int *ptr = &i;

- # Dereferncing pointer
- whenever you try to dereference pointer. pointer will see the base memory address and start dereferencing the base address + size of type of pointer.

- eg - int i=10;
- char* ptr = &i;
- printf("%d", *ptr); it will print only one byte of data. as size of char is one byte.
