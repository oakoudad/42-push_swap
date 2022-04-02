/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two_to_five.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakoudad <oakoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 10:55:16 by oakoudad          #+#    #+#             */
/*   Updated: 2022/03/28 12:10:15 by oakoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sort_2(t_list **lst)
{
	t_list	*t;

	t = *lst;
	if (t->content > t->next->content)
		sa(lst);
}

void	sort_3(t_list **lst)
{
	t_list	*n0;
	t_list	*n1;
	t_list	*n2;

	n0 = *lst;
	n1 = n0->next;
	n2 = n1->next;
	if (n0->content > n1->content && n0->content < n2->content)
		sa(lst);
	else if (n0->content > n1->content && n1->content > n2->content)
	{
		sa(lst);
		rra(lst);
	}
	else if (n0->content > n1->content && n1->content < n2->content)
		ra(lst);
	else if (n0->content < n1->content && n1->content > n2->content
		&& n0->content < n2->content)
	{
		sa(lst);
		ra(lst);
	}
	else if (n0->content < n1->content && n1->content > n2->content)
		rra(lst);
}

void	sort_4_5(t_list **a, t_list **b, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = data->len - 3;
	while (i < j)
	{
		if (!path(a, data))
			while ((*a)->index != i)
				ra(a);
		else
			while ((*a)->index != i)
				rra(a);
		pb(a, b);
		i++;
	}
	sort_3(a);
	while (j > 0)
	{
		pa(b, a);
		j--;
	}
}
