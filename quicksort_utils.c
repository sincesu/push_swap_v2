/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saincesu <saincesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 02:04:28 by saincesu          #+#    #+#             */
/*   Updated: 2025/12/28 02:16:15 by saincesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	partition_stack_b(t_stack *a, t_stack *b, int len, int pivot)
{
	int	items_pushed;
	int	items_rotated;
	int	len_copy;

	items_pushed = 0;
	items_rotated = 0;
	len_copy = len;
	while (len_copy > 0 && items_pushed < (len / 2) + (len % 2))
	{
		if (b->head->value >= pivot && ++items_pushed)
			pab(a, b, PA);
		else
		{
			rab(b, RB);
			items_rotated++;
		}
		len_copy--;
	}
	if (b->size > items_rotated)
		while (items_rotated-- > 0)
			rrab(b, RRB);
	return (items_pushed);
}

int	partition_stack_a(t_stack *a, t_stack *b, int len, int pivot)
{
	int	items_pushed;
	int	items_rotated;
	int	len_copy;

	items_pushed = 0;
	items_rotated = 0;
	len_copy = len;
	while (len_copy > 0 && items_pushed < (len / 2) + (len % 2))
	{
		if (a->head->value < pivot && ++items_pushed)
			pab(a, b, PB);
		else
		{
			rab(a, RA);
			items_rotated++;
		}
		len_copy--;
	}
	if (a->size > items_rotated)
		while (items_rotated-- > 0)
			rrab(a, RRA);
	return (items_pushed);
}
