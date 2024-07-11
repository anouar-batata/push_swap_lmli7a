/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouriga <alouriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 10:35:38 by alouriga          #+#    #+#             */
/*   Updated: 2024/04/07 10:55:39 by alouriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cost_stack(t_stack **stack)
{
	t_stack	*current;
	int		nb;

	if (!stack)
		return ;
	current = *stack;
	nb = nb_of_nodes(*stack);
	while (current)
	{
		if ((current)->index <= nb_of_nodes(*stack) / 2)
		{
			current->cost = current->index;
		}
		else
			current->cost = (nb - current->index);
		current = current->next;
	}
}

void	get_position(t_stack *stack, int k)
{
	t_stack	*max_one;
	int		index;
	t_stack	*tmp;

	index = nb_of_nodes(stack) - 1;
	tmp = stack;
	while (index)
	{
		k = INT_MIN;
		tmp = stack;
		while (tmp)
		{
			if (tmp->content > k && tmp->pos == 0)
			{
				k = tmp->content;
				max_one = tmp;
				tmp = stack;
			}
			else
				tmp = tmp->next;
		}
		max_one->pos = index;
		index--;
	}
}
