/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edmedeir <edmedeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 13:21:19 by edmedeir          #+#    #+#             */
/*   Updated: 2026/07/22 13:21:20 by edmedeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	is_valid_number(char *str);

int	main(void)
{
	printf("--- STRINGS QUE DEVEM RETORNAR 1 (VÁLIDAS) ---\n");
	printf("Muda para 1? [%d] -> '42'\n", is_valid_number("42"));
	printf("Muda para 1? [%d] -> '-42'\n", is_valid_number("-42"));
	printf("Muda para 1? [%d] -> '+42'\n", is_valid_number("+42"));
	printf("Muda para 1? [%d] -> '0'\n", is_valid_number("0"));

	printf("\n--- STRINGS QUE DEVEM RETORNAR 0 (INVÁLIDAS) ---\n");
	printf("Muda para 0? [%d] -> '42a' (Letra no fim)\n", is_valid_number("42a"));
	printf("Muda para 0? [%d] -> 'a42' (Letra no início)\n", is_valid_number("a42"));
	printf("Muda para 0? [%d] -> '++42' (Sinal duplo)\n", is_valid_number("++42"));
	printf("Muda para 0? [%d] -> '--42' (Sinal duplo)\n", is_valid_number("--42"));
	printf("Muda para 0? [%d] -> '+' (Apenas sinal)\n", is_valid_number("+"));
	printf("Muda para 0? [%d] -> '-' (Apenas sinal)\n", is_valid_number("-"));
	printf("Muda para 0? [%d] -> '4-2' (Sinal no meio)\n", is_valid_number("4-2"));
	printf("Muda para 0? [%d] -> '' (String vazia)\n", is_valid_number(""));

	return (0);
}