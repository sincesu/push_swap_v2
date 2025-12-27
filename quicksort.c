/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saincesu <saincesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 01:47:54 by saincesu          #+#    #+#             */
/*   Updated: 2025/12/28 02:16:46 by saincesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_median(t_node *head, int len, t_gc **gc)
{
	int		*arr;
	int		i;
	int		median;
	t_node	*tmp;

	arr = ft_malloc(sizeof(int) * len, gc);
	tmp = head;
	i = 0;
	while (i < len && tmp)
	{
		arr[i] = tmp->value;
		tmp = tmp->next;
		i++;
	}
	sort_int_array(arr, len);
	median = arr[len / 2];
	return (median);
}

static int	is_sorted_in_quick(t_node *head, int len, int flag)
{
	int		i;
	t_node	*tmp;

	i = 0;
	tmp = head;
	while (i < len - 1 && tmp && tmp->next)
	{
		if (flag == 0)
		{
			if (tmp->value > tmp->next->value)
				return (0);
		}
		else
		{
			if (tmp->value < tmp->next->value)
				return (0);
		}
		tmp = tmp->next;
		i++;
	}
	return (1);
}

static void	quicksort_b(t_stack *a, t_stack *b, int len, t_gc **gc)
{
	int	pivot;
	int	items_pushed;

	if (is_sorted_in_quick(b->head, len, 1))
	{
		while (len--)
			pab(a, b, PA);
		return ;
	}
	if (len <= 2)
	{
		if (len == 0)
			return ;
		if (len == 2 && b->head->value < b->head->next->value)
			sab(b, SB);
		while (len--)
			pab(a, b, PA);
		return ;
	}
	pivot = get_median(b->head, len, gc);
	items_pushed = partition_stack_b(a, b, len, pivot);
	quicksort_a(a, b, items_pushed, gc);
	quicksort_b(a, b, len - items_pushed, gc);
}

int	quicksort_a(t_stack *a, t_stack *b, int len, t_gc **gc)
{
	int	pivot;
	int	items_pushed;

	if (is_sorted_in_quick(a->head, len, 0))
		return (1);
	if (len <= 2)
	{
		if (len == 2 && a->head->value > a->head->next->value)
			sab(a, SA);
		return (1);
	}
	pivot = get_median(a->head, len, gc);
	items_pushed = partition_stack_a(a, b, len, pivot);
	quicksort_a(a, b, len - items_pushed, gc);
	quicksort_b(a, b, items_pushed, gc);
	return (1);
}
