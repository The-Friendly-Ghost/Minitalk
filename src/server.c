/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   server.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/02 15:39:37 by cpost         #+#    #+#                 */
/*   Updated: 2022/04/01 12:35:16 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include "libft.h"
#include <unistd.h>
#include <signal.h>

void	handler(int sig, siginfo_t *info, void *ucontext)
{
	static unsigned int	character;
	static int			count;

	(void)ucontext;
	character <<= 1;
	if (sig == SIGUSR1)
		character += 1;
	count++;
	if (count == 8)
	{
		write(1, &character, 1);
		character = 0;
		count = 0;
		kill(info->si_pid, SIGUSR1);
	}
	else
		kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	int					pid_t;
	struct sigaction	sa;

	pid_t = getpid();
	write(1, "PID: ", 5);
	ft_putnbr_fd(pid_t, 1);
	write(1, "\n", 1);
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO | SA_NODEFER;
	sa.sa_handler = SIG_DFL;
	sa.sa_sigaction = handler;
	if (sigaction(SIGUSR1, &sa, NULL) != 0)
		write(1, "Error", 5);
	if (sigaction(SIGUSR2, &sa, NULL) != 0)
		write(1, "Error", 5);
	while (1)
		pause();
	return (0);
}
