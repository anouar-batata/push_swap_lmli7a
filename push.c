/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouriga <alouriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 09:25:28 by alouriga          #+#    #+#             */
/*   Updated: 2024/04/07 15:49:08 by alouriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **stack_s, t_stack **stack_d)
{
	t_stack	*current;
	t_stack	*current_2;
	t_stack	*temp;

	temp = *stack_s;
	*stack_s = (*stack_s)->next;
	temp->next = *stack_d;
	*stack_d = temp;
	current = *stack_s;
	current_2 = *stack_d;
	print_indx(&current);
	print_indx(&current_2);
}

void	pb(t_stack **a, t_stack **b)
{
	push(a, b);
	write(1, "pb\n", 3);
}

void	pa(t_stack **a, t_stack **b)
{
	push(b, a);
	write(1, "pa\n", 3);
}
