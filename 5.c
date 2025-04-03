#include <stdio.h>
#include <stdlib.h>

int main(){
    //нормальний розмір
    void *ptr = malloc(10);
    if(!ptr){
        printf("Didn't allocate 10 bytes\n");
        exit(1);
    }
    printf("Allocated 10 bytes\nptr: %p\n", ptr);

    //невдале перевиділення нереальної кількості пам'яті
    size_t a_lot = (size_t)-1;
    void *ptr1 = realloc(ptr, a_lot);
    if(!ptr1){
        printf("Didn't realloc to ptr1\nptr: %p\n", ptr);
    }
    else{
        printf("Reallocated to ptr1: %p\n", ptr1);
        free(ptr1);
    }

    free(ptr);
}
