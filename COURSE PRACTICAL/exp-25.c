#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>

int main()
{
    int fd;
    char data[50];
    struct stat st;
    DIR *dir;
    struct dirent *entry;

    /* Open file */
    fd = open("test.txt", O_CREAT | O_RDWR, 0644);

    if(fd == -1)
    {
        printf("File cannot be opened\n");
        return 1;
    }

    /* Write data */
    write(fd, "Hello Operating System", 22);

    /* lseek - move file pointer to beginning */
    lseek(fd, 0, SEEK_SET);

    /* Read data */
    read(fd, data, 22);
    data[22] = '\0';

    printf("File content: %s\n", data);

    /* fcntl - get file flags */
    printf("File descriptor: %d\n", fd);
    printf("File flags: %d\n", fcntl(fd, F_GETFL));

    /* stat - get file information */
    stat("test.txt", &st);

    printf("File size: %ld bytes\n", st.st_size);

    /* opendir - open current directory */
    dir = opendir(".");

    if(dir == NULL)
    {
        printf("Directory cannot be opened\n");
        close(fd);
        return 1;
    }

    /* readdir - display files */
    printf("\nFiles in current directory:\n");

    while((entry = readdir(dir)) != NULL)
    {
        printf("%s\n", entry->d_name);
    }

    closedir(dir);
    close(fd);

    return 0;
}
