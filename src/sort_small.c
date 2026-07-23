/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edmedeir <edmedeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 15:32:07 by edmedeir          #+#    #+#             */
/*   Updated: 2026/07/23 16:09:42 by edmedeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	send_min_to_top(t_node **stack_a)
{
	int	pos;
	int	size;

	pos = find_small(*stack_a);
	size = stack_size(*stack_a);
	if (pos <= size / 2)
	{
		while (pos != 0)
		{
			ra(stack_a);
			pos = find_small(*stack_a);
		}
	}
	else
	{
		while (pos != 0)
		{
			rra(stack_a);
			pos = find_small(*stack_a);
		}
	}
}

void	sort_small(t_node **stack_a, t_node **stack_b)
{
	while (stack_size(*stack_a) > 3)
	{
		send_min_to_top(stack_a);
		pb(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b);
}
