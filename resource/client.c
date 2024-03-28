/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 10:30:07 by marvin            #+#    #+#             */
/*   Updated: 2024/03/28 10:30:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void send_bit(int pid, char c, int bit_index)
{
    if (bit_index < 0) return;

    if ((c >> bit_index) & 1)
        kill(pid, SIGUSR2);
    else
        kill(pid, SIGUSR1);

    usleep(10000);
    send_bit(pid, c, bit_index - 1);
}

void send_char(int pid, char c)
{
    send_bit(pid, c, 7);
}

int main(int argc, char *argv[])
{
    if (argc != 3) {
        printf("Usage: %s [PID] [STRING]\n", argv[0]);
        return 1;
    }

    int server_pid = atoi(argv[1]);
    char *message = argv[2];

    while (*message) {
        send_char(server_pid, *message++);
    }

    return 0;
}
