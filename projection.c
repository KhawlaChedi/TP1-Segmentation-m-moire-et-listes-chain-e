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
        perror("Error opening the file");
        exit(EXIT_FAILURE);
    }


    struct stat file_stat;
    if (fstat(fd, &file_stat) == -1) {
        perror("Error getting file information");
        close(fd);
        exit(EXIT_FAILURE);
    }
    size_t file_size = file_stat.st_size;
    

    char *file_content = mmap(NULL, file_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (file_content == MAP_FAILED) {
        perror("Error mapping the file");
        close(fd);
        exit(EXIT_FAILURE);
    }


    for (size_t i = 0; i < file_size / 2; i++) {
        char temp = file_content[i];
        file_content[i] = file_content[file_size - 1 - i];
        file_content[file_size - 1 - i] = temp;
    }


    if (munmap(file_content, file_size) == -1) {
        perror("Error unmapping the file");
    }


    close(fd);


    printf("Check the file content using the command: cat %s\n", filename);

    return 0;
}

