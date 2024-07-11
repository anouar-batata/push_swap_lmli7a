/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouriga <alouriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 13:52:02 by alouriga          #+#    #+#             */
/*   Updated: 2024/04/07 10:27:40 by alouriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*first;
	t_stack	*seconde;
	t_stack	*current;

	if (!stack || nb_of_nodes(*stack) < 2)
		return ;
	first = *stack;
	seconde = first->next;
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	last->next = first;
	first->next = NULL;
	*stack = seconde;
	current = *stack;
	print_indx(&current);
}

void	ra(t_stack **stack_a)
{
	rotate(stack_a);
	write(1, "ra\n", 3);
}

void	rb(t_stack **stack_b)
{
	rotate(stack_b);
	write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
