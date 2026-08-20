#include <stdio.h>

int main()
{
    int block[10], process[10];
    int nb, np;
    int i, j, best;

    printf("Enter number of memory blocks: ");
    scanf("%d", &nb);

    printf("Enter size of each block:\n");
    for(i = 0; i < nb; i++)
    {
        scanf("%d", &block[i]);
    }

    printf("Enter number of processes: ");
    scanf("%d", &np);

    printf("Enter size of each process:\n");
    for(i = 0; i < np; i++)
    {
        scanf("%d", &process[i]);
    }

    printf("\nProcess\tSize\tBlock\n");

    for(i = 0; i < np; i++)
    {
        best = -1;

        for(j = 0; j < nb; j++)
        {
            if(block[j] >= process[i])
            {
                if(best == -1 || block[j] < block[best])
                {
                    best = j;
                }
            }
        }

        if(best != -1)
        {
            printf("P%d\t%d\tB%d\n",
                   i + 1, process[i], best + 1);

            block[best] = block[best] - process[i];
        }
        else
        {
            printf("P%d\t%d\tNot Allocated\n",
                   i + 1, process[i]);
        }
    }

    return 0;
}
