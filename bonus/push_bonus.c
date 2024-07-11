/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouriga <alouriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 09:25:28 by alouriga          #+#    #+#             */
/*   Updated: 2024/04/25 05:29:57 by alouriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	push(t_stack **stack_s, t_stack **stack_d)
{
	t_stack	*current;
	t_stack	*current_2;
	t_stack	*temp;

	if (!stack_s || !*stack_s)
		return ;
	temp = *stack_s;
	*stack_s = (*stack_s)->next;
	temp->next = *stack_d;
	*stack_d = temp;
	current = *stack_s;
	current_2 = *stack_d;
}

void	pb(t_stack **a, t_stack **b)
{
	push(a, b);
}

void	pa(t_stack **a, t_stack **b)
{
	push(b, a);
}
