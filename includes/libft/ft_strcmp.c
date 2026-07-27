/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edmedeir <edmedeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 16:27:49 by edmedeir          #+#    #+#             */
/*   Updated: 2026/07/27 16:28:20 by edmedeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *st1, const char *st2)
{
	size_t	i;

	i = 0;
	while (st1[i] && (st1[i] == st2[i]))
		i++;
	return ((unsigned char)st1[i] - (unsigned char)st2[i]);
}
