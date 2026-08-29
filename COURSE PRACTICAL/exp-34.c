#include <stdio.h>

int main()
{
    FILE *fp;
    char data[100];

    // Create a file
    fp = fopen("file.txt", "w");

    if(fp == NULL)
    {
        printf("File cannot be opened\n");
        return 1;
    }

    // Write data
    printf("Enter data: ");
    scanf(" %[^\n]", data);

    fprintf(fp, "%s", data);
    fclose(fp);

    printf("File created successfully.\n");

    // Open file for reading
    fp = fopen("file.txt", "r");

    if(fp == NULL)
    {
        printf("File cannot be opened\n");
        return 1;
    }

    // Read data
    fscanf(fp, " %[^\n]", data);

    printf("File content: %s\n", data);

    // Close file
    fclose(fp);

    return 0;
}
