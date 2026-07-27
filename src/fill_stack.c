/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edmedeir <edmedeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 16:32:20 by edmedeir          #+#    #+#             */
/*   Updated: 2026/07/27 16:48:13 by edmedeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	add_back(t_node **stack, t_node *new_node)
{
	t_node	*temp;

	if (!stack || !new_node)
		return ;
	if (!*stack)
	{
		*stack = new_node;
		return ;
	}
	temp = *stack;
	while (temp->next)
		temp = temp->next;
	temp->next = new_node;
}

int	fill_stack_a(t_node **stack_a, int argc, char **argv, int start_idx)
{
	int		i;
	long	num;
	t_node	*new_node;

	i = start_idx;
	while (i < argc)
	{
		num = ft_atoi(argv[i]);
		if (num < -2147483648 || num > 2147483647)
			return (0);
		if (has_duplicate(*stack_a, (int)num))
			return (0);
		new_node = create_node((int)num);
		if (!new_node)
			return (0);
		add_back(stack_a, new_node);
		i++;
	}
	return (1);
}
