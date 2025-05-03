/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_text_raw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 11:48:22 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/03 12:46:22 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_element	*create_text_raw(char *p_start, char *p_end)
{
	t_element	*node;

	node = malloc(sizeof(t_element));
	if (!node)
		return (NULL);
	node->type = T_TEXT;
	node->data.text_raw.text = p_start;
	node->data.text_raw.len = p_end - p_start;
	return (node);
}
