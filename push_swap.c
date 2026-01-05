// #include <unistd.h>
// #include <stdio.h>
// #include <fcntl.h>
// #include <string.h>


#include "push_swap.h"
#include <stdio.h>

#include "push_swap.h"
#include <stdio.h>

void print_stack(t_node *pile, char *name, int size)
{
    if (!pile)
    {
        ft_printf("%s: (vide)\n", name);
        return;
    }
    
    ft_printf("%s: ", name);
    t_node *current = pile;
    int i = 0;
    while (i < size)
    {
        ft_printf("%d ", current->value);
        current = current->next;
        i++;
    }
    ft_printf("\n");
}

int main(void)
{
    t_data data;
    t_node *node;
    
    data.pile_a = NULL;
    data.pile_b = NULL;
    data.size_a = 0;
    data.size_b = 0;
    
    ft_printf("=== TEST 1: Créer la pile A ===\n");
    
    node = new_node(5);
    add_top(&data.pile_a, node);
    data.size_a++;
    
    node = new_node(3);
    add_top(&data.pile_a, node);
    data.size_a++;
    
    node = new_node(8);
    add_top(&data.pile_a, node);
    data.size_a++;
    
    node = new_node(1);
    add_top(&data.pile_a, node);
    data.size_a++;
    
    print_stack(data.pile_a, "Pile A", data.size_a);
    print_stack(data.pile_b, "Pile B", data.size_b);
    
    ft_printf("\n=== TEST 2: SA (swap a) ===\n");
    sa(&data);
    print_stack(data.pile_a, "Pile A après SA", data.size_a);
    
    ft_printf("\n=== TEST 3: PB (push b) ===\n");
    pb(&data);
    print_stack(data.pile_a, "Pile A après PB", data.size_a);
    print_stack(data.pile_b, "Pile B après PB", data.size_b);
    
    ft_printf("\n=== TEST 4: PB encore ===\n");
    pb(&data);
    print_stack(data.pile_a, "Pile A après PB", data.size_a);
    print_stack(data.pile_b, "Pile B après PB", data.size_b);
    
    ft_printf("\n=== TEST 5: RA (rotate a) ===\n");
    ra(&data);
    print_stack(data.pile_a, "Pile A après RA", data.size_a);
    
    ft_printf("\n=== TEST 6: RB (rotate b) ===\n");
    rb(&data);
    print_stack(data.pile_b, "Pile B après RB", data.size_b);
    
    ft_printf("\n=== TEST 7: RRA (reverse rotate a) ===\n");
    rra(&data);
    print_stack(data.pile_a, "Pile A après RRA", data.size_a);
    
    ft_printf("\n=== TEST 8: PA (push a) ===\n");
    pa(&data);
    print_stack(data.pile_a, "Pile A après PA", data.size_a);
    print_stack(data.pile_b, "Pile B après PA", data.size_b);
    
    ft_printf("\n=== TEST 9: SS ===\n");
    ss(&data);
    print_stack(data.pile_a, "Pile A après SS", data.size_a);
    print_stack(data.pile_b, "Pile B après SS", data.size_b);
    
    ft_printf("\n=== TEST 10: RR ===\n");
    rr(&data);
    print_stack(data.pile_a, "Pile A après RR", data.size_a);
    print_stack(data.pile_b, "Pile B après RR", data.size_b);
    
    ft_printf("\n=== TEST 11: RRR ===\n");
    rrr(&data);
    print_stack(data.pile_a, "Pile A après RRR", data.size_a);
    print_stack(data.pile_b, "Pile B après RRR", data.size_b);
    
    ft_printf("\n=== FIN DES TESTS ===\n");
    
    return (0);
}

