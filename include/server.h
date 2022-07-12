/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   server.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/02 15:40:54 by cpost         #+#    #+#                 */
/*   Updated: 2022/03/31 17:10:11 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <signal.h>

void	handler(int sig, siginfo_t *info, void *context);
int		main(void);

#endif