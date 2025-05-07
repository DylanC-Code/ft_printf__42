/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_printers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 21:49:38 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/07 17:44:18 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* =============== Importation =============== */

#include "ft_printf.h"

/* =============== Declaration =============== */

int	print_padding(unsigned int number);
int	print_n(char *text, size_t n);

/* =============== Definition =============== */

int	print_n(char *text, size_t n)
{
	ssize_t	bytes_written;

	bytes_written = 0;
	if (!text)
		return (bytes_written);
	bytes_written = write(STDOUT_FILENO, text, n);
	if (bytes_written >= 0)
		return (bytes_written);
	return (0);
}

int	print_padding(unsigned int number)
{
	size_t	i;
	size_t	bytes_written;

	i = -1;
	bytes_written = 0;
	while (++i < number)
		if (write(STDOUT_FILENO, " ", 1) > 0)
			bytes_written++;
	return (bytes_written);
}
