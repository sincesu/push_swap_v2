/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saincesu <saincesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 00:20:42 by saincesu          #+#    #+#             */
/*   Updated: 2025/12/28 02:02:05 by saincesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h> 
#include <unistd.h>

void	sab(t_stack *stack, int option)
{
	int	tmp;

	if (!stack || !stack->head->next)
		return ;
	tmp = stack->head->value;
	stack->head->value = stack->head->next->value;
	stack->head->next->value = tmp;
	if (option == SA)
		write(1, "sa\n", 3);
	else if (option == SB)
		write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	sab(a, SS);
	sab(b, SS);
	write(1, "ss\n", 3);
}

void	pab(t_stack *a, t_stack *b, int option)
{
	if (!a || !b)
		return ;
	if (option == PA)
	{
		if (!b->head)
			return ;
		do_push(b, a);
		write(1, "pa\n", 3);
	}
	else
	{
		if (!a->head)
			return ;
		do_push(a, b);
		write(1, "pb\n", 3);
	}
}

void	rab(t_stack *stack, int option)
{
	t_node	*tmp;
	t_node	*last;

	if (!stack->head || !stack->head->next)
		return ;
	tmp = stack->head;
	stack->head = stack->head->next;
	tmp->next = NULL;
	last = stack->head;
	while (last->next)
		last = last->next;
	last->next = tmp;
	if (option == RA)
		write(1, "ra\n", 3);
	else if (option == RB)
		write(1, "rb\n", 3);
}

void	rrab(t_stack *stack, int option)
{
	t_node	*last;
	t_node	*prev;

	if (!stack->head || !stack->head->next)
		return ;
	last = stack->head;
	prev = NULL;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = stack->head;
	stack->head = last;
	if (option == RRA)
		write(1, "rra\n", 4);
	else if (option == RRB)
		write(1, "rrb\n", 4);
}
