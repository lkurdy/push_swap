/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkurdy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:43:31 by lkurdy            #+#    #+#             */
/*   Updated: 2022/06/08 17:47:22 by lkurdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_duplicate(int num, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_isnum(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

static char	**temp(int *i, int argc, char **argv)
{
	char	**list;

	*i = 0;
	if (argc == 2)
		list = ft_split(argv[1], ' ');
	else
	{
		*i = 1;
		list = argv;
	}
	return (list);
}

int	ft_check_args(int argc, char **argv)
{
	int		i;
	long	tmp;
	char	**list;	

	list = temp(&i, argc, argv);
	while (list[i])
	{
		tmp = ft_atoi(list[i]);
		if (!ft_isnum(list[i]) || ft_duplicate(tmp, list, i)
			|| tmp < -2147483648 || tmp > 2147483647)
		{
			write(2, "Error\n", 6);
			if (argc == 2)
				ft_free(list);
			return (0);
		}
		i++;
	}
	if (argc == 2)
		ft_free(list);
	return (1);
}
