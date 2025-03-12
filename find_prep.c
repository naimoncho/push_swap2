#include "push_swap.h"

t_stack	*ft_findmin(t_stack *stacks)
{
	long	min;
	t_stack	*min_node;

	min = LONG_MAX;
	if (!stacks)
		return (NULL);
	while (stacks)
	{
		if (stacks->dataarg < min)
		{
			min = stacks->dataarg;
			min_node = stacks;
		}
		stacks = stacks->next;
	}
	return (min_node);
}

t_stack	*ft_findmax(t_stack *stacks)
{
	long	max;
	t_stack	*max_node;

	max = LONG_MIN;
	if (!stacks)
		return (NULL);
	while (stacks)
	{
		if (stacks->dataarg > max)
		{
			max = stacks->dataarg;
			max_node = stacks;
		}
		stacks = stacks->next;
	}
	return (max_node);
}

t_stack	*ft_lowercost(t_stack *stacks)
{
	t_stack	*best_node;
	int		best_score;
	int		moves;

	best_node = NULL;
	best_score = INT_MAX;
	while (stacks)
	{
		if (stacks->up_median && stacks->node->up_median)
			moves -= 1;
		else if (!stacks->up_median && !stacks->node->up_median)
			moves -= 1;
		moves = stacks->cost;
		if (moves < best_score)
		{
			best_score = moves;
			best_node = stacks;
		}
		stacks = stacks->next;
	}
	return (best_node);
}

void	ft_preppush(t_stack **stacks, t_stack *head, char name)
{
	while (*stacks != head)
	{
		if (name == 'a')
			if (head->up_median)
				ra(stacks);
			else
				rra(stacks);
		else if (name == 'b')
		{
			if (head->up_median)
				rb(stacks);
			else
				rrb(stacks);
		}
	}
}

void	ft_order_min_max(t_stack **a)
{
	t_stack *min_node;

	min_node = ft_findmin(*a);
	if (ft_stackorder(*a))
		return ;
	while ((*a)->dataarg != min_node->dataarg)
	{
		if(min_node->up_median)
			ra(a);
		else
			rra(a);
	}
}
