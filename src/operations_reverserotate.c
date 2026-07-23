/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_reverserotate.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edmedeir <edmedeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 12:03:50 by edmedeir          #+#    #+#             */
/*   Updated: 2026/07/23 12:18:52 by edmedeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	reverse_rotate(t_node **stack)
{
	t_node	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	last->prev->next = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	last->prev = NULL;
	*stack = last;
}

void	rra(t_node **stack_a)
{
	reverse_rotate(stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_node **stack_b)
{
	reverse_rotate(stack_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
}
