/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 05:37:10 by tpipi             #+#    #+#             */
/*   Updated: 2024/02/26 15:28:24 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	ft_putpointer(unsigned long nbr, int *nbpc)
{
	int		nb2;
	char	*base;

	base = "0123456789abcdef";
	if (nbr == 0)
		*nbpc += ft_putstr("(nil)");
	else if (nbr > 16 - 1)
	{
		nb2 = nbr % 16;
		ft_putpointer(nbr / 16, nbpc);
		*nbpc += ft_putchar(base[nb2]);
	}
	else
	{
		*nbpc += ft_putstr("0x");
		*nbpc += ft_putchar(base[nbr]);
	}
}
