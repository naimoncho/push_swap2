#include "push_swap.h"

static void	ft_rboth(t_stack **a, t_stack **b, t_stack *lower)
{
	while (*b != lower->node && *a != lower)
		rr(a, b);
	ft_index(*a);
	ft_index(*b);
}

static void	ft_rrboth(t_stack **a, t_stack **b, t_stack *lower)
{
	while (*b != lower->node && *a != lower)
		rrr(a, b);
	ft_index(*a);
	ft_index(*b);
}


static void	ft_movea(t_stack **a, t_stack **b)
{
	t_stack	*lowernode;

	if (!a || !*a || !b) 
		return ;
	lowernode = ft_lowercost(*a);
	if (!lowernode || !lowernode->node)
		return ;
	if (lowernode->up_median && lowernode->node->up_median)
		ft_rboth(a, b, lowernode);
	else if (!(lowernode->up_median) && !(lowernode->node->up_median))
		ft_rrboth(a, b, lowernode);
	ft_preppush(a, lowernode, 'a');
	ft_preppush(b, lowernode->node, 'b');
	pb(b, a);
}

static void	ft_moveb(t_stack **a, t_stack **b)
{
	t_stack *cheapest_node;

	if (!a || !*a || !b) 
		return ;
	cheapest_node = ft_lowercost(*b);
	if (!cheapest_node)
		return ;
	ft_preppush(a, cheapest_node, 'a');
	pa(a, b);
}

void	ft_sort_stacks(t_stack **a, t_stack **b)
{
	while (*a && ft_lstlen_ps(*a) > 3)
	{
		if ((*a)->dataarg < ft_find_median(*a))
			pb(a, b);
		else
			ra(a);
	}
	ft_sort_three(a);
	while (*b)
	{
		ft_init_nodesa(*a, *b);
		ft_movea(a, b);
	}
	ft_order_min_max(a);
}