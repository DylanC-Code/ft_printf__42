/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 14:33:43 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/03 20:04:08 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* =============== Importation =============== */

#include "ft_printf.h"

/* =============== Declaration =============== */

t_element	*create_format(void);

/* =============== Definition =============== */

t_element	*create_format(void)
{
	t_element	*node;

	node = malloc(sizeof(t_element));
	if (!node)
		return (NULL);
	node->type = T_FORMAT;
	node->data.format.len = 1;
	node->data.format.type = 0;
	node->data.format.padding = 0;
	node->data.format.minus = false;
	return (node);
}
