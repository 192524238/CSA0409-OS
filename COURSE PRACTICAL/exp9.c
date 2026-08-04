#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

int main()
{
    int shmid;
    char *str;

    // Create shared memory
    shmid = shmget(1234, 1024, 0666 | IPC_CREAT);

    // Attach shared memory
    str = (char *)shmat(shmid, NULL, 0);

    // Write data into shared memory
    strcpy(str, "Hello Shared Memory");

    printf("Data written in shared memory: %s\n", str);

    // Detach shared memory
    shmdt(str);

    return 0;
}
