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

int	ft_check(va_list argument, char type)
{
	if (type == 'c')
		return (ft_putchar(va_arg(argument, int)));
	else if (type == 's')
		return (ft_putstr(va_arg(argument, char *)));
	else if (type == 'p')
	{
		if (write(1, "0x", 2) == -1)
			return (-1);
		return (ft_putpointer(va_arg(argument, unsigned long)) + 2);
	}
	else if (type == 'd' || type == 'i')
	{
		return (ft_putnbr(va_arg(argument, int)));
	}	
	else if (type == 'u')
	{
		return (ft_putui(va_arg(argument, unsigned int)));
	}
	else if (type == 'x')
		return (ft_putlower(va_arg(argument, unsigned long)));
	else if (type == 'X')
		return (ft_putupper(va_arg(argument, unsigned long)));
	else if (type == '%')
		return (ft_putchar('%'));
	return (0);
}
