/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saincesu <saincesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 02:04:39 by saincesu          #+#    #+#             */
/*   Updated: 2025/12/28 02:04:41 by saincesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_push(t_stack *from, t_stack *to)
{
	t_node	*tmp;

	tmp = from->head;
	from->head = from->head->next;
	tmp->next = to->head;
	to->head = tmp;
	from->size--;
	to->size++;
}
