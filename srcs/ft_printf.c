/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 11:54:36 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/08 21:16:46 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* =============== Importation =============== */

#include "ft_printf.h"

/* =============== Declaration =============== */

int	ft_printf(const char *str, ...);

/* =============== Definition =============== */

int	ft_printf(const char *str, ...)
{
	t_list	*list;
	va_list	args;

	va_start(args, str);
	if (!str)
		return (ERROR);
	list = NULL;
	if (parse_str((char *)str, &list) == ERROR)
		return (free_list_el(list), ERROR);
	if (!list)
		return (0);
	if (apply_formats(list, args) == ERROR)
		return (free_list_el(list), ERROR);
	return (print_contents(list));
}

// int	main(int argc, char const *argv[])
// {
// 	size_t	actu;
// 	size_t	expe;

// 	if (!argc || !argv)
// 		return (1);
// 	// 	// ft_printf("%p", &argc);
// 	actu = ft_printf("| %.2d |", -1);
// 	__builtin_printf("\n");
// 	expe = __builtin_printf("| %.2d |", -1);
// 	// expe = __builtin_printf("| %50s |", "");
// 	//
// 	// __builtin_printf("%#p", &argc);
// 	__builtin_printf("\nE: %ld,\nA: %ld\n", expe, actu);
// 	return (0);
// }
