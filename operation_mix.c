#include "push_swap.h"

void ss(t_data *data)
{
    if (data->size_a < 2 && data->size_b < 2)
        return ;
    
    if (data->size_a >= 2)
        swap(&data->pile_a);
    
    if (data->size_b >= 2)
        swap(&data->pile_b);
    
    write(1, "ss\n", 3);
}

void rr(t_data *data)
{
    if (data->size_a < 2 && data->size_b < 2)
        return ;
    
    if (data->size_a >= 2)
        data->pile_a = data->pile_a->next;
    
    if (data->size_b >= 2)
        data->pile_b = data->pile_b->next;
    
    write(1, "rr\n", 3);
}

void rrr(t_data *data)
{
    t_node *last_a;
    t_node *last_b;
    
    if (data->size_a < 2 && data->size_b < 2)
        return ;
    
    if (data->size_a >= 2)
    {
        last_a = find_last(data->pile_a);
        data->pile_a = last_a;
    }
    
    if (data->size_b >= 2)
    {
        last_b = find_last(data->pile_b);
        data->pile_b = last_b;
    }
    
    write(1, "rrr\n", 4);
}