#include <stdio.h>

int main()
{
    FILE *fp;
    char data[100];

    /* Create and write to file */
    fp = fopen("sample.txt", "w");

    if(fp == NULL)
    {
        printf("File cannot be opened.\n");
        return 1;
    }

    printf("Enter text: ");
    scanf(" %[^\n]", data);

    fprintf(fp, "%s", data);

    fclose(fp);

    printf("File created and data written successfully.\n");

    /* Open file for reading */
    fp = fopen("sample.txt", "r");

    if(fp == NULL)
    {
        printf("File cannot be opened.\n");
        return 1;
    }

    fscanf(fp, " %[^\n]", data);

    printf("File content: %s\n", data);

    fclose(fp);

    return 0;
}
