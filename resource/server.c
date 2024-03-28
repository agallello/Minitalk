/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 10:30:26 by marvin            #+#    #+#             */
/*   Updated: 2024/03/28 10:30:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

volatile sig_atomic_t g_received_char = 0;

void sigusr_handler(int signum)
{
    if (signum == SIGUSR1)
        g_received_char <<= 1;
    else if (signum == SIGUSR2)
        g_received_char = (g_received_char << 1) | 1;
}

int main()
{
    struct sigaction sa;
    sa.sa_handler = sigusr_handler;
    sa.sa_flags = SA_RESTART;
    sigemptyset(&sa.sa_mask);

    if (sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa, NULL) == -1)
    {
        perror("Error setting up signal handler");
        return 1;
    }

    printf("Server PID: %d\n", getpid());

    while (1)
    {
        pause();
        putchar(g_received_char);
        fflush(stdout);
    }

    return 0;
}
