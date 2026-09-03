#include <stdio.h>
#include <sys/stat.h>

int main()
{
    char filename[] = "sample.txt";

    // Create file
    FILE *fp = fopen(filename, "w");

    if (fp == NULL)
    {
        printf("File creation failed\n");
        return 1;
    }

    fprintf(fp, "Hello Linux\n");
    fclose(fp);

    // Change file permissions to 755
    chmod(filename, 0755);

    printf("File created successfully\n");
    printf("File permission changed to 755\n");

    return 0;
}
