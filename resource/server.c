#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void new_signal_handler(int sig)
{
    static int received_bit_count = 0;
    static char received_char = 0;

    if (sig == SIGUSR1 || sig == SIGUSR2)
    {
        received_char |= (sig == SIGUSR2) << (7 - received_bit_count);
        received_bit_count++;
        if (received_bit_count == 8)
        {
            if (received_char == '\0')
            {
                fflush(stdout);
                write(1, "\n", 1);
                received_bit_count = 0;
                received_char = 0;
            }
            else
            {
                printf("%c", received_char);
                received_bit_count = 0;
                received_char = 0;
            }
        }
    }
}

int main(void)
{
    struct sigaction sa;

    sa.sa_handler = new_signal_handler;
    sa.sa_flags = 0;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    printf("Server PID: %d\n", getpid());
    while (1)
    {
        usleep(100000);
    }
    return (0);
}

