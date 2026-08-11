#include <stdio.h>

struct Employee
{
    int id;
    char name[20];
    float salary;
};

int main()
{
    FILE *fp;
    struct Employee e;
    int n, i, pos;

    fp = fopen("employee.dat", "w+");

    if(fp == NULL)
    {
        printf("File cannot be opened.\n");
        return 1;
    }

    printf("Enter number of employees: ");
    scanf("%d", &n);

    // Store employee details
    for(i = 0; i < n; i++)
    {
        printf("\nEnter Employee ID: ");
        scanf("%d", &e.id);

        printf("Enter Name: ");
        scanf("%s", e.name);

        printf("Enter Salary: ");
        scanf("%f", &e.salary);

        fwrite(&e, sizeof(e), 1, fp);
    }

    // Random access
    printf("\nEnter employee number to display: ");
    scanf("%d", &pos);

    fseek(fp, (pos - 1) * sizeof(e), SEEK_SET);

    fread(&e, sizeof(e), 1, fp);

    printf("\nEmployee Details\n");
    printf("ID     : %d\n", e.id);
    printf("Name   : %s\n", e.name);
    printf("Salary : %.2f\n", e.salary);

    fclose(fp);

    return 0;
}
