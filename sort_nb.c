/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_nb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouriga <alouriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 00:34:34 by alouriga          #+#    #+#             */
/*   Updated: 2024/04/25 17:01:35 by alouriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	min_number(t_stack **a)
{
	int		i;
	t_stack	*node;
	t_stack	*curr;

	i = INT_MAX;
	node = NULL;
	curr = *a;
	while (curr)
	{
		if (curr->content < i)
		{
			i = curr->content;
			node = curr;
		}
		curr = curr->next;
	}
	return (node->index);
}

static void	sort_2_3_nb(t_stack **stack_a)
{
	t_stack	*tmp;

	tmp = *stack_a;
	if (nb_of_nodes(tmp) == 2)
		sa(&tmp);
	else
	{
		if (tmp->content > tmp->next->content)
			sa(&tmp);
		if (tmp->next->content > tmp->next->next->content)
			rra(&tmp);
		if (tmp->content > tmp->next->content)
			sa(&tmp);
	}
	*stack_a = tmp;
}

static void	sort_5_nb(t_stack **a, t_stack **b)
{
	int	j;
	int	k;

	k = min_number(a);
	while (nb_of_nodes(*a) > 3)
	{
		k = min_number(a);
		if (k <= nb_of_nodes(*a) / 2)
		{
			while (k--)
				ra(a);
		}
		else
		{
			j = nb_of_nodes(*a) - k;
			while (j--)
				rra(a);
		}
		pb(a, b);
	}
	sort_2_3_nb(a);
	while (*b)
		pa(a, b);
}

void	sort_p_nm(t_stack **stack_a, t_stack **stack_b)
{
	print_indx(stack_a);
	print_indx(stack_b);
	if (nb_of_nodes(*stack_a) == 2 || nb_of_nodes(*stack_a) == 3)
		sort_2_3_nb(stack_a);
	else if (nb_of_nodes(*stack_a) <= 5)
	{
		sort_5_nb(stack_a, stack_b);
	}
	else
	{
		first_sort(stack_a, stack_b);
		final_sort(stack_a, stack_b);
	}
}
