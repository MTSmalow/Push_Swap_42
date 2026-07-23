/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edmedeir <edmedeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 11:40:05 by edmedeir          #+#    #+#             */
/*   Updated: 2026/07/23 12:22:29 by edmedeir         ###   ########.fr       */
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

int		has_duplicate(t_node *stack, int num);
int		is_valid_number(char *str);
int		stack_add_back(t_node **stack, int value);
int		free_stack(t_node **stack);
long	ft_atol_safe(char *str, int *error);
void	pa(t_node **stack_a, t_node **stack_b);
void	pb(t_node **stack_a, t_node **stack_b);
void	sa(t_node **stack_a);
void	sb(t_node **stack_b);
void	ss(t_node **stack_a, t_node **stack_b);
void	ra(t_node **stack_a);
void	rb(t_node **stack_b);
void	rr(t_node **stack_a, t_node **stack_b);
void	rra(t_node **stack_a);
void	rrb(t_node **stack_b);
void	rrr(t_node **stack_a, t_node **stack_b);
t_node	*create_node(int value);

#endif