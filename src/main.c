/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edmedeir <edmedeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 11:48:10 by edmedeir          #+#    #+#             */
/*   Updated: 2026/07/27 16:18:19 by edmedeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_config	config;
	t_node		*stack_a;
	t_node		*stack_b;
	int			start_idx;

	if (argc < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	if (!parse_flags(argc, argv, &config, &start_idx))
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	if (!fill_stack_a(&stack_a, argc, argv, start_idx))
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	config.disorder = compute_disorder(stack_a);
	sort_stack(&stack_a, &stack_b, &config);
	free_stack(&stack_a);
	return (0);
}
