/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saincesu <saincesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 00:02:17 by saincesu          #+#    #+#             */
/*   Updated: 2025/12/28 02:16:26 by saincesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

# define SA 1
# define SB 2
# define SS 3
# define PA 4
# define PB 5
# define RA 6
# define RB 7
# define RRA 8
# define RRB 9

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	int		size;
}	t_stack;

typedef struct s_gc
{
	void			*ptr;
	struct s_gc		*next;
}	t_gc;

void	parse_arguments(int ac, char **av, t_stack *stack_a, t_gc **gc);
char	**ft_split(char const *s, char c, t_gc **gc);
int		is_whitespace(int c);
int		is_digit(int c);
int		is_all_digit(char *str);
long	ft_atol(const char *str);
void	ft_gc_clean(t_gc **gc);
void	*ft_malloc(size_t size, t_gc **gc);
void	ft_error(t_gc **gc);
void	sab(t_stack *stack, int option);
void	ss(t_stack *a, t_stack *b);
void	pab(t_stack *a, t_stack *b, int option);
void	rab(t_stack *stack, int option);
void	rrab(t_stack *stack, int option);
int		is_sorted(t_node *head);
void	sort_three(t_stack *stack);
void	sort_four_and_five(t_stack *a, t_stack *b);
void	sort_int_array(int *arr, int size);
int		quicksort_a(t_stack *a, t_stack *b, int len, t_gc **gc);
void	do_push(t_stack *from, t_stack *to);
int		partition_stack_a(t_stack *a, t_stack *b, int len, int pivot);
int		partition_stack_b(t_stack *a, t_stack *b, int len, int pivot);

#endif