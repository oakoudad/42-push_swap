/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 12:18:50 by oakoudad          #+#    #+#             */
/*   Updated: 2022/03/28 12:18:52 by oakoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	set_index(t_list **lst, t_data *data)
{
	t_list	*list;
	int		i;

	list = *lst;
	while (list)
	{
		i = 0;
		while (i < data->len)
		{
			if (list->content == data->i_split[i])
				list->index = i;
			i++;
		}
		list = list->next;
	}
}

void	sort_index(t_list **lst, t_data *data)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < data->len - 1)
	{
		j = i + 1;
		while (j < data->len)
		{
			if (data->i_split[i] > data->i_split[j])
			{
				tmp = data->i_split[i];
				data->i_split[i] = data->i_split[j];
				data->i_split[j] = tmp;
			}
			j++;
		}
		i++;
	}
	set_index(lst, data);
}

int	get_min(t_list **lst)
{
	t_list	*tmp;
	int		min;

	tmp = *lst;
	min = tmp->index;
	while (tmp)
	{
		if (min > tmp->index)
		{
			min = tmp->index;
		}
		tmp = tmp->next;
	}
	return (min);
}

int	path(t_list **lst, t_data *data)
{
	int		i;
	int		y;
	t_list	*list;

	i = 0;
	y = data->len / 2;
	list = *lst;
	while (list)
	{
		if (list->index == get_min(lst))
		{
			if (i > y)
				return (1);
			else
				break ;
		}
		list = list->next;
		i++;
	}
	return (0);
}
