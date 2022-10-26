/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msindreu <msindreu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 14:51:14 by msindreu          #+#    #+#             */
/*   Updated: 2022/06/01 15:43:26 by msindreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static int	ft_intlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static	char	*ft_process(int n, int len, char *p)
{
	if (n > 9)
	{		
		while (n / 10 >= 0 && len > 0)
		{
			p[len - 1] = n % 10 + 48;
			n = n / 10;
			len--;
		}
	}
	else if (n < -9)
	{
		if (n < 0)
		{
			n = -n;
			p[0] = '-';
		}
		while (n / 10 >= 0 && len > 1)
		{
			p[len - 1] = n % 10 + 48;
			n = n / 10;
			len--;
		}
	}
	return (p);
}

char	*ft_itoa(int n)
{
	char	*p;
	int		len;

	len = ft_intlen(n);
	if (n == -2147483648)
	{
		p = ft_strdup("-2147483648");
		return (p);
	}
	p = (char *)malloc((len + 1) * sizeof(char));
	if (p == NULL)
		return (NULL);
	p[len] = '\0';
	if ((n <= 9 && n >= 0) || (n <= -1 && n >= -9))
	{
		if (n < 0)
		{
			n = -n;
			p[0] = '-';
		}
		p[len - 1] = n + 48;
		return (p);
	}
	p = ft_process(n, len, p);
	return (p);
}
