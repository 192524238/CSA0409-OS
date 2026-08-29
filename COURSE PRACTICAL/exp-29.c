#include <stdio.h>

int main()
{
    int indexBlock, n, i;
    int blocks[20];

    printf("Enter index block: ");
    scanf("%d", &indexBlock);

    printf("Enter number of file blocks: ");
    scanf("%d", &n);

    printf("Enter file block numbers:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &blocks[i]);
    }

    printf("\nIndex Block: %d\n", indexBlock);

    printf("File Blocks: ");
    for(i = 0; i < n; i++)
    {
        printf("%d ", blocks[i]);
    }

    printf("\n");

    return 0;
}
