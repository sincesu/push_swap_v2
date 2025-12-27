/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saincesu <saincesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 01:48:21 by saincesu          #+#    #+#             */
/*   Updated: 2025/12/28 02:12:06 by saincesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *stack)
{
	int	a;
	int	b;
	int	c;

	a = stack->head->value;
	b = stack->head->next->value;
	c = stack->head->next->next->value;
	if (a > b && c > b && c > a)
		sab(stack, SA);
	else if (a > b && b > c)
	{
		sab(stack, SA);
		rrab(stack, RRA);
	}
	else if (a > b && c > b && a > c)
		rab(stack, RA);
	else if (a < b && b > c && a < c)
	{
		sab(stack, SA);
		rab(stack, RA);
	}
	else if (a < b && b > c && a > c)
		rrab(stack, RRA);
}

void	sort_int_array(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

static int	get_min_pos(t_stack *stack)
{
	int		min;
	int		min_pos;
	int		i;
	t_node	*tmp;

	tmp = stack->head;
	min = tmp->value;
	min_pos = 0;
	i = 0;
	while (tmp)
	{
		if (tmp->value < min)
		{
			min = tmp->value;
			min_pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (min_pos);
}

void	sort_four_and_five(t_stack *a, t_stack *b)
{
	int	min_pos;

	while (a->size > 3)
	{
		min_pos = get_min_pos(a);
		if (min_pos <= a->size / 2)
			while (min_pos-- > 0)
				rab(a, RA);
		else
			while (min_pos++ < a->size)
				rrab(a, RRA);
		pab(a, b, PB);
	}
	sort_three(a);
	while (b->size > 0)
		pab(a, b, PA);
}
