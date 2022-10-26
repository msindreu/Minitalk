/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msindreu <msindreu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 19:18:18 by msindreu          #+#    #+#             */
/*   Updated: 2022/05/18 16:33:56 by msindreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*p;
	int		len;

	len = ft_strlen(s);
	if ((char)c == '\0')
	{
		p = (char *) s + len;
		return (p);
	}
	while (len >= 0)
	{
		if (s[len] == (char)c)
		{
			p = (char *)s + len;
			return (p);
		}
		len--;
	}
	return (0);
}
