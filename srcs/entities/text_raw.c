/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_raw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 11:48:22 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/04 15:40:58 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_element	*create_text_raw(char *text, size_t len)
{
	t_element	*node;

	node = malloc(sizeof(t_element));
	if (!node)
		return (NULL);
	node->type = T_TEXT;
	node->data.text_raw.text = text;
	node->data.text_raw.len = len;
	return (node);
}
