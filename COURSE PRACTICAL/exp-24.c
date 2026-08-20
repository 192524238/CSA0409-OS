#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;
    char data[100];

    // Create and open file
    fd = open("file.txt", O_CREAT | O_RDWR, 0644);

    if(fd == -1)
    {
        printf("File cannot be opened.\n");
        return 1;
    }

    // Write into file
    write(fd, "Hello Operating System", 22);

    // Move file pointer to beginning
    lseek(fd, 0, SEEK_SET);

    // Read from file
    read(fd, data, 22);

    data[22] = '\0';

    printf("File content: %s\n", data);

    // Close file
    close(fd);

    return 0;
}
