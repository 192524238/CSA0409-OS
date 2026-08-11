#include <stdio.h>
#include <string.h>

int main()
{
    char files[20][20];
    int n = 0;
    int choice, i;
    char name[20];

    while(1)
    {
        printf("\n--- SINGLE LEVEL DIRECTORY ---\n");
        printf("1. Create File\n");
        printf("2. Display Files\n");
        printf("3. Search File\n");
        printf("4. Delete File\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        if(choice == 1)
        {
            printf("Enter file name: ");
            scanf("%s", name);

            strcpy(files[n], name);
            n++;

            printf("File created successfully.\n");
        }

        else if(choice == 2)
        {
            printf("\nFiles in Directory:\n");

            for(i = 0; i < n; i++)
            {
                printf("%s\n", files[i]);
            }
        }

        else if(choice == 3)
        {
            printf("Enter file name to search: ");
            scanf("%s", name);

            for(i = 0; i < n; i++)
            {
                if(strcmp(files[i], name) == 0)
                {
                    printf("File found.\n");
                    break;
                }
            }

            if(i == n)
                printf("File not found.\n");
        }

        else if(choice == 4)
        {
            printf("Enter file name to delete: ");
            scanf("%s", name);

            for(i = 0; i < n; i++)
            {
                if(strcmp(files[i], name) == 0)
                {
                    for(; i < n - 1; i++)
                        strcpy(files[i], files[i + 1]);

                    n--;

                    printf("File deleted successfully.\n");
                    break;
                }
            }

            if(i == n)
                printf("File not found.\n");
        }

        else if(choice == 5)
        {
            printf("Exiting...\n");
            break;
        }

        else
        {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
