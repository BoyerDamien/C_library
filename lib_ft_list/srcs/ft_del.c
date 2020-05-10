/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 11:58:08 by dboyer            #+#    #+#             */
/*   Updated: 2020/04/29 21:02:42 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_list.h"

static inline void	correct_index(t_element *element)
{
	element->index--;
}

void				ft_del(t_list *list, t_element *element)
{
	if (element)
	{
		if (element->previous && element->next)
		{
			list->iter(element->next, correct_index);
			element->previous->next = element->next;
			element->next->previous = element->previous;
		}
		else if (!element->previous && element->next)
		{
			list->iter(element->next, correct_index);
			element->next->previous = NULL;
			list->first = element->next;
		}
		else if (element->previous && !element->next)
		{
			element->previous->next = NULL;
			list->last = element->previous;
		}
		free(element);
		list->size--;
	}
}
