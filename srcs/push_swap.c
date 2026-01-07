#include "push_swap.h"

static void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static int	parse_single_string(char *str, t_data *data)
{
	char	**tab;
	int		i;
	int		number;
	t_node	*node;

	tab = ft_split(str, ' ');
	if (tab == NULL)
		return (0);
	i = 0;
	while (tab[i] != NULL)
	{
		number = ft_atol(tab[i]);
		node = new_node(number);
		if (node == NULL)
		{
			free_tab(tab);
			return (0);
		}
		add_bottom(&data->pile_a, node);
		data->size_a++;
		i++;
	}
	free_tab(tab);
	return (1);
}

static int	parse_multiple_args(int argc, char **argv, t_data *data)
{
	int		i;
	int		number;
	t_node	*node;

	i = 1;
	while (i < argc)
	{
		number = atoi(argv[i]);
		node = new_node(number);
		if (node == NULL)
			return (0);
		add_bottom(&data->pile_a, node);
		data->size_a++;
		i++;
	}
	return (1);
}
int	parse_arguments(int argc, char **argv, t_data *data)
{
	if (argc < 2)
		return (1);
	else if (argc == 2)
		return (parse_single_string(argv[1], data));
	else
		return (parse_multiple_args(argc, argv, data));
}
int	main(int argc, char *argv[])
{
	t_data	data;

	data.pile_a = NULL;
	data.pile_b = NULL;
	data.size_a = 0;
	data.size_b = 0;
	if (parse_arguments(argc, argv, &data))
	{
		write(2, "Error\n", 6);
		return (1);
	}
    // else
    // {
        
    // }
    print_stack(data.pile_a, "PILE A", data.size_a);
	return (0);
}
