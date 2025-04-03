#include <stdio.h>
#include <stdlib.h>

struct sbar{int a; int b;};

int main(){
    struct sbar *ptr, *newptr;
    //масив на 1000 елементів
    ptr = calloc(1000, sizeof(struct sbar));
    if(!ptr){
        printf("Didn't calloc\n");
        exit(1);
    }
    printf("Callocated ptr: %p\n", ptr);

    //масив зменшується до 500
    newptr = reallocarray(ptr, 500, sizeof(struct sbar));
    if(!newptr){
        printf("Didn't reallocarray\n");
        free(ptr);
        exit(1);
    }
    printf("Reallocarray'd newptr: %p\n", newptr);
    free(newptr);
}

