#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/wait.h>

#define STRING "Hello, World!" 

int global_initialized = 42;
int global_uninitialized;

int main (){

    printf("Memory segment addresses:\n");

    printf("Initialized global data (Data) : %p\n", &global_initialized);
    printf("Uninitialized global data (BSS) : %p\n", &global_uninitialized);

    printf("String literal (Str) : %p\n", STRING);
    
    int *heap_var = (int *)malloc(sizeof(int));
    printf("Dynamically allocated data (Heap) : %p\n", heap_var);

    int stack_variable = 123;
    printf("Locally scoped data (Stack) : %p\n", &stack_variable);
    
    printf("Code memory area (Main Function) : %p\n", &main);

    printf("Shared library memory area (LibC Function) : %p\n", &printf);

    size_t length = 4096; 
    void* mmap_addr = mmap(NULL, length, PROT_READ | PROT_WRITE,
                            MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
    if (mmap_addr == MAP_FAILED) {
        perror("mmap");
    } else {
        printf("mmap address: %p\n", mmap_addr);
    }

    pid_t parent_pid = getpid();
    printf("Parent process PID : %d\n", parent_pid);

    pid_t pid = fork(); 
    if (pid == 0) {
        char pid_str[10];
        snprintf(pid_str, sizeof(pid_str), "%d", parent_pid);
        execlp("pmap", "pmap", "-X", pid_str, (char *)NULL);
        
        perror("execlp");
        exit(EXIT_FAILURE);
        
    } else if (pid > 0) {
        wait(NULL); 
    } else {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    free(heap_var);
    if (mmap_addr != MAP_FAILED) {
        munmap(mmap_addr, length);
    }

    return 0;
}

