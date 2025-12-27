/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saincesu <saincesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 01:34:50 by saincesu          #+#    #+#             */
/*   Updated: 2025/12/28 01:35:06 by saincesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

void	ft_gc_clean(t_gc **gc)
{
	t_gc	*tmp;
	t_gc	*head;

	head = *gc;
	while (head)
	{
		tmp = head;
		head = head->next;
		if (tmp->ptr)
			free(tmp->ptr);
		free(tmp);
	}
	*gc = NULL;
}

void	*ft_malloc(size_t size, t_gc **gc)
{
	void	*ptr;
	t_gc	*new_node;

	ptr = malloc(size);
	if (!ptr)
	{
		ft_gc_clean(gc);
		write(2, "Error\n", 6);
		exit(1);
	}
	new_node = malloc(sizeof(t_gc));
	if (!new_node)
	{
		free(ptr);
		ft_gc_clean(gc);
		write(2, "Error\n", 6);
		exit(1);
	}
	new_node->ptr = ptr;
	new_node->next = *gc;
	*gc = new_node;
	return (ptr);
}

void	ft_error(t_gc **gc)
{
	ft_gc_clean(gc);
	write(2, "Error\n", 6);
	exit(1);
}
