#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>
# include <stddef.h>
# include <unistd.h>

typedef struct s_node
{
	int value;
	struct s_node *next;
} t_node;

typedef struct s_data
{
	t_node *pile_a;
	t_node *pile_b;
	int size_a;
	int size_b;
} t_data;

extern int	ft_printf(const char *format, ...) __attribute__((format(printf, 1,
						2)));

size_t		ft_strlen(const char *str);
int			ft_print_char(char c);
int			ft_print_str(char *string);
int			ft_print_nbr(int n);
int			ft_print_unsigned(unsigned int n);
int			ft_print_hex(unsigned long n, int format);
int			ft_numlen(long n);
int			ft_unumlen(unsigned int n);
int			ft_print_ptr(unsigned long n);
int			ft_format(char c, va_list args);
int			ft_printf(const char *format, ...);

t_node 	*new_node(int nb);
void	add_top(t_node **top, t_node *new);
void 	swap(t_node **pile);
t_node	*find_last(t_node *top);

// Operations pile a
void	sa(t_data *data);
void	ra(t_data *data);
void	rra(t_data *data);
void	pa(t_data *data);

// Operations  pile b
void	sb(t_data *data);
void	rb(t_data *data);
void	rrb(t_data *data);
void	pb(t_data *data);

// Mix operations
void	ss(t_data *data);
void	rr(t_data *data);
void	rrr(t_data *data);
#endif

