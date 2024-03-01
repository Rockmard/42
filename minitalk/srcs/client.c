/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:30:19 by tpipi             #+#    #+#             */
/*   Updated: 2024/02/27 15:08:47 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <limits.h>
#include <signal.h>

int	g_signal_received = 0;

unsigned int	ft_atoui(const char *msg, unsigned int *nb)
{
	int	i;

	i = 0;
	(*nb) = 0;
	while (msg[i])
	{
		if (!(msg[i] >= '0' && msg[i] <= '9') || (*nb) > INT_MAX)
			return (1);
		(*nb) = (*nb) * 10 + msg[i] - '0';
		i++;
	}
	return (0);
}

void	sighandler(int sigtype)
{
	if (sigtype == SIGUSR2)
		g_signal_received = 1;
}

int	send_bit(pid_t pid, char character)
{
	int	nth_bit;
	int	timeout;

	nth_bit = 0;
	timeout = 0;
	while (nth_bit < 8)
	{
		g_signal_received = 0;
		if ((character & 1))
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		nth_bit++;
		character >>= 1;
		while (!g_signal_received)
		{
			timeout++;
			if (timeout == 10)
				return (1);
			sleep(1);
		}
	}
	return (0);
}

int	main(int ac, char **av)
{
	unsigned int	pid;
	int				i;

	if (ac != 3)
	{
		ft_printf("Error\nToo may or not enough parameters.\n" \
		"The programm works like this : ./client (server PID) (string)\n");
		return (1);
	}
	if (ft_atoui(av[1], &pid) || (pid_t)pid == getpid() || pid == 0)
	{
		ft_printf("Error\nPID isn't valid\n");
		return (1);
	}
	i = 0;
	signal(SIGUSR2, sighandler);
	while (av[2][i])
	{
		if (send_bit((pid_t)pid, av[2][i++]))
		{
			ft_printf("Error\nCouldn't send the signal.\n");
			return (1);
		}
	}
	return (0);
}
