#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/wait.h>

#define CHAINE "Hello, World!" 

int global_initialized = 42;
int global_uninitialized;

int main (){

printf("Adresse des segments mémoire :\n");

printf("Données globales initialisées (Data) : %p\n", &global_initialized);
printf("Données globales non initialisées (BSS) : %p\n", &global_uninitialized);

printf("Chaîne de caractères (Str) : %p\n", CHAINE);
 
int *heap_var = (int *)malloc (sizeof(int));
printf("Données allouées dynamiquement (Heap) : %p\n", heap_var);

int stack_variable = 123;
printf("Données à portée limitée (Stack) : %p\n", &stack_variable);
 
printf("Zone mémoire code (Main Function) : %p\n", &main);

printf("Zone mémoire librairie partagée (LibC Function) : %p\n", &printf);


size_t length = 4096; 
void* mmap_addr = mmap(NULL, length, PROT_READ | PROT_WRITE,
                           MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
if (mmap_addr == MAP_FAILED) {
        perror("mmap");
} else {
        printf("Adresse mmap: %p\n", mmap_addr);
}

pid_t parent_pid = getpid();
printf("PID du processus parent : %d\n", parent_pid);

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
