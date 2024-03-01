/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:29:54 by tpipi             #+#    #+#             */
/*   Updated: 2024/02/26 15:28:26 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	ft_putstr(char *s)
{
	int	nb_printed_char;

	if (!s)
		s = "(null)";
	nb_printed_char = write(1, s, ft_strlen(s));
	return (nb_printed_char);
}
