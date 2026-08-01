#include <stdio.h>
#include <unistd.h>

int main()
{
    pid_t pid;

    pid = fork();   // Create a new process

    if (pid == 0)
    {
        // Child Process
        printf("Child Process\n");
        printf("Process ID (PID) : %d\n", getpid());
        printf("Parent Process ID (PPID) : %d\n", getppid());
    }
    else if (pid > 0)
    {
        // Parent Process
        printf("Parent Process\n");
        printf("Process ID (PID) : %d\n", getpid());
        printf("Parent Process ID (PPID) : %d\n", getppid());
    }
    else
    {
        printf("Process creation failed.\n");
    }

    return 0;
}
