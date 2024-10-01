#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

int main() {
    const char *filename = "test.txt";

    
    int fd = open(filename, O_RDWR);
    if (fd == -1) {
        perror("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);
    }

   
    struct stat file_stat;
    if (fstat(fd, &file_stat) == -1) {
        perror("Erreur lors de la récupération des informations du fichier");
        close(fd);
        exit(EXIT_FAILURE);
    }
    size_t file_size = file_stat.st_size;
    
    
    char *file_content = mmap(NULL, file_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (file_content == MAP_FAILED) {
        perror("Erreur lors du mapping du fichier");
        close(fd);
        exit(EXIT_FAILURE);
    }

    
    for (size_t i = 0; i < file_size / 2; i++) {
        char temp = file_content[i];
        file_content[i] = file_content[file_size - 1 - i];
        file_content[file_size - 1 - i] = temp;
    }

    
    if (munmap(file_content, file_size) == -1) {
        perror("Erreur lors du unmapping du fichier");
    }

    
    close(fd);

    
    printf("Vérifiez le contenu du fichier en utilisant la commande : cat %s\n", filename);

    return 0;
}

