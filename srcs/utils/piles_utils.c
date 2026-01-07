#include "push_swap.h"

t_node	*new_node(int value)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = NULL;
	return (new);
}

t_node	*find_last(t_node *top)
{
	t_node	*current;

	if (top == NULL)
		return (NULL);
	current = top;
	while (current->next != top)
		current = current->next;
	return (current);
}

void	add_top(t_node **top, t_node *new)
{
	t_node	*last;

	if (*top == NULL)
	{
		*top = new;
		new->next = new;
		return ;
	}
	last = find_last(*top);
	new->next = *top;
	last->next = new;
	*top = new;
}

void	swap(t_node **pile)
{
	t_node	*first;
	t_node	*second;
	t_node	*last;

	if (*pile == NULL || (*pile)->next == *pile)
		return ;
	first = *pile;
	second = first->next;
	last = find_last(*pile);
	first->next = second->next;
	second->next = first;
	last->next = second;
	*pile = second;
}

void	add_bottom(t_node **top, t_node *new)
{
	t_node *last;

	if (*top == NULL)
	{
		*top = new;
		new->next = new;
		return ;
	}

    last = find_last(*top);
    new->next = *top;
    last->next = new;
}