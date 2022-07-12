/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   client.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/02 10:23:12 by cpost         #+#    #+#                 */
/*   Updated: 2022/07/12 12:03:01 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include "client.h"

static int	g_resume = 0;

void	handle_signal_client(int sig)
{
	if (sig == SIGUSR1)
		g_resume = 1;
}

void	ft_send_bits(struct s_args *arg)
{
	unsigned int	bit;
	int				shift;
	int				i;

	i = 0;
	while (arg->str[i])
	{
	shift = 7;
		while (shift >= 0)
		{
			g_resume = 0;
			bit = (arg->str[i] >> shift) & 1;
			if (bit == 1)
				kill(arg->pid, SIGUSR1);
			if (bit == 0)
				kill(arg->pid, SIGUSR2);
			shift--;
			while (g_resume == 0)
				;
		}
	i++;
	}
}

int	main(int argc, char **argv)
{
	struct s_args	arg;
	int				i;

	i = 0;
	signal(SIGUSR1, handle_signal_client);
	if (argc != 3)
		return (0);
	while (argv[1][i])
	{
		if (!(argv[1][i] >= '0' && argv[1][i] <= '9'))
			return (0);
		i++;
	}
	arg.pid = ft_atoi(argv[1]);
	arg.str = argv[2];
	ft_send_bits(&arg);
	return (0);
}
