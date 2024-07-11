/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouriga <alouriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 09:54:04 by alouriga          #+#    #+#             */
/*   Updated: 2024/04/07 10:33:52 by alouriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*current;
	int		first;
	int		second;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	current = *stack;
	first = (*stack)->content;
	second = (*stack)->next->content;
	current->content = second;
	current->next->content = first;
	current = *stack;
	print_indx(&current);
}

void	sa(t_stack **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
