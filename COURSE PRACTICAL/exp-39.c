#include <stdio.h>
#include <pthread.h>

void *task(void *arg)
{
    printf("Thread is running\n");
    return NULL;
}

int main()
{
    pthread_t t;

    pthread_create(&t, NULL, task, NULL);

    pthread_join(t, NULL);

    printf("Main thread finished\n");

    return 0;
}
