/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouriga <alouriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 13:52:02 by alouriga          #+#    #+#             */
/*   Updated: 2024/04/25 05:30:54 by alouriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*first;
	t_stack	*seconde;
	t_stack	*current;

	if (!stack || nb_of_nodes(*stack) < 2 || !*stack || ! (*stack)->next)
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
}

void	ra(t_stack **stack_a)
{
	rotate(stack_a);
}

void	rb(t_stack **stack_b)
{
	rotate(stack_b);
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
}
