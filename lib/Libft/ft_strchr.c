/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msindreu <msindreu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:31:13 by msindreu          #+#    #+#             */
/*   Updated: 2022/05/17 17:40:21 by msindreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*p;

	i = 0;
	if ((char)c == '\0')
	{
		p = (char *) s + ft_strlen(s);
		return (p);
	}
	while ((s != 0) && (s[i] != '\0'))
	{
		if (s[i] == (char)c)
		{
			p = ((char *)s) + i;
			return (p);
		}
		i++;
	}
	return (0);
}
