#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

void main()
{
    int fd = open("writefile.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0)
    {
        perror("File could not be opened");
        exit(1);
    }
    int count = write(fd, "Hello world", strlen("Hello World"));
    printf("\n1.Called write method to write Hello world\n");
    close(fd);
    char c;
    fd = open("writefile.txt", O_RDONLY, 0);
    read(fd, &c, 1);
    printf("\n2.Read the file\n\n");
    close(fd);
}