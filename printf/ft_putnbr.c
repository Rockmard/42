/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:33:31 by tpipi             #+#    #+#             */
/*   Updated: 2023/11/16 02:54:21 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, int *nbpc)
{
	int	nb;

	if (n == -2147483648)
	{
		*nbpc += write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		*nbpc += ft_putchar('-');
		n = -n;
	}
	if (n > 9)
	{
		nb = n % 10;
		ft_putnbr(n / 10, nbpc);
		*nbpc += ft_putchar(nb + '0');
	}
	else
		*nbpc += ft_putchar(n + '0');
}

void	ft_putunbr(unsigned int n, int *nbpc)
{
	unsigned int	nb;

	if (n > 9)
	{
		nb = n % 10;
		ft_putnbr(n / 10, nbpc);
		*nbpc += ft_putchar(nb + '0');
	}
	else
		*nbpc += ft_putchar(n + '0');
}
