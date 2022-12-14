/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msindreu <msindreu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:31:24 by msindreu          #+#    #+#             */
/*   Updated: 2022/10/20 18:29:55 by msindreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/ft_printf/lib/ft_printf.h"
#include "../lib/Libft/libft.h"
#include <unistd.h>
#include <signal.h>
#include <stdio.h>

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
		if ((kill(pid, signal)) == -1)
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
		server_pid = ft_atoi(argv[1]);
		i = 0;
		while (argv[2][i] != '\0')
		{
			ft_get_and_send_bits(argv[2][i], server_pid);
			i++;
		}
		ft_get_and_send_bits('\0', server_pid);
	}
	return (0);
}
