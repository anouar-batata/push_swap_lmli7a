/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ckeak_error_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouriga <alouriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:20:01 by alouriga          #+#    #+#             */
/*   Updated: 2024/04/25 06:13:00 by alouriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	check_ch(char **s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] != NULL)
	{
		j = 0;
		while (s[i][j] != '\0')
		{
			if (!((s[i][j] >= '0' && s[i][j] <= '9')
			|| (s[i][j] == '+') || s[i][j] == '-'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	cheak_the_string(char **s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] != NULL)
	{
		j = 0;
		while (s[i][j] != '\0')
		{
			if ((s[i][j] == '-' || s[i][j] == '+') && j != 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	cheak(t_slotlist *slots, int argc, char *argv[], t_stack **stack_a)
{
	char	*string;
	char	**p;

	string = ft_strjoin(slots, argc, argv);
	if (!string)
		return (1);
	p = ft_split(slots, string, ' ');
	if (!p)
		return (1);
	if (check_ch(p) == 1)
		return (1);
	if (sign(p) == 1)
		return (1);
	if (cheak_the_string(p) == 1)
		return (1);
	if (over_flow(p) == 1)
		return (1);
	if (same_nb(p) == 1)
		return (1);
	add_to_stacka(stack_a, p, slots);
	return (0);
}
