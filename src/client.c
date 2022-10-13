/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msindreu <msindreu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:31:24 by msindreu          #+#    #+#             */
/*   Updated: 2022/10/13 17:10:31 by msindreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/ft_printf/lib/ft_printf.h"
#include "../lib/Libft/libft.h"
#include <unistd.h>
#include <signal.h>
#include <stdio.h>

int	ft_get_and_send_bits(char c, int pid)
{
	int		i;








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



}

