/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 20:32:17 by tpipi             #+#    #+#             */
/*   Updated: 2024/01/31 23:27:20 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdlib.h>
# include <limits.h>
# include "./libft/libft.h"

typedef struct s_stack
{
	int				value;
	int				normalized;
	struct s_stack	*next;
	struct s_stack	*previous;
}	t_stack;

long	ft_atol(char *stack_val);
int		get_nb_elem(t_stack	*stack);
void	add_stack_val(int val, t_stack **stack);
void	free_stack(t_stack *stack);
void	free_split(char **str);
void	ft_swap(t_stack *stack, char *msg);
void	ft_push(t_stack **stack1, t_stack **stack2, char *msg);
void	ft_rotate(t_stack *stack, char *msg);
void	ft_reverse_rotate(t_stack *stack, char *msg);
t_stack	*new_stack(long val);
t_stack	*stack_fill(char **stack_val);
t_stack	*get_top(t_stack	*stack);
t_stack	*get_bottom(t_stack	*stack);

#endif