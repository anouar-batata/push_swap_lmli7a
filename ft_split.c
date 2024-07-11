/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouriga <alouriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 22:36:31 by alouriga          #+#    #+#             */
/*   Updated: 2024/04/08 10:35:16 by alouriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	nb_word(const char *st, char c)
{
	int	i;
	int	t;
	int	j;

	i = 0;
	t = 0;
	j = 0;
	while (st[j] != '\0')
	{
		if (st[j] != c && t == 0)
		{
			t = 1;
			i++;
		}
		else if (st[j] == c)
		{
			t = 0;
		}
		j++;
	}
	return (i);
}

static	char	*dimensional(t_slotlist *slots, const char *s, int d, int f)
{
	int		i;
	char	*p;

	i = 0;
	p = (char *)ft_malloc(slots, (f - d + 1) * sizeof(char));
	if (!p)
	{
		close_session(&slots);
		return (NULL);
	}
	while (d < f)
	{
		p[i] = s[d];
		i++;
		d++;
	}
	p[i] = '\0';
	return (p);
}

void	exiting(t_slotlist *slots)
{
	close_session(&slots);
	exit(1);
}

static char	**allocation(t_slotlist *slots, const char *s, size_t i, char c)
{
	int		v;
	size_t	j;
	char	**p;

	v = -1;
	j = 0;
	p = ft_malloc(slots, (nb_word(s, c) + 1) * sizeof(char *));
	if (!p)
		return (NULL);
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && v == -1)
			v = i;
		else if ((s[i] == c || i == ft_strlen(s)) && v >= 0)
		{
			p[j] = dimensional(slots, s, v, i);
			if (!p[j])
				exiting(slots);
			v = -1;
			j++;
		}
		i++;
	}
	p[j] = NULL;
	return (p);
}

char	**ft_split(t_slotlist *slots, char const *s, char c)
{
	size_t	i;
	int		v;
	size_t	j;

	v = -1;
	j = 0;
	i = 0;
	if (!s)
		return (NULL);
	return (allocation(slots, s, i, c));
}
