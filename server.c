/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msindreu <msindreu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 18:19:39 by msindreu          #+#    #+#             */
/*   Updated: 2022/10/04 18:47:49 by msindreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdio.h>

static void	ft_handle(int	sig, siginfo_t *info, void *contect)
{




}




int	main()
{
	int	pid;
	struct	sigaction signal;
	pid = getpid();
	printf("PID: %d\n", pid);
	signal.sa_sigaction = ft_handle;
	sigfillset(&signal.sa_mask);
	signal.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &signal, NULL);
	sigaction(SIGUSR2, &signal, NULL);
	while (1)
		pause();
	return (0);
}
