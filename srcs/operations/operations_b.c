#include "push_swap.h"

void sb(t_data *data)
{
    if (data->size_b < 2)
        return ;
    
    swap(&data->pile_b);
	data->ops_count++;
    write(1, "sb\n", 3);
}

void rb(t_data *data)
{
    if (data->size_b < 2)
        return ;
    
    data->pile_b = data->pile_b->next;
	data->ops_count++;
    write (1, "rb\n", 3);
}

void rrb(t_data *data)
{
    t_node *last;

    if (data->size_b < 2)
        return ;
    last = find_last(data->pile_b);
    data->pile_b = last;
	data->ops_count++;
    write (1, "rrb\n", 4);
}

void pb(t_data *data)
{
    t_node *move;
    t_node *last_a;

    if (data->pile_a == NULL)
        return ;

    move = data->pile_a;
    
    if (data->size_a == 1)
        data->pile_a = NULL;
    else
    {
        last_a = find_last(data->pile_a);
        data->pile_a = data->pile_a->next;
        last_a->next = data->pile_a;
    }
    data->size_a--; 

    move->next = move;
    add_top(&data->pile_b, move);
    data->size_b++;
	data->ops_count++;

    write(1, "pb\n", 3);
}

