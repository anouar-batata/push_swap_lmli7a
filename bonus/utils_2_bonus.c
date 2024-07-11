/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouriga <alouriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 01:37:38 by alouriga          #+#    #+#             */
/*   Updated: 2024/05/03 19:19:27 by alouriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

t_stack	*ft_lstnew(int content, t_slotlist *slots)
{
	t_stack	*p;

	p = (t_stack *)ft_malloc(slots, sizeof(t_stack));
	if (!p)
		return (close_session(&slots), NULL);
	p ->content = content;
	p ->next = NULL;
	p->pos = 0;
	return (p);
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	if (!lst || !new)
		return ;
	if (ft_lstlast(*lst))
	{
		ft_lstlast(*lst)->next = new;
	}
	else
		*lst = new;
}

t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (0);
	while (lst)
	{
		if (lst->next == NULL)
		{
			return (lst);
		}
		lst = lst->next;
	}
	return (0);
}

void	print_indx(t_stack **stack_a)
{
	int		i;
	t_stack	*curr;

	if (*stack_a == NULL)
		return ;
	i = 0;
	curr = *stack_a;
	while (curr)
	{
		(curr)->index = i;
		i++;
		curr = curr->next;
	}
}

int	nb_of_nodes(t_stack *stack)
{
	int	i;

	if (!stack)
		return (0);
	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}
