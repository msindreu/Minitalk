/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msindreu <msindreu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 18:19:39 by msindreu          #+#    #+#             */
/*   Updated: 2022/10/20 18:29:58 by msindreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/ft_printf/lib/ft_printf.h"
#include "../lib/Libft/libft.h"
#include <unistd.h>
#include <signal.h>
#include <stdio.h>

int		g_byte;

void	ft_handle(int sig, siginfo_t *info, void *context)
{
	static unsigned char	c;

	(void)context;
	(void)info;
	if (sig == SIGUSR1)
		c = c | 1;
	g_byte++;
	if (g_byte == 8)
	{
		if ((write(1, &c, 1)) == -1)
			exit (-1);
		g_byte = 0;
	}
	c = c << 1;
}

int	main(void)
{
	int					pid;
	struct sigaction	signal;

	pid = getpid();
	g_byte = 0;
	printf("PID: %d\n", pid);
	signal.sa_sigaction = ft_handle;
	signal.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &signal, NULL);
	sigaction(SIGUSR2, &signal, NULL);
	while (1)
		pause();
	return (0);
}
