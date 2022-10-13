/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msindreu <msindreu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 18:19:39 by msindreu          #+#    #+#             */
/*   Updated: 2022/10/13 16:44:49 by msindreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/ft_printf/lib/ft_printf.h"
#include "../lib/Libft/libft.h"
#include <unistd.h>
#include <signal.h>
#include <stdio.h>


/*typedef struct s_client{
	int	pid;



}	t_client;
*/
void	ft_handle(int sig, siginfo_t *info, void *context)
{
	static	pid_t	client_pid;
	
	client_pid = 0;
	(void)context;
	if (client_pid != info->si_pid && info->si_pid != 0)
		client_pid = info->si_pid;
	if (sig == SIGUSR1)
	{	printf("Senyal 1 rebuda.\n");
		printf("valor SIGUSR1:%d\n", sig);
	}
	if (sig == SIGUSR2)
		printf("Senyal2 rebuda.\n");
}

int	main()
{
	int	pid;
	struct	sigaction signal;
	pid = getpid();
	printf("PID: %d\n", pid);
	signal.sa_sigaction = ft_handle;
	signal.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &signal, NULL);
	sigaction(SIGUSR2, &signal, NULL);
	while (1)
		pause();
	return (0);
}
