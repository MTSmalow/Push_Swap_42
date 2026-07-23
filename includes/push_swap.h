/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edmedeir <edmedeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 11:40:05 by edmedeir          #+#    #+#             */
/*   Updated: 2026/07/23 10:21:45 by edmedeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_node
{
	int					value;
	int					index;
	struct s_node		*next;
	struct s_node		*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
}	t_stack;

int		main(int argc, char **argv);
int		has_duplicate(t_node *stack, int num);
int		is_valid_number(char *str);
int		stack_add_back(t_node **stack, int value);
int		free_stack(t_node **stack);
long	ft_atol_safe(char *str, int *error);
t_node	*create_node(int value);

#endif