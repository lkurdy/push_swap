/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkurdy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 18:04:00 by lkurdy            #+#    #+#             */
/*   Updated: 2022/06/08 18:04:01 by lkurdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
}				t_list;

int		check_a(t_list **a);
int		check_b(t_list **b);
int		check_min(t_list **l);
int		check_max(t_list **l);
int		sort_a(t_list **a, int a_low, int a_high);
int		sort_b(t_list **b, int b_low, int b_high);
void	sort2(t_list **b);
void	sort1(t_list **a);
int		remp(t_list **a, t_list **b, int b_max);
void	push_b(t_list **a, t_list **b, int m, int d);
void	push_swap(t_list **a, t_list **b);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_atoi(char *npt);
int		*int_sort_tab(t_list **a);
int		*fill_tab(int *tab, int *a);
void	push_a(int *a, int *b);
t_list	*ft_lstnew(int value);
void	ft_lstadd_front(t_list **stack, t_list *new);
t_list	*ft_lstlast(t_list *head);
void	ft_lstadd_back(t_list **stack, t_list *new);
int		ft_lstsize(t_list *head);
void	printList(t_list *head);
void	radix_sort(t_list **a, t_list **b);
int		sa(t_list **a);
int		sb(t_list **b);
int		ss(t_list **a, t_list **b);
int		pa(t_list **a, t_list **b);
int		pb(t_list **a, t_list **b);
int		ra(t_list **a);
int		rb(t_list **b);
int		rr(t_list **a, t_list **b);
int		rra(t_list **a);
int		rrb(t_list **b);
int		rrr(t_list **a, t_list **b);
char	**ft_split(const char *s, char c);
int		ft_isdigit(int c);
void	free_stack(t_list **stack);
void	ft_free(char **str);
int		ft_check_args(int argc, char **argv);
void	index_stack(t_list **stack);
int		sort_b(t_list **b, int b_low, int b_high);
int		sort_a(t_list **a, int a_low, int a_high);
int		rotate(t_list **stack);
int		push(t_list **stack_to, t_list **stack_from);
int		reverse(t_list **stack);

#endif
