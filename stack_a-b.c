#include "push_swap.h"

static void	ft_set_a(t_stack *a, t_stack *b)
{
	t_stack	*node_b;
	t_stack	*set_node;
	long	best_index;

	while (a)
	{
		best_index = LONG_MIN;
		set_node = NULL;
		node_b = b;
		while (node_b)
		{
			if(node_b->dataarg < a->dataarg && node_b->dataarg > best_index)
			{
				best_index = node_b->dataarg;
				set_node = node_b;
			}
			node_b = node_b->next;
		}
		if (set_node == NULL)
			a->node = ft_findmax(b);
		else
			a->node = set_node;
		a = a->next;
	}
}

static void	ft_analyse(t_stack *a, t_stack *b)
{
	int	count1;
	int	count2;
	t_stack *current_a;

	count1 = ft_lstlen_ps(a);
	count2 = ft_lstlen_ps(b);
	current_a = a;
	while (current_a)
	{
		if (!current_a->node)
		{
			current_a = current_a->next;
			continue ;
		}
		current_a->cost = current_a->index;
		if (!(current_a->up_median))
			current_a->cost = count1 - current_a->index;
		if (current_a->node->up_median)
			current_a->cost += current_a->node->index;
		else
		current_a->cost += count2 - current_a->node->index;
		current_a = current_a->next;
	}
}

void	ft_index(t_stack *stacks)
{
	int	i;
	int	med;

	i = 0;
	if (!stacks)
		return ;
	med = ft_lstlen_ps(stacks) / 2;
	while (stacks)
	{
		stacks->index = i;
		if (i <= med)
			stacks->up_median = true;
		else
			stacks->up_median = false;
		stacks = stacks->next;
		i ++;
	}
}

void	ft_cheapest(t_stack *stacks)
{
	t_stack	*cheapest_node;
	long	value;

	if (!stacks)
		return ;
	value = LONG_MAX;
	while (stacks)
	{
		if (stacks->cost < value)
		{
			value = stacks->cost;
			cheapest_node = stacks;
		}
		stacks = stacks->next;
	}
	cheapest_node->lowercost = true;
}

void	ft_init_nodesa(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return ;
	ft_index(a);
	ft_index(b);
	ft_set_a(a, b);
	ft_analyse(a, b);
	ft_cheapest(a);
}

