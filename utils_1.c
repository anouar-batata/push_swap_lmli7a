/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouriga <alouriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 21:32:58 by alouriga          #+#    #+#             */
/*   Updated: 2024/05/10 15:12:25 by alouriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi(const char *str)
{
	int					i;
	int					sign;
	long				result;
	long				result1;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign *= -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result1 = result * 10 + (str[i] - '0');
		if ((result1 > INT_MAX && sign == 1) || (result1 * sign < INT_MIN))
			return (9999999999999);
		result = result1;
		i++;
	}
	if (result == 0 && str[i - 1] != '0')
		return (9999999999999);
	return (result * sign);
}

static char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	i1;

	i = 0;
	i1 = 0;
	while (dest[i] != '\0')
		i++;
	while (src[i1] != '\0')
	{
		dest[i] = src[i1];
		i++;
		i1++;
	}
	dest[i] = '\0';
	return (dest);
}

void	check_sp(char *str)
{
	int	i;
	int	count;
	int	len;

	i = 0;
	count = 0;
	len = ft_strlen(str);
	while (str[i++] == ' ')
		count++;
	if (count == len)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
}

char	*ft_strjoin(t_slotlist *slots, int argc, char *argv[])
{
	size_t	t;
	int		i;
	char	*str;

	i = 0;
	t = 0;
	while (argv[++i])
		t += ft_strlen(argv[i]);
	t += argc - 1;
	str = ft_malloc(slots, t + 1);
	if (!str)
		return (NULL);
	str[0] = '\0';
	i = 1;
	while (argv[i])
	{
		check_sp(argv[i]);
		if (argv[i][0] == '\0')
			return (NULL);
		ft_strcat(str, argv[i]);
		if (i < argc - 1)
			ft_strcat(str, " ");
		i++;
	}
	return (str);
}

size_t	ft_strlen(const char *s)
{
	size_t	j;

	j = 0;
	while (s[j] != '\0')
		j++;
	return (j);
}
