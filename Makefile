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
CFLAGS		= -Wall -Wextra -Werror -g
INCLUDES	= -I./includes

# Directories
SRCDIR		= srcs
OBJDIR		= objs
INCDIR		= includes

# Source files
SRCS		= main.c \
			  $(SRCDIR)/push_swap.c \
			  $(SRCDIR)/algo/bubblesort.c \
			  $(SRCDIR)/algo/exception.c \
			  $(SRCDIR)/algo/inserption.c \
			  $(SRCDIR)/algo/radix.c \
			  $(SRCDIR)/utils/piles_utils.c \
			  $(SRCDIR)/utils/utils.c \
			  $(SRCDIR)/utils/exeption_utils.c \
			  $(SRCDIR)/utils/ft_split.c \
			  $(SRCDIR)/operations/operations_a.c \
			  $(SRCDIR)/operations/operations_b.c \
			  $(SRCDIR)/operations/operation_mix.c \
			  $(SRCDIR)/ft_printf/ft_printf.c \
			  $(SRCDIR)/ft_printf/ft_printf_utils.c \
			  $(SRCDIR)/ft_printf/ft_printf_utils2.c

# Object files
OBJS		= $(OBJDIR)/main.o \
			  $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(filter $(SRCDIR)/%,$(SRCS)))

# Header files
HEADERS		= $(INCDIR)/push_swap.h \
			  $(INCDIR)/ft_printf.h \
			  $(INCDIR)/operations.h \
			  $(INCDIR)/algorithms.h

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

clean:
	@rm -rf $(OBJDIR)
	@echo "✓ Fichiers objets supprimés"

fclean: clean
	@rm -f $(NAME)
	@echo "✓ Exécutable supprimé"

re: fclean all

.PHONY: all clean fclean re
