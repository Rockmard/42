/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 05:14:08 by tpipi             #+#    #+#             */
/*   Updated: 2023/11/16 08:37:19 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(unsigned int nbr, char *base, int *nbpc)
{
	unsigned int	nb2;
	unsigned int	base_type;

	base_type = ft_strlen(base);
	if (nbr > base_type - 1)
	{
		nb2 = nbr % base_type;
		ft_putnbr_base(nbr / base_type, base, nbpc);
		*nbpc += ft_putchar(base[nb2]);
	}
	else
		*nbpc += ft_putchar(base[nbr]);
}
