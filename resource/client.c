
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void my_send_char(int server_pid, char i)
{
    int bit;

    bit = 128;
    while (bit > 0)
    {
        if (i & bit)
            kill(server_pid, SIGUSR2);
        else
            kill(server_pid, SIGUSR1);
        bit /= 2;
        usleep(100);
    }
}

void my_send_str(int server_pid, char *str)
{
    while (*str)
    {
        my_send_char(server_pid, *str);
        str++;
    }
    my_send_char(server_pid, '\0');
}

int main(int argc, char *argv[])
{
    int server_pid;

    if (argc != 3)
    {
        printf("Usage: %s <server_pid> <string>\n", argv[0]);
        return (1);
    }
    server_pid = atoi(argv[1]);
    my_send_str(server_pid, argv[2]);
    return (0);
}
