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

int	ft_putnbr(unsigned int n)
{
	int	i;
	int	len;

	i = n;
	len = 0;
	if (i < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		i = -i;
		n = -n;
		len++;
	}
	if (n < 10)
	{
		if (ft_putchar(48 + i) == -1)
			return (-1);
		len++;
	}
	else
		return (len + ft_protect(n, 10, ft_putnbr));
	return (len);
}
