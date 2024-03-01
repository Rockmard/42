/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_fill_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:38:34 by tpipi             #+#    #+#             */
/*   Updated: 2024/01/31 23:31:13 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

long	ft_atol(char *stack_val)
{
	int		i;
	int		sign;
	long	nb;

	i = 0;
	sign = 1;
	nb = 0;
	while (stack_val[i] == ' ' || (stack_val[i] >= 8 && stack_val[i] <= 13))
		i++;
	if (stack_val[i] == '+' || stack_val[i] == '-')
	{
		if (stack_val[i] == '-')
			sign *= -1;
		i++;
	}
	if (!stack_val[i])
		return (-2147483649);
	while (stack_val[i])
	{
		if (!(stack_val[i] >= '0' && stack_val[i] <= '9') || nb > INT_MAX)
			return (-2147483649);
		nb = nb * 10 + stack_val[i] - '0';
		i++;
	}
	return (sign * nb);
}

void	add_stack_val(int val, t_stack **stack)
{
	t_stack	*new;

	new = new_stack(val);
	if (!(*stack))
		*stack = new;
	else
	{
		new->previous = (*stack);
		(*stack)->next = new;
		*stack = (*stack)->next;
	}
}

void	free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	*full_free(t_stack *stack, char **split)
{
	free_stack(get_top(stack));
	free_split(split);
	return (NULL);
}

t_stack	*stack_fill(char	**stack_val)
{
	char	**split;
	int		i;
	long	val;
	t_stack	*stack;

	stack = NULL;
	while (*stack_val)
	{
		split = ft_split(*stack_val, ' ');
		i = 0;
		if (!split[i])
			return (full_free(stack, split));
		while (split[i])
		{
			val = ft_atol(split[i]);
			if (val > 2147483647 || val < -2147483648)
				return (full_free(stack, split));
			else
				add_stack_val((int)val, &stack);
			i++;
		}
		stack_val++;
		free_split(split);
	}
	return (get_top(stack));
}
