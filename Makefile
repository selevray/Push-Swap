NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

SRCS		= push_swap.c \
			  operations_a.c \
			  operations_b.c \
			  operation_mix.c \
			  piles_utils.c \
			  ft_printf.c \
			  ft_printf_utils.c \
			  ft_printf_utils2.c

OBJS		= $(SRCS:.c=.o)

HEADER		= push_swap.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
