/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edmedeir <edmedeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 16:15:52 by edmedeir          #+#    #+#             */
/*   Updated: 2026/07/27 16:18:51 by edmedeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

#include "push_swap.h"

static void	init_config(t_config *config)
{
	config->strategy = STRAT_ADAPTIVE;
	config->bench = 0;
	config->disorder = 0.0;
}

static int	check_flag(char *arg, t_config *config)
{
	if (ft_strcmp(arg, "--simple") == 0)
		config->strategy = STRAT_SIMPLE;
	else if (ft_strcmp(arg, "--medium") == 0)
		config->strategy = STRAT_MEDIUM;
	else if (ft_strcmp(arg, "--complex") == 0)
		config->strategy = STRAT_COMPLEX;
	else if (ft_strcmp(arg, "--adaptive") == 0)
		config->strategy = STRAT_ADAPTIVE;
	else if (ft_strcmp(arg, "--bench") == 0)
		config->bench = 1;
	else
		return (0);
	return (1);
}

int	parse_flags(int argc, char **argv, t_config *config, int *start_idx)
{
	int	i;

	init_config(config);
	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-' && argv[i][1] == '-')
		{
			if (!check_flag(argv[i], config))
				return (0);
		}
		else
		{
			*start_idx = i;
			return (1);
		}
		i++;
	}
	*start_idx = i;
	return (1);
}
