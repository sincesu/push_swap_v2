
void    debug_print_stacks(t_stack *a, t_stack *b)
{
	t_node *tmp;
	
	printf("\n   [ STACK A (Size: %d) ]       [ STACK B (Size: %d) ]\n", a->size, b->size);
	printf("   --------------------       --------------------\n");
	
	t_node *tmp_a = a->head;
	t_node *tmp_b = b->head;

	while (tmp_a || tmp_b)
	{
		if (tmp_a) {
			printf("%10d", tmp_a->value);
			tmp_a = tmp_a->next;
		} else {
			printf("%10s", ".");
		}

		printf("           |   ");

		if (tmp_b) {
			printf("%10d", tmp_b->value);
			tmp_b = tmp_b->next;
		} else {
			printf("%10s", ".");
		}
		printf("\n");
	}
	printf("   -----------------------------------------------\n\n");
}

void    print_list(t_stack *stack)
{
	t_node  *tmp = stack->head;
	int     i;

	i = 0;
	printf("Stack Size: %d\n", stack->size);
	while (tmp != NULL)
	{
		printf("%d: %d \n", i, tmp->value);
		tmp = tmp->next;
		i++;
	}
}

int main(int ac, char **av)
{
	t_stack *a;
	t_stack *b;
	t_gc    *gc = NULL;

	if (ac < 2) return (0);
	
	a = ft_malloc(sizeof(t_stack), &gc);
	b = ft_malloc(sizeof(t_stack), &gc);
	a->head = NULL; a->size = 0;
	b->head = NULL; b->size = 0;
	
	parse_arguments(ac, av, a, &gc);

	printf("\n======= BAŞLANGIÇ DURUMU =======\n");
	debug_print_stacks(a, b);

	// TEST 1: Push B (A'dan B'ye at)
	printf(">>> TEST 1: PB (A'dan B'ye atiliyor)\n");
	pab(a, b, PB);
	debug_print_stacks(a, b);

	// TEST 2: Push B (Bir tane daha at)
	printf(">>> TEST 2: PB (Bir tane daha atiliyor)\n");
	pab(a, b, PB);
	debug_print_stacks(a, b);

	// TEST 3: Swap A (A'daki ilk ikiyi degistir)
	printf(">>> TEST 3: SA (A'daki 1. ve 2. yer degistiriyor)\n");
	sab(a, SA);
	debug_print_stacks(a, b);

	// TEST 4: Swap B (B'deki ilk ikiyi degistir)
	if (b->size >= 2)
	{
		printf(">>> TEST 4: SB (B'deki 1. ve 2. yer degistiriyor)\n");
		sab(b, SB);
		debug_print_stacks(a, b);
	}

	// TEST 5: Rotate A (A'nin basi sona gidiyor)
	printf(">>> TEST 5: RA (A'nin en ustundeki en alta gidiyor)\n");
	rab(a, RA);
	debug_print_stacks(a, b);

	// TEST 6: Reverse Rotate A (A'nin sonu basa geliyor)
	printf(">>> TEST 6: RRA (A'nin en altindaki en uste geliyor)\n");
	rrab(a, RRA);
	debug_print_stacks(a, b);

	// TEST 7: Push A (Hepsini geri topla)
	printf(">>> TEST 7: PA (B'den A'ya geri aliniyor)\n");
	while (b->size > 0)
	{
		pab(a, b, PA);
	}
	debug_print_stacks(a, b);
	print_list(a);
	ft_gc_clean(&gc);
	return (0);
}