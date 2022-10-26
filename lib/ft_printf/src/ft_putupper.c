/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msindreu <msindreu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 19:33:02 by msindreu          #+#    #+#             */
/*   Updated: 2022/06/29 17:37:53 by msindreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/ft_printf.h"

int	ft_putupper(unsigned int n)
{
	int	len;

	len = 0;
	if (n >= 16)
		return (ft_protect(n, 16, ft_putupper));
	else
	{
		if (n < 10)
		{
			if (ft_putchar(n + 48) == -1)
				return (-1);
		}
		else
		{
			if (ft_putchar(n + 55) == -1)
				return (-1);
		}
		len++;
	}
	return (len);
}
