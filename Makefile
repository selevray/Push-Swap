# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zeloxx <zeloxx@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/19 15:31:37 by zeloxx            #+#    #+#              #
#    Updated: 2026/01/19 15:31:39 by zeloxx           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g3
INCLUDES	= -I./includes -I./bonus/includes

# Directories
SRCDIR		= srcs
OBJDIR		= objs
INCDIR		= includes
BNSDIR 		= bonus

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
BONUS_SRCS = $(BNSDIR)/main_bonus.c \
			 $(BNSDIR)/srcs/read_ops_bonus.c \
			 $(BNSDIR)/srcs/get_next_line_bonus.c \
			 $(BNSDIR)/srcs/get_next_line_utils_bonus.c

# Object files
OBJS = $(OBJDIR)/main.o \
	$(OBJDIR)/push_swap.o \
	$(OBJDIR)/sorting/sort_small.o \
	$(OBJDIR)/sorting/insertion_utils.o \
	$(OBJDIR)/sorting/insertion_exec.o \
	$(OBJDIR)/sorting/insertion.o \
	$(OBJDIR)/sorting/sort_and_index.o \
	$(OBJDIR)/utils/piles_utils.o \
	$(OBJDIR)/utils/utils.o \
	$(OBJDIR)/utils/exeption_utils.o \
	$(OBJDIR)/utils/ft_split.o \
	$(OBJDIR)/operations/operations_a.o \
	$(OBJDIR)/operations/operations_b.o \
	$(OBJDIR)/operations/operation_mix.o \
	$(OBJDIR)/utils/operation_utils.o


# Bonus object files
BONUS_OBJS = $(OBJDIR)/bonus/main_bonus.o \
			 $(OBJDIR)/bonus/read_ops_bonus.o \
			 $(OBJDIR)/bonus/get_next_line_bonus.o \
			 $(OBJDIR)/bonus/get_next_line_utils_bonus.o

# Header files
HEADERS		= $(INCDIR)/push_swap.h \
			  $(BNSDIR)/includes/checker_bonus.h

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(NAME) compilé avec succès"

$(OBJDIR)/main.o: main.c $(HEADERS)
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@


$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADERS)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@


$(OBJDIR)/bonus/%.o: $(BNSDIR)/%.c $(HEADERS)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJDIR)/bonus/%.o: $(BNSDIR)/srcs/%.c $(HEADERS)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

bonus: $(BONUS_OBJS) $(filter-out $(OBJDIR)/main.o,$(OBJS))
	$(CC) $(CFLAGS) $^ -o checker
	@echo "Bonus compilé avec succès"

clean:
	rm -rf $(OBJDIR)
	@echo "Fichiers objets supprimés"

fclean: clean
	rm -f $(NAME)
	rm -f checker
	rm -rf $(OBJDIR)/bonus
	@echo "Exécutable supprimé"

re: fclean all

.PHONY: all clean fclean re bonus fclean_bonus
