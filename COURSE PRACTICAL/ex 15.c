#include <stdio.h>
#include <string.h>

char users[10][20];
char files[10][10][20];
int fileCount[10] = {0};
int userCount = 0;

int main()
{
    int choice, i, j;
    char username[20], filename[20];

    while(1)
    {
        printf("\n--- TWO LEVEL DIRECTORY ---\n");
        printf("1. Create User\n");
        printf("2. Create File\n");
        printf("3. Display Files\n");
        printf("4. Search File\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        if(choice == 1)
        {
            printf("Enter user name: ");
            scanf("%s", username);

            strcpy(users[userCount], username);
            userCount++;

            printf("User created successfully.\n");
        }

        else if(choice == 2)
        {
            printf("Enter user name: ");
            scanf("%s", username);

            for(i = 0; i < userCount; i++)
            {
                if(strcmp(users[i], username) == 0)
                {
                    printf("Enter file name: ");
                    scanf("%s", filename);

                    strcpy(files[i][fileCount[i]], filename);
                    fileCount[i]++;

                    printf("File created successfully.\n");
                    break;
                }
            }

            if(i == userCount)
                printf("User not found.\n");
        }

        else if(choice == 3)
        {
            printf("\n--- Directory ---\n");

            for(i = 0; i < userCount; i++)
            {
                printf("\nUser: %s\n", users[i]);

                for(j = 0; j < fileCount[i]; j++)
                {
                    printf("  %s\n", files[i][j]);
                }
            }
        }

        else if(choice == 4)
        {
            printf("Enter user name: ");
            scanf("%s", username);

            printf("Enter file name: ");
            scanf("%s", filename);

            for(i = 0; i < userCount; i++)
            {
                if(strcmp(users[i], username) == 0)
                {
                    for(j = 0; j < fileCount[i]; j++)
                    {
                        if(strcmp(files[i][j], filename) == 0)
                        {
                            printf("File found.\n");
                            break;
                        }
                    }

                    if(j == fileCount[i])
                        printf("File not found.\n");

                    break;
                }
            }
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
