/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouriga <alouriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 00:55:45 by alouriga          #+#    #+#             */
/*   Updated: 2024/05/10 14:52:53 by alouriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	cheak_moves(char *s, t_stack **stack_a, t_stack **stack_b)
{
	if (!ft_strcmp(s, "pa\n"))
		return (pa(stack_a, stack_b), 0);
	else if (!ft_strcmp(s, "pb\n"))
		return (pb(stack_a, stack_b), 0);
	else if (!ft_strcmp(s, "ra\n"))
		return (ra(stack_a), 0);
	else if (!ft_strcmp(s, "rb\n"))
		return (rb(stack_b), 0);
	else if (!ft_strcmp(s, "rr\n"))
		return (rr(stack_a, stack_b), 0);
	else if (!ft_strcmp(s, "rra\n"))
		return (rra(stack_a), 0);
	else if (!ft_strcmp(s, "rrb\n"))
		return (rrb(stack_b), 0);
	else if (!ft_strcmp(s, "rrr\n"))
		return (rrr(stack_a, stack_b), 0);
	else if (!ft_strcmp(s, "sa\n"))
		return (sa(stack_a), 0);
	else if (!ft_strcmp(s, "sb\n"))
		return (sb(stack_b), 0);
	else if (!ft_strcmp(s, "ss\n"))
		return (ss(stack_a, stack_b), 0);
	else
		return (1);
}

int	reading(t_stack **stack_a, t_stack **stack_b)
{
	char	*s;
	int		i;

	while (1)
	{
		s = get_next_line(0);
		if (!s)
			break ;
		i = cheak_moves(s, stack_a, stack_b);
		if (i == 1)
		{
			if (s)
			{
				free(s);
				s = NULL;
			}
			write(2, "Error\n", 6);
			return (1);
		}
		free(s);
		s = NULL;
	}
	return (0);
}

void	cheak_stack(t_stack **a, t_stack **b)
{
	if (*b == NULL && !sort_stack(a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

void	add_to_stacka(t_stack **stack_a, char **p, t_slotlist *slots)
{
	int		i;
	t_stack	*nb;

	i = 0;
	while (p[i])
	{
		nb = ft_lstnew(ft_atoi(p[i]), slots);
		ft_lstadd_back(stack_a, nb);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_slotlist	*slots;
	int			i;

	stack_b = NULL;
	if (argc == 1)
		return (0);
	slots = start_session();
	if (slots == NULL)
		return (1);
	i = cheak(slots, argc, argv, &stack_a);
	if (i == 1)
	{
		close_session(&slots);
		return (write(2, "Error\n", 6), 1);
	}
	else if (i == 2)
		return (close_session(&slots), 0);
	i = reading(&stack_a, &stack_b);
	if (i == 0)
		cheak_stack(&stack_a, &stack_b);
	close_session(&slots);
}
