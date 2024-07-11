/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouriga <alouriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:31:19 by alouriga          #+#    #+#             */
/*   Updated: 2024/04/25 17:11:18 by alouriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	get_position(stack_a, INT_MIN);
	sort_p_nm(&stack_a, &stack_b);
	close_session(&slots);
}
