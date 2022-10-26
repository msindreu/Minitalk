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

int	ft_protect(unsigned int n, int x, int (*f) (unsigned int))
{	
	int	div;
	int	mod;

	div = f(n / x);
	if (div == -1)
		return (-1);
	mod = f(n % x);
	if (mod == -1)
		return (-1);
	return (div + mod);
}
