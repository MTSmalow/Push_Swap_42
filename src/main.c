/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edmedeir <edmedeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 11:48:10 by edmedeir          #+#    #+#             */
/*   Updated: 2026/07/23 16:09:12 by edmedeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	long	num;
	int		error;
	int		i;
	int		size;

	if (argc <= 1)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	i = 1;
	while (argv[i])
	{
		error = 0;
		if (!is_valid_number(argv[i]))
		{
			free_stack(&stack_a);
			write(2, "Error\n", 6);
			return (1);
		}
		num = ft_atol_safe(argv[i], &error);
		if (error == 1 || has_duplicate(stack_a, (int)num))
		{
			free_stack(&stack_a);
			write(2, "Error\n", 6);
			return (1);
		}
		if (!stack_add_back(&stack_a, (int)num))
		{
			free_stack(&stack_a);
			write(2, "Error\n", 6);
			return (1);
		}
		i++;
	}
	size = stack_size(stack_a);
	if (!is_sorted(stack_a))
	{
		if (size == 2)
			sa(&stack_a);
		else if (size == 3)
			sort_three(&stack_a);
		else if (size <= 5)
			sort_small(&stack_a, &stack_b);
	}
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
