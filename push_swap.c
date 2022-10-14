/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkurdy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 16:18:24 by lkurdy            #+#    #+#             */
/*   Updated: 2022/06/08 16:19:22 by lkurdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort2(t_list **b)
{
	int	b_low;
	int	b_high;
	int	boolean;

	b_low = check_min(b);
	b_high = check_max(b);
	boolean = 2;
	while (!check_b(b))
	{
		boolean = boolean + sort_b(b, b_low, b_high);
		if (boolean % 2 == 0 && !check_b(b))
			rrb(b);
		else if (boolean % 2 == 1 && !check_b(b))
			rb(b);
	}
}

void	sort1(t_list **a)
{
	int	a_low;
	int	a_high;
	int	boolean;

	a_low = check_min(a);
	a_high = check_max(a);
	boolean = 2;
	while (!check_a(a))
	{
		boolean = boolean + sort_a(a, a_low, a_high);
		if (boolean % 2 == 0 && !check_a(a))
			rra(a);
		else if (boolean % 2 == 1 && !check_a(a))
			ra(a);
	}
}

int	remp(t_list **a, t_list **b, int b_max)
{
	t_list	*l;

	l = *b;
	b_max++;
	pb(a, b);
	if (b_max > 1 && l->value < ft_lstlast(l)->value)
		rb(b);
	if (b_max > 1 && l->value < l->next->value)
		sb(b);
	return (b_max);
}

void	push_b(t_list **a, t_list **b, int m, int d)
{
	t_list	*l;
	int		b_max;

	b_max = -1;
	while (b_max < d - 1)
	{
		l = *a;
		if (l->value >= m)
			b_max = remp(a, b, b_max);
		else
			ra(a);
	}
	sort1(a);
	sort2(b);
	while (ft_lstsize(*b) != 0)
		pa(a, b);
	while (!check_a(a))
		rra(a);
}

void	push_swap(t_list **a, t_list **b)
{
	t_list	*l;
	int		i;
	int		d;
	int		*tab;
	int		m;

	l = *a;
	i = ft_lstsize(l);
	tab = int_sort_tab(a);
	d = i;
	i = i / 2;
	d = d - i;
	m = tab[i];
	free(tab);
	if (!check_a(a) && i <= 3)
		push_b(a, b, m, d);
}
