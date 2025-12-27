NAME = push_swap

CC = cc

CFLAGS = -Wall -Werror -Wextra

CFILES =	main.c\
			ft_split.c\
			gc.c\
			libft_utils.c\
			operations.c\
			parser.c\
			quicksort.c\
			quicksort_utils.c\
			sort_utils.c\
			operations_utils.c
			
OBJS = $(CFILES:.c=.o)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)


all: $(NAME)

clean:
		@rm -f $(OBJS)

fclean: clean
		@rm -rf $(NAME) 

re: fclean all

.phony: re fclean clean all
 