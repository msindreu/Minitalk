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

int	ft_putui(unsigned int u)
{
	int	len;

	len = 0;
	if (u < 10)
	{
		if (ft_putchar(48 + u) == -1)
			return (-1);
		len++;
	}
	else
	{
		return (ft_protect(u, 10, ft_putui));
	}
	return (len);
}
