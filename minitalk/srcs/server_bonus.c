/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:30:13 by tpipi             #+#    #+#             */
/*   Updated: 2024/02/27 15:22:34 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <signal.h>

void	sighandler(int sigtype, siginfo_t *info, void *context)
{
	static int	i = 0;
	static int	nb = 0;

	(void)context;
	if (sigtype == SIGUSR2)
		nb |= 1 << i;
	i++;
	if (i == 8)
	{
		i = 0;
		ft_printf("%c", nb);
		nb = 0;
	}
	kill(info->si_pid, SIGUSR2);
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	action;

	pid = getpid();
	ft_printf("--------BONUS--------\n");
	ft_printf(">>> My PID : %d\n", pid);
	ft_printf("---------------------\n");
	action.sa_sigaction = sighandler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
		pause();
	return (0);
}
