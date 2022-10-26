/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msindreu <msindreu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 15:36:45 by msindreu          #+#    #+#             */
/*   Updated: 2022/05/21 19:49:32 by msindreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	j;
	int	n;

	j = 0;
	n = 1;
	i = 0;
	while (str[j] == '\t' || str[j] == '\r'
		|| str[j] == '\n' || str[j] == '\f'
		|| str[j] == '\v' || str[j] == ' ')
		j++;
	if (str[j] == '+' || str[j] == '-')
	{
		if (str[j] == '-')
			n = -n;
		j++;
	}
	while (str[j] >= 48 && str[j] <= 57)
	{
		i = ((i * 10) + (str[j] - 48));
		j++;
	}
	return (i * n);
}
