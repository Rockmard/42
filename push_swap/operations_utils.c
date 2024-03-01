/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:28:00 by tpipi             #+#    #+#             */
/*   Updated: 2024/01/31 23:26:48 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	ft_swap(t_stack *stack, char *msg)
{
	int	tmp;

	if (get_nb_elem(stack) > 1)
	{
		stack = get_top(stack);
		tmp = stack->value;
		stack->value = stack->next->value;
		stack->next->value = tmp;
		ft_putstr_fd(msg, 1);
	}
}

void	ft_push(t_stack **stack1, t_stack **stack2, char *msg)
{
	t_stack	*top_stack2;
	t_stack	*next_stack1;

	if (*stack2)
	{
		top_stack2 = get_top(*stack2);
		*stack1 = get_top(*stack1);
		if (!(*stack1))
			*stack1 = new_stack((*stack2)->value);
		else
		{
			(*stack1)->previous = new_stack((*stack2)->value);
			next_stack1 = *stack1;
			*stack1 = (*stack1)->previous;
			(*stack1)->next = next_stack1;
		}
		*stack2 = (*stack2)->next;
		if (*stack2)
			(*stack2)->previous = NULL;
		free(top_stack2);
		ft_putstr_fd(msg, 1);
	}
}

void	ft_rotate(t_stack *stack, char *msg)
{
	int	top_val;

	if (get_nb_elem(stack) > 1)
	{
		stack = get_top(stack);
		top_val = stack->value;
		while (stack->next)
		{
			stack->value = stack->next->value;
			stack = stack->next;
		}
		stack->value = top_val;
		ft_putstr_fd(msg, 1);
	}
}

void	ft_reverse_rotate(t_stack *stack, char *msg)
{
	int	bottom_val;

	if (get_nb_elem(stack) > 1)
	{
		stack = get_bottom(stack);
		bottom_val = stack->value;
		while (stack->previous)
		{
			stack->value = stack->previous->value;
			stack = stack->previous;
		}
		stack->value = bottom_val;
		ft_putstr_fd(msg, 1);
	}
}
