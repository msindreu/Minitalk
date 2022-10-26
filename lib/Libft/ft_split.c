/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msindreu <msindreu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 17:05:00 by msindreu          #+#    #+#             */
/*   Updated: 2022/05/28 18:03:35 by msindreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_words(char const *s, char c)
{
	size_t	i;
	size_t	nw;

	i = 0;
	nw = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			nw++;
		i++;
	}
	return (nw);
}

static size_t	ft_lenword(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}

void	ft_free(char **ptr, size_t i)
{
	while (i > 0)
	{
		free(ptr[i - 1]);
		i--;
	}
	free(ptr);
}

char	**ft_split(char const *s, char c)
{
	char		**p;
	size_t		i;
	size_t		j;
	size_t		words;

	words = ft_words(s, c);
	p = ft_calloc(words + 1, sizeof(char *));
	if (p == NULL)
		return (NULL);
	j = 0;
	i = 0;
	while (i < words)
	{
		while (s[j] == c && s[j] != '\0')
			j++;
		p[i] = ft_substr(s, j, ft_lenword(s + j, c));
		if (p[i] == NULL)
		{
			ft_free(p, i);
			return (NULL);
		}
		i++;
		j = j + ft_lenword(s + j, c);
	}
	return (p);
}
