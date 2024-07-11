/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouriga <alouriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 09:54:04 by alouriga          #+#    #+#             */
/*   Updated: 2024/04/25 05:31:02 by alouriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
}

void	sa(t_stack **a)
{
	swap(a);
}

void	sb(t_stack **b)
{
	swap(b);
}

void	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
}
