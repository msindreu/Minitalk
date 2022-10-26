/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msindreu <msindreu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:31:24 by msindreu          #+#    #+#             */
/*   Updated: 2022/10/26 11:15:17 by msindreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/ft_printf/lib/ft_printf.h"
#include "../lib/Libft/libft.h"
#include <unistd.h>
#include <signal.h>
#include <stdio.h>

void	ft_handle(int sig)
{
	static int	bits = 0;

	if (sig == SIGUSR2)
	{	
		if (ft_printf("\r\e[1;34mSending [%d] bits\e[0m", bits) == -1)
			exit(-1);
		bits++;
	}
	if (sig == SIGUSR1)
	{
		if (ft_printf("\r\e[1;34mMessage finished at [%d] bits\e[0m", bits) == -1)
			exit(-1);
		exit(EXIT_SUCCESS);
	}
}

void	ft_get_and_send_bits(char c, int pid)
{
	int		i;
	int		signal;

	i = 0;
	while (i < 8)
	{
		if (c << i & 128)
			signal = SIGUSR1;
		else
			signal = SIGUSR2;
		usleep(200);
		if (kill(pid, signal) == -1)
			exit (-1);
		usleep(300);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	server_pid;
	int	i;

	if (argc == 3)
	{
		signal(SIGUSR1, ft_handle);
		signal(SIGUSR2, ft_handle);
		server_pid = ft_atoi(argv[1]);
		i = 0;
		while (argv[2][i] != '\0')
		{
			ft_get_and_send_bits(argv[2][i], server_pid);
			i++;
		}
		ft_get_and_send_bits('\0', server_pid);
	}
	while (1)
		pause();
	return (0);
}
