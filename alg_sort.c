/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouriga <alouriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:44:17 by alouriga          #+#    #+#             */
/*   Updated: 2024/07/09 17:38:55 by alouriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>


void ft_lstiter(t_stack *node)
{
	if (!node)
		return ;
	while (node)
	{
		printf("%i\n", node->content);
		node = node->next;
	}
}

static int	find_max_number(t_stack *b)
{
	int		i;
	t_stack	*node;
	t_stack	*curr;

	i = INT_MIN;
	node = NULL;
	curr = b;
	cost_stack(&b);
	while (curr)
	{
		if (curr->content >= i)
		{
			i = curr->content;
			node = curr;
		}
		curr = curr->next;
	}
	return (node->index);
}

void	first_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	x;

	i = 0;
	if (nb_of_nodes(*stack_a) <= 100)
		x = 16;
	else if (nb_of_nodes(*stack_a) > 100)
		x = 34;
	while (*stack_a)
	{
		if ((*stack_a)->pos <= i)
		{
			pb(stack_a, stack_b);
			i++;
		}
		else if ((*stack_a)->pos <= i + x)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
			i++;
		}
		else
			ra(stack_a);
	}
}

void	final_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	curr;
	int	k;

	while ((*stack_b))
	{
		printf("-----\n");
		ft_lstiter(*stack_b);
		printf("-----\n");
		ft_lstiter(*stack_a);
		printf("-----\n");
		print_indx(stack_b);
		curr = find_max_number(*stack_b);
		if (curr <= nb_of_nodes(*stack_b) / 2)
		{
			while (curr-- > 0)
				rb(stack_b);
			pa(stack_a, stack_b);
		}
		else if (curr > nb_of_nodes(*stack_b) / 2)
		{
			k = nb_of_nodes(*stack_b) - curr;
			while (k > 0)
			{
				rrb(stack_b);
				k--;
			}
			pa(stack_a, stack_b);
		}
	}
}
