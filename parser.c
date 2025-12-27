/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saincesu <saincesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 00:07:16 by saincesu          #+#    #+#             */
/*   Updated: 2025/12/28 01:57:52 by saincesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

static void	add_to_stack(t_stack *stack, int num, t_gc **gc)
{
	t_node	*new_node;
	t_node	*tmp;

	new_node = ft_malloc(sizeof(t_node), gc);
	new_node->value = num;
	new_node->next = NULL;
	if (stack->head == NULL)
		stack->head = new_node;
	else
	{
		tmp = stack->head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_node;
	}
	stack->size++;
}

static int	check_duplicate(t_node *head, int num)
{
	while (head)
	{
		if (head->value == num)
			return (1);
		head = head->next;
	}
	return (0);
}

static void	process_args(char **tmp_args, t_stack *stack_a, t_gc **gc)
{
	int		j;
	long	num;

	j = 0;
	while (tmp_args[j])
	{
		if (!is_all_digit(tmp_args[j]))
			ft_error(gc);
		num = ft_atol(tmp_args[j]);
		if (num > 2147483647 || num < -2147483648)
			ft_error(gc);
		if (check_duplicate(stack_a->head, (int)num))
			ft_error(gc);
		add_to_stack(stack_a, (int)num, gc);
		j++;
	}
}

void	parse_arguments(int ac, char **av, t_stack *stack_a, t_gc **gc)
{
	int		i;
	char	**tmp_args;

	i = 1;
	while (i < ac)
	{
		tmp_args = ft_split(av[i], ' ', gc);
		if (!tmp_args[0])
			ft_error(gc);
		process_args(tmp_args, stack_a, gc);
		i++;
	}
}
