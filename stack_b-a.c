#include "push_swap.h"

static void	ft_set_b(t_stack *a, t_stack *b)
{
	t_stack	*node_a;
	t_stack	*set_node;
	long	best_index;

	while (b)
	{
		best_index = LONG_MIN;
		set_node =  NULL;
		node_a = a;
		while (node_a)
		{
			if(node_a->dataarg < b->dataarg && node_a->dataarg > best_index)
			{
				best_index = node_a->dataarg;
				set_node = node_a;
			}
			node_a = node_a->next;
		}
		if (set_node == NULL)
			b->node = ft_findmax(b);
		else
			b->node = set_node;
		b = b->next;
	}
}
void	ft_init_nodesb(t_stack *a, t_stack *b)
{
	ft_index(a);
	ft_index(b);
	ft_set_b(a, b);
}
static void ft_sort_array(int *arr, int size)
{
	int i;
	int j;
	int temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}
int ft_find_median(t_stack *a)
{
	int		i;
	int		size;
	int		*values;
	t_stack	*temp;

	if (!a)
		return 0;
	size = ft_lstlen_ps(a);
	values = malloc(sizeof(int) * size);
	if (!values)
		return 0;
	i = 0;
	temp = a;
	while (temp)
	{
		values[i] = temp->dataarg;
		temp = temp->next;
		i++;
	}
	ft_sort_array(values, size);
	int median = values[size / 2];
	free(values);
	return median;
}
