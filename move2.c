/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkurdy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:45:01 by lkurdy            #+#    #+#             */
/*   Updated: 2022/06/08 17:50:29 by lkurdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pa(t_list **a, t_list **b)
{
	if (push(a, b) == -1)
		return (-1);
	write(1, "pa\n", 3);
	return (0);
}

int	pb(t_list **a, t_list **b)
{
	if (push(b, a) == -1)
		return (-1);
	write(1, "pb\n", 3);
	return (0);
}

int	rotate(t_list **stack)
{
	t_list	*head;
	t_list	*tail;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	head = *stack;
	tail = ft_lstlast(head);
	*stack = head->next;
	head->next = NULL;
	tail->next = head;
	return (0);
}

int	ra(t_list **a)
{
	if (rotate(a) == -1)
		return (-1);
	write(1, "ra\n", 3);
	return (0);
}

int	rb(t_list **b)
{
	if (rotate(b) == -1)
		return (-1);
	write(1, "rb\n", 3);
	return (0);
}
