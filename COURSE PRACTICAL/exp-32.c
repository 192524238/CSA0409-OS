#include <stdio.h>
#include <stdlib.h>

int main()
{
    int request[20], n, head, disk, direction;
    int i, j, temp, movement = 0;

    printf("Enter disk size: ");
    scanf("%d", &disk);

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter request queue:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &request[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter direction (1=Right, 0=Left): ");
    scanf("%d", &direction);

    /* Sort requests */
    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(request[i] > request[j])
            {
                temp = request[i];
                request[i] = request[j];
                request[j] = temp;
            }
        }
    }

    printf("\nSeek Sequence: %d", head);

    if(direction == 1)
    {
        /* Move right */
        for(i = 0; i < n; i++)
        {
            if(request[i] >= head)
            {
                movement += abs(head - request[i]);
                head = request[i];
                printf(" -> %d", head);
            }
        }

        /* Go to end */
        movement += abs(head - (disk - 1));
        head = disk - 1;
        printf(" -> %d", head);

        /* Move left */
        for(i = n - 1; i >= 0; i--)
        {
            if(request[i] < head)
            {
                movement += abs(head - request[i]);
                head = request[i];
                printf(" -> %d", head);
            }
        }
    }
    else
    {
        /* Move left */
        for(i = n - 1; i >= 0; i--)
        {
            if(request[i] <= head)
            {
                movement += abs(head - request[i]);
                head = request[i];
                printf(" -> %d", head);
            }
        }

        /* Go to beginning */
        movement += head;
        head = 0;
        printf(" -> %d", head);

        /* Move right */
        for(i = 0; i < n; i++)
        {
            if(request[i] > head)
            {
                movement += abs(head - request[i]);
                head = request[i];
                printf(" -> %d", head);
            }
        }
    }

    printf("\nTotal Head Movement = %d\n", movement);

    return 0;
}
