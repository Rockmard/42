/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:50:12 by tpipi             #+#    #+#             */
/*   Updated: 2024/02/02 19:09:29 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "sorting.h"

int	check_double(t_stack *stack)
{
	t_stack	*p1;
	t_stack	*p2;

	p1 = stack;
	p2 = stack;
	while (p1)
	{
		while (p2)
		{
			if (p1->value == p2->value && p1 != p2)
				return (-1);
			p2 = p2->next;
		}
		p1 = p1->next;
		p2 = p1;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac > 1)
	{
		stack_a = stack_fill(++av);
		stack_b = NULL;
		if (!stack_a)
		{
			ft_putstr_fd("Error\n", 2);
			return (-1);
		}
		else if (check_double(stack_a) == -1)
		{
			ft_putstr_fd("Error\n", 2);
			free_stack(stack_a);
			return (-1);
		}
		normalize_value(stack_a);
		if (!stack_is_sorted(stack_a))
			stack_a = sort(stack_a, stack_b);
		free_stack(stack_a);
		return (0);
	}
}
