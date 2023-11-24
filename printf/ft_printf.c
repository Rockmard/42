/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 05:15:45 by tpipi             #+#    #+#             */
/*   Updated: 2023/11/20 11:19:02 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_valid(char c)
{
	int		i;
	char	*valid_char;

	i = 0;
	valid_char = "cspdiuxX%";
	while (c && valid_char[i])
	{
		if (c == valid_char[i])
			return (1);
		i++;
	}
	return (0);
}

static void	parsing(const char *str, int *i, va_list arg_lst, int *nbpc)
{
	if (str[*i] == '%' && is_valid(str[*i + 1]))
	{
		if (str[*i + 1] == 'd' || str[*i + 1] == 'i')
			ft_putnbr(va_arg(arg_lst, int), nbpc);
		else if (str[*i + 1] == 'u')
			ft_putunbr(va_arg(arg_lst, unsigned int), nbpc);
		else if (str[*i + 1] == 's')
			*nbpc += ft_putstr(va_arg(arg_lst, char *));
		else if (str[*i + 1] == 'c')
			*nbpc += ft_putchar(va_arg(arg_lst, int));
		else if (str[*i + 1] == 'x')
			ft_putnbr_base(va_arg(arg_lst, int), "0123456789abcdef", nbpc);
		else if (str[*i + 1] == 'X')
			ft_putnbr_base(va_arg(arg_lst, int), "0123456789ABCDEF", nbpc);
		else if (str[*i + 1] == 'p')
			ft_putpointer(va_arg(arg_lst, unsigned long), nbpc);
		else if (str[*i + 1] == '%')
			*nbpc += write(1, &str[*i], 1);
		(*i)++;
	}
	else if (str[*i] == '%' && !str[*i + 1])
		*nbpc = -1;
	else
		*nbpc += write(1, &str[*i], 1);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		nb_printed_char;
	va_list	arg_lst;

	if (!str)
		return (-1);
	va_start(arg_lst, str);
	i = 0;
	nb_printed_char = 0;
	while (str[i])
	{
		parsing(str, &i, arg_lst, &nb_printed_char);
		i++;
	}
	va_end(arg_lst);
	return (nb_printed_char);
}
