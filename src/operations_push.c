/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edmedeir <edmedeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 11:07:21 by edmedeir          #+#    #+#             */
/*   Updated: 2026/07/23 16:14:57 by edmedeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	push(t_node **dest, t_node **src)
{
	t_node	*top_src;

	if (!src || !*src)
		return ;
	top_src = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	top_src->next = *dest;
	top_src->prev = NULL;
	if (*dest != NULL)
		(*dest)->prev = top_src;
	*dest = top_src;
}

void	pa(t_node **stack_a, t_node **stack_b)
{
	push(stack_a, stack_b);
	write(1, "pa\n", 3);
}

void	pb(t_node **stack_a, t_node **stack_b)
{
	push(stack_b, stack_a);
	write(1, "pb\n", 3);
}
