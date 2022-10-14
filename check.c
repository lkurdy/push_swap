/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkurdy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:34:42 by lkurdy            #+#    #+#             */
/*   Updated: 2022/06/08 15:34:44 by lkurdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_a(t_list **a)
{
	t_list	*l;

	l = *a;
	while (l && l->next)
	{
		if (l->value > l->next->value)
			return (0);
		l = l->next;
	}
	return (1);
}

int	check_b(t_list **b)
{
	t_list	*l;

	l = *b;
	while (l && l->next)
	{
		if (l->value < l->next->value)
			return (0);
		l = l->next;
	}
	return (1);
}

int	check_min(t_list **a)
{
	int		d;
	t_list	*l;

	l = *a;
	d = l->value;
	while (l)
	{
		if (l->value < d)
			d = l->value;
		l = l->next;
	}
	return (d);
}

int	check_max(t_list **a)
{
	t_list	*l;
	int		d;

	l = *a;
	d = l->value;
	while (l)
	{
		if (l->value > d)
			d = l->value;
		l = l->next;
	}
	return (d);
}
