/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   client.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/02 10:25:45 by cpost         #+#    #+#                 */
/*   Updated: 2022/03/31 17:24:49 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

struct s_args
{
	int		pid;
	char	*str;
};

int			ft_atoi(const char *nptr);
int			main(int argc, char **argv);
void		ft_send_bits(struct s_args *arg);
void		handle_signal_client(int sig);

#endif