/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edmedeir <edmedeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 20:26:14 by edmedeir          #+#    #+#             */
/*   Updated: 2026/07/23 20:48:16 by edmedeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	assign_indexes(t_node **stack)
{
	t_node	*current;
	t_node	*iter;
	int		count;

	current = *stack;
	while (current)
	{
		iter = *stack;
		count = 0;
		while (iter)
		{
			if (iter-> value < current->value)
				count++;
			iter = iter->next;
		}
		current->index = count;
		current = current->next;
	}
}

static int	get_max_bits(t_node *stack)
{
	int	size;
	int	max_bits;

	size = stack_size(stack);
	max_bits = 0;
	while (((size - 1) >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_node **stack_a, t_node **stack_b)
{
	int	i;
	int	j;
	int	size;
	int	max_bits;

	size = stack_size(*stack_a);
	max_bits = get_max_bits(*stack_a);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if ((((*stack_a)->index >> i) & 1) == 0)
				pb(stack_a, stack_b);
			else
				ra(stack_a);
			j++;
		}
		while (*stack_b)
			pa(stack_a, stack_b);
		if (is_sorted(*stack_a))
			break ;
		i++;
	}
}
