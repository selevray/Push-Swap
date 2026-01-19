#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <limits.h>
#include <stdlib.h>
#include <unistd.h>

// Structures
typedef struct s_node
{
    int value;
    int index;
    struct s_node *next;
} t_node;

typedef struct s_data
{
    t_node *pile_a;
    t_node *pile_b;
    int size_a;
    int size_b;
} t_data;

void swap(t_node **pile);
void reverse(t_node **pile);
void reverse_rotate(t_node **pile, int size);
t_node *detach_first(t_node **src, int size_src);
void    push(t_node **src, t_node **dest, int *size_src, int *size_dest);

void sa(t_data *data);
void sb(t_data *data);
void ss(t_data *data);
void pa(t_data *data);
void pb(t_data *data);
void ra(t_data *data);
void rb(t_data *data);
void rr(t_data *data);
void rra(t_data *data);
void rrb(t_data *data);
void rrr(t_data *data);

t_node *new_node(int value);
void add_top(t_node **top, t_node *new);
void add_bottom(t_node **top, t_node *new);
t_node *find_last(t_node *top);

int parse_arguments(int argc, char **argv, t_data *data);
void free_stack(t_node *pile, int size);

int has_duplicate(t_node *pile, int value, int size);
int is_valid_number(char *str);
long ft_atol(const char *str);
int find_min(t_node *pile, int size);
int is_sorted(t_data *data);
void bring_to_top(t_data *piles, int value);

void sort_two(t_data *data);
void sort_three(t_data *data);
void sort_five(t_data *data);
void index_stack(t_node *pile, int size, int *median);
void insertion_sort(t_data *data, int median);
void rotate_both_up(t_data *data, int *pos_b, int *pos_a);
void rotate_both_down(t_data *data, int pos_b, int pos_a);
void rotate_both(t_data *data, int *pos_b, int *pos_a);
void rotate_a(t_data *data, int pos);
void rotate_b(t_data *data, int pos);
int find_min_pos(t_data *data);
void find_best_move(t_data *data, int *pos_b, int *pos_a);
int find_target_pos(t_data *data, int b_index);
int calc_cost(t_data *data, int pos_b, int pos_a);
int get_index_at(t_node *pile, int pos);

char **ft_split(char const *str, char charset);
// void print_stack(t_data *data);

#endif