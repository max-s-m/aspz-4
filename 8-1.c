#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(){
    //відкриття та задання розміру shared мапи
    //параметр 0666 визначає права доступу, та дозволяє по суті всім читати та записувати у файл
    int file_d = shm_open("/garbage", O_CREAT | O_RDWR, 0666);
    if(file_d == -1){
        printf("Didn't open\n");
        exit(1);
    }
    ftruncate(file_d, 100);
    //запис у пам'ять
    char *ptr = mmap(NULL, 100, PROT_READ | PROT_WRITE, MAP_SHARED, file_d, 0);
    strcpy(ptr, "Immovable object");
    printf("Wrote: %s\n", ptr);
    close(file_d);
}

