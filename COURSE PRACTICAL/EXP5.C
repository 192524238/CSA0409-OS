#include <stdio.h>

int main()
{
    int n, i, j;
    int bt[10], p[10], wt[10], tat[10];
    int temp;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("\nProcess P%d\n", i + 1);

        printf("Enter Burst Time: ");
        scanf("%d", &bt[i]);

        printf("Enter Priority: ");
        scanf("%d", &p[i]);
    }

    // Sort according to priority
    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(p[i] > p[j])
            {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;

                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
            }
        }
    }

    wt[0] = 0;

    for(i = 1; i < n; i++)
        wt[i] = wt[i - 1] + bt[i - 1];

    for(i = 0; i < n; i++)
        tat[i] = wt[i] + bt[i];

    printf("\nPriority\tBT\tWT\tTAT\n");

    for(i = 0; i < n; i++)
        printf("%d\t\t%d\t%d\t%d\n", p[i], bt[i], wt[i], tat[i]);

    return 0;
}
