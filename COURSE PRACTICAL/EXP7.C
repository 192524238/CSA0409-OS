#include <stdio.h>

int main()
{
    int n, i, j, temp;
    int bt[10], wt[10], tat[10];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Input Burst Time
    for(i = 0; i < n; i++)
    {
        printf("Enter Burst Time for P%d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    // Sort Burst Time in ascending order
    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(bt[i] > bt[j])
            {
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
            }
        }
    }

    // Calculate Waiting Time
    wt[0] = 0;
    for(i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1];
    }

    // Calculate Turnaround Time
    for(i = 0; i < n; i++)
    {
        tat[i] = wt[i] + bt[i];
    }

    // Display Output
    printf("\nBurst Time\tWaiting Time\tTurnaround Time\n");

    for(i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t%d\n", bt[i], wt[i], tat[i]);
    }

    return 0;
}
