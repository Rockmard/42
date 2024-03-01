/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 00:34:33 by tpipi             #+#    #+#             */
/*   Updated: 2024/02/02 18:53:18 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTING_H
# define SORTING_H

int		stack_is_sorted(t_stack *stack);
int		stack_is_normalized(t_stack *stack);
int		get_min(t_stack *stack);
void	normalize_value(t_stack *stack);
void	radix(int nth_bit, t_stack **stack_a, t_stack **stack_b);
t_stack	*sort_3_elem(t_stack *stack);
t_stack	*sort_4_elem(t_stack *stack_a, t_stack *stack_b);
t_stack	*sort_5_elem(t_stack *stack_a, t_stack *stack_b);
t_stack	*big_sort(t_stack *stack_a, t_stack *stack_b);
t_stack	*sort(t_stack *stack_a, t_stack *stack_b);

#endif