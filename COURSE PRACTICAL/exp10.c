#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct message
{
    long type;
    char text[100];
};

int main()
{
    int msgid;
    struct message msg;

    // Create message queue
    msgid = msgget(1234, 0666 | IPC_CREAT);

    // Message to send
    msg.type = 1;
    strcpy(msg.text, "Hello Message Queue");

    // Send message
    msgsnd(msgid, &msg, sizeof(msg.text), 0);

    // Receive message
    msgrcv(msgid, &msg, sizeof(msg.text), 1, 0);

    printf("Message Received: %s\n", msg.text);

    return 0;
}
