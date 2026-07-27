/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selector.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edmedeir <edmedeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 16:30:34 by edmedeir          #+#    #+#             */
/*   Updated: 2026/07/27 16:31:00 by edmedeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_strategy	get_adaptive_strategy(double disorder, int size)
{
	if (size <= 5)
		return (STRAT_SIMPLE);
	if (disorder < 0.2)
		return (STRAT_SIMPLE);
	if (disorder < 0.5)
		return (STRAT_MEDIUM);
	return (STRAT_COMPLEX);
}

void	sort_stack(t_node **stack_a, t_node **stack_b, t_config *config)
{
	int			size;
	t_strategy	active_strategy;

	if (is_sorted(*stack_a))
		return ;
	size = stack_size(*stack_a);
	if (config->strategy == STRAT_ADAPTIVE)
		active_strategy = get_adaptive_strategy(config->disorder, size);
	else
		active_strategy = config->strategy;
	if (active_strategy == STRAT_SIMPLE)
	{
		if (size <= 3)
			sort_three(stack_a);
		else
			sort_small(stack_a, stack_b);
	}
	else if (active_strategy == STRAT_MEDIUM)
		sort_small(stack_a, stack_b);
	else if (active_strategy == STRAT_COMPLEX)
		radix_sort(stack_a, stack_b);
}
