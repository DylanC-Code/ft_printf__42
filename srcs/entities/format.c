/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 14:33:43 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/07 17:52:12 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* =============== Importation =============== */

#include "ft_printf.h"

/* =============== Declaration =============== */

t_element	*create_format(void);
void		free_format(t_format *format);

/* =============== Definition =============== */

t_element	*create_format(void)
{
	t_element	*node;

	node = malloc(sizeof(t_element));
	if (!node)
		return (NULL);
	node->type = T_FORMAT;
	node->data.format.len = 2;
	node->data.format.minus = false;
	node->data.format.zero = false;
	node->data.format.precision = 0;
	node->data.format.hash = false;
	node->data.format.space = false;
	node->data.format.plus = false;
	node->data.format.width = 0;
	node->data.format.type = 0;
	node->data.format.text = NULL;
	node->data.format.text_len = 0;
	return (node);
}

void	free_format(t_format *format)
{
	if (!format)
		return ;
	free(format->text);
	free(format);
}
