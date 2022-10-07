/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msindreu <msindreu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 18:19:39 by msindreu          #+#    #+#             */
/*   Updated: 2022/10/07 17:53:26 by msindreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdio.h>

void	ft_handle(int	sig)//, siginfo_t *info, void *context)
{
	static pid_t 


	(void)context;
	(void)sig;
	if (sig == SIGUSR1)
		printf("Senyal 1 rebuda");
	if (sig == SIGUSR2)
		printf("Senyal2 rebuda");
}

int	main()
{
	int	pid;
	struct	sigaction signal;
	pid = getpid();
	printf("PID: %d\n", pid);
	signal.sa_sigaction = ft_handle;
	//signal.sa_handler = ft_handle;
	sigemptyset(sigset_t *set);
//	sigfillset(&signal.sa_mask);
	signal.sa_flags = 0;
	sigaction(SIGUSR1, &signal, NULL);
	sigaction(SIGUSR2, &signal, NULL);
	while (1)
		pause();
	return (0);
}
