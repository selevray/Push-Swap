# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bzeloxx <bzeloxx@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/08                          #+#    #+#                  #
#    Updated: 2026/01/08                         ###   ########.fr            #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g3
INCLUDES	= -I./includes

# Directories
SRCDIR		= srcs
OBJDIR		= objs
INCDIR		= includes

# Source files
SRCS		= main.c \
			  $(SRCDIR)/push_swap.c \
			  $(SRCDIR)/sorting/sort_small.c \
			  $(SRCDIR)/sorting/insertion_utils.c \
			  $(SRCDIR)/sorting/insertion_exec.c \
			  $(SRCDIR)/sorting/insertion.c \
			  $(SRCDIR)/sorting/sort_and_index.c \
			  $(SRCDIR)/utils/piles_utils.c \
			  $(SRCDIR)/utils/utils.c \
			  $(SRCDIR)/utils/exeption_utils.c \
			  $(SRCDIR)/utils/ft_split.c \
			  $(SRCDIR)/operations/operations_a.c \
			  $(SRCDIR)/operations/operations_b.c \
			  $(SRCDIR)/operations/operation_mix.c \
          	  $(SRCDIR)/utils/operation_utils.c \

# Bonus source files
BONUS_SRCS = $(SRCDIR)/bonus/checker.c \
             $(SRCDIR)/bonus/read_ops.c \
			 $(SRCDIR)/bonus/get-next-line/get_next_line.c \
			 $(SRCDIR)/bonus/get-next-line/get_next_line_utils.c \
             $(COMMON_SRCS)

# Object files
OBJS		= $(OBJDIR)/main.o \
			  $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(filter $(SRCDIR)/%,$(SRCS)))

# Bonus object files
BONUS_OBJS = $(patsubst $(SRCDIR)/bonus/%.c,$(OBJDIR)/bonus/%.o,$(filter $(SRCDIR)/bonus/%,$(BONUS_SRCS)))
BONUS_OBJS += $(patsubst $(SRCDIR)/bonus/get-next-line/%.c,$(OBJDIR)/bonus/get-next-line/%.o,$(filter $(SRCDIR)/bonus/get-next-line/%,$(BONUS_SRCS)))

# Header files
HEADERS		= $(INCDIR)/push_swap.h \
			  $(INCDIR)/operations.h \
			  $(INCDIR)/algorithms.h \
			  $(INCDIR)/bonus/checker.h

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "✓ $(NAME) compilé avec succès"

$(OBJDIR)/main.o: main.c $(HEADERS)
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@


$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADERS)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJDIR)/bonus/%.o: $(SRCDIR)/bonus/%.c $(HEADERS)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJDIR)/bonus/get-next-line/%.o: $(SRCDIR)/bonus/get-next-line/%.c $(HEADERS)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

bonus: $(BONUS_OBJS) $(filter-out $(OBJDIR)/main.o,$(OBJS))
	@$(CC) $(CFLAGS) $^ -o checker
	@echo "✓ Bonus compilé avec succès"

clean:
	@rm -rf $(OBJDIR)
	@echo "✓ Fichiers objets supprimés"

fclean_bonus:
	@rm -f checker
	@rm -rf $(OBJDIR)/bonus
	@echo "✓ Fichiers bonus et checker supprimés"

fclean: clean
	@rm -f $(NAME)
	@echo "✓ Exécutable supprimé"

re: fclean all

.PHONY: all clean fclean re bonus fclean_bonus
