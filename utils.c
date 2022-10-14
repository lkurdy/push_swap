/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkurdy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 18:11:46 by lkurdy            #+#    #+#             */
/*   Updated: 2022/06/08 18:19:23 by lkurdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
		free(str[i--]);
}

void	free_stack(t_list **stack)
{
	t_list	*head;
	t_list	*tmp;

	head = *stack;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	free(stack);
}

static int	*tmp(int i, t_list **a)
{
	int		*tab;
	t_list	*head;

	i = 0;
	head = *a;
	tab = malloc(sizeof(int) * ft_lstsize(head));
	while (head)
	{
		tab[i] = head->value;
		i++;
		head = head->next;
	}
	return (tab);
}

int	*int_sort_tab(t_list **a)
{
	t_list	*head;
	int		i;
	int		j;
	int		temp;
	int		*tab;

	i = 0;
	tab = tmp(i, a);
	head = *a;
	while (i < ft_lstsize(head))
	{
		j = i + 1;
		while (j < ft_lstsize(head))
		{
			if (tab[i] > tab[j])
			{
				temp = tab[i];
				tab[i] = tab[j];
				tab[j] = temp;
			}
			j++;
		}
		i++;
	}
	return (tab);
}
