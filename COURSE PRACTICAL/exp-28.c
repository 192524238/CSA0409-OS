#include <stdio.h>

int main()
{
    int n, start, length, i;
    int disk[100] = {0};

    printf("Enter number of disk blocks: ");
    scanf("%d", &n);

    printf("Enter starting block: ");
    scanf("%d", &start);

    printf("Enter number of blocks required: ");
    scanf("%d", &length);

    // Check whether blocks are available
    for(i = start; i < start + length; i++)
    {
        if(i >= n || disk[i] == 1)
        {
            printf("File cannot be allocated.\n");
            return 0;
        }
    }

    // Allocate blocks
    for(i = start; i < start + length; i++)
    {
        disk[i] = 1;
    }

    printf("\nFile allocated successfully.\n");
    printf("Allocated blocks: ");

    for(i = start; i < start + length; i++)
    {
        printf("%d ", i);
    }

    printf("\n");

    return 0;
}
