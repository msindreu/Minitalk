/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msindreu <msindreu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 15:33:23 by msindreu          #+#    #+#             */
/*   Updated: 2022/06/10 13:15:39 by msindreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*elemento;

	elemento = malloc(sizeof (t_list));
	if (elemento == NULL)
		return (NULL);
	elemento -> content = content;
	elemento -> next = NULL;
	return (elemento);
}
