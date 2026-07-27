/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edmedeir <edmedeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 15:24:02 by edmedeir          #+#    #+#             */
/*   Updated: 2026/07/27 15:58:19 by edmedeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

double	compute_disorder(t_node *stack)
{
	t_node	*i;
	t_node	*j;
	double	mistakes;
	double	tot_pairs;

	mistakes = 0.0;
	tot_pairs = 0.0;
	i = stack;
	if (!stack || !(stack->next))
		return (0.0);
	while (i)
	{
		j = i->next;
		while (j)
		{
			tot_pairs += 1.0;
			if (i->value > j->value)
				mistakes += 1.0;
			j = j->next;
		}
		i = i->next;
	}
	return (mistakes / tot_pairs);
}