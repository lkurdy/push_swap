/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkurdy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 13:31:02 by lkurdy            #+#    #+#             */
/*   Updated: 2022/05/11 22:30:07 by lkurdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	size(const char *str, char set)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (((str[i] != set) && (str[i + 1] == set))
			|| ((str[i] != set) && !str[i + 1]))
			j++;
		i++;
	}
	return (j);
}

static char	**ft_freesplit(char **dest, int j)
{
	while (j > 0)
	{
		j--;
		free(dest[j]);
	}
	free(dest);
	return (NULL);
}

static char	*ft_cpy(char *dest, const char *str, int n)
{
	int	i;

	i = 0;
	while (str[i] && i < n)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static char	**rempl(int *i, int *j, const char *s, char c)
{
	char	**dest;

	if (!s)
		return (NULL);
	dest = malloc(sizeof(const char *) * (size(s, c) + 1));
	*i = 0;
	*j = 0;
	return (dest);
}

char	**ft_split(const char *s, char c)
{
	char	**dest;
	int		i;
	int		j;
	int		g;

	dest = rempl(&i, &j, s, c);
	if (!dest)
		return (NULL);
	while (j < size(s, c) && s[i])
	{
		g = i;
		while ((s[i] != c) && s[i])
			i++;
		if (i)
		{
			dest[j] = malloc(sizeof(const char) * (i - g + 1));
			if (!dest[j])
				return (ft_freesplit(dest, j));
			dest[j] = ft_cpy(dest[j], &s[g], i - g);
			j++;
		}
		while ((s[i] == c) && s[i])
			i++;
	}
	return (dest[j] = 0, dest);
}
/*
int main()
{
	int	i;
	char **y;

	i = 0;
	y = ft_split(" la  la", ' ');
	while(i <= 2)
		printf("%s\n", y[i++]);
}
*/
