/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msindreu <msindreu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 18:16:46 by msindreu          #+#    #+#             */
/*   Updated: 2022/06/29 18:19:56 by msindreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;
	int	n;

	i = 0;
	if (!str)
	{
		n = write(1, "(null)", 6);
		if (n == -1)
			return (-1);
		else
			return (6);
	}
	else
	{
		while (str[i] != '\0')
		{
			n = write (1, (str + i), 1);
			if (n == -1)
				return (-1);
			i++;
		}
	}
	return (i);
}
