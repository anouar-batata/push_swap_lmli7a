/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_gnl_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouriga <alouriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 20:57:22 by alouriga          #+#    #+#             */
/*   Updated: 2024/04/25 08:06:54 by alouriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

// size_t	ft_strlen(char *s)
// {
// 	size_t	i;

// 	i = 0;
// 	while (s[i] != '\0')
// 		i++;
// 	return (i);
// }

void	*ft_free(char *reach)
{
	if (reach)
		free(reach);
	return (NULL);
}

char	*ft_strdup(char *src)
{
	char	*c;
	int		x;
	int		q;

	if (!src)
		return (NULL);
	x = ft_strlen(src);
	q = 0;
	c = (char *)malloc((x + 1) * sizeof(char));
	if (!c)
		return (NULL);
	while (src[q] != '\0')
	{
		c[q] = src[q];
		q++;
	}
	c[q] = '\0';
	return (c);
}

int	ft_strchr(char *s, int c)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == (char)c)
			return (1);
		s++;
	}
	return (0);
}

char	*ft_strjoinn(char *s1, char *s2)
{
	int		i;
	int		i1;
	int		i2;
	char	*p;

	if (!s1)
		return (ft_strdup(s2));
	i1 = ft_strlen(s1);
	i2 = ft_strlen(s2);
	p = (char *)malloc(sizeof(char) * (i1 + i2 + 1));
	i = 0;
	if (!p)
		return (free(s1), NULL);
	while (s1[i] != '\0')
	{
		p[i] = s1[i];
		i++;
	}
	i1 = 0;
	while (s2[i1] != '\0')
		p[i++] = s2[i1++];
	p[i] = '\0';
	return (free(s1), p);
}
