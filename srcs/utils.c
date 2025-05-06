/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 03:23:35 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/06 03:34:09 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* =============== Importation =============== */

#include "ft_printf.h"

/* =============== Declaration =============== */

void	free_list_el(t_list *head);
void	free_el(t_element *el);

/* =============== Definition =============== */

void	free_list_el(t_list *head)
{
	t_list	*next;

	while (head)
	{
		next = head->next;
		free_el(head->content);
		free(head);
		head = next;
	}
}

void	free_el(t_element *el)
{
	if (!el)
		return ;
	if (el->type == T_FORMAT)
		(free(el->data.format.text));
	return (free(el));
}
