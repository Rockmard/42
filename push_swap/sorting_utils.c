/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 00:31:10 by tpipi             #+#    #+#             */
/*   Updated: 2024/02/02 18:54:01 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	stack_is_sorted(t_stack *stack)
{
	if (get_nb_elem(stack) > 1)
	{
		stack = get_top(stack);
		while (stack->next)
		{
			if (stack->value > stack->next->value)
				return (0);
			stack = stack->next;
		}
	}
	return (1);
}

int	stack_is_normalized(t_stack *stack)
{
	if (get_nb_elem(stack) > 1)
	{
		stack = get_top(stack);
		while (stack)
		{
			if (stack->normalized == 0)
				return (0);
			stack = stack->next;
		}
	}
	return (1);
}

void	normalize_value(t_stack *stack)
{
	int		min_val;
	int		new_val;
	t_stack	*min;

	new_val = 0;
	while (!stack_is_normalized(stack))
	{
		min_val = INT_MAX;
		while (stack)
		{
			if (stack->value <= min_val && stack->normalized == 0)
			{
				min = stack;
				min_val = stack->value;
			}
			if (!stack->next)
				break ;
			stack = stack->next;
		}
		min->value = new_val++;
		min->normalized = 1;
		stack = get_top(stack);
	}
}

void	radix(int nth_bit, t_stack **stack_a, t_stack **stack_b)
{
	if ((((*stack_a)->value >> nth_bit) & 1) == 0)
		ft_push(stack_b, stack_a, "pb\n");
	else
		ft_rotate(*stack_a, "ra\n");
}

int	get_min(t_stack *stack)
{
	int	min;

	min = stack->value;
	while (stack)
	{
		if (stack->value <= min)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}
