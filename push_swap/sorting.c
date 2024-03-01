/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:21:54 by tpipi             #+#    #+#             */
/*   Updated: 2024/02/02 18:54:45 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "sorting.h"

t_stack	*big_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	nth_bit;
	int	bottom;

	nth_bit = 0;
	while (!stack_is_sorted(stack_a))
	{
		stack_a = get_top(stack_a);
		bottom = get_bottom(stack_a)->value;
		while (stack_a)
		{
			radix(nth_bit, &stack_a, &stack_b);
			if (stack_a->value == bottom)
			{
				radix(nth_bit, &stack_a, &stack_b);
				break ;
			}
		}
		nth_bit++;
		while (get_nb_elem(get_top(stack_b)) > 0)
			ft_push(&stack_a, &stack_b, "pa\n");
	}
	return (stack_a);
}

t_stack	*sort_3_elem(t_stack *stack)
{
	t_stack	*next;

	next = stack->next;
	if (!(next->next) || (stack->value > next->value && \
		next->value < next->next->value && stack->value < next->next->value))
		ft_swap(stack, "sa\n");
	else if (stack->value > next->value && next->value > next->next->value)
	{
		ft_swap(stack, "sa\n");
		ft_reverse_rotate(stack, "rra\n");
	}
	else if (stack->value < next->value && next->value > next->next->value && \
		stack->value > next->next->value)
		ft_reverse_rotate(stack, "rra\n");
	else if (stack->value > next->value && next->value < next->next->value && \
		stack->value > next->next->value)
		ft_rotate(stack, "ra\n");
	else if (stack->value < next->value && next->value > next->next->value && \
		stack->value < next->next->value)
	{
		ft_reverse_rotate(stack, "rra\n");
		ft_swap(stack, "sa\n");
	}
	return (stack);
}

t_stack	*sort_4_elem(t_stack *stack_a, t_stack *stack_b)
{
	int	min;

	min = get_min(stack_a);
	if (get_bottom(stack_a)->value == min)
		ft_reverse_rotate(stack_a, "rra\n");
	while (get_top(stack_a)->value != min)
		ft_rotate(stack_a, "ra\n");
	if (!stack_is_sorted(stack_a))
	{
		ft_push(&stack_b, &stack_a, "pb\n");
		stack_a = sort_3_elem(stack_a);
		ft_push(&stack_a, &stack_b, "pa\n");
	}
	return (stack_a);
}

t_stack	*sort_5_elem(t_stack *stack_a, t_stack *stack_b)
{
	int	min;

	min = get_min(stack_a);
	if (get_bottom(stack_a)->value == min)
		ft_reverse_rotate(stack_a, "rra\n");
	while (get_top(stack_a)->value != min)
		ft_rotate(stack_a, "ra\n");
	if (!stack_is_sorted(stack_a))
	{
		ft_push(&stack_b, &stack_a, "pb\n");
		stack_a = sort_4_elem(stack_a, stack_b);
		ft_push(&stack_a, &stack_b, "pa\n");
	}
	return (stack_a);
}

t_stack	*sort(t_stack *stack_a, t_stack *stack_b)
{
	if (get_nb_elem(stack_a) < 4)
		return (sort_3_elem(stack_a));
	else if (get_nb_elem(stack_a) == 4)
		return (sort_4_elem(stack_a, stack_b));
	else if (get_nb_elem(stack_a) == 5)
		return (sort_5_elem(stack_a, stack_b));
	else
		return (big_sort(stack_a, stack_b));
}
