/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saincesu <saincesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 00:17:47 by saincesu          #+#    #+#             */
/*   Updated: 2025/12/28 00:17:48 by saincesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static char	*ft_substr(char const *s, unsigned int start, size_t len, t_gc **gc)
{
	char	*buffer;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		len = 0;
	else if (ft_strlen(s) < len + start)
		len = ft_strlen(s) - start;
	buffer = ft_malloc((len + 1) * sizeof(char), gc);
	i = 0;
	while (i < len && s[start + i])
	{
		buffer[i] = s[start + i];
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}

static int	ft_wordcount(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if ((s[i] != c && s[i + 1] == c) || (s[i] != c && s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static int	ft_wordlen(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char	**ft_split(char const *s, char c, t_gc **gc)
{
	int		i;
	int		j;
	int		x;
	char	**split;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	x = ft_wordcount(s, c);
	split = ft_malloc(sizeof(char *) * (x + 1), gc);
	while (i < x)
	{
		while (s[j] == c)
			j++;
		split[i] = ft_substr(s, j, ft_wordlen(&s[j], c), gc);
		if (!split[i])
			return (NULL);
		j += ft_wordlen(&s[j], c);
		i++;
	}
	split[i] = NULL;
	return (split);
}
