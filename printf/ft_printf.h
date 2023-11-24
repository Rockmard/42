/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 05:11:42 by tpipi             #+#    #+#             */
/*   Updated: 2023/11/16 09:02:01 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		ft_strlen(char *str);
int		ft_putchar(char c);
int		ft_putstr(char *s);
void	ft_putnbr(int n, int *nbpc);
void	ft_putunbr(unsigned int n, int *nbpc);
void	ft_putnbr_base(unsigned int nbr, char *base, int *nbpc);
void	ft_putpointer(unsigned long nbr, int *nbpc);

#endif