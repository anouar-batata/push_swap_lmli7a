/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouriga <alouriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 10:35:38 by alouriga          #+#    #+#             */
/*   Updated: 2024/04/25 08:28:05 by alouriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && (s1[i] != '\0' || s2[i] != '\0'))
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

int	sort_stack(t_stack **a)
{
	int	i;

	i = 0;
	while ((*a)->next != NULL)
	{
		if ((*a)->content > (*a)->next->content)
			return (1);
		*a = (*a)->next;
	}
	return (0);
}
