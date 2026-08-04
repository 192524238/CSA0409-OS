#include <stdio.h>
#include <pthread.h>

void *display(void *arg)
{
    printf("Hello from Thread!\n");
    return NULL;
}

int main()
{
    pthread_t t1;

    // Create a thread
    pthread_create(&t1, NULL, display, NULL);

    // Wait for thread to finish
    pthread_join(t1, NULL);

    printf("Main Thread Finished.\n");

    return 0;
}
