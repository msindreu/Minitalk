/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msindreu <msindreu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 19:05:50 by msindreu          #+#    #+#             */
/*   Updated: 2022/06/30 17:28:54 by msindreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/ft_printf.h"

static int	ft_condition(const char *str, int *i, va_list argument, int len)
{
	int	n;

	n = 0;
	if (str[*i] == '%')
	{
		n = ft_check(argument, str[*i + 1]);
		if (n == -1)
			return (-1);
		len = len + n;
		*i = *i + 1;
	}
	else
	{
		if (ft_putchar(str[*i]) == -1)
			return (-1);
		else
			len++;
	}
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		len;
	int		i;
	va_list	argument;

	len = 0;
	i = 0;
	va_start(argument, str);
	while (str[i] != '\0')
	{
		len = ft_condition(str, &i, argument, len);
		if (len == -1)
			return (-1);
		i++;
	}
	va_end(argument);
	return (len);
}
