/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edmedeir <edmedeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 11:48:10 by edmedeir          #+#    #+#             */
/*   Updated: 2026/07/23 10:25:56 by edmedeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	long	num;
	int		error;
	int		i;

	if (argc <= 1)
		return (0);
	stack_a = NULL;
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
	free_stack (0);
	return (0);
}
