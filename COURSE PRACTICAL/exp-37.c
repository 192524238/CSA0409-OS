#include <stdio.h>
#include <string.h>

int main()
{
    FILE *fp;
    char word[50], line[200];

    printf("Enter the word to search: ");
    scanf("%s", word);

    fp = fopen("sample.txt", "r");

    if (fp == NULL)
    {
        printf("File cannot be opened\n");
        return 1;
    }

    printf("\nLines containing '%s':\n", word);

    while (fgets(line, sizeof(line), fp) != NULL)
    {
        if (strstr(line, word) != NULL)
        {
            printf("%s", line);
        }
    }

    fclose(fp);

    return 0;
}
