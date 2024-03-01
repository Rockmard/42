/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 20:35:27 by tpipi             #+#    #+#             */
/*   Updated: 2024/01/31 19:07:59 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack	*new_stack(long val)
{
	t_stack	*new_stack;

	new_stack = malloc(sizeof(t_stack));
	if (!new_stack)
		return (NULL);
	new_stack->value = val;
	new_stack->normalized = 0;
	new_stack->next = NULL;
	new_stack->previous = NULL;
	return (new_stack);
}

t_stack	*get_top(t_stack	*stack)
{
	while (stack && stack->previous)
		stack = stack->previous;
	return (stack);
}

t_stack	*get_bottom(t_stack	*stack)
{
	while (stack && stack->next)
		stack = stack->next;
	return (stack);
}

void	free_stack(t_stack *stack)
{
	if (stack)
	{
		if (stack->next)
			free_stack(stack->next);
		free(stack);
		stack = NULL;
	}
}

int	get_nb_elem(t_stack	*stack)
{
	int	nb;

	nb = 0;
	get_top(stack);
	if (stack)
		nb++;
	while (stack && stack->next)
	{
		stack = stack->next;
		nb++;
	}
	return (nb);
}
