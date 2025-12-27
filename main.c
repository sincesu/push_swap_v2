/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saincesu <saincesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 02:22:50 by saincesu          #+#    #+#             */
/*   Updated: 2025/12/28 01:58:57 by saincesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_stacks(t_stack **a, t_stack **b, t_gc **gc)
{
	*a = ft_malloc(sizeof(t_stack), gc);
	*b = ft_malloc(sizeof(t_stack), gc);
	(*a)->head = NULL;
	(*a)->size = 0;
	(*b)->head = NULL;
	(*b)->size = 0;
}

static void	select_algorithm(t_stack *a, t_stack *b, t_gc **gc)
{
	if (a->size == 2)
		sab(a, SA);
	else if (a->size == 3)
		sort_three(a);
	else if (a->size <= 5)
		sort_four_and_five(a, b);
	else
		quicksort_a(a, b, a->size, gc);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	t_gc	*gc;

	if (ac < 2)
		return (0);
	gc = NULL;
	init_stacks(&a, &b, &gc);
	parse_arguments(ac, av, a, &gc);
	if (!is_sorted(a->head))
		select_algorithm(a, b, &gc);
	ft_gc_clean(&gc);
	return (0);
}
