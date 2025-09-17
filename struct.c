#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>


int main(){
    struct A{
        int count;
        int arr[];
    };

    printf("Size of struct A: %lu\n", sizeof(struct A)); // Should be 4 or 8 depending on architecture

    struct A obj;
    obj.count = 5;
    obj.arr[0] = 10; // Undefined behavior, no space allocated for arr
    printf("obj.count: %d\n", obj.count);

    struct A* obj2 = malloc(sizeof(struct A)+5*sizeof(int));
    obj2->count = 5;
    for(int i=0;i<obj2->count;i++){
        obj2->arr[i] = i*10;
    }

    struct B{
        int a;
        int b;
    };

    struct B* bobj = (struct B*)malloc(sizeof(struct B) + sizeof(int));

    bobj->a = 1;
    bobj->b = 2;
    int* extraSpace = (int*)((char*)bobj + sizeof(struct B));
    *extraSpace = 1;

    if(*extraSpace == 1){
        printf("Struct Object is created successfully\n");
    }
    printf("bobj->a: %d, bobj->b: %d, extra int: %d\n", bobj->a, bobj->b, *extraSpace);
    
    free(bobj);
    extraSpace = NULL;
    return 0;
}
