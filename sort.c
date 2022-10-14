/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkurdy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 16:17:46 by lkurdy            #+#    #+#             */
/*   Updated: 2022/06/08 16:18:06 by lkurdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_a(t_list **a, int a_low, int a_high)
{
	t_list	*l;

	l = *a;
	if (l->value == a_high && l->next->value == a_low)
		return (0);
	else if (l->value > l->next->value)
	{
		sa(a);
		return (1);
	}
	return (0);
}

int	sort_b(t_list **b, int b_low, int b_high)
{
	t_list	*l;

	l = *b;
	if (l->value == b_low && l->next->value == b_high)
		return (0);
	else if (l->value < l->next->value)
	{
		sb(b);
		return (1);
	}
	return (0);
}
