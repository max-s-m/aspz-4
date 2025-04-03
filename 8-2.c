#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
    //відкриття пам'яті
    //параметр 0666 визначає права доступу, та дозволяє по суті всім читати та записувати у файл
    int file_d = shm_open("/garbage", O_RDONLY, 0666);
    if(file_d == -1){
        printf("Nothing to read\n");
        exit(1);
    }
    //відображення вмісту
    char *ptr = mmap(NULL, 100, PROT_READ, MAP_SHARED, file_d, 0);
    printf("Read: %s\n", ptr);
    close(file_d);
    //від'єднання shared мапи, тобто очищення пам'яті
    if(shm_unlink("/garbage") == -1){
        printf("Didn't unlink\n");
        exit(1);
    }
    printf("Shared map is no more\n");
}

