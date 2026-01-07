NAME		= push_swap
TEST_BUBBLE	= test_bubblesort
TEST_RADIX	= test_radix

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g
INCLUDES	= -I./includes

SRCDIR		= srcs
OBJDIR		= objs
UTILSDIR	= $(SRCDIR)/utils
ALGODIR		= $(SRCDIR)/algo
FTPRINTF	= $(SRCDIR)/ft_printf
OPERATIONS	= $(SRCDIR)/operations

COMMON_SRCS	= $(UTILSDIR)/piles_utils.c \
		  $(UTILSDIR)/utils.c \
		  $(UTILSDIR)/exeption_utils.c \
		  $(UTILSDIR)/ft_split.c \
		  $(OPERATIONS)/operations_a.c \
		  $(OPERATIONS)/operations_b.c \
		  $(OPERATIONS)/operation_mix.c \
		  $(FTPRINTF)/ft_printf.c \
		  $(FTPRINTF)/ft_printf_utils.c \
		  $(FTPRINTF)/ft_printf_utils2.c

SRCS		= $(SRCDIR)/push_swap.c \
		  $(ALGODIR)/bubblesort.c \
		  $(ALGODIR)/exception.c \
		  $(ALGODIR)/inserption.c \
		  $(ALGODIR)/radix.c \
		  $(COMMON_SRCS)

BUBBLE_SRCS	= $(ALGODIR)/bubblesort.c \
		  $(COMMON_SRCS)

RADIX_SRCS	= $(ALGODIR)/radix.c \
		  $(COMMON_SRCS)

OBJS		= $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
BUBBLE_OBJS	= $(BUBBLE_SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
RADIX_OBJS	= $(RADIX_SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

HEADERS		= includes/push_swap.h \
			  includes/ft_printf.h \
			  includes/operations.h \
			  includes/algorithms.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "✓ $(NAME) compilé avec succès"

test_bubble: $(BUBBLE_OBJS)
	$(CC) $(CFLAGS) $(BUBBLE_OBJS) -o $(TEST_BUBBLE)
	@echo "✓ $(TEST_BUBBLE) compilé avec succès"

test_radix: $(RADIX_OBJS)
	$(CC) $(CFLAGS) $(RADIX_OBJS) -o $(TEST_RADIX)
	@echo "✓ $(TEST_RADIX) compilé avec succès"

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADERS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJDIR)
	@echo "✓ Fichiers objets supprimés"

fclean: clean
	rm -f $(NAME) $(TEST_BUBBLE) $(TEST_RADIX)
	@echo "✓ Exécutables supprimés"

re: fclean all

.PHONY: all clean fclean re test_bubble test_radix
