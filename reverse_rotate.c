/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouriga <alouriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 18:37:42 by alouriga          #+#    #+#             */
/*   Updated: 2024/04/07 10:25:53 by alouriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*last;
	t_stack	*second_last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = *stack;
	second_last = NULL;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *stack;
	*stack = last;
	current = *stack;
	print_indx(&current);
}

void	rra(t_stack **a)
{
	rev_rotate_stack(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	rev_rotate_stack(b);
	write(1, "rrb\n", 4);
}
