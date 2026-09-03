#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;
    char buffer[100];
    int n;

    // Open file
    fd = open("sample.txt", O_CREAT | O_RDWR, 0644);

    if (fd < 0)
    {
        printf("File cannot be opened\n");
        return 1;
    }

    printf("File opened successfully\n");

    // Write into file
    write(fd, "Hello UNIX I/O System Calls\n", 27);

    // Move file pointer to beginning
    lseek(fd, 0, SEEK_SET);

    // Read from file
    n = read(fd, buffer, sizeof(buffer) - 1);

    buffer[n] = '\0';

    printf("Data read from file:\n%s", buffer);

    // Close file
    close(fd);

    printf("\nFile closed successfully\n");

    return 0;
}
