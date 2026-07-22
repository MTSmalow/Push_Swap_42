/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol_safe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edmedeir <edmedeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 13:38:54 by edmedeir          #+#    #+#             */
/*   Updated: 2026/07/22 13:39:17 by edmedeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

long	ft_atol_safe(const char *str, int *error);

void	run_test(const char *str, long expected_val, int expected_err)
{
	int	error;

	error = 0;
	long result = ft_atol_safe(str, &error);

	if (error == expected_err && (error == 1 || result == expected_val))
		printf("[  OK  ] Input: %-15s -> Result: %-11ld | Error Flag: %d\n", str, result, error);
	else
		printf("[ FAIL ] Input: %-15s -> Esperado: (%ld, err:%d) | Obtido: (%ld, err:%d)\n",
			str, expected_val, expected_err, result, error);
}

int	main(void)
{
	printf("=== 1. VALORES VÁLIDOS (Dentro do limite de int) ===\n");
	run_test("0", 0, 0);
	run_test("42", 42, 0);
	run_test("-42", -42, 0);
	run_test("+100", 100, 0);
	run_test("2147483647", 2147483647, 0);        // INT_MAX exato
	run_test("-2147483648", -2147483648, 0);      // INT_MIN exato

	printf("\n=== 2. OVERFLOW E UNDERFLOW (Devem acionar error = 1) ===\n");
	run_test("2147483648", 0, 1);                 // INT_MAX + 1
	run_test("-2147483649", 0, 1);                // INT_MIN - 1
	run_test("99999999999999999", 0, 1);          // Número gigante (Overflow de long/int)
	run_test("-99999999999999999", 0, 1);         // Número negativo gigante

	return (0);
}
