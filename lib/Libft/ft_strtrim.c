/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msindreu <msindreu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:43:09 by msindreu          #+#    #+#             */
/*   Updated: 2022/05/25 12:54:49 by msindreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s1);
	while (ft_strchr(set, s1[i]) != 0 && s1[i] != '\0')
		i++;
	while (ft_strrchr(set, s1[len]) != 0 && len > 0)
		len--;
	return (ft_substr(s1, (unsigned int)i, len - i + 1));
}
