/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edmedeir <edmedeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 09:57:38 by edmedeir          #+#    #+#             */
/*   Updated: 2026/07/23 15:58:37 by edmedeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*create_node(int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->index = -1;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

int	stack_add_back(t_node **stack, int value)
{
	t_node	*new_node;
	t_node	*last;

	new_node = create_node(value);
	if (!new_node)
		return (0);
	if (*stack == NULL)
		*stack = new_node;
	else
	{
		last = *stack;
		while (last->next != NULL)
			last = last->next;
		last->next = new_node;
		new_node->prev = last;
	}
	return (1);
}

int	stack_size(t_node *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

int	find_small(t_node *stack)
{
	int	cont;
	int	cont_small;
	int	small;

	if (!stack)
		return (-1);
	cont = 0;
	cont_small = 0;
	small = stack->value;
	while (stack)
	{
		if (stack->value < small)
		{
			small = stack->value;
			cont_small = cont;
		}
		cont++;
		stack = stack->next;
	}
	return (cont_small);
}

int	is_sorted(t_node *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}
