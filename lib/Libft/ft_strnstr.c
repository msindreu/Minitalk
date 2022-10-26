/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msindreu <msindreu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 13:03:04 by msindreu          #+#    #+#             */
/*   Updated: 2022/05/23 14:52:03 by msindreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*p;

	if (needle[0] == '\0')
		return ((char *)haystack);
	i = 0;
	while (i < len && haystack[i] != '\0')
	{
		j = 0;
		if (haystack[i] == needle[0])
		{
			p = (char *)(haystack + i);
			while (haystack[i + j] == needle[j] && needle[j] != '\0'
				&& i + j < len)
			{
				j++;
			}
			if (needle[j] == '\0')
				return (p);
		}
		i++;
	}
	return (NULL);
}
