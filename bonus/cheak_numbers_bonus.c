/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheak_numbers_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouriga <alouriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:56:16 by alouriga          #+#    #+#             */
/*   Updated: 2024/04/24 20:47:30 by alouriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	sign(char **arr)
{
	int	i;
	int	j;
	int	count_sing;

	i = 0;
	while (arr[i] != NULL)
	{
		count_sing = 0;
		j = 0;
		while (arr[i][j] != '\0')
		{
			if (arr[i][j] == '+' || arr[i][j] == '-')
				count_sing++;
			j++;
		}
		if (count_sing >= 2)
			return (1);
		i++;
	}
	return (0);
}

int	same_nb(char **arr1)
{
	int	i;
	int	j;

	i = 0;
	while (arr1[i] != NULL)
	{
		j = i + 1;
		while (arr1[j] != NULL)
		{
			if (ft_atoi(arr1[i]) == ft_atoi(arr1[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	sort_nb(char **arr2)
{
	int	i;

	i = 0;
	while (arr2[i + 1] != NULL)
	{
		if (ft_atoi(arr2[i]) > ft_atoi(arr2[i + 1]))
			return (0);
		i++;
	}
	return (1);
}

int	over_flow(char **arr3)
{
	int	i;

	i = 0;
	while (arr3[i] != NULL)
	{
		if (ft_atoi(arr3[i]) == 9999999999999)
			return (1);
		i++;
	}
	return (0);
}
