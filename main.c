/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saincesu <saincesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 02:22:50 by saincesu          #+#    #+#             */
/*   Updated: 2025/11/22 08:07:23 by saincesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

#define SA 1
#define SB 2
#define SS 3
#define PA 4
#define PB 5
#define RA 6
#define RB 7
#define RRA 8
#define RRB 9

void	free_list(t_node **head)
{
	t_node	*tmp;

	tmp = NULL;
	while (*head != NULL)
	{
		tmp = *head;
		*head = (*head)->next;
		free(tmp);
	}
}

void	print_list(t_node **head)
{
	t_node	*tmp;
	int		i;

	i = 1;
	tmp = *head;
	while (tmp != NULL)
	{
		printf("%d: %d \n", i, tmp->value);
		tmp = tmp->next;
		i++;
	}
}

void	create_new_node(int num, t_node **head)
{
	t_node	*tmp;

	tmp = NULL;
	//malloc kontrolü
	if ((*head) == NULL)
	{
		(*head) = malloc(sizeof(t_node));
		(*head)->next = NULL;
		(*head)->value = num;
		return ;
	}
	tmp = *head;
	while ((tmp->next) != NULL)
		tmp = tmp->next;
	(tmp->next) = malloc(sizeof(t_node));
	//malloc kontrolü;
	tmp->next->value = num;
	tmp->next->next = NULL;
	return ;
}

void	sab(t_node *head, int option)
{
	if (!head || !head->next) //bu kontrolü silcen
	{
		printf("HEAD VEYA NEXTİ NULL\n");
		return ;
	}
	head->value += head->next->value;
	head->next->value -= head->value - head->next->value;
	head->value = head->value - head->next->value;
	if (option == SA)
		printf("sa\n");
	else if (option == SB)
		printf("sb\n");
}

void	ss(t_node *a, t_node *b)
{
	sab(a, SS);
	sab(b, SS);
	printf("ss\n");
}

void	pab(t_node **a, t_node **b, int option)
{
	t_node	*tmp;
	t_node	**x;
	t_node	**y;
	
	if ((option == PA && *b == NULL) || (option == PB && *a == NULL))
		return ;
	x = a;
	y = b;
	if (option == PB)
	{
		x = b;
		y = a;
		printf("pb\n");
	}
	else
		printf("pa\n");
	tmp = *x;
	*x = (*x)->next;
	tmp->next = *y;
	*y = tmp;
}

void	rab(t_node **a, t_node **b, int option)
{
	t_node	*tmp;
	t_node	*head;
	t_node	**x;

	x = a;
	if (option == RB)
	{
		x = b;
		printf("rb\n");
	}
	else
		printf("ra\n");
	if (!*x || !(*x)->next)
		return ;
	tmp = *x;
	head = (*x)->next;
	while ((*x)->next)
		*x = (*x)->next;
	(*x)->next = tmp;
	tmp->next = NULL;
	*x = head;
}

void rrab(t_node **a, t_node **b, int option)
{
	t_node	*tmp;
	t_node	*head;
	t_node	*last;
	t_node	**x;

	x = a;
	if (option == RRB)
	{
		x = b;
		printf("rrb\n");
	}
	else
		printf("rra\n");
	if (!x || !(*x)->next)
		return ;
	tmp = *x;
	head = *x;
	while (head->next)
	{
		if (head->next && !head->next->next)
			last = head;
		head = head->next;
	}
	*x = head;
	head->next = tmp;
	last->next = NULL;
}

int is_whitespace(int c)
{
	return (c == ' ' || c == '\t');
}

int is_digit(int c)
{
	return (c >= '0' && c <= '9');
}

int	is_all_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!is_digit(str[i]) && !is_whitespace(str[i]))
			return (0);
		i++;
	}
	return (1);
}

#include <unistd.h>
void	ft_error(t_node *head, int flag)
{
	if (flag == 1)
	{
		free_list(&head); //burayı düzenlersin. a b stacki için ayrı ayrı olcak.
	}
	write(2, "Error\n", 6);
	exit(1);
}

int main()
{
	char *str = "3 2 1 ";
	if (!is_all_digit(str))
		ft_error(NULL, 0);
}

// int main(int ac, char **av)
// {
// 	if (ac < 2)
// 	{
// 		printf("Hata\n");
// 		return 1;
// 	}
// 	int i = 0;
// 	while (av[i])
// 	{
// 		if (!is_all_digit(av[i++]))
// 			ft_error(NULL, 0);
// 	}
	// int i = 1;
	// t_node  *a = NULL;
	// while (i < ac)
	// {
	// 	create_new_node(atoi(av[i]), &a);
	// 	i++;
	// }
	// print_list(&a);
	// free_list(&a);
//  }

// int main(int ac, char **av)
// {
// 	t_node *head = NULL;
// 	t_node *a = NULL;
// 	t_node *b = NULL;
// 	int i = 1;
// 	create_new_node(4, &a);
// 	create_new_node(5, &a);
// 	rrab(&a, 0, 0);
// 	print_list(&a);
// 	free_list(&b);
// }